#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" void func_ov031_02217e70(char* self);
bool IsContextInactive(ProcessorContext* context);

extern char* data_ov031_0224e69c;

// USA: func_ov031_0221a854
extern "C" ARM void func_ov031_0221a854(void) {
	char* p = data_ov031_0224e69c;
	if (p == NULL || *(int*)(p + 0x1bac) == 0) return;
	if (IsContextInactive((ProcessorContext*)(p + 0x1b40)) != 0) return;
	func_ov031_02217e70(data_ov031_0224e69c + 8);
}
