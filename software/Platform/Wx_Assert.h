/**
 * @file Wx_Assert.h
 * @author 
 * Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief 
 * Assertion and error handling macros and functions for Wx project.
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright 
 * Copyright (c) 2023
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

/*----------------------------------------------------------------------------*/
/** @brief Header guard */
#if !defined(__WX_ASSERT_H__)
#define __WX_ASSERT_H__

/** @brief C++ name mangling guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"

/*----------------------------------------------------------------------------*/

/**
 * @defgroup PublicMacros Public Macros
 * @{
 */

#if !defined(WX_ASSERT)
/**
 * @def WX_DEFINE_THIS_MODULE
 * @brief Define the name of the current module.
 * @param _NAME Name of the module.
 */
#define WX_DEFINE_THIS_MODULE(_NAME) \
    _WX_STATIC _CONST WX_U8 WX_this_module_[] = _NAME;

/**
 * @def WX_ASSERT_INCRIT
 * @brief Assert an expression in critical section.
 * @param _ID Identifier for the assertion.
 * @param _EXPR Expression to assert.
 */
#define WX_ASSERT_INCRIT(_ID, _EXPR) \
    ((_EXPR) ? (_WX_NULL) : WX_OnError(&WX_this_module_[0], (_ID)))

/**
 * @def WX_ERROR_INCRIT
 * @brief Trigger an error in critical section.
 * @param _ID Identifier for the error.
 */
#define WX_ERROR_INCRIT(_ID) \
    (WX_OnError(&WX_this_module_[0], (_ID)))

/**
 * @def WX_ASSERT_ID
 * @brief Assert an expression with an identifier.
 * @param _ID Identifier for the assertion.
 * @param _EXPR Expression to assert.
 */
#define WX_ASSERT_ID(_ID, _EXPR) do {   \
        ((_EXPR) ? (_WX_NULL) : WX_OnError(&WX_this_module_[0], (_ID))); \
    } while(0)

/**
 * @def WX_ERROR_ID
 * @brief Trigger an error with an identifier.
 * @param _ID Identifier for the error.
 */
#define WX_ERROR_ID(_ID) do { \
        (WX_OnError(&WX_this_module_[0], (_ID))); \
    } while(0)

#else

#define WX_DEFINE_THIS_MODULE(_NAME) _WX_NULL
#define WX_ASSERT_INCRIT(_ID, _EXPR) _WX_NULL
#define WX_ERROR_INCRIT(_ID) _WX_NULL
#define WX_ASSERT_ID(_ID, _EXPR) _WX_NULL
#define WX_ERROR_ID(_ID) _WX_NULL

#endif /* WX_ASSERT */

/**
 * @def WX_DEFINE_THIS_FILE
 * @brief Define the name of the current file.
 */
#define WX_DEFINE_THIS_FILE WX_DEFINE_THIS_MODULE(__FILE__)

/**
 * @def WX_ASSERT
 * @brief Assert an expression with the current line number as the identifier.
 * @param expr_ Expression to assert.
 */
#define WX_ASSERT(expr_) WX_ASSERT_ID(__LINE__, (expr_))

/**
 * @def WX_ERROR
 * @brief Trigger an error with the current line number as the identifier.
 */
#define WX_ERROR() WX_ERROR_ID(__LINE__)

/**
 * @def WX_REWXUIRE_ID
 * @brief Assert an expression with a specified identifier.
 * @param id_ Identifier for the assertion.
 * @param expr_ Expression to assert.
 */
#define WX_REWXUIRE_ID(id_, expr_) WX_ASSERT_ID((id_), (expr_))

/**
 * @def WX_REWXUIRE
 * @brief Assert an expression with the current line number as the identifier.
 * @param expr_ Expression to assert.
 */
#define WX_REWXUIRE(expr_) WX_ASSERT(expr_)

/**
 * @def WX_REWXUIRE_INCRIT
 * @brief Assert an expression in a critical section with a specified identifier.
 * @param id_ Identifier for the assertion.
 * @param expr_ Expression to assert.
 */
#define WX_REWXUIRE_INCRIT(id_, expr_) WX_ASSERT_INCRIT((id_), (expr_))

/**
 * @def WX_ENSURE_ID
 * @brief Ensure an expression with a specified identifier.
 * @param id_ Identifier for the assertion.
 * @param expr_ Expression to ensure.
 */
#define WX_ENSURE_ID(id_, expr_) WX_ASSERT_ID((id_), (expr_))

/**
 * @def WX_ENSURE
 * @brief Ensure an expression with the current line number as the identifier.
 * @param expr_ Expression to ensure.
 */
#define WX_ENSURE(expr_) WX_ASSERT(expr_)

/**
 * @def WX_ENSURE_INCRIT
 * @brief Ensure an expression in a critical section with a specified identifier.
 * @param id_ Identifier for the assertion.
 * @param expr_ Expression to ensure.
 */
#define WX_ENSURE_INCRIT(id_, expr_) WX_ASSERT_INCRIT((id_), (expr_))

/**
 * @def WX_INVARIANT_ID
 * @brief Invariant check for an expression with a specified identifier.
 * @param id_ Identifier for the assertion.
 * @param expr_ Expression to check.
 */
#define WX_INVARIANT_ID(id_, expr_) WX_ASSERT_ID((id_), (expr_))

/**
 * @def WX_INVARIANT
 * @brief Invariant check for an expression with the current line number as the identifier.
 * @param expr_ Expression to check.
 */
#define WX_INVARIANT(expr_) WX_ASSERT(expr_)

/**
 * @def WX_ASSERT_STATIC
 * @brief Static assert to check an expression at compile time.
 * @param expr_ Expression to check.
 */
#define WX_ASSERT_STATIC(expr_) extern char WX_static_assert_[(expr_) ? 1 : -1]

/** @} */

/*----------------------------------------------------------------------------*/

/**
 * @defgroup PublicFunctions Public Function Declarations
 * @{
 */

/**
 * @brief Handle an error.
 * @param pcArg_u8cModule Pointer to the module name.
 * @param Arg_u32cId Identifier for the error.
 */
_WX_FORCE_NORETURN WX_OnError(
    WX_U8 _WX_CONST * _WX_CONST pcArg_u8cModule, 
    WX_U32 _WX_CONST Arg_u32cId) {
    
    while(1) {
        ; /* HALT */
    }
}

/** @} */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_ASSERT_H__ */
