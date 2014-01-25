//
//  CounterDown.cpp
//  myMiku
//
//  Created by bin on 14-1-25.
//
//  用于建立滚动表盘，即表盘上的数字变化时会呈现滚动变换

#include "CounterDown.h"
#include "CounterDownLabel.h"

CounterDown::CounterDown()
{
    //arrayLabels=CCArray::create();
    //CC_SAFE_RETAIN(arrayLabels);
    
    m_numberLength=0;
    m_numberSize=30;
}

CounterDown::~CounterDown()
{
    //CC_SAFE_RELEASE_NULL(arrayLabels);
}

CounterDown* CounterDown::create(int num,int numberLenght,int numberSize,int numberWidth)
{
    CounterDown* instance=new CounterDown();
    if(instance&&instance->init(num,numberLenght,numberSize,numberWidth))
    {
        instance->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(instance);
    }
    return instance;
}

bool CounterDown::init(int num,int numberLenght,int numberSize,int numberWidth)
{
    bool bRet=false;
    
    this->m_numberSize=numberSize;
    
    CCArray* arrayInt=getIntArray(num);
    this->m_numberLength= numberLenght;
    
    for(int i=0;i<m_numberLength;i++)
    {
        int val;
        if(i<arrayInt->count())
        {
            val = static_cast<CCInteger*>(arrayInt->objectAtIndex(i))->getValue();
            
        }
        else
        {
            val = 0;
        }
        CounterDownLabel* single=CounterDownLabel::create(val,numberSize);
        single->setPosition(ccp(numberWidth*(m_numberLength-i-1),0));
        single->setTag(i);
        this->addChild(single);
        //arrayLabels->addObject(single);
    }
    
    bRet=true;
    return bRet;
}

void CounterDown::setNumber(int num)
{
    CCArray* arrayInt=getIntArray(num);
    int tmpCount=arrayInt->count();
    int val=0;
    
    for(int i=0;i<m_numberLength;i++)
    {
        if(i+1<=tmpCount)
        {
            val=static_cast<CCInteger*>(arrayInt->objectAtIndex(i))->getValue();
        }
        else
        {
            val=0;
        }
        CounterDownLabel* single=dynamic_cast<CounterDownLabel*>(this->getChildByTag(i));
        single->setNumber(val,false);
    }
}

CCArray* CounterDown::getIntArray(int num)
{
    CCArray* arr=CCArray::create();
    
    if(num<0)
    {
        return arr;
    }
    
    int tmp=num;
    while (tmp>0)
    {
        arr->addObject(CCInteger::create(tmp%10));
        tmp=tmp/10;
    }
    
    return arr;
}

int CounterDown::getCounterNumber()
{
    int number = 0;
    
    for(int i=m_numberLength - 1;i >= 0;i--)
    {
        number = 10 * number + (dynamic_cast<CounterDownLabel*>(this->getChildByTag(i)))->getNumber();
    }

    return number;
}

