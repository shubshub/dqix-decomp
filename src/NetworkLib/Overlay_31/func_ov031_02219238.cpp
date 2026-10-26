#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern void* data_ov031_0224e60c;
extern "C" void func_ov031_022192c0(void);
bool IsContextInactive(ProcessorContext* context);

// USA: func_ov031_02219238
extern "C" ARM void func_ov031_02219238(void) {
	if (*(int*)((char*)data_ov031_0224e60c + 0x1188) != 0) {
		if (IsContextInactive((ProcessorContext*)((char*)data_ov031_0224e60c + 0x111c)) == 0) {
			return;
		}
	}

	void* base = data_ov031_0224e60c;
	ProcessorContext* ctx = (ProcessorContext*)((char*)base + 0x111c);
	PopulateContext(ctx, (unsigned int)func_ov031_022192c0, (unsigned int)base, (unsigned int)base + 0x1000, 0x1000, 0x10);

	MarkContextReadyAndSwitch((ProcessorContext*)((char*)data_ov031_0224e60c + 0x111c));
}
