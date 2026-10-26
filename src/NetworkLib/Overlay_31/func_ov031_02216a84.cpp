#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224e5e8_5 {
	unsigned char pad[8];
	char *base;
};

extern Struct_ov031_0224e5e8_5 data_ov031_0224e5e8;

// USA: func_ov031_02216a84
extern "C" ARM void func_ov031_02216a84(void) {
	char *base = data_ov031_0224e5e8.base;
	if (*(int*)(base + 0x1384) != 0) {
		AwaitContextCompletion((ProcessorContext*)(base + 0x1318));
	}
}
