 #include "x31jzparsedata.h"
#include "libF_HFM_Processing.h"
#include "libF_passive.h"
#include "libF_Track_Lofar_Demon.h"
#include <QFile>
#include <QDataStream>
#include <QDateTime>

X31JzParseData::X31JzParseData()
{
}

X31JzParseData::~X31JzParseData()
{
}

//初始化参数
void X31JzParseData::initParams(int taskId, int targetId, QString &fileName)
{
    this->taskId = taskId;
    this->targetId = targetId;
    this->fileName = fileName;

    this->startPoint = 0;
    this->pausePoint = 0;
    this->isRunning = false;
    this->isReachEnd = false;
}

//设置运行使能
void X31JzParseData::setRunningEnable(bool running)
{
    this->runningEnabled = running;
}

//设置复位使能
void X31JzParseData::reset()
{
    this->runningEnabled = true;
    this->isReachEnd = false;
    this->isRunning = false;
    this->startPoint = 0;
    this->pausePoint = 0;
    this->scaleXForTrackLofar = -1;
}

//设置开始点
void X31JzParseData::setStartPoint(int startPoint)
{
    std::cout<<"set start point:"<<startPoint<<std::endl;
    this->startPoint = startPoint;
}

//设置坐标范围
void X31JzParseData::setScaleX(int scaleX)
{
    std::cout<<"get scale X:"<<scaleX<<std::endl;
    this->scaleXForTrackLofar = scaleX;
}

//数据解析
void X31JzParseData::parse()
{
//    std::cout<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
//    std::cout<<"running:reachend--"<<this->isRunning<<":"<<this->isReachEnd<<std::endl;
    if (this->isRunning || !this->runningEnabled)
        return;

    QFile targetFile(this->fileName);
    if (!targetFile.open(QIODevice::ReadOnly))////如果没有打开cpFile等文件
        return;

    this->isRunning = true;

    //
    std::cout<<"start x31 jz parse"<<std::endl;//std::cout<<“是向终端屏幕输出”
    QDataStream targetStream(&targetFile);

    targetStream.setFloatingPointPrecision(QDataStream::SinglePrecision);//将数据流的浮点精度设置为SinglePrecision
    targetStream.setByteOrder(QDataStream::LittleEndian);//将序列化字节顺序设置为LittleEndian即小端格式

    int mostElements = CROSS_ROWS * CROSS_COLUMNS;
    int mostLength = mostElements * sizeof (float);

    std::cout<<"startPoint:pausePoint"<<this->startPoint<<":"<<this->pausePoint<<std::endl;
    //Skips len bytes from the device. Returns the number of bytes actually skipped, or -1 on error.
    //skipRawData(int len)
    //跳过len bytes大小的数据，并且返回被跳过的数据
    targetStream.skipRawData((this->startPoint + this->pausePoint) * mostLength);//
    //Returns true if the I/O device has reached the end position (end of the stream or file) or if there is no I/O device set; otherwise returns false
    if (!targetStream.atEnd()) {//如果未结束
        float *lastValues = new float[mostElements];
        QVector<double> hfmData, pwdData, mbLofarData, lofarData, demonData;

        //
        while (true) {
            if (targetStream.atEnd()) {
                this->isReachEnd = true;
                break;
            }

            if (!this->runningEnabled) {
                break;
            }

            hfmData.clear();
            pwdData.clear();
            mbLofarData.clear();
            lofarData.clear();
            demonData.clear();

            char *tmp = new char[mostLength];
            //Reads at most len bytes from the stream into s and returns the number of bytes read. If an error occurs, this function returns -1.
            //QDataStream::readRawData(char *s, int len)
            targetStream.readRawData(tmp, mostLength);
            this->pausePoint++;
            //memcpy为C++中的内存copy函数，lastValues为复制内容的目标数组，tmp为复制的数据源，len为要复制的长度
            memcpy(lastValues, tmp, mostLength);

            delete [] tmp;

            mwArray hfmInputArray(CROSS_COLUMNS, CROSS_ROWS, mxSINGLE_CLASS, mxREAL);//创建mwArray数据类型对象
            //将lastValues内容写入hfmInputArray中，数据大小为mostElementns
            hfmInputArray.SetData(lastValues, mostElements);

//            std::cout<<"++++++++++++++++++++HFM INPUT DATA START "<<this->pausePoint<<" +++++++++++++++++++++++++++++"<<std::endl;
//            std::cout<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
//            std::cout<<"x:"<<hfmInputArray.GetDimensions()(1,1)<<"y:"<<hfmInputArray.GetDimensions()(1,2)<<std::endl;
//            std::cout<<hfmInputArray.ToString()<<std::endl;
//            std::cout<<"++++++++++++++++++++HFM INPUT DATA END "<<this->pausePoint<<" +++++++++++++++++++++++++++++"<<std::endl;

            int nargout = 2;//输出变量个数
            mwArray matrixDataHFM;
            mwArray matrixLenHFM;
            mwArray matrixInputFDSX(1, 1, mxDOUBLE_CLASS);
            matrixInputFDSX(1, 1) = 50;

            F_HFM_Processing(nargout, matrixDataHFM, matrixLenHFM, hfmInputArray, matrixInputFDSX);

//            std::cout<<"++++++++++++++++++++HFM START "<<this->pausePoint<<" +++++++++++++++++++++++++++++"<<std::endl;
//            std::cout<<"x:"<<matrixDataHFM.GetDimensions()(1,1)<<"y:"<<matrixDataHFM.GetDimensions()(1,2)<<std::endl;
//            std::cout<<matrixDataHFM.ToString()<<std::endl;
//            std::cout<<"++++++++++++++++++++HFM END "<<this->pausePoint<<" +++++++++++++++++++++++++++++"<<std::endl;

            operateDataAfterParse(matrixDataHFM, hfmData);

            int groups = 4;
            int step = mostElements / groups;
            for (int i=0;i<groups;i++) {
                if (!this->runningEnabled) {
                    break;
                }

                float *tmpPsResult = new float[step];
                mwArray passiveInputArray(CROSS_COLUMNS, CROSS_ROWS / groups, mxSINGLE_CLASS, mxREAL);

                memcpy(tmpPsResult, lastValues + i*step, step * sizeof (float));
                passiveInputArray.SetData(tmpPsResult, step);

//                std::cout<<"++++++++++++++++++++PASSIVE INPUT START "<<i<<" +++++++++++++++++++++++++++++";
//                std::cout<<"x:"<<passiveInputArray.GetDimensions()(1,1)<<"y:"<<passiveInputArray.GetDimensions()(1,2)<<std::endl;
//                std::cout<<passiveInputArray.ToString()<<std::endl;
//                std::cout<<"++++++++++++++++++++PASSIVE INPUT END "<<i<<" +++++++++++++++++++++++++++++";

                mwArray matrixDataPWD;
                mwArray matrixLenPWD;
                mwArray matrixDataMbLofar;
                mwArray matrixLenMbLofar;
                mwArray matrixDataMultiLofar;

                nargout = 5;
                mwArray matrixPsInputFDSX(1, 1, mxDOUBLE_CLASS);
                matrixPsInputFDSX(1, 1) = 8;
                F_passive(nargout, matrixDataPWD, matrixDataMbLofar, matrixLenPWD, matrixLenMbLofar, matrixDataMultiLofar, passiveInputArray, matrixPsInputFDSX);

                operateDataAfterParse(matrixDataPWD, pwdData);
                operateDataAfterParse(matrixDataMbLofar, mbLofarData);
//                std::cout<<"++++++++++++++++++++PWD START "<<i<<" +++++++++++++++++++++++++++++";
//                std::cout<<"x:"<<matrixDataPWD.GetDimensions()(1,1)<<"y:"<<matrixDataPWD.GetDimensions()(1,2)<<std::endl;
//                std::cout<<"len:"<<matrixLenPWD(1,1)<<std::endl;
//                std::cout<<matrixDataPWD.ToString()<<std::endl;
//                std::cout<<"++++++++++++++++++++PWD END "<<i<<" +++++++++++++++++++++++++++++";

//                std::cout<<"++++++++++++++++++++MBLOFAR START "<<i<<" +++++++++++++++++++++++++++++";
//                std::cout<<"x:"<<matrixDataMbLofar.GetDimensions()(1,1)<<"y:"<<matrixDataMbLofar.GetDimensions()(1,2)<<std::endl;
//                std::cout<<"len:"<<matrixLenMbLofar(1,1)<<std::endl;
//                std::cout<<matrixDataMbLofar.ToString()<<std::endl;
//                std::cout<<"++++++++++++++++++++MBLOFAR END+++++++++++++++++++++++++++++";

//                std::cout<<"++++++++++++++++++++MULTI LOFAR START "<<i<<" +++++++++++++++++++++++++++++";
//                std::cout<<"x:"<<matrixDataMultiLofar.GetDimensions()(1,1)<<"y:"<<matrixDataMultiLofar.GetDimensions()(1,2)<<std::endl;
//                std::cout<<matrixDataMultiLofar.ToString()<<std::endl;
//                std::cout<<"++++++++++++++++++++MULTI LOFAR END+++++++++++++++++++++++++++++";

                if (this->scaleXForTrackLofar != -1) {
                    mwArray matrixDataTLofar;
                    mwArray matrixDataTDemon;

                    nargout = 2;
                    mwArray matrixTrackInputFDSX(1, 1, mxDOUBLE_CLASS);
                    matrixTrackInputFDSX(1, 1) = 50;
                    mwArray matrixTrackX(1, 1, mxDOUBLE_CLASS);
                    matrixTrackX(1, 1) = this->scaleXForTrackLofar;
                    F_Track_Lofar_Demon(nargout, matrixDataTLofar, matrixDataTDemon, matrixDataMultiLofar, matrixTrackX, matrixTrackInputFDSX);

                    operateDataAfterParse(matrixDataTLofar, lofarData);
                    operateDataAfterParse(matrixDataTDemon, demonData);
                }
                delete [] tmpPsResult;
            }

            emit send_data(hfmData, pwdData, mbLofarData, lofarData, demonData);
        }

        delete [] lastValues;
    } else {
        this->isReachEnd = true;
    }

    if (this->runningEnabled) {
        emit complete_parse();
    }

    targetFile.close();

    reset();

    std::cout<<"end x31 jz parse"<<std::endl;
}

//解析完成后操作数据
void X31JzParseData::operateDataAfterParse(mwArray &inData, QVector<double> &output)
{
    //获取数据维数大小
    int xSize = inData.GetDimensions()(1, 1), ySize = inData.GetDimensions()(1, 2);
    for (int i=1;i<=xSize;i++) {
        for (int j=1;j<=ySize;j++) {
            output.append(inData(i,j));
        }
    }
}
