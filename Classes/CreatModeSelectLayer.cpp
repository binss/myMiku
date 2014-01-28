//
//  CreatModeSelectLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-28.
//
//

#include "CreatModeSelectLayer.h"

USING_NS_CC;

bool CreatModeSelectLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *fishSprite = CCSprite::create("buttons/food.png");
    CCSprite *dollarSprite = CCSprite::create("buttons/game.png");

    
    int spriteSize = 64;
    // Menu
    /*
    CCMenuItemSprite *menuItem1 = CCMenuItemSprite::create(sprite1, sprite1, this, menu_selector(bottonLayer::menu1Callback));
    menuItem1->setPosition(ccpAdd(ccp(16,20),ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem2 = CCMenuItemSprite::create(sprite2, sprite2, this, menu_selector(bottonLayer::menu2Callback));
    menuItem2->setPosition(ccpAdd(ccp(176,20), ccp(spriteSize,spriteSize)));
    
    CCMenu *menu = CCMenu::create(menuItem1, menuItem2,menuItem3,menuItem4,menuItem5,menuItem6,menuItem7,menuItem8, NULL); d
    menu->setPosition(CCPointZero);
    layer->addChild(menu);
    
    scrollView = CCScrollView::create(); // 创建一个实例
    scrollView->setContentSize(CCSizeMake(640, 168)); //设置容器大小（内容尺寸）
    scrollView->setViewSize(CCSizeMake(640, 168)); //设置显示（可视）范围
    scrollView->setContainer(layer);
    scrollView->setDirection(kCCScrollViewDirectionHorizontal );
    scrollView->setTouchPriority(-130);   //提升优先级到比ccMenu高
    this->addChild(scrollView);
    */
    return true;
}


void CreatModeSelectLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
}

void CreatModeSelectLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
}
/*
void bottonLayer::registerWithTouchDispatcher()
{
    //CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-10,true);
}


bool bottonLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCLOG("B");
    return true;
}

void bottonLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCLOG("yeah");
}

void bottonLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    
}
 */
