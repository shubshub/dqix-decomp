#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern void* data_ov031_0224e588;

extern "C" void func_ov031_0221038c(int state);
extern "C" void func_ov031_02210618(void);
bool IsContextInactive(ProcessorContext* context);
void UnblockContexts(struct BlockedContextList* list);

// USA: func_ov031_022101e0
extern "C" ARM int func_ov031_022101e0(void) {
	if (data_ov031_0224e588 == NULL) {
		return 1;
	}
	func_ov031_0221038c(2);
	if (!IsContextInactive((ProcessorContext*)((char*)data_ov031_0224e588 + 0xa10))) {
		func_ov031_02210618();
		return 0;
	}
	UnblockContexts((struct BlockedContextList*)((char*)data_ov031_0224e588 + 0xa04));
	data_ov031_0224e588 = NULL;
	return 1;
}
