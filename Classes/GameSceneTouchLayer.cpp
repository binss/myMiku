//
//  GameSceneTouchLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "GameSceneTouchLayer.h"
#include "toolClasses/CsvUtil.h"

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
    CsvUtil::sharedCsvUtil()->loadFile("notation/test.csv");
   
    //createElement(1.0f);
    //file = "notation/test.csv";
    line = 1;
    //createElement(0.1f);
    return true;
}

void GameSceneTouchLayer::createElement(float dt)
{
    if(CsvUtil::sharedCsvUtil()->getInt(line, 0, "notation/test.csv"))
    {
        int t1 = CsvUtil::sharedCsvUtil()->getInt(line, 1, "notation/test.csv");
        int t2 = CsvUtil::sharedCsvUtil()->getInt(line, 2, "notation/test.csv");
        if( t1 == 1 )
        {
            CCSprite *object = CCSprite::create("game/blueS.png");
            object->setTag(1);
            object->setPosition(ccp(75,565));
            leftArray->addObject(object);
            this->addChild(object);
            CCActionInterval *move = CCMoveBy::create(2.0, ccp(0,-550));
            object->runAction(move);
        }
        if( t2 == 1)
        {
            CCSprite *object = CCSprite::create("game/redS.png");
            object->setTag(2);
            object->setPosition(ccp(600,565));
            rightArray->addObject(object);
            this->addChild(object);
            CCActionInterval *move = CCMoveBy::create(2.0, ccp(0,-550));
            object->runAction(move);
        }
        CCLog("%i, %i",t1,t2);
        line ++;
    }
    else
    {
        unschedule(schedule_selector(GameSceneTouchLayer::createElement));
        line = 1;
    }
    
}

void GameSceneTouchLayer::update(float dt)
{
}

bool GameSceneTouchLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    
    //createElement(0.5f);
    //line = 1;
    //int t1 = CsvUtil::sharedCsvUtil()->getInt(line, 0, "notation/test.csv");
    //CCLog("%i",t1);

    this->schedule(schedule_selector(GameSceneTouchLayer::createElement),1.0f);
    return true;
}

void GameSceneTouchLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void GameSceneTouchLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    
}