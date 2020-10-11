#ifndef HYSDB_H
#define HYSDB_H
#include <QString>
#include <QMap>
#include <QThread>
#include <QObject>
#include <QSqlDatabase>

class HysDbHelper
{
private:
    HysDbHelper();

public:
    ~HysDbHelper();
    //isOpen, ture打开，false关闭
    bool isOpen();
    bool init();
    bool save(QString host, QString user, QString pwd, QString port="3306", QString db="yjs");
    QSqlDatabase getDb();
    bool test(QString host, QString user, QString pwd, QString port="3306", QString db="yjs");

    QString getHost() const;
    QString getUser() const;
    QString getPwd() const;
    QString getPort() const;

    static HysDbHelper* getInstance();

private:
    QString host;
    QString user;
    QString pwd;
    QString port;
    QString db;

private:
    static QString configFileName;
    static HysDbHelper *instance;
};

#endif // HYSDB_H
