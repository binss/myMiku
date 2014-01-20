//
//  SceneManager.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "SceneManager.h"
#include "MainScene.h"
SceneManager* SceneManager::mSceneManager = NULL;

SceneManager* SceneManager::sharedSceneManager()
{
    if(mSceneManager == NULL)
    {
        mSceneManager = new SceneManager();
        if(mSceneManager && mSceneManager->init())
        {
            mSceneManager->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(mSceneManager);
            mSceneManager = NULL;
        }
    }
    
    return mSceneManager;
}

bool SceneManager::init()
{
    return true;
}

void SceneManager::changeScene( EnumSceneType enScenType )
{
    CCScene* pScene = NULL;
    
    switch (enScenType) {
        case en_MainScene:          //初音主画面
            pScene = MainScene::scene();
            break;
        case  en_GameScene:          //游戏界面
            
            break;
    }
    
    if(pScene == NULL)
    {
        return;
    }
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCScene* curScene = pDirector->getRunningScene();
    if(curScene == NULL)                                    //如果当前没有在运行的场景的话，加载主场景，否则更换场景
    {
        pDirector->runWithScene(pScene);
    }
    else {
        pDirector->replaceScene(pScene);
    }
}
