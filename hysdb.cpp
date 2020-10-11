//数据解析
#include "hysdb.h"
#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>
#include <QCoreApplication>
#include <QDebug>

QString HysDbHelper::configFileName = "sys.in";
HysDbHelper* HysDbHelper::instance = NULL;

HysDbHelper::HysDbHelper()
{
    QString curDir = QCoreApplication::applicationDirPath();
    QFile configFile(curDir + '/' + HysDbHelper::configFileName);
    if (!configFile.open(QIODevice::ReadOnly))
        return;

    QDataStream in(&configFile);

    QByteArray result;
    in >> result;
    result = QByteArray::fromBase64(result);
    result = QByteArray::fromBase64(result);

    QString str = QString::fromLatin1(result);
//    qDebug()<<str;
    QStringList res = str.split("\n");
    if (res.count() == 5) {
        this->host = res.at(0);
        this->user = res.at(1);
        this->pwd = res.at(2);
        this->port = res.at(3);
        this->db = res.at(4);

        // 每个使用到连接的线程都设置一个ObjectName, 保证线程的连接不共用: 记住一定要明确设置线程名!
        QThread *curThread = QThread::currentThread();
        QString objName = curThread->objectName();
        if (objName.isEmpty()) {
            return;
        }
    }
}

HysDbHelper::~HysDbHelper()
{

}

bool HysDbHelper::isOpen()
{
    //判断主机，DB.用户，密码是否有空？有空的话返回false
    if (this->host.isEmpty() || this->db.isEmpty() || this->user.isEmpty() || this->pwd.isEmpty()) {
        return false;
    }
    // 每个使用到连接的线程都设置一个ObjectName, 保证线程的连接不共用: 记住一定要明确设置线程名!
    QThread *curThread = QThread::currentThread();
    QString objName = curThread->objectName();
    if (objName.isEmpty()) {
        return false;
    }

    QSqlDatabase db;
    if (QSqlDatabase::contains(objName)) {
        db = QSqlDatabase::database(objName);
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL", objName);
        db.setHostName(this->host);
        db.setPort(this->port.toInt());
        db.setDatabaseName(this->db);
        db.setUserName(this->user);
        db.setPassword(this->pwd);
    }

    db.setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT=2;");
    return db.open();
}

bool HysDbHelper::init()
{
    if (!isOpen()) {
        return false;
    }

    QSqlQuery query(getDb());
    // 任务表
    query.exec("CREATE TABLE IF NOT EXISTS task ("
               "id bigint(20) NOT NULL AUTO_INCREMENT,"
               "title varchar(200) NOT NULL COMMENT '数据名称',"
               "abbr varchar(200) DEFAULT NULL COMMENT '任务简称',"
               "area varchar(50) NOT NULL COMMENT '海区',"
               "crawl_time date NOT NULL COMMENT '采集时间',"
               "ship_name varchar(100) NOT NULL COMMENT '本舰名称',"
               "actor varchar(100) DEFAULT NULL COMMENT '值更长',"
               "author varchar(100) NOT NULL COMMENT '整编人',"
               "comment text COMMENT '备注信息',"
               "ship_type varchar(50) DEFAULT NULL COMMENT '本舰舰艇类型，字面值',"
               "sonar_type smallint(6) NOT NULL COMMENT '本舰声纳类型',"
               "raw_data_path varchar(300) DEFAULT NULL COMMENT '本舰原始数据路径',"
               "dat_data_path varchar(300) DEFAULT NULL COMMENT '本舰中间dat文件路径',"
               "gps_data_path varchar(300) DEFAULT NULL COMMENT '本舰gps文件路径',"
               "jz_data_path varchar(300) DEFAULT NULL COMMENT '本舰jz文件路径',"
               "listen_data_path varchar(300) DEFAULT NULL COMMENT '本舰收听文件路径',"
               "env_data_path varchar(300) DEFAULT NULL COMMENT '本舰环境文件路径',"
               "start_time datetime DEFAULT NULL COMMENT '本舰数据起始时间，源于gps文件',"
               "end_time datetime DEFAULT NULL COMMENT '本舰数据结束时间，源于gps文件',"
               "created_time datetime NOT NULL,"
               "modified_time datetime NOT NULL,"
               "PRIMARY KEY (`id`),"
               "KEY `i_title` (`title`),"
               "KEY `i_abbr` (`abbr`),"
               "KEY `i_area` (`abbr`),"
               "KEY `i_ship_name` (`ship_name`),"
               "KEY `i_actor` (`actor`),"
               "KEY `i_author` (`author`)"
               ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;");
    //GPS数据
    query.exec("CREATE TABLE IF NOT EXISTS gps_data ("
               "id bigint(20) NOT NULL AUTO_INCREMENT,"
               "task_id bigint(20) NOT NULL COMMENT '所属任务id',"
               "target_id bigint(20) NOT NULL COMMENT '目标id，默认为本舰0',"
               "crawl_time datetime NOT NULL COMMENT '采集时间',"
               "longitude double NOT NULL COMMENT '经度',"
               "latitude double NOT NULL COMMENT '纬度',"
               "created_time datetime NOT NULL,"
               "modified_time datetime NOT NULL,"
               "PRIMARY KEY (id)"
               ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;");

    // 事件表
    query.exec("CREATE TABLE IF NOT EXISTS attention ("
               "id bigint(20) NOT NULL AUTO_INCREMENT,"
               "task_id bigint(20) NOT NULL,"
               "target_id bigint(20) NOT NULL COMMENT '目标id，默认为本舰0',"
               "event_type smallint(6) NOT NULL COMMENT '事件类型',"
               "crawl_time datetime NOT NULL COMMENT '发生时间',"
               "longitude double NOT NULL COMMENT '经度',"
               "latitude double NOT NULL COMMENT '纬度',"
               "comment text COMMENT '备注',"
               "created_time datetime NOT NULL,"
               "modified_time datetime NOT NULL,"
               "PRIMARY KEY (id)"
               ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;");

    // 目标表
    query.exec("CREATE TABLE IF NOT EXISTS target_data ("
               "id bigint(20) NOT NULL AUTO_INCREMENT,"
               "task_id bigint(20) NOT NULL,"
               "name varchar(100) NOT NULL COMMENT '目标名称',"
               "ship_type varchar(50) DEFAULT NULL COMMENT '目标舰艇类型，字面值',"
               "sonar_type smallint(6) NOT NULL COMMENT '目标声纳类型',"
               "raw_data_path varchar(300) DEFAULT NULL COMMENT '原始文件路径',"
               "dat_data_path varchar(300) DEFAULT NULL COMMENT 'dat文件路径',"
               "gps_data_path varchar(300) DEFAULT NULL COMMENT 'gps文件路径',"
               "jz_data_path varchar(300) DEFAULT NULL COMMENT '基阵文件路径',"
               "listen_data_path varchar(300) DEFAULT NULL COMMENT '收听文件路径',"
               "env_data_path varchar(300) DEFAULT NULL COMMENT '环境文件路径',"
               "start_time datetime DEFAULT NULL,"
               "end_time datetime DEFAULT NULL,"
               "created_time datetime NOT NULL,"
               "modified_time datetime NOT NULL,"
               "PRIMARY KEY (id)"
               ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;");

    return true;
}
//保存用户主机，用户名，密码，端口等
bool HysDbHelper::save(QString host, QString user, QString pwd, QString port, QString db)
{
    QString curDir = QCoreApplication::applicationDirPath();
    QFile configFile(curDir + '/' + HysDbHelper::configFileName);
    if (!configFile.open(QFile::QIODevice::WriteOnly)) {
        return false;
    }

    this->host = host;
    this->user = user;
    this->pwd = pwd;
    this->port = port;
    this->db = db;

    QByteArray array = QString("%1\n%2\n%3\n%4\n%5").arg(host, user, pwd, port, db).toLatin1();
    array = array.toBase64().toBase64();

    QDataStream out(&configFile);
    out << array;
    configFile.close();

    return true;
}
//测试
bool HysDbHelper::test(QString host, QString user, QString pwd, QString port, QString dbName)
{
    if (host.isEmpty() || db.isEmpty() || user.isEmpty() || pwd.isEmpty()) {
        return false;
    }

    QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QMYSQL", "tmp_conn");
    db.setHostName(host);
    db.setPort(port.toInt());
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(pwd);

    db.setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT=2;");
    bool result = db.open();
    QSqlDatabase::removeDatabase("tmp_conn");

    return result;
}

HysDbHelper* HysDbHelper::getInstance()
{
    if (instance == NULL) {
        instance = new HysDbHelper();
    }

    return instance;
}

QString HysDbHelper::getHost() const
{
    return this->host;
}

QString HysDbHelper::getUser() const
{
    return this->user;
}

QString HysDbHelper::getPwd() const
{
    return this->pwd;
}

QString HysDbHelper::getPort() const
{
    if (this->port.isEmpty()) {
        return "3306";
    }
    return this->port;
}

// 必须保证调用在各个线程的isOpen之后调用，否则可能会取不到连接
QSqlDatabase HysDbHelper::getDb()
{
    QThread *curThread = QThread::currentThread();
    QString objName = curThread->objectName();
    QSqlDatabase db = QSqlDatabase::database(objName);
    return db;
}



