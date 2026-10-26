#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

bool IsContextInactive(ProcessorContext *context);
extern "C" void func_020c7e0c(void *a, int b, int c);

struct Struct_ov031_02291f24_2 {
	int unk0;
	int field4;
};

extern ProcessorContext data_ov031_02291f80;
extern struct Struct_ov031_02291f24_2 data_ov031_02291f24;
extern int data_ov031_02291f60;

// USA: func_ov031_02245938
extern "C" ARM void func_ov031_02245938(void) {
	if (data_ov031_02291f80.uniqueID == 0) {
		return;
	}
	if (IsContextInactive(&data_ov031_02291f80) == 0) {
		if (data_ov031_02291f24.field4 == 0) {
			data_ov031_02291f24.field4 = 1;
			func_020c7e0c(&data_ov031_02291f60, 0, 0);
		}
	}
}
