#pragma once
#include "cocos2d.h"

using namespace cocos2d;
class MaskImage : public CCNode
{
public:


	static MaskImage * create(const char * Image, const char * mask);

	bool initWithFile(const char * Image, const char * mask);

	//���ϴ� ��ġ�� �׸���
	void SetDrawWithPos(CCPoint pos);
	//���ϴ� ��ġ�� ����ŷ
	void SetMaskingWithPos(CCPoint pos);
	//����ũ ������ ����
	void SetMaskingSize(float size);
	//�̹��� ����
	void SetImageClear();
	
private:
	MaskImage();
	~MaskImage();

	Sprite * m_pImage;
	Sprite * m_pMask;
	RenderTexture * m_pRender;
};

