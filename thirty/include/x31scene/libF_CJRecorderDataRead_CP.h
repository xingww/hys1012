//
// MATLAB Compiler: 6.3 (R2016b)
// Date: Wed Jun 03 16:23:09 2020
// Arguments: "-B" "macro_default" "-W" "cpplib:libF_CJRecorderDataRead_CP"
// "-T" "link:lib" "-d" "F:\1\X1\CJ\libF_CJRecorderDataRead_CP\for_testing"
// "-v" "F:\1\X1\CJ\F_CJRecorderDataRead_CP.m" 
//

#ifndef __libF_CJRecorderDataRead_CP_h
#define __libF_CJRecorderDataRead_CP_h 1

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

#ifdef EXPORTING_libF_CJRecorderDataRead_CP
#define PUBLIC_libF_CJRecorderDataRead_CP_C_API __global
#else
#define PUBLIC_libF_CJRecorderDataRead_CP_C_API /* No import statement needed. */
#endif

#define LIB_libF_CJRecorderDataRead_CP_C_API PUBLIC_libF_CJRecorderDataRead_CP_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libF_CJRecorderDataRead_CP
#define PUBLIC_libF_CJRecorderDataRead_CP_C_API __declspec(dllexport)
#else
#define PUBLIC_libF_CJRecorderDataRead_CP_C_API __declspec(dllimport)
#endif

#define LIB_libF_CJRecorderDataRead_CP_C_API PUBLIC_libF_CJRecorderDataRead_CP_C_API


#else

#define LIB_libF_CJRecorderDataRead_CP_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libF_CJRecorderDataRead_CP_C_API 
#define LIB_libF_CJRecorderDataRead_CP_C_API /* No special import/export declaration */
#endif

extern LIB_libF_CJRecorderDataRead_CP_C_API 
bool MW_CALL_CONV libF_CJRecorderDataRead_CPInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libF_CJRecorderDataRead_CP_C_API 
bool MW_CALL_CONV libF_CJRecorderDataRead_CPInitialize(void);

extern LIB_libF_CJRecorderDataRead_CP_C_API 
void MW_CALL_CONV libF_CJRecorderDataRead_CPTerminate(void);



extern LIB_libF_CJRecorderDataRead_CP_C_API 
void MW_CALL_CONV libF_CJRecorderDataRead_CPPrintStackTrace(void);

extern LIB_libF_CJRecorderDataRead_CP_C_API 
bool MW_CALL_CONV mlxF_CJRecorderDataRead_CP(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libF_CJRecorderDataRead_CP
#define PUBLIC_libF_CJRecorderDataRead_CP_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libF_CJRecorderDataRead_CP_CPP_API __declspec(dllimport)
#endif

#define LIB_libF_CJRecorderDataRead_CP_CPP_API PUBLIC_libF_CJRecorderDataRead_CP_CPP_API

#else

#if !defined(LIB_libF_CJRecorderDataRead_CP_CPP_API)
#if defined(LIB_libF_CJRecorderDataRead_CP_C_API)
#define LIB_libF_CJRecorderDataRead_CP_CPP_API LIB_libF_CJRecorderDataRead_CP_C_API
#else
#define LIB_libF_CJRecorderDataRead_CP_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libF_CJRecorderDataRead_CP_CPP_API void MW_CALL_CONV F_CJRecorderDataRead_CP(int nargout, mwArray& SaveDataCP_all, mwArray& CP_timedata_all, mwArray& CP_len, const mwArray& filepath);

#endif
#endif
