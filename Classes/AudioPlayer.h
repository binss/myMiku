//
//  AudioPlayer.h
//  myMiku
//
//  Created by bin on 14-1-22.
//
//

#ifndef __myMiku__AudioPlayer__
#define __myMiku__AudioPlayer__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace CocosDenshion;

enum effects
{
    leftClick = 0,
    rightClick
};

enum musicList
{
    deepSeaGirl = 0,
    hazyMoon,
    senBenZakura,
    meltDown
};


class AudioPlayer : public CCObject
{
//    enum music
//    {
//        deepSeaGirl = 0,            //深海少女，3 min 35s = 215s
//    };
    
private:
    bool PlayingEffect;
    bool PlayingMusic;
    
    CREATE_FUNC(AudioPlayer);
public:
    bool init();
    
    static AudioPlayer* sharedAudio();
    void playEffect(int index);
    void playMusic(int music);
    void playAudition(int music);
    void stopAllMusic();
    void pauseMusic();
    void resumeMusic();
    void preLoadMusic(int music);
//    void setEffectPlay(bool play);
//    void setBackgroundMusicPlay(bool play);
    void setVolume(float volume);
    bool isBackgroundMusicPlaying();
  
};


#endif /* defined(__myMiku__AudioPlayer__) */
