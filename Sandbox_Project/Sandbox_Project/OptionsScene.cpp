#include "stdafx.h"
#include "OptionsScene.h"


void COptionsScene::buttonFunc(unsigned int index)
{
	
}

void COptionsScene::init()
{
	//Title
	m_font.loadFromFile("fonts/Keep_Singing.ttf");
	m_title.setFont(m_font);
	m_title.setCharacterSize(64);
	m_title.setFillColor(Color::White);
	m_title.setPosition(400, 120);
	m_title.setString("Options");

	// Menu Button
	CInteractiveButton* _newBtn = new CInteractiveButton();
	_newBtn->m_name = "Back_Button";
	_newBtn->setPosition(400, 260);
	_newBtn->setLabel("Back");
	m_buttonList.push_back(_newBtn);
}

void COptionsScene::update()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->update();
}

void COptionsScene::render(RenderWindow & wnd)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(wnd);
	wnd.draw(m_title);
}

void COptionsScene::destroy()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->destroy();
	m_buttonList.clear();
}

void COptionsScene::onMouseClick(int x, int y, short btn)
{

}

void COptionsScene::onMouseMove(int x, int y)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->isHoverbyPosition(x, y);
}

COptionsScene::COptionsScene()
{
}


COptionsScene::~COptionsScene()
{
	destroy();
}
