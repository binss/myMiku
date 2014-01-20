//
//  StringUtil.h
//  myMiku
//
//  Created by bin on 14-1-20.
//
//
//  用于将Csv文件中用逗号分隔的字符串分离出来，存入数组中

#ifndef __myMiku__StringUtil__
#define __myMiku__StringUtil__

#include "cocos2d.h"

using namespace cocos2d;

class StringUtil : public CCObject
{
public:
    static StringUtil* sharedStrUtil();
    
    bool init();

    CCArray* split(const char* srcStr, const char* sSep);    //存放截取字符串的数组
    
private:
    static StringUtil* bStringUtil;
};

#endif /* defined(__myMiku__StringUtil__) */
