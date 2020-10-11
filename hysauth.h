#ifndef HYSAUTHHELPER_H
#define HYSAUTHHELPER_H

#include <QString>
#include <QStringList>

class HysAuthHelper
{
private:
    HysAuthHelper();

public:
    bool isAuthorized();
    bool checkAuthorization(QString number);
    bool save(QString number);

    static HysAuthHelper* getInstance();

private:
    static QString configFileName;
    static HysAuthHelper *instance;

    QStringList lisences;
    QString lisenceNo;
};

#endif // HYSAUTHHELPER_H
