#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "backImg.h"
#include <cassert>

void SceneMain::init()
{
	m_isEnd = false;

	for (int i = 0; i < 10; i++)
	{
		Object* pObject = new Object;
		pObject->init();
		pObject->setMain(this);
		m_pObjectVt.push_back(pObject);
	}
}

SceneBase* SceneMain::update()
{
	m_backImg.update();
	for (auto& pObject : m_pObjectVt)
	{
		assert(pObject);
		pObject->update();
	}
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	return this;
}

void SceneMain::draw()
{
	m_backImg.draw();
	for (auto& pObject : m_pObjectVt)
	{
		assert(pObject);
		pObject->draw();
	}
	
	//DrawString(4, 0, "ƒƒCƒ“‰æ–Ê", GetColor(255, 255, 255));
}