/**
 * @file Wx_Static_LinkedList.h
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
#if !defined(__WX_STATIC_LINKEDLIST_H__)
#define __WX_STATIC_LINKEDLIST_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"

/**
 * ===============================================================================================
 *   > Public Macros
 * ===============================================================================================
 */

/**
 * @brief Initialize a doubly linked list.
 * @param Name_ Name of the doubly linked list.
 */
#define Wx_Static_DLinkedList_DeclareInstance_(Name_) Wx_Static_DLinkedList_t *Name_ = NULL

/**
 * @brief Get the data from a pointer of a specified type.
 * @param TYPE_ The type of the data.
 * @param EXP_ The expression representing the pointer to the data.
 * @return The data of the specified type.
 */
#define Wx_Static_DLinkedList_GetDataStored_(TYPE_, EXP_) (*(TYPE_ *)(EXP_))

/**
 * @brief
 *
 * @defgroup User Controlled Macros Configurations
 * @{
 */

/**
 * @brief
 *
 * @note Use the size carfully for better memory efficency
 */
#define NODE_POOL_SIZE ((WX_U8)(20))

/**
 * @brief
 *
 * @note Use the size carfully for better memory efficency
 */
#define LIST_POOL_SIZE ((WX_U8)(1))

/** @} */

/**
 * ===============================================================================================
 *   > Public Enums
 * ===============================================================================================
 */

/**
 * @brief Error codes for the linked list layer
 *
 */
enum Wx_Static_LinkedListErrorCode {
    WX_E_LINKEDLIST_SUCCESS = 0,       /* Operation successful */
    WX_E_LINKEDLIST_INVALID_ARG,       /* Invalid argument provided */
    WX_E_LINKEDLIST_NULL,              /* Null pointer encountered */
    WX_E_LINKEDLIST_OUT_OF_MEMORY,     /* Memory allocation failure */
    WX_E_LINKEDLIST_EMPTY_CONTAINER,   /* Container is empty (e.g., trying to remove
                                       from an empty list) */
    WX_E_LINKEDLIST_NOT_FOUND,         /* Element not found */
    WX_E_LINKEDLIST_DUPLICATE,         /* Duplicate element found */
    WX_E_LINKEDLIST_OVERFLOW,          /* Arithmetic overflow */
    WX_E_LINKEDLIST_UNDERFLOW,         /* Arithmetic underflow */
    WX_E_LINKEDLIST_UNSUPPORTED_OP,    /* Unsupported operation or feature */
    WX_E_LINKEDLIST_FILE_NOT_FOUND,    /* File not found */
    WX_E_LINKEDLIST_IO_ERROR,          /* Input/output error */
    WX_E_LINKEDLIST_PERMISSION_DENIED, /* Permission denied */
    WX_E_LINKEDLIST_UNKNOWN            /* Unknown or generic error */
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
typedef struct Wx_Static_SLinkedList SLinkedList_t;

/**
 * @brief
 *
 */
typedef struct Wx_Static_DLinkedList Wx_Static_DLinkedList_t;

/**
 * @brief
 *
 */
typedef enum Wx_Static_LinkedListErrorCode Wx_Static_En_LinkedListErrorCode_t;

/**
 * ===============================================================================================
 *   > Public Function Declaration
 * ===============================================================================================
 */

/**
 * @brief Function to revive a passed Instance
 *
 * @param EmptyInstance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetInstance(Wx_Static_DLinkedList_t **EmptyInstance);

/**
 * @brief Function to Insert an Element at the Beginning of the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */

Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_InsertFront(Wx_Static_DLinkedList_t **Instance, _WX_CONST void *Data);

/**
 * @brief Function to Remove the First Element from the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_RemoveFront(Wx_Static_DLinkedList_t **Instance, void **Data);

/**
 * @brief Function to Insert an Element at the End of the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_InsertBack(Wx_Static_DLinkedList_t **Instance, _WX_CONST void *Data);

/**
 * @brief Function to Remove the Last Element from the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_RemoveBack(Wx_Static_DLinkedList_t **Instance, void **Data);

/**
 * @brief Function to Access the Data of the First Element in the Linked List
 *
 * @param Instance
 * @param Data
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetFront(_WX_CONST Wx_Static_DLinkedList_t *Instance, void **Data);

/**
 * @brief Function to Access the Data of the Last Element in the Linked List
 *
 * @param Instance
 * @param Data
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetBack(_WX_CONST Wx_Static_DLinkedList_t *Instance, void **Data);

/**
 * @brief Function to Get the Size of the Linked List
 *
 * @param Instance
 * @param Size
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetSize(_WX_CONST Wx_Static_DLinkedList_t *Instance, WX_U32P Size);

/**
 * @brief Function to Check if the Linked List is Empty
 *
 * @param Instance
 * @return WX_BOOL
 */

Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_IsEmpty(_WX_CONST Wx_Static_DLinkedList_t *Instance, WX_BOOL *IsEmptyFlag);

/**
 * @brief Function to Remove All Elements from the Linked List
 *
 * @param Instance
 * @return Wx_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t Wx_Static_DLinkedList_Clear(Wx_Static_DLinkedList_t **Instance);

/**
 * @brief Function to Free Resources Allocated for the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_Destroy(Wx_Static_DLinkedList_t **Instance);

/*-------------------------------------*/
/**
 * @brief
 * @defgroup User Friendly Interface
 *
 * @{
 */

/**     @defgroup Helpers @{ */
#define WX_DEFINE_A_DLIST(wx_q) Wx_Static_DLinkedList_DeclareInstance_((wx_q))
#define WX_EXTRACT_DATA_FROM_DLIST(TYPE_, EXP_) Wx_Static_DLinkedList_GetDataStored_(TYPE_, EXP_)
/**     @} */

/**     @defgroup Main Library Interface @{ */
#define WX_DLIST_CTOR(wx_list_ptr)                                                                 \
    Wx_Static_DLinkedList_GetInstance((Wx_Static_DLinkedList_t **)(&(wx_list_ptr)))
#define WX_DLIST_APPEND(wx_list_ptr, element)                                                      \
    Wx_Static_DLinkedList_Append((Wx_Static_DLinkedList_t **)(&(wx_list_ptr)), (void *)(&(element)))
#define WX_DLIST_REMOVE_FRONT(wx_list_ptr, element)                                                \
    Wx_Static_DLinkedList_RemoveFront((Wx_Static_DLinkedList_t **)(&(wx_list_ptr)),                \
                                      (void **)(&(element)))
#define WX_DLIST_GET_FRONT(wx_list_ptr, element)                                                   \
    Wx_Static_DLinkedList_GetFront((_WX_CONST Wx_Static_DLinkedList_t *)(wx_list_ptr),               \
                                   (void **)(&(element)))
#define WX_DLIST_GET_TAIL(wx_list_ptr, element)                                                    \
    Wx_Static_DLinkedList_GetTail((_WX_CONST Wx_Static_DLinkedList_t *)(wx_list_ptr),                \
                                  (void **)(&(element)))
#define WX_DLIST_IS_EMPTY(wx_list_ptr, is_empty)                                                   \
    Wx_Static_DLinkedList_IsEmpty((_WX_CONST Wx_Static_DLinkedList_t *)(wx_list_ptr),                \
                                  (WX_BOOL *)(&(is_empty)))
#define WX_DLIST_GET_SIZE(wx_list_ptr, size)                                                       \
    Wx_Static_DLinkedList_GetSize((_WX_CONST Wx_Static_DLinkedList_t *)(wx_list_ptr),                \
                                  (WX_U16 *)(&(size)))
#define WX_DLIST_CLEAR(wx_list_ptr)                                                                \
    Wx_Static_DLinkedList_Clear((Wx_Static_DLinkedList_t *)(wx_list_ptr))
#define WX_DLIST_DTOR(wx_list_ptr)                                                                 \
    Wx_Static_DLinkedList_Destroy((Wx_Static_DLinkedList_t **)(&(wx_list_ptr)))
/**     @} */
/** @} */
/*-------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_STATIC_LINKEDLIST_H__ */