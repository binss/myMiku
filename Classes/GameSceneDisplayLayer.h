//
//  GameSceneDisplayLayer.h
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#ifndef __myMiku__GameSceneDisplayLayer__
#define __myMiku__GameSceneDisplayLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace std;
USING_NS_CC;
using namespace extension;

class GameSceneDisplayLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(GameSceneDisplayLayer);
    void turnLeft();
    void turnRight();
    void setCombo(int combo);


private:
    CCArmature *armature;
    CCLabelAtlas* comboCount;
    
};

#endif /* defined(__myMiku__GameSceneDisplayLayer__) */
