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
#include "SongData.h"

USING_NS_CC;

using namespace extension;


class GameSongSelectScene : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void sendSongMessage();
    CCPoint touchBeginPos;

    SongData * detail;
    
    CREATE_FUNC(GameSongSelectScene);
    void setSongData(int num);
    
    bool selectState;
    CCSize visibleSize;
    
    CCSpriteFrameCache *backgroundCache;
    CCSprite * leftArrow;
    CCSprite * rightArrow;
    CCSprite * songBackground;
    CCSprite * nameFrame;
    
    int songNum;
    CCLabelTTF *leftWord;
    CCLabelTTF *rightWord;
    CCLabelTTF *name;
    CCLabelTTF *time;
    CCLabelTTF *difficulty;
    
    
};
#endif /* defined(__myMiku__GameSongSelectScene__) */
