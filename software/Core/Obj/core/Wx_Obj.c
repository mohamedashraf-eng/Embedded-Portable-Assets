/**
 * @file Wx_Obj.c
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
#include "Wx_Obj.h"

WX_DEFINE_THIS_FILE;

/**
 * ===============================================================================================
 *   > Private Macros
 * ===============================================================================================
 */

#if defined(LOG)
#   define LOG_INFO 0
#   define LOG_ERROR 1
#   define LOG_WARN 2
#   define LOG_CRITICAL 3
#   define LOG__(LLEVEL, STR_) __ObjLog(LLEVEL, (_WX_CONST WX_U8P)STR_)
#else
#   define LOG__(LLEVEL, STR_)
#endif /* LOG */

/**
 * ===============================================================================================
 *   > Private Datatypes
 * ===============================================================================================
 */


/**
 * ===============================================================================================
 *   > Private Structs
 * ===============================================================================================
 */

/**
 * ===============================================================================================
 *   > Private Global Variables (Localized Global)
 * ===============================================================================================
 */

_WX_STATIC WXObjClass_t global_tClass;

/**
 * ===============================================================================================
 *   > Private Function Declaration
 * ===============================================================================================
 */

#if defined(LOG)
/**
 * @brief Function to log the
 *
 * @param log_level
 * @param string
 * @return _WX_NORETURN
 */
_WX_STATIC _WX_NORETURN __ObjLog(WX_U8 log_level, _WX_CONST WX_U8 *string);
#endif /* LOG */

/**
 * @brief 
 * 
 * @param pArg_u8Msg 
 * @return None 
 */
_WX_STATIC _WX_NORETURN Debug(WX_U8P pArg_u8Msg);

/**
 * @brief 
 * 
 * @return None 
 */
_WX_STATIC _WX_NORETURN Delete(_WX_NOARG);

/**
 * @brief 
 * 
 * @param ObjX 
 * @param ObjY 
 * @return _WX_STATIC 
 */
_WX_STATIC WX_BOOL Differ(_WX_CONST void* ObjX, _WX_CONST void* ObjY);

/**
 * ===============================================================================================
 *   > Private Function Implementation
 * ===============================================================================================
 */

#if defined(LOG)
_WX_STATIC _WX_NORETURN __ObjLog(WX_U8 log_level, _WX_CONST WX_U8 *string) {
    switch (log_level) {
    case LOG_INFO:
        WXPRINT("Obj - [INFO]: %s\n", string);
        break;
    case LOG_ERROR:
        WXPRINT(stderr, "Obj - [ERROR]: %s\n", string);
        break;
    case LOG_WARN:
        WXPRINT("Obj - [WARNING]: %s\n", string);
        break;
    case LOG_CRITICAL:
        WXPRINT("Obj - [CRITICAL]: %s\n", string);
        break;
    default:
        break;
    }
}
#endif /* LOG */

/**
 * @brief 
 * 
 * @param pArg_u8Msg 
 * @return _WX_NORETURN 
 */
_WX_STATIC _WX_NORETURN Debug(WX_U8P pArg_u8Msg) {
    LOG__(LOG_INFO, "debug object");

    WX_ASSERT(pArg_u8Msg != _WX_NULL);
    WXObj_t* this = __THAT__;
    WXPRINT("[%s]: %s\r\n", this->name, pArg_u8Msg);
}

/**
 * @brief 
 * 
 * @return _WX_NORETURN 
 */
_WX_STATIC _WX_NORETURN Delete(_WX_NOARG) {
    LOG__(LOG_INFO, "Delete object");

    WXObj_t* this = __THAT__;
    WXFREE(this);
}

/**
 * @brief Checks if the object is equal to other object.
 * 
 * @param ObjX 
 * @param ObjY 
 * @return WX_BOOL 
 */
_WX_STATIC WX_BOOL Differ(_WX_CONST void* ObjX, _WX_CONST void* ObjY) {
    LOG__(LOG_INFO, "Differentiate between this object and other object");

    WXObj_t* this = __THAT__;
    
    return (ObjX == ObjY);
}

/**
 * ===============================================================================================
 *   > Public Function Implementation
 * ===============================================================================================
 */

/**
 * @brief 
 * 
 * @param pArg_tClass 
 * @return WXObjClass_t* 
 */
WXObjClass_t* WXObjClass_Init(WXObjClass_t* pArg_tClass) {
    LOG__(LOG_INFO, "Init object class");

    pArg_tClass->super = _WX_NULL;
    pArg_tClass->debug = Debug;
    pArg_tClass->delete = Delete;
    pArg_tClass->differ = Differ;
    
    return &global_tClass;
}

/**
 * @brief 
 * 
 * @param pArg_tThis 
 * @param pArG_u8Name 
 * @return WXObj_t* 
 */
WXObj_t* WXObj_New(WXObj_t* pArg_tThis, WX_U8P pArG_u8Name) {
    LOG__(LOG_INFO, "Create new object");

    if (_WX_NULL == pArg_tThis) {
        WX_ASSERT(_WX_NULL != (pArg_tThis = WXCALLOC(WXObj_t, 1u, sizeof(WXObj_t))));
    }

    pArg_tThis->class = WXObjClass_Init(&global_tClass);
    pArg_tThis->name = pArG_u8Name;
    
    return pArg_tThis;
}