/**
 * @file Wx_Obj.h
 * @author 
 * Mohamed Wx (mohamedashrafwx@gmail.com)
 * @brief 
 * Header file for Wx_Obj class.
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright 
 * Copyright (c) 2023
 * @license 
 * MIT License
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
#if !defined(__WX_OBJ_H__)
#define __WX_OBJ_H__

/** @brief C++ name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"
#include "Wx_OOP.h"
/*----------------------------------------------------------------------------*/

/**
 * ===============================================================================================
 *   > Public Macros
 * ===============================================================================================
 */

/**
 * @brief Macro for defining member variables of WXObj.
 */
#define WXObj_MEMBERS \
    WX_U8P name;

/**
 * @brief Macro for defining methods of WXObj.
 */
#define WXObj_METHODS \
    _WX_NORETURN (*debug)(WX_U8P); \
    _WX_NORETURN (*delete)(_WX_NOARG); \
    WX_BOOL (*differ)(_WX_CONST void* ObjX, _WX_CONST void* ObjY);

/**
 * ===============================================================================================
 *   > Public Datatypes
 * ===============================================================================================
 */

/**
 * @brief Typedef for WXObj class structure.
 */
typedef struct wx_obj_class WXObjClass_t;

/**
 * @brief Typedef for WXObj structure.
 */
typedef struct wx_obj WXObj_t;

/**
 * ===============================================================================================
 *   > Public Structs
 * ===============================================================================================
 */

/**
 * @brief WXObj class structure.
 */
struct wx_obj_class {
    void* super;
    WXObj_METHODS
};

/**
 * @brief WXObj structure.
 */
struct wx_obj {
    WXObjClass_t* class;
    WXObj_MEMBERS
};

/**
 * ===============================================================================================
 *   > Public Function Declarations
 * ===============================================================================================
 */

/**
 * @brief Initializes the WXObj class.
 *
 * @param pArg_tClass Pointer to the WXObjClass_t structure.
 * @return WXObjClass_t* Pointer to the initialized WXObjClass_t structure.
 */
extern WXObjClass_t* WXObjClass_Init(WXObjClass_t* pArg_tClass);

/**
 * @brief Creates a new WXObj instance.
 *
 * @param pArg_tThis Pointer to the WXObj_t structure.
 * @param pArG_u8Name Pointer to the name of the WXObj instance.
 * @return WXObj_t* Pointer to the created WXObj_t instance.
 */
extern WXObj_t* WXObj_New(WXObj_t* pArg_tThis, WX_U8P pArG_u8Name);

/*-------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_OBJ_H__ */
