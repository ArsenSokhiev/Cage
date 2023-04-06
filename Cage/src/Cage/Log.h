#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Cage
{

	class CG_API Log
	{
	public:
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		static void Init();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define CG_CORE_TRACE(...)	::Cage::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define CG_CORE_INFO(...)	::Cage::Log::GetCoreLogger()->info(__VA_ARGS__);
#define CG_CORE_WARN(...)	::Cage::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define CG_CORE_ERROR(...)	::Cage::Log::GetCoreLogger()->error(__VA_ARGS__);
#define CG_CORE_FATAL(...)	::Cage::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client log macros
#define CG_TRACE(...)		::Cage::Log::GetClientLogger()->trace(__VA_ARGS__);
#define CG_INFO(...)		::Cage::Log::GetClientLogger()->info(__VA_ARGS__);
#define CG_WARN(...)		::Cage::Log::GetClientLogger()->warn(__VA_ARGS__);
#define CG_ERROR(...)		::Cage::Log::GetClientLogger()->error(__VA_ARGS__);
#define CG_FATAL(...)		::Cage::Log::GetClientLogger()->fatal(__VA_ARGS__);