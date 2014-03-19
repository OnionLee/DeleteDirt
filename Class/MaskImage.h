#pragma once

#include "cocos2d.h"

class MaskImage : public cocos2d::CCNode
{
public:
	static MaskImage * create(const char * image, const char * mask);

	bool initWithFile(const char * image, const char * mask);


	void drawWithPos(cocos2d::CCPoint pos);

	void maskingWithPos(cocos2d::CCPoint pos);

	void setMaskingSize(float size);

	void imageClear();
	
protected:
	MaskImage();
	virtual ~MaskImage();

	cocos2d::Sprite * m_pImage;
	cocos2d::Sprite * m_pMask;
	cocos2d::RenderTexture * m_pRender;
};

