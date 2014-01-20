//
//  FileLoadUtil.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "FileLoadUtil.h"
#include "StringUtil.h"

FileLoadUtil* FileLoadUtil::bFileLoadUtil = NULL;

FileLoadUtil* FileLoadUtil::sharedFileLoadUtil()
{
    if(bFileLoadUtil == NULL)
    {
        bFileLoadUtil = new FileLoadUtil();
        if(bFileLoadUtil && bFileLoadUtil->init())
        {
            bFileLoadUtil->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(bFileLoadUtil);
            bFileLoadUtil = NULL;
        }
    }
    
    return bFileLoadUtil;
}

bool FileLoadUtil::init()
{
    return true;
}

CCArray* FileLoadUtil::getDataLines( const char* sFilePath )
{
    CCArray* linesList = CCArray::create();
    
    unsigned long pSize = 0;
    unsigned char* chDatas = CCFileUtils::sharedFileUtils()->getFileData(sFilePath, "r", &pSize);   //读取文本数据
    
    CCString* str = CCString::createWithData(chDatas, pSize);                                       //转换成CCString类型

    linesList = StringUtil::sharedStrUtil()->split(str->getCString(), "\n");                        //调用StringUtil类的分割函数
                                                                                                //以“/n”即换行为分隔符，得到一行的内容    
    return linesList;
}
