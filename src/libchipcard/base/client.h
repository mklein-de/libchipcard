/***************************************************************************
    begin       : Mon Mar 01 2004
    copyright   : (C) 2021 by Martin Preuss
    email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/


#ifndef CHIPCARD_CLIENT_CLIENT_H
#define CHIPCARD_CLIENT_CLIENT_H


/** @addtogroup chipcardc_client_app
 */
/*@{*/

#include <gwenhywfar/inherit.h>
#include <gwenhywfar/error.h>

#include <libchipcard/chipcard.h>


#ifdef __cplusplus
extern "C" {
#endif



typedef struct LC_CLIENT LC_CLIENT;
GWEN_INHERIT_FUNCTION_LIB_DEFS(LC_CLIENT, CHIPCARD_API)


/**
 * Targets for commands (used by @ref LC_Card_ExecApdu)
 */
typedef enum {
  LC_Client_CmdTargetCard=0,
  LC_Client_CmdTargetReader
} LC_CLIENT_CMDTARGET;



#ifdef __cplusplus
}
#endif


#include <libchipcard/base/card.h>


#ifdef __cplusplus
extern "C" {
#endif


/** @name Main API
 *
 * To work with this API you'll need to create a client object first.
 * This is normally done by @ref LC_Client_new.
 */
/*@{*/

/**
 * This function creates a libchipcard client.
 * @param programName name of the program which wants to create the client
 * @param programVersion version string of that program
 */
CHIPCARD_API LC_CLIENT *LC_Client_new(const char *programName, const char *programVersion);

/**
 * Release all ressources associated with Libchipcard3. This must be called
 * at the end of the application to avoid memory leaks.
 */
CHIPCARD_API void LC_Client_free(LC_CLIENT *cl);

/**
 * Init Libchipcard. This functions reads the configuration file and
 * the card command description files. It does not allocate the readers
 * (see @ref LC_Client_Start), so it is perfectly save to call this function
 * upon startup of the application.
 */
CHIPCARD_API int LC_Client_Init(LC_CLIENT *cl);

/**
 * Deinit Libchipcard. Unloads all data files.
 *
 */
CHIPCARD_API int LC_Client_Fini(LC_CLIENT *cl);



CHIPCARD_API int LC_Client_Start(LC_CLIENT *cl);

CHIPCARD_API int LC_Client_Stop(LC_CLIENT *cl);


CHIPCARD_API int LC_Client_GetNextCard(LC_CLIENT *cl, LC_CARD **pCard, int timeout);

CHIPCARD_API int LC_Client_ReleaseCard(LC_CLIENT *cl, LC_CARD *card);


/*@}*/


/** @name Informational Functions
 *
 */
/*{@*/
CHIPCARD_API const char *LC_Client_GetProgramName(const LC_CLIENT *cl);

CHIPCARD_API const char *LC_Client_GetProgramVersion(const LC_CLIENT *cl);

/*@}*/


#ifdef __cplusplus
}
#endif


/*@}*/

#endif /* CHIPCARD_CLIENT_CLIENT_H */



