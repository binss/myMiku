//
//  SceneManager.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "SceneManager.h"
#include "MainScene.h"
#include "GameScene.h"
#include "GameSongSelectScene.h"
#include "CreatModeScene.h"

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
    
    switch (enScenType)
    {
        case en_MainScene:          //初音主画面
        {
            if(pScene == NULL)
                pScene = MainScene::scene();
            else
                CCDirector::sharedDirector()->replaceScene(CCTransitionProgressHorizontal::create(1.0f, MainScene::scene()));
            break;
        }
        case en_GameSongSelectScene:
            CCDirector::sharedDirector()->replaceScene(CCTransitionProgressHorizontal::create(1.0f, GameSongSelectScene::scene()));
            break;
        case  en_GameScene:          //游戏界面
        {
            CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(1.0f, GameScene::newGameScene()));
            break;
        }
        case en_creatModeScene:
        {
            CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(1.0f, CreatModeScene::shareCreatModeScene()));
            break;
        }
            
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

void SceneManager::checkSaveXML()
{
    
    if(!CCUserDefault::sharedUserDefault()->getBoolForKey("isHaveSaveFileXml"))                 //用于判断存档是否存在
    {
        CCUserDefault::sharedUserDefault()->setBoolForKey("isHaveSaveFileXml", true);
        
        CCUserDefault::sharedUserDefault()->setIntegerForKey("highScore-deepSeaGirl", 0);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("highScore-hazyMoon", 0);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("highScore-senBenZakura", 0);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("highScore-meltDown", 0);
        
        CCUserDefault::sharedUserDefault()->flush();                                        //提交
        CCLOG("First run,creat the saveFile");
    }
    else
    {
        CCLOG("The saveFile is exist on : %s",CCUserDefault::sharedUserDefault()->getXMLFilePath().c_str());

    }

}
