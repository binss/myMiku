//
//  CreatModeDisplayLayer.h
//  myMiku
//
//  Created by bin on 14-1-27.
//
//

#ifndef __myMiku__CreatModeDisplayLayer__
#define __myMiku__CreatModeDisplayLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;

class CreatModeDisplayLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(CreatModeDisplayLayer);
    CCLabelTTF *creatModeLabel;

    void setResult(bool state,std::string name,double value);

    
    
private:
    
    
    
};

#endif /* defined(__myMiku__CreatModeDisplayLayer__) */
