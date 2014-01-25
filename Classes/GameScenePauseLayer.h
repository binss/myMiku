//
//  GameScenePauseLayer.h
//  myMiku
//
//  Created by bin on 14-1-25.
//
//

#ifndef __myMiku__GameScenePauseLayer__
#define __myMiku__GameScenePauseLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;

class GameScenePauseLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(GameScenePauseLayer);
    
    
    
private:
    void menu1Callback(CCNode *pSender);
    void menu2Callback(CCNode *pSender);
    void menu3Callback(CCNode *pSender);
    void menu4Callback(CCNode *pSender);

};

#endif /* defined(__myMiku__GameScenePauseLayer__) */
