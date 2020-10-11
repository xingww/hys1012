//
// MATLAB Compiler: 6.3 (R2016b)
// Date: Fri Nov 15 16:34:59 2019
// Arguments: "-B" "macro_default" "-W" "cpplib:libgetStartT0" "-T" "link:lib"
// "-d"
// "C:\Users\Administrator\Desktop\1\3x9AdataAy_V2.1\libgetStartT0\for_testing"
// "-v"
// "C:\Users\Administrator\Desktop\1\3x9AdataAy_V2.1\function\getStartT0.m" 
//

#ifndef __libgetStartT0_h
#define __libgetStartT0_h 1

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

#ifdef EXPORTING_libgetStartT0
#define PUBLIC_libgetStartT0_C_API __global
#else
#define PUBLIC_libgetStartT0_C_API /* No import statement needed. */
#endif

#define LIB_libgetStartT0_C_API PUBLIC_libgetStartT0_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libgetStartT0
#define PUBLIC_libgetStartT0_C_API __declspec(dllexport)
#else
#define PUBLIC_libgetStartT0_C_API __declspec(dllimport)
#endif

#define LIB_libgetStartT0_C_API PUBLIC_libgetStartT0_C_API


#else

#define LIB_libgetStartT0_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libgetStartT0_C_API 
#define LIB_libgetStartT0_C_API /* No special import/export declaration */
#endif

extern LIB_libgetStartT0_C_API 
bool MW_CALL_CONV libgetStartT0InitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libgetStartT0_C_API 
bool MW_CALL_CONV libgetStartT0Initialize(void);

extern LIB_libgetStartT0_C_API 
void MW_CALL_CONV libgetStartT0Terminate(void);



extern LIB_libgetStartT0_C_API 
void MW_CALL_CONV libgetStartT0PrintStackTrace(void);

extern LIB_libgetStartT0_C_API 
bool MW_CALL_CONV mlxGetStartT0(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libgetStartT0
#define PUBLIC_libgetStartT0_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libgetStartT0_CPP_API __declspec(dllimport)
#endif

#define LIB_libgetStartT0_CPP_API PUBLIC_libgetStartT0_CPP_API

#else

#if !defined(LIB_libgetStartT0_CPP_API)
#if defined(LIB_libgetStartT0_C_API)
#define LIB_libgetStartT0_CPP_API LIB_libgetStartT0_C_API
#else
#define LIB_libgetStartT0_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libgetStartT0_CPP_API void MW_CALL_CONV getStartT0(int nargout, mwArray& tstr, const mwArray& filepath2);

#endif
#endif
