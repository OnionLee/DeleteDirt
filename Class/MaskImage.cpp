#include "MaskImage.h"


MaskImage::MaskImage()
{
}


MaskImage::~MaskImage()
{
}

MaskImage * MaskImage::create()
{
	MaskImage *ptr = new MaskImage();
	if (ptr && ptr->init())
	{
		ptr->autorelease();
		return ptr;
	}
	CC_SAFE_DELETE(ptr);
	return nullptr;
}

MaskImage * MaskImage::create(const char * Image, const char * mask)
{
	MaskImage *ptr = new MaskImage();
	if (ptr && ptr->initWithFile(Image, mask))
	{
		ptr->autorelease();
		return ptr;
	}
	CC_SAFE_DELETE(ptr);
	return nullptr;
}

bool MaskImage::init()
{
	return true;
}

bool MaskImage::initWithFile(const char * Image, const char * mask)
{
	if (!init())
		return false;

	//Áö¿ï ÀÌ¹ÌÁö
	m_pImage = Sprite::create(Image);
	m_pImage->retain();
	m_pImage->setAnchorPoint(ccp(0, 0));

	setPosition(ccp(m_pImage->getContentSize().width / 2,
		m_pImage->getContentSize().height / 2));

	//¸¶½ºÅ©(ºí·»µù)
	m_pMask = Sprite::create(mask);
	m_pMask->retain();
	ccBlendFunc blend1 = { GL_ZERO, GL_ONE_MINUS_SRC_ALPHA };
	m_pMask->setBlendFunc(blend1);

	//·»´õ ÅØ½ºÃÄ(ºí·»µù)
	m_pRender = RenderTexture::create(m_pImage->getContentSize().width,
									m_pImage->getContentSize().height);
	ccBlendFunc blend2 = { GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA };
	m_pRender->getSprite()->setBlendFunc(blend2);
	addChild(m_pRender, 2);

	//ÀÌ¹ÌÁö ÇÑ¹ø ·»´õ ÇÔ
	m_pRender->begin();
	m_pImage->visit();
	m_pRender->end();

	return true;
}

void MaskImage::SetDrawWithPos(CCPoint pos)
{
	m_pRender->begin();
	m_pMask->setPosition(pos);
	m_pMask->visit();
	m_pRender->end();
}

void MaskImage::SetMaskingWithPos(CCPoint pos)
{
	m_pRender->clear(0, 0, 0, 1);
	m_pRender->begin();
	m_pImage->visit();
	m_pMask->setPosition(pos);
	m_pMask->visit();
	m_pRender->end();
}

void MaskImage::SetMaskingSize(float size)
{
	m_pMask->setScale(size);
}

void MaskImage::SetImageClear()
{
	m_pRender->clear(0, 0, 0, 1);
	m_pRender->begin();
	m_pImage->visit();
	m_pRender->end();
}




