#pragma once

#include "cocos2d.h"

class MaskImage : public cocos2d::CCNode
{
public:
	static MaskImage * create(const char * image, const char * mask);

	bool initWithFile(const char * image, const char * mask);


	void SetDrawWithPos(cocos2d::CCPoint pos);

	void SetMaskingWithPos(cocos2d::CCPoint pos);

	void SetMaskingSize(float size);

	void SetImageClear();
	
protected:
	MaskImage();
	virtual ~MaskImage();

	cocos2d::Sprite * m_pImage;
	cocos2d::Sprite * m_pMask;
	cocos2d::RenderTexture * m_pRender;
};

