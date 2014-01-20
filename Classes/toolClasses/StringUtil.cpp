//
//  StringUtil.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "StringUtil.h"

StringUtil* StringUtil::bStringUtil = NULL;

StringUtil* StringUtil::sharedStrUtil()
{
    if(bStringUtil == NULL)
    {
        bStringUtil = new StringUtil();
        if(bStringUtil && bStringUtil->init())
        {
            bStringUtil->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(bStringUtil);
            bStringUtil = NULL;
        }
    }
    
    return bStringUtil;
}

bool StringUtil::init()
{
    
    return true;
}

CCArray* StringUtil::split( const char* srcStr, const char* sSep )
{
    CCArray* stringList = CCArray::create();
    
    int size = strlen(srcStr);
    
    CCString* str = CCString::create(srcStr);       //将char*类型转换为CCString类型对象
    
    int startIndex = 0;
    int endIndex = 0;
    endIndex = str->m_sString.find(sSep);           //找到第一个分隔符所在位置下标
    
    CCString* spliStr = NULL;
    
    while(endIndex > 0)                             //根据分隔符分割字符串
    {
        spliStr = CCString::create("");
        
        spliStr->m_sString = str->m_sString.substr(startIndex, endIndex);       //截取
        
        stringList->addObject(spliStr);                                         //加入数组
        
        str->m_sString = str->m_sString.substr(endIndex + 1, size);             //截取接下来的字符串，+1是为了去掉分隔符
        
        endIndex = str->m_sString.find(sSep);                                   //查找下一个分隔符所在位置下标，当找不到时会返回0
    }
    
    if(str->m_sString.compare("") != 0)
    {
        stringList->addObject(CCString::create(str->m_sString));                //把最后一个逗号后面的也加进来
    }
    
    return stringList;
}
