#pragma once

#ifdef _MSC_VER // VS
#	define EXPORT __declspec(dllexport)
#	define IMPORT __declspec(dllimport)
#elif __GNUC__ // GCC
#	define EXPORT __attribute__((visibility("default")))
#	define IMPORT
#else
#	error Tars does not support your compiler!
#endif

#ifdef TARS_BUILD_DLL
#	define TARS_API EXPORT
#else
#	define TARS_API IMPORT
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
				TARS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);                                  \
				__debugbreak();                                                                    \
			}                                                                                      \
		}
#else
#	define TARS_ASSERT(x, ...)
#	define TARS_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)