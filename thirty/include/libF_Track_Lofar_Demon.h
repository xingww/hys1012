//
// MATLAB Compiler: 6.3 (R2016b)
// Date: Mon Jun 08 11:10:25 2020
// Arguments: "-B" "macro_default" "-W" "cpplib:libF_Track_Lofar_Demon" "-T"
// "link:lib" "-d" "F:\1\X1\function\libF_Track_Lofar_Demon\for_testing" "-v"
// "F:\1\X1\function\F_Track_Lofar_Demon.m" 
//

#ifndef __libF_Track_Lofar_Demon_h
#define __libF_Track_Lofar_Demon_h 1

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

#ifdef EXPORTING_libF_Track_Lofar_Demon
#define PUBLIC_libF_Track_Lofar_Demon_C_API __global
#else
#define PUBLIC_libF_Track_Lofar_Demon_C_API /* No import statement needed. */
#endif

#define LIB_libF_Track_Lofar_Demon_C_API PUBLIC_libF_Track_Lofar_Demon_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libF_Track_Lofar_Demon
#define PUBLIC_libF_Track_Lofar_Demon_C_API __declspec(dllexport)
#else
#define PUBLIC_libF_Track_Lofar_Demon_C_API __declspec(dllimport)
#endif

#define LIB_libF_Track_Lofar_Demon_C_API PUBLIC_libF_Track_Lofar_Demon_C_API


#else

#define LIB_libF_Track_Lofar_Demon_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libF_Track_Lofar_Demon_C_API 
#define LIB_libF_Track_Lofar_Demon_C_API /* No special import/export declaration */
#endif

extern LIB_libF_Track_Lofar_Demon_C_API 
bool MW_CALL_CONV libF_Track_Lofar_DemonInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libF_Track_Lofar_Demon_C_API 
bool MW_CALL_CONV libF_Track_Lofar_DemonInitialize(void);

extern LIB_libF_Track_Lofar_Demon_C_API 
void MW_CALL_CONV libF_Track_Lofar_DemonTerminate(void);



extern LIB_libF_Track_Lofar_Demon_C_API 
void MW_CALL_CONV libF_Track_Lofar_DemonPrintStackTrace(void);

extern LIB_libF_Track_Lofar_Demon_C_API 
bool MW_CALL_CONV mlxF_Track_Lofar_Demon(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                         *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libF_Track_Lofar_Demon
#define PUBLIC_libF_Track_Lofar_Demon_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libF_Track_Lofar_Demon_CPP_API __declspec(dllimport)
#endif

#define LIB_libF_Track_Lofar_Demon_CPP_API PUBLIC_libF_Track_Lofar_Demon_CPP_API

#else

#if !defined(LIB_libF_Track_Lofar_Demon_CPP_API)
#if defined(LIB_libF_Track_Lofar_Demon_C_API)
#define LIB_libF_Track_Lofar_Demon_CPP_API LIB_libF_Track_Lofar_Demon_C_API
#else
#define LIB_libF_Track_Lofar_Demon_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libF_Track_Lofar_Demon_CPP_API void MW_CALL_CONV F_Track_Lofar_Demon(int nargout, mwArray& SX_TLofar, mwArray& SX_TDemon, const mwArray& Multi_lofar, const mwArray& Track_num_X, const mwArray& Flag_FDSX);

#endif
#endif
