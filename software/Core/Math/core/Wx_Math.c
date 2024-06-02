/**
 * @file Wx_Math.c
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

#include "Wx_Math.h"

/**
 * ===============================================================================================
 *   > Private Macros
 * ===============================================================================================
 */

/**
 * ===============================================================================================
 *   > Private Enums
 * ===============================================================================================
 */

/**
 * ===============================================================================================
 *   > Private Datatypes
 * ===============================================================================================
 */

/**
 * ===============================================================================================
 *   > Private Function Declaration
 * ===============================================================================================
 */

/**
 * ===============================================================================================
 *   > Public Function Implementation
 * ===============================================================================================
 */

WX_U32 WX_MATH_U32Map(WX_U32 Arg_u32IN, WX_U32 Arg_u32InMin, WX_U32 Arg_u32InMax,
                      WX_U32 Arg_u32OutMin, WX_U32 Arg_u32OutMax) {
    return (WX_U32)((((Arg_u32IN - Arg_u32InMin) * (Arg_u32OutMax - Arg_u32OutMin)) /
                     (Arg_u32InMax - Arg_u32InMin)) +
                    Arg_u32OutMin);
}

WX_U32 WX_MATH_U32Constrain(WX_U32 Arg_u32IN, WX_U32 Arg_u32InMin, WX_U32 Arg_u32InMax) {
    if (Arg_u32IN < Arg_u32InMin) {
        return Arg_u32InMin;
    } else if (Arg_u32IN > Arg_u32InMax) {
        return Arg_u32InMax;
    } else {
        return Arg_u32IN;
    }
}

WX_U32 WX_MATH_U32Min(WX_MATH_ARRAY pArg_u32Array, WX_U32 Arg_u32ArrayLength) {
    WX_U32 Local_u32Min = pArg_u32Array[0];

    for (WX_U32 Local_u32Iterator = 1; Local_u32Iterator < Arg_u32ArrayLength; ++Local_u32Iterator) {
        if (pArg_u32Array[Local_u32Iterator] < Local_u32Min) {
            Local_u32Min = pArg_u32Array[Local_u32Iterator];
        }
    }
    return Local_u32Min;
}

WX_U32 WX_MATH_U32Max(WX_MATH_ARRAY pArg_u32Array, WX_U32 Arg_u32ArrayLength) {
    WX_U32 Local_u32Max = pArg_u32Array[0];

    for (WX_U32 Local_u32Iterator = 1; Local_u32Iterator < Arg_u32ArrayLength; ++Local_u32Iterator) {
        if (pArg_u32Array[Local_u32Iterator] > Local_u32Max) {
            Local_u32Max = pArg_u32Array[Local_u32Iterator];
        }
    }
    return Local_u32Max;
}