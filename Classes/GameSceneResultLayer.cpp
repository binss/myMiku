//
//  GameSceneResultLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-25.
//
//

#include "GameSceneResultLayer.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "AudioPlayer.h"

bool GameSceneResultLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    GameScene::shareGameScene()->touchLayer->setTouchEnabled(false);
    GameScene::shareGameScene()->touchLayer->menu->setTouchEnabled(false);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite *background = CCSprite::create("game/result.png");
    background->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(background,0);
    
    coolLabel = CCLabelTTF::create("0","DFGirlKelvin",50);
    coolLabel->setPosition(ccp(700,610));
    coolLabel->setColor(ccc3(230,201,6));
    this->addChild(coolLabel,2);
    
    fineLabel = CCLabelTTF::create("0","DFGirlKelvin",50);
    fineLabel->setPosition(ccp(700,555));
    fineLabel->setColor(ccc3(0,168,255));
    this->addChild(fineLabel,2);
    
    safeLabel = CCLabelTTF::create("0","DFGirlKelvin",50);
    safeLabel->setPosition(ccp(700,500));
    safeLabel->setColor(ccc3(28,192,39));
    this->addChild(safeLabel,2);
    
    sadLabel = CCLabelTTF::create("0","DFGirlKelvin",50);
    sadLabel->setPosition(ccp(700,445));
    sadLabel->setColor(ccc3(176,107,240));    this->addChild(sadLabel,2);
    
    comboLabel = CCLabelTTF::create("0","DFGirlKelvin",50);
    comboLabel->setPosition(ccp(700,395));
    comboLabel->setColor(ccc3(255,0,0));
    this->addChild(comboLabel,2);
    
    counter =  CounterDown::create(0,6,60,30);
    counter->setPosition(ccp(310,275));
    this->addChild(counter);
    
    

    
    return true;
}

void GameSceneResultLayer::setScore(CCObject* psender)
{
    int newNumber = (dynamic_cast<CCInteger*>(psender))->getValue();
    counter->setNumber(counter->getCounterNumber() + newNumber);
}

void GameSceneResultLayer::setResult(int cool, int fine, int safe, int sad, int maxCombo)
{
    sprintf(buffer,"%d",cool);
    coolLabel->setString(buffer);
    sprintf(buffer,"%d",fine);
    fineLabel->setString(buffer);
    sprintf(buffer,"%d",safe);
    safeLabel->setString(buffer);
    sprintf(buffer,"%d",sad);
    sadLabel->setString(buffer);
    sprintf(buffer,"%d",maxCombo);
    comboLabel->setString(buffer);
    

    int coolScore = cool * 100;          //这里设置权重
    int fineScore = fine * 50;
    int safeScore = safe * 10;
    int sadScore = sad * (- 5);
    int comboScore;

    if(maxCombo < 10)
        comboScore = maxCombo * 10;
    else if(maxCombo < 30)
        comboScore = maxCombo * 50;
    else if(maxCombo < 50)
        comboScore = maxCombo * 80;
    else if(maxCombo < 100)
        comboScore = maxCombo * 100;
    else
        comboScore = maxCombo * 200;
    
    showResult(coolScore,fineScore,safeScore,sadScore,comboScore);
}

void GameSceneResultLayer::showResult(int coolScore,int fineScore,int safeScore,int sadScore,int comboScore)
{
    CCActionInterval *move = CCMoveBy::create(0.3f, ccp(-300,0));
    
    CCCallFuncO *set1 = CCCallFuncO::create(this,callfuncO_selector(GameSceneResultLayer::setScore),CCInteger::create(coolScore));
    CCCallFuncO *set2 = CCCallFuncO::create(this,callfuncO_selector(GameSceneResultLayer::setScore),CCInteger::create(fineScore));
    CCCallFuncO *set3 = CCCallFuncO::create(this,callfuncO_selector(GameSceneResultLayer::setScore),CCInteger::create(safeScore));
    CCCallFuncO *set4 = CCCallFuncO::create(this,callfuncO_selector(GameSceneResultLayer::setScore),CCInteger::create(sadScore));
    CCCallFuncO *set5 = CCCallFuncO::create(this,callfuncO_selector(GameSceneResultLayer::setScore),CCInteger::create(comboScore));
    CCCallFunc * set6 = CCCallFunc::create(this,callfunc_selector(GameSceneResultLayer::creatCloseButton));
    
    CCSequence *sequence1 = CCSequence::create(CCDelayTime::create(1),move,set1,NULL);
    CCSequence *sequence2 = CCSequence::create(CCDelayTime::create(2),move,set2,NULL);
    CCSequence *sequence3 = CCSequence::create(CCDelayTime::create(3),move,set3,NULL);
    CCSequence *sequence4 = CCSequence::create(CCDelayTime::create(4),move,set4,NULL);
    CCSequence *sequence5 = CCSequence::create(CCDelayTime::create(5),move,set5,set6,NULL);
    
    
    coolLabel->runAction(sequence1);
    fineLabel->runAction(sequence2);
    safeLabel->runAction(sequence3);
    sadLabel->runAction(sequence4);
    comboLabel->runAction(sequence5);
}

void GameSceneResultLayer::creatCloseButton()
{
    CCSprite *sprite = CCSprite::create("game/back_button.png");
    CCMenuItemSprite *menuItem = CCMenuItemSprite::create(sprite, sprite, this, menu_selector(GameSceneResultLayer::menuCallback));
    menuItem->setPosition(ccp(475,685));
    
    CCMenu *menu = CCMenu::create(menuItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
}

void GameSceneResultLayer::menuCallback(cocos2d::CCNode *pSender)
{
    SceneManager::sharedSceneManager()->changeScene(SceneManager::en_MainScene);
    CCDirector::sharedDirector()->resume();
    
    this->removeAllChildren();
    this->removeFromParentAndCleanup(true);
}