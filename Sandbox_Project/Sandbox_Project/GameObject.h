#pragma once
class CGameObject
{
public:

	virtual void	init() = 0;
	virtual void	update() = 0;
	virtual void	render() = 0;
	virtual void	destroy() = 0;

	CGameObject();
	virtual ~CGameObject();
};

