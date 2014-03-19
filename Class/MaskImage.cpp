#include "MaskImage.h"

using namespace cocos2d;

MaskImage::MaskImage() :
	m_pImage(NULL),
	m_pMask(NULL),
	m_pRender(NULL)
{
}


MaskImage::~MaskImage()
{
}

MaskImage * MaskImage::create(const char * image, const char * mask)
{
	MaskImage *ptr = new MaskImage();
	if (ptr && ptr->initWithFile(image, mask))
	{
		ptr->autorelease();
		return ptr;
	}
	CC_SAFE_DELETE(ptr);
	return nullptr;
}

bool MaskImage::initWithFile(const char * image, const char * mask)
{
	if (!CCNode::init())
		return false;

	
	m_pImage = Sprite::create(image);
	m_pImage->retain();
	m_pImage->setAnchorPoint(ccp(0, 0));

	
	m_pMask = Sprite::create(mask);
	m_pMask->retain();
	ccBlendFunc blend1 = { GL_ZERO, GL_ONE_MINUS_SRC_ALPHA };
	m_pMask->setBlendFunc(blend1);

	int w = Director::getInstance()->getWinSize().width;
	int h = Director::getInstance()->getWinSize().height;
	m_pRender = RenderTexture::create(w,h);
	m_pRender->setPosition(w / 2, h / 2);

	ccBlendFunc blend2 = { GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA };
	m_pRender->getSprite()->setBlendFunc(blend2);
	addChild(m_pRender, 2);


	m_pRender->begin();
		m_pImage->visit();
	m_pRender->end();

	return true;
}

void MaskImage::drawWithPos(CCPoint pos)
{
	m_pRender->begin();
		m_pMask->setPosition(pos);
		m_pMask->visit();
	m_pRender->end();
}

void MaskImage::maskingWithPos(CCPoint pos)
{
	m_pRender->clear(0, 0, 0, 1);
	m_pRender->begin();
		m_pImage->visit();
		m_pMask->setPosition(pos);
		m_pMask->visit();
	m_pRender->end();
}

void MaskImage::setMaskingSize(float size)
{
	m_pMask->setScale(size);
}

void MaskImage::imageClear()
{
	m_pRender->clear(0, 0, 0, 1);
	m_pRender->begin();
		m_pImage->visit();
	m_pRender->end();
}




