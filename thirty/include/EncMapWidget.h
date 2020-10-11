#ifndef ENCMAPWIDGET_H
#define ENCMAPWIDGET_H

#include <QWidget>
#include <QPainter>
#include "YimaEncDll.h"

class EncMapWidgetData; 
class EncMapWidget : public QWidget, public YMEncMapMan
{
	Q_OBJECT
private:
	EncMapWidgetData* d_ptr;
	friend class YMEncMapMan;
public:
	explicit EncMapWidget(QWidget *parent = 0);
	explicit EncMapWidget(const char* pStrWorkDirectory, QWidget *parent = 0);

    ~EncMapWidget();

	M_POINT GetCurrentDragMapOff();							//获取当前拖动状态下的偏移 
	void ReDrawWidgetMap(bool bForcyRefresh = false);		//刷新海图
	bool ToolAddPointObj(int layerPos);						//标绘点
	bool ToolAddLineObj(int layerPos, SPECIAL_LINE_TYPE specialLineType);	//标绘线
	bool ToolAddFaceObj(int layerPos, SPECIAL_LINE_TYPE specialFaceType);	//标绘面
	bool ToolMapMeasure(M_TOOl_TYPE toolType);				//电子方位线、测距、测面积等测量工具
	bool ToolMapEffect(bool bHollowOrDelay);				//空心、延迟
	bool ToolAddNewMap();									//新增海图视窗 
	bool ToolUserDefinedOperator();							//用户自定义操作
	void ToolEndUserDefinedOperator();						//结束用户自定义操作
	bool ToolEditingUserObject(int layerPos, int objPos);	//物标编辑
	bool ToolIsNoOperate();									//判断是否为空操作
	bool ToolIsInOperate(TOperatorType curOperate);			//判断是否在指定状态内 
	bool ToolClearCache();									//清除电子方位线、测距、测面积等留下的痕迹（功能同海图蓝色关闭按钮） 
	void ToolCancelAllOperation();							//退出所有操作 
    void ToolSetMapScaledMode(bool bCenterScaled);			//设置缩放模式，true=中心缩放 false = 定点缩放（默认值）
    void ToolSetMapDragMode(bool bRealtimeDrag);            //设置是否无缝漫游
	void ToolSetLimitScale(int maxScale, int minScale);		//设置缩放比例尺限制
	void ToolGetCurEditObjInfo(int& layerPos, int& objPos, int& nodePos, M_GEO_TYPE& geoType, SPECIAL_LINE_TYPE& specialType);//获取当前编辑节点信息，可用于删除节点
	void OpenMapDialog(const QString &caption = QString(), const QString &directory = QString());//添加海图数据
    void SetRenderMode(QPainter::RenderHint hint, bool bOnOrOff);//设置画笔平滑程度，bOnOrOff = false,不开启平滑画笔
    void SetAuthorityAddress(QString _AuthorityIP, int port, int waitMsecs);//设置自动授权地址
    void ReconnectAuthorization();                                          //（当授权失败后）重连授权服务

signals:
	//void OnMapScaleChanged();//使用信号槽或者虚方法
	void OnMouseLeftDowned(M_POINT point);	//左键按下
	void OnMouseRightDowned(M_POINT point);	//右键按下
	void OnMouseLeftUpped(M_POINT point);	//左键抬起
	void OnMouseRightUppped(M_POINT point);	//右键抬起
	void OnLeftMouseDoubleClick(QMouseEvent *event);	//左键双击
	void OnRightMouseDoubleClick(QMouseEvent *event);	//右键双击
	void OnMouseMove(QMouseEvent *event);	//鼠标移动
	void OnMouseWheel(QWheelEvent *event);	//鼠标滚轮
	//物标添加阶段：新增一个物标节点时
	void OnAddingNewNodeByTool(int layerPos, int objPos, M_GEO_TYPE geoType, SPECIAL_LINE_TYPE specialType, int nodePos, M_POINT nodeGeoPo); 
	//当添加完物标后，预留给用户设置风格的事件
	void OnEndAddObjectByTool(int layerPos, int objPos, M_GEO_TYPE geoType, SPECIAL_LINE_TYPE specialType);
	//编辑完物标坐标后，预留给用户保存数据库等操作
	void OnEndEditObjectByTool(int layerPos, int objPos, M_GEO_TYPE geoType, SPECIAL_LINE_TYPE specialType);
	//物标编辑阶段：修改物标坐标触发，changeState：1==在nodePos后添加了一个节点；2==移动了一个节点；3==移动了整个物标
	void OnObjectChangedByTool(int layerPos, int objPos, M_GEO_TYPE geoType, SPECIAL_LINE_TYPE specialType, int nodePos, M_POINT nodeGeoPoX, int changeState);
	void OnEndAddNewMapByTool(EncMapWidget* newEncMap, bool& retInitSuc);


    //叠加海图相关信号：
    //执行顺序：OnDrawAfterDrawShip-OnAferDrawMap-OnMapWorking
    void OnAfterDrawShip(QPainter* painter);
    void OnAferDrawMap(QPainter* painter);
    void OnMapWorking(QPainter* painter);
    void SelectedShip(int shipId);  //选中船舶:左击时选中船舶
    void AfterAuthorized(bool bSuc);//当每次验证完成后触发

protected:
	void paintEvent(QPaintEvent *event);
	void wheelEvent(QWheelEvent *event);
	void resizeEvent(QResizeEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
    void DrawAfterMaps(QPainter *p);
    void DrawAfterMapsExceptObject(QPainter *p);
};

#endif // ENCMAPWIDGET_H
