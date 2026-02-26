#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Auralite {
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
#define AR_CORE_TRACE(...)    ::Auralite::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AR_CORE_INFO(...)     ::Auralite::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AR_CORE_WARN(...)     ::Auralite::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AR_CORE_ERROR(...)    ::Auralite::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AR_CORE_FATAL(...)    ::Auralite::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//Client Log
#define AR_TRACE(...)         ::Auralite::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AR_INFO(...)          ::Auralite::Log::GetClientLogger()->info(__VA_ARGS__)
#define AR_WARN(...)          ::Auralite::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AR_ERROR(...)         ::Auralite::Log::GetClientLogger()->error(__VA_ARGS__)
#define AR_FATAL(...)         ::Auralite::Log::GetClientLogger()->fatal(__VA_ARGS__)