//
//  AudioPlayer.cpp
//  myMiku
//
//  Created by bin on 14-1-22.
//
//

#include "AudioPlayer.h"

const static char* musicList[4] = { "music/deepSeaGirl.mp3","music/hazyMoon.mp3","music/senBenZakura.mp3","music/meltDown.mp3"};
const static char* auditionList[4] = { "audition/A_deepSeaGirl.mp3","audition/A_hazyMoon.mp3","audition/A_senBenZakura.mp3","audition/A_meltDown.mp3"};

static AudioPlayer* instance = NULL;
AudioPlayer* AudioPlayer::sharedAudio()
{
    if(instance == NULL)
    {
        instance = AudioPlayer::create();
    }
    return instance;
}


bool AudioPlayer::init()
{
    CCLog("AudioPlayer init.");
    for(int i=0;i<4;i++)
        SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(auditionList[i]);          //预加载
    
    SimpleAudioEngine::sharedEngine()->preloadEffect("effects/leftCycleEffect.caf");
    SimpleAudioEngine::sharedEngine()->preloadEffect("effects/rightCycleEffect.caf");
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5f);
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0f);
    

    
    PlayingEffect = true;
    PlayingMusic = true;
    
    return true;
}

void AudioPlayer::pause()
{
    
}

void AudioPlayer::resume()
{
    
}

void AudioPlayer::playEffect(int index)
{

    if(index == leftClick)
    {
        SimpleAudioEngine::sharedEngine()->playEffect("effects/leftCycleEffect.caf");
        CCLOG("left effect!");
    }
    else if(index == rightClick)
    {
        SimpleAudioEngine::sharedEngine()->playEffect("effects/rightCycleEffect.caf");
        CCLOG("right effect!");
    }
    
}

void AudioPlayer::preLoadMusic(int music)
{
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(musicList[music]);          //预加载
}

void AudioPlayer::playMusic(int music)
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(musicList[music]);
}

void AudioPlayer::playAudition(int music)
{
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(auditionList[music], true);
}

void AudioPlayer::pauseMusic()
{
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AudioPlayer::resumeMusic()
{
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AudioPlayer::stopAllMusic()
{
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void AudioPlayer::setEffectPlay(bool play)
{
    PlayingEffect = play;
}

void AudioPlayer::setBackgroundMusicPlay(bool play)
{
    PlayingMusic = play;
}

void AudioPlayer::setVolume(float volume)
{
    //SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(volume);
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(volume);
}