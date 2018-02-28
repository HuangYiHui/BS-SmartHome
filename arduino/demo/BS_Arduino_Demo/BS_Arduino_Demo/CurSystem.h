
#ifndef _BS_CURRENT_SYSTEM_H_
#define _BS_CURRENT_SYSTEM_H_

/*
��������꣬����Ŀ->����->c/c++->Ԥ������->Ԥ�����������ж���
CUR_SYSTEM_IN	- ��ʾ��ǰϵͳΪ���ڵ�
CUR_SYSTEM_OUT	- ��ʾ��ǰϵͳΪ�����
*/
#include "cfg.h"
#include "SystemAPI.h"
#include "SystemIn.h"
#include "Test1App.h"


#ifdef CUR_SYSTEM_IN
#include "SystemIn.h"
SystemIn curSystem;
#else
#include "SystemOut.h"
SystemOut curSystem ;
#endif
SystemAPI API(&curSystem);


#endif
