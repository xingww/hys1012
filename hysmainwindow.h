#ifndef HYSMAINWINDOW_H
#define HYSMAINWINDOW_H

#include <QWidget>
#include <QThread>
#include <QProgressDialog>
#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include "parsedata.h"
#include "models/taskmodel.h"
#include "forms/homeform.h"
#include "forms/mapform.h"
#include "forms/analysisform.h"
#include "forms/exportform.h"
#include "exportformnchart.h"

//声明了一个名称为 Ui 的命名空间（namespace），包含一个类 Widget。但是这个类 Widget 并不是本文件里定义的类 Widget，而是 ui_widget.h 文件里定义的类，用于描述界面组件的。
namespace Ui {
class HysMainWindow;
}

//定义一个窗口类及宏
//.h 文件的主体部分是一个继承于QWidget的类Widget的定义，也就是本实例的窗体类。
class HysMainWindow : public QWidget
{
    Q_OBJECT

public:
    const static int SELF_DATA = 0;

    enum TreeItemType {
        UPDATA_ITEM = 1,
        EVENT_ITEM = 2,
        SELF_ITEM = 3,
        TARGET_ITEM = 4,
        OTHER_ITEM = 9
    };

    enum EventType {
        CONDITION = 1,
        PROBE = 2,
        MANUAL= 3
    };

    enum DataCate {
        RAW_DATA = 0,
        GPS_DATA = 1,
        JZ_DATA = 2,
        SCENE_DATA = 3,
        LISTEN_DATA = 4,
        ENV_DATA = 5
    };

    enum SonarType {
        X39 = 0,
        X31 = 1,
        X25 = 2
    };

//在 public 部分定义了 Widget 类的构造函数和析构函数。
public:
    HysMainWindow(QWidget *parent = nullptr);
    ~HysMainWindow();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private slots:
    void setCurrent(int index);
    void openSetting();

signals:
    void update_plot(int taskId, int scene, int dataType);
    void update_ana_taskId(int taskId);
    void update_map_taskId(int taskId);
    void update_export_taskId(int taskId);

private:
    void init();


//在 private 部分又定义了一个指针
//这个指针是用前面声明的 namespace Ui 里的 Widget 类定义的，所以指针 ui 是指向可视化设计的界面，后面会看到要访问界面上的组件，都需要通过这个指针 ui。
//为各个窗口定义指针
private:
    Ui::HysMainWindow *ui;
    HomeForm *homeWidget;
    MapForm *mapWidget;
    AnalysisForm *anaWidget;
    ExportForm *exWidget;
//    exportFormnchart *exWidget;

    int currentForm = 0;
};

#endif // HYSMAINWINDOW_H
