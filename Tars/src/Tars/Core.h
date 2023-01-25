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

#define BIT(x) (1 << x)