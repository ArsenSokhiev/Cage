#pragma once

#include "Cage/Core.h"

#include <string>
#include <functional>

namespace Cage
{

	// Events are currently blocking 
	// (when an event occurs it gets dispatched and must be dealt with right then an there)
	// For the future, a better strategy might be to buffer events in an event bus
	// and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,

		// Application events
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,

		// Key events
		KeyPressed, KeyReleased,

		// Mouse events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum class EventCategory
	{
		None = 0,
		EC_Application	= BIT(0),
		EC_Input		= BIT(1),
		EC_Keyboard		= BIT(2),
		EC_Mouse		= BIT(3),
		EC_MouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
 

	class CG_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & (int)category;
		}

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
	private:
		template <typename T>
		using EventFn = std::function<bool(T&)>;

		Event& m_Event;

	public:
		EventDispatcher(Event& Event) : m_Event(Event) {}

		template <typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}