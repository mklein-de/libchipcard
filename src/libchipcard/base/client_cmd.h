/***************************************************************************
    begin       : Mon Mar 01 2004
    copyright   : (C) 2021 by Martin Preuss
    email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/

#ifndef CHIPCARD_CLIENT_CLIENT_CMD_H
#define CHIPCARD_CLIENT_CLIENT_CMD_H


#include "libchipcard/base/client.h"
#include "libchipcard/base/card.h"


int LC_Client_AddCardTypesByAtr(LC_CLIENT *cl, LC_CARD *card);
int LC_Client_BuildApdu(LC_CLIENT *cl,
                        LC_CARD *card,
                        const char *command,
                        GWEN_DB_NODE *cmdData,
                        GWEN_BUFFER *buf);
int LC_Client_ExecCommand(LC_CLIENT *cl,
                          LC_CARD *card,
                          const char *commandName,
                          GWEN_DB_NODE *cmdData,
                          GWEN_DB_NODE *rspData);
GWEN_XMLNODE *LC_Client_FindCardCommand(LC_CLIENT *cl, LC_CARD *card, const char *commandName);







#endif

