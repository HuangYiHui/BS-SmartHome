#ifndef _BS_SYSTEM_CFG_H_
#define _BS_SYSTEM_CFG_H_

//#define CUR_SYSTEM_IN
#define CUR_SYSTEM_OUT
#define SERAIL_BAUD_RATE	19200	//´®¿Ú²¨ÌØÂÊ

#include "ZBC.h"

#ifdef CUR_SYSTEM_IN
#include "SystemInCfg.h"
#else
#include "SystemOutCfg.h"
#endif


#endif