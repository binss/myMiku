//
//  CounterDownLabel.h
//  myMiku
//
//  Created by bin on 14-1-25.
//
//  refering to <<制作自己的捕鱼达人>>
//  用于数字的滚动显示

#ifndef __myMiku__CounterDownLabel__
#define __myMiku__CounterDownLabel__

#include "cocos2d.h"

USING_NS_CC;

class CounterDownLabel:public CCNode
{
public:
    CounterDownLabel();
    ~CounterDownLabel();
    
    virtual bool init(int num,int numberSize);
    static CounterDownLabel* create(int num,int numberSize);
    
    void setNumber(int num,bool up);        // 设置数值
    int getNumber();
    void visit(void);
    
private:
    
    CCArray* labels;        //用来保存label的数组
    
    CCNode* visibleNode;    //创建一个节点，将label添加到节点上，便于移动

    int lastNumber;         //上次的数值，便于动画控制
    
    int m_numberSize;       //文字字号大小
    
    void setNumberDirect(int num);              //直接设定数字，不需要滚动
    
    void setNumberWithAnimation(int num);       //设置数字，需要滚动动画
    

};

#endif /* defined(__myMiku__CounterDownLabel__) */
