//
//  GameScene.h
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#ifndef __myMiku__GameScene__
#define __myMiku__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameSceneTouchLayer.h"
#include "GameSceneDisplayLayer.h"
USING_NS_CC;

using namespace extension;

class GameScene : public cocos2d::CCScene
{
public:
    
    bool init();
    static GameScene * shareGameScene();
	static GameScene * newGameScene();
    GameSceneTouchLayer * touchLayer;
    GameSceneDisplayLayer * displayLayer;
    
	//MenuLayer* menuLayer;
};



#endif /* defined(__myMiku__GameScene__) */
