// Sandbox_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"

int main()
{
	CApplication app_sandbox;
	app_sandbox.init(VideoMode(500, 500), "Sandbox Application");
	
	while (app_sandbox.m_window.isOpen()) {
		app_sandbox.update();
		app_sandbox.render();
	}

	return 0;
}
