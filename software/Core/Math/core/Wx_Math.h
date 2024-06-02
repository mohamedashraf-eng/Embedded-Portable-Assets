/**
 * @file Wx_Math.h
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-05
 *
 * @Argright Argright (c) 2023
 * @license MIT License
 *
 * @attention
 *
 * MIT License
 *
 * Argright (c) 2023, Mohamed Ashraf Wx
 *
 * Permission is hereby granted, free of charge, to any person obtaining a Arg
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, Arg, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above Argright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 **/
/** @brief header gurad */
#if !defined(__WX_MATH_H__)
#define __WX_MATH_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"

/**
 * ===============================================================================================
 *   > Public Macros
 * ===============================================================================================
 */

/**
 * ===============================================================================================
 *   > Public Enums
 * ===============================================================================================
 */

/**
 * ===============================================================================================
 *   > Public Datatypes
 * ===============================================================================================
 */

/**
 * @brief Typedef for a pointer to an array of signed 32-bit integers.
 */
typedef WX_S32* WX_MATH_ARRAY;

/**
 * ===============================================================================================
 *   > Public Function Declaration
 * ===============================================================================================
 */

/**
 * @brief Maps a given value from one range to another.
 *
 * @param Arg_u32IN Input value to be mapped.
 * @param Arg_u32InMin Minimum value of the input range.
 * @param Arg_u32InMax Maximum value of the input range.
 * @param Arg_u32OutMin Minimum value of the output range.
 * @param Arg_u32OutMax Maximum value of the output range.
 * @return Mapped value in the output range.
 */
WX_U32 WX_MATH_U32Map(WX_U32 Arg_u32IN, WX_U32 Arg_u32InMin, WX_U32 Arg_u32InMax,
                WX_U32 Arg_u32OutMin, WX_U32 Arg_u32OutMax);

/**
 * @brief Constrains a given value to be within a specified range.
 *
 * @param Arg_u32IN Input value to be constrained.
 * @param Arg_u32InMin Minimum value of the range.
 * @param Arg_u32InMax Maximum value of the range.
 * @return Constrained value.
 */
WX_U32 WX_MATH_U32Constrain(WX_U32 Arg_u32IN, WX_U32 Arg_u32InMin, WX_U32 Arg_u32InMax);

/**
 * @brief Finds the minimum value in an array of unsigned 32-bit integers.
 *
 * @param pArg_u32Array Pointer to the array of unsigned 32-bit integers.
 * @param Arg_u32ArrayLength Length of the array.
 * @return Minimum value in the array.
 */
WX_U32 WX_MATH_U32Min(WX_MATH_ARRAY pArg_u32Array, WX_U32 Arg_u32ArrayLength);

/**
 * @brief Finds the maximum value in an array of unsigned 32-bit integers.
 *
 * @param pArg_u32Array Pointer to the array of unsigned 32-bit integers.
 * @param Arg_u32ArrayLength Length of the array.
 * @return Maximum value in the array.
 */
WX_U32 WX_MATH_U32Max(WX_MATH_ARRAY pArg_u32Array, WX_U32 Arg_u32ArrayLength);

/*-------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_MATH_H__ */