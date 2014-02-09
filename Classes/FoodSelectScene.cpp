//
//  FoodSelectScene.cpp
//  myMiku
//
//  Created by bin on 14-2-8.
//
//

#include "FoodSelectScene.h"

bool FoodSelectScene::init()
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
    
    CCSprite *fishSprite = CCSprite::create("food/fish_item.png");
    CCSprite *dollarSprite = CCSprite::create("food/dollar_item.png");
    CCSprite *orangeSprite = CCSprite::create("food/orange_item.png");
    CCSprite *starSprite = CCSprite::create("food/star_item.png");
    CCSprite *diamondSprite = CCSprite::create("food/diamond_item.png");
    CCSprite *lollipopSprite = CCSprite::create("food/lollipop_item.png");
    
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
    
    
    

    this->addChild(layer);
    
    
    return true;
}


CCScene* FoodSelectScene::shareFoodSelectScene()
{
    CCScene *_sharedFoodSelectScene = CCScene::create();

    FoodSelectScene *layer = FoodSelectScene::create();
    
    if (!layer)
    {
        CC_SAFE_DELETE(layer);
    }
    
    _sharedFoodSelectScene->addChild(layer);
    
    return _sharedFoodSelectScene;
}