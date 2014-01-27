//
//  CreatModeDisplayLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-27.
//
//

#include "CreatModeDisplayLayer.h"

bool CreatModeDisplayLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite *background = CCSprite::create("creatMode/background.png");
    background->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(background,0);
    
       
    
    return true;
}
