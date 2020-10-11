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
	bool ResetEditObjectPos(M_GEO_OBJ_POS _objPos);//���ñ༭�����
	void DeleteDialog();	//���ڴ˴���ر�ʱ��Ĭ�����أ��ô˽ӿڳ���ɾ��

private :
	ObjectStyleEditWidgetData* d_ptr;
};

#endif // OBJECTSTYLEEDITWIDGET_H
