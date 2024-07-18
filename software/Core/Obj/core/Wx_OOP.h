/**
 * @file Wx_OOP.h
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
#if !defined(__WX_OOP_H__)
#define __WX_OOP_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"
/*----------------------------------------------------------------------------*/

/**
 * ===============================================================================================
 *   > Public Exported Datatypes
 * ===============================================================================================
 */

extern void * __THAT__;

/**
 * ===============================================================================================
 *   > Public Macros
 * ===============================================================================================
 */

#define _(_OBJ) (__THAT__=(_OBJ), ((_OBJ)->class))
#define __(_OBJ) (__THAT__=(_OBJ), ((_OBJ)->class->super))

/*-------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_OOP_H__ */