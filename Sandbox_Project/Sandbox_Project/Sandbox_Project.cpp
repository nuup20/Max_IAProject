// Sandbox_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"
#include <iostream>

int main()
{	
	CApplication app_sandbox;
	app_sandbox.init(1280, 720, "Steering Behaviors");
	
	while (1) {
		app_sandbox.update();
		app_sandbox.render();
	}	

	return 0;
}
