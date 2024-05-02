#pragma once

#define STATICTYPE(x) static EventType GetStaticType() { return EventType::x; } \
						EventType GetEventType() override { return GetStaticType(); }

#define BIND_FUNC(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Thurmy
{
	enum class EventType
	{
		Window,
		Mouse,
		Keyboard,
		Gamepad
	};

	class Event
	{
	public:
		bool Handled;

		virtual EventType GetEventType() = 0;
	};

	class KeyPressEvent : public Event
	{
	public:
		KeyPressEvent(int key)
			: m_Key(key)
		{
		}

		STATICTYPE(Keyboard)

		inline int GetKey() const { return m_Key; }

	private:
		int m_Key;
	};


	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{

		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}

			return false;
		}

	private:
		Event& m_Event;
	};

	class KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent(int key)
			: m_Key(key)
		{
		}

		STATICTYPE(Keyboard)

		inline int GetKey() const { return m_Key; }

	private:
		int m_Key;
	};
}