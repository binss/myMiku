//
//  CreatModeScene.cpp
//  myMiku
//
//  Created by bin on 14-1-27.
//
//

#include "CreatModeScene.h"
#include "SceneManager.h"

bool CreatModeScene::init()
{
    
    gestureLayer = GestureManager::create();
    
    this->addChild(gestureLayer,10);

    
    displayLayer = new CreatModeDisplayLayer();   //º”‘ÿ»ÀŒÔ
	
	if(displayLayer && displayLayer->init())
    {
		
		displayLayer->autorelease();
	}else{
		
		CC_SAFE_DELETE(displayLayer);
	}
	
    this->addChild(displayLayer, 0);

    return true;
}

static CreatModeScene *_sharedCreatModeScene = NULL;
CreatModeScene* CreatModeScene::shareCreatModeScene()
{
    if (!_sharedCreatModeScene)
    {
        _sharedCreatModeScene = new CreatModeScene();
        if (!_sharedCreatModeScene->init())
        {
            CC_SAFE_DELETE(_sharedCreatModeScene);
        }
    }
    return _sharedCreatModeScene;
}