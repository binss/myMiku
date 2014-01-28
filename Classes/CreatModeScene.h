//
//  CreatModeScene.h
//  myMiku
//
//  Created by bin on 14-1-27.
//
//

#ifndef __myMiku__CreatModeScene__
#define __myMiku__CreatModeScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CreatModeGestureLayer.h"
#include "CreatModeDisplayLayer.h"
#include "CreatModeMenuLayer.h"
USING_NS_CC;

using namespace extension;

class CreatModeScene : public cocos2d::CCScene
{
public:
    
    bool init();
    GestureManager * gestureLayer;
    CreatModeDisplayLayer * displayLayer;
    CreatModeMenuLayer *menuLayer;
    static CreatModeScene * shareCreatModeScene();
    
};

#endif /* defined(__myMiku__CreatModeScene__) */
