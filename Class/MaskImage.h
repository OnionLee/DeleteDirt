#pragma once
#include "cocos2d.h"

using namespace cocos2d;
class MaskImage : public CCNode
{
public:


	static MaskImage * create();
	static MaskImage * create(const char * Image, const char * mask);

	bool init();
	bool initWithFile(const char * Image, const char * mask);

	//원하는 위치에 그리기
	void SetDrawWithPos(CCPoint pos);
	//원하는 위치에 마스킹
	void SetMaskingWithPos(CCPoint pos);
	//마스크 사이즈 조절
	void SetMaskingSize(float size);
	//이미지 리셋
	void SetImageClear();
	
private:
	MaskImage();
	~MaskImage();

	Sprite * m_pImage;
	Sprite * m_pMask;
	RenderTexture * m_pRender;
};

