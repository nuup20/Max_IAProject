#include "stdafx.h"
#include "InteractiveButton.h"


void CInteractiveButton::resetLabelPosition()
{
	sf::FloatRect rect = m_label.getGlobalBounds();
	m_label.setPosition(m_position.x + ((m_width - rect.width)*0.5), m_position.y + ((m_height - rect.height)*0.5));
}

void CInteractiveButton::init()
{
	if (!m_font.loadFromFile("fonts/Keep_Singing.ttf"))
		return;
	m_label.setFont(m_font);
	m_label.setFillColor(Color::White);
	m_label.setCharacterSize(20);
	m_label.setString("Default");	

	if (!m_texture.loadFromFile("textures/default/spr_btn_01.png"))
		return;
	setSizeByTexture(m_texture);
	m_btnSprite.setTexture(m_texture);
	m_btnSprite.setPosition(m_position.x, m_position.y);
	resetLabelPosition();	
	return;
}

void CInteractiveButton::update()
{
	//m_label.setPosition(m_position.x, m_position.y);
	//m_btnSprite.setPosition(m_position.x, m_position.y);
}

void CInteractiveButton::render(RenderWindow & wnd)
{
	wnd.draw(m_btnSprite);
	wnd.draw(m_label);
}

void CInteractiveButton::destroy()
{

}

bool CInteractiveButton::isPressedByPosition(int x, int y)
{
	sf::FloatRect butRect = m_btnSprite.getGlobalBounds();
	if (butRect.contains(x, y))
		return true;
	return false;
}

void CInteractiveButton::setSize(int width, int height)
{

}

bool CInteractiveButton::setTextureDirectory(string _directory)
{
	if(!m_texture.loadFromFile(_directory))
		return false;
	setSizeByTexture(m_texture);
	resetLabelPosition();
	return true;
}

void CInteractiveButton::setTexture(Texture _newTexture)
{
	m_texture = _newTexture;
}

void CInteractiveButton::setLabel(string _newLabel)
{
	m_label.setString(_newLabel);
	resetLabelPosition();
}

void CInteractiveButton::setFont(Font _newFont)
{
	m_font = _newFont;
	m_label.setFont(m_font);
	resetLabelPosition();
}

bool CInteractiveButton::loadFont(string _directory)
{
	if (!m_font.loadFromFile(_directory))
		return false;
	return true;
}

void CInteractiveButton::setFontColor(Color _fontColor)
{
	m_label.setFillColor(_fontColor);
}

void CInteractiveButton::setFontSize(int _size)
{
	m_label.setCharacterSize(_size);
}

void CInteractiveButton::setSizeByTexture(Texture & _texture)
{
	sf::Vector2u aux = _texture.getSize();
	m_width = aux.x;
	m_height = aux.y;
}

CInteractiveButton::CInteractiveButton()
{
}


CInteractiveButton::~CInteractiveButton()
{
}
