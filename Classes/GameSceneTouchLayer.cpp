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
	this->setTouchMode(kCCTouchesAllAtOnce);            //多点触摸
	this->setTouchPriority(10);
    
    winSize = CCDirector::sharedDirector()->getWinSize();

    CCSprite * leftCycle = CCSprite::create("game/blueC.png");
    leftCycle->setPosition(ccp(leftCycle->getContentSize().width / 2, leftCycle->getContentSize().height / 2));
    CCSprite * rightCycle = CCSprite::create("game/redC.png");
    rightCycle->setPosition(ccp(winSize.width - rightCycle->getContentSize().width / 2, rightCycle->getContentSize().height / 2));
    
    this->addChild(leftCycle);
    this->addChild(rightCycle);
    this->scheduleUpdate();
    
    CCLabelTTF* pLabel = CCLabelTTF::create("test", "Arial", 50);//参数分别是：按钮要显示的文字，字体，字号
	CCMenuItemLabel* pBtn = CCMenuItemLabel::create(pLabel, this,menu_selector(GameSceneTouchLayer::menuCallback)) ;
	pBtn->setPosition(ccp(240, 800));
	CCMenu* pMenu = CCMenu::create(pBtn, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu);

    
    
    
    
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

void GameSceneTouchLayer::menuCallback(CCNode *pSender)
{
    this->schedule(schedule_selector(GameSceneTouchLayer::createElement),1.0f);
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
            
            CCActionInterval *move = CCMoveBy::create(2.0, ccp(0,-640));
            CCCallFuncO *callback = CCCallFuncO::create(this,callfuncO_selector(GameSceneTouchLayer::rubbishCollection),object);
            CCSequence *sequence = CCSequence::create(move,callback,NULL);
            object->runAction(sequence);
            
        }
        if( t2 == 1)
        {
            CCSprite *object = CCSprite::create("game/redS.png");
            object->setTag(2);
            object->setPosition(ccp(600,565));
            rightArray->addObject(object);
            this->addChild(object);
            
            CCActionInterval *move = CCMoveBy::create(2.0, ccp(0,-640));
            CCCallFuncO *callback = CCCallFuncO::create(this,callfuncO_selector(GameSceneTouchLayer::rubbishCollection),object);
            CCSequence *sequence = CCSequence::create(move,callback,NULL);
            object->runAction(sequence);
            
        }
        CCLog("%i, %i",t1,t2);
        line ++;
    }
    else
    {
        //unschedule(schedule_selector(GameSceneTouchLayer::createElement));
        line = 1;
    }
    
}

void GameSceneTouchLayer::update(float dt)
{
}


void GameSceneTouchLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCObject *obj;
    CCSetIterator itor;
    for( itor = pTouches->begin(); itor != pTouches->end(); ++itor)             //遍历同时触控的点
    {
        CCTouch *pTouch = dynamic_cast<CCTouch *>(*itor);
        //获得游戏坐标位置
        CCPoint ccp = pTouch->getLocation();
        printf("%f\t%f\n", ccp.x, ccp.y);
        if(ccp.y < 200)                                                         //范围判断
        {
            if(ccp.x > 0 && ccp.x < 150)
            {
                CCARRAY_FOREACH(leftArray,obj)
                {
                    CCSprite *object = (CCSprite*)obj;
                    if(object->getPositionY() > 0 && object->getPositionY() < 150)
                    {
                        rubbishCollection(object);
                        CCParticleSystem * particle=CCParticleExplosion::create();
                        particle->setPosition(ccp(75,75));
                        particle->setAutoRemoveOnFinish(true);
                        this->addChild(particle);
                        
                    }
                }
            }
            if(ccp.x > 490 && ccp.x < 640)
            {
                CCARRAY_FOREACH(rightArray,obj)
                {
                    CCSprite *object = (CCSprite*)obj;
                    if(object->getPositionY() > 0 && object->getPositionY() < 150)
                    {
                        rubbishCollection(object);
                        CCParticleSystem * particle=CCParticleExplosion::create();
                        particle->setPosition(ccp(600,75));
                        particle->setAutoRemoveOnFinish(true);
                        this->addChild(particle);
                    }
                }
            }
        }
    }

    
                
    /*
    if(pTouches->count() >= 2)  //多点触控
    {
        CCSetIterator itor;
        for( itor = pTouches->begin(); itor != pTouches->end(); ++itor)
        {
            CCTouch *pTouch = dynamic_cast<CCTouch *>(*itor);
            //获得游戏坐标位置
            CCPoint ccp = pTouch->getLocation();
            printf("%f\t%f\n", ccp.x, ccp.y);
        }
        printf("\n");
    }
    else    //单点触控
    {
        CCTouch *pTouch = dynamic_cast<CCTouch *>(pTouches->anyObject());
        CCPoint ccp = pTouch->getLocation();
        printf("%f\t%f\n", ccp.x, ccp.y);
    }
    //createElement(0.5f);
    //line = 1;
    //int t1 = CsvUtil::sharedCsvUtil()->getInt(line, 0, "notation/test.csv");
    //CCLog("%i",t1);

    //this->schedule(schedule_selector(GameSceneTouchLayer::createElement),1.0f);
     */
}

void GameSceneTouchLayer::rubbishCollection(CCObject *object)               //destroy the object which is out of view
{
    CCSprite *sprite = (CCSprite*)object;
    if (sprite->getTag() == 1 )
    {
        leftArray->removeObject(sprite);
        sprite->stopAllActions();
        //sprite->removeAllChildrenWithCleanup(true);
        this->removeChild(sprite,true);
        return;
    }
    if (sprite->getTag() == 2 )
    {
        rightArray->removeObject(sprite);
        sprite->stopAllActions();
        //sprite->removeAllChildrenWithCleanup(true);
        this->removeChild(sprite,true);
        return;
    }
}

void GameSceneTouchLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    
}

void GameSceneTouchLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    
}