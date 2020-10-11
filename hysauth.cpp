//平台授权

#include "hysauth.h"
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>

QString HysAuthHelper::configFileName = "auth.in";
HysAuthHelper* HysAuthHelper::instance = NULL;

HysAuthHelper::HysAuthHelper()
{
    this->lisences.append("BE0E75A0-BFC5-4D55-918A-7F8264C3DA7A");
    this->lisences.append("7DC6DB98-3849-4226-9669-33A593202F30");
    this->lisences.append("0D512F20-5E9F-4C6C-BC4C-3E6D8EFDE7CD");
    this->lisences.append("CD5909AD-2DF1-4798-9417-48C79A23F5C2");
    this->lisences.append("0E663354-DD55-4F90-8601-937430A25B44");
    this->lisences.append("C66C10BF-ECCB-410B-BCB7-3458ACCA1907");
    this->lisences.append("504F02C9-6EDB-4AFA-9D50-19879D9C2E55");
    this->lisences.append("2F59C92E-39F6-43A7-91D9-C5C4F809BC53");
    this->lisences.append("C985DB27-13C0-42D0-A42E-C332F943C9F8");
    this->lisences.append("94CBE65E-B914-49FE-BB09-64BD776C9F7E");

    QString curDir = QCoreApplication::applicationDirPath();
    QFile configFile(curDir + '/' + HysAuthHelper::configFileName);
    if (!configFile.open(QIODevice::ReadOnly))
        return;

    QDataStream in(&configFile);

    QByteArray result;
    in >> result;
    result = QByteArray::fromBase64(result);
    result = QByteArray::fromBase64(result);

    this->lisenceNo = QString::fromLatin1(result);
}

bool HysAuthHelper::save(QString number)
{
    QString curDir = QCoreApplication::applicationDirPath();
    QFile configFile(curDir + '/' + HysAuthHelper::configFileName);
    if (!configFile.open(QFile::QIODevice::WriteOnly)) {
        return false;
    }

    QByteArray array = number.toLatin1();

    array = array.toBase64().toBase64();

    QDataStream out(&configFile);
    out << array;
    configFile.close();

    return true;
}

bool HysAuthHelper::isAuthorized()
{
    if (this->lisenceNo.isEmpty()) {
        return false;
    }

    if (!this->lisences.contains(this->lisenceNo)) {
        return false;
    }

    return true;
}

bool HysAuthHelper::checkAuthorization(QString number)
{
    return !number.isEmpty() && this->lisences.contains(number);
}

HysAuthHelper* HysAuthHelper::getInstance()
{
    if (instance == NULL) {
        instance = new HysAuthHelper();
    }

    return instance;
}
