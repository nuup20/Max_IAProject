#include "stdafx.h"
#include "InteractiveButton.h"


void CInteractiveButton::hoverAnimation()
{

}

void CInteractiveButton::updateButtonParams()
{
	
	if (!m_font.loadFromFile(m_fontDirectory))
		m_font.loadFromFile("fonts/arial.ttf");
	m_label.setFont(m_font);
	m_label.setCharacterSize(m_characterSize);
	m_label.setString(m_buttonLabelStr);

	if (!m_texture.loadFromFile(m_buttonTextureDirectory))
		m_texture.loadFromFile("textures/default/spr_btn_01.png");
	setSizeByTexture(m_texture);
	m_btnSprite.setTexture(m_texture, true);
	m_btnSprite.setPosition(m_position.x, m_position.y);
	m_btnSprite.setColor(m_normalColor);

	sf::FloatRect rect = m_label.getGlobalBounds();
	m_label.setPosition(m_position.x + ((m_width - rect.width)*0.5), m_position.y + ((m_height - rect.height)*0.25));
}

void CInteractiveButton::init()
{
	m_fontDirectory = "fonts/Keep_Singing.ttf";
	m_buttonTextureDirectory = "textures/default/spr_btn_01.png";
	m_textColor = Color::White;
	m_hoverColor = Color::Red;
	m_normalColor = Color::Blue;
	m_buttonLabelStr = "Default";
	m_characterSize = 20;
	updateButtonParams();
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

unsigned int CInteractiveButton::getID()
{
	return m_buttonID;
}

bool CInteractiveButton::isPressedByPosition(int x, int y)
{
	sf::FloatRect butRect = m_btnSprite.getGlobalBounds();
	if (butRect.contains(x, y))
		return true;
	return false;
}

bool CInteractiveButton::isHoverbyPosition(int x, int y)
{
	sf::FloatRect butRect = m_btnSprite.getGlobalBounds();
	if (butRect.contains(x, y)) {		
		m_btnSprite.setColor(m_hoverColor);
		return true;
	}
	m_btnSprite.setColor(m_normalColor);
	return false;
}

void CInteractiveButton::setSize(int width, int height)
{

}

void CInteractiveButton::setTextureDirectory(string _directory)
{
	m_buttonTextureDirectory = _directory;
	updateButtonParams();	
}

void CInteractiveButton::setLabel(string _newLabel)
{
	m_buttonLabelStr = _newLabel;
	updateButtonParams();
}

CVector3 CInteractiveButton::getLabelPosition()
{
	sf::Vector2f p = m_label.getPosition();
	return CVector3(p.x, p.y, 0);
}

void CInteractiveButton::setLabelPosition(int x, int y, int z)
{
	m_label.setPosition(x, y);
}

void CInteractiveButton::setFontDirectory(string _Directory)
{
	m_fontDirectory = _Directory;
	updateButtonParams();
}


void CInteractiveButton::setFontColor(short r, short g, short b, short a)
{
	m_textColor = Color(r, g, b, a);
	m_label.setFillColor(m_textColor);
}

void CInteractiveButton::setNormalColor(short r, short g, short b, short a)
{
	m_normalColor = Color(r, g, b, a);
	m_btnSprite.setColor(m_normalColor);
}

void CInteractiveButton::setHoverColor(short r, short g, short b, short a)
{
	m_hoverColor = Color(r, g, b, a);
}

void CInteractiveButton::setFontSize(int _size)
{
	m_characterSize = _size;
	updateButtonParams();
}

void CInteractiveButton::setSizeByTexture(Texture & _texture)
{
	sf::Vector2u aux = _texture.getSize();
	m_width = aux.x;
	m_height = aux.y;
}


CInteractiveButton::~CInteractiveButton()
{
	destroy();
}
