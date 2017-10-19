#pragma once
class CWindowApp
{
public:

	virtual void init();
	virtual void update();
	virtual void render();
	virtual void clear();
	virtual void destroy();	

	CWindowApp();
	virtual ~CWindowApp();
};

