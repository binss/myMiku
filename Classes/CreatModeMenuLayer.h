//
//  CreatModeMenuLayer.h
//  myMiku
//
//  Created by bin on 14-1-28.
//
//

#ifndef __myMiku__CreatModeMenuLayer__
#define __myMiku__CreatModeMenuLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CreatModeSelectLayer.h"

USING_NS_CC;
using namespace extension;

class CreatModeMenuLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    void setCreatItemData(std::string name,double value);

    CREATE_FUNC(CreatModeMenuLayer);
    
    
    
private:
    void clearMenuCallback(CCNode *pSender);
    void creatMenuCallback(CCNode *pSender);
    void penMenuCallback(CCNode *pSender);
    
    CCMenuItemLabel *clearItem;
    
    CCMenuItemLabel *creatItem;
    bool selectState;
    CreatModeSelectLayer* selectLayer;

    
};
#endif /* defined(__myMiku__CreatModeMenuLayer__) */
