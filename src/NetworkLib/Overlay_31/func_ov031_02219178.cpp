#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern char* data_ov031_0224e60c;
extern "C" void func_ov031_02217e70(char *self);
extern "C" void func_ov031_022169a0(void);

// USA: func_ov031_02219178
extern "C" ARM void func_ov031_02219178(void) {
	char *base = data_ov031_0224e60c;
	if (base == NULL) return;
	char *field14 = *(char**)((char*)&data_ov031_0224e60c + 0x14);
	if (field14 != NULL) {
		func_ov031_02217e70(field14);
	}
	func_ov031_022169a0();
	base = data_ov031_0224e60c;
	if (*(int*)(base + 0x1000 + 0x188) != 0) {
		AwaitContextCompletion((ProcessorContext*)(base + 0x1000 + 0x11c));
	}
	base = data_ov031_0224e60c;
	*(int*)(base + 0x1000 + 4) = -7;
}
