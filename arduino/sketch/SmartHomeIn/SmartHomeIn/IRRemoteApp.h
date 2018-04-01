#ifndef _BS_IRREMOTE_APP_H_
#define _BS_IRREMOTE_APP_H_

#include "SampleApp.h"
#include "IRRemoteDevice.h"

class IRRemoteApp : public SampleApp
{
public:
	IRRemoteApp(IRRemoteDevice& irRemote);
	void init();
	void run();
private:
	IRRemoteDevice& irRemote;
};

#endif