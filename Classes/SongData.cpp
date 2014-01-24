//
//  SongData.cpp
//  myMiku
//
//  Created by bin on 14-1-24.
//
//

#include "SongData.h"

SongData::SongData(int tname)
{
    switch (tname)
    {
        case deepSeaGirl:
        {
            name = "深海少女";
            previousSong = "null";
            nextSong = "胧月";
            time = "time: 3:35";
            difficulty = "difficulty: easy";
            picPath = "deepSeaGirl.png";
            csvPath = "notation/test.csv";
            songNumber = 0;
            break;
        }
            
        case hazyMoon:
        {
            name = "胧月";
            previousSong = "深海少女";
            nextSong = "千本樱";
            time = "time: 3:35";
            difficulty = "difficulty: easy";
            picPath = "hazyMoon.png";
            csvPath = "notation/test.csv";
            songNumber = 1;
            break;
        }
            
        case senBenZakura:
        {
            name = "千本樱";
            previousSong = "胧月";
            nextSong = "炉心融解";
            time = "time: 3:11";
            difficulty = "difficulty: normal";
            picPath = "senBenZakura.png";
            csvPath = "notation/test.csv";
            songNumber = 2;
            break;
        }
            
        case meltDown:
        {
            name = "炉心融解";
            previousSong = "千本樱";
            nextSong = "null";
            time = "time: 3:35";
            difficulty = "difficulty: hard";
            picPath = "meltDown.png";
            csvPath = "notation/test.csv";
            songNumber = 3;
            break;
        }

        default:
            break;
    }
}