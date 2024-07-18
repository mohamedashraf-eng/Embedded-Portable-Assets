/**
 * @file Wx_Static_Node.h
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
#if !defined(__WX_NODE_H__)
#define __WX_NODE_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"
/*----------------------------------------------------------------------------*/

/**
 * ===============================================================================================
 *   > Public Macros
 * ===============================================================================================
 */


/**
 * ===============================================================================================
 *   > Public Enums
 * ===============================================================================================
 */

/**
 * @brief Error codes for the node layer
 *
 */
enum wx_node_status {
    WX_E_NODE_SUCCESS = 0,       /* Operation successful */
    WX_E_NODE_INVALID_ARG,       /* Invalid argument provided */
    WX_E_NODE_NULL,              /* Null pointer encountered */
    WX_E_NODE_OUT_OF_MEMORY,     /* Memory allocation failure */
    WX_E_NODE_EMPTY_CONTAINER,   /* Container is empty (e.g., trying to remove
                                       from an empty list) */
    WX_E_NODE_NOT_FOUND,         /* Element not found */
    WX_E_NODE_DUPLICATE,         /* Duplicate element found */
    WX_E_NODE_OVERFLOW,          /* Arithmetic overflow */
    WX_E_NODE_UNDERFLOW,         /* Arithmetic underflow */
    WX_E_NODE_UNSUPPORTED_OP,    /* Unsupported operation or feature */
    WX_E_NODE_FILE_NOT_FOUND,    /* File not found */
    WX_E_NODE_IO_ERROR,          /* Input/output error */
    WX_E_NODE_PERMISSION_DENIED, /* Permission denied */
    WX_E_NODE_UNKNOWN            /* Unknown or generic error */
};

/**
 * ===============================================================================================
 *   > Public Datatypes
 * ===============================================================================================
 */

/**
 * @brief
 * 
*/
typedef enum wx_node_status WXNodeStatus_t;

/**
 * @brief
 * 
*/
typedef struct wx_node WXNode_t;

/**
 * ===============================================================================================
 *   > Public Function Declaration
 * ===============================================================================================
 */


/*-------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_NODE_H__ */