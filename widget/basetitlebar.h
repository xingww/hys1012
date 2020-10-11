#ifndef BASETITLEBAR_H
#define BASETITLEBAR_H

#include <QWidget>

namespace Ui {
class BaseTitleBar;
}

class BaseTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit BaseTitleBar(QWidget *parent = nullptr);
    void setWindowTitle(const QString &title);
    ~BaseTitleBar();

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

protected slots:
    void onClicked();
private:
    Ui::BaseTitleBar *ui;
};

#endif // BASETITLEBAR_H
