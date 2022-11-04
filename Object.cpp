#include "Object.h"
#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"
#include "SceneResult.h"

namespace
{
	//�L�����N�^�[�̃T�C�Y
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
	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//A�{�^���������ƒ�~
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
	
	if (m_pos.y < 0)   m_pos.y = 0;    //��ʊO�ɍs���Ȃ��悤��
	if (m_pos.y > Game::kScreenHight - kSizeY)  m_pos.y = Game::kScreenHight - kSizeY;	 //��ʊO�ɍs���Ȃ��悤��
	if (m_pos.x < 0)   m_pos.x = 0;	 //��ʊO�ɍs���Ȃ��悤��
	if (m_pos.x > Game::kScreenWidth - kSizeX)  m_pos.x = 0;	 //��ʊO�ɍs���Ȃ��悤��


}

void Object::draw()
{
	DrawBox(m_pos.x, m_pos.y,m_pos.x + 60,m_pos.y + 60,GetColor(255,0,0),true);
}

//bool Object::isCol(Object& object)
//{
//
//}
