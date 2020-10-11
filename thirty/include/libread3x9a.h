//
// MATLAB Compiler: 6.3 (R2016b)
// Date: Tue Apr 07 10:10:16 2020
// Arguments: "-B" "macro_default" "-W" "cpplib:libread3x9a" "-T" "link:lib"
// "-d" "F:\1\3x9AdataAy_V2.1\libread3x9a\for_testing" "-v"
// "F:\1\3x9AdataAy_V2.1\function\read3x9a.m" 
//

#ifndef __libread3x9a_h
#define __libread3x9a_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_libread3x9a
#define PUBLIC_libread3x9a_C_API __global
#else
#define PUBLIC_libread3x9a_C_API /* No import statement needed. */
#endif

#define LIB_libread3x9a_C_API PUBLIC_libread3x9a_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libread3x9a
#define PUBLIC_libread3x9a_C_API __declspec(dllexport)
#else
#define PUBLIC_libread3x9a_C_API __declspec(dllimport)
#endif

#define LIB_libread3x9a_C_API PUBLIC_libread3x9a_C_API


#else

#define LIB_libread3x9a_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libread3x9a_C_API 
#define LIB_libread3x9a_C_API /* No special import/export declaration */
#endif

extern LIB_libread3x9a_C_API 
bool MW_CALL_CONV libread3x9aInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libread3x9a_C_API 
bool MW_CALL_CONV libread3x9aInitialize(void);

extern LIB_libread3x9a_C_API 
void MW_CALL_CONV libread3x9aTerminate(void);



extern LIB_libread3x9a_C_API 
void MW_CALL_CONV libread3x9aPrintStackTrace(void);

extern LIB_libread3x9a_C_API 
bool MW_CALL_CONV mlxRead3x9a(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libread3x9a
#define PUBLIC_libread3x9a_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libread3x9a_CPP_API __declspec(dllimport)
#endif

#define LIB_libread3x9a_CPP_API PUBLIC_libread3x9a_CPP_API

#else

#if !defined(LIB_libread3x9a_CPP_API)
#if defined(LIB_libread3x9a_C_API)
#define LIB_libread3x9a_CPP_API LIB_libread3x9a_C_API
#else
#define LIB_libread3x9a_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libread3x9a_CPP_API void MW_CALL_CONV read3x9a(const mwArray& tstr, const mwArray& filepath2);

#endif
#endif
