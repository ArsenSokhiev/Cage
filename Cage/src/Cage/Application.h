#pragma once

#include "Core.h"

namespace Cage
{

	class CG_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}