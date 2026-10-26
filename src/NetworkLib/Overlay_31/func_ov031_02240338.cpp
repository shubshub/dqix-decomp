#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224e204 {
	int a; int b; int c; int d;
	int e; int f; int g; int h;
};

extern "C" int func_020c75a4(void);
extern "C" void func_020c7de4(Struct_ov031_0224e204* s, int e, int f);
extern Struct_ov031_0224e204 data_ov031_022918bc;
extern int data_ov031_022918a0;
extern ProcessorContext data_ov031_022918dc;
extern "C" void func_ov031_0224185c(void);

// USA: func_ov031_02240338
extern "C" ARM int func_ov031_02240338(int a, int ctx) {
	if (func_020c75a4()) {
		func_020c7de4(&data_ov031_022918bc, (int)&data_ov031_022918a0, 1);
		PopulateContext(&data_ov031_022918dc, (unsigned int)func_ov031_0224185c, 0, ctx + 0x2000, 0x2000, a);
		MarkContextReadyAndSwitch(&data_ov031_022918dc);
		return 1;
	}
	return 0;
}
