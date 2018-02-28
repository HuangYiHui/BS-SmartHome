
#ifndef _BS_CURRENT_SYSTEM_H_
#define _BS_CURRENT_SYSTEM_H_

/*
条件编译宏，在项目->属性->c/c++->预处理器->预处理器定义中定义
CUR_SYSTEM_IN	- 表示当前系统为室内的
CUR_SYSTEM_OUT	- 表示当前系统为室外的
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
