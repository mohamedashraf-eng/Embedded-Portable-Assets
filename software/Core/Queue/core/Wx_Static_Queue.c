/**
 * @file Wx_Static_Queue.c
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
#include "Wx_Static_Queue.h"

/**
 * ===============================================================================================
 *   > Private Macros
 * ===============================================================================================
 */

#if defined(LOG)
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
 * @brief Limit the physical queue pool size based on a given virtual queue pool size.
 *
 * This macro ensures that the physical queue pool size does not exceed 255u.
 *
 * @param VIRTUAL_QUEUE_POOL_SIZE_ The virtual QUEUE pool size.
 * @return The limited physical QUEUE pool size.
 */
#define PHYSICAL_QUEUE_POOL_SIZE(VIRTUAL_QUEUE_POOL_SIZE_)                                         \
    (((VIRTUAL_QUEUE_POOL_SIZE_) > ((WX_U8)(255u))) ? 255u : (VIRTUAL_QUEUE_POOL_SIZE_))

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
 * @brief Queue Structure
 *
 */
struct Wx_Static_Queue {
    /* Statically allocated node pool */
    Wx_Node_t npool_[PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE)];
    WX_U16 front_;
    WX_U16 rear_;
    WX_U16 size_;
};

/**
 * ===============================================================================================
 *   > Private Global Variables (Localized Global)
 * ===============================================================================================
 */

/**
 * @brief Queue Pool (Statically)
 *
 */
_WX_STATIC Wx_Static_Queue_t g_Qpool[PHYSICAL_QUEUE_POOL_SIZE(QUEUE_POOL_SIZE)];

/**
 * @brief
 *
 */
_WX_STATIC WX_U16 g_Qpool_counter = 0;

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
_WX_FORCE_INLINE _WX_STATIC _WX_NORETURN __QueueLog(WX_U8 log_level, _WX_CONST WX_U8 *string);
#endif

/**
 * ===============================================================================================
 *   > Private Function Implementation
 * ===============================================================================================
 */

#if defined(LOG)
_WX_NORETURN __QueueLog(WX_U8 log_level, _WX_CONST WX_U8 *string) {
    switch (log_level) {
    case LOG_INFO:
        WXPRINT("QUEUE - [INFO]: %s\n", string);
        break;
    case LOG_ERROR:
        WXPRINT("QUEUE - [ERROR]: %s\n", string);
        break;
    case LOG_WARN:
        WXPRINT("QUEUE - [WARNING]: %s\n", string);
        break;
    case LOG_CRITICAL:
        WXPRINT("QUEUE - [CRITICAL]: %s\n", string);
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
 * @brief Get an instance of the queue.
 *
 * @param EmptyInstance Pointer to the pointer where the instance will be
 * stored.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetInstance(Wx_Static_Queue_t **EmptyInstance) {
    if ((_WX_NULL == EmptyInstance) || (_WX_NULL != (*EmptyInstance))) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    if ((g_Qpool_counter >= PHYSICAL_QUEUE_POOL_SIZE(QUEUE_POOL_SIZE))) {
        return WX_E_QUEUE_OUT_OF_MEMORY;
    }

    /* Get pool memory instance */
    (*EmptyInstance) = (Wx_Static_Queue_t *)&g_Qpool[g_Qpool_counter];

    WX_U16 i = 0;
    for (i = 0; (i < PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE)); ++i) {
        (*EmptyInstance)->npool_[i].data_ = _WX_NULL;
    }

    (*EmptyInstance)->size_ = 0;
    (*EmptyInstance)->front_ = 0;
    (*EmptyInstance)->rear_ = 0;

    g_Qpool_counter++;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Enqueue an element to the queue.
 *
 * @param Instance Pointer to the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Enqueue(Wx_Static_Queue_t **Instance, void *Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    if ((*Instance)->size_ == PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE)) {
        return WX_E_QUEUE_OVERFLOW;
    }

    (*Instance)->npool_[(*Instance)->rear_].data_ = (void *)Data;
    (*Instance)->rear_ = ((*Instance)->rear_ + 1) % PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE);
    (*Instance)->size_++;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Dequeue an element from the queue.
 *
 * @param Instance Pointer to the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Dequeue(Wx_Static_Queue_t **Instance, void **Data) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    if ((*Instance)->size_ == 0) {
        return WX_E_QUEUE_UNDERFLOW;
    }

    *Data = (*Instance)->npool_[(*Instance)->front_].data_;
    (*Instance)->npool_[(*Instance)->front_].data_ = _WX_NULL;

    (*Instance)->front_ = ((*Instance)->front_ + 1) % PHYSICAL_NODE_POOL_SIZE(NODE_POOL_SIZE);
    (*Instance)->size_--;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Get the front element of the queue.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param Data Pointer to the data where the front element will be stored.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetFront(_WX_CONST Wx_Static_Queue_t *Instance,
                                                       void **Data) {
    if ((_WX_NULL == Instance)) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    *Data = Instance->npool_[Instance->front_].data_;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Get the rear element of the queue.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param Data Pointer to the data where the rear element will be stored.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetRear(_WX_CONST Wx_Static_Queue_t *Instance,
                                                      void **Data) {
    if ((_WX_NULL == Instance)) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    *Data = Instance->npool_[Instance->rear_].data_;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Check if the queue is empty.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param EmptyFlag Boolean flag indicating if the queue is empty.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_IsEmpty(_WX_CONST Wx_Static_Queue_t *Instance,
                                                      WX_BOOL *EmptyFlag) {
    if ((_WX_NULL == Instance)) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    *EmptyFlag = (Instance->size_ > 0) ? WX_FALSE : WX_TRUE;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Check if the queue is full.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param EmptyFlag Boolean flag indicating if the queue is full.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_IsFull(_WX_CONST Wx_Static_Queue_t *Instance,
                                                     WX_BOOL *FullFlag) {
    if ((_WX_NULL == Instance)) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    *FullFlag = (Instance->size_ > 0) ? WX_TRUE : WX_FALSE;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief
 *
 * @param Instance
 * @param FullFlag
 * @return Wx_Static_En_QueueErrorCode_t
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetSize(_WX_CONST Wx_Static_Queue_t *Instance,
                                                      WX_U16P Size) {
    if ((_WX_NULL == Instance)) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    *Size = Instance->size_;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Clear the contents of the queue.
 *
 * @param Instance Pointer to the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Clear(Wx_Static_Queue_t *Instance) {
    if ((_WX_NULL == Instance)) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    WX_U16 i = 0;
    for (i = 0; (i < Instance->size_); ++i) {
        Instance->npool_[i].data_ = _WX_NULL;
    }

    Instance->size_ = 0;
    Instance->front_ = 0;
    Instance->rear_ = 0;

    return WX_E_QUEUE_SUCCESS;
}

/**
 * @brief Destroy the queue instance.
 *
 * @param Instance Pointer to the pointer of the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Destroy(Wx_Static_Queue_t **Instance) {
    if ((_WX_NULL == Instance) || (_WX_NULL == (*Instance))) {
        return WX_E_QUEUE_INVALID_ARG;
    }

    Wx_Static_Queue_Clear(*Instance);

    g_Qpool_counter--;

    return WX_E_QUEUE_SUCCESS;
}