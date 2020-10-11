//
// MATLAB Compiler: 6.3 (R2016b)
// Date: Mon Nov 18 15:28:37 2019
// Arguments: "-B" "macro_default" "-W" "cpplib:libdat3x9apre" "-T" "link:lib"
// "-d" "F:\1\3x9AdataAy_V2.1\libdat3x9apre\for_testing" "-v"
// "F:\1\3x9AdataAy_V2.1\function\dat3x9apre.m" 
//

#ifndef __libdat3x9apre_h
#define __libdat3x9apre_h 1

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

#ifdef EXPORTING_libdat3x9apre
#define PUBLIC_libdat3x9apre_C_API __global
#else
#define PUBLIC_libdat3x9apre_C_API /* No import statement needed. */
#endif

#define LIB_libdat3x9apre_C_API PUBLIC_libdat3x9apre_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libdat3x9apre
#define PUBLIC_libdat3x9apre_C_API __declspec(dllexport)
#else
#define PUBLIC_libdat3x9apre_C_API __declspec(dllimport)
#endif

#define LIB_libdat3x9apre_C_API PUBLIC_libdat3x9apre_C_API


#else

#define LIB_libdat3x9apre_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libdat3x9apre_C_API 
#define LIB_libdat3x9apre_C_API /* No special import/export declaration */
#endif

extern LIB_libdat3x9apre_C_API 
bool MW_CALL_CONV libdat3x9apreInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libdat3x9apre_C_API 
bool MW_CALL_CONV libdat3x9apreInitialize(void);

extern LIB_libdat3x9apre_C_API 
void MW_CALL_CONV libdat3x9apreTerminate(void);



extern LIB_libdat3x9apre_C_API 
void MW_CALL_CONV libdat3x9aprePrintStackTrace(void);

extern LIB_libdat3x9apre_C_API 
bool MW_CALL_CONV mlxDat3x9apre(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libdat3x9apre
#define PUBLIC_libdat3x9apre_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libdat3x9apre_CPP_API __declspec(dllimport)
#endif

#define LIB_libdat3x9apre_CPP_API PUBLIC_libdat3x9apre_CPP_API

#else

#if !defined(LIB_libdat3x9apre_CPP_API)
#if defined(LIB_libdat3x9apre_C_API)
#define LIB_libdat3x9apre_CPP_API LIB_libdat3x9apre_C_API
#else
#define LIB_libdat3x9apre_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libdat3x9apre_CPP_API void MW_CALL_CONV dat3x9apre(const mwArray& filepath1);

#endif
#endif
