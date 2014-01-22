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
//#include "SimpleAudioEngine.h"

using namespace std;
USING_NS_CC;
using namespace extension;
//using namespace CocosDenshion;



class GameSceneTouchLayer : public cocos2d::CCLayer
{
    enum sign
    {
        cool = 0,
        fine,
        safe,
        sad
    };
    
    enum click
    {
        leftClick = 0,
        rightClick
    };
    
    
    
    enum musicList
    {
        deepSeaGirl = 0
    };
public:
    
    bool init();
    
    //void backgroundInit();
    
	CCArmature *chenxiaogeArmature;
	CCPoint chenxiaogePosition;
    
private:
    
	void update(float dt);
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	void createElement(float dt);
    void rubbishCollection(CCObject *object);
    void menuCallback(CCNode *pSender);
    void updateCycle(float dt);
    void setSign(bool side,int sign);
    void hideLeftSign(float dt);
    void hideRightSign(float dt);
    void setSadSign(CCObject *object);
    void start(CCNode *pSender);
    void finish(CCNode *pSender);

	//void rubbishCollection(CCObject *object);
    //void gameOver();
	
	//CCParticleSystem *particle;
	//CCParticleSystem *particle2;
	CCSize winSize;
	CCArray *leftArray;
    CCArray *rightArray;
    
    CCSprite *leftCycle;
    CCSprite *rightCycle;
    CCSprite *leftCoolSign;
    CCSprite *leftFineSign;
    CCSprite *leftSafeSign;
    CCSprite *leftSadSign;
    CCSprite *rightCoolSign;
    CCSprite *rightFineSign;
    CCSprite *rightSafeSign;
    CCSprite *rightSadSign;

    int line;
    const char * file;
    int coolNum;
    int fineNum;
    int safeNum;
    int sadNum;

    
    CREATE_FUNC(GameSceneTouchLayer);
};

#endif /* defined(__myMiku__GameSceneTouchLayer__) */
