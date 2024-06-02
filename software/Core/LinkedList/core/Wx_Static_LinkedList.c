/**
 * @file Wx_Static_LinkedList.c
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
#include "Wx_Static_LinkedList.h"

#if defined(WIN32) || defined(__GNUC__)
#include <stdio.h>
#endif

/**
 * ===============================================================================================
 *   > Private Macros
 * ===============================================================================================
 */

#if defined(WIN32) || defined(__GNUC__)
#define LOG_INFO 0
#define LOG_ERROR 1
#define LOG_WARN 2
#define LOG_CRITICAL 3
#define LOG__(LLEVEL, STR_) __LinkedListsLog(LLEVEL, (_WX_CONST WX_U8P)STR_)
#else
#define LOG__(LLEVEL, STR_)
#endif

/**
 * @brief Limit the physical node pool size based on a given virtual node pool size.
 *
 * This macro ensures that the physical node pool size does not exceed 255u.
 *
 * @param VIRTUAL_NODE_POOL_SIZE_ The virtual node pool size.
 * @return The limited physical node pool size.
 */
#define PHYSICAL_NODE_POOL_SIZE(VIRTUAL_NODE_POOL_SIZE_)                                           \
    (((VIRTUAL_NODE_POOL_SIZE_) > ((WX_U8)(255u))) ? 255u : (VIRTUAL_NODE_POOL_SIZE_))

/**
 * @brief Limit the physical list pool size based on a given virtual list pool size.
 *
 * This macro ensures that the physical list pool size does not exceed 255u.
 *
 * @param VIRTUAL_LIST_POOL_SIZE_ The virtual list pool size.
 * @return The limited physical list pool size.
 */
#define PHYSICAL_LIST_POOL_SIZE(VIRTUAL_LIST_POOL_SIZE_)                                           \
    (((VIRTUAL_LIST_POOL_SIZE_) > ((WX_U8)(255u))) ? 255u : (VIRTUAL_LIST_POOL_SIZE_))

/**
 * ===============================================================================================
 *   > Private Datatypes
 * ===============================================================================================
 */

/**
 * @brief
 *
 */
typedef struct Node Wx_Node_t;

/**
 * @brief
 *
 */
typedef enum NodeErrorCode Wx_En_NodeErrorCode_t;

/**
 * ===============================================================================================
 *   > Private Structs
 * ===============================================================================================
 */

/**
 * @brief
 *
 */
struct Node {
    void *data_;
};

/**
 * @brief Singly Linked List Structure
 *
 */
struct Wx_Static_SLinkedList {
    Wx_Node_t *head_;
    WX_U32 size_;
};

/**
 * @brief Doubly Linked List Structure
 *
 */
struct Wx_Static_DLinkedList {
    /* Statically allocated node pool */
    Wx_Node_t npool_[PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE)];
    WX_U16 tidx_;
    WX_U16 start_;
    WX_U16 end_;
    WX_U32 size_;
};

/**
 * ===============================================================================================
 *   > Private Global Variables (Localized Global)
 * ===============================================================================================
 */

/**
 * @brief Dynamic Linked List Pool (Statically)
 *
 */
_WX_STATIC Wx_Static_DLinkedList_t g_Dpool[PHYSICAL_LIST_POOL_SIZE(LIST_POOL_SIZE)];
/**
 * @brief
 *
 */
_WX_STATIC WX_U16 g_Dpool_counter = 0;

/**
 * ===============================================================================================
 *   > Private Function Declaration
 * ===============================================================================================
 */

#if defined(WIN32) || defined(__GNUC__)
/**
 * @brief Function to log the
 *
 * @param log_level
 * @param string
 * @return _WX_NORETURN
 */
_WX_FORCE_INLINE _WX_STATIC 
_WX_NORETURN __LinkedListsLog(WX_U8 log_level, _WX_CONST WX_U8 *string);
#endif

/**
 * ===============================================================================================
 *   > Private Function Implementation
 * ===============================================================================================
 */

#if defined(WIN32) || defined(__GNUC__)
_WX_NORETURN __LinkedListsLog(WX_U8 log_level, _WX_CONST WX_U8 *string) {
    switch (log_level) {
    case LOG_INFO:
        fprintf(stdout, "LinkedList - [INFO]: %s\n", string);
        break;
    case LOG_ERROR:
        fprintf(stderr, "LinkedList - [ERROR]: %s\n", string);
        break;
    case LOG_WARN:
        fprintf(stdout, "LinkedList - [WARNING]: %s\n", string);
        break;
    case LOG_CRITICAL:
        fprintf(stderr, "LinkedList - [CRITICAL]: %s\n", string);
        break;
    default:
        break;
    }
}
#endif

/**
 * ===============================================================================================
 *   > Public Function Implementation
 * ===============================================================================================
 */

/**
 * @brief Function to revive a passed Instance
 *
 * @param EmptyInstance
 * @return Wx_Static_En_LinkedListErrorCode_t
 *
 * @todo Make it more dynamic and friendly - making dynamic pool allocator for dynamic usage.
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetInstance(Wx_Static_DLinkedList_t **EmptyInstance) {
    if ((_WX_NULL == EmptyInstance) || (_WX_NULL != (*EmptyInstance))) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    if ((g_Dpool_counter >= PHYSICAL_LIST_POOL_SIZE(LIST_POOL_SIZE))) {
        return WX_E_LINKEDLIST_OUT_OF_MEMORY;
    }

    /* Get pool memory instance */
    (*EmptyInstance) = (Wx_Static_DLinkedList_t *)&g_Dpool[g_Dpool_counter];

    WX_U16 i = 0;
    for (i = 0; (i < PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE)); ++i) {
        (*EmptyInstance)->npool_[i].data_ = _WX_NULL;
    }

    (*EmptyInstance)->size_ = 0;
    (*EmptyInstance)->tidx_ = 0;
    (*EmptyInstance)->start_ = 0;
    (*EmptyInstance)->end_ = 0;

    g_Dpool_counter++;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Insert an Element at the Beginning of the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_InsertFront(Wx_Static_DLinkedList_t **Instance, _WX_CONST void *Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    if (((*Instance)->tidx_ >= PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE))) {
        return WX_E_LINKEDLIST_OVERFLOW;
    }

    (*Instance)->npool_[(*Instance)->tidx_].data_ = (void *)Data;

    (*Instance)->end_ = (*Instance)->tidx_;
    (*Instance)->tidx_++;
    (*Instance)->size_++;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Remove the First Element from the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_RemoveFront(Wx_Static_DLinkedList_t **Instance, void **Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    if (((*Instance)->tidx_ >= PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE))) {
        (*Instance)->end_ = 0;
        (*Instance)->tidx_ = 0;
        (*Instance)->size_ = 0;
    }

    *Data = (*Instance)->npool_[(*Instance)->end_].data_;
    (*Instance)->npool_[(*Instance)->end_].data_ = _WX_NULL;

    (*Instance)->end_--;
    (*Instance)->tidx_--;
    (*Instance)->size_--;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Insert an Element at the End of the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_InsertBack(Wx_Static_DLinkedList_t **Instance, _WX_CONST void *Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    if ((0 == (*Instance)->size_)) {
        (*Instance)->npool_[(*Instance)->tidx_].data_ = (void *)Data;
    } else {
        ;
    }

    (*Instance)->end_ = (*Instance)->tidx_;
    (*Instance)->tidx_++;
    (*Instance)->size_++;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Remove the Last Element from the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_RemoveBack(Wx_Static_DLinkedList_t **Instance, void **Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    (void)Data;
    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Access the Data of the First Element in the Linked List
 *
 * @param Instance
 * @param Data
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetFront(_WX_CONST Wx_Static_DLinkedList_t *Instance, void **Data) {
    if ((_WX_NULL == Instance)) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    *Data = (void *)Instance->npool_[Instance->end_].data_;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Access the Data of the Last Element in the Linked List
 *
 * @param Instance
 * @param Data
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetBack(_WX_CONST Wx_Static_DLinkedList_t *Instance, void **Data) {
    if ((_WX_NULL == Instance)) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    *Data = (void *)Instance->npool_[Instance->start_].data_;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Get the Size of the Linked List
 *
 * @param Instance
 * @param Size
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_GetSize(_WX_CONST Wx_Static_DLinkedList_t *Instance, WX_U32P Size) {
    if ((_WX_NULL == Instance)) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    *Size = Instance->size_;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Check if the Linked List is Empty
 *
 * @param Instance
 * @return WX_BOOL
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_IsEmpty(_WX_CONST Wx_Static_DLinkedList_t *Instance, WX_BOOL *IsEmptyFlag) {
    if ((_WX_NULL == Instance)) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    if ((Instance->size_ > 0)) {
        *IsEmptyFlag = WX_FALSE;
    } else {
        *IsEmptyFlag = WX_TRUE;
    }

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Remove All Elements from the Linked List
 *
 * @param Instance
 * @return Wx_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t Wx_Static_DLinkedList_Clear(Wx_Static_DLinkedList_t **Instance) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_LINKEDLIST_INVALID_ARG;
    }

    WX_U16 i = 0;
    for (i = 0; i < PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE); ++i) {
        (*Instance)->npool_[i].data_ = _WX_NULL;
    }

    (*Instance)->size_ = 0;
    (*Instance)->tidx_ = 0;
    (*Instance)->start_ = 0;
    (*Instance)->end_ = 0;

    return WX_E_LINKEDLIST_SUCCESS;
}

/**
 * @brief Function to Free Resources Allocated for the Linked List
 *
 * @param Instance
 * @return Wx_Static_En_LinkedListErrorCode_t
 */
Wx_Static_En_LinkedListErrorCode_t
Wx_Static_DLinkedList_Destroy(Wx_Static_DLinkedList_t **Instance) {
    Wx_Static_En_LinkedListErrorCode_t retval = Wx_Static_DLinkedList_Clear(Instance);
    if(WX_E_LINKEDLIST_SUCCESS != retval) {
        return retval;
    }
    g_Dpool_counter--;
    return WX_E_LINKEDLIST_SUCCESS;
}