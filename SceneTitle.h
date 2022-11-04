#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_isEnd = false;
	}
	virtual ~SceneTitle() {}


	virtual void init() override;
	virtual void end()override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

private:

	bool m_isEnd;

	int m_handle;
	//座標
	double x, y;

	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
};