//
//  SongData.h
//  myMiku
//
//  Created by bin on 14-1-24.
//
//

#ifndef __myMiku__SongData__
#define __myMiku__SongData__

#include "cocos2d.h"

using namespace cocos2d;

class SongData
{
    enum song
    {
        deepSeaGirl = 0,
        hazyMoon,
        senBenZakura,
        meltDown
    };
    
public:
    SongData(int tname);
    const char * name;
    const char * previousSong;
    const char * nextSong;
    const char * time;
    const char * difficulty;
    const char * picPath;
    const char * csvPath;
    float runningTime;
    int songNumber;
    int highScore;

};
#endif /* defined(__myMiku__SongData__) */
