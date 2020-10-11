#include "basetitlebar.h"
#include "ui_basetitlebar.h"
#include <QStyleOption>
#include <QPainter>

BaseTitleBar::BaseTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseTitleBar)
{
    ui->setupUi(this);

    connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(onClicked()));
}

BaseTitleBar::~BaseTitleBar()
{
    delete ui;
}

void BaseTitleBar::setWindowTitle(const QString &title)
{
    ui->lbTitle->setAlignment(Qt::AlignLeft);
    ui->lbTitle->setText(title);
}

bool BaseTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type()) {
    case QEvent::WindowTitleChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            ui->lbTitle->setText(pWidget->windowTitle());
            return true;
        }
    }
    case QEvent::WindowIconChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            ui->lbIcon->setPixmap(icon.pixmap(ui->lbIcon->size()));
            return true;
        }
    }
    }

    return QWidget::eventFilter(obj, event);
}

void BaseTitleBar::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void BaseTitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == ui->btnClose)
        {
            pWindow->close();
        }
    }
}

