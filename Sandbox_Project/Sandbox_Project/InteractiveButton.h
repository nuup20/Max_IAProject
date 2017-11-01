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

	unsigned int	m_buttonID;

	Color	m_hoverColor;
	Color	m_normalColor;
	Color	m_textColor;
	int		m_characterSize;
	string	m_buttonLabelStr;
	string	m_fontDirectory;
	string	m_buttonTextureDirectory;
	
	Font	m_font;
	Text	m_label;
	Texture	m_texture;
	Sprite	m_btnSprite;

	int m_width;
	int m_height;
	
	void hoverAnimation();	
	void setSizeByTexture(Texture& _texture);

public:

	void	init();
	void	update();
	void	render(RenderWindow& wnd);
	void	destroy();

	unsigned int getID();
	
	bool		isPressedByPosition(int x, int y);
	bool		isHoverbyPosition(int x, int y);	

	void		setSize(int width, int height);
	void		setTextureDirectory(string _directory);	
	void		setLabel(string _newLabel);
	CVector3	getLabelPosition();
	void		setLabelPosition(int x, int y, int z = 0);
	void		setFontDirectory(string _directory);	
	void		setFontColor(short r, short g, short b, short a);
	void		setNormalColor(short r, short g, short b, short a);
	void		setHoverColor(short r, short g, short b, short a);
	void		setFontSize(int _size);
	CVector3	getButtonSpriteSize();
	void		updateButtonParams();
	

	CInteractiveButton(unsigned int id) : m_buttonID(id) { init(); };
	~CInteractiveButton();
};

