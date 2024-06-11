/**
 * @file Wx_Wrappers.h
 * @brief Platform-specific wrappers for various functions and macros.
 * @version 0.2
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

/** @brief Header guard */
#if !defined(__WX_WRAPPERS_H__)
#define __WX_WRAPPERS_H__

/** @brief C++ name mangling guard */
#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* (__cplusplus) || defined(c_plusplus) */

#include "Wx_StdTypes.h"

/*----------------------------------------------------------------------------*/
/** @brief Define platform macros */
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
#   include <string.h>

#   define XPRINT(_FMT, ...) printf((_FMT), ##__VA_ARGS__)
#   define XMALLOC(_T, _SIZE) (_T*)malloc((_SIZE))
#   define XCALLOC(_T, _N, _SIZE) (_T*)calloc((_N), (_SIZE))
#   define XREALLOC(_T, _PTR, _N, _SIZE) (_T*)realloc((_PTR), ((_N) * (_SIZE)))
#   define XFREE(_PTR) free((_PTR))
#   define XMALLOC_ARRAY(_T, _N) (_T*)malloc(sizeof(_T) * (_N))
#   define XCALLOC_ARRAY(_T, _N) (_T*)calloc((_N), sizeof(_T))
#   define XFREE_ARRAY(_PTR) free((_PTR))

#   define XSTRLEN(_STR) strlen((_STR))
#   define XSTRCMP(_STR1, _STR2) strcmp((_STR1), (_STR2))
#   define XSTRNCMP(_STR1, _STR2, _N) strncmp((_STR1), (_STR2), (_N))
#   define XSTRCPY(_DEST, _SRC) strcpy((_DEST), (_SRC))
#   define XSTRNCPY(_DEST, _SRC, _N) strncpy((_DEST), (_SRC), (_N))
#   define XSTRCAT(_DEST, _SRC) strcat((_DEST), (_SRC))
#   define XSTRNCAT(_DEST, _SRC, _N) strncat((_DEST), (_SRC), (_N))
#   define XMEMSET(_PTR, _VAL, _SIZE) memset((_PTR), (_VAL), (_SIZE))
#   define XMEMCPY(_DEST, _SRC, _SIZE) memcpy((_DEST), (_SRC), (_SIZE))
#   define XMEMMOVE(_DEST, _SRC, _SIZE) memmove((_DEST), (_SRC), (_SIZE))
#   define XMEMCMP(_PTR1, _PTR2, _SIZE) memcmp((_PTR1), (_PTR2), (_SIZE))

#elif defined(WX_PLATFORM_LINUX)
#   include <stdio.h>
#   include <stdlib.h>
#   include <string.h>

#   define XPRINT(_FMT, ...) printf((_FMT), ##__VA_ARGS__)
#   define XMALLOC(_T, _SIZE) (_T*)malloc((_SIZE))
#   define XCALLOC(_T, _N, _SIZE) (_T*)calloc((_N), (_SIZE))
#   define XREALLOC(_T, _PTR, _N, _SIZE) (_T*)realloc((_PTR), ((_N) * (_SIZE)))
#   define XFREE(_PTR) free((_PTR))
#   define XMALLOC_ARRAY(_T, _N) (_T*)malloc(sizeof(_T) * (_N))
#   define XCALLOC_ARRAY(_T, _N) (_T*)calloc((_N), sizeof(_T))
#   define XFREE_ARRAY(_PTR) free((_PTR))

#   define XSTRLEN(_STR) strlen((_STR))
#   define XSTRCMP(_STR1, _STR2) strcmp((_STR1), (_STR2))
#   define XSTRNCMP(_STR1, _STR2, _N) strncmp((_STR1), (_STR2), (_N))
#   define XSTRCPY(_DEST, _SRC) strcpy((_DEST), (_SRC))
#   define XSTRNCPY(_DEST, _SRC, _N) strncpy((_DEST), (_SRC), (_N))
#   define XSTRCAT(_DEST, _SRC) strcat((_DEST), (_SRC))
#   define XSTRNCAT(_DEST, _SRC, _N) strncat((_DEST), (_SRC), (_N))
#   define XMEMSET(_PTR, _VAL, _SIZE) memset((_PTR), (_VAL), (_SIZE))
#   define XMEMCPY(_DEST, _SRC, _SIZE) memcpy((_DEST), (_SRC), (_SIZE))
#   define XMEMMOVE(_DEST, _SRC, _SIZE) memmove((_DEST), (_SRC), (_SIZE))
#   define XMEMCMP(_PTR1, _PTR2, _SIZE) memcmp((_PTR1), (_PTR2), (_SIZE))

#elif defined(WX_PLATFORM_MAC)
#   include <stdio.h>
#   include <stdlib.h>
#   include <string.h>

#   define XPRINT(_FMT, ...) printf((_FMT), ##__VA_ARGS__)
#   define XMALLOC(_T, _SIZE) (_T*)malloc((_SIZE))
#   define XCALLOC(_T, _N, _SIZE) (_T*)calloc((_N), (_SIZE))
#   define XREALLOC(_T, _PTR, _N, _SIZE) (_T*)realloc((_PTR), ((_N) * (_SIZE)))
#   define XFREE(_PTR) free((_PTR))
#   define XMALLOC_ARRAY(_T, _N) (_T*)malloc(sizeof(_T) * (_N))
#   define XCALLOC_ARRAY(_T, _N) (_T*)calloc((_N), sizeof(_T))
#   define XFREE_ARRAY(_PTR) free((_PTR))

#   define XSTRLEN(_STR) strlen((_STR))
#   define XSTRCMP(_STR1, _STR2) strcmp((_STR1), (_STR2))
#   define XSTRNCMP(_STR1, _STR2, _N) strncmp((_STR1), (_STR2), (_N))
#   define XSTRCPY(_DEST, _SRC) strcpy((_DEST), (_SRC))
#   define XSTRNCPY(_DEST, _SRC, _N) strncpy((_DEST), (_SRC), (_N))
#   define XSTRCAT(_DEST, _SRC) strcat((_DEST), (_SRC))
#   define XSTRNCAT(_DEST, _SRC, _N) strncat((_DEST), (_SRC), (_N))
#   define XMEMSET(_PTR, _VAL, _SIZE) memset((_PTR), (_VAL), (_SIZE))
#   define XMEMCPY(_DEST, _SRC, _SIZE) memcpy((_DEST), (_SRC), (_SIZE))
#   define XMEMMOVE(_DEST, _SRC, _SIZE) memmove((_DEST), (_SRC), (_SIZE))
#   define XMEMCMP(_PTR1, _PTR2, _SIZE) memcmp((_PTR1), (_PTR2), (_SIZE))

#else
#   warning "Unsupported platform!"
#   define XPRINT(_FMT, ...)
#   define XMALLOC(_T, _SIZE) NULL
#   define XCALLOC(_T, _N, _SIZE) NULL
#   define XREALLOC(_T, _PTR, _N, _SIZE) NULL
#   define XFREE(_PTR)
#   define XMALLOC_ARRAY(_T, _N) NULL
#   define XCALLOC_ARRAY(_T, _N) NULL
#   define XFREE_ARRAY(_PTR)

#   define XSTRLEN(_STR) 0
#   define XSTRCMP(_STR1, _STR2) 0
#   define XSTRNCMP(_STR1, _STR2, _N) 0
#   define XSTRCPY(_DEST, _SRC) (_DEST)
#   define XSTRNCPY(_DEST, _SRC, _N) (_DEST)
#   define XSTRCAT(_DEST, _SRC) (_DEST)
#   define XSTRNCAT(_DEST, _SRC, _N) (_DEST)
#   define XMEMSET(_PTR, _VAL, _SIZE) (_PTR)
#   define XMEMCPY(_DEST, _SRC, _SIZE) (_DEST)
#   define XMEMMOVE(_DEST, _SRC, _SIZE) (_DEST)
#   define XMEMCMP(_PTR1, _PTR2, _SIZE) 0

#endif

#if defined(__WRAPPERS__)
/**
 * @defgroup WX_Memory Memory Management Functions
 * @{
 */

/**
 * @brief 
 * 
 * @param _FMT The format string.
 * @param... The format arguments.
 * @return Number of characters printed.
 * 
 * @code
 * int code_num = 3;
 * WXPRINT("This is code %d", code_num);
 * @endcode
 */
#   define WXPRINT(_FMT, ...) XPRINT((_FMT), ##__VA_ARGS__)

/**
 * @brief Allocates memory.
 * 
 * @param _T The type of the memory to allocate.
 * @param _SIZE The size of the memory to allocate.
 * @return A pointer to the allocated memory.
 * 
 * @code
 * int *arr = WXMALLOC(int, 10 * sizeof(int));
 * if (arr != NULL) {
 *     // Use the memory
 *     WXFREE(arr);
 * }
 * @endcode
 */
#   define WXMALLOC(_T, _SIZE) XMALLOC(_T, (_SIZE))

/**
 * @brief Allocates zero-initialized memory.
 * 
 * @param _T The type of the memory to allocate.
 * @param _N The number of elements to allocate.
 * @param _SIZE The size of each element.
 * @return A pointer to the allocated memory.
 * 
 * @code
 * int *arr = WXCALLOC(int, 10, sizeof(int));
 * if (arr != NULL) {
 *     // Use the memory
 *     WXFREE(arr);
 * }
 * @endcode
 */
#   define WXCALLOC(_T, _N, _SIZE) XCALLOC(_T, (_N), (_SIZE))

/**
 * @brief Reallocates memory.
 * 
 * @param _PTR The pointer to the existing memory block.
 * @param _T The type of the memory to reallocate.
 * @param _N The number of elements to allocate.
 * @param _SIZE The size of each element.
 * @return A pointer to the reallocated memory.
 * 
 * @code
 * int *arr = WXMALLOC(int, 10 * sizeof(int));
 * arr = WXREALLOC(arr, int, 20, sizeof(int));
 * if (arr != NULL) {
 *     // Use the memory
 *     WXFREE(arr);
 * }
 * @endcode
 */
#   define WXREALLOC(_PTR, _T, _N, _SIZE) XREALLOC(_T, (_PTR), (_N), (_SIZE))

/**
 * @brief Frees memory.
 * 
 * @param _PTR The pointer to the memory to free.
 * 
 * @code
 * int *arr = WXMALLOC(int, 10 * sizeof(int));
 * if (arr != NULL) {
 *     // Use the memory
 *     WXFREE(arr);
 * }
 * @endcode
 */
#   define WXFREE(_PTR) XFREE((_PTR))

/**
 * @brief Allocates memory for an array.
 * 
 * @param _T The type of the memory to allocate.
 * @param _N The number of elements to allocate.
 * @return A pointer to the allocated memory.
 * 
 * @code
 * int *arr = WXMALLOC_ARRAY(int, 10);
 * if (arr != NULL) {
 *     // Use the memory
 *     WXFREE_ARRAY(arr);
 * }
 * @endcode
 */
#   define WXMALLOC_ARRAY(_T, _N) XMALLOC_ARRAY(_T, (_N))

/**
 * @brief Allocates zero-initialized memory for an array.
 * 
 * @param _T The type of the memory to allocate.
 * @param _N The number of elements to allocate.
 * @return A pointer to the allocated memory.
 * 
 * @code
 * int *arr = WXCALLOC_ARRAY(int, 10);
 * if (arr != NULL) {
 *     // Use the memory
 *     WXFREE_ARRAY(arr);
 * }
 * @endcode
 */
#   define WXCALLOC_ARRAY(_T, _N) XCALLOC_ARRAY(_T, (_N))

/**
 * @brief Frees memory allocated for an array.
 * 
 * @param _PTR The pointer to the memory to free.
 * 
 * @code
 * int *arr = WXMALLOC_ARRAY(int, 10);
 * if (arr != NULL) {
 *     // Use the memory
 *     WXFREE_ARRAY(arr);
 * }
 * @endcode
 */
#   define WXFREE_ARRAY(_PTR) XFREE((_PTR))

/** @} */

/**
 * @defgroup WX_String String Management Functions
 * @{
 */

/**
 * @brief Gets the length of a string.
 * 
 * @param _STR The string to get the length of.
 * @return The length of the string.
 * 
 * @code
 * const char *str = "Hello, World!";
 * size_t len = WXSTRLEN(str);
 * @endcode
 */
#   define WXSTRLEN(_STR) XSTRLEN((_STR))

/**
 * @brief Compares two strings.
 * 
 * @param _STR1 The first string to compare.
 * @param _STR2 The second string to compare.
 * @return An integer less than, equal to, or greater than zero if _STR1 is found, respectively, to be less than, to match, or be greater than _STR2.
 * 
 * @code
 * const char *str1 = "Hello";
 * const char *str2 = "World";
 * int cmp = WXSTRCMP(str1, str2);
 * @endcode
 */
#   define WXSTRCMP(_STR1, _STR2) XSTRCMP((_STR1), (_STR2))

/**
 * @brief Compares up to _N characters of two strings.
 * 
 * @param _STR1 The first string to compare.
 * @param _STR2 The second string to compare.
 * @param _N The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if _STR1 is found, respectively, to be less than, to match, or be greater than _STR2.
 * 
 * @code
 * const char *str1 = "Hello";
 * const char *str2 = "Hello, World!";
 * int cmp = WXSTRNCMP(str1, str2, 5);
 * @endcode
 */
#   define WXSTRNCMP(_STR1, _STR2, _N) XSTRNCMP((_STR1), (_STR2), (_N))

/**
 * @brief Copies a string.
 * 
 * @param _DEST The destination buffer.
 * @param _SRC The source string.
 * @return A pointer to the destination string.
 * 
 * @code
 * char dest[50];
 * const char *src = "Hello, World!";
 * WXSTRCPY(dest, src);
 * @endcode
 */
#   define WXSTRCPY(_DEST, _SRC) XSTRCPY((_DEST), (_SRC))

/**
 * @brief Copies up to _N characters of a string.
 * 
 * @param _DEST The destination buffer.
 * @param _SRC The source string.
 * @param _N The maximum number of characters to copy.
 * @return A pointer to the destination string.
 * 
 * @code
 * char dest[50];
 * const char *src = "Hello, World!";
 * WXSTRNCPY(dest, src, 5);
 * @endcode
 */
#   define WXSTRNCPY(_DEST, _SRC, _N) XSTRNCPY((_DEST), (_SRC), (_N))

/**
 * @brief Concatenates two strings.
 * 
 * @param _DEST The destination buffer.
 * @param _SRC The source string.
 * @return A pointer to the destination string.
 * 
 * @code
 * char dest[50] = "Hello";
 * const char *src = ", World!";
 * WXSTRCAT(dest, src);
 * @endcode
 */
#   define WXSTRCAT(_DEST, _SRC) XSTRCAT((_DEST), (_SRC))

/**
 * @brief Concatenates up to _N characters of two strings.
 * 
 * @param _DEST The destination buffer.
 * @param _SRC The source string.
 * @param _N The maximum number of characters to concatenate.
 * @return A pointer to the destination string.
 * 
 * @code
 * char dest[50] = "Hello";
 * const char *src = ", World!";
 * WXSTRNCAT(dest, src, 5);
 * @endcode
 */
#   define WXSTRNCAT(_DEST, _SRC, _N) XSTRNCAT((_DEST), (_SRC), (_N))

/** @} */

/**
 * @defgroup WX_MemoryManip Memory Manipulation Functions
 * @{
 */

/**
 * @brief Sets a block of memory.
 * 
 * @param _PTR The pointer to the memory block.
 * @param _VAL The value to set.
 * @param _SIZE The size of the memory block.
 * @return A pointer to the memory block.
 * 
 * @code
 * int arr[10];
 * WXMEMSET(arr, 0, sizeof(arr));
 * @endcode
 */
#   define WXMEMSET(_PTR, _VAL, _SIZE) XMEMSET((_PTR), (_VAL), (_SIZE))

/**
 * @brief Copies a block of memory.
 * 
 * @param _DEST The destination memory block.
 * @param _SRC The source memory block.
 * @param _SIZE The size of the memory block.
 * @return A pointer to the destination memory block.
 * 
 * @code
 * int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 * int dest[10];
 * WXMEMCPY(dest, src, sizeof(src));
 * @endcode
 */
#   define WXMEMCPY(_DEST, _SRC, _SIZE) XMEMCPY((_DEST), (_SRC), (_SIZE))

/**
 * @brief Moves a block of memory.
 * 
 * @param _DEST The destination memory block.
 * @param _SRC The source memory block.
 * @param _SIZE The size of the memory block.
 * @return A pointer to the destination memory block.
 * 
 * @code
 * int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 * WXMEMMOVE(&arr[1], &arr[0], 9 * sizeof(int));
 * @endcode
 */
#   define WXMEMMOVE(_DEST, _SRC, _SIZE) XMEMMOVE((_DEST), (_SRC), (_SIZE))

/**
 * @brief Compares two blocks of memory.
 * 
 * @param _PTR1 The first memory block.
 * @param _PTR2 The second memory block.
 * @param _SIZE The size of the memory blocks.
 * @return An integer less than, equal to, or greater than zero if _PTR1 is found, respectively, to be less than, to match, or be greater than _PTR2.
 * 
 * @code
 * int arr1[5] = {1, 2, 3, 4, 5};
 * int arr2[5] = {1, 2, 3, 4, 5};
 * int cmp = WXMEMCMP(arr1, arr2, sizeof(arr1));
 * @endcode
 */
#   define WXMEMCMP(_PTR1, _PTR2, _SIZE) XMEMCMP((_PTR1), (_PTR2), (_SIZE))

/** @} */

#endif /* __WRAPPERS__ */

/*----------------------------------------------------------------------------*/
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */
#endif /* __WX_WRAPPERS_H__ */
