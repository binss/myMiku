//
//  SceneManager.h
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#ifndef __myMiku__SceneManager__
#define __myMiku__SceneManager__


#include "cocos2d.h"

using namespace cocos2d;

class SceneManager : public CCObject {
public:
    //以下是场景枚举
    enum EnumSceneType {
        en_MainScene,  //初音主画面
        en_GameSongSelectScene, //游戏歌曲选择画面
        en_GameScene   //游戏界面
		
    };
    
    static SceneManager* sharedSceneManager();   //获取共享的场景管理器对象，用于子类调用

    virtual bool init();

    void changeScene(EnumSceneType enScenType);   //改变场景
    
private:
    static SceneManager* mSceneManager;      //场景管理器对象
};

#endif /* defined(__myMiku__SceneManager__) */

