#include "stdafx.h"
#include "MenuGM.h"

void CMenuGM::buttonFunc(unsigned int index)
{
	switch (index) {
	case 0: // Play Button
		
		break;
	case 1:// Option Button

		break;
	default:
		break;
	}
}

void CMenuGM::init()
{
	//Title
	m_font.loadFromFile("fonts/Keep_Singing.ttf");
	m_title.setFont(m_font);
	m_title.setCharacterSize(64);
	m_title.setFillColor(Color::White);
	m_title.setPosition(350, 120);
	m_title.setString("SandBox");

	// Play Button
	CInteractiveButton* _newBtn = new CInteractiveButton();
	_newBtn->m_name = "Play_Button";
	_newBtn->setPosition(400, 260);
	_newBtn->init();
	_newBtn->setLabel("Play!");
	m_buttonList.push_back(_newBtn);

	// Option Button
	_newBtn = new CInteractiveButton();
	_newBtn->m_name = "Option_Button";
	_newBtn->setPosition(400, 360);
	_newBtn->init();
	_newBtn->setLabel("Options");
	m_buttonList.push_back(_newBtn);
	
}

void CMenuGM::update()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->update();
}

void CMenuGM::render(RenderWindow& wnd)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(wnd);
	wnd.draw(m_title);
}

void CMenuGM::destroy()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->destroy();
}

void CMenuGM::onMouseClick(int x, int y, short btn)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		if (m_buttonList[i]->isPressedByPosition(x, y)) {
			buttonFunc(i);
			return;
		}
}

CMenuGM::CMenuGM()
{
}


CMenuGM::~CMenuGM()
{
	destroy();
}
