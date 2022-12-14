#include "backImg.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	constexpr int scrollSpead = 2;
}
Back::Back()
{
	m_handle = LoadGraph("data/midori2.jpg");
	x = 0;
	y = 0;
}

Back::~Back()
{

}

void Back::init()
{

}

void Back::update()
{
	y += scrollSpead;
}

void Back::draw()
{
#if false
	//１枚目描画
	DrawGraph(x, y, m_handle, false);
	//２枚目描画
	DrawGraph(x, y - Game::kScreenHight, m_handle, false);
	//１番下までスクロールすると初期値に
	if (y == 480)
	{
		y = 0;
	}
#else
	//Y軸
	DrawLine(60, 120, 60, 660, GetColor(255, 255, 255));
	DrawLine(120, 120, 120, 660, GetColor(255, 255, 255));
	DrawLine(180, 120, 180, 660, GetColor(255, 255, 255));
	DrawLine(240, 120, 240, 660, GetColor(255, 255, 255));
	DrawLine(300, 120, 300, 660, GetColor(255, 255, 255));
	DrawLine(360, 120, 360, 660, GetColor(255, 255, 255));

	//ゴールのライン
	DrawLine(0, 120, 420, 120, GetColor(255, 255, 255));
#endif
}
