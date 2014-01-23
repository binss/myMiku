//
//  GameSongSelectScene.cpp
//  myMiku
//
//  Created by bin on 14-1-23.
//
//

#include "GameSongSelectScene.h"

CCScene* GameSongSelectScene::scene()
{
    CCScene * scene = NULL;
    do
    {
        scene = CCScene::create();
        CC_BREAK_IF(! scene);
        
        GameSongSelectScene *layer = GameSongSelectScene::create();
        CC_BREAK_IF(! layer);
        
        scene->addChild(layer);
    } while (0);
    
    // return the scene
    return scene;
}

bool GameSongSelectScene::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CCLayer::init());
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCSprite * songBackground = CCSprite::create("game/selectSong/deepSeaGirl.png");
        songBackground->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
        this->addChild(songBackground,0);
        
        CCSprite * leftArrow = CCSprite::create("game/selectSong/left.png");
        leftArrow->setPosition(ccp(50,500));
        this->addChild(leftArrow,1);
        
        CCSprite * rightArrow = CCSprite::create("game/selectSong/right.png");
        rightArrow->setPosition(ccp(590,500));
        this->addChild(rightArrow,1);
        
        CCSprite * play = CCSprite::create("game/selectSong/play.png");
        play->setPosition(ccp(visibleSize.width/2,500));
        this->addChild(play,2);
        
		
        bRet = true;
    } while (0);
    
    return bRet;
}
