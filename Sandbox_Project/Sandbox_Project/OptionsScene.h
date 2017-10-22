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
	unsigned int update(void* pObject);
	void render(RenderWindow& wnd);
	void destroy();
	
	void onMouseReleased(int x, int y, short btn);
	void onMouseMove(int x, int y);

	COptionsScene(const std::string& title, RenderWindow* window) : CScene(SCENE_STATES ::kOptions, title, window) { m_font.loadFromFile("fonts/Keep_Singing.ttf"); }
	~COptionsScene();
};

