#pragma once

#ifdef CG_PLATFORM_WINDOWS

extern Cage::Application* Cage::CreateApplication();

int main(int argc, char** argv)
{
	Cage::Log::Init();

	CG_CORE_WARN("Initialized Log");

	int a = 5;
	CG_INFO("Hello Var = {0}", a);

	auto app = Cage::CreateApplication();
	app->Run();
	delete app;
}

#endif