//
//  GestureManager.cpp
//  testForDollar1
//
//  Created by bin on 14-1-26.
//
//

#include "CreatModeGestureLayer.h"
#include "CreatModeScene.h"

GestureManager* GestureManager::mGestureManager = NULL;

GestureManager* GestureManager::create()
{
    if(mGestureManager == NULL)
    {
        mGestureManager = new GestureManager();
        if(mGestureManager && mGestureManager->init())
        {
            mGestureManager->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(mGestureManager);
            mGestureManager = NULL;
        }
    }
    
    return mGestureManager;
}

bool GestureManager::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    setTouchEnabled(true);
   
    //m_pTarget = pTarget;                                      //记录调用对象
    m_endPoint = new CCPoint();                                 //新建触摸的终点
    
    m_GeometricRecognizer = new GeometricRecognizer();          //新建识别类对象
    m_GeometricRecognizer->loadTemplates();                     //加载识别模版
    
    m_Clicked = false;                                          //是否为单击
    effectParticle = CCNode::create();                          //新建一个节点,用于装载粒子，便于显示路径
    
    this->addChild(effectParticle,10 );                         //把节点加到该层
    
    drawPoints.reserve(256);                                    //建立容纳256个点的容器
    drawState = true;                                           //默认开启划线，显示轨迹
    setDrawColor(ccc4(255,255,255,255));                        //默认设定为白色轨迹
    setValidZone(960,0,0,640);                                  //默认按4S的分辨率设置
    outOfBound = false;
    
    return true;
}

bool GestureManager::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
    CCPoint point = pTouch->getLocation();
    if(point.x < leftBound || point.x > rightBound || point.y < downBound || point.y > upBound)
    {
        outOfBound = true;
        CCLOG("out");
        return true;
    }
    CCParticleSystemQuad* mEffect = CCParticleSystemQuad::create("particle/TouchEffect.plist");
    mEffect->setPosition( 0, 0 );
    effectParticle->addChild(mEffect);

    effectParticle->setPosition( point.x, point.y );            //粒子节点跟随触摸点移动
    
    if(drawState)
    {
        clearPoints();
        drawPoints.push_back(point);
    }
    return true;
}

void GestureManager::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    if(outOfBound)
        return;
    CCPoint point = pTouch->getLocation();
    if(point.x < leftBound || point.x > rightBound || point.y < downBound || point.y > upBound)
        return;
    
    effectParticle->setPosition( point.x, point.y );            //粒子节点跟随触摸点移动

    CCPoint mLocation = pTouch->getLocationInView();
    Point2D mPoint;
    mPoint.x = mLocation.x;
    mPoint.y = mLocation.y;
    path.push_back(mPoint);                                     //把该点坐标写入路径中
    
    if(drawState)
        drawPoints.push_back(point);
}
void GestureManager::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if(outOfBound)
    {
        outOfBound = false;
        CCLOG("out end");
        return;
    }
    
    effectParticle->removeAllChildren();                        //移除粒子效果
    CCPoint mLocation = pTouch->getLocationInView();
    m_endPoint->x = mLocation.x;                                //记录终点坐标
    m_endPoint->y = mLocation.y;
    
//    CCPoint point = pTouch->getLocation();
//    if(drawState)
//        drawPoints.push_back(point);

//    FingerJudge();
    
}

void GestureManager::ccTouchCancelled( CCTouch *pTouch, CCEvent *pEvent )       //遇到取消触摸事件则初始化
{
    m_Clicked = false;
    path.clear();
    
    if(drawState)
        clearPoints();
}

void GestureManager::FingerJudge()
{
    if( path.size() < 1 )
    {
        CCLOG("click");
        return;
    }
    
    //PathWriter::writeToFile(path);                                            //把路径的点输出到文件
    
    
    
    RecognitionResult result = m_GeometricRecognizer->recognize(path);          //把路径交给识别类识别，得到结果
    
    CreatModeScene::shareCreatModeScene()->menuLayer->setCreatItemData(result.name, result.score);
//    path.clear();
}

void GestureManager::registerWithTouchDispatcher()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

void GestureManager::draw()
{
    if(drawState)
    {
        if(drawPoints.size() <= 1)
            return;
        glLineWidth(5);
        for(int i=0;i<drawPoints.size()-1;i++)
        {
            CCPoint point1 = drawPoints[i];
            CCPoint point2 = drawPoints[i+1];
            ccDrawLine(point1, point2);
        }
    }
}

void GestureManager::clearPoints()
{
    drawPoints.clear();
    path.clear();
}

void GestureManager::setValidZone(int up,int down,int left,int right)
{
    upBound = up;
    downBound = down;
    leftBound = left;
    rightBound = right;
}

void GestureManager::setDrawState(bool state)
{
    drawState = state;
}

void GestureManager::setDrawColor(ccColor4B color)
{
    ccDrawColor4B(color.r, color.g, color.b, color.a);
}

