//
// MATLAB Compiler: 6.3 (R2016b)
// Date: Sat May 09 22:56:12 2020
// Arguments: "-B" "macro_default" "-W" "cpplib:libF_HFM_Processing" "-T"
// "link:lib" "-d"
// "C:\Users\Administrator\Desktop\func\libF_HFM_Processing\for_testing" "-v"
// "C:\Users\Administrator\Desktop\func\F_HFM_Processing.m" 
//

#ifndef __libF_HFM_Processing_h
#define __libF_HFM_Processing_h 1

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

#ifdef EXPORTING_libF_HFM_Processing
#define PUBLIC_libF_HFM_Processing_C_API __global
#else
#define PUBLIC_libF_HFM_Processing_C_API /* No import statement needed. */
#endif

#define LIB_libF_HFM_Processing_C_API PUBLIC_libF_HFM_Processing_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libF_HFM_Processing
#define PUBLIC_libF_HFM_Processing_C_API __declspec(dllexport)
#else
#define PUBLIC_libF_HFM_Processing_C_API __declspec(dllimport)
#endif

#define LIB_libF_HFM_Processing_C_API PUBLIC_libF_HFM_Processing_C_API


#else

#define LIB_libF_HFM_Processing_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libF_HFM_Processing_C_API 
#define LIB_libF_HFM_Processing_C_API /* No special import/export declaration */
#endif

extern LIB_libF_HFM_Processing_C_API 
bool MW_CALL_CONV libF_HFM_ProcessingInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libF_HFM_Processing_C_API 
bool MW_CALL_CONV libF_HFM_ProcessingInitialize(void);

extern LIB_libF_HFM_Processing_C_API 
void MW_CALL_CONV libF_HFM_ProcessingTerminate(void);



extern LIB_libF_HFM_Processing_C_API 
void MW_CALL_CONV libF_HFM_ProcessingPrintStackTrace(void);

extern LIB_libF_HFM_Processing_C_API 
bool MW_CALL_CONV mlxF_HFM_Processing(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libF_HFM_Processing
#define PUBLIC_libF_HFM_Processing_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libF_HFM_Processing_CPP_API __declspec(dllimport)
#endif

#define LIB_libF_HFM_Processing_CPP_API PUBLIC_libF_HFM_Processing_CPP_API

#else

#if !defined(LIB_libF_HFM_Processing_CPP_API)
#if defined(LIB_libF_HFM_Processing_C_API)
#define LIB_libF_HFM_Processing_CPP_API LIB_libF_HFM_Processing_C_API
#else
#define LIB_libF_HFM_Processing_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libF_HFM_Processing_CPP_API void MW_CALL_CONV F_HFM_Processing(int nargout, mwArray& XK_MfM, mwArray& XK_MfM_len, const mwArray& dataAll, const mwArray& Flag_FDSX);

#endif
#endif
