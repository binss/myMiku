//
//  CounterDownLabel.cpp
//  myMiku
//
//  Created by bin on 14-1-25.
//
//  refering to <<制作自己的捕鱼达人>>
//  用于数字的滚动显示

#include "CounterDownLabel.h"

CounterDownLabel::CounterDownLabel()
{
    labels=CCArray::create();
    CC_SAFE_RETAIN(labels);
    
    visibleNode=CCNode::create();
    CC_SAFE_RETAIN(visibleNode);
    
    lastNumber=0;                   //默认设定为0
    m_numberSize=30;                //默认用30号字
}

CounterDownLabel::~CounterDownLabel()
{
    CC_SAFE_RELEASE(labels);
    CC_SAFE_RELEASE(visibleNode);
}

CounterDownLabel* CounterDownLabel::create(int num,int numberSize)
{
    CounterDownLabel* instance=new CounterDownLabel();
    if(instance&&instance->init(num,numberSize))
    {
        instance->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(instance);
    }
    return instance;
}

bool CounterDownLabel::init(int num,int numberSize)
{
    bool bRet=false;
    this->lastNumber=num;
    this->m_numberSize=numberSize;
    
    this->addChild(this->visibleNode);
    //创建十个标签，数字0-9
    for(int i=0;i<10;i++)
    {
        char str[2];
        str[0]='0'+i;
        str[1]='\0';
        
        CCLabelTTF * single=CCLabelTTF::create(str, "DFGirlKelvin", m_numberSize);      //为方便使用，这里设定为娃娃体
        single->setColor(ccc3(38,132,113));                                             //设置标签字体颜色
        single->setTag(i);
        single->setAnchorPoint(ccp(0, 0));                                              //将锚点设为0，0便于设置坐标，容易对齐
        single->setPosition(ccp(0, m_numberSize *i));
        visibleNode->addChild(single);
        
        labels->addObject(single);      //将标签存入数组中
    }
    this->setNumberDirect(num);
    
    bRet=true;
    return bRet;
}

void CounterDownLabel::setNumber(int num,bool up=false)
{
    if(num<0 || num>9)
    {
        return;
    }
    
    this->stopAllActions();
    if(!up)                         //向下滚动，数字递减
    {
        if(this->lastNumber == 0 && num == 9)	//如果是从0到9，则直接设置，不滚动
        {
            setNumberDirect(num);
        }
        else
        {
            setNumberWithAnimation(num);
        }
    }
    else                            //向上滚动，数字累加
    {
        if(this->lastNumber == 9 && num == 0)	//如果是从9到0，则直接设置，不滚动
        {
            setNumberDirect(num);
        }
        else
        {
            setNumberWithAnimation(num);
        }
    }
    this->lastNumber=num;
}

void CounterDownLabel::setNumberDirect(int num)
{
    //获取到要移动到的label的坐标
    CCPoint moveToPosition =ccp(visibleNode->getPositionX(),-(static_cast<CCLabelTTF*>(labels->objectAtIndex(num)))->getPositionY());
    //创建一个动作，移动到该label的位置
    CCMoveTo * moveAction =CCMoveTo::create(0, moveToPosition);
    
    visibleNode->runAction(moveAction);
}

void CounterDownLabel::setNumberWithAnimation(int num)
{
    //获取到要移动到的label的坐标
    CCPoint moveToPosition =ccp(visibleNode->getPositionX(),-(static_cast<CCLabelTTF*>(labels->objectAtIndex(num)))->getPositionY());
    //创建一个动作，移动到该label的位置
    CCMoveTo * moveAction =CCMoveTo::create(0.8f, moveToPosition);          //move为移动时间
    
    visibleNode->runAction(moveAction);
}

void CounterDownLabel::visit()
{
    //启动遮罩效果
    glEnable(GL_SCISSOR_TEST);
    
    CCPoint  pos=CCPointZero;
    pos=visibleNode->getParent()->convertToWorldSpace(pos);
    CCRect rect =CCRectMake(pos.x, pos.y, m_numberSize, m_numberSize);
    //设置遮罩效果
    glScissor(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
    
    CCNode::visit();
    
    //关闭遮罩效果
    glDisable(GL_SCISSOR_TEST);
}

int CounterDownLabel::getNumber()
{
    return lastNumber;
}