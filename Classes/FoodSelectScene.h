//
//  FoodSelectScene.h
//  myMiku
//
//  Created by bin on 14-2-8.
//
//

#ifndef __myMiku__FoodSelectScene__
#define __myMiku__FoodSelectScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;



class FoodSelectScene : public cocos2d::CCLayer
{
public:
    
    bool init();
    static CCScene * shareFoodSelectScene();

    CREATE_FUNC(FoodSelectScene);
    CCScrollView *scrollView;
};

#endif /* defined(__myMiku__FoodSelectScene__) */
