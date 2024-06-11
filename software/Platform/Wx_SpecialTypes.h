/**
 * @file Wx_SpecialTypes.h
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
#if !defined(__WX_SPECIALTYPES_H__)
#define __WX_SPECIALTYPES_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */
/*----------------------------------------------------------------------------*/

/** 
 * @defgroup Special Data Types 
 * @{
 */
/** 
 * @brief 8-bit register structure with individual bit access.
 */
typedef union {
    struct {
        WX_U8 bit_0 : 1; /**< Bit 0 */
        WX_U8 bit_1 : 1; /**< Bit 1 */
        WX_U8 bit_2 : 1; /**< Bit 2 */
        WX_U8 bit_3 : 1; /**< Bit 3 */
        WX_U8 bit_4 : 1; /**< Bit 4 */
        WX_U8 bit_5 : 1; /**< Bit 5 */
        WX_U8 bit_6 : 1; /**< Bit 6 */
        WX_U8 bit_7 : 1; /**< Bit 7 */
    };
    WX_U8 byte; /**< Full byte access */
} WXReg8_t;

/** 
 * @brief 32-bit register structure with access to 8-bit segments and full 32-bit value.
 */
typedef union {
    struct {
        WXReg8_t byte_1; /**< Byte 1 */
        WXReg8_t byte_2; /**< Byte 2 */
        WXReg8_t byte_3; /**< Byte 3 */
        WXReg8_t byte_4; /**< Byte 4 */
    };
    WX_U32 word; /**< Full 32-bit access */
} WXReg32_t;

/** 
 * @brief 64-bit register structure with access to 8-bit segments, 32-bit segments and full 64-bit value.
 */
typedef union {
    struct {
        WXReg8_t byte_1; /**< Byte 1 */
        WXReg8_t byte_2; /**< Byte 2 */
        WXReg8_t byte_3; /**< Byte 3 */
        WXReg8_t byte_4; /**< Byte 4 */
        WXReg8_t byte_5; /**< Byte 5 */
        WXReg8_t byte_6; /**< Byte 6 */
        WXReg8_t byte_7; /**< Byte 7 */
        WXReg8_t byte_8; /**< Byte 8 */
    };
    struct {
        WXReg32_t word_1; /**< Word 1 */
        WXReg32_t word_2; /**< Word 2 */
    };
    WX_U64 dword; /**< Full 64-bit access */
} WXReg64_t;

/**
 * @brief 
 * 
 */
typedef struct {

} WXBigInt128_t;

/**
 * @brief 
 * 
 */
typedef struct {

} WXBigInt256_t;

/** @} */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_SPECIALTYPES_H__ */