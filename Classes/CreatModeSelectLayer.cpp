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
    CCLayer *layer = CCLayer::create();
    layer->setContentSize(CCSizeMake(640,1200));
    
    CCSprite *fishSprite = CCSprite::create("creatMode/items/fish.png");
    CCSprite *dollarSprite = CCSprite::create("creatMode/items/dollar.png");
    CCSprite *orangeSprite = CCSprite::create("creatMode/items/orange.png");
    CCSprite *starSprite = CCSprite::create("creatMode/items/star.png");
    CCSprite *diamondSprite = CCSprite::create("creatMode/items/diamond.png");
    CCSprite *lollipopSprite = CCSprite::create("creatMode/items/lollipop.png");

    // Menu
    
    fishSprite->setPosition(ccp(320,1100));
    dollarSprite->setPosition(ccp(320,900));
    orangeSprite->setPosition(ccp(320,700));
    starSprite->setPosition(ccp(320,500));
    diamondSprite->setPosition(ccp(320,300));
    lollipopSprite->setPosition(ccp(320,100));

    layer->addChild(fishSprite);
    layer->addChild(dollarSprite);
    layer->addChild(orangeSprite);
    layer->addChild(starSprite);
    layer->addChild(diamondSprite);
    layer->addChild(lollipopSprite);

    

    scrollView = CCScrollView::create();                            // 创建一个实例
    scrollView->setContentSize(CCSizeMake(640, 1200));              //设置容器大小（内容尺寸）
    scrollView->setViewSize(CCSizeMake(640, 710));                  //设置显示（可视）范围
    
    scrollView->setPosition(ccp(0,80));
    scrollView->setContainer(layer);
    scrollView->setDirection(kCCScrollViewDirectionVertical);
    //scrollView->setBounceable(false);                             //关闭弹性效果
    scrollView->setTouchPriority(-130);                             //提升优先级到比ccMenu高
    this->addChild(scrollView);
    
    scrollView->setContentOffset(ccp(0,-500));

    
    return true;
}

void CreatModeSelectLayer::menu1Callback(cocos2d::CCNode *pSender)
{
    CCLOG("menu1Callback");
}

void CreatModeSelectLayer::menu2Callback(cocos2d::CCNode *pSender)
{
   
    
    
}

void CreatModeSelectLayer::menu3Callback(cocos2d::CCNode *pSender)
{
    CCLOG("menu3Callback");
    
}

void CreatModeSelectLayer::menu4Callback(cocos2d::CCNode *pSender)
{
    
}


void CreatModeSelectLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
}

void CreatModeSelectLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
    
}