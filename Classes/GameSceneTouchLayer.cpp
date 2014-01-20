//
//  GameSceneTouchLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "GameSceneTouchLayer.h"

bool GameSceneTouchLayer::init()
{
	leftArray = CCArray::create();
	leftArray->retain();
    rightArray = CCArray::create();
	rightArray->retain();
   
	this->setTouchEnabled(true);
	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchPriority(10);
    
    winSize = CCDirector::sharedDirector()->getWinSize();

    CCSprite * leftCycle = CCSprite::create("game/blueC.png");
    leftCycle->setPosition(ccp(leftCycle->getContentSize().width / 2, leftCycle->getContentSize().height / 2));
    CCSprite * rightCycle = CCSprite::create("game/redC.png");
    rightCycle->setPosition(ccp(winSize.width - rightCycle->getContentSize().width / 2, rightCycle->getContentSize().height / 2));
    
    this->addChild(leftCycle);
    this->addChild(rightCycle);
    this->scheduleUpdate();

    //backgroundInit();
    
    //score = 0;
    
	//this->schedule(schedule_selector(GameScenePlayLayer::createCoin),0.8f);
	//this->schedule(schedule_selector(GameScenePlayLayer::changeSeason),10);
	//this->scheduleUpdate();
    
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/background.mp3", true);
	//SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5f);
    return true;
}

void GameSceneTouchLayer::createElement(float dt)
{
    //获取下一行
    
}

void GameSceneTouchLayer::update(float dt)
{
}

bool GameSceneTouchLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}

void GameSceneTouchLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void GameSceneTouchLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    
}