//
//  bottonLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-15.
//
//

#include "bottonLayer.h"
#include "SceneManager.h"
USING_NS_CC;

bool bottonLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //CCSize size = CCDirector::sharedDirector()->getWinSize();

    CCLayerColor *layer = CCLayerColor::create(ccc4(192, 192, 192, 255));
    //CCLayer *layer = CCLayer::create();
    layer->setContentSize(CCSizeMake(1280,168));
    CCSprite *sprite1 = CCSprite::create("buttons/food.png");
    CCSprite *sprite2 = CCSprite::create("buttons/game.png");
    CCSprite *sprite3 = CCSprite::create("buttons/gift.png");
    CCSprite *sprite4 = CCSprite::create("buttons/heart.png");
    CCSprite *sprite5 = CCSprite::create("buttons/lib.png");
    CCSprite *sprite6 = CCSprite::create("buttons/money.png");
    CCSprite *sprite7 = CCSprite::create("buttons/setting.png");
    CCSprite *sprite8 = CCSprite::create("buttons/talk.png");
    
    int spriteSize = 64;
    // Menu
    CCMenuItemSprite *menuItem1 = CCMenuItemSprite::create(sprite1, sprite1, this, menu_selector(bottonLayer::menu1Callback));
    menuItem1->setPosition(ccpAdd(ccp(16,20),ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem2 = CCMenuItemSprite::create(sprite2, sprite2, this, menu_selector(bottonLayer::menu2Callback));
    menuItem2->setPosition(ccpAdd(ccp(176,20), ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem3 = CCMenuItemSprite::create(sprite3, sprite3, this, menu_selector(bottonLayer::menu3Callback));
    menuItem3->setPosition(ccpAdd(ccp(336,20), ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem4 = CCMenuItemSprite::create(sprite4, sprite4, this, menu_selector(bottonLayer::menu3Callback));
    menuItem4->setPosition(ccpAdd(ccp(496,20), ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem5 = CCMenuItemSprite::create(sprite5, sprite5, this, menu_selector(bottonLayer::menu3Callback));
    menuItem5->setPosition(ccpAdd(ccp(656,20), ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem6 = CCMenuItemSprite::create(sprite6, sprite6, this, menu_selector(bottonLayer::menu3Callback));
    menuItem6->setPosition(ccpAdd(ccp(816,20), ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem7 = CCMenuItemSprite::create(sprite7, sprite7, this, menu_selector(bottonLayer::menu3Callback));
    menuItem7->setPosition(ccpAdd(ccp(976,20), ccp(spriteSize,spriteSize)));
    CCMenuItemSprite *menuItem8 = CCMenuItemSprite::create(sprite8, sprite8, this, menu_selector(bottonLayer::menu3Callback));
    menuItem8->setPosition(ccpAdd(ccp(1136,20), ccp(spriteSize,spriteSize)));

    CCMenu *menu = CCMenu::create(menuItem1, menuItem2,menuItem3,menuItem4,menuItem5,menuItem6,menuItem7,menuItem8, NULL);
    
    menu->setPosition(CCPointZero);
    layer->addChild(menu);
    
    scrollView = CCScrollView::create(); // 创建一个实例
    scrollView->setContentSize(CCSizeMake(1080, 168)); //设置容器大小（内容尺寸）
    scrollView->setViewSize(CCSizeMake(640, 168)); //设置显示（可视）范围
    scrollView->setContainer(layer);
    scrollView->setDirection( kCCScrollViewDirectionHorizontal );
    scrollView->setTouchPriority(-130);   //提升优先级到比ccMenu高
    this->addChild(scrollView);

    return true;
}

void bottonLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
}

void bottonLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
}

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

void bottonLayer::menu1Callback(cocos2d::CCNode *pSender)
{
    CCLOG("menu1Callback");
}

void bottonLayer::menu2Callback(cocos2d::CCNode *pSender)
{
    SceneManager::sharedSceneManager()->changeScene(SceneManager::en_GameScene);

}

void bottonLayer::menu3Callback(cocos2d::CCNode *pSender)
{
    CCLOG("menu3Callback");
    
}