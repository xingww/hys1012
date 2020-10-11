#ifndef HYSTITLEBAR_H
#define HYSTITLEBAR_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class HysTitleBar;
}

class HysTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit HysTitleBar(QWidget *parent = nullptr);
    void setWindowTitle(const QString &title);
    void resetMenu(int index);

    ~HysTitleBar();
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
    // 最大化/还原
    void updateMaximize();

    virtual void paintEvent(QPaintEvent *event) override;

protected slots:
    void onClicked();
signals:
    void setForm(int index);    
    void openSetting();

private:
    Ui::HysTitleBar *ui;

    QPoint m_start;//起始点
    QPoint m_end;//结束点
    bool m_leftButtonPressed;//鼠标左键按下标记
};

#endif // HYSTITLEBAR_H
