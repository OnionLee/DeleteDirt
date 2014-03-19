#pragma once

#include "cocos2d.h"
#include "MaskImage.h"

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


	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
};