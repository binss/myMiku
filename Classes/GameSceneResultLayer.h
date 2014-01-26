//
//  GameSceneResultLayer.h
//  myMiku
//
//  Created by bin on 14-1-25.
//
//

#ifndef __myMiku__GameSceneResultLayer__
#define __myMiku__GameSceneResultLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CounterDown.h"

USING_NS_CC;
using namespace extension;

class GameSceneResultLayer : public cocos2d::CCLayer
{
    enum song
    {
        deepSeaGirl = 0,
        hazyMoon,
        senBenZakura,
        meltDown
    };
    
public:
    virtual bool init();
    CREATE_FUNC(GameSceneResultLayer);
    void setResult(int songNum,int cool,int fine,int safe,int sad,int maxCombo);
    
    
private:
    void menuCallback(CCNode *pSender);
    CCLabelTTF *coolLabel;
    CCLabelTTF *fineLabel;
    CCLabelTTF *safeLabel;
    CCLabelTTF *sadLabel;
    CCLabelTTF *comboLabel;

    void setScore(CCObject* psender);
    void creatCloseButton();
    int score;
    char buffer [10];
    void displayScore(float dt);
    void showResult(int coolScore,int fineScore,int safeScore,int sadScore,int comboScore);
    void writeSaveFile(int songNum,int score);
    CounterDown *counter;
};

#endif /* defined(__myMiku__GameSceneResultLayer__) */
