#pragma once

#ifdef TARS_DEBUG
#	define TARS_ENABLE_ASSERTS
#endif

#ifdef TARS_ENABLE_ASSERTS
#	define TARS_ASSERT(x, ...)                                                                    \
		{                                                                                          \
			if (!(x)) {                                                                            \
				TARS_ERROR("Assertion Failed: {0}", __VA_ARGS__);                                  \
				__debugbreak();                                                                    \
			}                                                                                      \
		}
#	define TARS_CORE_ASSERT(x, ...)                                                               \
		{                                                                                          \
			if (!(x)) {                                                                            \
				TARS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);                             \
				__debugbreak();                                                                    \
			}                                                                                      \
		}
#else
#	define TARS_ASSERT(x, ...)
#	define TARS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TARS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)