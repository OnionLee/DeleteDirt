#pragma once

#include "cocos2d.h"

class MaskImage : public cocos2d::CCNode
{
public:
	static MaskImage * create(const char * image, const char * mask);

	bool initWithFile(const char * image, const char * mask);

	//���ϴ� ��ġ�� �׸���
	void SetDrawWithPos(cocos2d::CCPoint pos);
	//���ϴ� ��ġ�� ����ŷ
	void SetMaskingWithPos(cocos2d::CCPoint pos);
	//����ũ ������ ����
	void SetMaskingSize(float size);
	//�̹��� ����
	void SetImageClear();
	
protected:
	MaskImage();
	virtual ~MaskImage();

	cocos2d::Sprite * m_pImage;
	cocos2d::Sprite * m_pMask;
	cocos2d::RenderTexture * m_pRender;
};

