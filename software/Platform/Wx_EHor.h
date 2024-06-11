/**
 * @file Wx_EHOR.h
 * @brief Error handling macros and functions for the Wx project.
 * @version 0.3
 * @date 2023-10-05
 * 
 * @attention
 * 
 * MIT License
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
/** @brief Header guard */
#if !defined(__WX_EHOR_H__)
#define __WX_EHOR_H__

/** @brief C++ name mangling guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"

/*----------------------------------------------------------------------------*/

/**
 * @defgroup PublicMacros Public Macros
 * @{
 */

// General Errors
#define WX_EHOR_NONE                    ((WX_U32)0x00000000)  // No error
#define WX_EHOR_UNKNOWN                 ((WX_U32)0x00000001)  // Unknown error
#define WX_EHOR_MEMORY_ALLOCATION       ((WX_U32)0x00000002)  // Memory allocation failure
#define WX_EHOR_NULL_POINTER            ((WX_U32)0x00000003)  // Null pointer error
#define WX_EHOR_INVALID_PARAMETER       ((WX_U32)0x00000004)  // Invalid parameter
#define WX_EHOR_TIMEOUT                 ((WX_U32)0x00000005)  // Operation timed out
#define WX_EHOR_OVERFLOW                ((WX_U32)0x00000006)  // Overflow error
#define WX_EHOR_UNDERFLOW               ((WX_U32)0x00000007)  // Underflow error
#define WX_EHOR_OUT_OF_RANGE            ((WX_U32)0x00000008)  // Value out of range
#define WX_EHOR_NOT_IMPLEMENTED         ((WX_U32)0x00000009)  // Feature not implemented
#define WX_EHOR_PERMISSION_DENIED       ((WX_U32)0x0000000A)  // Permission denied
#define WX_EHOR_RESOURCE_BUSY           ((WX_U32)0x0000000B)  // Resource busy
#define WX_EHOR_RESOURCE_UNAVAILABLE    ((WX_U32)0x0000000C)  // Resource unavailable

// Communication Errors
#define WX_EHOR_COMMUNICATION_FAILURE   ((WX_U32)0x0000000D)  // General communication failure
#define WX_EHOR_UART_TRANSMIT           ((WX_U32)0x0000000E)  // UART transmission error
#define WX_EHOR_UART_RECEIVE            ((WX_U32)0x0000000F)  // UART reception error
#define WX_EHOR_SPI_TRANSMIT            ((WX_U32)0x00000010)  // SPI transmission error
#define WX_EHOR_SPI_RECEIVE             ((WX_U32)0x00000011)  // SPI reception error
#define WX_EHOR_I2C_TRANSMIT            ((WX_U32)0x00000012)  // I2C transmission error
#define WX_EHOR_I2C_RECEIVE             ((WX_U32)0x00000013)  // I2C reception error
#define WX_EHOR_CAN_TRANSMIT            ((WX_U32)0x00000014)  // CAN transmission error
#define WX_EHOR_CAN_RECEIVE             ((WX_U32)0x00000015)  // CAN reception error
#define WX_EHOR_LIN_TRANSMIT            ((WX_U32)0x00000016)  // LIN transmission error
#define WX_EHOR_LIN_RECEIVE             ((WX_U32)0x00000017)  // LIN reception error
#define WX_EHOR_BLUETOOTH_FAILURE       ((WX_U32)0x00000018)  // Bluetooth failure
#define WX_EHOR_WIFI_FAILURE            ((WX_U32)0x00000019)  // WiFi failure

// Sensor Errors
#define WX_EHOR_SENSOR_FAILURE          ((WX_U32)0x0000001A)  // General sensor failure
#define WX_EHOR_SENSOR_DISCONNECTED     ((WX_U32)0x0000001B)  // Sensor disconnected
#define WX_EHOR_SENSOR_OUT_OF_RANGE     ((WX_U32)0x0000001C)  // Sensor value out of range
#define WX_EHOR_SENSOR_CALIBRATION      ((WX_U32)0x0000001D)  // Sensor calibration error
#define WX_EHOR_SENSOR_TIMEOUT          ((WX_U32)0x0000001E)  // Sensor timeout

// Actuator Errors
#define WX_EHOR_ACTUATOR_FAILURE        ((WX_U32)0x0000001F)  // General actuator failure
#define WX_EHOR_ACTUATOR_DISCONNECTED   ((WX_U32)0x00000020)  // Actuator disconnected
#define WX_EHOR_ACTUATOR_OVER_CURRENT   ((WX_U32)0x00000021)  // Actuator over current
#define WX_EHOR_ACTUATOR_UNDER_CURRENT  ((WX_U32)0x00000022)  // Actuator under current
#define WX_EHOR_ACTUATOR_POSITION       ((WX_U32)0x00000023)  // Actuator position error

// File System Errors
#define WX_EHOR_FILE_NOT_FOUND          ((WX_U32)0x00000024)  // File not found
#define WX_EHOR_FILE_READ               ((WX_U32)0x00000025)  // File read error
#define WX_EHOR_FILE_WRITE              ((WX_U32)0x00000026)  // File write error
#define WX_EHOR_FILE_SYSTEM_CORRUPT     ((WX_U32)0x00000027)  // File system corrupt
#define WX_EHOR_FILE_PERMISSION_DENIED  ((WX_U32)0x00000028)  // File permission denied

// Network Errors
#define WX_EHOR_NETWORK_DOWN            ((WX_U32)0x00000029)  // Network down
#define WX_EHOR_NETWORK_TIMEOUT         ((WX_U32)0x0000002A)  // Network timeout
#define WX_EHOR_NETWORK_UNREACHABLE     ((WX_U32)0x0000002B)  // Network unreachable
#define WX_EHOR_NETWORK_PROTOCOL        ((WX_U32)0x0000002C)  // Network protocol error
#define WX_EHOR_NETWORK_SECURITY        ((WX_U32)0x0000002D)  // Network security error

// Power Management Errors
#define WX_EHOR_POWER_FAILURE           ((WX_U32)0x0000002E)  // General power failure
#define WX_EHOR_POWER_UNDER_VOLTAGE     ((WX_U32)0x0000002F)  // Power under voltage
#define WX_EHOR_POWER_OVER_VOLTAGE      ((WX_U32)0x00000030)  // Power over voltage
#define WX_EHOR_POWER_OVER_CURRENT      ((WX_U32)0x00000031)  // Power over current
#define WX_EHOR_BATTERY_LOW             ((WX_U32)0x00000032)  // Battery low
#define WX_EHOR_BATTERY_FAILURE         ((WX_U32)0x00000033)  // Battery failure
#define WX_EHOR_POWER_SUPPLY_FAILURE    ((WX_U32)0x00000034)  // Power supply failure

// Security Errors
#define WX_EHOR_SECURITY_VIOLATION      ((WX_U32)0x00000035)  // Security violation
#define WX_EHOR_AUTHENTICATION_FAILURE  ((WX_U32)0x00000036)  // Authentication failure
#define WX_EHOR_AUTHORIZATION_FAILURE   ((WX_U32)0x00000037)  // Authorization failure
#define WX_EHOR_ENCRYPTION_FAILURE      ((WX_U32)0x00000038)  // Encryption failure
#define WX_EHOR_DECRYPTION_FAILURE      ((WX_U32)0x00000039)  // Decryption failure

// Miscellaneous Errors
#define WX_EHOR_INITIALIZATION          ((WX_U32)0x0000003A)  // Initialization error
#define WX_EHOR_SHUTDOWN                ((WX_U32)0x0000003B)  // Shutdown error
#define WX_EHOR_OPERATION_FAILED        ((WX_U32)0x0000003C)  // General operation failure
#define WX_EHOR_DATA_CORRUPTION         ((WX_U32)0x0000003D)  // Data corruption error
#define WX_EHOR_CONFIGURATION_ERROR     ((WX_U32)0x0000003E)  // Configuration error
#define WX_EHOR_STATE_MISMATCH          ((WX_U32)0x0000003F)  // State mismatch error

/** @} */

/*----------------------------------------------------------------------------*/

/**
 * @brief 
 * Structure to hold error status
 */
typedef struct {
    WX_U32 error;                 // Bitwise error flags
    WX_U32 error_code;            // Base error code
#if defined(EHOR_EEXT)
    WX_U32 error_subcode;         // Extension error code
#endif /* EHOR_EEXT */
    WX_U32 error_count;           // Error occurrence counter
    WX_U8 error_response[64u];    // Error response message buffer
    WX_U8 last_module[32u];       // Module where last error occurred
    WX_U8 last_function[32u];     // Function where last error occurred
} WXEHOR_t;

/**
 * @brief Instance of the error status.
 */
WXEHOR_t global_tThisErrStatus;

/**
 * @defgroup PublicFunctions Public Function Declarations
 * @{
 */

/**
 * @brief Set the module name where the error occurred.
 * 
 * This macro sets the name of the module in which the error occurred.
 * It copies the module name string into the `last_module` field of the global
 * error status structure.
 * 
 * @param THIS_MOD The name of the module (file) where the error occurred.
 */
#define WX_EHOR_XTHISMOD(THIS_MOD) \
    WXSTRCPY(global_tThisErrStatus.last_module, (const WX_U8 *)(THIS_MOD))

/**
 * @brief Set the function name where the error occurred.
 * 
 * This macro sets the name of the function in which the error occurred.
 * It copies the function name string into the `last_function` field of the global
 * error status structure.
 * 
 * @param THIS_FUN The name of the function where the error occurred.
 */
#define WX_EHOR_XTHISFUN(THIS_FUN) \
    WXSTRCPY(global_tThisErrStatus.last_function, (const WX_U8 *)(THIS_FUN))

/**
 * @brief Set the error response message.
 * 
 * This macro sets the error response message that provides additional information
 * about the error. It copies the response message string into the `error_response`
 * field of the global error status structure.
 * 
 * @param RESPONSE The error response message.
 */
#define WX_EHOR_ERESPONSE(RESPONSE) \
    WXSTRCPY(global_tThisErrStatus.error_response, (const WX_U8 *)(RESPONSE))

/**
 * @brief Append an error to the global error status.
 * 
 * This macro appends a specified error code to the global error status.
 * It sets the corresponding bit in the `error` field of the global error status
 * structure and increments the `error_count` field.
 * 
 * @param ERR The error code to append.
 */
#define WX_EHOR_APPEND(ERR) do { \
    global_tThisErrStatus.error |= (ERR); \
    global_tThisErrStatus.error_count++; \
} while(0)

/**
 * @brief Clear a specific error from the global error status.
 * 
 * This macro clears a specified error code from the global error status.
 * It clears the corresponding bit in the `error` field of the global error status
 * structure and decrements the `error_count` field if it is greater than zero.
 * 
 * @param ERR The error code to clear.
 */
#define WX_EHOR_CLEAR(ERR) do { \
    global_tThisErrStatus.error &= ~(ERR); \
    if (global_tThisErrStatus.error_count > 0) { \
        global_tThisErrStatus.error_count--; \
    } \
} while(0)

/**
 * @brief Check if a specific error is set in the global error status.
 * 
 * This macro checks if a specified error code is set in the global error status.
 * It returns a non-zero value if the corresponding bit in the `error` field of
 * the global error status structure is set, otherwise, it returns zero.
 * 
 * @param ERR The error code to check.
 * @return Non-zero if the error is set, zero otherwise.
 */
#define WX_EHOR_CHECK(ERR) ((global_tThisErrStatus.error & (ERR)) != 0)

/**
 * @brief Set a specific error in the global error status.
 * 
 * This macro sets a specified error code in the global error status.
 * It sets the `error` field of the global error status structure to the specified
 * error code and sets the `error_count` field to 1.
 * 
 * @param ERR The error code to set.
 */
#define WX_EHOR_SET(ERR) do { \
    global_tThisErrStatus.error = (ERR); \
    global_tThisErrStatus.error_count = 1; \
} while(0)

/**
 * @brief Clear all errors in the global error status.
 * 
 * This macro clears all errors in the global error status.
 * It sets the `error` field of the global error status structure to zero and sets
 * the `error_count` field to zero.
 */
#define WX_EHOR_CLEAR_ALL() do { \
    global_tThisErrStatus.error = 0; \
    global_tThisErrStatus.error_count = 0; \
} while(0)

/**
 * @brief Get the current global error status.
 * 
 * This macro returns the current global error status by retrieving the value of
 * the `error` field of the global error status structure.
 * 
 * @return The current global error status.
 */
#define WX_EHOR_GET() (global_tThisErrStatus.error)

/**
 * @brief Log an error with additional information.
 * 
 * This macro logs an error with additional information including the module name,
 * function name, and a response message. It sets the module and function names,
 * sets the error response message, and appends the error code to the global error
 * status.
 * 
 * @param WX_EHOR_ERROR The error code to log.
 * @param WX_EHOR_RESPONSE The error response message.
 */
#define WX_EHOR_LOG(WX_EHOR_ERROR, WX_EHOR_RESPONSE) do { \
    WX_EHOR_XTHISMOD(__FILE__); \
    WX_EHOR_XTHISFUN(__FUNCTION__); \
    WX_EHOR_ERESPONSE(WX_STRING(WX_EHOR_RESPONSE)); \
    WX_EHOR_APPEND(WX_EHOR_ERROR); \
} while(0)
/** @} */

/**
 * @brief Handle error condition with a callback.
 * 
 * @param pfArg_onErrCallback Pointer to the error callback function.
 */
_WX_STATIC _WX_NORETURN WX_EHOR_ON_ERROR((_WX_NORETURN)(* _WX_CONST pfArg_onErrCallback)(_WX_NOARG)) {
    if(global_tThisErrStatus.size > 0) { 
        WX_ASSERT(_WX_NULL != pF_onErr_xcallBack);
        /* Call the error callback. */
        pfArg_onErrCallback();
    }
}

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_EHOR_H__ */

