/***************************************************************************
 $RCSfile$
                             -------------------
    cvs         : $Id$
    begin       : Mon Mar 01 2004
    copyright   : (C) 2004 by Martin Preuss
    email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/


#ifndef CHIPCARD_SERVICE_SERVICE_H
#define CHIPCARD_SERVICE_SERVICE_H


typedef struct LC_SERVICE LC_SERVICE;

#include <gwenhywfar/ipc.h>
#include <gwenhywfar/inherit.h>
#include <gwenhywfar/types.h>

#include <chipcard2-service/client.h>
#include <chipcard2-client/client/client.h>


typedef enum {
  LC_ServiceCheckArgsResultOk=0,
  LC_ServiceCheckArgsResultError,
  LC_ServiceCheckArgsResultVersion,
  LC_ServiceCheckArgsResultHelp
} LC_SERVICE_CHECKARGS_RESULT;


typedef GWEN_TYPE_UINT32 (*LC_SERVICE_OPEN_FN)(LC_CLIENT *cl,
                                               LC_SERVICECLIENT *scl,
                                               GWEN_DB_NODE *dbData);

typedef GWEN_TYPE_UINT32 (*LC_SERVICE_CLOSE_FN)(LC_CLIENT *cl,
                                                LC_SERVICECLIENT *scl,
                                                GWEN_DB_NODE *dbData);

typedef GWEN_TYPE_UINT32 (*LC_SERVICE_COMMAND_FN)(LC_CLIENT *cl,
                                                  LC_SERVICECLIENT *scl,
                                                  GWEN_DB_NODE *dbRequest,
                                                  GWEN_DB_NODE *dbResponse);

typedef int (*LC_SERVICE_WORK_FN)(LC_CLIENT *cl);

typedef const char* (*LC_SERVICE_GETERRORTEXT_FN)(LC_CLIENT *cl,
                                                  GWEN_TYPE_UINT32 err);


void LC_Service_Usage(const char *prgName);

LC_CLIENT *LC_Service_new(int argc, char **argv);
void LC_Service_free(LC_SERVICE *d);

const char *LC_Service_GetServiceDataDir(const LC_CLIENT *d);
const char *LC_Service_GetLibraryFile(const LC_CLIENT *d);
const char *LC_Service_GetServiceId(const LC_CLIENT *d);

LC_SERVICECLIENT_LIST *LC_Service_GetClients(const LC_CLIENT *d);


int LC_Service_Connect(LC_CLIENT *cl, const char *code, const char *text);

int LC_Service_Work(LC_CLIENT *d);

GWEN_TYPE_UINT32 LC_Service_Open(LC_CLIENT *d,
                                 LC_SERVICECLIENT *scl,
                                 GWEN_DB_NODE *dbData);

GWEN_TYPE_UINT32 LC_Service_Close(LC_CLIENT *d,
                                  LC_SERVICECLIENT *scl,
                                  GWEN_DB_NODE *dbData);

GWEN_TYPE_UINT32 LC_Service_Command(LC_CLIENT *d,
                                    LC_SERVICECLIENT *scl,
                                    GWEN_DB_NODE *dbRequest,
                                    GWEN_DB_NODE *dbResponse);

const char *LC_Service_GetErrorText(LC_CLIENT *d,
                                    GWEN_TYPE_UINT32 err);


void LC_Service_SetOpenFn(LC_CLIENT *d, LC_SERVICE_OPEN_FN fn);
void LC_Service_SetCloseFn(LC_CLIENT *d, LC_SERVICE_CLOSE_FN fn);
void LC_Service_SetCommandFn(LC_CLIENT *d, LC_SERVICE_COMMAND_FN fn);
void LC_Service_SetGetErrorTextFn(LC_CLIENT *d,
                                  LC_SERVICE_GETERRORTEXT_FN fn);
void LC_Service_SetWorkFn(LC_CLIENT *d, LC_SERVICE_WORK_FN fn);




LC_SERVICECLIENT *LC_Service_FindClientById(const LC_CLIENT *d,
                                            GWEN_TYPE_UINT32 id);

void LC_Service_AddClient(LC_CLIENT *d, LC_SERVICECLIENT *cl);
void LC_Service_DelClient(LC_CLIENT *d, LC_SERVICECLIENT *cl);

int LC_Service_Connect(LC_CLIENT *d,
                       const char *code,
                       const char *text);







#endif /* CHIPCARD_SERVICE_SERVICE_H */




