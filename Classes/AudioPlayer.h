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

class AudioPlayer : public CCObject
{
    enum effects{
        leftClick = 0,
        rightClick
    };
    
    
    enum music
    {
        deepSeaGirl = 0,            //深海少女，3 min 35s = 215s
    };
    
private:
    bool PlayingEffect;
    bool PlayingMusic;
    
    void pause();
    void resume();  //will used?
    CREATE_FUNC(AudioPlayer);
public:
    bool init();
    
    static AudioPlayer* sharedAudio();
    void playEffect(int index);
    void playMusic(int music);
    void preLoadMusic(int music);
    void setEffectPlay(bool play);
    void setBackgroundMusicPlay(bool play);
    void setVolume(float volume);
  
};


#endif /* defined(__myMiku__AudioPlayer__) */
