#include "Object.h"
#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"
#include "SceneResult.h"

namespace
{
	//キャラクターのサイズ
	constexpr float kSizeX = 60.0f;
	constexpr float kSizeY = 60.0f;
}

Object::Object() : 
	m_pos(),
	m_flag(false),
	num(0)
{
}

Object::~Object()
{

}

void Object::init()
{

}

void Object::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//Aボタンを押すと停止
	if (padState & PAD_INPUT_2)
	{
		m_flag = true;
	}

	if (!m_flag)
	{
		m_pos.x += 60;
	}
	else
	{
		num++;
		if (num > 60)
		{
			m_pos.y += 60;

		}	
	}
	
	if (m_pos.y < 0)   m_pos.y = 0;    //画面外に行かないように
	if (m_pos.y > Game::kScreenHight - kSizeY)  m_pos.y = Game::kScreenHight - kSizeY;	 //画面外に行かないように
	if (m_pos.x < 0)   m_pos.x = 0;	 //画面外に行かないように
	if (m_pos.x > Game::kScreenWidth - kSizeX)  m_pos.x = 0;	 //画面外に行かないように


}

void Object::draw()
{
	DrawBox(m_pos.x, m_pos.y,m_pos.x + 60,m_pos.y + 60,GetColor(255,0,0),true);
}

//bool Object::isCol(Object& object)
//{
//
//}
