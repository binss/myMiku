//
//  CsvUtil.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "CsvUtil.h"
#include "FileLoadUtil.h"
#include "StringUtil.h"

CsvUtil* CsvUtil::bCsvUtil = NULL;

CsvUtil* CsvUtil::sharedCsvUtil()
{
    if(bCsvUtil == NULL)
    {
        bCsvUtil = new CsvUtil();
        bCsvUtil->init();
        /*
        bCsvUtil = new CsvUtil();
        if(bCsvUtil && bCsvUtil->init())
        {
            bCsvUtil->autorelease();                    //罪魁祸首！！！如果自动释放，那么CCDictionary各种报错！！！
        }
        else
        {
            CC_SAFE_DELETE(bCsvUtil);
            bCsvUtil = NULL;
        }
         */
    }
    return bCsvUtil;
}

bool CsvUtil::init()
{
    bCsvDict = CCDictionary::create();          //初始化变量
    bCsvDict->retain();
    
    return true;
}

void CsvUtil::loadFile( const char* sPath )
{
    CCArray* csvStrList = CCArray::create();          //创建存放字符串的数组
    
    CCArray* linesList = FileLoadUtil::sharedFileLoadUtil()->getDataLines(sPath);   //读取每一行数据，放到存放行数据的数组里
    
    CCObject* obj;
    CCString* tString = NULL;
    CCARRAY_FOREACH(linesList, obj)
    {
        tString = (CCString *) obj;         //取出一行字符串，如果存在，那么就拆分它
        
        if(tString)
        {
            CCArray* tArr = StringUtil::sharedStrUtil()->split(tString->getCString(), ";");     //以顿号为拆分识别符
            csvStrList->addObject(tArr);                    //加入csvStrList数组中
        }
    }
    bCsvDict->setObject(csvStrList, sPath);
}

void CsvUtil::releaseFile( const char* sPath ){
	bCsvDict->removeObjectForKey(sPath);
}

const char* CsvUtil::get( int iRow, int iCol, const char* csvFilePath )
{
    CCObject* csvObj = bCsvDict->objectForKey(csvFilePath);     //取出配置文件的二维表格
    
    if(csvObj == NULL)
    {
        loadFile(csvFilePath);
    }
    CCArray* csvStrList = (CCArray *) bCsvDict->objectForKey(csvFilePath);
    
    CCSize size = getFileRowColNum(csvFilePath);
    
    int iRowNum = size.width;       //获取行数和列数
    int iColNum = size.height;
    
    if(iRow >= iRowNum || iCol >= iColNum)  //越界检查
    {
        return "out of bound";
    }
    
    CCObject* rowObj = csvStrList->objectAtIndex(iRow);     //获取iRow行数据
    
    if(rowObj != NULL)
    {
        CCArray* rowArr = (CCArray *) rowObj;
        CCObject* colObj = rowArr->objectAtIndex(iCol);     //获取iCol列数据
        
        if(colObj != NULL)
        {
            CCString* colStr = (CCString *) colObj;
            return colStr->getCString();
        }
    }
    
    return "";
}

const CCSize CsvUtil::getFileRowColNum( const char* csvFilePath )
{
    
    CCObject* csvObj = bCsvDict->objectForKey(csvFilePath);         //取出配置文件的二维表格
    
    if(csvObj == NULL)
    {
        loadFile(csvFilePath);
    }
    
    CCArray* csvStrList = (CCArray *) bCsvDict->objectForKey(csvFilePath);
    
    int iRowNum = csvStrList->count();                      //获取行数
    int iColNum = 0;
    if(iRowNum > 0)
    {
        CCObject* rowObj = csvStrList->objectAtIndex(0);    //获取第0行数据
        
        if(rowObj != NULL)
        {
            CCArray* rowArr = (CCArray *) rowObj;
            iColNum = rowArr->count();                      //获取列数
        }
    }
    CCSize size = CCSize(iRowNum, iColNum);
    return size;
}

const int CsvUtil::getInt( int iRow, int iCol, const char* csvFilePath )
{
	const char* chData = get(iRow, iCol, csvFilePath);

	return atoi(chData);
}

const float CsvUtil::getFloat( int iRow, int iCol, const char* csvFilePath )
{
	const char* chData = get(iRow, iCol, csvFilePath);
    
	return atof(chData);
}

const int CsvUtil::findValueInWithLine( const char* chValue, int iValueCol, const char* csvFilePath )
{
    CCSize csvSize = getFileRowColNum(csvFilePath);
    
    int iLine = -1;
    for(int i = 0; i < csvSize.width; i++)
    {
        const char* ID = get(i, iValueCol, csvFilePath);
        CCString* IDStr = CCString::createWithFormat(ID);
        if(IDStr->m_sString.compare(chValue) == 0)
        {
            iLine = i;
            break;
        }
    }
    
    return iLine;
}