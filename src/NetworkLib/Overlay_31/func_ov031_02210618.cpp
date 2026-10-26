#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

bool IsContextInactive(ProcessorContext* context);
extern void* data_ov031_0224e588;

// USA: func_ov031_02210618
extern "C" ARM void func_ov031_02210618(void) {
	volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
	unsigned short old = *ime;
	*ime = 0;
	AddContextSwitchLock();
	if (!IsContextInactive((ProcessorContext*)((char*)data_ov031_0224e588 + 0xa10))) {
		MarkContextReadyAndSwitch((ProcessorContext*)((char*)data_ov031_0224e588 + 0xa10));
	}
	RemoveContextSwitchLock();
	(void)*ime;
	*ime = old;
}
