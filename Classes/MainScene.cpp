//
//  MainScene.cpp
//  myMiku
//
//  Created by bin on 14-1-15.
//
//

#include "MainScene.h"

cocos2d::CCScene* MainScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    
    HelloWorld *mikuLayer = HelloWorld::create();
    bottonLayer *botton = bottonLayer::create();
    
    // add layer as a child to scene
    scene->addChild(mikuLayer);
    scene->addChild(botton);
    // return the scene
    return scene;
}

