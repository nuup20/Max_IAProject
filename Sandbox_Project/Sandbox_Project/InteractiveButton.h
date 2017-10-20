#pragma once
#include "GameObject.h"

using sf::Texture;
using sf::Text;
using sf::Font;
using sf::Sprite;
using sf::Color;

class CInteractiveButton : public CGameObject
{
private:
	
	Font	m_font;
	Text	m_label;
	Texture	m_texture;
	Sprite	m_btnSprite;

	int m_width;
	int m_height;

	void resetLabelPosition();

public:

	void	init();
	void	update();
	void	render(RenderWindow& wnd);
	void	destroy();
	
	bool isPressedByPosition(int x, int y);

	void setSize(int width, int height);
	bool setTextureDirectory(string _directory);
	void setTexture(Texture _newTexture);
	void setLabel(string _newLabel);
	void setFont(Font _newFont);
	bool loadFont(string _directory);
	void setFontColor(Color _fontColor);
	void setFontSize(int _size);
	void setSizeByTexture(Texture& _texture);

	CInteractiveButton();
	~CInteractiveButton();
};

