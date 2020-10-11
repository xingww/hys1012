#ifndef EXPORTFORM_H
#define EXPORTFORM_H

#include <QWidget>
#include <QMap>
#include <QTreeWidget>
#include <QComboBox>
#include "EncMapWidget.h"
#include "exportformdetect.h"
#include "exportformnchart.h"
#include <QHBoxLayout>
#include <QLabel>

namespace Ui {
class ExportForm;
}

class ExportForm : public QWidget
{
    Q_OBJECT

public:
    explicit ExportForm(QWidget *parent = nullptr);
    ~ExportForm();

private slots:
    void switchForm();
    void hideWidget();
    void on_navdetSel_currentIndexChanged(int index);
    void setCurrentTaskId(int taskId);

private:
    void initUI();

private:
    Ui::ExportForm *ui;
    QHBoxLayout *lhContainer;
    QLabel *lbTitle;

    exportFormdetect *exportformdetect;//新增图片
    exportFormnchart *exportformnchart;//新增图片

    QComboBox *navdetSel;
    int navdetSelValue = 0;

};

#endif // EXPORTFORM_H
