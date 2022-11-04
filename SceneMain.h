#pragma once
#include "SceneBase.h"
#include "backImg.h"
#include "Object.h"
#include <vector>

class SceneMain : public SceneBase
{
public:
	SceneMain(){};
	virtual ~SceneMain() {}


	virtual void init();
	virtual void end() {}

	virtual SceneBase* update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:

	//�w�i
	Back m_backImg;
	//�I�u�W�F�N�g
	//Object object;

	std::vector<Object*> m_pObjectVt;

	bool m_isEnd;
};