#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include <Tars/Main/Core.h>

namespace Tars {
	class Log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};


}

// Core log macros
#define TARS_CORE_TRACE(...) ::Tars::Log::getCoreLogger()->trace(__VA_ARGS__)
#define TARS_CORE_INFO(...) ::Tars::Log::getCoreLogger()->info(__VA_ARGS__)
#define TARS_CORE_WARN(...) ::Tars::Log::getCoreLogger()->warn(__VA_ARGS__)
#define TARS_CORE_ERROR(...) ::Tars::Log::getCoreLogger()->error(__VA_ARGS__)
#define TARS_CORE_CRITICAL(...) ::Tars::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TARS_TRACE(...) ::Tars::Log::getClientLogger()->trace(__VA_ARGS__)
#define TARS_INFO(...) ::Tars::Log::getClientLogger()->info(__VA_ARGS__)
#define TARS_WARN(...) ::Tars::Log::getClientLogger()->warn(__VA_ARGS__)
#define TARS_ERROR(...) ::Tars::Log::getClientLogger()->error(__VA_ARGS__)
#define TARS_CRITICAL(...) ::Tars::Log::getClientLogger()->critical(__VA_ARGS__)