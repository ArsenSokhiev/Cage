#include "Application.h"

#include "Cage/Log.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Cage
{

	Application::Application() {}
	Application::~Application() {}

	void Application::Run()
	{
		WindowResizeEvent event(1280, 720);
		if (event.IsInCategory(EventCategory::EC_Application))
		{
			CG_TRACE(event);
		}

		while (true);
	}

}