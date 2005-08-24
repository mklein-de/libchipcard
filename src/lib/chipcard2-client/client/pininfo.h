/* This file is auto-generated from "pininfo.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifndef PININFO_H
#define PININFO_H

/** @page P_LC_PININFO_PUBLIC LC_PinInfo (public)
This page describes the properties of LC_PININFO
@anchor LC_PININFO_Name
<h3>Name</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetName, 
get it with @ref LC_PinInfo_GetName
</p>

@anchor LC_PININFO_Id
<h3>Id</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetId, 
get it with @ref LC_PinInfo_GetId
</p>

@anchor LC_PININFO_Encoding
<h3>Encoding</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetEncoding, 
get it with @ref LC_PinInfo_GetEncoding
</p>

@anchor LC_PININFO_MinLength
<h3>MinLength</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetMinLength, 
get it with @ref LC_PinInfo_GetMinLength
</p>

@anchor LC_PININFO_MaxLength
<h3>MaxLength</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetMaxLength, 
get it with @ref LC_PinInfo_GetMaxLength
</p>

@anchor LC_PININFO_AllowChange
<h3>AllowChange</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetAllowChange, 
get it with @ref LC_PinInfo_GetAllowChange
</p>

@anchor LC_PININFO_Filler
<h3>Filler</h3>
<p>
</p>
<p>
Set this property with @ref LC_PinInfo_SetFiller, 
get it with @ref LC_PinInfo_GetFiller
</p>

*/
#ifdef __cplusplus
extern "C" {
#endif

typedef struct LC_PININFO LC_PININFO;

#ifdef __cplusplus
} /* __cplusplus */
#endif

#include <gwenhywfar/db.h>
#include <gwenhywfar/inherit.h>
#include <gwenhywfar/list2.h>
#include <gwenhywfar/types.h>
#include <chipcard2/chipcard2.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  LC_PinInfo_EncodingUnknown=-1,
  /** No encoding given.  */
  LC_PinInfo_EncodingNone=0,
  /** Binary encoding.  */
  LC_PinInfo_EncodingBin,
  /** BCD encoding.  */
  LC_PinInfo_EncodingBcd,
  /** ASCII encoding  */
  LC_PinInfo_EncodingAscii,
  /** FPIN2 encoding  */
  LC_PinInfo_EncodingFpin2
} LC_PININFO_ENCODING;

LC_PININFO_ENCODING LC_PinInfo_Encoding_fromString(const char *s);
const char *LC_PinInfo_Encoding_toString(LC_PININFO_ENCODING v);

GWEN_INHERIT_FUNCTION_LIB_DEFS(LC_PININFO, CHIPCARD_API)
GWEN_LIST2_FUNCTION_LIB_DEFS(LC_PININFO, LC_PinInfo, CHIPCARD_API)

/** Destroys all objects stored in the given LIST2 and the list itself
*/
CHIPCARD_API void LC_PinInfo_List2_freeAll(LC_PININFO_LIST2 *stl);
/** Creates a deep copy of the given LIST2.
*/
CHIPCARD_API LC_PININFO_LIST2 *LC_PinInfo_List2_dup(const LC_PININFO_LIST2 *stl);

/** Creates a new object.
*/
CHIPCARD_API LC_PININFO *LC_PinInfo_new();
/** Destroys the given object.
*/
CHIPCARD_API void LC_PinInfo_free(LC_PININFO *st);
/** Increments the usage counter of the given object, so an additional free() is needed to destroy the object.
*/
CHIPCARD_API void LC_PinInfo_Attach(LC_PININFO *st);
/** Creates and returns a deep copy of thegiven object.
*/
CHIPCARD_API LC_PININFO *LC_PinInfo_dup(const LC_PININFO*st);
/** Creates an object from the data in the given GWEN_DB_NODE
*/
CHIPCARD_API LC_PININFO *LC_PinInfo_fromDb(GWEN_DB_NODE *db);
/** Stores an object in the given GWEN_DB_NODE
*/
CHIPCARD_API int LC_PinInfo_toDb(const LC_PININFO*st, GWEN_DB_NODE *db);
/** Returns 0 if this object has not been modified, !=0 otherwise
*/
CHIPCARD_API int LC_PinInfo_IsModified(const LC_PININFO *st);
/** Sets the modified state of the given object
*/
CHIPCARD_API void LC_PinInfo_SetModified(LC_PININFO *st, int i);


/**
* Returns the property @ref LC_PININFO_Name
*/
CHIPCARD_API const char *LC_PinInfo_GetName(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_Name
*/
CHIPCARD_API void LC_PinInfo_SetName(LC_PININFO *el, const char *d);

/**
* Returns the property @ref LC_PININFO_Id
*/
CHIPCARD_API GWEN_TYPE_UINT32 LC_PinInfo_GetId(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_Id
*/
CHIPCARD_API void LC_PinInfo_SetId(LC_PININFO *el, GWEN_TYPE_UINT32 d);

/**
* Returns the property @ref LC_PININFO_Encoding
*/
CHIPCARD_API LC_PININFO_ENCODING LC_PinInfo_GetEncoding(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_Encoding
*/
CHIPCARD_API void LC_PinInfo_SetEncoding(LC_PININFO *el, LC_PININFO_ENCODING d);

/**
* Returns the property @ref LC_PININFO_MinLength
*/
CHIPCARD_API int LC_PinInfo_GetMinLength(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_MinLength
*/
CHIPCARD_API void LC_PinInfo_SetMinLength(LC_PININFO *el, int d);

/**
* Returns the property @ref LC_PININFO_MaxLength
*/
CHIPCARD_API int LC_PinInfo_GetMaxLength(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_MaxLength
*/
CHIPCARD_API void LC_PinInfo_SetMaxLength(LC_PININFO *el, int d);

/**
* Returns the property @ref LC_PININFO_AllowChange
*/
CHIPCARD_API int LC_PinInfo_GetAllowChange(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_AllowChange
*/
CHIPCARD_API void LC_PinInfo_SetAllowChange(LC_PININFO *el, int d);

/**
* Returns the property @ref LC_PININFO_Filler
*/
CHIPCARD_API int LC_PinInfo_GetFiller(const LC_PININFO *el);
/**
* Set the property @ref LC_PININFO_Filler
*/
CHIPCARD_API void LC_PinInfo_SetFiller(LC_PININFO *el, int d);


#ifdef __cplusplus
} /* __cplusplus */
#endif


#endif /* PININFO_H */
