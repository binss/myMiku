//
//  CreatModeMenuLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-28.
//
//

#include "CreatModeMenuLayer.h"
#include "CreatModeScene.h"

bool CreatModeMenuLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
//    this->setTouchEnabled(true);
//    setTouchMode(kCCTouchesOneByOne);
    
//    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCLabelTTF *clearLabel = CCLabelTTF::create("清空","DFGirlKelvin",60);
    clearLabel->setColor(ccc3(255,255,255));
    
    CCLabelTTF *creatLabel = CCLabelTTF::create("创造","DFGirlKelvin",60);
    creatLabel->setColor(ccc3(255,255,255));
    
    
    CCMenuItemLabel *clearItem = CCMenuItemLabel::create(clearLabel, this, menu_selector(CreatModeMenuLayer::clearMenuCallback));
    clearItem->setPosition(ccp(150,130));
    
    CCMenuItemLabel *creatItem = CCMenuItemLabel::create(creatLabel, this, menu_selector(CreatModeMenuLayer::creatMenuCallback));
    creatItem->setPosition(ccp(490,130));
    
    CCSprite *penSprite = CCSprite::create("creatMode/pen_normal.png");
    CCSprite *penLightSprite = CCSprite::create("creatMode/pen_light.png");


    CCMenuItemSprite *penItem = CCMenuItemSprite::create(penLightSprite,penSprite , this, menu_selector(CreatModeMenuLayer::penMenuCallback));
    penItem->setPosition(ccp(550,750));

    
    CCMenu *menu = CCMenu::create(clearItem,creatItem,penItem,NULL);
    
    menu->setPosition(CCPointZero);
    this->addChild(menu);

    
    
    return true;
}

void CreatModeMenuLayer::clearMenuCallback(cocos2d::CCNode *pSender)
{
    CreatModeScene::shareCreatModeScene()->gestureLayer->clearPoints();
}

void CreatModeMenuLayer::creatMenuCallback(cocos2d::CCNode *pSender)
{
    CreatModeScene::shareCreatModeScene()->gestureLayer->FingerJudge();
    
}

void CreatModeMenuLayer::penMenuCallback(cocos2d::CCNode *pSender)
{
    CCLOG("pen");

}

void CreatModeMenuLayer::setCreatItemData(std::string name, double value)
{
    CCLOG("judge: %s,%f",name.c_str(),value);

}
