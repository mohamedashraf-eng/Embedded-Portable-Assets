/**
 * @file Wx_OOLL.c
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
#include "Wx_OOLL.h"

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
#   define LOG__(LLEVEL, STR_) __LinkedListsLog(LLEVEL, (_WX_CONST WX_U8P)STR_)
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

/**
 * ===============================================================================================
 *   > Private Function Declaration
 * ===============================================================================================
 */

/**
 * @brief Function to log the
 *
 * @param log_level
 * @param string
 * @return _WX_NORETURN
 */
_WX_NORETURN __LinkedListsLog(WX_U8 log_level, _WX_CONST WX_U8 *string);

/**
 * ===============================================================================================
 *   > Private Function Implementation
 * ===============================================================================================
 */

_WX_NORETURN __LinkedListsLog(WX_U8 log_level, _WX_CONST WX_U8 *string) {
    switch (log_level) {
    case LOG_INFO:
        WXPRINT("LinkedList - [INFO]: %s\n", string);
        break;
    case LOG_ERROR:
        WXPRINT(stderr, "LinkedList - [ERROR]: %s\n", string);
        break;
    case LOG_WARN:
        WXPRINT("LinkedList - [WARNING]: %s\n", string);
        break;
    case LOG_CRITICAL:
        WXPRINT("LinkedList - [CRITICAL]: %s\n", string);
        break;
    default:
        break;
    }
}

/**
 * ===============================================================================================
 *   > Public Function Implementation
 * ===============================================================================================
 */