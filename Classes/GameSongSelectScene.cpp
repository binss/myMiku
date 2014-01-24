//
//  GameSongSelectScene.cpp
//  myMiku
//
//  Created by bin on 14-1-23.
//
//

#include "GameSongSelectScene.h"
#include "SceneManager.h"
#include "AudioPlayer.h"

CCLayerColor * colorLayer = NULL;
CCSprite * play = NULL;

CCScene* GameSongSelectScene::scene()
{
    CCScene * scene = NULL;
    do
    {
        scene = CCScene::create();
        CC_BREAK_IF(! scene);
        
        GameSongSelectScene *layer = GameSongSelectScene::create();
        CC_BREAK_IF(! layer);
        
        colorLayer = CCLayerColor::create(ccc4(255, 255, 255, 130), 640, 960);
        play = CCSprite::create("game/selectSong/play.png");
        play->setPosition(ccp(320,500));
        colorLayer->addChild(play,2);
        colorLayer->setVisible(false);
        
        scene->addChild(layer);
        scene->addChild(colorLayer,10);
    } while (0);
    
    // return the scene
    return scene;
}

bool GameSongSelectScene::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CCLayer::init());
        this->setTouchEnabled(true);
        this->setTouchMode(kCCTouchesOneByOne);
        
        AudioPlayer::sharedAudio();
        
        visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        songNum = 0;
        detail = new SongData(songNum);

        backgroundCache = CCSpriteFrameCache::sharedSpriteFrameCache();
        backgroundCache->addSpriteFramesWithFile("songList/select.plist","songList/select.png" );
        songBackground = CCSprite::createWithSpriteFrameName("deepSeaGirl.png");
        
        //CCSprite * songBackground = CCSprite::create("game/selectSong/deepSeaGirl.png");
        songBackground->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
        this->addChild(songBackground,0);
        
        nameFrame = CCSprite::create("songList/nameFrame.png");
        nameFrame->setOpacity(180);
        nameFrame->setPosition(ccp(320,500));
        this->addChild(nameFrame,1);
        
        leftArrow = CCSprite::create("game/selectSong/left.png");
        leftArrow->setPosition(ccp(50,480));
        leftArrow->setVisible(false);            //初始时前一首歌为无
        this->addChild(leftArrow,1);
        
        leftWord = CCLabelTTF::create("","DFGirlKelvin",30);
        leftWord->setPosition(ccp(70,530));
        leftArrow->setVisible(false);            //初始时前一首歌为无
        this->addChild(leftWord,2);
        
        rightArrow = CCSprite::create("game/selectSong/right.png");
        rightArrow->setPosition(ccp(590,480));
        this->addChild(rightArrow,1);
        
        rightWord = CCLabelTTF::create(detail->nextSong,"DFGirlKelvin",30);
        rightWord->setPosition(ccp(570,530));
        this->addChild(rightWord,2);
        
        
        name = CCLabelTTF::create(detail->name,"DFGirlKelvin",80);
        name->setPosition(ccp(320,590));
        this->addChild(name,2);
        
        time = CCLabelTTF::create(detail->time,"DFGirlKelvin",40);
        time->setPosition(ccp(320,510));
        this->addChild(time,2);
        
        difficulty = CCLabelTTF::create(detail->difficulty,"DFGirlKelvin",40);
        difficulty->setPosition(ccp(320,450));
        this->addChild(difficulty,2);
        
        CCLabelTTF *highScore = CCLabelTTF::create("record: 99999","DFGirlKelvin",40);
        highScore->setPosition(ccp(320,390));
        this->addChild(highScore,2);
        
        AudioPlayer::sharedAudio()->playAudition(detail->songNumber);
        selectState = true;
        
        bRet = true;
    } while (0);
    
    return bRet;
}

bool GameSongSelectScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    touchBeginPos = pTouch->getLocation();
    
    return true;
}

void GameSongSelectScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}

void GameSongSelectScene::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    

    CCPoint touchEndPos  = pTouch->getLocation();
    if(selectState)                                 //判定为点击
    {
        float moveX = touchEndPos.x - touchBeginPos.x;
        if(moveX > 10)                                  //判定为向左滑
        {
            AudioPlayer::sharedAudio()->playEffect(rightClick);              //击打音效
            if(songNum <= 0)
                return;
            songNum --;
            setSongData(songNum);
            return;
        }
        
        if(moveX < -10)                                 //判定为向右滑
        {
            AudioPlayer::sharedAudio()->playEffect(rightClick);              //击打音效
            if(songNum >= 3)
                return;
            songNum ++;
            setSongData(songNum);
            return;
        }
        AudioPlayer::sharedAudio()->playEffect(leftClick);              //击打音效
        colorLayer->setVisible(true);
        nameFrame->setVisible(false);
        selectState = false;
    }
    else
    {
        CCSize playSize = play->getContentSize();
        if( touchBeginPos.x > (visibleSize.width / 2 - playSize.width / 2 ) && touchBeginPos.x < (visibleSize.width / 2 + playSize.width /2 )
           && touchBeginPos.y > (visibleSize.height / 2 - playSize.height / 2 ) && touchBeginPos.y < (visibleSize.height / 2 + playSize.height / 2 ) )
        {
            CCLog("play , go to the gameScene");
            AudioPlayer::sharedAudio()->stopAllMusic();
            AudioPlayer::sharedAudio()->playEffect(leftClick);              //击打音效
            SceneManager::sharedSceneManager()->changeScene(SceneManager::en_GameScene);
            sendSongMessage();
            backgroundCache->removeUnusedSpriteFrames();
        }
        else
        {
            AudioPlayer::sharedAudio()->playEffect(rightClick);              //击打音效
            colorLayer->setVisible(false);
            nameFrame->setVisible(true);

            selectState = true;
        }
    }


}

void GameSongSelectScene::setSongData(int num)
{
    detail = new SongData(songNum);
    if(!strncmp(detail->previousSong,"null",4))
    {
        leftArrow->setVisible(false);
        leftWord->setVisible(false);
    }
    else
    {
        leftArrow->setVisible(true);
        leftWord->setVisible(true);
        leftWord->setString(detail->previousSong);
    }
    if(!strncmp(detail->nextSong,"null",4))
    {
        rightArrow->setVisible(false);
        rightWord->setVisible(false);
    }
    else
    {
        rightArrow->setVisible(true);
        rightWord->setVisible(true);
        rightWord->setString(detail->nextSong);
    }
    
    CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(detail->picPath);
    songBackground->setDisplayFrame(frame);
    
    name->setString(detail->name);
    time->setString(detail->time);
    difficulty->setString(detail->difficulty);
    
    AudioPlayer::sharedAudio()->playAudition(detail->songNumber);
}

void GameSongSelectScene::sendSongMessage()
{
    CCArray *data = CCArray::create();
    data->retain();
    CCString *data1 = CCString::createWithFormat("%i",detail->songNumber);
    CCString *data2 = CCString::createWithFormat("%s",detail->csvPath);
    data->addObject(data1);
    data->addObject(data2);
    //CCString *data = CCString::createWithFormat("%i,%s",detail->songNumber,detail->csvPath);
    CCNotificationCenter::sharedNotificationCenter()->postNotification("SongNum", data);
}
