#pragma once

namespace Thurmy
{
	class Time
	{
	public:
		Time() = delete;
		Time(const Time&) = delete;

		inline static float GetDeltaTime();
		static float CalculateDeltaTime();
	};
}