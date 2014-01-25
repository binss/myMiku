//
//  GameScenePauseLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-25.
//
//

#include "GameScenePauseLayer.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "AudioPlayer.h"

bool GameScenePauseLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    GameScene::shareGameScene()->touchLayer->setTouchEnabled(false);
    GameScene::shareGameScene()->touchLayer->menu->setTouchEnabled(false);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite *background = CCSprite::create("game/pause.png");
    background->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(background,0);

    CCSprite *sprite1 = CCSprite::create("game/pause_button_1.png");
    CCSprite *sprite2 = CCSprite::create("game/pause_button_2.png");
    CCSprite *sprite3 = CCSprite::create("game/pause_button_3.png");
    CCSprite *sprite4 = CCSprite::create("game/pause_button_4.png");

    
    // Menu
    CCMenuItemSprite *menuItem1 = CCMenuItemSprite::create(sprite1, sprite1, this, menu_selector(GameScenePauseLayer::menu1Callback));
    menuItem1->setPosition(ccp(320,595));
    CCMenuItemSprite *menuItem2 = CCMenuItemSprite::create(sprite2, sprite2, this, menu_selector(GameScenePauseLayer::menu2Callback));
    menuItem2->setPosition(ccp(320,495));
    CCMenuItemSprite *menuItem3 = CCMenuItemSprite::create(sprite3, sprite3, this, menu_selector(GameScenePauseLayer::menu3Callback));
    menuItem3->setPosition(ccp(320,395));
    CCMenuItemSprite *menuItem4 = CCMenuItemSprite::create(sprite4, sprite4, this, menu_selector(GameScenePauseLayer::menu4Callback));
    menuItem4->setPosition(ccp(320,295));
    
    CCMenu *menu = CCMenu::create(menuItem1, menuItem2,menuItem3,menuItem4, NULL);
    
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    
    return true;
}

void GameScenePauseLayer::menu1Callback(cocos2d::CCNode *pSender)
{
    GameScene::shareGameScene()->touchLayer->setTouchEnabled(true);
    GameScene::shareGameScene()->touchLayer->menu->setTouchEnabled(true);
    CCDirector::sharedDirector()->resume();
    AudioPlayer::sharedAudio()->resumeMusic();
    this->removeFromParentAndCleanup(true);
}

void GameScenePauseLayer::menu2Callback(cocos2d::CCNode *pSender)
{
    GameScene::shareGameScene()->touchLayer->setTouchEnabled(true);
    GameScene::shareGameScene()->touchLayer->menu->setTouchEnabled(true);
    GameScene::shareGameScene()->touchLayer->ready();
    CCDirector::sharedDirector()->resume();
    this->removeAllChildren();
    this->removeFromParentAndCleanup(true);
}

void GameScenePauseLayer::menu3Callback(cocos2d::CCNode *pSender)
{
    SceneManager::sharedSceneManager()->changeScene(SceneManager::en_GameSongSelectScene);
    CCDirector::sharedDirector()->resume();

    this->removeAllChildren();
    this->removeFromParentAndCleanup(true);
}

void GameScenePauseLayer::menu4Callback(cocos2d::CCNode *pSender)
{
    SceneManager::sharedSceneManager()->changeScene(SceneManager::en_MainScene);
    CCDirector::sharedDirector()->resume();

    this->removeAllChildren();
    this->removeFromParentAndCleanup(true);
}
