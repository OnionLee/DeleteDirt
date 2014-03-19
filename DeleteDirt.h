#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "MaskImage.h"

using namespace cocos2d;


class DeleteDirt : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	void foo(float dt);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(DeleteDirt);

	cocos2d::Sprite * Back;
	MaskImage * Mask;
	MaskImage * Mask2;


	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
};

#endif // __HELLOWORLD_SCENE_H__
