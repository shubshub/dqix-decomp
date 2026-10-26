#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

// USA: func_ov031_02207d3c
extern "C" ARM void func_ov031_02207d3c(unsigned int priority) {
	if (priority < 0x20) {
		ChangeContextPriority(data_02111304.activeContext, priority);
	}
}
