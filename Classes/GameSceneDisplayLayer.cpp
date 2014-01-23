//
//  GameSceneDisplayLayer.cpp
//  myMiku
//
//  Created by bin on 14-1-20.
//
//

#include "GameSceneDisplayLayer.h"

bool GameSceneDisplayLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    CCSprite *background = CCSprite::create("game/stage.png");
    background->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(background,0);
    
    CCSprite *comboTag = CCSprite::create("game/COMBO.png");
    comboTag->setPosition(ccp(225,850));
    this->addChild(comboTag,4);
    
    CCLabelAtlas* comboCount=CCLabelAtlas::create("0123456789","game/number.png",40,50,'0');
    comboCount->setString("500");
    comboCount->setPosition(ccp(360,822));

    this->addChild(comboCount,4);
 
    
    
    
    //加载动画资源
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("animation/newmiku0.png","animation/newmiku0.plist","animation/newmiku.ExportJson");
    
	//新建动画
	armature = CCArmature::create("newmiku");
    
    //设定启始动画
    
    //armature->getAnimation()->setLoopType(ANIMATION_NO_LOOP);
    
    //std::string weapon[] = {"game/blueS.png"};
    //CCSkin *skin = CCSkin::createWithSpriteFrameName(weapon[0].c_str());
    //skin->setAnchorPoint(ccp(0,0)) ;
    //armature->getBone("cloth")->addDisplay(skin, 1);
    //armature->getBone("cloth")->changeDisplayWithIndex(1, true);
    
	//设置放大倍数
	armature->setScale(1.8f);
    
	//设置显示位置
	armature->setPosition(ccp(visibleSize.width * 0.5, armature->getContentSize().height/2+280));
    
	//添加到层
	this->addChild(armature,5);
    

    return true;
}

void GameSceneDisplayLayer::turnLeft()
{
	armature->getAnimation()->playWithIndex(0,1,15,0);
}

void GameSceneDisplayLayer::turnRight()
{
    armature->getAnimation()->playWithIndex(1,1,15,0);   //第三个参数越小越快
}
