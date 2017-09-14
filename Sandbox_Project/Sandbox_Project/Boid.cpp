#include "stdafx.h"
#include "Boid.h"

void CBoid::init() {
	m_shape.setRadius(100.f);
	m_shape.setFillColor(sf::Color::Red);
}

void CBoid::update()
{
}

void CBoid::render(RenderWindow& wnd)
{
	wnd.draw(m_shape);
}

void CBoid::destroy()
{
}

CBoid::CBoid()
{
}

CBoid::~CBoid()
{
	destroy();
}
