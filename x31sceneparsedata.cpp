#include "x31sceneparsedata.h"
#include "libF_CJRecorderDataRead_CP.h"
#include "libF_CJRecorderDataRead_DEMON.h"
#include "libF_CJRecorderDataRead_HFMTRACK.h"
#include "libF_CJRecorderDataRead_LOFAR.h"
#include "libF_CJRecorderDataRead_MultiLOFAR.h"
#include "libF_CJRecorderDataRead_Passive.h"
#include "libF_CJRecorderDataRead_PassiveTRACK.h"
#include <QFile>
#include <QCoreApplication>
#include <QDateTime>
#include <QDataStream>
#include <QMultiMap>

// x31 scene base
QString X31SceneRunnableBase::formatTime(int year1, int year2, int month, int day, int hour, int minute, int seconds)
{
    int year = year1 + year2 * 256;

    QString tmp = QString("%1-%2-%3 %4:%5:%6").arg(year).arg(month, 2, 10, QChar('0')).arg(day, 2, 10, QChar('0')).arg(hour, 2, 10, QChar('0')).arg(minute, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    return tmp;
}

QString X31SceneRunnableBase::dataFileName(int taskId, int targetId, QString dType)
{
    QString appDir = QCoreApplication::applicationDirPath();
    return QString("%1/%2_%3_%4_data.bin").arg(appDir).arg(taskId).arg(targetId).arg(dType);
}

bool X31SceneRunnableBase::checkSerializationFile(int taskId, int targetId, QString dType)
{
    QString targetFileName = this->dataFileName(taskId, targetId, dType);
    QFile targetFile(targetFileName);

    if (targetFile.exists()) {
        return true;
    }

    return false;
}


// x31 double
X31SceneDoubleRunnable::X31SceneDoubleRunnable(QString dType, int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData)
{
    this->dType = dType;
    this->taskId = taskId;
    this->targetId = targetId;
    this->fileName = fileName;
    this->data = cpData;
}

void X31SceneDoubleRunnable::run()
{
    if (this->checkSerializationFile(this->taskId, this->targetId, this->dType)) {
        this->parseFromSerialization(this->taskId, this->targetId, this->dType);
    } else {
        this->parse();
    }

    this->sendSignal();
}

void X31SceneDoubleRunnable::parseFromSerialization(int taskId, int targetId, QString dType)
{
    QString fileName = this->dataFileName(taskId, targetId, dType);
    QFile cpFile(fileName);
    cpFile.open(QIODevice::ReadOnly);

    QDataStream cpStream(&cpFile);
    cpStream >> this->data >> this->startTime >> this->endTime;

    cpFile.close();
}

void X31SceneDoubleRunnable::operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime)
{
    QString targetFileName = this->dataFileName(taskId, targetId, dType);
    QFile targetFile(targetFileName);

    targetFile.open(QIODevice::WriteOnly);
    QDataStream targetStream(&targetFile);

    int size = inData.NumberOfElements();
    if (size != 0) {
        int xSize = inData.GetDimensions()(1, 1), ySize = inData.GetDimensions()(1, 2);

        int xStart = dType == "CP" ? 3 : 1;
        for (int i=xStart;i<=xSize;i++) {
            // 读取时间, 9个字节， xx(年)x(月)x(日)x(时)x(分)x(秒)xx(毫秒)
            QString tmp = formatTime(inTime(i, 1), inTime(i, 2), inTime(i, 3), inTime(i, 4), inTime(i, 5), inTime(i, 6), inTime(i, 7));
            QVector<double> values;
            for (int j=1;j<=ySize;j++) {
                values.append(inData(i,j));
            }
            this->data.insert(tmp, values);
        }

        QString startTimeStr = formatTime(inTime(1, 1), inTime(1, 2), inTime(1, 3), inTime(1, 4), inTime(1, 5), inTime(1, 6), inTime(1, 7));
        QString endTimeStr = formatTime(inTime(xSize, 1), inTime(xSize, 2), inTime(xSize, 3), inTime(xSize, 4), inTime(xSize, 5), inTime(xSize, 6), inTime(xSize, 7));

        this->startTime = QDateTime::fromString(startTimeStr, "yyyy-MM-dd hh:mm:ss");
        this->endTime = QDateTime::fromString(endTimeStr, "yyyy-MM-dd hh:mm:ss");

        targetStream << this->data;
        targetStream << this->startTime;
        targetStream << this->endTime;
    }

    targetFile.close();
}

//复位参数
void X31SceneDoubleRunnable::resetParam(int taskId, int targetId, QString fileName)
{
    this->taskId = taskId;
    this->targetId = targetId;
    this->fileName = fileName;
}


// x31 quint
X31SceneUnitRunnable::X31SceneUnitRunnable(QString dType, int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<quint8>> &cpData)
{
    this->dType = dType;
    this->taskId = taskId;
    this->targetId = targetId;
    this->fileName = fileName;
    this->data = cpData;
}

void X31SceneUnitRunnable::run()
{
    if (this->checkSerializationFile(this->taskId, this->targetId, this->dType)) {
        this->parseFromSerialization(this->taskId, this->targetId, this->dType);
    } else {
        this->parse();
    }

    this->sendSignal();
}

void X31SceneUnitRunnable::parseFromSerialization(int taskId, int targetId, QString dType)
{
    QString fileName = this->dataFileName(taskId, targetId, dType);
    QFile cpFile(fileName);
    cpFile.open(QIODevice::ReadOnly);

    QDataStream cpStream(&cpFile);
    cpStream >> this->data >> this->startTime >> this->endTime;

    cpFile.close();
}

void X31SceneUnitRunnable::operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime)
{
    QString targetFileName = this->dataFileName(taskId, targetId, dType);
    QFile targetFile(targetFileName);

    targetFile.open(QIODevice::WriteOnly);
    QDataStream targetStream(&targetFile);

    int size = inData.NumberOfElements();
    if (size != 0) {
        int xSize = inData.GetDimensions()(1, 1), ySize = inData.GetDimensions()(1, 2);

        for (int i=1;i<=xSize;i++) {
            // 读取时间, 9个字节， xx(年)x(月)x(日)x(时)x(分)x(秒)xx(毫秒)
            QString tmp = formatTime(inTime(i, 1), inTime(i, 2), inTime(i, 3), inTime(i, 4), inTime(i, 5), inTime(i, 6), inTime(i, 7));
            QVector<quint8> values;
            for (int j=1;j<=ySize;j++) {
                quint8 v = inData(i,j);
                values.append(v);
            }
            this->data.insert(tmp, values);
        }
        QString startTimeStr = formatTime(inTime(1, 1), inTime(1, 2), inTime(1, 3), inTime(1, 4), inTime(1, 5), inTime(1, 6), inTime(1, 7));
        QString endTimeStr = formatTime(inTime(xSize, 1), inTime(xSize, 2), inTime(xSize, 3), inTime(xSize, 4), inTime(xSize, 5), inTime(xSize, 6), inTime(xSize, 7));

        this->startTime = QDateTime::fromString(startTimeStr, "yyyy-MM-dd hh:mm:ss");
        this->endTime = QDateTime::fromString(endTimeStr, "yyyy-MM-dd hh:mm:ss");

        targetStream << this->data;
        targetStream << this->startTime;
        targetStream << this->endTime;
    }

    targetFile.close();
}

void X31SceneUnitRunnable::resetParam(int taskId, int targetId, QString fileName)
{
    this->taskId = taskId;
    this->targetId = targetId;
    this->fileName = fileName;
}

// cp runnable
X31SceneCpRunnable::X31SceneCpRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData) : X31SceneDoubleRunnable("CP", taskId, targetId, fileName, cpData)
{
}

void X31SceneCpRunnable::parse()
{

    std::string datFile_str = this->fileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 3;	//输出变量个数
    mwArray matrixDataCP;
    mwArray matrixTimeCP;
    mwArray matrixLenCP;

    std::cout<<"start cp parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
    F_CJRecorderDataRead_CP(nargout, matrixDataCP, matrixTimeCP, matrixLenCP, datFile);

    operateDataAfterParse(this->taskId, this->targetId, this->dType, matrixDataCP, matrixTimeCP);
    std::cout<<"end cp parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
}

void X31SceneCpRunnable::sendSignal()
{
    emit send_cpdata(this->startTime, this->endTime, this->data);
}


// lofar runnable
X31SceneLofarRunnable::X31SceneLofarRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData) : X31SceneDoubleRunnable("LOFAR", taskId, targetId, fileName, cpData)
{

}

void X31SceneLofarRunnable::parse()
{
    std::string datFile_str = this->fileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 3;	//输出变量个数
    mwArray matrixDataLofar;
    mwArray matrixTimeLofar;
    mwArray matrixLenLofar;

    std::cout<<"start lofar parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
    F_CJRecorderDataRead_LOFAR(nargout, matrixDataLofar, matrixTimeLofar, matrixLenLofar, datFile);

    operateDataAfterParse(this->taskId, this->targetId, this->dType, matrixDataLofar, matrixTimeLofar);
    std::cout<<"end lofar parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;

}

void X31SceneLofarRunnable::sendSignal()
{
    emit send_lofardata(this->startTime, this->endTime, this->data);
}


// demon runnable
X31SceneDemonRunnable::X31SceneDemonRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData) : X31SceneDoubleRunnable("DEMON", taskId, targetId, fileName, cpData)
{

}

void X31SceneDemonRunnable::parse()
{
    std::string datFile_str = this->fileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 3;	//输出变量个数
    mwArray matrixDataDemon;
    mwArray matrixTimeDemon;
    mwArray matrixLenDemon;

    std::cout<<"start demon parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
    F_CJRecorderDataRead_DEMON(nargout, matrixDataDemon, matrixTimeDemon, matrixLenDemon, datFile);

    operateDataAfterParse(this->taskId, this->targetId, this->dType, matrixDataDemon, matrixTimeDemon);
    std::cout<<"end demon parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
}

void X31SceneDemonRunnable::sendSignal()
{
    emit send_demondata(this->startTime, this->endTime, this->data);
}


// passive runnable
X31ScenePassiveRunnable::X31ScenePassiveRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData) : X31SceneDoubleRunnable("PASSIVE", taskId, targetId, fileName, cpData)
{

}

void X31ScenePassiveRunnable::parse()
{
    std::string datFile_str = this->fileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 3;	//输出变量个数
    mwArray matrixDataPassive;
    mwArray matrixTimePassive;
    mwArray matrixLenPassive;

    F_CJRecorderDataRead_Passive(nargout, matrixDataPassive, matrixTimePassive, matrixLenPassive, datFile);

    operateDataAfterParse(this->taskId, this->targetId, this->dType, matrixDataPassive, matrixTimePassive);
}

void X31ScenePassiveRunnable::sendSignal()
{
    emit send_passivedata(this->startTime, this->endTime, this->data);
}


// multilofar runnable
X31SceneMultiLofarRunnable::X31SceneMultiLofarRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData) : X31SceneDoubleRunnable("MULTILOFAR", taskId, targetId, fileName, cpData)
{

}

void X31SceneMultiLofarRunnable::parse()
{
    std::string datFile_str = this->fileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 3;	//输出变量个数
    mwArray matrixDataMultiLofar;
    mwArray matrixTimeMultiLofar;
    mwArray matrixLenMultiLofar;

    std::cout<<"start multilofar parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;

    F_CJRecorderDataRead_MultiLOFAR(nargout, matrixDataMultiLofar, matrixTimeMultiLofar, matrixLenMultiLofar, datFile);

    operateDataAfterParse(this->taskId, this->targetId, this->dType, matrixDataMultiLofar, matrixTimeMultiLofar);

    std::cout<<"end multilofar parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
}

void X31SceneMultiLofarRunnable::sendSignal()
{
    emit send_multilofardata(this->startTime, this->endTime, this->data);
}


// hfmtrack runnable
X31SceneHfmTrackRunnable::X31SceneHfmTrackRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<quint8>> &cpData) : X31SceneUnitRunnable("HFMTRACK", taskId, targetId, fileName, cpData)
{

}

void X31SceneHfmTrackRunnable::parse()
{
    std::string datFile_str = this->fileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 3;	//输出变量个数
    mwArray matrixDataHfmTrack;
    mwArray matrixTimeHfmTrack;
    mwArray matrixLenHfmTrack;

    std::cout<<"start hfmtrack parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;

    F_CJRecorderDataRead_MultiLOFAR(nargout, matrixDataHfmTrack, matrixTimeHfmTrack, matrixLenHfmTrack, datFile);

    operateDataAfterParse(this->taskId, this->targetId, this->dType, matrixDataHfmTrack, matrixTimeHfmTrack);
    std::cout<<"end hfmtrack parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
}

void X31SceneHfmTrackRunnable::sendSignal()
{
    emit send_hfmtrackdata(this->startTime, this->endTime, this->data);
}


// passivetrack runnable
X31ScenePassiveTrackRunnable::X31ScenePassiveTrackRunnable(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<quint8>> &cpData) : X31SceneUnitRunnable("PASSIVETRACK", taskId, targetId, fileName, cpData)
{

}

void X31ScenePassiveTrackRunnable::parse()
{
    std::string datFile_str = this->fileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 3;	//输出变量个数
    mwArray matrixDataHfmTrack;
    mwArray matrixTimeHfmTrack;
    mwArray matrixLenHfmTrack;

    std::cout<<"start passivetrack parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
    F_CJRecorderDataRead_MultiLOFAR(nargout, matrixDataHfmTrack, matrixTimeHfmTrack, matrixLenHfmTrack, datFile);

    operateDataAfterParse(this->taskId, this->targetId, this->dType, matrixDataHfmTrack, matrixTimeHfmTrack);
    std::cout<<"end passivetrack parse at "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<<std::endl;
}

void X31ScenePassiveTrackRunnable::sendSignal()
{
    emit send_passivetrackdata(this->startTime, this->endTime, this->data);
}

