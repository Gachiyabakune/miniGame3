#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	// ������_��
	constexpr int kTextDispFrame = 45;
	constexpr int kTextHideFrame = 15;
}
void SceneTitle::init()
{
	m_isEnd = false;
	m_textBlinkFrame = 0;
	x = 0;
	y = 0;
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//�Q�[���X�^�[�g
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}
	// �e�L�X�g�̓_��
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= kTextDispFrame + kTextHideFrame)
	{
		m_textBlinkFrame = 0;
	}
	return this;
}

void SceneTitle::draw()
{
	//DrawGraph(x, y, m_handle, false);
	//DrawString(0, m_textPosY, "�^�C�g��", GetColor(255, 255, 255));
	//DrawString(0, m_textPosY + 20, "�Q�[���X�^�[�g->A�{�^��", GetColor(255, 255, 255));

	SetFontSize(32);                             //�T�C�Y��64�ɕύX
	SetFontThickness(4);                         //������8�ɕύX
	ChangeFont("HGS�n�p�p�߯�ߑ�");                     //��ނ�MS�����ɕύX
	if (m_textBlinkFrame < kTextDispFrame)
	{
		DrawString(150, 150, "�^�C�g��", GetColor(255, 255, 255));
	}
	
}