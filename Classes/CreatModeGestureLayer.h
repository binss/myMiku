//
//  GestureManager.h
//  testForDollar1
//
//  Created by bin on 14-1-26.
//
//

#ifndef __testForDollar1__GestureManager__
#define __testForDollar1__GestureManager__

#include "cocos2d.h"
#include "GeometricRecognizer.h"
#include "PathWriter.h"

USING_NS_CC;
using namespace DollarRecognizer;

class GestureManager : public CCLayer
{
    
public:
    static GestureManager* create();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    virtual void draw();
    void clearPoints();
    void setDrawState(bool state);              //设置是否沿手势轨迹划线
    void setDrawColor(ccColor4B color);         //设置划线颜色
    void setValidZone(int up,int down,int left,int right);
    void FingerJudge();


    
private:
    bool init();

    std::vector<CCPoint> drawPoints;
    static GestureManager* mGestureManager;      //场景管理器对象
    CCPoint* m_endPoint;
    bool m_Clicked;
    GeometricRecognizer* m_GeometricRecognizer;
    CCNode* effectParticle;
    Path2D path;           //轨迹
    bool drawState;
    bool outOfBound;
    int leftBound;
    int rightBound;
    int upBound;
    int downBound;

};

#endif /* defined(__testForDollar1__GestureManager__) */
