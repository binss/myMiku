//
//  GameSongSelectScene.h
//  myMiku
//
//  Created by bin on 14-1-23.
//
//

#ifndef __myMiku__GameSongSelectScene__
#define __myMiku__GameSongSelectScene__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;

using namespace extension;



class GameSongSelectScene : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameSongSelectScene);

};
#endif /* defined(__myMiku__GameSongSelectScene__) */
