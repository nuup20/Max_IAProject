// Sandbox_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"
#include "SFMLApplication.h"
#include <iostream>

int main()
{	
	CSFMLApplication app_sandbox;
	
	app_sandbox.init();	
	return app_sandbox.run();
}
