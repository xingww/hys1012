//头文件
//#include ""为非标准头文件
//#include <>为标准头文件
#include "hysmainwindow.h"
#include "lisencedialog.h"
#include "hysauth.h"
//线程头文件
#include <QThread>
#include <QApplication>
#include <QFile>
//#include <QThread>

#include "libF_CJRecorderDataRead.h"
#include "libF_HFM_Processing.h"
#include "libF_Track_Lofar_Demon.h"
#include "libF_passive.h"
#include "libdat3x9apre.h"
#include "libgetStartT0.h"
#include "libread3x9a.h"

//modify2
#include "F_CJPassiveX1.h"
//#include "F_DataCJBZHX1.h"
//#include "Get_X1CJTime.h"

#include "libF_CJRecorderDataRead_CP.h"
#include "libF_CJRecorderDataRead_DEMON.h"
#include "libF_CJRecorderDataRead_HFMTRACK.h"
#include "libF_CJRecorderDataRead_LOFAR.h"
#include "libF_CJRecorderDataRead_MultiLOFAR.h"
#include "libF_CJRecorderDataRead_Passive.h"
#include "libF_CJRecorderDataRead_PassiveTRACK.h"

#include "YimaEncDll.h"

//定义一个isMatlabtInit的布尔变量
bool isMatlabInit = false;

class InitMatlabThread : public QThread {
    void run()
    {
        //初始化matlab
        init_matlab();
    }

private:
    void init_matlab()
    {
        //把”start“这几个字符打印到标准输出上（通常是控制台），并追加一个换行（std::endl是换行）
        std::cout<<"start"<<std::endl;

        //初始化
        libF_CJRecorderDataReadInitialize();
        libF_HFM_ProcessingInitialize();
        libF_Track_Lofar_DemonInitialize();
        libF_passiveInitialize();
        libdat3x9apreInitialize();
        libgetStartT0Initialize();
        libread3x9aInitialize();

        //modify2
//       F_CJPassiveX1Initialize();
  //      F_DataCJBZHX1Initialize();
  //      Get_X1CJTimeInitialize();

        libF_CJRecorderDataRead_CPInitialize();
        libF_CJRecorderDataRead_DEMONInitialize();
        libF_CJRecorderDataRead_LOFARInitialize();
        libF_CJRecorderDataRead_PassiveInitialize();
        libF_CJRecorderDataRead_MultiLOFARInitialize();
        libF_CJRecorderDataRead_PassiveTRACKInitialize();
        libF_CJRecorderDataRead_HFMTRACKInitialize();

        //初始化成功
        isMatlabInit = true;

        //把”end“这几个字符打印到标准输出上（通常是控制台），并追加一个换行（std::endl是换行）
        std::cout<<"end"<<std::endl;
    }
};


//主函数运行
int main(int argc, char *argv[])
{
    // 每个线程创建一个数据库连接，不然不能复用

    //定义当前线程的指针，静态函数
    QThread *current = QThread::currentThread();
    //给该线程起一个名字叫做"main_app"
    current->setObjectName("main_app");

    //初始化Matlab线程类
    InitMatlabThread thread;
    thread.start();

    //定义了一个 QApplication 类的实例 a，就是应用程序对象
    //定义并创建应用程序
    QApplication a(argc, argv);

    //调用工程资源文件
    QFile qssFile(":/style.qss");
    qssFile.open(QFile::ReadOnly);
    a.setStyleSheet(QString::fromLocal8Bit(qssFile.readAll()));
    qssFile.close();

    //定义并创建窗口指针
    LisenceDialog *lsDialog;
    HysMainWindow *w;
    //授权后显示窗口
    if (!HysAuthHelper::getInstance()->isAuthorized()) {
        lsDialog = new LisenceDialog();
        lsDialog->show();
    } else {
        w = new HysMainWindow();
        //由于void setWindowTitle(const QString &title);因此title="中船重工七一五研究所数据采集系统"
        w->setWindowTitle(QString::fromLocal8Bit("中船重工七一五研究所数据采集系统"));
        w->show();
    }

    //循环执行
    return a.exec();
}
