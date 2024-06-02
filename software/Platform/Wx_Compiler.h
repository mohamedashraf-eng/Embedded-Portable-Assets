/**
 * @file Wx_Compiler.h
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * @license MIT License
 * 
 * @attention
 *  
 * MIT License
 * 
 * Copyright (c) 2023, Mohamed Ashraf Wx
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
**/
/** @brief header gurad */
#if !defined(__WX_COMPILER_H__)
#define __WX_COMPILER_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_CompilerCfg.h"
/*----------------------------------------------------------------------------*/
/** 
 * @defgroup Compiler Specific Declarations 
 * @{
 */

#if defined(COMPILER_USED)

#  if (COMPILER_USED == WX_COMPILER_GCC)

/** 
 * @defgroup Compiler_Specific_Declarations Compiler Specific Declarations 
 * @{
 */

#if defined(COMPILER_USED)

#  if (COMPILER_USED == WX_COMPILER_GCC)

/** 
 * @defgroup GCC_Compiler_Configurations GCC Compiler Configurations 
 * @{
 */
#    if defined(__GNUC__) && ((__GNUC__ > 2) || ((__GNUC__ == 2) && (__GNUC_MINOR__ >= 0)))
#      define __NORETURN void
#      define __NOARG    void
#      define __STATIC   static
#      define __INLINE   inline
#      define __CONST    const
#      define __LOCAL_INLINE __STATIC __INLINE
#      define __FORCE_CONST  __attribute__((__const__))
#      define __PRINTF(a, b)  __attribute__((__format__(printf, a, b)))
#      define __SCANF(a, b)  __attribute__((__format__(scanf, a, b)))
#      define __MALLOC  __attribute__((__malloc__))
#      define __FORCE_NORETURN  __NORETURN __attribute__((__noreturn__))
#      define __WEAK  __attribute__((__weak__))
#    endif /* GCC >= 2.0.0 */

#    if ((__GNUC__ > 2) || ((__GNUC__ == 2) && (__GNUC_MINOR__ >= 5)))
#      define __COMPILETIME_WARNING(msg)  __attribute__((__warning__(msg)))
#    endif /* GCC >= 2.5.0 */

#    if ((__GNUC__ > 2) || ((__GNUC__ == 2) && (__GNUC_MINOR__ >= 7)))
#      define __FORCE_INLINE __INLINE __attribute__((__always_inline__))
#      define __FORCE_NOINLINE __attribute__((__noinline__))
#      define __FORCE_SIGNAL __attribute__((__signal__))
#      define __FORCE_SECTION(__SECTION) __attribute__((section(__SECTION)))
#      define __USED __attribute__((used))
#    endif /* GCC >= 2.7.0 */

#    if ((__GNUC__ > 2) || ((__GNUC__ == 2) && (__GNUC_MINOR__ >= 9)))
#      define __COMPILETIME_ERROR(msg)  __attribute__((__error__(msg)))
#    endif /* GCC >= 2.9.0 */

#    if ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#      define __FORCE_UNUSED  __attribute__((__unused__))
#      define __MUST_CHECK   __attribute__((__warn_unused_result__))
#    endif /* GCC >= 3.3.1 */

#    if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 5)))
#      define __OPTIMIZE_O0 __attribute__((optimize("O0"))) /**< No optimization */
#      define __OPTIMIZE_O1 __attribute__((optimize("O1"))) /**< Optimize for size */
#      define __OPTIMIZE_O2 __attribute__((optimize("O2"))) /**< Optimize for speed */
#      define __OPTIMIZE_O3 __attribute__((optimize("O3"))) /**< Aggressive optimization */
#      define __OPTIMIZE_OG __attribute__((optimize("OG"))) /**< Optimize for debugging */
#    endif /* GCC >= 4.5.0 */

#    define __LIKELY(cond) __builtin_expect(!!(cond), 1)
#    define __UNLIKELY(cond) __builtin_expect(!!(cond), 0)
#    define __THREAD_LOCAL __thread
#    define __NULL  (void *)0
#    define INTERRUPT_FUNC 
/** @} */

#  elif (COMPILER_USED == WX_COMPILER_CLANG)

/** 
 * @defgroup Clang_Compiler_Configurations Clang Compiler Configurations 
 * @{
 */
#    if defined(__clang__)
#      define __NORETURN void
#      define __NOARG    void
#      define __STATIC static
#      define __INLINE inline
#      define __CONST  const
#      define __LOCAL_INLINE __STATIC __INLINE
#      define __FORCE_CONST __attribute__((const))
#      define __FORCE_INLINE __attribute__((always_inline))
#      define __FORCE_NOINLINE __attribute__((noinline))
#      define __FORCE_NORETURN __attribute__((noreturn))
#      define __FORCE_SIGNAL __attribute__((signal))
#      define __FORCE_SECTION(__SECTION) __attribute__((section(__SECTION)))
#      define __USED __attribute__((used))
#      define __ALIGN(n) __attribute__((aligned(n)))
#      define __PACKED_STRUCT __attribute__((packed))
#      define __PRINTF_FORMAT(fmt, args) __attribute__((format(printf, fmt, args)))

#      if ((__clang_major__ > 3) || ((__clang_major__ == 3) && (__clang_minor__ >= 0)))
#        define __OPTIMIZE_O0 __attribute__((optimize("O0"))) /**< No optimization */
#        define __OPTIMIZE_O1 __attribute__((optimize("O1"))) /**< Optimize for size */
#        define __OPTIMIZE_O2 __attribute__((optimize("O2"))) /**< Optimize for speed */
#        define __OPTIMIZE_O3 __attribute__((optimize("O3"))) /**< Aggressive optimization */
#        define __OPTIMIZE_OG __attribute__((optimize("OG"))) /**< Optimize for debugging */
#      endif /* CLANG >= 3.0 */

#      if ((__clang_major__ > 11) || ((__clang_major__ == 11) && (__clang_minor__ >= 0)))
#        define __THREAD_LOCAL _Thread_local
#      endif /* CLANG >= 11.0.0 */

#      define __NULL (void *)0
#      define INTERRUPT_FUNC 
#      error "Unimplemented compiler configurations yet"
#    endif /* __clang__ */
/** @} */

#  else
#    error "Unsupported compiler configuration"
#  endif

#endif 
#endif
#endif /* COMPILER_USED */

/** @} */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_COMPILER_H__ */