//
// MATLAB Compiler: 6.3 (R2016b)
// Date: Wed Jun 03 16:28:47 2020
// Arguments: "-B" "macro_default" "-W"
// "cpplib:libF_CJRecorderDataRead_HFMTRACK" "-T" "link:lib" "-d"
// "F:\1\X1\CJ\libF_CJRecorderDataRead_HFMTRACK\for_testing" "-v"
// "F:\1\X1\CJ\F_CJRecorderDataRead_HFMTRACK.m" 
//

#ifndef __libF_CJRecorderDataRead_HFMTRACK_h
#define __libF_CJRecorderDataRead_HFMTRACK_h 1

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

#ifdef EXPORTING_libF_CJRecorderDataRead_HFMTRACK
#define PUBLIC_libF_CJRecorderDataRead_HFMTRACK_C_API __global
#else
#define PUBLIC_libF_CJRecorderDataRead_HFMTRACK_C_API /* No import statement needed. */
#endif

#define LIB_libF_CJRecorderDataRead_HFMTRACK_C_API PUBLIC_libF_CJRecorderDataRead_HFMTRACK_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libF_CJRecorderDataRead_HFMTRACK
#define PUBLIC_libF_CJRecorderDataRead_HFMTRACK_C_API __declspec(dllexport)
#else
#define PUBLIC_libF_CJRecorderDataRead_HFMTRACK_C_API __declspec(dllimport)
#endif

#define LIB_libF_CJRecorderDataRead_HFMTRACK_C_API PUBLIC_libF_CJRecorderDataRead_HFMTRACK_C_API


#else

#define LIB_libF_CJRecorderDataRead_HFMTRACK_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libF_CJRecorderDataRead_HFMTRACK_C_API 
#define LIB_libF_CJRecorderDataRead_HFMTRACK_C_API /* No special import/export declaration */
#endif

extern LIB_libF_CJRecorderDataRead_HFMTRACK_C_API 
bool MW_CALL_CONV libF_CJRecorderDataRead_HFMTRACKInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libF_CJRecorderDataRead_HFMTRACK_C_API 
bool MW_CALL_CONV libF_CJRecorderDataRead_HFMTRACKInitialize(void);

extern LIB_libF_CJRecorderDataRead_HFMTRACK_C_API 
void MW_CALL_CONV libF_CJRecorderDataRead_HFMTRACKTerminate(void);



extern LIB_libF_CJRecorderDataRead_HFMTRACK_C_API 
void MW_CALL_CONV libF_CJRecorderDataRead_HFMTRACKPrintStackTrace(void);

extern LIB_libF_CJRecorderDataRead_HFMTRACK_C_API 
bool MW_CALL_CONV mlxF_CJRecorderDataRead_HFMTRACK(int nlhs, mxArray *plhs[], int nrhs, 
                                                   mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libF_CJRecorderDataRead_HFMTRACK
#define PUBLIC_libF_CJRecorderDataRead_HFMTRACK_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libF_CJRecorderDataRead_HFMTRACK_CPP_API __declspec(dllimport)
#endif

#define LIB_libF_CJRecorderDataRead_HFMTRACK_CPP_API PUBLIC_libF_CJRecorderDataRead_HFMTRACK_CPP_API

#else

#if !defined(LIB_libF_CJRecorderDataRead_HFMTRACK_CPP_API)
#if defined(LIB_libF_CJRecorderDataRead_HFMTRACK_C_API)
#define LIB_libF_CJRecorderDataRead_HFMTRACK_CPP_API LIB_libF_CJRecorderDataRead_HFMTRACK_C_API
#else
#define LIB_libF_CJRecorderDataRead_HFMTRACK_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libF_CJRecorderDataRead_HFMTRACK_CPP_API void MW_CALL_CONV F_CJRecorderDataRead_HFMTRACK(int nargout, mwArray& SaveDataHFMTRACK_all, mwArray& HFMTRACK_timedata_all, mwArray& HFMTRACK_len, const mwArray& filepath);

#endif
#endif
