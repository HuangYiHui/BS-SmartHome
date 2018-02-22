#ifndef _BS_IRREMOTE_APP_H_
#define _BS_IRREMOTE_APP_H_

#include "cfg.h"
#include "WithCommandApp.h"
#include "pt.h"
#include "IRRemoteDevice.h"

class IRRemoteApp : public WithCommandApp
{
public:
	IRRemoteApp(IRRemoteDevice& irRemote);
	void init();
private:
	void exeCmd();
	int exeTask();
	IRRemoteDevice& irRemote;
	struct pt pt;
};
#endif