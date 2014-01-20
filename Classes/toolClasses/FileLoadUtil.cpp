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

    linesList = StringUtil::sharedStrUtil()->split(str->getCString(), "\r");                        //调用StringUtil类的分割函数
    /*
        注:以“\r”即换行为分隔符，得到一行的内容
            mac/linux系统下\r为换行符，而在windows下\n为换行符，切记切记
    */
    return linesList;
}
