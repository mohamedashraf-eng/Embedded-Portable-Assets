/**
 * @file Wx_Compiler.h
 * @brief Compiler-specific macros and configurations for the Wx project.
 * @version 0.1
 * @date 2023-10-05
 * 
 * @license MIT License
 * 
 * @attention
 * MIT License
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * This file defines compiler-specific macros and configurations to ensure compatibility
 * across different compilers used in the Wx project.
 **/

/** @brief Header guard */
#if !defined(__WX_COMPILER_H__)
#define __WX_COMPILER_H__

/** @brief C++ name mangling guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_CompilerCfg.h"

/**
 * @defgroup CompilerSpecific Compiler-Specific Declarations
 * @{
 */

/* GCC Compiler Configurations */
#if defined(COMPILER_USED) && (COMPILER_USED == WX_COMPILER_GCC)

/**
 * @defgroup GCC_Compiler_Configurations GCC Compiler Configurations
 * @{
 */
#    define _WX_NORETURN __attribute__((noreturn))
#    define _WX_NOARG    __attribute__((noreturn))
#    define _WX_STATIC   static
#    define _WX_INLINE   inline __attribute__((always_inline))
#    define _WX_CONST    const
#    define _WX_LOCAL_INLINE static inline
#    define _WX_FORCE_CONST  __attribute__((const))
#    define _WX_PRINTF(a, b)  __attribute__((format(printf, a, b)))
#    define _WX_SCANF(a, b)  __attribute__((format(scanf, a, b)))
#    define _WX_MALLOC  __attribute__((malloc))
#    define _WX_WEAK  __attribute__((weak))
#    define _WX_COMPILETIME_WARNING(msg)  __attribute__((warning(msg)))
#    define _WX_FORCE_INLINE __attribute__((always_inline))
#    define _WX_FORCE_NOINLINE __attribute__((noinline))
#    define _WX_FORCE_SIGNAL __attribute__((signal))
#    define _WX_FORCE_SECTION(__SECTION) __attribute__((section(__SECTION)))
#    define _WX_USED __attribute__((used))
#    define _WX_ALIGN(n) __attribute__((aligned(n)))
#    define _WX_PACKED_STRUCT __attribute__((packed))
#    define _WX_COMPILETIME_ERROR(msg)  __attribute__((error(msg)))
#    define _WX_FORCE_UNUSED  __attribute__((unused))
#    define _WX_MUST_CHECK   __attribute__((warn_unused_result))
#    define _WX_OPTIMIZE_O0 __attribute__((optimize("O0"))) /**< No optimization */
#    define _WX_OPTIMIZE_O1 __attribute__((optimize("O1"))) /**< Optimize for size */
#    define _WX_OPTIMIZE_O2 __attribute__((optimize("O2"))) /**< Optimize for speed */
#    define _WX_OPTIMIZE_O3 __attribute__((optimize("O3"))) /**< Aggressive optimization */
#    define _WX_OPTIMIZE_OG __attribute__((optimize("Og"))) /**< Optimize for debugging */
#    define _WX_LIKELY(cond) __builtin_expect(!!(cond), 1)
#    define _WX_UNLIKELY(cond) __builtin_expect(!!(cond), 0)
#    define _WX_THREAD_LOCAL __thread
#    define _WX_NULL  (void *)0
#    define INTERRUPT_FUNC
/** @} */ /* End of GCC_Compiler_Configurations */

/* Clang Compiler Configurations */
#elif defined(COMPILER_USED) && (COMPILER_USED == WX_COMPILER_CLANG)

/**
 * @defgroup Clang_Compiler_Configurations Clang Compiler Configurations
 * @{
 */
#    define _WX_NORETURN __attribute__((noreturn))
#    define _WX_NOARG    __attribute__((noreturn))
#    define _WX_STATIC static
#    define _WX_INLINE inline __attribute__((always_inline))
#    define _WX_CONST  const
#    define _WX_LOCAL_INLINE static inline
#    define _WX_FORCE_CONST __attribute__((const))
#    define _WX_FORCE_INLINE __attribute__((always_inline))
#    define _WX_FORCE_NOINLINE __attribute__((noinline))
#    define _WX_FORCE_NORETURN __attribute__((noreturn))
#    define _WX_FORCE_SIGNAL __attribute__((signal))
#    define _WX_FORCE_SECTION(__SECTION) __attribute__((section(__SECTION)))
#    define _WX_USED __attribute__((used))
#    define _WX_ALIGN(n) __attribute__((aligned(n)))
#    define _WX_PACKED_STRUCT __attribute__((packed))
#    define _WX_PRINTF_FORMAT(fmt, args) __attribute__((format(printf, fmt, args)))
#    define _WX_OPTIMIZE_O0 __attribute__((optimize("O0"))) /**< No optimization */
#    define _WX_OPTIMIZE_O1 __attribute__((optimize("O1"))) /**< Optimize for size */
#    define _WX_OPTIMIZE_O2 __attribute__((optimize("O2"))) /**< Optimize for speed */
#    define _WX_OPTIMIZE_O3 __attribute__((optimize("O3"))) /**< Aggressive optimization */
#    define _WX_OPTIMIZE_OG __attribute__((optimize("Og"))) /**< Optimize for debugging */
#    define _WX_THREAD_LOCAL _Thread_local
#    define _WX_NULL (void *)0
#    define INTERRUPT_FUNC
/** @} */ /* End of Clang_Compiler_Configurations */

#else
#  error "Unsupported compiler configuration"
#endif /* COMPILER_USED */

/** @} */ /* End of CompilerSpecific */
/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_COMPILER_H__ */
