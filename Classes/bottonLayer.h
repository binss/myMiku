//
//  bottonLayer.h
//  myMiku
//
//  Created by bin on 14-1-15.
//
//

#ifndef __myMiku__bottonLayer__
#define __myMiku__bottonLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class bottonLayer : public cocos2d::CCLayer,public CCScrollViewDelegate
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void registerWithTouchDispatcher();
    void scrollViewDidScroll(CCScrollView* view);
    void scrollViewDidZoom(CCScrollView* view);

    CREATE_FUNC(bottonLayer);
private:
    CCScrollView *scrollView;
    // 菜单回调

    void menu1Callback(CCNode *pSender);
    void menu2Callback(CCNode *pSender);
    void menu3Callback(CCNode *pSender);
    void menu4Callback(CCNode *pSender);


};

#endif /* defined(__myMiku__bottonLayer__) */
