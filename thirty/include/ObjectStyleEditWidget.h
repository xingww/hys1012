#ifndef OBJECTSTYLEEDITWIDGET_H
#define OBJECTSTYLEEDITWIDGET_H

#include <QDialog>
#include "YimaEncDll.h"

class ObjectStyleEditWidgetData;
class ObjectStyleEditWidget : public QDialog
{
	Q_OBJECT
public:
	explicit ObjectStyleEditWidget(YMEncMapMan* _pEncMapMan, QWidget *parent = 0);
	~ObjectStyleEditWidget();
	bool ResetEditObjectPos(M_GEO_OBJ_POS _objPos);//重置编辑的物标
	void DeleteDialog();	//由于此窗体关闭时，默认隐藏，用此接口彻底删除

private :
	ObjectStyleEditWidgetData* d_ptr;
};

#endif // OBJECTSTYLEEDITWIDGET_H
