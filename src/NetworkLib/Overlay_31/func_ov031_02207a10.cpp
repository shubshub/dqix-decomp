#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

struct Struct_ov031_0224e3b8 {
	char pad[0x20];
	char unknown_20_[0x30];
	char pad2[0x54 - 0x50];
	int field54;
	unsigned short unknown_58_;
	unsigned char unknown_5a_;
	char pad3[0x5c - 0x5b];
};

extern Struct_ov031_0224e3b8 data_ov031_0224e3b8[4];

extern "C" int memcmp(void* entry, void* arg1, int arg2);

// USA: func_ov031_02207a10
extern "C" ARM void func_ov031_02207a10(void* obj) {
	int i;
	int var1;
	Struct_ov031_0224e3b8* entry;
	var1 = DisableIRQInterrupts();
	*(unsigned char*)((char*)obj + 0x30) = 0;
	entry = data_ov031_0224e3b8;
	i = 0;
	do {
		if (entry->unknown_5a_ != 0 && entry->field54 == 0 && entry->unknown_58_ == 0) {
			if (memcmp(entry, (char*)obj + 0x74, 0x20) == 0) {
				VectorizedInvertedMemcpy(entry->unknown_20_, obj, 0x30);
				*(unsigned char*)((char*)obj + 0x30) = 1;
				break;
			}
		}
		i++;
		entry++;
	} while (i < 4);
	SetIRQInterruptState(var1);
}
