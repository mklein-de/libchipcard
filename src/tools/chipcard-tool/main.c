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


#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#undef BUILDING_LIBCHIPCARD2_DLL

#include "global.h"
#include <gwenhywfar/args.h>
#include <gwenhywfar/nettransportssl.h>

#define PROGRAM_VERSION "1.9"


const GWEN_ARGS prg_args[]={
{
  GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
  GWEN_ArgsTypeChar,            /* type */
  "configfile",                 /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  "C",                          /* short option */
  "configfile",                 /* long option */
  "Configuration file to load", /* short description */
  "Configuration file to load." /* long description */
},
{
  GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
  GWEN_ArgsTypeChar,            /* type */
  "file",                       /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  "f",                          /* short option */
  "file",                       /* long option */
  "File name",                  /* short description */
  "File name. \n"
  "This filename is used when reading or writing data such as public keys,\n"
  "bank information etc."
},
{
  GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
  GWEN_ArgsTypeChar,            /* type */
  "logtype",                    /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  0,                            /* short option */
  "logtype",                    /* long option */
  "Set the logtype",            /* short description */
  "Set the logtype (console, file)."
},
{
  GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
  GWEN_ArgsTypeChar,            /* type */
  "loglevel",                   /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  0,                            /* short option */
  "loglevel",                   /* long option */
  "Set the log level",          /* short description */
  "Set the log level (info, notice, warning, error)."
},
{
  GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
  GWEN_ArgsTypeChar,            /* type */
  "logfile",                    /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  0,                            /* short option */
  "logfile",                   /* long option */
  "Set the log file",          /* short description */
  "Set the log file (if log type is \"file\")."
},
{
  0,                            /* flags */
  GWEN_ArgsTypeInt,             /* type */
  "verbosity",                  /* name */
  0,                            /* minnum */
  10,                           /* maxnum */
  "v",                          /* short option */
  "verbous",                    /* long option */
  "Increase the verbosity",     /* short description */
  "Every occurrence of this option increases the verbosity."
},
{
  0,                            /* flags */
  GWEN_ArgsTypeInt,             /* type */
  "showAll",                    /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  "a",                          /* short option */
  "showall",                    /* long option */
  "Show event log for drivers and readers",     /* short description */
  "Show event log for drivers and readers."
},
{
  GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
  GWEN_ArgsTypeInt,             /* type */
  "timeout",                    /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  "t",                          /* short option */
  "timeout",                    /* long option */
  "Total timeout for check command",     /* short description */
  "Set the total timeout for check command."
},
{
  0,                            /* flags */
  GWEN_ArgsTypeInt,             /* type */
  "readers",                    /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  0,                            /* short option */
  "readers",                    /* long option */
  "Show readers",               /* short description */
  "Show readers."
},
{
  0,                            /* flags */
  GWEN_ArgsTypeInt,             /* type */
  "drivers",                    /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  0,                            /* short option */
  "drivers",                    /* long option */
  "Show drivers",               /* short description */
  "Show drivers."
},
{
  0,                            /* flags */
  GWEN_ArgsTypeInt,             /* type */
  "services",                   /* name */
  0,                            /* minnum */
  1,                            /* maxnum */
  0,                            /* short option */
  "services",                   /* long option */
  "Show services",              /* short description */
  "Show services."
},
{
  GWEN_ARGS_FLAGS_HELP | GWEN_ARGS_FLAGS_LAST, /* flags */
  GWEN_ArgsTypeInt,             /* type */
  "help",                       /* name */
  0,                            /* minnum */
  0,                            /* maxnum */
  "h",                          /* short option */
  "help",                       /* long option */
  "Show help",                  /* short description */
  "Shows this help."            /* long description */
  }
};



void showError(LC_CARD *card, LC_CLIENT_RESULT res, const char *x) {
  const char *s;

  switch(res) {
  case LC_Client_ResultOk:
    s="Ok.";
    break;
  case LC_Client_ResultWait:
    s="Timeout.";
    break;
  case LC_Client_ResultIpcError:
    s="IPC error.";
    break;
  case LC_Client_ResultCmdError:
    s="Command error.";
    break;
  case LC_Client_ResultDataError:
    s="Data error.";
    break;
  case LC_Client_ResultAborted:
    s="Aborted.";
    break;
  case LC_Client_ResultInvalid:
    s="Invalid argument to command.";
    break;
  case LC_Client_ResultInternal:
    s="Internal error.";
    break;
  case LC_Client_ResultGeneric:
    s="Generic error.";
    break;
  default:
    s="Unknown error.";
    break;
  }

  fprintf(stderr, "Error in \"%s\": %s\n", x, s);
  if (res==LC_Client_ResultCmdError) {
    fprintf(stderr, "  Last card command result:\n");
    fprintf(stderr, "   SW1=%02x, SW2=%02x\n",
            LC_Card_GetLastSW1(card),
            LC_Card_GetLastSW2(card));
    s=LC_Card_GetLastResult(card);
    if (s)
      fprintf(stderr, "   Result: %s\n", s);
    s=LC_Card_GetLastText(card);
    if (s)
      fprintf(stderr, "   Text  : %s\n", s);
  }
}



GWEN_NETTRANSPORTSSL_ASKADDCERT_RESULT _askAddCert(GWEN_NETTRANSPORT *tr,
                                                   GWEN_DB_NODE *cert){
  return GWEN_NetTransportSSL_AskAddCertResultTmp;
}



int main(int argc, char **argv) {
  int rv;
  GWEN_DB_NODE *db;
  const char *s;
  LC_CLIENT *cl;
  GWEN_LOGGER_LOGTYPE logType;
  GWEN_LOGGER_LEVEL logLevel;

  GWEN_NetTransportSSL_SetAskAddCertFn(_askAddCert);

  db=GWEN_DB_Group_new("arguments");
  rv=GWEN_Args_Check(argc, argv, 1,
                     GWEN_ARGS_MODE_ALLOW_FREEPARAM,
                     prg_args,
                     db);
  if (rv==-2) {
    GWEN_BUFFER *ubuf;

    ubuf=GWEN_Buffer_new(0, 256, 0, 1);
    if (GWEN_Args_Usage(prg_args, ubuf, GWEN_ArgsOutTypeTXT)) {
      fprintf(stderr, "Could not generate usage string.\n");
      GWEN_Buffer_free(ubuf);
      return RETURNVALUE_PARAM;
    }
    fprintf(stderr, "%s\n", GWEN_Buffer_GetStart(ubuf));
    GWEN_Buffer_free(ubuf);
    return 0;
  }
  if (rv<1) {
    fprintf(stderr, "ERROR: Error in argument list (%d)\n", rv);
    return RETURNVALUE_PARAM;
  }

  /* setup logging */
  s=GWEN_DB_GetCharValue(db, "loglevel", 0, "warning");
  logLevel=GWEN_Logger_Name2Level(s);
  if (logLevel==GWEN_LoggerLevelUnknown) {
    fprintf(stderr, "ERROR: Unknown log level (%s)\n", s);
    return RETURNVALUE_PARAM;
  }
  s=GWEN_DB_GetCharValue(db, "logtype", 0, "console");
  logType=GWEN_Logger_Name2Logtype(s);
  if (logType==GWEN_LoggerTypeUnknown) {
    fprintf(stderr, "ERROR: Unknown log type (%s)\n", s);
    return RETURNVALUE_PARAM;
  }
  rv=GWEN_Logger_Open(LC_LOGDOMAIN,
		      "chipcard-tool",
		      GWEN_DB_GetCharValue(db, "logfile", 0, "chipcard-tool.log"),
		      logType,
		      GWEN_LoggerFacilityUser);
  if (rv) {
    fprintf(stderr, "ERROR: Could not setup logging (%d).\n", rv);
    return RETURNVALUE_SETUP;
  }
  GWEN_Logger_SetLevel(LC_LOGDOMAIN, logLevel);

  /* get command */
  s=GWEN_DB_GetCharValue(db, "params", 0, 0);
  if (!s) {
    fprintf(stderr, "No command given.\n");
    GWEN_DB_Group_free(db);
    return RETURNVALUE_PARAM;
  }

  cl=LC_Client_new("chipcard-tool", PROGRAM_VERSION, 0);
  if (LC_Client_ReadConfigFile(cl,
                               GWEN_DB_GetCharValue(db, "configfile",
                                                    0, 0))) {
    fprintf(stderr, "Error reading configuration.\n");
    LC_Client_free(cl);
    GWEN_DB_Group_free(db);
    return RETURNVALUE_SETUP;
  }

  /* handle command */
  if (strcasecmp(s, "list")==0) {
    rv=listReaders(cl, db);
  }
  else if (strcasecmp(s, "check")==0) {
    rv=checkReaders(cl, db);
  }
  else if (strcasecmp(s, "atr")==0) {
    rv=getAtr(cl, db);
  }
  else {
    fprintf(stderr, "Unknown command \"%s\"", s);
    rv=RETURNVALUE_PARAM;
  }

  LC_Client_free(cl);
  GWEN_DB_Group_free(db);
  return 0;
}








