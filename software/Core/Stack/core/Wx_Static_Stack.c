/**
 * @file Wx_Static_Stack.c
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
#include "Wx_Static_Stack.h"

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
 * @brief Limit the physical stack pool size based on a given virtual stack pool size.
 *
 * This macro ensures that the physical stack pool size does not exceed 255u.
 *
 * @param VIRTUAL_STACK_POOL_SIZE_ The virtual STACK pool size.
 * @return The limited physical STACK pool size.
 */
#define PHYSICAL_STACK_POOL_SIZE(VIRTUAL_STACK_POOL_SIZE_)                                         \
    (((VIRTUAL_STACK_POOL_SIZE_) > ((WX_U8)(255u))) ? 255u : (VIRTUAL_STACK_POOL_SIZE_))

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
 * @brief Stack Structure
 *
 */
struct Wx_Static_Stack {
    /* Statically allocated node pool */
    Wx_Node_t npool_[PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE)];
    WX_U16 top_;
    WX_U16 bottom_;
    WX_U16 size_;
};

/**
 * ===============================================================================================
 *   > Private Global Variables (Localized Global)
 * ===============================================================================================
 */

/**
 * @brief Stack Pool (Statically)
 *
 */
_WX_STATIC Wx_Static_Stack_t g_Spool[PHYSICAL_STACK_POOL_SIZE(STACK_POOL_SIZE)];

/**
 * @brief
 *
 */
_WX_STATIC WX_U16 g_Spool_counter = 0;

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
_WX_FORCE_INLINE _WX_STATIC _WX_NORETURN __StackLog(WX_U8 log_level, _WX_CONST WX_U8 *string);
#endif

/**
 * ===============================================================================================
 *   > Private Function Implementation
 * ===============================================================================================
 */

#if defined(WIN32) || defined(__GNUC__)
_WX_NORETURN __StackLog(WX_U8 log_level, _WX_CONST WX_U8 *string) {
    switch (log_level) {
    case LOG_INFO:
        fprintf(stdout, "STACK - [INFO]: %s\n", string);
        break;
    case LOG_ERROR:
        fprintf(stderr, "STACK - [ERROR]: %s\n", string);
        break;
    case LOG_WARN:
        fprintf(stdout, "STACK - [WARNING]: %s\n", string);
        break;
    case LOG_CRITICAL:
        fprintf(stderr, "STACK - [CRITICAL]: %s\n", string);
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
 * @brief Create a new Stack instance.
 *
 * @param capacity Maximum capacity of the Stack.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetInstance(Wx_Static_Stack_t **EmptyInstance) {
    if ((_WX_NULL == EmptyInstance) || (_WX_NULL != (*EmptyInstance))) {
        return WX_E_STACK_INVALID_ARG;
    }

    if ((g_Spool_counter >= PHYSICAL_STACK_POOL_SIZE(STACK_POOL_SIZE))) {
        return WX_E_STACK_OUT_OF_MEMORY;
    }

    /* Get pool memory instance */
    (*EmptyInstance) = (Wx_Static_Stack_t *)&g_Spool[g_Spool_counter];

    WX_U16 i = 0;
    for (i = 0; (i < PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE)); ++i) {
        (*EmptyInstance)->npool_[i].data_ = _WX_NULL;
    }

    (*EmptyInstance)->size_ = 0;
    (*EmptyInstance)->top_ = 0;
    (*EmptyInstance)->bottom_ = 0;

    g_Spool_counter++;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Push an element onto the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @param Data Pointer to the Data to be pushed.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Push(Wx_Static_Stack_t **Instance, void *Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_STACK_INVALID_ARG;
    }

    if ((*Instance)->size_ == (PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE) - 1)) {
        return WX_E_STACK_OVERFLOW;
    }

    (*Instance)->npool_[(*Instance)->top_].data_ = (void *)Data;
    (*Instance)->top_ = ((*Instance)->top_ + 1) % PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE);
    (*Instance)->size_++;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Pop an element from the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] Data Pointer to store the popped Data.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Pop(Wx_Static_Stack_t **Instance, void **Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_STACK_INVALID_ARG;
    }

    if ((*Instance)->size_ == 0) {
        (*Instance)->top_ = 0;
        return WX_E_STACK_UNDERFLOW;
    }

    (*Instance)->top_--;

    *Data = (*Instance)->npool_[(*Instance)->top_].data_;
    (*Instance)->npool_[(*Instance)->top_].data_ = _WX_NULL;

    (*Instance)->size_--;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Get the top element of the Stack without removing it.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] Data Pointer to store the top Data.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetTop(_WX_CONST Wx_Static_Stack_t *Instance,
                                                     void **Data) {
    if ((_WX_NULL == Instance)) {
        return WX_E_STACK_INVALID_ARG;
    }

    *Data = Instance->npool_[Instance->top_].data_;
    
    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Get the bottom element of the Stack without removing it.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] Data Pointer to store the bottom Data.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetBottom(_WX_CONST Wx_Static_Stack_t *Instance,
                                                        void **Data) {
    if ((_WX_NULL == Instance)) {
        return WX_E_STACK_INVALID_ARG;
    }

    *Data = Instance->npool_[Instance->bottom_].data_;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Check if the Stack is empty.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] isEmptyFlag Pointer to a WX_BOOLean indicating if the Stack is empty.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_IsEmpty(_WX_CONST Wx_Static_Stack_t *Instance,
                                                      WX_BOOL *isEmptyFlag) {
    if ((_WX_NULL == Instance)) {
        return WX_E_STACK_INVALID_ARG;
    }

    *isEmptyFlag = (Instance->size_ > 0) ? WX_FALSE : WX_TRUE;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Check if the Stack is full.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] isFullFlag Pointer to a WX_BOOLean indicating if the Stack is full.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_IsFull(_WX_CONST Wx_Static_Stack_t *Instance,
                                                     WX_BOOL *isFullFlag) {
    if ((_WX_NULL == Instance)) {
        return WX_E_STACK_INVALID_ARG;
    }

    *isFullFlag = (Instance->size_ > 0) ? WX_TRUE : WX_FALSE;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Get the current size of the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] size Pointer to store the size of the Stack.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetSize(_WX_CONST Wx_Static_Stack_t *Instance,
                                                      WX_U16P Size) {
    if ((_WX_NULL == Instance)) {
        return WX_E_STACK_INVALID_ARG;
    }

    *Size = Instance->size_;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Clear the contents of the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Clear(Wx_Static_Stack_t *Instance) {
    if ((_WX_NULL == Instance)) {
        return WX_E_STACK_INVALID_ARG;
    }

    WX_U16 i = 0;
    for (i = 0; (i < Instance->size_); ++i) {
        Instance->npool_[i].data_ = _WX_NULL;
    }

    Instance->size_ = 0;

    return WX_E_STACK_SUCCESS;
}

/**
 * @brief Destroy the Stack instance.
 *
 * @param Stack Pointer to the pointer of the Stack instance.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Destroy(Wx_Static_Stack_t **Instance) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_STACK_INVALID_ARG;
    }

    Wx_Static_Stack_Clear(*Instance);

    g_Spool_counter--;

    return WX_E_STACK_SUCCESS;
}