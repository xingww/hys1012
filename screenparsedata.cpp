#include "screenparsedata.h"
#include "libF_CJRecorderDataRead.h"
#include <QDataStream>
#include <QCoreApplication>
#include <QFile>
#include <QDebug>

//创建Screenparsedata对象
Screenparsedata::Screenparsedata()
{
}

void Screenparsedata::parse(int taskId, int targetId, const QString &fileName, QMultiMap<QString, QVector<double>> &cpData, QMultiMap<QString, QVector<double>> &edData, QMultiMap<QString, QVector<double>> &noiselData
                              , QMultiMap<QString, QVector<double>> &noisesData, QMultiMap<QString, QVector<double>> &fsdData, QMultiMap<QString, QVector<double>> &lofarData, QMultiMap<QString, QVector<double>> &demonData
                              , QMultiMap<QString, QVector<quint8>> &echoData, QMultiMap<QString, QVector<quint8>> &noData)
{
    //解析数据
    if (checkDatFileSerialization(taskId, targetId)) {
        deserializeDatFile(taskId, targetId, fileName, cpData, edData, noiselData, noisesData, fsdData, lofarData, demonData, echoData, noData);
    } else {
        parseDatFile(taskId, targetId, fileName, cpData, edData, noiselData, noisesData, fsdData, lofarData, demonData, echoData, noData);
    }
}

//检查数据文件序列化
bool Screenparsedata::checkDatFileSerialization(int taskId, int targetId)
{
    QFile cpFile(this->dataFileName(taskId, targetId, "CP"));
    QFile edFile(this->dataFileName(taskId, targetId, "ED"));
    QFile noiselFile(this->dataFileName(taskId, targetId, "NOISEL"));
    QFile noisesFile(this->dataFileName(taskId, targetId, "NOISES"));
    QFile fsdFile(this->dataFileName(taskId, targetId, "FSD"));
    QFile lofarFile(this->dataFileName(taskId, targetId, "LOFAR"));
    QFile demonFile(this->dataFileName(taskId, targetId, "DEMON"));
    QFile echoFile(this->dataFileName(taskId, targetId, "ECHO"));
    QFile noFile(this->dataFileName(taskId, targetId, "NO"));

    if (cpFile.exists() && edFile.exists() && noiselFile.exists() && noisesFile.exists() &&
            fsdFile.exists() && lofarFile.exists() && demonFile.exists() && echoFile.exists() && noFile.exists()) {
        return true;
    }
    return false;
}

//解析数据文件
void Screenparsedata::parseDatFile(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double> > &cpData, QMultiMap<QString, QVector<double> > &edData, QMultiMap<QString, QVector<double> > &noiselData, QMultiMap<QString, QVector<double> > &noisesData, QMultiMap<QString, QVector<double> > &fsdData, QMultiMap<QString, QVector<double> > &lofarData, QMultiMap<QString, QVector<double> > &demonData, QMultiMap<QString, QVector<quint8> > &echoData, QMultiMap<QString, QVector<quint8> > &noData)
{
    std::string datFile_str = datFileName.toStdString();//转换为标准字符串
    const char* datCh = datFile_str.c_str();//c_str()生成一个const char*指针，指向以空字符终止的数组
    mwArray datFile(datCh);//mwArray赋值datch

    int nargout = 27;	//输出变量个数，每组3个数据，共九组
    //定义cp数据，时间，长度
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

    F_CJRecorderDataRead(nargout, matrixDataCP, matrixTimeCP, matrixDataED, matrixDataFSD, matrixTimeED, matrixTimeFSD,
                         matrixDataNoiseL, matrixTimeNoiseL, matrixDataNoiseS,matrixTimeNoiseS, matrixLenCP, matrixLenED,
                         matrixLenFSD, matrixLenNoiseL, matrixLenNoiseS, matrixDataLOFAR, matrixTimeLOFAR, matrixDataEcho,
                         matrixTimeEcho, matrixDataNo, matrixTimeNo, matrixDataDEMON, matrixTimeDEMON, matrixLenLOFAR,
                         matrixLenEcho, matrixLenNo, matrixLenDEMON, datFile);

    // 判断实际数据大小和声明大小是否一致
    int cpSize = matrixDataCP.NumberOfElements(),
        edSize = matrixDataED.NumberOfElements(),
        fsdSize = matrixDataFSD.NumberOfElements(),
        nlSize = matrixDataNoiseL.NumberOfElements(),
        nsSize = matrixDataNoiseS.NumberOfElements(),
        lofarSize = matrixDataLOFAR.NumberOfElements(),
        echoSize = matrixDataEcho.NumberOfElements(),
        noSize = matrixDataNo.NumberOfElements(),
        demonSize = matrixDataDEMON.NumberOfElements();

    //判断每个数据的大小不为1
    if (cpSize != (int)matrixLenCP(1,1) || edSize != (int)matrixLenED(1,1) || fsdSize != (int)matrixLenFSD(1,1) ||
            nlSize != (int)matrixLenNoiseL(1,1) || nsSize != (int)matrixLenNoiseS(1,1) || lofarSize != (int)matrixLenLOFAR(1,1) ||
            echoSize != (int)matrixLenEcho(1,1) || noSize != (int)matrixLenNo(1,1) || demonSize != (int)matrixLenDEMON(1,1))
    {
        return;
    }

    //解析后的数据，调用operateDataAfterParse函数
    operateDataAfterParse(taskId, targetId, "CP", matrixDataCP, matrixTimeCP, cpData);
    operateDataAfterParse(taskId, targetId, "ED", matrixDataED, matrixTimeED, edData);
    operateDataAfterParse(taskId, targetId, "NOISEL", matrixDataNoiseL, matrixTimeNoiseL, noiselData);
    operateDataAfterParse(taskId, targetId, "NOISES", matrixDataNoiseS, matrixTimeNoiseS, noisesData);
    operateDataAfterParse(taskId, targetId, "FSD", matrixDataFSD, matrixTimeFSD, fsdData);
    operateDataAfterParse(taskId, targetId, "LOFAR", matrixDataLOFAR, matrixTimeLOFAR, lofarData);
    operateDataAfterParse(taskId, targetId, "DEMON", matrixDataDEMON, matrixTimeDEMON, demonData);
    operateDataAfterParseAtByte(taskId, targetId, "ECHO", matrixDataEcho, matrixTimeEcho, echoData);
    operateDataAfterParseAtByte(taskId, targetId, "NO", matrixDataNo, matrixTimeNo, noData);
}

//数据文件反序列化
void Screenparsedata::deserializeDatFile(int taskId, int targetId, const QString &datFileName, QMultiMap<QString, QVector<double> > &cpData, QMultiMap<QString, QVector<double> > &edData, QMultiMap<QString, QVector<double> > &noiselData, QMultiMap<QString, QVector<double> > &noisesData, QMultiMap<QString, QVector<double> > &fsdData, QMultiMap<QString, QVector<double> > &lofarData, QMultiMap<QString, QVector<double> > &demonData, QMultiMap<QString, QVector<quint8> > &echoData, QMultiMap<QString, QVector<quint8> > &noData)
{
    //创建cpFile等文件
    QFile cpFile(this->dataFileName(taskId, targetId, "CP"));
    QFile edFile(this->dataFileName(taskId, targetId, "ED"));
    QFile noiselFile(this->dataFileName(taskId, targetId, "NOISEL"));
    QFile noisesFile(this->dataFileName(taskId, targetId, "NOISES"));
    QFile fsdFile(this->dataFileName(taskId, targetId, "FSD"));
    QFile lofarFile(this->dataFileName(taskId, targetId, "LOFAR"));
    QFile demonFile(this->dataFileName(taskId, targetId, "DEMON"));
    QFile echoFile(this->dataFileName(taskId, targetId, "ECHO"));
    QFile noFile(this->dataFileName(taskId, targetId, "NO"));

    //打开cpFile等文件
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

    //读二进制数据
    QDataStream cpStream(&cpFile), edStream(&edFile), noiselStream(&noiselFile), noisesStream(&noisesFile), fsdStream(&fsdFile), lofarStream(&lofarFile), demonStream(&demonFile), echoStream(&echoFile), noStream(&noFile);

    //cp数据
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
    emit send_nodata(startTime, endTime, noData);

    //关闭文件
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

//格式时间
QString Screenparsedata::formatTime(int year1, int year2, int month, int day, int hour, int minute, int seconds)
{
    int year = year1 + year2 * 256;
    //arg(month, 2, 10, QChar('0')), month为输入字符串，"2"为字符串宽度，"10"为十进制，"QChar('0'))"表示多余位填充字符串
    QString tmp = QString("%1-%2-%3 %4:%5:%6").arg(year).arg(month, 2, 10, QChar('0')).arg(day, 2, 10, QChar('0')).arg(hour, 2, 10, QChar('0')).arg(minute, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    return tmp;
    //时间格式为：年-月-日 时：分：秒
}

//文件名生成
QString Screenparsedata::dataFileName(int taskId, int targetId, QString dType)
{
    QString appDir = QCoreApplication::applicationDirPath();
    //文件名拼接
    //str = QString("%1 %2 (%3s-%4s)").arg("permissive").arg("society").arg(1950).arg(1970);
    //这段代码中，%1, %2, %3, %4作为占位符，将被后面的arg()函数中的内容依次替换，比如%1将被替换成permissive，
    //%2将被替换成society，%3将被替换成 1950，%4将被替换曾1970，最后，
    //这句代码输出为：permissive society (1950s-1970s). arg()函数比起sprintf()来是类型安全的，
    return QString("%1/%2_%3_%4_data.bin").arg(appDir).arg(taskId).arg(targetId).arg(dType);
}

//解析后数据操作
void Screenparsedata::operateDataAfterParse(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<double> > &output)
{
    QString targetFileName = this->dataFileName(taskId, targetId, dType);
    QFile targetFile(targetFileName);//给targetFile赋值

    targetFile.open(QIODevice::WriteOnly);//打开文件
    QDataStream targetStream(&targetFile);
    //开始时间及结束时间
    QDateTime sDateTime = QDateTime::fromString("1949-10-01 15:00:00", "yyyy-MM-dd hh:mm:ss");
    QDateTime eDateTime = QDateTime::fromString("1949-10-01 15:00:00", "yyyy-MM-dd hh:mm:ss");

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

        sDateTime = QDateTime::fromString(startTime, "yyyy-MM-dd hh:mm:ss");
        eDateTime = QDateTime::fromString(endTime, "yyyy-MM-dd hh:mm:ss");

        targetStream << output;
        targetStream << sDateTime;
        targetStream << eDateTime;
    }

    targetFile.close();

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
//解析数据Btye后的操作，仅Echo为此种类型数据解析
void Screenparsedata::operateDataAfterParseAtByte(int taskId, int targetId, QString dType, mwArray &inData, mwArray &inTime, QMultiMap<QString, QVector<quint8> > &output)
{
    QString targetFileName = this->dataFileName(taskId, targetId, dType);
    QFile targetFile(targetFileName);

    targetFile.open(QIODevice::WriteOnly);
    QDataStream targetStream(&targetFile);

    QDateTime sDateTime = QDateTime::fromString("1949-10-01 15:00:00", "yyyy-MM-dd hh:mm:ss");
    QDateTime eDateTime = QDateTime::fromString("1949-10-01 15:00:00", "yyyy-MM-dd hh:mm:ss");

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
        QString startTimeStr = formatTime(inTime(1, 1), inTime(1, 2), inTime(1, 3), inTime(1, 4), inTime(1, 5), inTime(1, 6), inTime(1, 7));
        QString endTimeStr = formatTime(inTime(xSize, 1), inTime(xSize, 2), inTime(xSize, 3), inTime(xSize, 4), inTime(xSize, 5), inTime(xSize, 6), inTime(xSize, 7));

        sDateTime = QDateTime::fromString(startTimeStr, "yyyy-MM-dd hh:mm:ss");
        eDateTime = QDateTime::fromString(endTimeStr, "yyyy-MM-dd hh:mm:ss");

        targetStream << output;
        targetStream << sDateTime;
        targetStream << eDateTime;
    }

    targetFile.close();

    if ("ECHO" == dType) {

        emit send_echodata(sDateTime, eDateTime, output);
    } else if ("NO" == dType) {

        emit send_nodata(sDateTime, eDateTime, output);
    }
}
