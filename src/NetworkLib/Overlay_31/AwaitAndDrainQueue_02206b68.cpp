#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Interrupts.h"

extern "C" int func_020c7ea0(void* obj, unsigned int* out, int arg2);
extern "C" void func_020c7e0c(void* data, int a, int b);
extern "C" void func_ov031_02205174(int v);

struct Struct_ov031_02206b68 { char pad[8]; void* field8; };

// USA: func_ov031_02206b68
extern "C" ARM void func_ov031_02206b68(char* obj) {
	if (obj == 0) {
		return;
	}
	AwaitContextCompletion((ProcessorContext*)(obj + 0x20));
	int var0 = DisableIRQInterrupts();
	AddContextSwitchLock();

	unsigned int cursor;
	if (func_020c7ea0(obj, &cursor, 0)) {
		do {
			if (cursor != 0) {
				if (((struct Struct_ov031_02206b68*)cursor)->field8 != 0) {
					func_020c7e0c(((struct Struct_ov031_02206b68*)cursor)->field8, -11, 0);
				}
				func_ov031_02205174((int)cursor);
			}
		} while (func_020c7ea0(obj, &cursor, 0));
	}

	RemoveContextSwitchLock();
	SwitchContextUninterrupted();
	SetIRQInterruptState(var0);
}
