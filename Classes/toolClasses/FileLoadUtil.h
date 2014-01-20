//
//  FileLoadUtil.h
//  myMiku
//
//  Created by bin on 14-1-20.
//
//  用于把Csv文件按行读取，并储存在数组中

#ifndef __myMiku__FileLoadUtil__
#define __myMiku__FileLoadUtil__

#include "cocos2d.h"

using namespace cocos2d;

class FileLoadUtil : public CCObject
{
public:
    static FileLoadUtil* sharedFileLoadUtil();
    
    bool init();
    
    CCArray* getDataLines(const char* sFilePath);         //数组，存储每一行的字符串
    
private:
    static FileLoadUtil* bFileLoadUtil;
};

#endif /* defined(__myMiku__FileLoadUtil__) */
