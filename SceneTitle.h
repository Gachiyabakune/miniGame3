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
	//���W
	double x, y;

	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;
};