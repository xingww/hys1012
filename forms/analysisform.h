#ifndef ANALYSISFORM_H
#define ANALYSISFORM_H

#include "x31sceneform.h"
#include "x31jzform.h"
#include "x39sceneform.h"
#include "x39jzform.h"
#include "x25sceneform.h"
#include "x25jzform.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QMap>
#include "screenpas.h"//新增图片
#include "screenact.h"//新增图片


namespace Ui {
class AnalysisForm;
}

class AnalysisForm : public QWidget
{
    Q_OBJECT

public:
    explicit AnalysisForm(QWidget *parent = nullptr);
    ~AnalysisForm();
    Screenpas initUi();//新增图片

private slots:
    void setCurrentTaskId(int taskId);

    void enableComboBox(bool enable);

    void on_cbActpas_currentIndexChanged(int index);

private:
    void initUI();
    void switchForm();
    void hideWidget();

private:
    Ui::AnalysisForm *ui;
    QHBoxLayout *lhContainer;
    QLabel *lbTitle;
    QComboBox *cbActpas;

    X31SceneForm *x31Form;
    X31JzForm *x31JzForm;
    X39SceneForm *x39Form;
    X39JzForm *x39JzForm;
    X25SceneForm *x25Form;
    X25JzForm *x25JzForm;

    Screenpas *screenpas;//新增图片
    Screenact *screenact;//新增图片

    int taskId;

    int cbActpasValue = 0;

    int sonarTypeValue = -1;

    QMap<int, int> sonarMap;
    QMap<QString, QString> fileMap;
};

#endif // ANALYSISFORM_H
