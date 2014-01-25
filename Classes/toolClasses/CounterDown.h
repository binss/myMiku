//
//  CounterDown.h
//  myMiku
//
//  Created by bin on 14-1-25.
//
//  用于建立滚动表盘，即表盘上的数字变化时会呈现滚动变换

#ifndef __myMiku__CounterDown__
#define __myMiku__CounterDown__

#include "cocos2d.h"

USING_NS_CC;

class CounterDown:public CCNode
{
public:
    CounterDown();
    ~CounterDown();
    
    //参数：初始化时表盘数字大小，要设置的表盘位数，表盘数字尺寸，表盘各位之间的间隔
    virtual bool init(int num,int numberLenght,int numberSize,int numberWidth);
    static CounterDown* create(int num,int numberLenght,int numberSize,int numberWidth);
    // 设置数值
    void setNumber(int num);
    int getCounterNumber();
    
private:
    
    CCArray* arrayLabels;               //CounterDownLabel数组，用于存储数显示字的每一位
    
    CCArray* getIntArray(int num);      //把一个整数按照每一位转换成整数数组

    int m_numberSize;                   //字号大小
    int m_numberLength;                  //数字位数

};
#endif /* defined(__myMiku__CounterDown__) */
