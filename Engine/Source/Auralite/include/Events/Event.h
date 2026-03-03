#pragma once
#include "arpch.h"
#include "Core/Core.h"


namespace Auralite {

	enum class EventType
	{
		None = 0,
        // Window events
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
        // Application events
		AppTick, AppUpdate, AppRender,
        // Key events
		KeyPressed, KeyReleased, KeyTyped,
        // Mouse events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication		= BIT(0),
		EventCategoryInput				= BIT(1),
		EventCategoryKeyboard			= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryMouseButton        = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class AURA_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		void SetHandled(bool handle) { m_Handle = handle; }
		bool IsHandled() const { return m_Handle; }

	protected:
		bool m_Handle = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatcher(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handle = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}

#include <spdlog/fmt/fmt.h>
//To fix this problem of C2079: '_' uses undefined struct 'fmt::v12::detail::type_is_unformattable_for<T,char>'
// Formatter for Auralite::Event - fixes all spdlog/fmt errors

template <>
struct fmt::formatter<Auralite::Event>
{
	// parse is always the same
	constexpr auto parse(format_parse_context& ctx)
	{
		return ctx.begin();
	}

	// format MUST be const
	template <typename FormatContext>
	auto format(const Auralite::Event& e, FormatContext& ctx) const
	{
		return fmt::format_to(ctx.out(), "{}", e.ToString());
	}
};
