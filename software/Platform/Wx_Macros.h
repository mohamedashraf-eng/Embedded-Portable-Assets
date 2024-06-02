/**
 * @file Wx_Macros.h
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
/*----------------------------------------------------------------------------*/
/** @brief header gurad */
#if !defined(__WX_MACROS_H__)
#define __WX_MACROS_H__

#include "Wx_StdTypes.h"

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */
/*----------------------------------------------------------------------------*/

/** 
 * @defgroup Functions Like Macros
 * @{
 */

/**
 * @brief Determine the type of an expression at compile-time.
 * 
 * @param _X The expression to determine the type of.
 * @return int This macro returns 1.
 */
#define WX_TYPECHECK(_TYPE, _X) (__extension__((       \
    _TYPE __dummy;                                     \
    WX_TYPE_OF(_X) __dummy2;                           \
    (void)(&__dummy == &__dummy2);                     \
    1;                                                 \
)) ) 

/**
 * @brief Get the offset of a member within a struct type.
 * 
 * @param TYPE The type of the struct.
 * @param MEMBER The member whose offset is to be determined.
 * @return size_t The offset of the member within the struct.
 */
#define WX_OFFSET_OF(TYPE, MEMBER) ((WX_U32) &((TYPE *)0)->MEMBER)

/** 
 * @brief Get the pointer to the parent struct from a pointer to a member.
 * 
 * This macro computes the address of the parent struct given a pointer to
 * a member within the struct.
 * 
 * @param _PTR Pointer to the member within the struct.
 * @param _TYPE Type of the parent struct.
 * @param _MEMBER Name of the member within the struct.
 * @return _TYPE* Pointer to the parent struct.
 */
#define WX_CONTAINER_OF(_PTR, _TYPE, _MEMBER) (__extension__((      \
    _WX_CONST WX_TYPE_OF( ((_TYPE*)0)->_MEMBER ) *__mptr = (_PTR);    \
    (_TYPE*)( (WX_U8*)__mptr - WX_OFFSET_OF(_TYPE, _MEMBER));       \
)) )

/**
 * @brief Helper macro to convert an expression to a string literal.
 * 
 * This macro is a helper macro used by STRING macro to convert the given expression
 * into a string literal.
 * 
 * @param _EXPR The expression to be converted to a string.
 * @return char* The string representation of the expression.
 */
#define _STRING(_EXPR) #_EXPR
/**
 * @brief Convert an expression to a string literal.
 * 
 * This macro converts the given expression into a string literal.
 * 
 * @param _EXPR The expression to be converted to a string.
 * @return char* The string representation of the expression.
 */
#define STRING(_EXPR) _STRING( (_EXPR) )

/**
 * @brief Function like macro to get the array dimensions.
 * @param _ARR The array to be calculated its dim.
 * @return unsigned long The array dimension. 
*/
#define WX_DIM(_ARR) (WX_U32)(sizeof((_ARR)) / sizeof((_ARR)[0u]))
/** @} */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_MACROS_H__ */