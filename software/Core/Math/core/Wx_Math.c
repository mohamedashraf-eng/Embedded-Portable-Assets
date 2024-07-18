/**
 * @file Wx_Math.c
 * @brief Math utility functions for various operations.
 * @version 0.1
 * @date 2023-10-05
 * 
 * @Argright Copyright (c) 2023
 * @license MIT License
 * 
 * @attention
 * 
 * MIT License
 * 
 * Argright (c) 2023, Mohamed Ashraf Wx
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

#include "Wx_Math.h"

/**
 * ===============================================================================================
 *   > Private Macros
 * ===============================================================================================
 */
// Add any private macros here if needed

/**
 * ===============================================================================================
 *   > Private Enums
 * ===============================================================================================
 */
// Add any private enums here if needed

/**
 * ===============================================================================================
 *   > Private Datatypes
 * ===============================================================================================
 */
// Add any private datatypes here if needed

/**
 * ===============================================================================================
 *   > Private Function Declaration
 * ===============================================================================================
 */
// Add any private function declarations here if needed

/**
 * ===============================================================================================
 *   > Public Function Implementation
 * ===============================================================================================
 */

/**
 * @brief Maps a value from one range to another.
 * 
 * This function takes a value and maps it from one range to another. It is useful in cases
 * where you need to translate a value from a known range to a target range.
 * 
 * @param Arg_u32IN Input value to be mapped.
 * @param Arg_u32InMin Minimum value of the input range.
 * @param Arg_u32InMax Maximum value of the input range.
 * @param Arg_u32OutMin Minimum value of the output range.
 * @param Arg_u32OutMax Maximum value of the output range.
 * @return WX_U32 Mapped output value.
 * 
 * If you have a value `5` in the range `0` to `10`, and you want to map it to a range of `0` to `100`:
 * 
 * WX_U32 result = WX_MATH_U32Map(5, 0, 10, 0, 100); // result will be 50
 * 
 */
WX_U32 WX_MATH_U32Map(WX_U32 Arg_u32IN, WX_U32 Arg_u32InMin, WX_U32 Arg_u32InMax,
                      WX_U32 Arg_u32OutMin, WX_U32 Arg_u32OutMax) {
    return (WX_U32)((((Arg_u32IN - Arg_u32InMin) * (Arg_u32OutMax - Arg_u32OutMin)) /
                     (Arg_u32InMax - Arg_u32InMin)) +
                    Arg_u32OutMin);
}

/**
 * @brief Constrains a value within a specified range.
 * 
 * This function ensures that a value falls within a specified minimum and maximum range. 
 * If the value is less than the minimum, it returns the minimum. If the value is greater 
 * than the maximum, it returns the maximum. Otherwise, it returns the value itself.
 * 
 * @param Arg_u32IN Input value to be constrained.
 * @param Arg_u32InMin Minimum value of the range.
 * @param Arg_u32InMax Maximum value of the range.
 * @return WX_U32 Constrained value.
 * 
 *
 * WX_U32 result = WX_MATH_U32Constrain(15, 0, 10); // result will be 10
 * WX_U32 result2 = WX_MATH_U32Constrain(-5, 0, 10); // result2 will be 0
 * WX_U32 result3 = WX_MATH_U32Constrain(5, 0, 10); // result3 will be 5
 * 
 */
WX_U32 WX_MATH_U32Constrain(WX_U32 Arg_u32IN, WX_U32 Arg_u32InMin, WX_U32 Arg_u32InMax) {
    if (Arg_u32IN < Arg_u32InMin) {
        return Arg_u32InMin;
    } else if (Arg_u32IN > Arg_u32InMax) {
        return Arg_u32InMax;
    } else {
        return Arg_u32IN;
    }
}

/**
 * @brief Finds the minimum value in an array.
 * 
 * This function iterates through an array and finds the minimum value. It is useful 
 * for identifying the smallest value in a dataset.
 * 
 * @param pArg_u32Array Pointer to the array.
 * @param Arg_u32ArrayLength Length of the array.
 * @return WX_U32 Minimum value found in the array.
 * 
 * 
 * WX_U32 arr[] = {3, 1, 4, 1, 5};
 * WX_U32 minVal = WX_MATH_U32Min(arr, 5); // minVal will be 1
 * 
 */
WX_U32 WX_MATH_U32Min(WX_MATH_ARRAY pArg_u32Array, WX_U32 Arg_u32ArrayLength) {
    WX_U32 Local_u32Min = pArg_u32Array[0];

    for (WX_U32 Local_u32Iterator = 1; Local_u32Iterator < Arg_u32ArrayLength; ++Local_u32Iterator) {
        if (pArg_u32Array[Local_u32Iterator] < Local_u32Min) {
            Local_u32Min = pArg_u32Array[Local_u32Iterator];
        }
    }
    return Local_u32Min;
}

/**
 * @brief Finds the maximum value in an array.
 * 
 * This function iterates through an array and finds the maximum value. It is useful 
 * for identifying the largest value in a dataset.
 * 
 * @param pArg_u32Array Pointer to the array.
 * @param Arg_u32ArrayLength Length of the array.
 * @return WX_U32 Maximum value found in the array.
 *  
 * 
 * WX_U32 arr[] = {3, 1, 4, 1, 5};
 * WX_U32 maxVal = WX_MATH_U32Max(arr, 5); // maxVal will be 5
 * 
 */
WX_U32 WX_MATH_U32Max(WX_MATH_ARRAY pArg_u32Array, WX_U32 Arg_u32ArrayLength) {
    WX_U32 Local_u32Max = pArg_u32Array[0];

    for (WX_U32 Local_u32Iterator = 1; Local_u32Iterator < Arg_u32ArrayLength; ++Local_u32Iterator) {
        if (pArg_u32Array[Local_u32Iterator] > Local_u32Max) {
            Local_u32Max = pArg_u32Array[Local_u32Iterator];
        }
    }
    return Local_u32Max;
}
