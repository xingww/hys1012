#ifndef YIMAENCDLL_H
#define YIMAENCDLL_H
#include "YIMAENCHEAD.H"
#include "YimaEncDll_Global.h"

class YMEncMapMan {

private:
   int* pMembers;
public:       

    void DrawWordMap(); //绘制世界地图，需把WORLD.ymp放在与maplib同级目录下（在mapLib外）
	
    int GetKeyNumber(); //获取ymc文件加密密码

    bool VerifyUserLicense(bool bShowMessageBox);//未实现

    void GetDeviceIDForLicSvr(char* retStrDevID);

    void SetLicenceKeyFromSvr(char* strKey);

    void ClearMemMaps(); //卸载内存中所有已加载的图幅

    bool EncryptYmcFile(const char* pStrSrcFileName, const char* pStrDstFileName, int iKeyNumber);//加密ymc文件
    bool DecryptYmcFile(const char* pStrSrcFileName, const char* pStrDstFileName, int iKeyNumber);//解密ymc文件

    void SetIfOnDrawRadarMode(bool bDrawRadarMode);//设置是否显示雷达
    bool GetIfOnDrawRadarMode();//获取当前雷达显示状态

    void SetIfOnAutoLoadMapMode(bool bUseAutoLoadMode);//是否采用自动载图模式
    //海图加载比例尺门限。数值越小，图幅需要放大到更大才能显示
    void SetLoadMapScaleFactor(float scaleFactorToOriginalScale, bool bOnJudgeSizeRatio = true, float loadMapJudgeSizeRatio = 4);
    float GetLoadMapScaleFactor(bool *pbOnJudgeSizeRatio = NULL, float *pfLoadMapJudgeSizeRatio = NULL);//获取当前的海图加载比例尺门限

    void SetHaloTextBakColor(M_COLOR haloColor); //设置text halo效果的背景色

    M_POINT GetSpherePoFromScrnPo(M_POINT scrnPoint);//根据屏幕坐标（像素）获取地理坐标

    M_POINT GetScrnPoFromSpherePo(M_POINT spherePoint);//根据平面左边获取屏幕坐标

   //********* assist drawer mangage, for drawing objects on non-main-map window ***********/ 
    bool DeleteEncScreen(ID_INT scrnID);//未实现
    bool SwitchToEncScreen(ID_INT scrnID);//未实现
    //绘制自定义图层的一个物标
    bool DrawUserMapLayerStyleAtPoint(int layerNum, int layerStyleNum, M_POINT scrnPoint,
									  const char* pStrExampleText, int drawStyleScopeWidth,
                                      M_COLOR backGroundColor);

   //********************** routes mangage *******************/

    bool AddRoutesFromFile(const char* pStrRouteFileName);//从文件读取航线
    bool SaveRoutesToFile(const char* pStrRouteFileName);//将所有航线保存到文件中

    int AddWayPoint(M_POINT point, const char* pStrName,
                            float radius, const char* strUsage, bool bIfShowPoint, bool bIfShowName);//添加新航路点
    int GetWayPointsCount();//获取所有航路点数量
    int GetWayPointIDFromPos(UINT wpPos);//根据航路点索引获取航路点ID
    UINT GetWayPointPosFromID(int wpID); //根据航路点ID获取航路点索引
    bool GetWayPointUsageString(int wpID, char* strUsage); //根据航路点ID获取用途
    bool DeleteWayPoint(int wpID); //根据Id删除航路点
    bool SetWayPointCoor(int wpID, M_POINT point);//设置某航路点坐标
    bool GetWayPointCoor(int wpID, M_POINT& retPoint);//获取某航路点坐标

	bool SetWayPointShowText(int wpPos, bool bSetText, const char* pStrText,
						   bool bSetFontSize, int fontSize, 
                           bool bSetColor, const M_COLOR* pFontColor, bool bStrTextIsUTF8Code = false);//设置航路点显示的文字及文字风格

    ROUTE_ID AddRoute(const char* pStrRouteName, const UINT* pWpIDs,
        int wpCount, bool bPlanedRouteOrAlterated);//添加航线
    bool DeleteRoute(ROUTE_ID routeID); //删除航线

    bool SetRouteName(ROUTE_ID routeID, const char* pRouteName);//设置航线名称
    bool SetRouteStyle(ROUTE_ID routeID, bool bSetColor,M_COLOR mColor,bool bSetWidth,int iWidth);
    int SelectWayPointIdByScrnPo(M_POINT scrnPo,int iCheckDis);
    int SelectRouteIdByScrnPo(M_POINT scrnPo,int iCheckDis);
    bool GetRouteName(long routeID, char* retRouteName);//获取指定航线名称
    int GetRouteWayPointsCount(ROUTE_ID routeID);  //获取指定航线的航路点数量
    int GetRouteWayPointsID(ROUTE_ID routeID, UINT* pWpIDs);//获取指定航线的所有航路点ID
    int GetRouteWayPointsCoor(ROUTE_ID routeID, M_POINT* pPoints); //获取指定航线的所有航路点坐标

	bool AddRouteWayPoint(ROUTE_ID routeID, int addWpPos,
        const UINT* pAddWpIDs, int addWpCount = 1);//给指定航线在addWpPos位置处插入一些航路点
    bool DeleteRouteWayPoint(ROUTE_ID routeID, int delWpPos, int delWpCount = 1);//删除一条航线上的指定位置处后的delWpCount个航路点
    bool SetRouteBePlannedOrAlternated(ROUTE_ID routeID, bool bPlanedRouteOrAlterated, bool bAlongOrBack); //设置指定航线是否为计划航线
    bool GetRouteBePlannedOrAlternated(ROUTE_ID routeID, bool& bPlanedRouteOrAlterated, bool &bAlongOrBack);//true：计划航线，false：备用航线

    bool SetWayPointShowOrNot(bool bSetAllWayPoints, int wpID, bool bShowOrNot);//设置全部或指定航路点显示与否

    bool SetRouteShowOrNot(bool bSetAllRoutes, ROUTE_ID routeID, bool bShowOrNot, bool bSetNewColor, M_COLOR color);//设置全部或指定航线显示与否

    int GetRoutesCount();//获取航线数量
	 
    ROUTE_ID GetRouteIDFromPos(long globalRoutePos);//根据航线索引获取航线ID
    UINT GetRoutePosFromID(ROUTE_ID routeID);       //根据航线ID获取航线索引
	/////////////////////////////////////////////////////////


	//////////////////// ship mangage ////////////////////
    SHIP_ID GetOtherVesselID(int vesselNum);//根据目标船索引获取船舶ID
    INT GetOtherVesselPosOfID(SHIP_ID vesselID);//根据船舶ID获取目标船索引

    int GetOtherVesselPosOfMMSI(int mmsi); //根据目标船MMSI号获取目标船索引
	
    bool SetOtherVesselDrawOrNot(int vesselNum, bool bDrawOrNot);//设置指定目标船是否显示

    bool RemoveOtherVessel(int vesselPos);	//删除指定目标船
    void ClearOtherVessels(); //删除所有非本船的目标船

    void HighlightOtherVessel(int otherVesselPos);//高亮指定目标船
    SHIP_ID SelectOtherVesselByScrnPoint(M_POINT scrnPoint);//根据屏幕坐标选中目标船
  
	void SetDrawShipHeadingLineLen(int ownShipHeadLineLenByMm, 
        int otherShipHeadingLineLenByMm);//未实现，参考SetDrawShipHeadingLineLenByMm

    //设置本船或其他船显示样式
    void SetDrawShipOptions(bool bSetOwnshipOrOtherVessel,  //true:本船，false：目标船
        bool bShowCourseAndSpeedVector,                     //是否显示航速及航向向量
        bool bShowTimeMarksOnVector,                        //是否显示向量刻度
        bool bShowHeadingLine,                              //是否显示船首线
        float vectorLenTimePer,                             //向量长度时间段，单位为分钟(Min) 实际显示的向量长度为 船速与该参量的乘积，即在该时间段内船航行的距离
        int vectorStable,                                   //航速及航向向量是相对地面还是水，1 == 相对地面，其他 -->相对水
        int vectorTimeMarkIntvl,                            //航向及航速向量刻度类型，1 == 显示1分钟和6分钟刻度，2 == 仅显示6分钟刻度
        int memStoreTrackPointsLength,                      //内存最多存多少个航迹点
        int showTrackPointsLength, int memTrackTimeLenByMin = 0);//showTrackPointsLength：最多显示多少个航迹点；memTrackTimeLenByMin：当前是存储多长时间的，以分钟为单位

	bool ClearShipMemTrackPoints(bool bSetOwnshipOrOtherVessel, 
        bool bSetAllOtherVessel, SHIP_ID vesselID);//清空内存中本船或指定目标船的当前轨迹信息
	bool SetShipTrackShowOrNot(bool bSetOwnshipOrOtherVessel, 
        bool bSetAllOtherVessel, SHIP_ID vesselID, bool bShowOrNot); //设置指定船舶的轨迹是否显示
    //设置本船特殊属性
    void SetDrawOwnShipSpecialOptions(bool bDrawOwnShipSymbolOrOutline, // 显示符号还是轮廓
        bool bShowBeamBearingLine, bool bSetColor, M_COLOR newColor);//是否显示正横方位线
    //设置本船基础信息
	void SetOwnShipBasicInfo(const char* pStrShipName, const char* pStrMmsi, 
          float shipLength, float shipBreath);
    //获取本船基础信息
	void GetOwnShipBasicInfo(float* pShipLength = NULL, float* pShipBreath = NULL, 
          char* pStrShipName = NULL, char* pStrMmsi = NULL);
    //设置目标船的基础信息
    bool SetOtherVesselBasicInfo(int vesselPos, //目标船索引
		    float shipLength, float shipBreath, const char* pStrShipName = NULL, int mmsi = 0);  
    //获取目标船的基础信息
	bool GetOtherVesselBasicInfo(int vesselPos, 
		   float* pShipLength, float* pShipBreath, 
		   char* pStrShipName = NULL, int* pMmsi = NULL);
    //设置本船的动态信息
    void SetOwnShipCurrentInfo(M_POINT currentPo, float heading, //currentPo:本船当前地理位置坐标; heading: 船首向，以度数(degree)为单位, 由正北(North Up)方向顺时针旋转所得角度
            float courseOverGround, float courseThrghWater,//courseOverGround:对地航向，courseThrghWater:对水航向
            float speedOverGround, float speedThrghWater);//speedOverGround：对地航速;speedThrghWater:对水航速
    //获取本船的动态信息
	void GetOwnShipCurrentInfo(M_POINT* pCurrentPo, float* pHeading,
			float* pCourseOverGround, float* pCourseThrghWater,
	        float* pSpeedOverGround, float* pSpeedThrghWater);
    //设置目标船的动态信息
	bool SetOtherVesselCurrentInfo(int otherVesselNum, M_POINT currentPo,
		    float heading, float courseOverGround, float courseThrghWater,
	        float speedOverGround, float speedThrghWater);
    //获取目标船的动态信息
    bool GetOtherVesselCurrentInfo(int otherVesselNum, bool* bArpaOrAisTarget = NULL, //otherVesselNum:目标船索引；bArpaOrAisTarget：ture== ARPA对象，false==AIS对象
           M_POINT* pCurrentPo = NULL, float* pHeading = NULL, float* pCourseOverGround = NULL, //其余返回参考SetOwnShipCurrentInfo接口
		   float* pCourseThrghWater = NULL, float* pSpeedOverGround = NULL, float* pSpeedThrghWater = NULL);

    int GetOtherVesselCount();//获取所有目标船的数量
    //添加一艘目标船
    SHIP_ID AddOtherVessel(bool bArpaOrAisTarget, M_POINT currentPo,
		    float heading, float courseOverGround, float courseThrghWater,
	        float speedOverGround, float speedThrghWater);
    //设置目标船显示的颜色
	bool SetOtherVesselShowColor(int otherVesselNum, bool bUseDefaultColor, 
							M_COLOR vslColor, bool bUseDefualtVectorColor, 
							M_COLOR vectorColor); 
    //设置目标船显示的文字样式
	bool SetOtherVesselShowText(int otherVslPos, bool bSetText, const char* pStrText,
										   bool bSetFontSize, int fontSize, 
                                           bool bSetColor, const M_COLOR* pFontColor, bool bStrTextIsUTF8Code = false);
	/////////////////////////////////////////////////////////


    bool AddHighLightPointObject(M_POINT geoPoint);//设置高亮点物标，geoPoint：待高亮的点物标的地理坐标
    bool AddHighLightLineObject(const M_POINT* pGeoPoints, int linePoCount);//设置高亮线物标，传入待高亮线物标地理坐标
    bool AddHighLightFaceObject(const M_POINT* pGeoPoints, int facePoCount);//设置高亮面物标，传入待高亮面物标地理坐标
    void ClearHighLightPointObject();//清除所有使用AddHighLightPoint 添加的高亮点物标的高亮效果。
    void ClearHighLightLineObject(); //清除所有使用AddHighLightLineObject 添加的高亮点物标的高亮效果
    void ClearHighLightFaceObject(); //清除所有使用AddHighLightFaceObject 添加的高亮点物标的高亮效果

    bool DrawHighLightObjects();//画高亮物标

    int QueryObjectsByKeyWordsString(MEM_GEO_OBJ_POS* pRetObjectPoses,//查询返回的物标索引
                                       const char* pStrKeyWords);//传入的关键字

    //
	int QueryInMapLayerByFieldCondtion(int memMapPos, int layerPos, int conditionFieldPos, 
							FIELD_COMPARE_OPTION conditionCompareOption, 
							const char* conditionVal, int* pRetResultObjectPoses);

    void EnlargeDrawRect(MRECT& scrnRect, int enlargeWidth);//扩大传入矩形的大小

    bool SetOneMapShowMode(bool bSetOnOrCancelOneMapMode, int libMapPos);//bSetOnOrCancelOneMapMode：true：开启只显示一张海图的显示模式

    //在内存中绘制海图
    void DrawMapsInMemScreenAreas(MRECT* pScrnRect, int rectCount,
        DRAW_MAP_WITH_RADAR_MODEL objWithRadarModel = DRAW_ALL_OBJ, bool bUseScaleMin = true);

	YMEncMapMan(void);
	~YMEncMapMan(void);
	
    void SetIfUseScaleMin(bool bUseOrNot);//设置是否使用最小比例尺来限定海图显示
	bool GetIfUseScaleMin();
	
    void SetIfShowText(bool bIfShow); //是否显示文字
	bool GetIfShowText();

    void SetIfUseTextOutLineEffect(bool bIfShow); //显示的文字是否带轮廓线特效

    void SetIfShowNorthArrow(bool bIfShow);//是否显示指北针
	bool GetIfShowNorthArrow();
    void SetShowNorthArrowScrnPo(M_POINT mScrnPo);//设置指北针位置
    void SetIfShowScaleBar(bool bIfShow);//是否显示比例尺图例
	bool GetIfShowScaleBar();
    void SetScaleBarUnit(bool bUnitNmOrKm);//设置比例尺图例显示单位，true：海里，false：公里
    void SetScaleBarPosition(bool bUseDefaultPosition, M_POINT setScaleBarPoint);//设置比例次图例位置

    void SetIfShowMapFrame(bool bIfShow);//是否显示图幅边框
	bool GetIfShowMapFrame();

    void SetIfUseGDIPlus(bool bUseGDIPlus); //是否使用GDIPlus
    bool GetIfUseGDIPlus();

    void SetIfShowGrid(bool bShowGrid);//设置是否显示经纬网格
	bool GetIfShowGrid();


    void SetIfShowOwnship(bool bShowOrNot);//是否显示本船
	bool GetIfShowOwnship();

    void SetIfShowWorldMap(bool bShowWorldMap); //设置是否显示世界地图，默认为False
    bool GetIfShowWorldMap();                   //获取当前是否显示世界地图
	
    void SetIfShowCountry(bool bShowCntry); //是否显示国家名
	bool GetIfShowCountry(); 
	
    void SetIfShowSounding(bool bShow);//是否显示水深
	bool GetIfShowSounding();

    bool SetYimapEncFileExtension(const char* ymcExtension, const char *ympExtension); //设置意玛海图文件格式 如".ymc"".ymp"
    bool GetYimapEncFileExtension(char* ymcExtension, char *ympExtension);  //获取意玛文件格式

    void SetBackGroundColor(M_COLOR color);//设置背景颜色，在没海图的位置处可见

	//Offset Point coor by Himeter !!
	bool RefreshMemMapsForCurScrn(const float* pNewScale = NULL,
        const M_POINT* pNewOffsetPoint = NULL);//根据当前屏幕大小刷新海图
	
    int SelectMapsInScrnRect(int* libMapPoses, MRECT scrnRect);//传入一个屏幕矩形范围，返回在该范围内图幅索引

    void SetS52SymbolSizeZoomRatio(float zoomRatio);//设置S52符号缩放

    void SetS52FontSizeZoomRatio(float zoomRatio);//设置S52字体缩放

    void ZoomS52SymbolOrFontSize(float zoomSymbolSizeRatio, float zoomFontSizeRatio);//同时设置字体和符号缩放

    bool Init(const char* pStrWordDirectory = NULL);//初始化海图组件

	bool RefreshDrawer(int scrnWidth, int scrnHeight, int scrnOrgOffsetPoX, int scrnOrgOffsetPoY, void* pVoid1 = NULL,
                                void* pVoid2 = NULL, void* pVoid3 = NULL);//设置海图绘制的范围，偏移量，pVoid1 pVoid2 pVoid3一般为null

    void Exit(bool bFastExit); //退出
	
	bool ReInitDrawer(const char* strS57ConfigDir, bool bReInitS57Structure = false,
                               bool bReInitDrawerInfo = true);//重新导入S57配置
	
    bool GetWorkDirectory(char* pStrWorkDirectory);//获取工作目录

    void SetActiveDrawer(bool bSetMainOrDynamicDrawerActive);//设置活动的绘制器

    bool DrawMapsInMemScreen(DRAW_MAP_WITH_RADAR_MODEL drawRadarModel = DRAW_ALL_OBJ);  //在内存中绘制还如

    void SetMapToForcelyRefresh();//强制刷新一次海图

    int GetDrawerScreenWidth();//获取当前海图绘制区域长

    int GetDrawerScreenHeight();//获取当前海图绘制区域高

    void SetMapScreenSize(int scrnWidth, int scrnHeight);//设置海图绘制区域长、高

    int GetGeoCoorMultiFactor();//获取地理坐标因子

    UINT SaveScrnToBmpFileStream(char* pStrStream, int streamSize);//保存当前屏幕到文件

	bool SaveScrnToBmpFile(int saveScrnLeft, int saveScrnTop, int saveScrnWidth,
                                    int saveScrnHeight, char* pStrFileName);//保存当前屏幕到文件

    M_POINT GetMapOffset();//获取当前屏幕偏移量
    float GetCurrentScale();//获取当前比例次大小
	
    void CenterMemMaps(M_POINT centerSpherePo, bool bSphereOrPlaneGeo = true);//内存海图在指定地理坐标处居中
	//void CenterMemMapsToGeoPoint(M_POINT centerGeoPoint);
    void SetMemMapsCurrentScale(float& scale);//设置内存海图比例尺大小
	//offset coor By Himeter !!
    void SetMemMapsOffset(int xOffset, int yOffset);//设置内存海图屏幕偏移量

    void SetCurrentScale(float scale);//设置海图比例尺大小
    void SetMapOffset(int xOffset, int yOffset);	//弃用
    void SetMapMoreOffset(int moreXOffset, int moreYOffset);//设置海图屏幕偏移量
    void CenterMap(M_POINT centerGeoPoint, bool bSphereOrPlaneGeo = true); //
    float CaculateScale(M_POINT centerMapGeoPoint, int distOnScreenByPixel, float distOnMapByMeter);//获取屏幕长度distOnScreenByPixel下地理长度为distOnMapByMeter的地图比例尺。
    float GetMapRotatedAngle();//获取当前海图旋转角度
    void RotateMapByScrnCenter(float fRotateAngleByDegree);//

	bool ZoomInByScreenRect(M_POINT leftTopScrnPo, M_POINT rightDownScrnPo);

    M_POINT GetGeoPoFromScrnPo(M_POINT scrnPoint);
    M_POINT GetScrnPoFromGeoPo(M_POINT spherePoint);

	////////////////////////////// Geo Computing ////////////////////////
	bool IsPointInFace(M_POINT point,
							M_POINT* pFacePoints, int facePoCount); 
	
	//return Unit : Natical Mile //返回单位海里
	double GetDistBetwTwoPoint(M_POINT geoStartPo, M_POINT geoEndPo);
	
	//return Unit : Degree 
	double GetBearingBetwTwoPoint(M_POINT geoStartPo, M_POINT geoEndPo);

	/* dist 单位为海里 */
	M_POINT GetDesPointOfCrsAndDist(M_POINT geoStartPo, double dist, double course);

	M_POINT GetLinePointNearestToPoint(M_POINT geoPoint, M_POINT geoLineStartPoint, M_POINT geoLineEndPoint, 
		float& distByNm, bool bRetPointOnLineSection);

	float GetAreaOfGeoRegion(int poCount, M_POINT* geoRegionPoints);

    float GetGeoLenFromScrnLen(int scrnLen);//输出单位是mm
	float GetScrnLenFromGeoLen(float geoLenByMm);
	//////////////////////////////////////////////////////////////////////


	////////// global var contral //////////
	void SetSafetyDepth(float safeDepth);
	float GetSafetyDepth(); 

    void GetDepthShadesMode(bool* pBTwoShadesOrFourShades, 
									 float* pShallowDepth, float* pSafetyDepth, float* pDeepDepth, ISODANGER_STYLE *pIsoDangerStyle);
    void SetDepthShadesMode(bool bTwoShadesOrFourShades, 
									 float shallowDepth, float safetyDepth, float deepDepth, ISODANGER_STYLE isoDangerStyle);

	void SetColorModel(ENC_COLOR_GROUP colorGroup);

    bool SetEncColor(const char* colorToken, M_COLOR newColor);

    ENC_COLOR_GROUP GetColorModel();

	void SetLanguage(bool bEnglishOrNational);
	bool GetLanguage();
	void SetNationalLanguageCountry(MAP_NATIONAL_LANGUAGE langCountry);
	MAP_NATIONAL_LANGUAGE GetNationalLanguageCountry();

	void SetDisplayCategory(DISPLAY_CATEGORY_NUM dspCtgry);
	DISPLAY_CATEGORY_NUM GetDisplayCategory();

	void SetUsingTraditionOrSimpleSymbol(bool bUsingTradSymbol);
    void SetUseSmpSymbolOrNot(bool bUseOrNot);
    bool GetUseSmpSymbolOrNot();

	void SetUsingPlainOrSymbolBndry(bool bUsingSymbolBndry); 
    bool GetUsePlainBndryOrNot();

	void SetDrawRadarOrNot(bool bDrawRadarOrNot);
	////////////////////////////////////////

	/********************** tracks mangage *******************/ 
	TRACK_ID GetHistoryTrackIDFromPos(UINT pos);	//通过位置获取航迹ID
	UINT GetHistoryTrackPosFromID(TRACK_ID trackID);	//通过航迹ID获得位置，如没有该ID，则返回-1

	int GetHistoryTrackCount();		//获取航迹个数
	bool DeleteHistoryTrack(UINT pos);	//删除pos位的航迹
	bool ClearHistoryTracks();	//删除所有航迹

	int GetHistoryTrackPointCount(UINT trackPos);
	int GetHistoryTrackPoints(UINT trackPos, M_POINT* pRetPoints);

    bool GetHistoryTrackPoint(UINT trackPos, UINT poPos, M_POINT* pRetPoint, int* pRetPointOffsetTime = NULL,
                              float* pRetCourseOverGround = NULL, float* pRetSpeedOverGround = NULL);

	bool SetHistoryTrackInfo(UINT trackPos, const char* name = NULL, const char* comment = NULL, float totalDist = 0);

    bool GetHistoryTrackInfo(UINT trackPos, char* pStrRetName = NULL, char* pStrRetComment = NULL, float* pTotalDist = NULL,
               M_POINT* pRetFrstPoint = NULL, M_POINT* pRetLastPoint = NULL,M_TIME* pRetStartTime = NULL, M_TIME* pRetEndTime = NULL);
   
	bool SaveCurrentTrackToLibrary(bool bOwnShipOrOtherVessel, int otherVesselPos = -1); /* 保存当前航迹到航迹库 */

	void SetNewTrackJudgeTimeInterval(int timeIntervalByMin); /* 对应 AddNewPostionToTrack() 函数, 设置新航迹开始的时间间隔判据, 以分钟为单位 */
	void SetNewTrackJudgeDist(int distByMeter); /* 对应 AddNewPostionToTrack() 函数, 设置新航迹开始的距离间隔判据, 以米为单位 */
   
	bool SaveHistoryTrackPoints(int libTrackPos); //保存航迹到航迹库里的航迹文件
	bool LoadHistoryTrackPoints(int libTrackPos); //加载某条航迹的所有点信息
	bool UnloadHistoryTrackPoints(int libTrackPos); //卸载某条航迹的所有点信息, 并将其保存到航迹文件中

	bool ReadOwnShipTrackFromFile(); /* 读取本船上次保存的航迹 */
	bool SaveOwnShipTrackToFile();   /* 保存本船当前航迹 */

	bool SaveHistoryTracksToFile(); /* 将当前所有航迹保存到航迹库: 
	                         1.所有航迹基本信息保存到 "\HistoryTracks\hisTracks.lib" 文件中; 
	                         2.如果有某条的航迹的点信息已载入, 则将其保存到对应的航迹文件中去  */
	bool ReadHistoryTracksFromFile(); /* 从航迹库读入航迹到 m_historyTracks 目录, 航迹的点信息不读入 */

	bool IsHistoryTrackPointsLoaded(int libTrackPos, bool& bLoaded); /*判断航迹的点信息是否已经加载,如果没有则需
                   要调用 LoadHistoryTrackPoints 将其加载进来 */
	/**********************************************************************************************/

	/******************** 图库管理 ******************/
    bool LoadYimapFileToMemory(const char* pStrFilePathName, int libMapPos = -1);
	bool CheckEncMapFileVersion(const char* strFilePathName, int& baseEdition, int& updtEditon);
	INT OpenMap(const char* strFilePathName); 	 
    void CloseMap(int libMapPos, bool bDeleteFile=true);   //从海图库中删除某幅海图

	int GetLibMapCount();

	int GetLibMapPosOfName(const char* pStrMapName);
	int GetLibMapPosByMapFileName(const char* pStrMapFileName);

	bool OverViewGeoRect(M_POINT leftDownGeoPo, M_POINT rightUpGeoPo);
	bool OverViewLibMap(int libMapPos);
	bool FocusLibMap(int libMapPos);

	int GetMapElementPosOfID(LIB_MAP_ELEMENT_ID libMapID);

	bool GetLibMapInfo(int libMapPos, char* pStrMapType = NULL, char* pStrMapName = NULL,
		    float* pOriginalScale = NULL, 
			int* pLeftMost = NULL, int* pUpMost = NULL,
			int* pRightMost = NULL, int* pDownMost = NULL,
			int* pEditionNum = NULL, int* pUpdateEditionNum = NULL, 
			int* pAngencyNum = NULL, int* pHdat = NULL, int* pVdat = NULL, int* pSdat = NULL, 
			char* pStrMapFileName = NULL, 
			UINT* pScaleMin = NULL, UINT* pMemNeedByKB = NULL);

	bool RenameLibMap(int libMapPos, const char* pStrNewMapName);

	bool SetLibMapLoadScale(int libMapPos, float minScaleToLoadAndShow);
	float GetLibMapLoadScale(int libMapPos);

	bool GetLibMapEditionIssueDate(int libMapPos, int iEditionNumber, char* retStrDate);

	bool GetMemMapInfo(int memMapPos, char* pStrMapType = NULL, char* pStrMapName = NULL,
		float* pOriginalScale = NULL, 
		int* pLeftMost = NULL, int* pUpMost = NULL,
		int* pRightMost = NULL, int* pDownMost = NULL,
		int* pEditionNum = NULL, int* pUpdateEditionNum = NULL);
	
	INT GetLibMapScaleMin(int libMapPos);
	
	int GetYMCFileEncryptKey();
	void SetYMCFileEncryptKey(int keyNumber);
	
	void SetIfYmcFileNeedEncrypt(bool bEncryptOrNot);
	
	void SetDeviceID(const UINT deviceID);  
 
	///////////////////////////// object operations in a specified memory map ///////////////
    int SelectObjectsByScrnPo(MEM_GEO_OBJ_POS* pRetObjectPoses, int scrnPoX, int scrnPoY);

	bool IsLibMapSelectedByLineSection(int libMapPos, M_POINT lineSectionGeoStartPo,
											M_POINT lineSectionGeoEndPo);

	bool SelectObjectByScrnPo(const MEM_GEO_OBJ_POS& objectPos, int scrnPoX, int scrnPoY, bool& bSelect);

	bool IsLineSectionCrossPolygon(M_POINT lineSectionStartPo, M_POINT lineSectionEndPo, 
									   M_POINT* polygonPoints, int polygonPoCount,
									   bool bInputSphereOrPlaneCoor, bool& bRetResult); 

	bool SelectGeoObjectByLineSection(MEM_GEO_OBJ_POS& objPos, M_POINT lineSectionStartPo, M_POINT lineSectionEndPo, 
										  float selDistByMeter, bool& bRetResult);

	void SetPointSelectJudgeDist(int pointHitPointDist, int pointHitLineDist);

	int SelectObjectsByScrnRect(MEM_GEO_OBJ_POS* pRetObjectPoses, MRECT scrnRect);

	int GetLayerObjectCountOfMap(int memMapPos, int layerPos);

	bool GetObjectAttrValue(MEM_GEO_OBJ_POS objectPos, 
              int attrPos, char* pDesVal, bool* pFieldValFilled = NULL);

	M_GEO_TYPE GetObjectGeoType(MEM_GEO_OBJ_POS objectPos);

	bool GetObjectCenterPoint(MEM_GEO_OBJ_POS objectPos, M_POINT* pRetPoint); //得到物标的中心点, 经纬度坐标
	bool GetObjectExtent(MEM_GEO_OBJ_POS objectPos, MRECT* pRetRect); /* 得到物标的地理范围(左边,右边,上边,下边), 经纬度坐标,
													  如果是点物标, 则四边的值都相同 */

	bool GetPointObjectCoor(MEM_GEO_OBJ_POS objectPos, M_POINT& geoSpherePoint);

	int GetLineObjectCoorCount(MEM_GEO_OBJ_POS objectPos);
	int GetLineObjectCoors(MEM_GEO_OBJ_POS objectPos, M_POINT* pGeoSpherePoints);

	int GetFaceOutBndryCoorCount(MEM_GEO_OBJ_POS objectPos);
	int GetFaceOutBndryCoors(MEM_GEO_OBJ_POS objectPos, M_POINT* pGeoSpherePoints);

	int GetFaceInnerBndryCount(MEM_GEO_OBJ_POS objectPos);
	int GetFaceInnerBndryCoorCount(MEM_GEO_OBJ_POS objectPos, int innerBndryPos);
	int GetFaceInnerBndryCoors(MEM_GEO_OBJ_POS objectPos, int innerBndryPos, 
		  M_POINT* pGeoSpherePoints);   

	bool GetObjectAttrValueString(MEM_GEO_OBJ_POS objectPos, 
		  int attrPos, char* pDesString,
		  bool bToGetEnumFullString = true, bool* pRetBeWideString = NULL); 

	bool SetObjectAttrValueString(MEM_GEO_OBJ_POS objectPos, int attrPos, const char* pSrcString);

	bool HighlightEdge(int edgePos, M_COLOR color);

	bool HighLightSelectedObject(MEM_GEO_OBJ_POS objectPos, M_COLOR pointColor,
		    M_COLOR lineColor, int lineWidth, M_COLOR areaColor, int areaFillTransparency, bool bCenterTheObject, 
			bool bEditing, int iEditingLinePoint);
	//////////////////////////////////////////////////////////////////////////////////

	///////////////////////////// common layer informations operations ///////////////
	int GetLayerCount(int mapPos);

	bool GetLayerInfo(int mapPos, int layerPos, char* pStrLayerName, 
		char* pStrLayerNameToken, int* pFeatureAttrCount);

	//return -1 when failed to get layer pos or error occured
	int GetLayerPosByToken(int mapPos, char* pStrLayerToken);

	bool GetLayerObjectAttrInfo(int mapPos, int layerPos, int attrPos, 
		M_DATA_TYPE_ID& dataTypeID, char* pAttrName, char* pAttrToken);

	int GetLayerObjectAttrPosByToken(int mapPos, int layerPos, char* pAttrToken);

	bool GetLayerDrawOrNot(int mapPos, int layerPos);
    bool SetLayerDrawOrNot(int mapPos, int layerPos, bool bDrawOrNot);

	void SetAllMetaLayerDrawOrNot(bool bDrawOrNot);

	void SetAllLayerDrawOrNot(int mapPos, bool bDrawOrNot);
	//////////////////////////////////////////////////////////////////////////////////
	
    void SetMemoryUpperLimit(int memSizeByMega);

	bool LoadMapToMemory(int libMapPos);

    bool TestLoadMapToMemory(int libMapPos);
	
	bool UnloadMapFromMemory(int memMapPos);

	bool IsMapLoaded(int libMapPos, bool& bLoaded);
	bool IsMapInScrnRect(int libMapPos, MRECT scrnRect, MRECT* pIntSectRect = NULL);
	bool IsMapInCurrentScrn(int libMapPos, MRECT* pIntSectRect = NULL); 	

    int GetMemMapCount();
	
	int GetMemMapPosInLib(UINT memMapPos);
	int GetLibMapPosInMem(int libMapPos);

	LIB_MAP_ELEMENT_ID GetMemMapID(UINT mapPos);
	int GetMemMapPosOfID(LIB_MAP_ELEMENT_ID id);

	bool InterChangeTwoMapPos(int firstMemMapPos, int secondMemMapPos);

	bool MoveMapPos(int oldMemMapPos, int newMemMapPos); 
 
	bool SaveMapAs(int memMapPos, const char* desFileName, MAP_FILE_TYPE desFileType);

    bool tmOpenMapDataFile(const char* pFilePathName, bool bClearOldData = true);
    bool tmSaveToMapDataFile(const char* pFilePathName);
    bool tmSetLayerSaveToFileOrNot(int layerPos, bool bSaveOrNot);
	
    int tmGetLayerCount();
    bool tmGetLayerName(int layerPos, char* pStrLayerName);
	
    M_GEO_OBJ_ID tmGetObjectIDFromPos(M_GEO_OBJ_POS objPos);
    M_GEO_OBJ_POS tmGetObjectPosFromID(M_GEO_OBJ_ID objID);

    int tmGetLayerIDFromPos(int layerPos);
    int tmGetLayerPosFromID(int layerID);

    LAYER_GEO_TYPE tmGetLayerGeoType(int layerPos);
    int tmGetLayerObjectCount(int layerPos);

    M_GEO_TYPE tmGetGeoObjType(int layerPos, int innerLayerObjPos);

    bool tmAppendObjectInLayer(int layerPos, M_GEO_TYPE geoType = TYPE_NULL);
    bool tmSetObjectAsSpecialType(int layerPos, int innerLayerObjPos, SPECIAL_LINE_TYPE specialType);

    bool tmSetObjectAsSymbolLineObject(M_GEO_OBJ_POS geoObjPos, bool bSetOrCancelToBeSymbolObj);
    bool tmGetObjectIsSymbolLineObject(M_GEO_OBJ_POS geoObjPos,
												 bool& bSetOrCancelToBeSymbolObj);

    bool tmSetPointObjectStyle(M_GEO_OBJ_POS geoObjPos, UINT symbolID,
	    bool bSetTrueTypeSymbolColor = false, M_COLOR trueTypeSymbolColor = M_COLOR(0, 0, 0), 
		UINT trueTypeSymbolSize = 0, const char* strText = NULL, const char* pStrFontName = NULL,
		int fontHeight = 14, M_COLOR color = M_COLOR(0, 0, 0), 
		bool bIsBold = false, bool bIsItalic = false, int symbolOffsetX = 0, int symbolOffsetY = 0, 
        int textOffsetX = 0, int textOffsetY = 0, bool bStrTextIsUTF8Code = false);

    bool tmGetPointObjectStyle(M_GEO_OBJ_POS geoObjPos,
			 int* pRetReferLibSymbolId, 
			 M_COLOR* pRetTrueTypeSymbolColor = NULL, UINT* pRetTrueTypeSymbolSize = NULL, 
			 char* pRetStrText = NULL, char* pRetStrFontName = NULL, 
			 int* pRetFontHeight = NULL, M_COLOR* pRetFontColor = NULL, bool* pRetIsBold = NULL, 
			 bool* pRetIsItalic = NULL, int* pRetSymbolOffsetX = NULL, 
			 int* pRetSymbolOffsetY = NULL, int* pRetTextOffsetX = NULL, int* pRetTextOffsetY = NULL);

    bool tmSetLineObjectStyle(M_GEO_OBJ_POS geoObjPos, bool bSetBasicLineStyle, bool bSolidOrDashLine,
		UINT dashCycle, UINT dashLen,
		UINT lineWidth, M_COLOR lineColor,
		UINT cycleSymbolID, UINT cycleSymbolLen, 
		const char* strText = NULL, const char* pStrFontName = NULL,
		int fontHeight = 14, M_COLOR color = M_COLOR(0, 0, 0), 
		bool bIsBold = false, bool bIsItalic = false,  
		int textOffsetX = 0, int textOffsetY = 0, 
        bool bShowTextAlongLine = false, bool bStrTextIsUTF8Code = false);

    bool tmGetLineObjectStyle(M_GEO_OBJ_POS geoObjPos,
			 bool* pRetIsTakeSolidLnSytle = NULL, bool* pRetIsTakeDashLnSytle = NULL, 
			 int* pRetLnWidth = NULL, M_COLOR* pRetLnColor = NULL, int* pRetDashCycle = NULL, int* pRetDashLen = NULL, 
			 char* pRetStrText = NULL, char* pRetStrFontName = NULL, 
			 int* pRetFontHeight = NULL, M_COLOR* pRetFontColor = NULL, bool* pRetIsBold = NULL, 
			 bool* pRetIsItalic = NULL, int* pRetTextOffsetX = NULL, 
			 int* pRetTextOffsetY = NULL, bool* pRetIsShowTextAlongLine = NULL);

	int GetLibLineStyleCount();
	UINT GetLibLineStyleIDFromPos(int libLsPos);
	int GetLibLineStylePosOfID(UINT libLsID);

	int GetLibFaceStyleCount();
	UINT GetLibFaceStyleIDFromPos(int libFsPos);
	int GetLibFaceStylePosOfID(UINT libFsID);

    bool tmSetPointObjectStyleReferLibrary(M_GEO_OBJ_POS geoObjPos, UINT symbolID,
												bool bSetColor, M_COLOR color, 
                                                float zoomScale, float symbloRotateAngleByDeg);

    bool tmSetLineObjectStyleReferLibrary(M_GEO_OBJ_POS geoObjPos, UINT libStyleID,
												bool bSetColor, M_COLOR lineColor, 
													bool bSetWidth, UINT lineWidth);

    bool tmSetFaceObjectStyleReferLibrary(M_GEO_OBJ_POS geoObjPos,
													UINT libFaceStyleID, 
													bool bSetFillColor, M_COLOR fillColor, 
													bool bSetFillTransparency, int transparency, 
													bool bSetPatternColor, M_COLOR patternColor);

    bool tmSetFaceObjectStyle(M_GEO_OBJ_POS geoObjPos, bool bFillColor, M_COLOR faceColor, UINT transparency,
		UINT patternSymbolID, UINT patternSymbolSpaceWidth,
		UINT patternSymbolSpaceHeight, const char* pStrText, const char* pStrFontName, 
		int fontHeight, M_COLOR fontColor, bool bIsBold, bool bIsItalic, bool bAtCenterOrBottom, 
        int textOffsetX, int textOffsetY, bool bStrTextIsUTF8Code = false);

    bool tmGetFaceObjectStyle(M_GEO_OBJ_POS geoObjPos, int* pRetLibFaceStyleID,
		     bool* pRetIsFillColor, M_COLOR* pRetFaceColor, UINT* pRetTransparency, 
			 char* pRetStrText = NULL, char* pRetStrFontName = NULL, 
			 int* pRetFontHeight = NULL, M_COLOR* pRetFontColor = NULL, bool* pRetIsBold = NULL, 
			 bool* pRetIsItalic = NULL, int* pRetTextOffsetX = NULL, 
             int* pRetTextOffsetY = NULL);

    bool tmGetLineObjectSpecialType(M_GEO_OBJ_POS geoObjPos, SPECIAL_LINE_TYPE& retType);

    bool tmSetArcTypeLineObjectParams(M_GEO_OBJ_POS geoObjPos,
												   bool bSetCenterPoint, M_POINT centerPoint, 
												   bool bSetRadius, float newRadiusByMeter,  
												   bool bSetStartAngle, float newStartAngleByDeg, 
												   bool bSetEndAngle, float newEndAngleByDeg);

    bool tmGetArcTypeLineObjectParams(M_GEO_OBJ_POS geoObjPos,
												   M_POINT* pRetCenterPoint = NULL, 
												   float* pRetRadiusByMeter = NULL,  
												   float* pRetStartAngleByDeg = NULL, 
												   float* pRetEndAngleByDeg = NULL);

    bool tmSetSectorTypeLineObjectParams(M_GEO_OBJ_POS geoObjPos,
												   bool bSetCenterPoint, M_POINT newCenterPoint, 
												   bool bSetInnerRadius, float newInnerRadiusByMeter, 
												   bool bSetOutterRadius, float newOutterRadiusByMeter, 
												   bool bSetStartAngle, float newStartAngleByDeg, 
												   bool bSetEndAngle, float newEndAngleByDeg); 

    bool tmGetSectorTypeLineObjectParams(M_GEO_OBJ_POS geoObjPos,
												   M_POINT* pRetCenterPoint = NULL, 
												   float* pRetInnerRadiusByMeter = NULL, 
												   float* pRetOutterRadiusByMeter = NULL, 
												   float* pRetStartAngleByDeg = NULL, 
												   float* pRetEndAngleByDeg = NULL); 

    bool tmSetPointObjectCoor(M_GEO_OBJ_POS geoObjPos, M_POINT geoPoint);
    bool tmSetLineObjectCoors(M_GEO_OBJ_POS geoObjPos, int geoPoCount, const M_POINT* pGeoPoints);
    bool tmSetFaceObjectCoors(M_GEO_OBJ_POS geoObjPos, int geoPoCount, const M_POINT* pGeoPoints);

    bool tmDeleteGeoObject(M_GEO_OBJ_POS geoObjPos);

    bool tmClearLayer(int layerPos);

    void tmAppendLayer(LAYER_GEO_TYPE layerType);
    bool tmDeleteLayer(int layerPos);
    bool tmSetLayerName(int layerPos, const char* pStrName);

    int tmSelectObjectsByScrnPo(M_POINT scrnPoint, M_GEO_OBJ_POS* retObjPoses);
    int tmSelectOnePointOfLineOrFaceObject(M_POINT scrnPoint, M_GEO_OBJ_POS objPos);
	
    bool tmAddOnePointToLineOrFaceObject(M_GEO_OBJ_POS lineObjPos,
				int addPointPosInLine, M_POINT newGeoPoint);
    bool tmDeleteOnePointOfLineOrFaceObject(M_GEO_OBJ_POS lineObjPos,
				int pointPosInLine);
    bool tmMoveOnePointOfLineOrFaceObject(M_GEO_OBJ_POS lineObjPos,
				int pointPosInLine, M_POINT newGeoPosition);

    bool tmMoveObjectInScrn(M_GEO_OBJ_POS lineObjPos, int scrnX, int scrnY);
    bool tmCopyObject(M_GEO_OBJ_POS srcObjPos, int dstLayerPos = -1);
    bool tmRotateLineObjectInScrn(M_GEO_OBJ_POS objPos, M_POINT centerGeoPoint, float rotateAngleByDegree);

    bool tmPushInStackUndoOperation(UNDO_OPERATION_TYPE oprnType, M_GEO_OBJ_POS objPos);
    void tmSetTargetForRedoOperation();
    void tmUndo();
    void tmRedo();

    void SetDrawerPastingByMemScrn(bool bPasteFromMemScrnOrNot);
	bool GetDrawerPastingByMemScrn();
 
    bool SetObjectShowOrNot(MEM_GEO_OBJ_POS memGeoObjPos, bool bShowOrNot) ;

    bool tmSetObjectShowOrNot(M_GEO_OBJ_POS geoObjPos, bool bShowOrNot);

    bool tmSetObjectDynamicObjectOrNot(M_GEO_OBJ_POS geoObjPos, bool bDynamicObjectOrNot);
	
    bool tmGetPointObjectCoor(M_GEO_OBJ_POS geoObjPos, M_POINT& geoPoint);
    int tmGetLineObjectCoorCount(M_GEO_OBJ_POS geoObjPos);
    int tmGetLineObjectCoors(M_GEO_OBJ_POS geoObjPos, M_POINT* pGeoPoints, bool bRetScrnCoor = false);

    int tmGetFaceObjectCoorCount(M_GEO_OBJ_POS geoObjPos);
    int tmGetFaceObjectCoors(M_GEO_OBJ_POS geoObjPos, M_POINT* pGeoPoints);

    bool tmGetLineOrFaceObjectPivotPoint(M_GEO_OBJ_POS geoObjPos, M_POINT* pPivotPoint);

    int tmGetLayerObjectAttrCount(int layerPos);
    bool tmGetLayerObjectAttrInfo(int layerPos, int attrPos,
		M_DATA_TYPE_ID& dataTypeID, char* pAttrName);

    bool tmGetLayerObjectAttrType(long layerPos, long attrPos, int &retAttrType);

    int tmGetObjectGeoType(M_GEO_OBJ_POS geoObjPos);

    bool tmGetObjectShowOrNot(M_GEO_OBJ_POS geoObjPos);

    bool tmGetObjectAttrValueString(M_GEO_OBJ_POS objectPos,
		  int attrPos, char* pDesString);


    bool tmSetObjectAttrValueString(M_GEO_OBJ_POS objectPos,
		  int attrPos, const char* pSrcString); 

    void tmDrawGeoObject(M_GEO_OBJ_POS geoObjPos);

	bool UpdateUserMapFromLayersConfigureFile(const char* pStrCfgFile, bool bIfKeepOldMapDataFile = false);

    bool tmUpdateUserMapFromLayersCfgFile(const char* pStrCfgFile, bool bIfKeepOldMapDataFile = false);

    bool IsGeoObjectNearPoint(MEM_GEO_OBJ_POS objPos,
                                     M_POINT geoSpherePoint,
                                     int nearJudgeDistByMeter, bool& bRetIfNear);

	bool IsGeoLineSelectByScrnPoint(M_POINT scrnPoint, const M_POINT* pGeoLineSpherePoints,
        int linePoCount, int pointAtLineDist);//判断某一线物标是否被屏幕上的一点所选中
	bool IsGeoPointSelectByScrnPoint(M_POINT scrnPoint, M_POINT geoSpherePoint, 
		int pointSelectDist);

	bool IsGeoFaceSelectByScrnPoint(M_POINT scrnPoint, const M_POINT* pGeoFaceSpherePoints,
		int facePoCount);

	bool IsPointInFaceGeoObject(M_POINT scrnPoint, MEM_GEO_OBJ_POS memObjPos, bool bGeoCoorOrScrnCoor);

	bool IsShipApprochingRestrictedArea(M_POINT ownShipPoint, double fCourse,  
						float approchDistLimitByMeter, MEM_GEO_OBJ_POS* pRetRstrctAreaPos);

	bool IsShipApprochingCautionArea(M_POINT ownShipPoint, double fCourse,  
						float approchDistLimitByMeter, MEM_GEO_OBJ_POS* pRetCautionAreaPos);

	bool IsShipApproachingIsolatedDanger(M_POINT ownShipPoint, float distLimitToPointByMeter, 
		MEM_GEO_OBJ_POS* pRetObjPos = NULL);

	bool IsShipCrossingSafetyContour(M_POINT ownShipPoint, double fCourse,  
						float approchDistLimitByMeter);  

	bool IsShipCrossingSafeAreaCenterLine(M_POINT ownShipPoint, float approchDistLimitByMeter);

    //判断船舶是否偏离航线，对所有船舶有效，只检测本船使用 IsOwnShipOffRoute
    bool IsShipOffRoute(M_POINT mShipPoint, ROUTE_ID routeID, float offRouteDistLimitByMeter, float *pRetOffDistByMeter);

	/**********************************用户自行绘制接口系列**********************************/
    bool SetCurrentPen(int width, M_COLOR color);//
    bool SetCurrentBrush(M_COLOR color);//
	bool SetCurrentFont(const char* pStrFontName, int fontHeight, M_COLOR color, 
        bool bIsBold = false, bool bIsItalic = false); //
    void DrawLine(M_POINT startPoint, M_POINT endPoint);//
    bool DrawPolyline(const M_POINT* pPoints, int poCount);//
    bool FillPolygon(const M_POINT* pPoints, int poCount, bool bDrawEdges = false, int transparency = 100);//
    bool TextOutAtPoint(const char* pStrText, M_POINT point, bool bStrTextIsUTF8Code = false); //
    bool DrawEllipse(M_POINT centerPoint, int width, int height, bool bFill, bool bDrawEdge = true);//
    bool DrawCircle(M_POINT centerPoint, int radius, bool bFill, bool bDrawEdge = true);//
	bool DrawArc(M_POINT centerPoint, int radius, float startArc, float endArc, int outlineWidth,
        bool bFill = false, bool bClockWise = true, int transparency = 100);//

	bool DrawDashLine(const M_POINT* pLnPoints, int lnPointCount,
                                         int lineWidth, int lineColor, int dashCycle, int dashLen);//
	
    bool DrawPointWithLibSymbol(int symbolID, M_POINT point, bool bSetColor, M_COLOR color, float zoomScale, float rotateAngle);	//
	bool DrawLineWithLibLineStyle(int libLineStyleID, const M_POINT* linePoints, int linePoCount, 
           bool bSetColor, M_COLOR color, bool bSetWidth, int penWidth);	//
	bool DrawFaceWithLibFaceStyle(int libFaceStyleID, const M_POINT* facePoints, int facePoCount, 
           bool bSetFillColor, M_COLOR fillColor, bool bSetPatternColor, M_COLOR patternColor);//
	/*****************************************************************************************/

	/*************************************符号库编辑******************************************/
	UINT AddAnEmptySymbol(); //返回添加的Symbol的ID
    UINT GetSymbolCount();//获取符号个数
    UINT GetSymbolIDFromPos(int symbolPos);//根据符号索引返回Symbol的ID
    int GetSymbolPosOfID(UINT symbolID);//根据符号ID返回Symbol的索引
    bool SetSymbolAsTrueTypeSymbol(UINT symbolID, const char* pStrFontName, UINT charCode, int offsetX, int offsetY);//设置指定符号属性
    bool DeleteSymbol(UINT symbolID);//删除指定符号
    void SaveSymbolsToFile();//保存符号到文件
	/*****************************************************************************************/

	/*************************************S57物表编辑接口*************************************/
	/* 这些接口为 09.12 添加 */
    bool DeleteGeoObject(MEM_GEO_OBJ_POS geoObjPos);//删除指定物标
    bool SetGeoObjectScaleMin(MEM_GEO_OBJ_POS geoObjPos, float scaleMin);//社会自指定物标最小显示比例尺
    bool SaveS57MemMapToFile(int memMapPos, const char* pFilePathName, bool bOnlySaveLayersToDraw = false); //保存指定内存中的S57图幅到文件
    void ExportMapLibToFile(bool bExportByOpenNew = false); //导出图库记录到文件
    void SaveMapLibBasicInfo();//同ExportMapLibToFile()
	/*****************************************************************************************/

	/*************************************水深点接口*************************************/
    bool GetSoundPointSelectByGeoPoint(M_POINT sphereGeoPoint, UINT maxDistByMmToSounding,
											   float& retSoundingDepth, MEM_GEO_OBJ_POS& retSoundingObjPos, 
                                               int& retSoundingInObjPos);//获取指定地理坐标出的水深数据

    int GetSoundingSetPointCount(MEM_GEO_OBJ_POS soundingObjPos);//获取指定水深的个数

	bool GetSoundingSetPointDepth(MEM_GEO_OBJ_POS soundingObjPos, int pointPosInSoundingSet,
        float& retDepth, M_POINT& retSoundCoor);//获取水深点深度

    bool SetSoundingSetPointDepth(MEM_GEO_OBJ_POS soundingObjPos, int pointPosInSoundingSet,
                                       float newDepth);//设置指定水深点深度
    void SetSoundingShowColor(bool bSetSoundingColor, M_COLOR soundingColor1, M_COLOR soundingColor2);//设置水深显示颜色

    void SetIfUseSafeDepthLineDectect(bool bSetSafeLineDetectOnOrOff, bool bShowDetectSafeLine);//设置是否使用安全线检测
	
    void SetDectectSafeDepthBufferWidth(float bufferWidth); //设置安全线检测深度

    bool PasteToScrn(void* pDestScrnDC, int dstOffsetX = 0, int dstOffsetY = 0, int pasteWidth = 0, int pasteHeight = 0,
                     int srcOffsetX = 0, int srcOffsetY = 0);//将内存绘制的图形绘制到屏幕dc上

    void GetDrawerParams(void** pParam1, void** pParam2 = NULL, void** pParam3 = NULL);//获取海图绘制Dc

    void ResizeDrawer(long newWidth, long newHeight);//重置绘制大小

    void ReleaseDrawerResources();//清空绘图资源

    //--------------------------------------------------add by zcz 2015.7.31
    void SetDrawShipHeadingLineLenByMm(int ownShipHeadLineLen, int otherShipHeadingLineLen);//设置船首线长度，单位：mm

    int AddAisType(const char* pStrType);//添加一种Ais船舶类型

    int GetAisTargetType(int otherVesselPos);//获取AIS船舶的类型

    bool GetRouteShowOrNot(ROUTE_ID routeID, bool* pBeShowOrNot);//获取指定航线是否显示

    bool GetWayPointCircleRadius(int wpID, float* retRadius, float* retRadius2);//指定航路点原半径

    bool GetWayPointName(int wpID, char* pStrName);//获取指定航路点名称

    bool GetWayPointShowOrNot(int wpID, bool* pBeShowOrNot, bool* pBeShowNameOrNot);//获取指定航路点是否显示

    bool SetWayPointUsage(int wpID, const char* pStrUsage);//设置指定航路点使用情况
    bool SetWayPointName(int wpID, const char* pStrName);//设置指定航路点名称

    bool SetWayPointRadialLine(int wpID, float radialAngleByDeg,
        M_COLOR color, float radialAngleByDeg2 = 0, M_COLOR color2 = M_COLOR(0, 0, 0));//设置航路点无线射线样式

    bool SetWayPointAsAimPoint(int wpID, bool bAim, float direction, float offset);//设置指定航路点作为目标点

    bool SetWayPointCircle(int wpID, float radiusByMeter, M_COLOR color,
        float radiusByMeter2 = 0, M_COLOR color2 = M_COLOR(0, 0, 0));//设置指定航路点圆的样式

    void SetStandardAisTargetLen(float standardLength,  float standardWidth);//标准AIS目标船长宽, 超过标准长度相应放大显示符号大小

    bool SetAisTargetType(int otherVesselPos, int typeID);//设置指定AIS船舶的类型

    void GeoCoor2PlaneCoor(M_POINT mGeoPo, M_POINT &mPlanePo);//根据平面坐标获取地理坐标

    void GetDrawerOrgOffset(M_POINT &mOrgOffsetPo);//获取绘图组织偏移量

    bool GetDrawRadarOrNot();//获取雷达图层是否显示

    M_POINT GetEncScrnPoFromGeoPo(M_POINT mGeoPo);//根据地理坐标获取屏幕坐标

    M_POINT GetGeoPoByPlanePo(M_POINT mPlanePo);//根据屏幕坐标获取地理坐标

    M_POINT GetGeoPoFromEncScrnPo(M_POINT mScrnPo);//根据屏幕坐标和获取地理坐标

    void GetPlaneCoorFromGeoCoor(M_POINT mGeoPo, M_POINT &mPlanePo);//根据地理坐标获取平面坐标

    bool tmGetLayerDrawOrNot(int iLayerPos, bool &retDrawOrNot);//获取指定自定义图层是否显示

    bool tmSetLayerDrawOrNot(int iLayerPos, bool bDrawOrNot);//设置指定自定义图层是否显示

    //设置工作目录
    bool SetWorkDirectory(char* pStrCfgFileLibDir, char* pStrMapLibDir);

    //设置指定图幅图层的风格
    bool SetLayerSubStyleParams(int memMapPos, int layerPos, int layerSubStylePos,
                                              bool bShowOrNot, bool bSetColor, M_COLOR newColor);
    //设置AIS船舶样式信息
    bool SetAisTypeInfo(long typeID, char* pStrTypeName, bool bUseStandardS52Symbol,
                                      long symbolID, float zoomSymbolRatio, bool bSetColor, long symbolColor,
                                      long tinySymbolID, float showTinySymbolScale, bool bShowRealSize,
                                      bool bZoomWithScale, float zoomBaseScale, bool bRotateSymbolWithCourse);

    void PlaneCoor2GeoCoor(M_POINT mPlanePo, M_POINT &mGeoPo);//平面坐标转换地理坐标

    bool IsLibMapLoaded(long libMapPos);//获取指定libmap是否加载到内存

    bool IsGeoObjectSelectedByArea(long objectMemMapPos, long objectLayPos, long objectInnerLayerPos,
                                                 long areaCenterPointX, long areaCenterPointY, long areaRadius);//判断指定物标是否在指定区域内

    bool GetWayPointRadialLineAngle(long wpID, float *pRetRadialAngle1, float *pRetRadialAngle2);//获取指定航路点的径向角

    void GetTwoShipsDcpaAndTcpa(long firstShipGeoPoX, long firstShipGeoPoY, float firstShipSpeed,
                                float firstShipDirection,long secondShipGeoPoX, long secondShipGeoPoY,
                                float secondShipSpeed, float secondShipDirection, float * pDcpa, float * pTcpa);//获取两船的DCPA和TCPA

    void GetScrnPointsFromGeoPoints(M_POINT *arrGeoPo, int iGeoPoCount, M_POINT *arrRetScrnPo);//根据地理坐标获取屏幕坐标

    bool IsPointNearObjectEdae(MEM_GEO_OBJ_POS objPos, M_POINT destGeoPoint,
                                      int nearJudgeDistByMeter, int *pCurDisPo2Obj, bool *bPoInFaceOrOut, M_POINT *retNearestGeoPo);//判断点是否靠近物标边

    bool SaveMemScrnToImageFile(const char* pStrFileName, int imageType,
            int saveScrnLeft = 0, int saveScrnTop = 0, int saveImageWidth = 0, int saveImageHeight = 0);//保存内存图像数据到文件

    int GetHistoryTrackPointsByTime(int iCheckOffsetTime, M_TIME tmBeginTime,
            M_TIME tmEndTime,M_TIME *pHistoryTrackStartTime, TrackPoint* ptrRetTrackPointArray,int* nRetCount);//获取指定实际那内的轨迹点
    bool tmAddLayerAttribute(int layerPos, int nDataType, const char* attrName);//向指定的自定义图层添加一条属性，nDataType：属性数据类型；attrName：属性名

    UINT AddS63MapLib(const char* pS63CellFilePath,const char* pS63PermitFilePath,bool bLeaveS57File);//添加S63图幅到maplib中

    bool GetDrawDCQPixMap(QPixmap* pQPixMap);//返回屏幕的图像

    bool GetQPixMapByCenterGeoPo(float scale,M_POINT mGeoPo,int disOfM,QPixmap* pQPixMap);//返回屏幕的图像

    M_POINT GetCurrentAimPoint();//获取本船的下一个航路点

    bool GetGeoPosFromScrnPos(int iPoCount,M_POINT* pScrnPoint,M_POINT* pGeoPoint);

    void SetIfDrawTransparentMap(bool bTransparent, int iTransparency);     //设置海图整体透明度， 0:不透明 255:完全透明
    void GetIfDrawTransparentMap(bool &bTransparent, int &iTransparency);
    bool SetIsHiddenInLandShip(bool bHiddenOrNot,float startMaxScale);      //是否隐藏陆地上的船舶
    //------------------九九方格线相关-------------------//
    void SetNineNineBoxCenterGeoPo(M_POINT curGeoPo);                       //设置99方格中心
    void GetNineNineBoxCenterGeoPo(M_POINT* pGeoPo);                        //获取99方格地理中心
    void SetShowNineNineBoxOrNot(bool bDrawOrNot);                          //设置是否显示99方格线
    bool GetIfShowNineNineBox();                                            //获取是否显示99方格线
    void SetShowNineNineBoxText(bool bShowOrNot);                           //设置是否显示99方格文字
    bool GetIfShowNineNineBoxText();                                        //获取是否显示99方格文字
    void SetDrawNineNineBoxStyle(M_COLOR mMaxBoxColor, M_COLOR mMidBoxColor, M_COLOR mMinBoxColor, M_COLOR mNameColor);//设置99方格显示风格
    bool GetNineNineNumberByGeoPo(M_POINT curGeoPo, char* pmStrNumberValue,int iLevelNumber = 3);//获取指定地理坐标，指定99方格等级的99方格坐标
    //------------------空心延迟相关-----------------------//
    void SetMapHollowEffect(M_POINT centerGeoPo, float radiusByMeter);      //空心
    void SetMapDelayEffect(M_POINT centerGeoPo, float radiusByMeter);       //延迟
    void SetMapEffectRadius(float radiusByMeter);                           //设置特效的半径
    void CancelMapEffect();                                                 //取消空心/延迟
    void GetMapEffectParameter(M_POINT &centerGeoPo, float &radiusByMeter); //获取空心/延迟中心、半径
    MAP_EFFECT GetMapEffect();                                              //获取当前效果

    //------------------可重写的虚函数-------------------//
    virtual void DrawAfterMaps(QPainter* p);
    virtual void DrawAfterMapsExceptObject(QPainter* p);
    //------------------------------------------------//
    bool GetObjectShowOrNot(MEM_GEO_OBJ_POS geoObjPos);                     //获取物标是否显示
    void SetGridLines(int lineCountPerScreen, M_COLOR gridLineColor, M_COLOR latTextColor, M_COLOR lonTextColor, int textFontSize);
    void GetGridLines(int &lineCountPerScreen, M_COLOR &gridLineColor, M_COLOR &latTextColor, M_COLOR &lonTextColor, int &textFontSize);
    bool IsOwnShipOffRoute(float offRouteDistLimitByMeter, float *pRetOffDistByMeter); //判断本船是否偏离航线，同类接口 IsShipOffRoute
    void SetVcfLayerDrawOrNot(int layerPos, bool bDrawOrNot);  //设置vcf军图图层是否显示
    bool GetVcfLayerDrawOrNot(int layerPos);                   //获取vcf军图图层是否显示
    bool GetMemMapIsArmsMap(int memMapPos);                    //判断指定图幅是否为vcf军图

    void SetIfShipOverlapOffsetShowOrHide(bool bOffSetShowOrHide);  //如果两艘船舶重叠，true==错位显示，false==隐藏
    void SetDrawExpandPixel(int expandPixelX, int expandPixelY);    //画布多绘制像素数
    bool tmZoomLineObject(M_GEO_OBJ_POS objPos, M_POINT centerGeoPoint, float scaleValue); //设置物标放大缩小
    void tmSetObjectTextRotate(M_GEO_OBJ_POS geoObjPos, float rotateAngle);     //设置物标文字的旋转角 范围：[-90,90]
    float tmGetObjectTextRotate(M_GEO_OBJ_POS geoObjPos);                       //获取物标文字旋转角
    void SetIfHideShipInSimpleLandArea(bool bHide);                 //是否隐藏在陆地的船舶
    void AddASimpleLandArea(M_POINT* landAreaGeoPo, int poCount);   //添加一个简易的陆地区域,使其隐藏
    void SetShipTrackStyle(bool bOwnOrOtherShip, int shipPos, bool bUseOwnTrackColor, M_COLOR trackColor,
            int trackLineWide, bool bShowTrackPoint, int trackPointRadius, M_COLOR trackPointFillColor); //设置船舶轨迹样式
    float GetSoundingDepthByGeoPo(M_POINT curGeoPoint); //估算某地理位置的水深
    void SetOwnShipShowSymbol(bool bUseStandS52Symbol, int symbolId, bool bRotateWithCourse, int tinySymbolId, float showTinySymbolScale);//设置本船显示自定义符号

    //设置点图层的显示风格
    bool tmSetPointLayerStyleReferLibrary(int layerPos, UINT libSymbolID, bool bSetColor, M_COLOR color, float zoomScale, int rotateDegree,
            bool bSetText, bool bTakeText,const char* pStrTextFormat, const char* pStrFontName, int fontHeight, M_COLOR textColor,
            bool bIsBold, bool bIsItalic, int textHoriJust, int textVetiJust,int textOffsetX, int textOffsetY);
    //设置线图层的显示风格
    bool tmSetLineLayerStyleReferLibrary(int layerPos,int simpleLineType,int dashCycle, int dashLen,
                    int libLineStyleID, bool bSetColor, M_COLOR lineColor, int lineWidth,bool bSetText,bool bTakeText,
                    const char* pStrTextFormat, const char* pStrFontName,int fontHeight, M_COLOR fontColor,bool bIsBold,
                     bool bIsItalic,bool bShowTextAlongLine, int textOffsetX, int textOffsetY);
    //设置面图层的显示风格
    bool tmSetFaceLayerStyleReferLibrary(int layerPos, bool bSetFillStyle,int libFaceStyleID, bool bSetFillColor, M_COLOR fillColor,
                            int transparency, bool bSetPatternColor, M_COLOR patternColor, bool bSetBorderLineStyle,
                            int simpleLineType, int dashCycle, int dashLen,int libLineStyleID, bool bSetColor, M_COLOR lineColor, int lineWidth,
                            bool bSetText, bool bTakeText, const char* pStrTextFormat, const char* pStrFontName,
                            int fontHeight, M_COLOR fontColor, bool bIsBold, bool bIsItalic, bool bAtCenterOrBottom,int textOffsetX, int textOffsetY);
    int GetCurShipTrackPointPos(bool bOwnShipOrOtherVessel, int shipID); //获取当前最新的绘制轨迹的索引值
    bool ClearShipPartMemTrackPoints(bool bOwnShipOrOtherVessel, int shipID, int startTrackPos, int endTrackPos);//删除一部分轨迹点
    bool SetRadarBaseInfo(int iLineCount, int iLineNodeCount, float fPerNodeLenByMeter, M_COLOR mColor);//设置雷达基本信息
    void SetRadarShowState(bool bShowOrNot, bool bShowAllInfoOrFadingColor);//设置雷达显示状态，bShowAllInfoOrFadingColor完全显示或者余晖显示效果
    void SetRadarCenterGeoPo(M_POINT centerGeoPo);//设置雷达地理中心
    bool SetRadarLineDataByPos(int iLinePos, int* pArrLineData, int iCount);//设置雷达某条扫描线的数据，该数据结构为以0 1为单位的数组
    void AdjustSoundingDepthByMeter(float fIncreaseDepthByMeter);   //校准水深数值
    void SetParentWidget(QWidget* mainWidget); //设置父窗体指针，使海图自动刷新
    int GetWayPointPosInRoute(int routeId, int wayPointId);//获取指定航线上指定航路点的索引
    void GetSdkVersion(char* version, char* trailDate);    //获取SDK版本信息
    int GetShipsIdByArea(const M_POINT *arrAreaGeoPo, int iAreaGeoPoCount, int *retArrShipId);  //获取区域内所有船舶ID
    int GetShipsIdByCircleArea(const M_POINT circleCenterGeoPo, float radiusByMeter, int *retArrShipId);    //获取圆形区域内的所有船舶Id

    //海陆叠加相关接口
    void SetIfOverlaySeaMap(bool bOverlaySeaMap);       //设置是否显示海图
    void SetIfOverlayLandMap(bool bOverlayLandMap, LoadMapName curLoadMap);//设置是否显示海图
    void GetIfOverlayLandMap(bool& bOverlayLandMap, LoadMapName& curLoadMap);//获取是否显示陆图及陆图类型
    ProjectorType GetEncMapProject();   //获取海图投影

    std::string GetSymbolNameByID(int symbolId); //获取符号的名称
    int GetSymbolIDByName(std::string symbolName); //获取符号的ID
    void tmSetPointObjectColor(M_GEO_OBJ_POS geoObjPos, bool bsetPen, M_COLOR penColor, bool bSetFillColor, M_COLOR fillColor, bool bSetTextColor, M_COLOR textColor);//设置符号颜色
    bool tmResetLayerObjId(int layerPos); //重置指定图层的自定义物标的id计数，只有当该图层没有物标时才能重置
    bool SelectShipSpeedLine(M_POINT scrnPo, ShipSpeedLine& speedLine); //选择船舶速度线

    QWidget* GetParentWidget();
    //渔区
    void SetIfShowFishArea(bool bShow);
    bool GetIfShowFishArea();
    bool SetFishAreaShowScale(float _firstAreaMaxScale, float _secondAreaMaxScale);
    void SetFishAreaLineStyle(M_COLOR lineColor, int outLineWidth = 3, int innerLineWidth = 2);
    bool SelectFishAreaByGeoPoint(M_POINT geoPo, char* pStr);
    bool GetFishAreaGeo(const char* areaName, char* retGeo);
    bool GetFishAreaAndSmallNumbolGeo(const char* areaName, char* retGeo);
    void SetFishAreaHightLight(const char* nameAndSmallNumbor, M_COLOR hightLightColor);
    bool GetHightLightFishArea(char* retFishAreaName);
    void SetMapLight(int light);//设置海图亮度，默认100,范围[0,100]

    //曲线航线相关
    bool SetWayPointTurnRadiusByMeter(WAY_POINT_ID wpID, int radius);
    bool GetWayPointTurnRadiusByMeter(WAY_POINT_ID wpID, int* radius);
    bool SetRouteWidth(ROUTE_ID routeID, float widthByMeter);
    bool GetRouteWidth(ROUTE_ID routeID, float *widthByMeter);
    bool SetRouteWidthStyle(ROUTE_ID routeID, M_COLOR mColor1, M_COLOR mColor2, int lineWidth);

    //选择扇形范围内的船舶
    int SelectOtherVesselsByGeoSector(M_POINT centerGeoPoint, float raduisByMeter, float startAngle, float endAngle, int* retShipId);//选择指定扇形的船舶
    //选择扇形范围内，指定图层的物标索引，最多返回1024个物标
    int SelectObjectsByGeoSector(MEM_GEO_OBJ_POS* pRetObjectPoses, M_POINT centerGeoPoint,float raduisByMeter, float startAngle, float endAngle, int* layerIds, int layerCount);//选择指定扇形区域并指定图层内的物标

    //设置轨迹点显示样式,时间单位：秒
    void SetShipTrackPointStyleEx(bool bOwnOrOtherShip, int shipPos, int timeSpacePreTrackPoint, bool bShowNote, int timeSpacePreNote);
    void SetRouteAsGreatCircle(int routeId, double minDisTransByNm);//设置航线为大圆航线
    void SetRouteAsRhumbLine(int routeId);//设置航线为恒向线

    //图层控制
    void SetIfUseS52LayerDisplaySet(bool bSet);
    bool GetIfUseS52LayerDisplaySet();
    //添加图幅坐标偏移，叠加设置
    void AdjustMapCoor(int iLon, int iLat);
    //自定义图幅的图层数据导入导出
    bool tmOpenLayerDataFile(const char* pFilePathName);
    bool tmSaveToLayerDataFile(int layerPos, const char* pFilePathName);

    //------使用QWidget操作模式相关方法-------//
    bool tmGetIfLayerHadStyle(int layerPos);
    bool DrawDragingMap(void* destHDc, M_POINT curDragMousePo, M_POINT dragStartPo, bool bRuntimeDragMap);
    bool DrawPointWithLibSymbolToPainter(QPainter* painter, int symbolID, M_POINT point);
    bool DrawLineWithLibLineStyleToPainter(QPainter* painter, int libLineStyleID, const M_POINT* linePoints, int linePoCount);	//
    bool DrawFaceWithLibFaceStyleToPainter(QPainter* painter, int libFaceStyleID, const M_POINT* facePoints, int facePoCount);//
    //------使用QWidget操作模式相关方法-------//


    /**
     * @brief SetAisTypeTextStyle 设置AisType的文字样式，参考AddAisType
     * @param typeID
     * @param textOffset 设置显示文字坐标偏移（像素）
     */
    void SetAisTypeTextStyle(int typeID, M_POINT textOffset);

    /**
     * @brief SelectObjectEdgeByScrnPo 根据屏幕坐标选取物标的一条边
     * @param objectPos 自定义物标索引
     * @param scrnPo
     * @param selIndexInLine 返回选取的边索引
     * @return 是否选取到
     */
    bool SelectObjectEdgeByScrnPo(const MEM_GEO_OBJ_POS& objectPos, M_POINT scrnPo, int& selIndexInLine);

    //add for 28
    int tmSelectOnePointOfLineOrFaceObject(M_POINT scrnPoint, M_GEO_OBJ_POS objPos, M_POINT* selNodeScrnPo);
    bool tmSelectObjectByScrnPo(const M_GEO_OBJ_POS objectPos, int scrnPoX, int scrnPoY, int selJudgeDist);
    M_POINT tmGetObjectCenterScrnPoint(const M_GEO_OBJ_POS objectPos);
    void DrawRectangle(M_POINT centerPoint, int width, int height, bool bFill, bool bDrawEdge);
    void TextOutAtPoint(QString qStrText, M_POINT point);
    M_POINT GetMapCenterGeoPoint();//获取中心点经纬度
    //生成报警区
    //distanceByMeter:偏移距离，单位：米
    //squareOrRound:true:矩形转角，false:弧线转角
    //arcTolerance：对于弧线转角，弧线容差值，取值[1，100]
    int tmCableObjLayerMergeToLayer(int srcLayerPos, int destLayerPos, float distanceByMeter, bool squareOrRound, int arcTolerance);
    //针对单条线，生成报警区
    bool tmCableObjLayerMergeToLayer_Single(int srcLayerPos, int srcObjPos, int destLayerPos, float distanceByMeter, bool squareOrRound, int arcTolerance,
                                            int previousLayerPos, std::vector<int>& changedPoses);

    bool tmCableObjRecheckMerge(int srcLayerPos, int srcObjPos, int destLayerPos, std::vector<int>& changedPoses);//修改报警区坐标后，检查并融合报警区
    void SetOtherVesselSelectedOrNot(int shipId, bool bSelectedOrNot);//船舶将以正常大小1.1倍放大显示
	void SetIfLandMapVector(bool bVector);//设置陆图模式为矢量缩放
	//---船舶聚合相关接口，参考版本3.2.100更新说明---
    void SetIfShipsShowAsCluster(bool bOpenCluster);
    bool GetIfShipsShowAsCluster();
    void SetStartUseClusterSysScale(float scale);
    float GetStartUseClusterSysScale();
    void SetOneShipJoinClusterSys(int shipPos, bool bJoinIn);
    bool SelectClusterByScrnPo(M_POINT scrnPo, int& shipsCountInCluster, int* shipsIdInCluster);
    //---船舶聚合相关接口---

};



#endif
