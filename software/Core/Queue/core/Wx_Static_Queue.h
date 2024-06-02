/**
 * @file Wx_Static_Queue.h
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
#if !defined(__WX_STATIC_QUEUE_H__)
#define __WX_STATIC_QUEUE_H__

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
 * @brief Initialize a stack
 * @param Name_ Name of the stack
 */
#define Wx_Static_Queue_DeclareInstance_(Name_) Wx_Static_Queue_t *Name_ = NULL

/**
 * @brief Get the data from a pointer of a specified type.
 * @param TYPE_ The type of the data.
 * @param EXP_ The expression representing the pointer to the data.
 * @return The data of the specified type.
 */
#define Wx_Static_Queue_GetDataStored_(TYPE_, EXP_) (*(TYPE_ *)(EXP_))

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
#define QUEUE_POOL_SIZE ((WX_U8)(1))

/** @} */

/**
 * ===============================================================================================
 *   > Public Enums
 * ===============================================================================================
 */

/**
 * @brief Error codes for the queue layer
 *
 */
enum Wx_Static_QueueErrorCode {
    WX_E_QUEUE_SUCCESS = 0,       /* Operation successful */
    WX_E_QUEUE_INVALID_ARG,       /* Invalid argument provided */
    WX_E_QUEUE_NULL,              /* Null pointer encountered */
    WX_E_QUEUE_OUT_OF_MEMORY,     /* Memory allocation failure */
    WX_E_QUEUE_EMPTY_CONTAINER,   /* Container is empty (e.g., trying to remove
                                       from an empty list) */
    WX_E_QUEUE_NOT_FOUND,         /* Element not found */
    WX_E_QUEUE_DUPLICATE,         /* Duplicate element found */
    WX_E_QUEUE_OVERFLOW,          /* Arithmetic overflow */
    WX_E_QUEUE_UNDERFLOW,         /* Arithmetic underflow */
    WX_E_QUEUE_UNSUPPORTED_OP,    /* Unsupported operation or feature */
    WX_E_QUEUE_FILE_NOT_FOUND,    /* File not found */
    WX_E_QUEUE_IO_ERROR,          /* Input/output error */
    WX_E_QUEUE_PERMISSION_DENIED, /* Permission denied */
    WX_E_QUEUE_UNKNOWN            /* Unknown or generic error */
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
typedef struct Wx_Static_Queue Wx_Static_Queue_t;

/**
 * @brief
 *
 */
typedef enum Wx_Static_QueueErrorCode Wx_Static_En_QueueErrorCode_t;

/**
 * ===============================================================================================
 *   > Public Function Declaration
 * ===============================================================================================
 */

/**
 * @brief Get an instance of the queue.
 *
 * @param EmptyInstance Pointer to the pointer where the instance will be
 * stored.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetInstance(Wx_Static_Queue_t **EmptyInstance);

/**
 * @brief Enqueue an element to the queue.
 *
 * @param Instance Pointer to the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Enqueue(Wx_Static_Queue_t **Instance, void *Data);

/**
 * @brief Dequeue an element from the queue.
 *
 * @param Instance Pointer to the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Dequeue(Wx_Static_Queue_t **Instance, void **Data);

/**
 * @brief Get the front element of the queue.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param Data Pointer to the data where the front element will be stored.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetFront(_WX_CONST Wx_Static_Queue_t *Instance,
                                                       void **Data);

/**
 * @brief Get the rear element of the queue.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param Data Pointer to the data where the rear element will be stored.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetRear(_WX_CONST Wx_Static_Queue_t *Instance,
                                                      void **Data);

/**
 * @brief Check if the queue is empty.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param EmptyFlag Boolean flag indicating if the queue is empty.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_IsEmpty(_WX_CONST Wx_Static_Queue_t *Instance,
                                                      WX_BOOL *EmptyFlag);

/**
 * @brief Check if the queue is full.
 *
 * @param Instance Const pointer to an empty instance for size information.
 * @param EmptyFlag Boolean flag indicating if the queue is full.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_IsFull(_WX_CONST Wx_Static_Queue_t *Instance,
                                                     WX_BOOL *FullFlag);

/**
 * @brief
 *
 * @param Instance
 * @param FullFlag
 * @return Wx_Static_En_QueueErrorCode_t
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_GetSize(_WX_CONST Wx_Static_Queue_t *Instance,
                                                      WX_U16P Size);

/**
 * @brief Clear the contents of the queue.
 *
 * @param Instance Pointer to the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Clear(Wx_Static_Queue_t *Instance);

/**
 * @brief Destroy the queue instance.
 *
 * @param Instance Pointer to the pointer of the queue instance.
 * @return Wx_Static_En_QueueErrorCode_t Error code.
 */
Wx_Static_En_QueueErrorCode_t Wx_Static_Queue_Destroy(Wx_Static_Queue_t **Instance);

/*-------------------------------------*/
/**
 * @brief
 * @defgroup User Friendly Interface
 *
 * @{
 */

/**     @defgroup Helpers @{ */
#define WX_DEFINE_A_QUEUE(wx_q) Wx_Static_Queue_DeclareInstance_((wx_q))
#define WX_EXTRACT_DATA_FROM_QUEUE(TYPE_, EXP_) Wx_Static_Queue_GetDataStored_(TYPE_, EXP_)
/**     @} */

/**     @defgroup Main Library Interface @{ */
#define WX_QUEUE_CTOR(wx_queue_ptr)                                                                \
    Wx_Static_Queue_GetInstance((Wx_Static_Queue_t **)(&(wx_queue_ptr)))
#define WX_QUEUE_ENQUEUE(wx_queue_ptr, element)                                                    \
    Wx_Static_Queue_Enqueue((Wx_Static_Queue_t **)(&(wx_queue_ptr)), (void *)(&(element)))
#define WX_QUEUE_DEQUEUE(wx_queue_ptr, element)                                                    \
    Wx_Static_Queue_Dequeue((Wx_Static_Queue_t **)(&(wx_queue_ptr)), (void **)(&(element)))
#define WX_QUEUE_GET_FRONT(wx_queue_ptr, element)                                                  \
    Wx_Static_Queue_GetFront((_WX_CONST Wx_Static_Queue_t *)(wx_queue_ptr), (void **)(&(element)))
#define WX_QUEUE_GET_REAR(wx_queue_ptr, element)                                                   \
    Wx_Static_Queue_GetRear((_WX_CONST Wx_Static_Queue_t *)(wx_queue_ptr), (void **)(&(element)))
#define WX_QUEUE_IS_EMPTY(wx_queue_ptr, is_empty)                                                  \
    Wx_Static_Queue_IsEmpty((_WX_CONST Wx_Static_Queue_t *)(wx_queue_ptr), (WX_BOOL *)(&(is_empty)))
#define WX_QUEUE_IS_FULL(wx_queue_ptr, is_full)                                                    \
    Wx_Static_Queue_IsFull((_WX_CONST Wx_Static_Queue_t *)(wx_queue_ptr), (WX_BOOL *)(&(is_full)))
#define WX_QUEUE_GET_SIZE(wx_queue_ptr, size)                                                      \
    Wx_Static_Queue_GetSize((_WX_CONST Wx_Static_Queue_t *)(wx_queue_ptr), (WX_U16 *)(&(size)))
#define WX_QUEUE_CLEAR(wx_queue_ptr) Wx_Static_Queue_Clear((Wx_Static_Queue_t *)(wx_queue_ptr))
#define WX_QUEUE_DTOR(wx_queue_ptr) Wx_Static_Queue_Destroy((Wx_Static_Queue_t **)(&(wx_queue_ptr)))
/**     @} */
/** @} */
/*-------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_STATIC_QUEUE_H__ */