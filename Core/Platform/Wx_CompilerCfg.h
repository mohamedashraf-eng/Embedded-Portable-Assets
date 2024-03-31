/**
 * @file Wx_CompilerCfg.h
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
#if !defined(__WX_COMPILERCFG_H__)
#define __WX_COMPILERCFG_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

/*----------------------------------------------------------------------------*/
/**
 * @brief 
 * @warning don't change these values.
 */
#define WX_COMPILER_GCC         (0u)
#define WX_COMPILER_MSVC        (1u)
#define WX_COMPILER_CLANG       (2u)
#define WX_COMPILER_ARM         (3u)
#define WX_COMPILER_GREENHILL   (4u)
#define WX_COMPILER_TRICORE     (5u)

/**
 * @brief Compiler selection
 * @arg
 *      WX_COMPILER_GCC
 *      WX_COMPILER_MSVC
 *      WX_COMPILER_CLANG
 *      WX_COMPILER_ARM
 */
#define COMPILER_USED       ( WX_COMPILER_GCC )
/*----------------------------------------------------------------------------*/

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_COMPILERCFG_H__ */