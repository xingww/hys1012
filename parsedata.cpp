#include "parsedata.h"
#include "libdat3x9apre.h"
#include "libgetStartT0.h"
#include "libread3x9a.h"
#include "libF_CJRecorderDataRead.h"
#include "models/taskmodel.h"
#include "models/gpsmodel.h"
#include "models/targetmodel.h"
#include "hysmainwindow.h"
#include "hysdb.h"
#include <QSqlRecord>
#include <QFile>
#include <QDateTime>
#include <QDataStream>
#include <QFile>

//modify2
//#include "F_CJPassiveX1.h"
//#include "F_DataCJBZHX1.h"
//#include "Get_X1CJTime.h"

ParseData::ParseData(QObject *parent) : QObject(parent)
{

}

//解析数据
//任务ID，目标ID，数据类型，文件名
void ParseData::parse(int taskId, int targetId, int dataCate, const QString &fileName)
{
    emit parse_status(0, QString::fromLocal8Bit("正在进行初始化..."));

    if (!HysDbHelper::getInstance()->isOpen()) {
        emit parse_status(100, QString::fromLocal8Bit("数据库连接失败..."));
        return;
    }

    try {
        //modify2
        if (!libdat3x9apreInitialize() || !libgetStartT0Initialize() || !libread3x9aInitialize())
        //if (!F_CJPassiveX1Initialize())
        {
            //发射信息
            emit parse_status(100, QString::fromLocal8Bit("初始化函数失败..."));
            return;
        }

        emit parse_status(1, QString::fromLocal8Bit("正在解析数据，请耐心等待..."));

        switch (dataCate) {
        case HysMainWindow::DataCate::RAW_DATA:
            parseFile(taskId, targetId, fileName);
            break;
        case HysMainWindow::DataCate::GPS_DATA:
            parseGpsFile(taskId, targetId, fileName);
            break;
        case HysMainWindow::DataCate::JZ_DATA:
            break;
        default:
            break;
        }

        emit parse_status(200, QString::fromLocal8Bit("解析数据完成！"));
    } catch (std::exception) {
        emit parse_status(100, QString::fromLocal8Bit("数据解析异常,请核对文件."));
    }
}
//读取数据
 void ParseData::read(int taskId, int targetId, int dataCate, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                      , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                      , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData)
 {
     emit parse_status(0, QString::fromLocal8Bit("正在进行初始化..."));
     if (!HysDbHelper::getInstance()->isOpen()) {
         emit parse_status(100, QString::fromLocal8Bit("数据库连接失败..."));
         return;
     }
    //初始化失败
     if (!libF_CJRecorderDataReadInitialize()) {
         return;
     }

     switch (dataCate) {
     //场景数据
     case HysMainWindow::DataCate::SCENE_DATA:
         if (checkDatFileSerialization(taskId, targetId)) {
             deserializeDatFileForScene(taskId, targetId, fileName, cpData, edData, noiselData, noisesData, fsdData, lofarData, demonData, echoData, noData);
         } else {
             parseDatFileForScene(taskId, targetId, fileName, cpData, edData, noiselData, noisesData, fsdData, lofarData, demonData, echoData, noData);
         }
         break;
     }

     emit parse_status(200, QString::fromLocal8Bit("解析数据完成！"));
 }

//解析原始文件,内部调用
void ParseData::parseFile(int taskId, int targetId, const QString &fileName)
{
    // 第一步, 生成.ad 和 .dat文件
    this->parseRawFile(fileName);

    // 第二步, 解析.ad文件, 获取tstr
    QString adFileName = fileName + ".ad";
    double tstr = this->parseAdFile(adFileName);

    // 第三步， 通过.dat文件生成GPS、JZ等文件
    QString datFileName = fileName + ".dat";
    this->parseDatFile(tstr, datFileName);

    // 第四步，保存GPS信息到数据库
    QString gpsFileName = fileName + ".gps";
    this->parseGpsFile(taskId, targetId, gpsFileName);

    QString jzFileName = fileName + ".jz";

    // 更新任务信息，保存文件路径
    updateTask(taskId, targetId, fileName, datFileName, gpsFileName, jzFileName);
}

//解析源文件
void ParseData::parseRawFile(const QString &rawFileName)
{
    //tmp_ch_str "D:/TEST_CH1"
    //ch is: D:/TEST_CH1
    std::string tmp_ch_str = rawFileName.toStdString();//转换为标准字符串
    const char* ch = tmp_ch_str.c_str();//c_str()生成一个const char*指针，指向以空字符终止的数组
    mwArray chFile(ch);//mwArray赋值ch
    dat3x9apre(chFile);
    //F_DataCJBZHX1(chFile);
}
//解析.ad文件
double ParseData::parseAdFile(const QString &adFileName)
{
    //adFile_str is: "D:/TEST_CH1.ad"
    //*adCh is: D:/TEST_CH1.ad
    std::string adFile_str = adFileName.toStdString();
    const char* adCh = adFile_str.c_str();
    mwArray adFile(adCh);
    int rowN = 1;
    int colN = 1;
    mwArray matrixTstr(rowN, colN, mxDOUBLE_CLASS, mxREAL);//创建行数列数为1的MATLAT数据矩阵
    int nargout = 1;//函数输出的参数个数
    try {
        getStartT0(nargout, matrixTstr, adFile);
    } catch (...) {
        matrixTstr(1, 1) = 2.018101308072700e+13;
    }

    return matrixTstr.Get(1,1);
}
//解析.dat文件
void ParseData::parseDatFile(const double &tstr, const QString &datFileName)
{
    //datFile_str "D:/TEST_CH1.dat"
    //* datCh D:/TEST_CH1.dat
    mwArray matrixTstr(1, 1, mxDOUBLE_CLASS, mxREAL);
    matrixTstr(1, 1) = tstr;

    std::string datFile_str = datFileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);
    read3x9a(matrixTstr, datFile);
}
//解析GPS文件
void ParseData::parseGpsFile(int taskId, int targetId, const QString &fileName)
{
    QFile gpsFile(fileName);
    gpsFile.open(QIODevice::ReadOnly);

    GpsModel *model = new GpsModel(this, HysDbHelper::getInstance()->getDb() );
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter(QString("task_id=%1 and target_id=%2").arg(taskId).arg(targetId));
    model->select();
    //删除所有历史数据
    model->removeRows(0, model->rowCount());
    model->submitAll();

    QSqlDatabase db = model->database();
    db.transaction();
    QString startTime, endTime;
    while (!gpsFile.atEnd()) {
        QByteArray line = gpsFile.readLine();
        QString strLine(line);
        QStringList items = strLine.split(QRegExp("\\s+"));
        if (items.size() != 19) {    //一行18个，空格分开
            continue;
        }

        QString year = items.at(2);
        QString month = items.at(3);
        QString day = items.at(4);
        QString hour = items.at(5);
        QString minute = items.at(6);
        QString second = items.at(7);
        QString longitude = items.at(13);
        QString latitude = items.at(14);

        QString actionTime = QString("%1-%2-%3 %4:%5:%6").arg(year, month, day, hour, minute, second);
        if (startTime.isEmpty()) {
            startTime = actionTime;
        }
        endTime = actionTime;

        QSqlRecord record = model->record();
        record.setGenerated("id", false);
        record.setValue("task_id", taskId);
        record.setValue("target_id", targetId);
        record.setValue("crawl_time", actionTime);
        record.setValue("longitude", longitude);
        record.setValue("latitude", latitude);

        QDateTime now = QDateTime::currentDateTime();
        QString nowStr = now.toString("yyyy-MM-dd hh:mm:ss");
        record.setValue("created_time", nowStr);
        record.setValue("modified_time", nowStr);

        model->insertRecord(-1, record);
    }
    if (model->submitAll()) {
        // 保存GPS时间段
        if (!startTime.isEmpty() && !endTime.isEmpty()) {
            if (targetId == HysMainWindow::SELF_DATA) {
                // 本舰
                TaskModel *tmodel = new TaskModel(this, db);
                tmodel->setFilter(QString("id=%1").arg(taskId));
                tmodel->select();
                if (tmodel->rowCount() == 1) {
                    QSqlRecord record = tmodel->record(0);
                    record.setValue("start_time", startTime);
                    record.setValue("end_time", endTime);

                    tmodel->setRecord(0, record);
                    tmodel->submitAll();
                }

                delete tmodel;
            } else {
                // 目标舰
                TargetModel *targetModel = new TargetModel(this, db);
                targetModel->setFilter(QString("id=%1").arg(targetId));
                targetModel->select();
                if (targetModel->rowCount() == 1) {
                    QSqlRecord record = targetModel->record(0);
                    record.setValue("start_time", startTime);
                    record.setValue("end_time", endTime);

                    targetModel->setRecord(0, record);
                    targetModel->submitAll();
                }
                delete targetModel;
            }
        }
        emit update_taskinfo();
        db.commit();
    } else {
        db.rollback();
    }
}
//更新任务
void ParseData::updateTask(int taskId, int targetId, const QString &rawFileName, const QString &datFileName, const QString &gpsFileName, const QString &jzFileName)
{
    if (targetId == HysMainWindow::SELF_DATA) {
        TaskModel *model = new TaskModel(this, HysDbHelper::getInstance()->getDb());
        model->setFilter(QString("id=%1").arg(taskId));
        model->select();

        if (model->rowCount() != 1) {
            return;
        }
        QSqlRecord record = model->record(0);
        // 将文件路径保存到数据库
        record.setValue("raw_data_path", rawFileName);
        record.setValue("dat_data_path", datFileName);
        record.setValue("gps_data_path", gpsFileName);
        record.setValue("jz_data_path", jzFileName);

        model->setRecord(0, record);
        model->submitAll();

        delete model;
    } else {
        // 目标舰
        TargetModel *targetModel = new TargetModel(this, HysDbHelper::getInstance()->getDb());
        targetModel->setFilter(QString("id=%1").arg(targetId));
        targetModel->select();
        if (targetModel->rowCount() == 1) {
            QSqlRecord record = targetModel->record(0);
            record.setValue("raw_data_path", rawFileName);
            record.setValue("dat_data_path", datFileName);
            record.setValue("gps_data_path", gpsFileName);
            record.setValue("jz_data_path", jzFileName);

            targetModel->setRecord(0, record);
            targetModel->submitAll();
        }
        delete targetModel;
    }
}

bool ParseData::checkDatFileSerialization(int taskId, int targetId)
{
    QString appDir = QCoreApplication::applicationDirPath();
    QFile cpFile(QString("%1/%2_%3_cpdata.bin").arg(appDir).arg(taskId).arg(targetId)),
            edFile(QString("%1/%2_%3_eddata.bin").arg(appDir).arg(taskId).arg(targetId)),
            noiselFile(QString("%1/%2_%3_noiseldata.bin").arg(appDir).arg(taskId).arg(targetId)),
            noisesFile(QString("%1/%2_%3_noisesdata.bin").arg(appDir).arg(taskId).arg(targetId)),
            fsdFile(QString("%1/%2_%3_fsddata.bin").arg(appDir).arg(taskId).arg(targetId)),
            lofarFile(QString("%1/%2_%3_lofardata.bin").arg(appDir).arg(taskId).arg(targetId)),
            demonFile(QString("%1/%2_%3_demondata.bin").arg(appDir).arg(taskId).arg(targetId)),
            echoFile(QString("%1/%2_%3_echodata.bin").arg(appDir).arg(taskId).arg(targetId)),
            noFile(QString("%1/%2_%3_nodata.bin").arg(appDir).arg(taskId).arg(targetId));

    if (cpFile.exists() && edFile.exists() && noiselFile.exists() && noisesFile.exists() &&
            fsdFile.exists() && lofarFile.exists() && demonFile.exists() && echoFile.exists() && noFile.exists()) {
        return true;
    }

    return false;
}

void ParseData::deserializeDatFileForScene(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double> > &cpData, QMultiMap<QString, QVector<double> > &edData, QMultiMap<QString, QVector<double> > &noiselData
                                           , QMultiMap<QString, QVector<double> > &noisesData, QMultiMap<QString, QVector<double> > &fsdData, QMultiMap<QString, QVector<double> > &lofarData, QMultiMap<QString, QVector<double> > &demonData
                                           , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData)
{
    qDebug()<<"deserialize";
    QString appDir = QCoreApplication::applicationDirPath();
    QFile cpFile(QString("%1/%2_%3_cpdata.bin").arg(appDir).arg(taskId).arg(targetId)),
            edFile(QString("%1/%2_%3_eddata.bin").arg(appDir).arg(taskId).arg(targetId)),
            noiselFile(QString("%1/%2_%3_noiseldata.bin").arg(appDir).arg(taskId).arg(targetId)),
            noisesFile(QString("%1/%2_%3_noisesdata.bin").arg(appDir).arg(taskId).arg(targetId)),
            fsdFile(QString("%1/%2_%3_fsddata.bin").arg(appDir).arg(taskId).arg(targetId)),
            lofarFile(QString("%1/%2_%3_lofardata.bin").arg(appDir).arg(taskId).arg(targetId)),
            demonFile(QString("%1/%2_%3_demondata.bin").arg(appDir).arg(taskId).arg(targetId)),
            echoFile(QString("%1/%2_%3_echodata.bin").arg(appDir).arg(taskId).arg(targetId)),
            noFile(QString("%1/%2_%3_nodata.bin").arg(appDir).arg(taskId).arg(targetId));

    cpFile.open(QIODevice::ReadOnly);
    edFile.open(QIODevice::ReadOnly);
    noiselFile.open(QIODevice::ReadOnly);
    noisesFile.open(QIODevice::ReadOnly);
    fsdFile.open(QIODevice::ReadOnly);
    lofarFile.open(QIODevice::ReadOnly);
    demonFile.open(QIODevice::ReadOnly);
    echoFile.open(QIODevice::ReadOnly);
    noFile.open(QIODevice::ReadOnly);

    QDateTime startTime, endTime;
    // CP数据
    QDataStream cpStream(&cpFile), edStream(&edFile), noiselStream(&noiselFile), noisesStream(&noisesFile), fsdStream(&fsdFile), lofarStream(&lofarFile), demonStream(&demonFile), echoStream(&echoFile), noStream(&noFile);
    cpStream >> cpData >> startTime >> endTime;
    emit send_cpdata(startTime, endTime, cpData);

    // ED数据
    edStream >> edData >> startTime >> endTime;
    emit send_eddata(startTime, endTime, edData);

    // NoiseL数据
    noiselStream >> noiselData >> startTime >> endTime;
    emit send_noiseldata(startTime, endTime, noiselData);

    // NoiseS数据
    noisesStream >> noisesData >> startTime >> endTime;
    emit send_noisesdata(startTime, endTime, noisesData);

    // FSD数据
    fsdStream >> fsdData >> startTime >> endTime;
    emit send_fsddata(startTime, endTime, fsdData);

    // Lofar数据
    lofarStream >> lofarData >> startTime >> endTime;
    emit send_lofardata(startTime, endTime, lofarData);

    // Demon数据
    demonStream >> demonData >> startTime >> endTime;
    emit send_demondata(startTime, endTime, demonData);

// Echo数据
    echoStream >> echoData >> startTime >> endTime;
    emit send_echodata(startTime, endTime, echoData);

// No数据
    noStream >> noData >> startTime >> endTime;
    emit send_echodata(startTime, endTime, noData);

    cpFile.close();
    edFile.close();
    noiselFile.close();
    noisesFile.close();
    fsdFile.close();
    lofarFile.close();
    demonFile.close();
    echoFile.close();
    noFile.close();
}

//为场景解析Dat文件
void ParseData::parseDatFileForScene(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                                     , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                                     , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData)
{
    QString appDir = QCoreApplication::applicationDirPath();

    std::string datFile_str = datFileName.toStdString();
    const char* datCh = datFile_str.c_str();
    mwArray datFile(datCh);

    int nargout = 27;	//输出变量个数
    mwArray matrixDataCP;
    mwArray matrixTimeCP;
    mwArray matrixLenCP;

    mwArray matrixDataED;
    mwArray matrixTimeED;
    mwArray matrixLenED;

    mwArray matrixDataFSD;
    mwArray matrixTimeFSD;
    mwArray matrixLenFSD;

    mwArray matrixDataNoiseL;
    mwArray matrixTimeNoiseL;
    mwArray matrixLenNoiseL;

    mwArray matrixDataNoiseS;
    mwArray matrixTimeNoiseS;
    mwArray matrixLenNoiseS;

    mwArray matrixDataLOFAR;
    mwArray matrixTimeLOFAR;
    mwArray matrixLenLOFAR;

    mwArray matrixDataEcho(mxINT8_CLASS);
    mwArray matrixTimeEcho;
    mwArray matrixLenEcho;

    mwArray matrixDataNo(mxINT8_CLASS);
    mwArray matrixTimeNo;
    mwArray matrixLenNo;

    mwArray matrixDataDEMON;
    mwArray matrixTimeDEMON;
    mwArray matrixLenDEMON;

    qDebug()<<"file read";
    qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    F_CJRecorderDataRead(nargout, matrixDataCP, matrixTimeCP, matrixDataED, matrixDataFSD, matrixTimeED, matrixTimeFSD,
                         matrixDataNoiseL, matrixTimeNoiseL, matrixDataNoiseS,matrixTimeNoiseS, matrixLenCP, matrixLenED,
                         matrixLenFSD, matrixLenNoiseL, matrixLenNoiseS, matrixDataLOFAR, matrixTimeLOFAR, matrixDataEcho,
                         matrixTimeEcho, matrixDataNo, matrixTimeNo, matrixDataDEMON, matrixTimeDEMON, matrixLenLOFAR,
                         matrixLenEcho, matrixLenNo, matrixLenDEMON, datFile);
    qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    // 判断实际数据大小和声明大小是否一致
    int cpSize = matrixDataCP.NumberOfElements(), edSize = matrixDataED.NumberOfElements(), fsdSize = matrixDataFSD.NumberOfElements(),
            nlSize = matrixDataNoiseL.NumberOfElements(), nsSize = matrixDataNoiseS.NumberOfElements(), lofarSize = matrixDataLOFAR.NumberOfElements(),
            echoSize = matrixDataEcho.NumberOfElements(), noSize = matrixDataNo.NumberOfElements(), demonSize = matrixDataDEMON.NumberOfElements();
    if (cpSize != (int)matrixLenCP(1,1) || edSize != (int)matrixLenED(1,1) || fsdSize != (int)matrixLenFSD(1,1) ||
            nlSize != (int)matrixLenNoiseL(1,1) || nsSize != (int)matrixLenNoiseS(1,1) || lofarSize != (int)matrixLenLOFAR(1,1) ||
            echoSize != (int)matrixLenEcho(1,1) || noSize != (int)matrixLenNo(1,1) || demonSize != (int)matrixLenDEMON(1,1)) {
        qDebug()<<"size not correct";
        return;
    }

    // CP数据
    operateDataAfterParse(taskId, targetId, "CP", matrixDataCP, matrixTimeCP, cpData);

    //ED数据
    operateDataAfterParse(taskId, targetId, "ED", matrixDataED, matrixTimeED, edData);

    //NoiseL数据
    operateDataAfterParse(taskId, targetId, "NOISEL", matrixDataNoiseL, matrixTimeNoiseL, noiselData);

    //NoiseS数据
    operateDataAfterParse(taskId, targetId, "NOISES", matrixDataNoiseS, matrixTimeNoiseS, noisesData);

    //FSD数据
    operateDataAfterParse(taskId, targetId, "FSD", matrixDataFSD, matrixTimeFSD, fsdData);

    //LOFAR数据
    operateDataAfterParse(taskId, targetId, "LOFAR", matrixDataLOFAR, matrixTimeLOFAR, lofarData);

    //Demon数据
    operateDataAfterParse(taskId, targetId, "DEMON", matrixDataDEMON, matrixTimeDEMON, demonData);

    //Echo数据
    operateDataAfterParseAtByte(taskId, targetId, "ECHO", matrixDataEcho, matrixTimeEcho, echoData);

    //No数据
    operateDataAfterParseAtByte(taskId, targetId, "NO", matrixDataNo, matrixTimeNo, noData);
}
//时间格式化
QString ParseData::formatTime(int year1, int year2, int month, int day, int hour, int minute, int seconds)
{
    int year = year1 + year2 * 256;

    QString tmp = QString("%1-%2-%3 %4:%5:%6").arg(year).arg(month, 2, 10, QChar('0')).arg(day, 2, 10, QChar('0')).arg(hour, 2, 10, QChar('0')).arg(minute, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    return tmp;
}

void ParseData::operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<double>> &output)
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString targetFileName;
    if ("CP" == dType) {
        targetFileName = QString("%1/%2_%3_cpdata.bin").arg(appDir).arg(taskId).arg(targetId);
    } else if ("ED" == dType) {
        targetFileName = QString("%1/%2_%3_eddata.bin").arg(appDir).arg(taskId).arg(targetId);
    } else if ("NOISEL" == dType) {
        targetFileName = QString("%1/%2_%3_noiseldata.bin").arg(appDir).arg(taskId).arg(targetId);
    } else if ("NOISES" == dType) {
        targetFileName = QString("%1/%2_%3_noisesdata.bin").arg(appDir).arg(taskId).arg(targetId);
    } else if ("FSD" == dType) {
        targetFileName = QString("%1/%2_%3_fsddata.bin").arg(appDir).arg(taskId).arg(targetId);
    } else if ("LOFAR" == dType) {
        targetFileName = QString("%1/%2_%3_lofardata.bin").arg(appDir).arg(taskId).arg(targetId);
    } else if ("DEMON" == dType) {
        targetFileName = QString("%1/%2_%3_demondata.bin").arg(appDir).arg(taskId).arg(targetId);
    }
    QFile targetFile(targetFileName);

    targetFile.open(QIODevice::WriteOnly);
    QDataStream targetStream(&targetFile);

    int size = inData.NumberOfElements();
    if (size != 0) {
        int xSize = inData.GetDimensions()(1, 1), ySize = inData.GetDimensions()(1, 2);
        for (int i=1;i<=xSize;i++) {
            // 读取时间, 9个字节， xx(年)x(月)x(日)x(时)x(分)x(秒)xx(毫秒)
            QString tmp = formatTime(inTime(i, 1), inTime(i, 2), inTime(i, 3), inTime(i, 4), inTime(i, 5), inTime(i, 6), inTime(i, 7));
            QVector<double> values;
            for (int j=1;j<=ySize;j++) {
                values.append(inData(i,j));
            }
            output.insert(tmp, values);
        }
        QString startTime = formatTime(inTime(1, 1), inTime(1, 2), inTime(1, 3), inTime(1, 4), inTime(1, 5), inTime(1, 6), inTime(1, 7));
        QString endTime = formatTime(inTime(xSize, 1), inTime(xSize, 2), inTime(xSize, 3), inTime(xSize, 4), inTime(xSize, 5), inTime(xSize, 6), inTime(xSize, 7));

        QDateTime sDateTime = QDateTime::fromString(startTime, "yyyy-MM-dd hh:mm:ss");
        QDateTime eDateTime = QDateTime::fromString(endTime, "yyyy-MM-dd hh:mm:ss");

        targetStream << output;
        targetStream << sDateTime;
        targetStream << eDateTime;

        if ("CP" == dType) {
            emit send_cpdata(sDateTime, eDateTime, output);
        } else if ("ED" == dType) {
            emit send_eddata(sDateTime, eDateTime, output);
        } else if ("NOISEL" == dType) {
            emit send_noiseldata(sDateTime, eDateTime, output);
        } else if ("NOISES" == dType) {
            emit send_noisesdata(sDateTime, eDateTime, output);
        } else if ("FSD" == dType) {
            emit send_fsddata(sDateTime, eDateTime, output);
        } else if ("LOFAR" == dType) {
            emit send_lofardata(sDateTime, eDateTime, output);
        } else if ("DEMON" == dType) {
            emit send_demondata(sDateTime, eDateTime, output);
        }
    }

    targetFile.close();
}

//解析数据后操作数据
void ParseData::operateDataAfterParseAtByte(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<quint8>> &output)
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString targetFileName;
    if ("ECHO" == dType) {
        targetFileName = QString("%1/%2_%3_echodata.bin").arg(appDir).arg(taskId).arg(targetId);
    } else if ("NO" == dType) {
        targetFileName = QString("%1/%2_%3_nodata.bin").arg(appDir).arg(taskId).arg(targetId);
    }
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
            output.insert(tmp, values);
        }
        QString startTime = formatTime(inTime(1, 1), inTime(1, 2), inTime(1, 3), inTime(1, 4), inTime(1, 5), inTime(1, 6), inTime(1, 7));
        QString endTime = formatTime(inTime(xSize, 1), inTime(xSize, 2), inTime(xSize, 3), inTime(xSize, 4), inTime(xSize, 5), inTime(xSize, 6), inTime(xSize, 7));

        QDateTime sDateTime = QDateTime::fromString(startTime, "yyyy-MM-dd hh:mm:ss");
        QDateTime eDateTime = QDateTime::fromString(endTime, "yyyy-MM-dd hh:mm:ss");

        targetStream << output;
        targetStream << sDateTime;
        targetStream << eDateTime;

        if ("ECHO" == dType) {
            emit send_echodata(sDateTime, eDateTime, output);
        } else if ("NO" == dType) {
            emit send_nodata(sDateTime, eDateTime, output);
        }
    }

    targetFile.close();
}
