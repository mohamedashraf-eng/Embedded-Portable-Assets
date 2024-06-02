/**
 * @file Wx_StdTypes.h
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
#if !defined(__WX_STDTYPES_H__)
#define __WX_STDTYPES_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_Compiler.h"
#include "Wx_Platform.h"

/** 
 * @defgroup Compiler Specific Declarations 
 * @{
 */

/**
 * @brief Physical state 5V or 3.3V
 * @implements SymbolDefinitions_enumeration
 */
#define WX_STD_HIGH 0x01
/**
 * @brief Physical state 0V
 * @implements SymbolDefinitions_enumeration
 */
#define WX_STD_LOW 0x00
/**
 * @brief Logical state active.
 * @implements SymbolDefinitions_enumeration
 */
#define WX_STD_ACTIVE 0x01
/**
 * @brief Physical state idle.
 * @implements SymbolDefinitions_enumeration
 */
#define WX_STD_IDLE 0x00
/**
 * @brief ON State.
 * @implements SymbolDefinitions_enumeration
 */
#define WX_STD_ON 0x01
/**
 * @brief OFF State.
 * @implements SymbolDefinitions_enumeration
 */
#define WX_STD_OFF 0x00
/**
 * @brief Return code for failure/error.
 * @implements SymbolDefinitions_enumeration
 */
	#define E_NOT_OK 0x01
/**
 * @brief Because E_OK is already defined within OSEK, the symbol E_OK has to be shared.
 * 				To avoid name clashed and redfinitions problems. The symbols have to be defined in the following way
 */
#ifndef STATUSTYPEDEFINED
#  define STATUSTYPEDEFINED
/**
 * @brief Success return code
 */
#define E_OK 0x00
/**
 * @brief This type is defined for OSEK compilance.
 */
typedef WX_UINT8 Wx_StatusType;
#endif /* STATUSTYPEDEFINED */
/**
 * @brief This type can be used as standard API return type which is shared between the RTE and BSW modules.
 * @implements WX_Std_ReturnType_type
 */
typedef WX_UINT8 Wx_Std_ReturnType;

/** @} */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_STDTYPES_H__ */