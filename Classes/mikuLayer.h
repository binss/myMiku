#ifndef __mikuLayer_SCENE_H__
#define __mikuLayer_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class mikuLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    //virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    //static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    
    // implement the "static node()" method manually
    CREATE_FUNC(mikuLayer);
    virtual void registerWithTouchDispatcher();
    void checkQuestionBoxStatus(float dt);
    //void update(float dt);
    CCArmature * armature;
    int i;
    
};

#endif // __mikuLayer_SCENE_H__
