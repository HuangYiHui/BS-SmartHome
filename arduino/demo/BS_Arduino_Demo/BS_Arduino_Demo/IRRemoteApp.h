
#include "SystemCfg.h"

//��ΪIRremote����Tone���ͻ������ѡ���Ա���
#ifdef CUR_SYSTEM_IN

#ifndef _BS_IRREMOTE_APP_H_
#define _BS_IRREMOTE_APP_H_

#include "SampleApp.h"
#include "pt.h"
#include "IRRemoteDevice.h"

class IRRemoteApp : public SampleApp
{
public:
	IRRemoteApp(unsigned int appID, IRRemoteDevice& irRemote);
	void init();
	void run();
private:
	int runTask();
	IRRemoteDevice& irRemote;
	struct pt pt;
};
#endif

#endif