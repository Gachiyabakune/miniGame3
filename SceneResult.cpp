#include "SceneTitle.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "SceneMain.h"


//namespace
//{
//	const char* const kPlayerGraphicFilename = "data/end.png";
//}

void SceneResult::init()
{
	m_textPosY = 0;
	m_textVecY = 4;

	m_handle = 0;
	m_isEnd = false;

	//m_handle = LoadGraph("data/end.png");
}

SceneBase* SceneResult::update()
{

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	/*if (padState & PAD_INPUT_3)
	{
		DxLib_End();
	}*/
	return this;
}

void SceneResult::draw()
{
	DrawString(0, m_textPosY, "�Q�[���N���A", GetColor(255, 255, 255));
	//DrawGraphF(0, 0, m_handle, false);
}