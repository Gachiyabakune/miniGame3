#pragma once

class SceneMain;

class Back
{
private:
	//���W
	double x, y;

	//�O���t�B�b�N�n���h��
	int m_handle;

public:
	Back();
	virtual ~Back();

	void init();

	void update();

	void draw();
};
