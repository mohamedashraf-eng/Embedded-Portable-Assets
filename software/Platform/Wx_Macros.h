/**
 * @file Wx_Macros.h
 * @author 
 * @brief A collection of utility macros for various purposes in C/C++.
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
/** @brief Header guard */
#if !defined(__WX_MACROS_H__)
#define __WX_MACROS_H__

#include "Wx_StdTypes.h"

/** @brief C++ name mangling guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */
/*----------------------------------------------------------------------------*/

/** 
 * @defgroup Type Checking Macros
 * @{
 */

/**
 * @brief Commonly used porting macro for determining the type of an expression.
 * 
 */
#define WX_TYPE_OF typeof

/**
 * @brief Determine the type of an expression at compile-time.
 * 
 * This macro checks the type of an expression to ensure it matches the expected type.
 * 
 * @param _TYPE The expected type.
 * @param _X The expression to check the type of.
 * @return int This macro returns 1 if the types match.
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
 * This macro computes the byte offset of a member within a struct type.
 * 
 * @param TYPE The type of the struct.
 * @param MEMBER The member whose offset is to be determined.
 * @return size_t The offset of the member within the struct.
 */
#define WX_OFFSET_OF(TYPE, MEMBER) ((WX_U32) &((TYPE *)0)->MEMBER)

/** @} */

/** 
 * @defgroup Container Macros
 * @{
 */

/**
 * @brief Get the pointer to the parent struct from a pointer to a member.
 * 
 * This macro computes the address of the parent struct given a pointer to
 * a member within the struct.
 * 
 * Memory Address     Content
 * 
 * 0x1000             +-------------------+
 *                    | ParentStruct      |
 *                    | member: X         |
 *                    | another_member: Y |
 *                    +-------------------+
 * 
 * 0x2000             +-------------------+
 *                    | memberPtr (0x1004)|  ----> Points to member at 0x1004
 *                    +-------------------+
 * The macro calculates the parent struct address by subtracting the offset
 * of the member from the member pointer.
 * 
 * @param _PTR Pointer to the member within the struct.
 * @param _TYPE Type of the parent struct.
 * @param _MEMBER Name of the member within the struct.
 * @return _PTR Pointer to the parent struct.
 */
#define WX_CONTAINER_OF(_PTR, _TYPE, _MEMBER) (__extension__((       \
    _WX_CONST WX_TYPE_OF( ((_TYPE*)0)->_MEMBER ) *__mptr = (_PTR);   \
    (_TYPE*)( (WX_U8*)__mptr - WX_OFFSET_OF(_TYPE, _MEMBER));        \
)) )

/** @} */

/** 
 * @defgroup String Conversion Macros
 * @{
 */

/**
 * @brief Helper macro to convert an expression to a string literal.
 * 
 * This macro is a helper macro used by the STRING macro to convert the given expression
 * into a string literal.
 * 
 * @param _EXPR The expression to be converted to a string.
 * @return char* The string representation of the expression.
 */
#define _WXSTRING(_EXPR) #_EXPR

/**
 * @brief Convert an expression to a string literal.
 * 
 * This macro converts the given expression into a string literal.
 * 
 * @param _EXPR The expression to be converted to a string.
 * @return char* The string representation of the expression.
 */
#define WX_STRING(_EXPR) _WXSTRING( (_EXPR) )

/** @} */

/** 
 * @defgroup Array Macros
 * @{
 */

/**
 * @brief Function-like macro to get the array dimensions.
 * 
 * This macro calculates the number of elements in an array.
 * 
 * @param _ARR The array to be calculated its dimension.
 * @return unsigned long The array dimension. 
 */
#define WX_DIM(_ARR) (WX_U32)(sizeof((_ARR)) / sizeof((_ARR)[0u]))

/** @} */

/** 
 * @defgroup Pointer Access Macros
 * @{
 */

/**
 * @brief Function-like macro to force access a pointer as container.
 * 
 * @details 
 *  This macro allows accessing a member of a structure through a generic pointer.
 *  It is especially useful in low-level programming where type-punning and generic 
 *  pointers are common.
 * 
 * Memory Address        Content
 * 
 * 0x1000           +-------------------+
 *                  | Data structure    |
 *                  | idata: X          |
 *                  | fdata: 6.5        |
 *                  +-------------------+
 * 
 * 0x2000           +-------------------+
 *                  | dataPtr (0x1000)  |  ----> Points to the Data structure at 0x1000
 *                  +-------------------+
 * 
 * 0x3000           +-------------------+
 *                  | genericPtr (0x2000)|  ----> Points to dataPtr at 0x2000
 *                  +-------------------+
 * The macro first casts the generic pointer to a double pointer of the given type, then
 * dereferences it twice to access the actual member of the structure.
 * 
 * @param _TYPE The type of the structure.
 * @param _MEMBER The member of the structure to access.
 * @param _PTR The pointer to a pointer to the structure.
 * @return The value of the member.
 */
#define WX_EXTRACT_MEMBER_FROM_PTR(_TYPE, _MEMBER, _PTR) (*(_TYPE**)((void**)&(_PTR)))->_MEMBER

/** @} */

/** 
 * @defgroup MinMax Macros
 * @{
 */

/**
 * @brief Branchless minimum macro.
 * 
 * @details 
 * The branchless minimum macro calculates the minimum value of two input parameters
 * without using any conditional statements. It is optimized for performance and can be
 * used in low-level programming.
 * 
 * @param _A The first input value.
 * @param _B The second input value.
 * @return The minimum value of _A and _B.
 */
#define _WX_BRANCHLESS_MIN(_A, _B)  (((_A)*((_A) < (_B))) + ((_B)*((_B) < (_A))))

/**
 * @brief Branchless maximum macro.
 * 
 * @details 
 * The branchless maximum macro calculates the maximum value of two input parameters
 * without using any conditional statements. It is optimized for performance and can be
 * used in low-level programming.
 * 
 * @param _A The first input value.
 * @param _B The second input value.
 * @return The maximum value of _A and _B.
 */
#define _WX_BRANCHLESS_MAX(_A, _B)  (((_A)*((_A) > (_B))) + ((_B)*((_B) > (_A))))

/**
 * @brief Minimum macro.
 * 
 * @details 
 * The minimum macro calculates the minimum value of two input parameters. It uses the
 * branchless minimum macro for optimized performance.
 * 
 * @param _A The first input value.
 * @param _B The second input value.
 * @return The minimum value of _A and _B.
 */
#define WX_MIN(_A, _B) _WX_BRANCHLESS_MIN(_A, _B) 

/**
 * @brief Maximum macro.
 * 
 * @details 
 * The maximum macro calculates the maximum value of two input parameters. It uses the
 * branchless maximum macro for optimized performance.
 * 
 * @param _A The first input value.
 * @param _B The second input value.
 * @return The maximum value of _A and _B.
 */
#define WX_MAX(_A, _B) _WX_BRANCHLESS_MAX(_A, _B)

/** @} */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_MACROS_H__ */
