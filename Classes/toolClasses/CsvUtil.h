//
//  CsvUtil.h
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#ifndef __myMiku__CsvUtil__
#define __myMiku__CsvUtil__

#include "cocos2d.h"

using namespace cocos2d;

class CsvUtil : public CCObject
{
public:
    static CsvUtil* sharedCsvUtil();            //对象
    
    bool init();
    
    void loadFile(const char* sPath);           //加载读取文件
    
    void releaseFile(const char* sPath);        //释放读取文件
    
    const char* get(int iRow, int iCol, const char* csvFilePath);   //读取某行某列的数据
    
	const int getInt(int iRow, int iCol, const char* csvFilePath);  //读取某行某列的数据，并存为int
    
	const float getFloat(int iRow, int iCol, const char* csvFilePath);  //读取某行某列的数据，并存为float
    
    const CCSize getFileRowColNum(const char* csvFilePath);         //获取行数和列数
    
    const int findValueInWithLine(const char* chValue, int iValueCol, const char* csvFilePath);  //根据某个列值查找该值所在的行

private:
    static CsvUtil* bCsvUtil;
    
    CCDictionary* bCsvDict;     //存放文件内容的字典
};


#endif /* defined(__myMiku__CsvUtil__) */
