#pro配置
    #QT       += core gui sql network
    #greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
    #CONFIG += c++11
    #CONFIG += qwt
    #DEFINES += QT_DEPRECATED_WARNINGS
    #定义源文件
    #SOURCES += \
    #添加头文件
    #HEADERS += \
    #添加图形文件
    #FORMS += \
    # 指定编译项目时应该被搜索的
    #include目录
    #指定资源文件 (qrc) 的名称
    #RESOURCES += \
    #更改数据库路径
    #win32: LIBS += -L$$quote(C:/MySQL-5_7_22/lib/) -llibmysql

#core为QT内核
# GUI图形界面
# sql数据库
# network网络
#QT += coregui 需要引用工程的模块，core表示核心模块，gui表示界面模块。Qt的代码都是模块化方式组织的，如果你想引入某方面的功能，就需要将对应模块引入到你的工程中。例如我想添加数据库模块，则可以写成QT += core gui sql。
QT       += core gui sql network

#如果QT主版本大于4（也就是说当前使用的是Qt5或者更高版本），则需要添加widgets模块
#这是Qt5为了兼容Qt4而专门设计的，语句大意为如果Qt版本大于4，则将widgets模块加入到QT变量中，从这一点，我们可以推敲出Qt4的widgets模块是和gui模块为一体的，而Qt5已经将其分离了出来。

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#使用C++11的标准进行编译
CONFIG += c++11

#添加QWT库
CONFIG += qwt


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#定义编译选项。QT_DEPRECATED_WARNINGS表示当Qt的某些功能被标记为过时的，那么编译器会发出警告。
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#定义源文件
SOURCES += \
    curveplot.cpp \
    exportformdetect.cpp \
    exportformdisplay.cpp \
    exportformnchart.cpp \
    forms/analysisform.cpp \
    forms/exportform.cpp \
    forms/homeform.cpp \
    forms/mapform.cpp \
    hysauth.cpp \
    hysdb.cpp \
    hysmainwindow.cpp \
    lisencedialog.cpp \
    main.cpp \
    mframepcolorplot.cpp \
    models/attentionmodel.cpp \
    models/gpsmodel.cpp \
    models/targetmodel.cpp \
    models/taskmodel.cpp \
    mpcolorplot.cpp \
    mstreamframepcolorplot.cpp \
    mstreampcolorplot.cpp \
    newattentiondialog.cpp \
    newtargetdialog.cpp \
    newtaskdialog.cpp \
    parsedata.cpp \
    screenact.cpp \
    screenparsedata.cpp \
    screenpas.cpp \
    settingdialog.cpp \
    viewattentiondialog.cpp \
    widget/basetitlebar.cpp \
    widget/hystitlebar.cpp \
    widgetscreen.cpp \
    widgetscreenact.cpp \
    x25jzform.cpp \
    x25sceneform.cpp \
    x31jzform.cpp \
    x31jzparsedata.cpp \
    x31sceneform.cpp \
    x31sceneparsedata.cpp \
    x39jzform.cpp \
    x39sceneform.cpp \
    x39sceneparsedata.cpp


#添加头文件
HEADERS += \
    curveplot.h \
    exportformdetect.h \
    exportformdisplay.h \
    exportformnchart.h \
    forms/analysisform.h \
    forms/exportform.h \
    forms/homeform.h \
    forms/mapform.h \
    hysauth.h \
    hysdb.h \
    hysmainwindow.h \
    lisencedialog.h \
    m_colormap.h \
    m_raster_data.h \
    mframepcolorplot.h \
    models/attentionmodel.h \
    models/gpsmodel.h \
    models/targetmodel.h \
    models/taskmodel.h \
    mpcolorplot.h \
    mstreamframepcolorplot.h \
    mstreampcolorplot.h \
    newattentiondialog.h \
    newtargetdialog.h \
    newtaskdialog.h \
    parsedata.h \
    run_status.h \
    screenact.h \
    screenparsedata.h \
    screenpas.h \
    settingdialog.h \
    thirty/include/EncMapWidget.h \
    thirty/include/F_CJPassiveX1.h \
    thirty/include/F_DataCJBZHX1.h \
    thirty/include/Get_X1CJTime.h \
    thirty/include/ObjectStyleEditWidget.h \
    thirty/include/YIMAENCHEAD.H \
    thirty/include/YimaEncDll.h \
    thirty/include/YimaEncDll_Global.h \
    thirty/include/libdat3x9apre.h \
    thirty/include/libread3x9a.h \
    viewattentiondialog.h \
    widget/basetitlebar.h \
    widget/hystitlebar.h \
    widgetscreen.h \
    widgetscreenact.h \
    x25jzform.h \
    x25sceneform.h \
    x31jzform.h \
    x31jzparsedata.h \
    x31sceneform.h \
    x31sceneparsedata.h \
    x39jzform.h \
    x39sceneform.h \
    x39sceneparsedata.h

#添加图形文件
FORMS += \
    analysisform.ui \
    basetitlebar.ui \
    exportform.ui \
    exportformdetect.ui \
    exportformdisplay.ui \
    exportformnchart.ui \
    homeform.ui \
    hysmainwindow.ui \
    hystitlebar.ui \
    lisencedialog.ui \
    mapform.ui \
    newattentiondialog.ui \
    newtargetdialog.ui \
    newtaskdialog.ui \
    screenact.ui \
    screenpas.ui \
    settingdialog.ui \
    viewattentiondialog.ui \
    widgetscreen.ui \
    widgetscreenact.ui \
    x25jzform.ui \
    x25sceneform.ui \
    x31jzactiveform.ui \
    x31jzform.ui \
    x31jzpassiveform.ui \
    x31scactiveform.ui \
    x31sceneform.ui \
    x31scpassiveform.ui \
    x39jzform.ui \
    x39scactiveform.ui \
    x39sceneform.ui \
    x39scpassiveform.ui

# Default rules for deployment.部署的默认规则
#应为固定格式
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# matlab头文件
# 指定编译项目时应该被搜索的#include目录
# quote表示引用带空格路径
INCLUDEPATH += $$quote(d:/MATLAB/R2016b/extern/include)           //quote为支持带空格文件目录
INCLUDEPATH += $$quote(d:/MATLAB/R2016b/extern/include/Win64)

#INCLUDEPATH += "d:/MATLAB/R2016b/extern/include"                   //如文件目录不带空格，可直接引用
#INCLUDEPATH += "d:/MATLAB/R2016b/extern/include/Win64"

INCLUDEPATH += $$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/)

##程序编译时依赖的相关路径
DEPENDPATH += $$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/)

#LIBS += -L folderPath  //引入的lib文件的路径  -L：引入路径
unix|win32: LIBS += -L$$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/) -llibmex
unix|win32: LIBS += -L$$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/) -llibmx
unix|win32: LIBS += -L$$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/) -llibmat
unix|win32: LIBS += -L$$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/) -llibeng
unix|win32: LIBS += -L$$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/) -lmclmcr
unix|win32: LIBS += -L$$quote(d:/MATLAB/R2016b/extern/lib/win64/microsoft/) -lmclmcrrt

# 715所数据解析包
#”-L$$PWD/“    表示 .pro所在目录
win32: LIBS += -L$$PWD/thirty/lib/ -llibdat3x9apre
win32: LIBS += -L$$PWD/thirty/lib/ -llibgetStartT0
win32: LIBS += -L$$PWD/thirty/lib/ -llibread3x9a
win32: LIBS += -L$$PWD/thirty/lib/ -llibF_CJRecorderDataRead
win32: LIBS += -L$$PWD/thirty/lib/ -llibF_Track_Lofar_Demon
win32: LIBS += -L$$PWD/thirty/lib/ -llibF_HFM_Processing
win32: LIBS += -L$$PWD/thirty/lib/ -llibF_passive

#x31scene
win32: LIBS += -L$$PWD/thirty/lib/x31scene/ -llibF_CJRecorderDataRead_CP
win32: LIBS += -L$$PWD/thirty/lib/x31scene/ -llibF_CJRecorderDataRead_DEMON
win32: LIBS += -L$$PWD/thirty/lib/x31scene/ -llibF_CJRecorderDataRead_HFMTRACK
win32: LIBS += -L$$PWD/thirty/lib/x31scene/ -llibF_CJRecorderDataRead_LOFAR
win32: LIBS += -L$$PWD/thirty/lib/x31scene/ -llibF_CJRecorderDataRead_MultiLOFAR
win32: LIBS += -L$$PWD/thirty/lib/x31scene/ -llibF_CJRecorderDataRead_Passive
win32: LIBS += -L$$PWD/thirty/lib/x31scene/ -llibF_CJRecorderDataRead_PassiveTRACK

# Enc海图
# 配置信息
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/thirty/lib/ -lYimaEncDll_d
}
else: {
    CONFIG(release, debug|release): LIBS += -L$$PWD/thirty/lib/ -lYimaEncDll
}

INCLUDEPATH += $$PWD/thirty/include
DEPENDPATH += $$PWD/thirty/include
INCLUDEPATH += $$PWD/thirty/include/x31scene
DEPENDPATH += $$PWD/thirty/include/x31scene

include ( $$quote(C:/Qwt-6.1.4/features/qwt.prf) )

#指定资源文件 (qrc) 的名称
RESOURCES += \
    icons.qrc

#更改数据库路径
#win32: LIBS += -L$$PWD/'../../Program Files/mysql-5.7.22-winx64/lib/' -llibmysql
win32: LIBS += -L$$quote(C:/MySQL-5_7_22/lib/) -llibmysql

INCLUDEPATH += $$quote(C:/MySQL-5_7_22/include)

win32: LIBS += -L$$PWD/thirty/lib/ -lF_CJPassiveX1
