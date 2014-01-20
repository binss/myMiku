//
//  GameScene.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "GameScene.h"
#include "SceneManager.h"

bool GameScene::init()
{
	touchLayer = new GameSceneTouchLayer();
    
	if(touchLayer && touchLayer->init())
	{
		touchLayer->autorelease();
	}else
    {
		CC_SAFE_DELETE(touchLayer);
	}
	
	this->addChild(touchLayer, 2);
    
    /*
    playLayer = new GameScenePlayLayer();   //º”‘ÿ»ÀŒÔ
	
	if(playLayer && playLayer->init()){
		
		playLayer->autorelease();
	}else{
		
		CC_SAFE_DELETE(playLayer);
	}
	
    this->addChild(playLayer, 0);
	*/
    return true;
}

static GameScene *_sharedGameScene = NULL;
GameScene* GameScene::shareGameScene()
{
    if (!_sharedGameScene)
    {
        _sharedGameScene = new GameScene();
        if (!_sharedGameScene->init())
        {
            CC_SAFE_DELETE(_sharedGameScene);
        }
    }
    return _sharedGameScene;
}

GameScene* GameScene::newGameScene()
{
    _sharedGameScene = new GameScene();
    if (!_sharedGameScene->init())
    {
		CC_SAFE_DELETE(_sharedGameScene);
    }
    
    return _sharedGameScene;
}
