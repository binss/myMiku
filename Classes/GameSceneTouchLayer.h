//
//  GameSceneTouchLayer.h
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#ifndef __myMiku__GameSceneTouchLayer__
#define __myMiku__GameSceneTouchLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"

using namespace std;
USING_NS_CC;
using namespace extension;
using namespace CocosDenshion;

class GameSceneTouchLayer : public cocos2d::CCLayer
{
public:
    
    bool init();
    
    //void backgroundInit();
    
	CCArmature *chenxiaogeArmature;
	CCPoint chenxiaogePosition;
    
private:
    
	void update(float dt);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void createElement(float dt);
	//void rubbishCollection(CCObject *object);
    //void gameOver();
	
	//CCParticleSystem *particle;
	//CCParticleSystem *particle2;
	CCSize winSize;
	CCArray *leftArray;
    CCArray *rightArray;
    
    CREATE_FUNC(GameSceneTouchLayer);
};

#endif /* defined(__myMiku__GameSceneTouchLayer__) */
