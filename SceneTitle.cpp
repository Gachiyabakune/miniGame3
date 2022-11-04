#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	// 文字列点滅
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
	//ゲームスタート
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}
	// テキストの点滅
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
	//DrawString(0, m_textPosY, "タイトル", GetColor(255, 255, 255));
	//DrawString(0, m_textPosY + 20, "ゲームスタート->Aボタン", GetColor(255, 255, 255));

	SetFontSize(32);                             //サイズを64に変更
	SetFontThickness(4);                         //太さを8に変更
	ChangeFont("HGS創英角ﾎﾟｯﾌﾟ体");                     //種類をMS明朝に変更
	if (m_textBlinkFrame < kTextDispFrame)
	{
		DrawString(150, 150, "タイトル", GetColor(255, 255, 255));
	}
	
}