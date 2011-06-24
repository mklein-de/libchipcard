/* This file is auto-generated from "pininfo.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifndef PININFO_L_H
#define PININFO_L_H

/** @page P_LC_PININFO_LIB LC_PinInfo (lib)
This page describes the properties of LC_PININFO
@anchor LC_PININFO_RecordNum
<h3>RecordNum</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetRecordNum, 
get it with @ref LC_PinInfo_GetRecordNum
</p>

*/
#include <gwenhywfar/misc.h>
#include "pininfo.h"
#include <gwenhywfar/misc.h>

#ifdef __cplusplus
extern "C" {
#endif


GWEN_LIST_FUNCTION_DEFS(LC_PININFO, LC_PinInfo)
LC_PININFO_LIST *LC_PinInfo_List_dup(const LC_PININFO_LIST *stl);









/**
* Returns the property @ref LC_PININFO_RecordNum
*/
CHIPCARD_API int LC_PinInfo_GetRecordNum(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_RecordNum
*/
CHIPCARD_API void LC_PinInfo_SetRecordNum(LC_PININFO *el, int d);


#ifdef __cplusplus
} /* __cplusplus */
#endif


#endif /* PININFO_L_H */
