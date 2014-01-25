//
//  GameSceneTouchLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "GameSceneTouchLayer.h"
#include "toolClasses/StringUtil.h"
#include "toolClasses/CsvUtil.h"
#include "AudioPlayer.h"
#include "GameScene.h"
#include "GameScenePauseLayer.h"
#include "GameSceneResultLayer.h"

bool GameSceneTouchLayer::init()
{
    //添加观察者，监视GameSongSelectScene发来的歌曲信息
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameSceneTouchLayer::setSongInfo),"SongNum", NULL);
    
    
	leftArray = CCArray::create();
	leftArray->retain();
    rightArray = CCArray::create();
	rightArray->retain();
    

   
	this->setTouchEnabled(true);
	this->setTouchMode(kCCTouchesAllAtOnce);            //多点触摸
	this->setTouchPriority(10);
    
    winSize = CCDirector::sharedDirector()->getWinSize();

    leftCycle = CCSprite::create("game/blueC.png");
    leftCycle->setPosition(ccp(leftCycle->getContentSize().width / 2 + 50 , leftCycle->getContentSize().height / 2 + 50));
    rightCycle = CCSprite::create("game/redC.png");
    rightCycle->setPosition(ccp(winSize.width - rightCycle->getContentSize().width / 2 - 50, rightCycle->getContentSize().height / 2 + 50));
    
    leftCoolSign = CCSprite::create("game/cool.png");
    leftCoolSign->setPosition(ccp(240, 75));
    this->addChild(leftCoolSign);
    
    leftFineSign = CCSprite::create("game/fine.png");
    leftFineSign->setPosition(ccp(240, 75));
    this->addChild(leftFineSign);
    
    leftSafeSign = CCSprite::create("game/safe.png");
    leftSafeSign->setPosition(ccp(240, 75));
    this->addChild(leftSafeSign);
    
    leftSadSign = CCSprite::create("game/sad.png");
    leftSadSign->setPosition(ccp(240, 75));
    this->addChild(leftSadSign);
    
    rightCoolSign = CCSprite::create("game/cool.png");
    rightCoolSign->setPosition(ccp(400, 75));
    this->addChild(rightCoolSign);
    
    rightFineSign = CCSprite::create("game/fine.png");
    rightFineSign->setPosition(ccp(400, 75));
    this->addChild(rightFineSign);
    
    rightSafeSign = CCSprite::create("game/safe.png");
    rightSafeSign->setPosition(ccp(400, 75));
    this->addChild(rightSafeSign);
    
    rightSadSign = CCSprite::create("game/sad.png");
    rightSadSign->setPosition(ccp(400, 75));
    this->addChild(rightSadSign);
    
    hideLeftSign(0.1f);
    hideRightSign(0.1f);
    
    this->addChild(leftCycle);
    this->addChild(rightCycle);
    
    //菜单按钮
    CCSprite *sprite1 = CCSprite::create("game/pause_button1.png");
    CCSprite *sprite2 = CCSprite::create("game/pause_button2.png");
    CCSprite *sprite3 = CCSprite::create("game/help_button1.png");
    CCSprite *sprite4 = CCSprite::create("game/help_button2.png");

    CCMenuItemSprite *menuItem1 = CCMenuItemSprite::create(sprite1, sprite2, this, menu_selector(GameSceneTouchLayer::pauseButtonCallback));
    menuItem1->setPosition(ccpAdd(ccp(0,10),ccp(40,35)));
    CCMenuItemSprite *menuItem2 = CCMenuItemSprite::create(sprite3, sprite4, this, menu_selector(GameSceneTouchLayer::helpButtonCallback));
    menuItem2->setPosition(ccpAdd(ccp(100,0), ccp(26,40)));
    
    menu = CCMenu::create(menuItem1, menuItem2, NULL);
    menu->setPosition(ccp(470,860));
    this->addChild(menu);

    //backgroundInit();
    

	//this->scheduleUpdate();
    
    csvPath = new char[50];

    line = 1;

    return true;
}

void GameSceneTouchLayer::pauseButtonCallback(cocos2d::CCNode *pSender)
{
    GameScenePauseLayer* pauseLayer = new GameScenePauseLayer();
    if(pauseLayer && pauseLayer->init())
    {
        pauseLayer->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pauseLayer);
    }
    
    pauseLayer->setAnchorPoint(ccp(0, 0));
    pauseLayer->setPosition(ccp(0,0));
    
    GameScene::shareGameScene()->addChild(pauseLayer,20);
    CCDirector::sharedDirector()->pause();
    AudioPlayer::sharedAudio()->pauseMusic();
}


void GameSceneTouchLayer::helpButtonCallback(cocos2d::CCNode *pSender)
{
    GameSceneResultLayer* resultLayer = new GameSceneResultLayer();
    if(resultLayer && resultLayer->init())
    {
        resultLayer->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(resultLayer);
    }
    
    resultLayer->setAnchorPoint(ccp(0, 0));
    resultLayer->setPosition(ccp(0,0));
    resultLayer->setResult(100, 20, 33, 44, 55);
    GameScene::shareGameScene()->addChild(resultLayer,20);
    AudioPlayer::sharedAudio()->pauseMusic();
}

void GameSceneTouchLayer::ready()
{
    unschedule(schedule_selector(GameSceneTouchLayer::createElement));
    unschedule(schedule_selector(GameSceneTouchLayer::updateCycle));
    unschedule(schedule_selector(GameSceneTouchLayer::finish));
    CCObject *obj;
    CCARRAY_FOREACH(leftArray,obj)
    {
        CCSprite *object = (CCSprite*)obj;
        rubbishCollection(object);
    }
    CCARRAY_FOREACH(rightArray,obj)
    {
        CCSprite *object = (CCSprite*)obj;
        rubbishCollection(object);
    }

    CsvUtil::sharedCsvUtil()->loadFile(csvPath);
    AudioPlayer::sharedAudio()->preLoadMusic(songNum);
    this->scheduleOnce(schedule_selector(GameSceneTouchLayer::start),5.0f);
    this->schedule(schedule_selector(GameSceneTouchLayer::updateCycle),0.2f);
    coolNum = 0;
    fineNum = 0;
    safeNum = 0;
    sadNum = 0;
    comboNum = 0;
}

void GameSceneTouchLayer::start(CCNode *pSender)
{
    float musicTime = 215.0f;
    AudioPlayer::sharedAudio()->playMusic(songNum);
    CCLOG("play");
    this->schedule(schedule_selector(GameSceneTouchLayer::createElement),1.0f);
    this->scheduleOnce(schedule_selector(GameSceneTouchLayer::finish),musicTime);
}

void GameSceneTouchLayer::finish(CCNode *pSender)
{
    unschedule(schedule_selector(GameSceneTouchLayer::createElement));
    unschedule(schedule_selector(GameSceneTouchLayer::updateCycle));
    CCLOG("cool: %i  fine: %i  safe: %i  sad: %i",coolNum,fineNum,safeNum,sadNum);
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
            object->setPosition(ccp(110,565));
            leftArray->addObject(object);
            this->addChild(object);
            
            CCActionInterval *move = CCMoveBy::create(2.0, ccp(0,-640));
            CCCallFuncO *callback = CCCallFuncO::create(this,callfuncO_selector(GameSceneTouchLayer::rubbishCollection),object);
            CCCallFuncO *sad = CCCallFuncO::create(this,callfuncO_selector(GameSceneTouchLayer::setSadSign),object);
            CCSequence *sequence = CCSequence::create(move,sad,callback,NULL);
            object->runAction(sequence);
            
        }
        if( t2 == 1)
        {
            CCSprite *object = CCSprite::create("game/redS.png");
            object->setTag(2);
            object->setPosition(ccp(530,565));
            rightArray->addObject(object);
            this->addChild(object);
            
            CCActionInterval *move = CCMoveBy::create(2.0, ccp(0,-640));
            CCCallFuncO *callback = CCCallFuncO::create(this,callfuncO_selector(GameSceneTouchLayer::rubbishCollection),object);
            CCCallFuncO *sad = CCCallFuncO::create(this,callfuncO_selector(GameSceneTouchLayer::setSadSign),object);
            CCSequence *sequence = CCSequence::create(move,sad,callback,NULL);
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

void GameSceneTouchLayer::setSadSign(CCObject *object)
{
    CCSprite *sprite = (CCSprite*)object;
    if (sprite->getTag() == 1 )
        setSign(true, sad);
    if (sprite->getTag() == 2 )
        setSign(false, sad);
    
    comboNum = 0;
    sadNum ++;
    GameScene::shareGameScene()->displayLayer->setCombo(comboNum);
}

void GameSceneTouchLayer::update(float dt)
{
    
}

void GameSceneTouchLayer::updateCycle(float dt)             //符号经过时圆圈缩放效果
{
    CCObject *obj;
    CCARRAY_FOREACH(leftArray,obj)
    {
        CCSprite *object = (CCSprite*)obj;
        if(object->getPositionY() > 0 && object->getPositionY() < 150)
        {
            CCActionInterval *scale = CCScaleTo::create(0.1f, 1.5f);
            CCActionInterval *back = CCScaleTo::create(0.1f, 1.0f);
            CCSequence *sequence = CCSequence::create(scale,back,NULL);
            leftCycle->runAction(sequence);
        }
    }
    CCARRAY_FOREACH(rightArray,obj)
    {
        CCSprite *object = (CCSprite*)obj;
        if(object->getPositionY() > 0 && object->getPositionY() < 150)
        {
            CCActionInterval *scale = CCScaleTo::create(0.1f, 1.5f);
            CCActionInterval *back = CCScaleTo::create(0.1f, 1.0f);
            CCSequence *sequence = CCSequence::create(scale,back,NULL);
            rightCycle->runAction(sequence);
        }
    }
}

void GameSceneTouchLayer::hideLeftSign(float dt)
{
    leftCoolSign->setVisible(false);
    leftFineSign->setVisible(false);
    leftSafeSign->setVisible(false);
    leftSadSign->setVisible(false);
}

void GameSceneTouchLayer::hideRightSign(float dt)
{
    rightCoolSign->setVisible(false);
    rightFineSign->setVisible(false);
    rightSafeSign->setVisible(false);
    rightSadSign->setVisible(false);
}

void GameSceneTouchLayer::setSign(bool side, int sign)
{
    if(side)                    //true 为左边
    {
        switch (sign)
        {
            case cool:
                leftCoolSign->setVisible(true);
                break;
            case fine:
                leftFineSign->setVisible(true);
                break;
            case safe:
                leftSafeSign->setVisible(true);
                break;
            case sad:
                leftSadSign->setVisible(true);
        }
        scheduleOnce(schedule_selector(GameSceneTouchLayer::hideLeftSign), 0.4f);
    }
    else
    {
        switch (sign)
        {
            case cool:
                rightCoolSign->setVisible(true);
                break;
            case fine:
                rightFineSign->setVisible(true);
                break;
            case safe:
                rightSafeSign->setVisible(true);
                break;
            case sad:
                rightSadSign->setVisible(true);
        }
        scheduleOnce(schedule_selector(GameSceneTouchLayer::hideRightSign), 0.4f);
        
    }
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
//        printf("%f\t%f\n", ccp.x, ccp.y);
        if(ccp.y < 200)                                                         //只允许y值小于200的触摸生效
        {
            if(ccp.x > 40 && ccp.x < 180)                                       //只允许x值为40-180(leftCycle)的触摸生效
            {
                AudioPlayer::sharedAudio()->playEffect(leftClick);              //击打音效
                GameScene::shareGameScene()->displayLayer->turnLeft();
                CCARRAY_FOREACH(leftArray,obj)
                {
                    CCSprite *object = (CCSprite*)obj;
                    float x = object->getPositionX();
                    float y = object->getPositionY();
                    if(y <= 200 )
                    {
                        if( y >= 90 && y <= 130 )
                        {
                            setSign(true, cool);
                            comboNum ++;
                            coolNum ++;
                        }
                        else if(( y > 130 && y <= 170) || ( y >= 50 && y < 90 ))
                        {
                            setSign(true, fine);
                            comboNum ++;
                            fineNum ++;
                        }
                        else if(( y > 170 && y <= 200) || ( y >= 20 && y < 50))
                        {
                            setSign(true, safe);
                            comboNum = 0;
                            safeNum ++;
                        }
                        GameScene::shareGameScene()->displayLayer->setCombo(comboNum);
                        rubbishCollection(object);
                        CCParticleSystem * particle=CCParticleExplosion::create();
                        particle->setPosition(ccp(x,y));
                        particle->setAutoRemoveOnFinish(true);
                        this->addChild(particle);

                    }
                }
            }
            if(ccp.x > 460 && ccp.x < 600)                                      //只允许x值为460-600(rightCycle)的触摸生效
            {
                AudioPlayer::sharedAudio()->playEffect(rightClick);             //击打音效
                GameScene::shareGameScene()->displayLayer->turnRight();

                CCARRAY_FOREACH(rightArray,obj)
                {
                    CCSprite *object = (CCSprite*)obj;
                    float x = object->getPositionX();
                    float y = object->getPositionY();
                    if(y <= 200 )
                    {
                        if( y >= 90 && y <= 130 )
                        {
                            setSign(false, cool);
                            comboNum ++;
                            coolNum ++;
                        }
                        else if(( y > 130 && y <= 170) || ( y >= 50 && y < 90 ))
                        {
                            setSign(false, fine);
                            comboNum ++;
                            fineNum ++;
                        }
                        else if(( y > 170 && y <= 200) || ( y >= 20 && y < 50))
                        {
                            setSign(false, safe);
                            comboNum = 0;
                            safeNum ++;
                        }
                        GameScene::shareGameScene()->displayLayer->setCombo(comboNum);
                        rubbishCollection(object);
                        CCParticleSystem * particle=CCParticleExplosion::create();
                        particle->setPosition(ccp(x,y));
                        particle->setAutoRemoveOnFinish(true);
                        this->addChild(particle);
                    }
                }
            }
        }
    }

    //createElement(0.5f);
    //line = 1;
    //int t1 = CsvUtil::sharedCsvUtil()->getInt(line, 0, "notation/test.csv");
    //CCLog("%i",t1);

    //this->schedule(schedule_selector(GameSceneTouchLayer::createElement),1.0f);
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

void GameSceneTouchLayer::setSongInfo(CCObject *pSender)
{
    CCArray *dataList = (CCArray *)pSender;
    songNum = ((CCString*)dataList->objectAtIndex(0))->intValue();
    strncpy(csvPath,((CCString*)dataList->objectAtIndex(1))->getCString(),50);
    CCLog("setSongInfo: %i , %s",songNum,csvPath);
    ready();
    CC_SAFE_RELEASE_NULL(dataList);         //释放数组
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, "SongNum");      //释放观察者
}