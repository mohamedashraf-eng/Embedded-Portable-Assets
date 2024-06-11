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
    };
    WX_U16 hword; /**< Full 16-bit access */
} WXReg16_t;

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
    struct {
        WXReg16_t hword_1; /**< Hword 1 */
        WXReg16_t hword_2; /**< Hword 2 */
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
 * @brief Placeholder for 128-bit big integer.
 */
typedef union {
    struct {
        WXReg64_t dword_1; /**< Dword 1 */
        WXReg64_t dword_2; /**< Dword 2 */
    };
    WX_U8 i128_[16]; /**< Full 128-bit access */
} WXBigInt128_t;

/** 
 * @brief Placeholder for 256-bit big integer.
 */
typedef union {
    struct {
        WXBigInt128_t i128_1; /**< I128 1 */
        WXBigInt128_t i128_2; /**< I128 2 */
    };
    WX_U8 i256_[32]; /**< Full 256-bit access */
} WXBigInt256_t;

/** 
 * @brief Placeholder for 512-bit big integer.
 */
typedef union {
    struct {
        WXBigInt256_t i256_1; /**< I128 1 */
        WXBigInt256_t i256_2; /**< I128 2 */
    };
    WX_U8 i512_[32]; /**< Full 512-bit access */
} WXBigInt512_t;

/** 
 * @brief Macros for defining register types.
 */
#define WX_RU8      WXReg8_t
#define WX_RU16     WXReg16_t
#define WX_RU32     WXReg32_t
#define WX_RU64     WXReg64_t

#define WX_RS8      WXReg8_t
#define WX_RS16     WXReg16_t
#define WX_RS32     WXReg32_t
#define WX_RS64     WXReg64_t

#if defined(__WRAP_PLATFORM_TYPES__)

#   if defined(WX_U8)
#      undef WX_U8
#      define WX_U8 WX_RU8
#   endif /* WX_U8 */

#   if defined(WX_U16)
#      undef WX_U16
#      define WX_U16 WX_RU16
#   endif /* WX_U16 */

#   if defined(WX_U32)
#      undef WX_U32
#      define WX_U32 WX_RU32
#   endif /* WX_U32 */

#   if defined(WX_U64)
#      undef WX_U64
#      define WX_U64 WX_RU64
#   endif /* WX_U64 */

#   if defined(WX_S8)
#      undef WX_S8
#      define WX_S8 WX_RS8
#   endif /* WX_S8 */

#   if defined(WX_S16)
#      undef WX_S16
#      define WX_S16 WX_RS16
#   endif /* WX_S16 */

#   if defined(WX_S32)
#      undef WX_S32
#      define WX_S32 WX_RS32
#   endif /* WX_S32 */

#   if defined(WX_S64)
#      undef WX_S64
#      define WX_S64 WX_RS64
#   endif /* WX_S64 */

#   if defined(WX_U8_L)
#      undef WX_U8_L
#      define WX_U8_L WX_RU8
#   endif /* WX_U8_L */

#   if defined(WX_U16_L)
#      undef WX_U16_L
#      define WX_U16_L WX_RU16
#   endif /* WX_U16_L */

#   if defined(WX_U32_L)
#      undef WX_U32_L
#      define WX_U32_L WX_RU32
#   endif /* WX_U32_L */

#   if defined(WX_S8_F)
#      undef WX_S8_F
#      define WX_S8_F WX_RS8
#   endif /* WX_S8_F */

#   if defined(WX_S16_F)
#      undef WX_S16_F
#      define WX_S16_F WX_RS16
#   endif /* WX_S16_F */

#   if defined(WX_S32_F)
#      undef WX_S32_F
#      define WX_S32_F WX_RS32
#   endif /* WX_S32_F */

#endif /* __WRAP_PLATFORM_TYPES__ */

/** @} */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_SPECIALTYPES_H__ */