/**
 * @file Wx_Wrappers.h
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
#if !defined(__WX_COMPILER_H__)
#define __WX_COMPILER_H__

/** @brief cpp name mangle guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */
/*----------------------------------------------------------------------------*/
#define __WRAPPERS__

/* Detect platform */
#if defined(_WIN32) || defined(_WIN64)
#   define WX_PLATFORM_WINDOWS
#elif defined(__linux__)
#   define WX_PLATFORM_LINUX
#elif defined(__APPLE__)
#   define WX_PLATFORM_MAC
#endif

/** @todo Make it more generic */
#ifdef WX_PLATFORM_WINDOWS
#   include <stdio.h>
#   include <stdlib.h>
#   define XPRINT(...) printf(__VA_ARGS__)
#   define XMALLOC(_SIZE) malloc(_SIZE)
#   define XCALLOC(_N, _SIZE) calloc(_N, _SIZE)
#   define XREALLOC(_T, _PTR, _N, _SIZE) (_T*)realloc((_PTR), ((_N) * (_SIZE)))
#   define XFREE(_PTR) free(_PTR)
#   define XMALLOC_ARRAY(_T, _N) (_T*)malloc(_SIZEof(_T) * (_N))
#   define XCALLOC_ARRAY(_T, _N) (_T*)calloc(_N, _SIZEof(_T))
#   define XFREE_ARRAY(_PTR) free(_PTR)

#elif defined(WX_PLATFORM_LINUX)
#   include <stdio.h>
#   include <stdlib.h>
#   define XPRINT(...) printf(__VA_ARGS__)
#   define XMALLOC(_T, _SIZE) (_T*)malloc(_SIZE)
#   define XCALLOC(_T, _N, _SIZE) (_T*)calloc(_N, _SIZE)
#   define XREALLOC(_T, _PTR, _N, _SIZE) (_T*)realloc((_PTR), ((_N) * (_SIZE)))
#   define XFREE(_PTR) free(_PTR)
#   define XMALLOC_ARRAY(_T, _N) (_T*)malloc(_SIZEof(_T) * (_N))
#   define XCALLOC_ARRAY(_T, _N) (_T*)calloc(_N, _SIZEof(_T))
#   define XFREE_ARRAY(_PTR) free(_PTR)
#elif defined(WX_PLATFORM_MAC)
#   include <stdio.h>
#   include <stdlib.h>
#   define XPRINT(...) printf(__VA_ARGS__)
#   define XMALLOC(_SIZE) malloc((_SIZE))
#   define XCALLOC(_N, _SIZE) calloc((_N), (_SIZE))
#   define XREALLOC(_T, _PTR, _N, _SIZE) (_T*)realloc((_PTR), ((_N) * (_SIZE)))
#   define XFREE(_PTR) free(_PTR)
#   define XMALLOC_ARRAY(_T, _N) (_T*)malloc(_SIZEof(_T) * (_N))
#   define XCALLOC_ARRAY(_T, _N) (_T*)calloc((_N), _SIZEof(_T))
#   define XFREE_ARRAY(_PTR) free((_PTR))
#else
#   error "Unsupported platform!"
#endif

#if defined(__WRAPPERS__)
/**
    @brief Platform-specific print macro.       
            This macro prints formatted output to the standard output.
    @param ... The format string followed by the variables to format.
*/
#   define WXPRINT(...) XPRINT(__VA_ARGS__)
/**
    @brief Platform-specific memory allocation macro.
            Allocates a block of memory of specified _SIZE.
    @param _SIZE The _SIZE of memory block to allocate.
    @return Pointer to the allocated memory block, or NULL if the allocation fails.
*/
#   define WXMALLOC(_T, _SIZE) XMALLOC((_T), (_SIZE))
/**
    @brief Platform-specific contiguous memory allocation macro.
            Allocates memory for an array of elements, initializes to zero.
    @param _N Number of elements.
    @param _SIZE Size of each element.
    @return Pointer to the allocated memory block, or NULL if the allocation fails.
*/
#   define WXCALLOC(_T, _N, _SIZE) XCALLOC((_T), (_N), (_SIZE))
/**
    @brief Platform-specific contiguous memory reallocation macro.
            Reallocation of an existant memory.
    @param _N Number of elements.
    @param _SIZE Size of each element.
    @return Pointer to the allocated memory block, or NULL if the allocation fails.
*/
#   define WXREALLOC(_PTR, _T, _N, _SIZE) XREALLOC((_T), (_PTR), (_N), (_SIZE))
/**
    @brief Platform-specific memory free macro.
            Frees a previously allocated block of memory.
    @param _PTR Pointer to the memory block to be freed.
*/
#   define WXFREE(_PTR) XFREE((_PTR))
/**
    @brief Platform-specific array allocation macro.
            Allocates memory for an array of specified _T and number of elements.
    @param _T The data _T of the array elements.
    @param _N Number of elements in the array.
    @return Pointer to the allocated memory block, or NULL if the allocation fails.
*/
#   define WXMALLOC_ARRAY(_T, _N) XMALLOC_ARRAY((_T), (_N))
/**
    @brief Platform-specific contiguous array allocation macro.
            Allocates memory for an array of specified type and number of elements, initializes to zero.
    @param _T The data type of the array elements.
    @param _N Number of elements in the array.
    @return Pointer to the allocated memory block, or NULL if the allocation fails.
*/
#   define WXCALLOC_ARRAY(_T, _N) XCALLOC_ARRAY((_N), (_T))
/**
    @brief Platform-specific array free macro.
            Frees a previously allocated block of array memory.
    @param _PTR Pointer to the array memory block to be freed.
*/
#   define WXFREE_ARRAY(_PTR) XFREE((_PTR))
#endif /* __WRAPPERS__ */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_COMPILER_H__ */