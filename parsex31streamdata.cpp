#include "parsex31streamdata.h"
#include "libF_HFM_Processing.h"
#include "libF_passive.h"
#include "libF_Track_Lofar_Demon.h"
#include <QDebug>
#include <QDateTime>

ParseX31StreamData::ParseX31StreamData(QObject *parent) : QObject(parent)
{
    this->crossRows = 8192;
    this->crossColumns = 384;

    this->lastValues = new float[this->crossRows * this->crossColumns];
}

ParseX31StreamData::~ParseX31StreamData()
{
    delete[] this->lastValues;
}

// 初始化
bool ParseX31StreamData::init(const QString &fileName)
{
    if (!libF_HFM_ProcessingInitialize() || !libF_passiveInitialize()) {
        return false;
    }

    this->targetFile = new QFile(fileName);
    if (!this->targetFile->open(QIODevice::ReadOnly))
    {
        return false;
    }

    this->targetDataS.setDevice(this->targetFile);

    return true;
}

// 文件读取周期为1s，passive数据解析周期为250ms, 定时器周期为250ms
void ParseX31StreamData::read(int taskId, int targetId, int dataCate, long startPoint)
{
    qDebug()<<this->targetFile->fileName()<<":"<<this->targetFile->size();
    this->targetDataS.setFloatingPointPrecision(QDataStream::SinglePrecision);
    this->targetDataS.setByteOrder(QDataStream::LittleEndian);

    int mostElement = this->crossRows * this->crossColumns;
    int mostLen = mostElement * sizeof (float);
    if (startPoint % 4 == 0) {
        // 读取文件
        this->targetDataS.skipRawData(mostLen * startPoint / 4);
        if (!this->targetDataS.atEnd()) {
            mwArray hfmInputArray(this->crossColumns, this->crossRows, mxSINGLE_CLASS, mxREAL);

            char *tmp = new char[mostLen];
            float *tmpResult = new float[mostElement];
            this->targetDataS.readRawData(tmp, mostLen);

            memcpy(tmpResult, tmp, mostLen);
            memcpy(this->lastValues, tmpResult, mostElement);
            hfmInputArray.SetData(tmpResult, mostElement);

            delete[] tmp;
            delete[] tmpResult;

            int nargout = 2;
            mwArray matrixDataHFM;
            mwArray matrixLenHFM;
            mwArray matrixInputFDSX(1, 1, mxDOUBLE_CLASS);
            matrixInputFDSX(1, 1) = 50;
            F_HFM_Processing(nargout, matrixDataHFM, matrixLenHFM, hfmInputArray, matrixInputFDSX);


            mwArray passiveInputArray(this->crossColumns, this->crossRows / 4, mxSINGLE_CLASS, mxREAL);
            float *tmpPaResult = new float[mostElement/4];
            memcpy(tmpPaResult, this->lastValues, mostElement/4);
            passiveInputArray.SetData(tmpPaResult, mostElement/4);

            mwArray matrixDataPWD;
            mwArray matrixLenPWD;
            mwArray matrixDataMbLofar;
            mwArray matrixLenMbLofar;
            mwArray matrixDataMultiLofar;

            nargout = 5;
            mwArray matrixPsInputFDSX(1, 1, mxDOUBLE_CLASS);
            matrixPsInputFDSX(1, 1) = 8;
            F_passive(nargout, matrixDataPWD, matrixDataMbLofar, matrixLenPWD, matrixLenMbLofar, matrixDataMultiLofar, passiveInputArray, matrixPsInputFDSX);

            delete[] tmpPaResult;

//            std::cout<<"x:"<<matrixDataHFM.GetDimensions()(1,1)<<"y:"<<matrixDataHFM.GetDimensions()(1,2)<<std::endl;
//            std::cout<<"len:"<<matrixLenHFM(1,1)<<std::endl;
//            std::cout<<matrixDataHFM.ToString()<<std::endl;

//            std::cout<<"x:"<<matrixDataPWD.GetDimensions()(1,1)<<"y:"<<matrixDataPWD.GetDimensions()(1,2)<<std::endl;
//            std::cout<<"len:"<<matrixLenPWD(1,1)<<std::endl;
//            std::cout<<matrixDataPWD.ToString()<<std::endl;

//            std::cout<<"x:"<<matrixDataMbLofar.GetDimensions()(1,1)<<"y:"<<matrixDataMbLofar.GetDimensions()(1,2)<<std::endl;
//            std::cout<<"len:"<<matrixLenMbLofar(1,1)<<std::endl;
//            std::cout<<matrixDataMbLofar.ToString()<<std::endl;

//            std::cout<<"x:"<<matrixDataMultiLofar.GetDimensions()(1,1)<<"y:"<<matrixDataMultiLofar.GetDimensions()(1,2)<<std::endl;
//            std::cout<<matrixDataMultiLofar.ToString()<<std::endl;

            int xSize = 0, ySize = 0;

            QVector<double> hfmData;
            xSize = matrixDataHFM.GetDimensions()(1, 1), ySize = matrixDataHFM.GetDimensions()(1, 2);
            for (int i=1;i<=xSize;i++) {
                for (int j=1;j<=ySize;j++) {
                    hfmData.append(matrixDataHFM(i,j));
                }
            }

            QVector<double> pwdData;
            xSize = matrixDataPWD.GetDimensions()(1, 1), ySize = matrixDataPWD.GetDimensions()(1, 2);
            for (int i=1;i<=xSize;i++) {
                for (int j=1;j<=ySize;j++) {
                    pwdData.append(matrixDataPWD(i,j));
                }
            }

            QVector<double> mbLofarData;
            xSize = matrixDataMbLofar.GetDimensions()(1, 1), ySize = matrixDataMbLofar.GetDimensions()(1, 2);
            for (int i=1;i<=xSize;i++) {
                for (int j=1;j<=ySize;j++) {
                    mbLofarData.append(matrixDataMbLofar(i,j));
                }
            }

            QVector<double> tLofarData;

            QVector<double> tDemonData;

            emit update_data(hfmData, pwdData, mbLofarData, tLofarData, tDemonData);
        }
    } else {
        mwArray passiveInputArray(this->crossColumns, this->crossRows / 4, mxSINGLE_CLASS, mxREAL);
        // 仅解析Passive数据

        int cross = startPoint % 4;
        float *tmpPaResult = new float[mostElement/4];
        memcpy(tmpPaResult, this->lastValues + cross * mostElement / 4, mostElement/4);
        passiveInputArray.SetData(tmpPaResult, mostElement/4);

        int nargout = 5;
        mwArray matrixDataPWD;
        mwArray matrixLenPWD;
        mwArray matrixDataMbLofar;
        mwArray matrixLenMbLofar;
        mwArray matrixDataMultiLofar;
        mwArray matrixPsInputFDSX(1, 1, mxDOUBLE_CLASS);
        matrixPsInputFDSX(1, 1) = 8;
        F_passive(nargout, matrixDataPWD, matrixDataMbLofar, matrixLenPWD, matrixLenMbLofar, matrixDataMultiLofar, passiveInputArray, matrixPsInputFDSX);

        std::cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
        std::cout<<tmpPaResult<<std::endl;
        std::cout<<"x:"<<matrixDataPWD.GetDimensions()(1,1)<<"y:"<<matrixDataPWD.GetDimensions()(1,2)<<std::endl;
        std::cout<<"len:"<<matrixLenPWD(1,1)<<std::endl;
        std::cout<<matrixDataPWD.ToString()<<std::endl;

        std::cout<<"x:"<<matrixDataMbLofar.GetDimensions()(1,1)<<"y:"<<matrixDataMbLofar.GetDimensions()(1,2)<<std::endl;
        std::cout<<"len:"<<matrixLenMbLofar(1,1)<<std::endl;
        std::cout<<matrixDataMbLofar.ToString()<<std::endl;

        std::cout<<"x:"<<matrixDataMultiLofar.GetDimensions()(1,1)<<"y:"<<matrixDataMultiLofar.GetDimensions()(1,2)<<std::endl;
        std::cout<<matrixDataMultiLofar.ToString()<<std::endl;
        std::cout<<"==================================================="<<std::endl;

        delete[] tmpPaResult;

        int xSize = 0, ySize = 0;

        QVector<double> hfmData;

        QVector<double> pwdData;
        xSize = matrixDataPWD.GetDimensions()(1, 1), ySize = matrixDataPWD.GetDimensions()(1, 2);
        for (int i=1;i<=xSize;i++) {
            for (int j=1;j<=ySize;j++) {
                pwdData.append(matrixDataPWD(i,j));
            }
        }

        QVector<double> mbLofarData;
        xSize = matrixDataMbLofar.GetDimensions()(1, 1), ySize = matrixDataMbLofar.GetDimensions()(1, 2);
        for (int i=1;i<=xSize;i++) {
            for (int j=1;j<=ySize;j++) {
                mbLofarData.append(matrixDataMbLofar(i,j));
            }
        }

        QVector<double> tLofarData;

        QVector<double> tDemonData;

        emit update_data(hfmData, pwdData, mbLofarData, tLofarData, tDemonData);
    }
}

// 关闭文件
bool ParseX31StreamData::close()
{
    this->targetFile->close();
    return true;
}
