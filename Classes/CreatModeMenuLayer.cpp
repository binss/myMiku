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
    
    
    clearItem = CCMenuItemLabel::create(clearLabel, this, menu_selector(CreatModeMenuLayer::clearMenuCallback));
    clearItem->setPosition(ccp(150,130));
    
    creatItem = CCMenuItemLabel::create(creatLabel, this, menu_selector(CreatModeMenuLayer::creatMenuCallback));
    creatItem->setPosition(ccp(490,130));
    
    CCSprite *penSprite = CCSprite::create("creatMode/pen_normal.png");
    CCSprite *penLightSprite = CCSprite::create("creatMode/pen_light.png");


    CCMenuItemSprite *penItem = CCMenuItemSprite::create(penSprite, penLightSprite, this, menu_selector(CreatModeMenuLayer::penMenuCallback));
    penItem->setPosition(ccp(550,750));

    
    CCMenu *menu = CCMenu::create(clearItem,creatItem,penItem,NULL);
    
    menu->setPosition(CCPointZero);
    this->addChild(menu);

    selectState = false;
    
    
    return true;
}

void CreatModeMenuLayer::clearMenuCallback(cocos2d::CCNode *pSender)
{
    CCLOG("clear");
    CreatModeScene::shareCreatModeScene()->gestureLayer->clearPoints();
}

void CreatModeMenuLayer::creatMenuCallback(cocos2d::CCNode *pSender)
{
    CreatModeScene::shareCreatModeScene()->gestureLayer->FingerJudge();
    
}

void CreatModeMenuLayer::penMenuCallback(cocos2d::CCNode *pSender)
{
    if(!selectState)
    {
        CreatModeScene::shareCreatModeScene()->displayLayer->creatModeLabel->setString("图鉴");
        //CreatModeScene::shareCreatModeScene()->gestureLayer->clearPoints();
        CreatModeScene::shareCreatModeScene()->gestureLayer->setVisible(false);
        CreatModeScene::shareCreatModeScene()->gestureLayer->setTouchEnabled(false);

        clearItem->setVisible(false);
        creatItem->setVisible(false);

        selectLayer = new CreatModeSelectLayer();
        if(selectLayer && selectLayer->init())
        {
            selectLayer->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(selectLayer);
        }

        selectLayer->setAnchorPoint(ccp(0, 0));
        selectLayer->setPosition(ccp(0,0));
        addChild(selectLayer,10);
        selectState = true;
    }
    else
    {
        CreatModeScene::shareCreatModeScene()->displayLayer->creatModeLabel->setString("创造模式");
        CreatModeScene::shareCreatModeScene()->gestureLayer->setTouchEnabled(true);
        CreatModeScene::shareCreatModeScene()->gestureLayer->setVisible(true);

        clearItem->setVisible(true);
        creatItem->setVisible(true);
        
        selectLayer->removeAllChildren();
        selectLayer->removeFromParentAndCleanup(true);
        selectState = false;
    }

}

void CreatModeMenuLayer::setCreatItemData(std::string name, double value)
{
    CCLOG("judge: %s,%f",name.c_str(),value);
    if(value < 0.7)
    {
        CCLOG("创造失败");
        return;
    }
    if(strncmp(name.c_str(),"null",4))
    {
           
    }
       

}
