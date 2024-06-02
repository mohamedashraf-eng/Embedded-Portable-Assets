/**
 * @file Wx_Static_Stack.h
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
#if !defined(__WX_STATIC_STACK_H__)
#define __WX_STATIC_STACK_H__

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
 * @brief Initialize a stack.
 * @param Name_ Name of the stack.
 */
#define Wx_Static_Stack_DeclareInstance_(Name_) Wx_Static_Stack_t *Name_ = NULL

/**
 * @brief Get the data from a pointer of a specified type.
 * @param TYPE_ The type of the data.
 * @param EXP_ The expression representing the pointer to the data.
 * @return The data of the specified type.
 */
#define Wx_Static_Stack_GetDataStored_(TYPE_, EXP_) (*(TYPE_ *)(EXP_))

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
#define STACK_POOL_SIZE ((WX_U8)(1))

/** @} */

/**
 * ===============================================================================================
 *   > Public Enums
 * ===============================================================================================
 */

/**
 * @brief Error codes for the Stack layer
 *
 */
enum Wx_Static_StackErrorCode {
    WX_E_STACK_SUCCESS = 0,       /* Operation successful */
    WX_E_STACK_INVALID_ARG,       /* Invalid argument provided */
    WX_E_STACK_NULL,              /* Null pointer encountered */
    WX_E_STACK_OUT_OF_MEMORY,     /* Memory allocation failure */
    WX_E_STACK_EMPTY_CONTAINER,   /* Container is empty (e.g., trying to remove
                                       from an empty list) */
    WX_E_STACK_NOT_FOUND,         /* Element not found */
    WX_E_STACK_DUPLICATE,         /* Duplicate element found */
    WX_E_STACK_OVERFLOW,          /* Arithmetic overflow */
    WX_E_STACK_UNDERFLOW,         /* Arithmetic underflow */
    WX_E_STACK_UNSUPPORTED_OP,    /* Unsupported operation or feature */
    WX_E_STACK_FILE_NOT_FOUND,    /* File not found */
    WX_E_STACK_IO_ERROR,          /* Input/output error */
    WX_E_STACK_PERMISSION_DENIED, /* Permission denied */
    WX_E_STACK_UNKNOWN            /* Unknown or generic error */
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
typedef struct Wx_Static_Stack Wx_Static_Stack_t;

/**
 * @brief
 *
 */
typedef enum Wx_Static_StackErrorCode Wx_Static_En_StackErrorCode_t;

/**
 * ===============================================================================================
 *   > Public Function Declaration
 * ===============================================================================================
 */

/**
 * @brief Create a new Stack instance.
 *
 * @param capacity Maximum capacity of the Stack.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetInstance(Wx_Static_Stack_t **Stack);

/**
 * @brief Push an element onto the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @param Data Pointer to the Data to be pushed.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Push(Wx_Static_Stack_t **Instance, void *Data);

/**
 * @brief Pop an element from the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] Data Pointer to store the popped Data.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Pop(Wx_Static_Stack_t **Instance, void **Data);

/**
 * @brief Get the top element of the Stack without removing it.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] Data Pointer to store the top Data.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetTop(__CONST Wx_Static_Stack_t *Instance,
                                                     void **Data);

/**
 * @brief Get the bottom element of the Stack without removing it.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] Data Pointer to store the bottom Data.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetBottom(__CONST Wx_Static_Stack_t *Instance,
                                                        void **Data);

/**
 * @brief Check if the Stack is empty.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] isEmptyFlag Pointer to a WX_BOOLean indicating if the Stack is empty.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_IsEmpty(__CONST Wx_Static_Stack_t *Instance,
                                                      WX_BOOL *isEmptyFlag);

/**
 * @brief Check if the Stack is full.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] isFullFlag Pointer to a WX_BOOLean indicating if the Stack is full.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_IsFull(__CONST Wx_Static_Stack_t *Instance,
                                                     WX_BOOL *isFullFlag);

/**
 * @brief Get the current size of the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @param[out] size Pointer to store the size of the Stack.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_GetSize(__CONST Wx_Static_Stack_t *Instance,
                                                      WX_U16P Size);

/**
 * @brief Clear the contents of the Stack.
 *
 * @param Stack Pointer to the Stack instance.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Clear(Wx_Static_Stack_t *Instance);

/**
 * @brief Destroy the Stack instance.
 *
 * @param Stack Pointer to the pointer of the Stack instance.
 * @return Wx_Static_En_StackErrorCode_t Error code.
 */
Wx_Static_En_StackErrorCode_t Wx_Static_Stack_Destroy(Wx_Static_Stack_t **Instance);

/*-------------------------------------*/
/**
 * @brief
 * @defgroup User Friendly Interface
 *
 * @{
 */

/**     @defgroup Helpers @{ */
#define WX_DEFINE_A_STACK(wx_q) Wx_Static_Stack_DeclareInstance_((wx_q))
#define WX_EXTRACT_DATA_FROM_STACK(TYPE_, EXP_) Wx_Static_Stack_GetDataStored_(TYPE_, EXP_)
/**     @} */

/**     @defgroup Main Library Interface @{ */
#define WX_STACK_CTOR(stack_ptr) Wx_Static_Stack_GetInstance((Wx_Static_Stack_t **)(&(stack_ptr)))
#define WX_STACK_PUSH(stack_ptr, element)                                                          \
    Wx_Static_Stack_Push((Wx_Static_Stack_t **)(&(stack_ptr)), (void *)(&(element)))
#define WX_STACK_POP(stack_ptr, element)                                                           \
    Wx_Static_Stack_Pop((Wx_Static_Stack_t **)(&(stack_ptr)), (void **)(&(element)))
#define WX_STACK_GET_TOP(stack_ptr, element)                                                       \
    Wx_Static_Stack_GetTop((__CONST Wx_Static_Stack_t *)(stack_ptr), (void **)(&(element)))
#define WX_STACK_GET_BOTTOM(stack_ptr, element)                                                    \
    Wx_Static_Stack_GetBottom((__CONST Wx_Static_Stack_t *)(stack_ptr), (void **)(&(element)))
#define WX_STACK_IS_EMPTY(stack_ptr, is_empty)                                                     \
    Wx_Static_Stack_IsEmpty((__CONST Wx_Static_Stack_t *)(stack_ptr), (WX_BOOL *)(&(is_empty)))
#define WX_STACK_IS_FULL(stack_ptr, is_full)                                                       \
    Wx_Static_Stack_IsFull((__CONST Wx_Static_Stack_t *)(stack_ptr), (WX_BOOL *)(&(is_full)))
#define WX_STACK_GET_SIZE(stack_ptr, size)                                                         \
    Wx_Static_Stack_GetSize((__CONST Wx_Static_Stack_t *)(stack_ptr), (WX_U16 *)(&(size)))
#define WX_STACK_CLEAR(stack_ptr) Wx_Static_Stack_Clear((Wx_Static_Stack_t *)(stack_ptr))
#define WX_STACK_DTOR(stack_ptr) Wx_Static_Stack_Destroy((Wx_Static_Stack_t **)(&(stack_ptr)))
/**     @} */
/** @} */
/*-------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_STATIC_STACK_H__ */