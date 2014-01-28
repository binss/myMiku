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
    gestureLayer->setValidZone(800, 100, 100, 540);
    this->addChild(gestureLayer,5);

    
    displayLayer = new CreatModeDisplayLayer();  
	
	if(displayLayer && displayLayer->init())
    {
		
		displayLayer->autorelease();
	}else{
		
		CC_SAFE_DELETE(displayLayer);
	}
	
    this->addChild(displayLayer, 0);
    
    menuLayer = new CreatModeMenuLayer();
	
	if(menuLayer && menuLayer->init())
    {
		
		menuLayer->autorelease();
	}else{
		
		CC_SAFE_DELETE(menuLayer);
	}
	
    this->addChild(menuLayer, 10);

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