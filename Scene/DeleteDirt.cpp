#include "DeleteDirt.h"
#include "RGBARead.h"

USING_NS_CC;

Scene* DeleteDirt::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DeleteDirt::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool DeleteDirt::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Back = Sprite::create("Back.png");
	Back->setPosition(ccp(1280 * 0.5f, 720 * 0.5f));
	addChild(Back, 0);


	this->schedule(schedule_selector(DeleteDirt::foo));

	Mask = MaskImage::create("Fore.png", "Mask.png");
	addChild(Mask);

	Mask2 = MaskImage::create("Fore.png", "Mask.png");
	addChild(Mask2);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(DeleteDirt::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(DeleteDirt::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(DeleteDirt::onTouchEnded, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void DeleteDirt::foo(float dt)
{
	static int i = 0;
	i++;

	Mask2->maskingWithPos(ccp(300, 300));
	Mask2->setMaskingSize(i/100.0f);
}

bool DeleteDirt::onTouchBegan(Touch *touch, Event *event)
{
	return true;
}

void DeleteDirt::onTouchMoved(Touch *touch, Event *event)
{
	Mask->drawWithPos(touch->getLocation());
}

void DeleteDirt::onTouchEnded(Touch *touch, Event *event)
{
	
}





