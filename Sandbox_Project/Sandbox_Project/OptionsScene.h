#pragma once
#include "Scene.h"
#include "InteractiveButton.h"

class COptionsScene :
	public CScene
{
private:

	vector<CInteractiveButton*> m_buttonList;
	Font	m_font;
	Text	m_title;

	void buttonFunc(unsigned int index);

public:

	void init();
	void update();
	void render(RenderWindow& wnd);
	void destroy();
	
	void onMouseClick(int x, int y, short btn);
	void onMouseMove(int x, int y);

	COptionsScene();
	~COptionsScene();
};

