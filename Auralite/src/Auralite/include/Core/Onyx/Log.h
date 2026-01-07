#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Onyx {
	class AURA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Loging
#define AR_CORE_TRACE(...)    ::Onyx::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AR_CORE_INFO(...)     ::Onyx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AR_CORE_WARN(...)     ::Onyx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AR_CORE_ERROR(...)    ::Onyx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AR_CORE_FATAL(...)    ::Onyx::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//Client Log
#define AR_TRACE(...)         ::Onyx::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AR_INFO(...)          ::Onyx::Log::GetClientLogger()->info(__VA_ARGS__)
#define AR_WARN(...)          ::Onyx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AR_ERROR(...)         ::Onyx::Log::GetClientLogger()->error(__VA_ARGS__)
#define AR_FATAL(...)         ::Onyx::Log::GetClientLogger()->fatal(__VA_ARGS__)