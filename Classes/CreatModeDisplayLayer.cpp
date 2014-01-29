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
    
    creatModeLabel = CCLabelTTF::create("创造模式","DFGirlKelvin",60);
    creatModeLabel->setPosition(ccp(320,830));
    this->addChild(creatModeLabel,2);

    
    return true;
}

void CreatModeDisplayLayer::setResult(bool state,std::string name, double value)
{
    CCLabelTTF *creatStateLabel;
    if(!state)
    {
        creatStateLabel = CCLabelTTF::create("创造失败T T","DFGirlKelvin",60);
        creatStateLabel->setPosition(ccp(320,500));
        this->addChild(creatStateLabel,2);
    }
    else
    {
        creatStateLabel = CCLabelTTF::create("创造成功^ ^","DFGirlKelvin",60);
        creatStateLabel->setPosition(ccp(320,500));
        this->addChild(creatStateLabel,2);
        
        char buffer[30];
        sprintf(buffer, "恭喜你创造出 %s",name.c_str());
        CCLabelTTF *creatResult = CCLabelTTF::create(buffer,"DFGirlKelvin",40);
        creatStateLabel->setPosition(ccp(320,300));
        this->addChild(creatResult,2);
        
        sprintf(buffer, "hasCreated-%s",name.c_str());
        if(!CCUserDefault::sharedUserDefault()->getBoolForKey(buffer))
        {
            CCUserDefault::sharedUserDefault()->setBoolForKey(buffer,true);
            
            sprintf(buffer, "%s 加入图鉴",name.c_str());
            CCLabelTTF *addLabel = CCLabelTTF::create(buffer,"DFGirlKelvin",40);
            addLabel->setPosition(ccp(320,200));
            this->addChild(addLabel,2);
        }
        
        int num = CCUserDefault::sharedUserDefault()->getIntegerForKey(name.c_str()) + 1;
        CCUserDefault::sharedUserDefault()->setIntegerForKey(name.c_str(), num);
        



    }
    
}