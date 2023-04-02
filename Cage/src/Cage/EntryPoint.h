#pragma once

#ifdef CG_PLATFORM_WINDOWS

extern Cage::Application* Cage::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Cage::CreateApplication();
	app->Run();
	delete app;
}

#endif