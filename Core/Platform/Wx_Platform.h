/**
 * @file Wx_Platform.h
 * @brief Configuration file for platform settings
 * @author Mohamed Wx (mohamedashrafwx@gmail.com)
 * @version 0.1
 * @date 2023-10-05
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
#ifndef WX_PLATFORM_H
#define WX_PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif
/*----------------------------------------------------------------------------*/
/** @brief CPU Configurations */
/** @defgroup CPU_CFGS CPU Configurations @{ */

/** @defgroup CPU_TYPES CPU Type Configurations */
/** @{
 * @brief Processor type configurations
 */
/**
 * @brief 8 bit Type Processor
 * @implements CPU_TYPE_enumration
*/
#define WX_CPU_TYPE_8   8u
/**
 * @brief 16 bit Type Processor
 * @implements CPU_TYPE_enumration
*/
#define WX_CPU_TYPE_16  16u
/**
 * @brief 32 bit Type Processor
 * @implements CPU_TYPE_enumration
*/
#define WX_CPU_TYPE_32  32u
/**
 * @brief 64 bit Type Processor
 * @implements CPU_TYPE_enumration
*/
#define WX_CPU_TYPE_64  64u
/** @defgroup CPU Configurations */
/**
 * @brief Processor Type 
 * @implements CPU_TYPE_enumration
*/
#define WX_CPU_TYPE     WX_CPU_TYPE_64  /**< Set the processor type */
/** @} */

/** @defgroup BIT_ORDER Bit Order Configurations */
/** @{
 * @brief Bit order configurations
 */
/**
 * @brief MSB First Processor
 * @implements CPU_BIT_ORDER_enumration
*/
#define WX_MSB_FIRST    0u
/**
 * @brief LSB First Processor
 * @implements CPU_BIT_ORDER_enumration
*/
#define WX_LSB_FIRST    1u
/** 
 * @brief Bit order on register level 
 * @implements CPU_BIT_ORDER_enumration
*/
#define WX_BIT_ORDER    WX_LSB_FIRST   /**< Set the bit order on register level */
/** @} */

/** @defgroup BYTE_ORDER Byte Order Configurations */
/** @{
 * @brief Byte order configurations
 */
/**
 * @brief LOW_BYTE_FIRST Processor
 * @implements CPU_BYTE_ORDER_enumration
*/
#define WX_LOW_BYTE_FIRST   0u
/**
 * @brief HIGH_BYTE_FIRST Processor
 * @implements CPU_BYTE_ORDER_enumration
*/
#define WX_HIGH_BYTE_FIRST  1u
/**
 * @brief The byte order on memory level shall be indicated in the platform types header file using
 * 				the symbol CPU_BYTE_ORDER.
 * @implements CPU_BYTE_ORDER_enumration
*/
#define WX_BYTE_ORDER       WX_LOW_BYTE_FIRST  /**< Set the byte order on memory level */
/** @} */

/** @brief CPU Configurations */
#define WX_CPU_TYPE_CONFIG     WX_CPU_TYPE
#define WX_BIT_ORDER_CONFIG    WX_BIT_ORDER
#define WX_BYTE_ORDER_CONFIG   WX_BYTE_ORDER

/** @} */

/** @brief Boolean values */
/** @defgroup BOOL_VALUES Boolean Values @{ */
#if !defined(WX_TRUE)
#   define WX_TRUE  1u
#endif
#if !defined(WX_FALSE)
#   define WX_FALSE 0u
#endif
/** @} */
/*----------------------------------------------------------------------------*/

/** 
 * @defgroup Abstracted platform types 
 * @{
 */

/** @brief Concise Name */
#define WX_U8           _uint8
#define WX_U16          _uint16
#define WX_U32          _uint32
#define WX_U64          _uint64
#define WX_S8           _sint8
#define WX_S16          _sint16
#define WX_S32          _sint32
#define WX_S64          _sint64
#define WX_F32          _float32
#define WX_F64          _float64
#define WX_BOOL         _boolean

#define WX_U8P         _uint8ptr
#define WX_U16P        _uint16ptr
#define WX_U32P        _uint32ptr
#define WX_U64P        _uint64ptr
#define WX_S8P         _sint8ptr
#define WX_S16P        _sint16ptr 
#define WX_S32P        _sint32ptr
#define WX_S64P        _sint64ptr
#define WX_F32P        _float32ptr
#define WX_F64P        _float64ptr
#define WX_BOOLPTR     _boolptr

#define WX_U8_L        _uint8_least
#define WX_U16_L       _uint16_least
#define WX_U32_L       _uint32_least
#define WX_S8_F        _sint8_fast
#define WX_S16_F       _sint16_fast
#define WX_S32_F       _sint32_fast

/** @brief Full Name */
#define WX_UINT8           _uint8
#define WX_UINT16          _uint16
#define WX_UINT32          _uint32
#define WX_UINT64          _uint64
#define WX_INT8            _sint8
#define WX_INT16           _sint16
#define WX_INT32           _sint32
#define WX_INT64           _sint64
#define WX_FLOAT32         _float32
#define WX_FLOAT64         _float64

#define WX_UINT8PTR        _uint8ptr
#define WX_UINT16PTR       _uint16ptr
#define WX_UINT32PTR       _uint32ptr
#define WX_UINT64PTR       _uint64ptr
#define WX_INT8PTR         _sint8ptr
#define WX_INT16PTR        _sint16ptr 
#define WX_INT32PTR        _sint32ptr
#define WX_INT64PTR        _sint64ptr
#define WX_FLOAT32PTR      _float32ptr
#define WX_FLOAT64PTR      _float64ptr

#define WX_UINT8_LEAST     _uint8_least
#define WX_UINT16_LEAST    _uint16_least
#define WX_UINT32_LEAST    _uint32_least
#define WX_SINT8_FAST      _sint8_fast
#define WX_SINT16_FAST     _sint16_fast
#define WX_SINT32_FAST     _sint32_fast
/** @} */

/*----------------------------------------------------------------------------*/

/** 
 * @brief 
 * @defgroup
 * @{
*/

#if (CPU_TYPE == CPU_TYPE_64)

/**
 * @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long
 *        unsigned integer.
 * @implements boolean_type
 */
typedef unsigned char _boolean;

/** @defgroup Unsigned integers */
/**
 * @brief Unsigned 8-bit integer with a range of 0..255 (0x00..0xFF) - 8 bit
 * @implements uint8_type
 */
typedef unsigned char _uint8;
/**
 * @brief Unsigned 16-bit integer with a range of 0..65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_type
 */
typedef unsigned short _uint16;
/**
 * @brief Unsigned 32-bit integer with a range of 0..4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_type
 */
typedef unsigned long _uint32;
/**
 * @brief Unsigned 64-bit integer with a range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) - 64 bit
 * @implements uint64_type
 */
typedef unsigned long long _uint64;

/** @defgroup Signed integers */
/**
 * @brief Signed 8-bit integer with a range of -128..127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_type
 */
typedef signed char _sint8;
/**
 * @brief Signed 16-bit integer with a range of -32768..32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_type
 */
typedef signed short _sint16;
/**
 * @brief Signed 32-bit integer with a range of -2147483648..2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_type
 */
typedef signed long _sint32;
/**
 * @brief Signed 64-bit integer with a range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF) - 63 bit + 1 sign bit
 * @implements sint64_type
 */
typedef signed long long _sint64;

/** @defgroup unsigned least integers */
/**
 * @brief Unsigned 8-bit integer with a range of 0..255 (0x00..0xFF) - 8 bit
 * @implements uint8_least_type
 */
typedef unsigned long _uint8_least;
/**
 * @brief Unsigned 16-bit integer with a range of 0..65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_least_type
 */
typedef unsigned long _uint16_least;
/**
 * @brief Unsigned 32-bit integer with a range of 0..4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_least_type
 */
typedef unsigned long _uint32_least;

/** @defgroup Signed least integers */
/**
 * @brief Signed 8-bit integer with a range of -128..127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_fast_type
 */
typedef signed char _sint8_fast;
/**
 * @brief Signed 16-bit integer with a range of -32768..32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_fast_type
 */
typedef signed short _sint16_fast;
/**
 * @brief Signed 32-bit integer with a range of -2147483648..2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_fast_type
 */
typedef signed long _sint32_fast;

/** @defgroup Floating point types */
/**
 * @brief 32-bit long floating point data type
 * @implements float32_type
 * @details
 * 
 */
typedef float _float32;
/**
 * @brief 64-bit long floating point data type
 * @implements float64_type
 */
typedef double _float64;

#endif /* (CPU_TYPE == CPU_TYPE_64) */

#if (CPU_TYPE == CPU_TYPE_32)
/**
 * @brief The standard AUTOSAR type boolean shall be implemented on basis of and eight bits long
 * 				unsigned integer.
 * @implements boolean_type
 */
typedef unsigned char _boolean;
/** @defgroup Unsigned integers */
/**
 * @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 8 bit
 * @implements uint8_type
 */
typedef unsigned char _uint8;
/**
 * @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_type
 */
typedef unsigned short _uint16;
/**
 * @brief Unsigned 16 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_type
 */
typedef unsigned long _uint32;
/**
 * @brief Unsigned 16 bit integer with range of 0 ..+18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) - 64 bit
 * @implements uint64_type
 */
typedef unsigned long long _uint64;
/** @defgroup Signed integers */
/**
 * @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_type
 */
typedef signed char _sint8;
/**
 * @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_type
 */
typedef signed short _sint16;
/**
 * @brief Signed 16 bit integer with range of -2147483648 ..+2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_type
 */
typedef signed long _sint32;
/**
 * @brief Signed 16 bit integer with range of -9223372036854775808 ..+9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF) - 63 bit + 1 sign bit
 * @implements sint64_type
 */
typedef signed long long _sint64;
/** @defgroup unsigned least integers */
/**
 * @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 8 bit
 * @implements uint8_least_type
 */
typedef unsigned long _uint8_least;
/**
 * @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_least_type
 */
typedef unsigned long _uint16_least;
/**
 * @brief Unsigned 16 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_least_type
 */
typedef unsigned long _uint32_least;
/** @defgroup Signed least integers */
/**
 * @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_fast_type
 */
typedef signed char _sint8_fast;
/**
 * @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_fast_type
 */
typedef signed short _sint16_fast;
/**
 * @brief Signed 16 bit integer with range of -2147483648 ..+2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_fast_type
 */
typedef signed long _sint32_fast;
/** @defgroup Floating point types */
/**
 * @brief 32 bit long floating point data types
 * @implements float32_type
 * @details
 * 
 */
typedef float _float32;
/**
 * @brief 64 bit long floating point data types
 * @implements float64_type
 */
typedef double _float64;

#endif /* (CPU_TYPE == CPU_TYPE_32) */

#if (CPU_TYPE == CPU_TYPE_16)

/**
 * @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long
 *        unsigned integer.
 * @implements boolean_type
 */
typedef unsigned char _boolean;

/** @defgroup Unsigned integers */
/**
 * @brief Unsigned 8-bit integer with a range of 0..255 (0x00..0xFF) - 8 bit
 * @implements uint8_type
 */
typedef unsigned char _uint8;
/**
 * @brief Unsigned 16-bit integer with a range of 0..65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_type
 */
typedef unsigned short _uint16;
/**
 * @brief Unsigned 32-bit integer with a range of 0..4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_type
 */
typedef unsigned long _uint32;
/**
 * @brief Unsigned 64-bit integer with a range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) - 64 bit
 * @implements uint64_type
 */
typedef unsigned long long _uint64;

/** @defgroup Signed integers */
/**
 * @brief Signed 8-bit integer with a range of -128..127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_type
 */
typedef signed char _sint8;
/**
 * @brief Signed 16-bit integer with a range of -32768..32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_type
 */
typedef signed short _sint16;
/**
 * @brief Signed 32-bit integer with a range of -2147483648..2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_type
 */
typedef signed long _sint32;
/**
 * @brief Signed 64-bit integer with a range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF) - 63 bit + 1 sign bit
 * @implements sint64_type
 */
typedef signed long long _sint64;

/** @defgroup unsigned least integers */
/**
 * @brief Unsigned 8-bit integer with a range of 0..255 (0x00..0xFF) - 8 bit
 * @implements uint8_least_type
 */
typedef unsigned long _uint8_least;
/**
 * @brief Unsigned 16-bit integer with a range of 0..65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_least_type
 */
typedef unsigned long _uint16_least;
/**
 * @brief Unsigned 32-bit integer with a range of 0..4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_least_type
 */
typedef unsigned long _uint32_least;

/** @defgroup Signed least integers */
/**
 * @brief Signed 8-bit integer with a range of -128..127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_fast_type
 */
typedef signed char _sint8_fast;
/**
 * @brief Signed 16-bit integer with a range of -32768..32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_fast_type
 */
typedef signed short _sint16_fast;
/**
 * @brief Signed 32-bit integer with a range of -2147483648..2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_fast_type
 */
typedef signed long _sint32_fast;

/** @defgroup Floating point types */
/**
 * @brief 32-bit long floating point data type
 * @implements float32_type
 * @details
 * 
 */
typedef float _float32;
/**
 * @brief 64-bit long floating point data type
 * @implements float64_type
 */
typedef double _float64;

#endif /* (CPU_TYPE == CPU_TYPE_16) */

#if (CPU_TYPE == CPU_TYPE_8)

/**
 * @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long
 *        unsigned integer.
 * @implements boolean_type
 */
typedef unsigned char _boolean;

/** @defgroup Unsigned integers */
/**
 * @brief Unsigned 8-bit integer with a range of 0..255 (0x00..0xFF) - 8 bit
 * @implements uint8_type
 */
typedef unsigned char _uint8;
/**
 * @brief Unsigned 16-bit integer with a range of 0..65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_type
 */
typedef unsigned short _uint16;
/**
 * @brief Unsigned 32-bit integer with a range of 0..4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_type
 */
typedef unsigned long _uint32;
/**
 * @brief Unsigned 64-bit integer with a range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) - 64 bit
 * @implements uint64_type
 */
typedef unsigned long long _uint64;

/** @defgroup Signed integers */
/**
 * @brief Signed 8-bit integer with a range of -128..127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_type
 */
typedef signed char _sint8;
/**
 * @brief Signed 16-bit integer with a range of -32768..32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_type
 */
typedef signed short _sint16;
/**
 * @brief Signed 32-bit integer with a range of -2147483648..2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_type
 */
typedef signed long _sint32;
/**
 * @brief Signed 64-bit integer with a range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF) - 63 bit + 1 sign bit
 * @implements sint64_type
 */
typedef signed long long _sint64;

/** @defgroup unsigned least integers */
/**
 * @brief Unsigned 8-bit integer with a range of 0..255 (0x00..0xFF) - 8 bit
 * @implements uint8_least_type
 */
typedef unsigned long _uint8_least;
/**
 * @brief Unsigned 16-bit integer with a range of 0..65535 (0x0000..0xFFFF) - 16 bit
 * @implements uint16_least_type
 */
typedef unsigned long _uint16_least;
/**
 * @brief Unsigned 32-bit integer with a range of 0..4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
 * @implements uint32_least_type
 */
typedef unsigned long _uint32_least;

/** @defgroup Signed least integers */
/**
 * @brief Signed 8-bit integer with a range of -128..127 (0x80..0x7F) - 7 bit + 1 sign bit
 * @implements sint8_fast_type
 */
typedef signed char _sint8_fast;
/**
 * @brief Signed 16-bit integer with a range of -32768..32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
 * @implements sint16_fast_type
 */
typedef signed short _sint16_fast;
/**
 * @brief Signed 32-bit integer with a range of -2147483648..2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
 * @implements sint32_fast_type
 */
typedef signed long _sint32_fast;

/** @defgroup Floating point types */
/**
 * @brief 32-bit long floating point data type
 * @implements float32_type
 * @details
 * 
 */
typedef float _float32;
/**
 * @brief 64-bit long floating point data type
 * @implements float64_type
 */
typedef double _float64;

#endif /* (CPU_TYPE == CPU_TYPE_8) */


/** 
 * @brief Pointer defintions
 * 
*/
typedef _uint8*  _uint8ptr;
typedef _uint16* _uint16ptr;
typedef _uint32* _uint32ptr;
typedef _uint64* _uint64ptr;
typedef _sint8*  _sint8ptr;
typedef _sint16* _sint16ptr;
typedef _sint32* _sint32ptr;
typedef _sint64* _sint64ptr;
typedef _float32* _float32ptr;
typedef _float64* _float64ptr;
typedef _boolean* _boolptr;

/** @} */
/*----------------------------------------------------------------------------*/

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif // WX_PLATFORM_H
