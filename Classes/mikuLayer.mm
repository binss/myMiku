#include "mikuLayer.h"
#include "QuestionBox/QuestionBox.h"


// on "init" you need to initialize your instance

QuestionBox * box;

bool mikuLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(mikuLayer::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    
    
    //加载动画资源
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("miku0.png","miku0.plist","miku.ExportJson");
    
	//新建动画
	armature = CCArmature::create("miku");
	//设定启始帧
	armature->getAnimation()->playByIndex(0);
	//设置放大倍数
	armature->setScale(1.8f);
    
	//设置显示位置
	armature->setPosition(ccp(visibleSize.width * 0.5, armature->getContentSize().height/2+190));
    
	//添加到层
	this->addChild(armature,0);
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    
    i=0;

    return true;
}

void mikuLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,30,true);
}

bool mikuLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(i == 40)
        i = 0;
    i += 10;
    armature->getAnimation()->playByIndex(0);
    for (int x=i;x<i+ 10;x++)
        armature->getAnimation()->gotoAndPause(i);
    
//    if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    {
//        //CCMessageBox("this is content","title");
//        box = [[QuestionBox alloc] init];
//        [box hMessageBox:@"是否喂食？" title:@"喂食"];
//        schedule(schedule_selector(mikuLayer::checkQuestionBoxStatus), 0.1f);
//    }
    return true;
}

void mikuLayer::checkQuestionBoxStatus(float dt)
{
    if(box.status != 0 )
    {
        CCLog("%i",box.status);
        unschedule(schedule_selector(mikuLayer::checkQuestionBoxStatus));
        [box release];
    }
}


/*
void mikuLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCLOG("yeah");
}
*/
void mikuLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
}


void mikuLayer::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
