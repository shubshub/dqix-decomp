#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0224e3b8_4 {
	char pad[0x5a];
	unsigned char unknown_5a_;
	char pad2[0x5c - 0x5b];
};

extern Struct_ov031_0224e3b8_4 data_ov031_0224e3b8[4];

extern "C" int memcmp(void* entry, void* arg1, int arg2);

// USA: func_ov031_02207c30
extern "C" ARM void func_ov031_02207c30(void* obj) {
	int i;
	int var1;
	Struct_ov031_0224e3b8_4* entry;
	var1 = DisableIRQInterrupts();
	entry = data_ov031_0224e3b8;
	i = 0;
	do {
		if (entry->unknown_5a_ != 0) {
			if (memcmp(entry, (char*)obj + 0x74, 0x20) == 0) {
				entry->unknown_5a_ = 0;
				break;
			}
		}
		i++;
		entry++;
	} while (i < 4);
	SetIRQInterruptState(var1);
}
