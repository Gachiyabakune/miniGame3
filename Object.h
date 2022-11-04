#pragma once

#include "Vec2.h"

class SceneMain;

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void init();

	virtual void update();
	virtual void draw();

	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	//bool isCol(Object& object);

protected:
	//SceneMain�̃|�C���^
	SceneMain* m_pMain;
	// ������W
	Vec2 m_pos;

	bool m_flag;

	int num = 0;
};