#pragma once

#include "Core/Application.h"



#ifndef THURMY_OVERRIDE_MAIN

extern Thurmy::Application* Thurmy::GetMainApp();

int main()
{
	auto app = Thurmy::GetMainApp();
	app->Run();
	delete app;
	return 0;
}

#endif // !THURMY_OVERRIDE_MAIN
