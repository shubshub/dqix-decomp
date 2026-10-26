#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"

struct Struct_ov031_0224e3b8_2 {
	char pad[0x20];
	char unknown_20_[0x30];
	int unknown_50_;
	int field54;
	unsigned short unknown_58_;
	unsigned char unknown_5a_;
	char pad2[0x5c - 0x5b];
};

extern Struct_ov031_0224e3b8_2 data_ov031_0224e3b8[4];

// USA: func_ov031_02207aa4
extern "C" ARM void func_ov031_02207aa4(void* obj, int a, int b) {
	int i;
	int var1;
	Struct_ov031_0224e3b8_2* entry;
	var1 = DisableIRQInterrupts();
	*(unsigned char*)((char*)obj + 0x30) = 0;
	entry = data_ov031_0224e3b8;
	i = 0;
	do {
		if (entry->unknown_5a_ != 0 && entry->field54 == a && entry->unknown_58_ == b) {
			VectorizedInvertedMemcpy(entry, (char*)obj + 0x74, 0x20);
			VectorizedInvertedMemcpy(entry->unknown_20_, obj, 0x30);
			entry->unknown_50_ = (int)(GetCurrentTimestamp() >> 16);
			*(unsigned char*)((char*)obj + 0x30) = 1;
			break;
		}
		i++;
		entry++;
	} while (i < 4);
	SetIRQInterruptState(var1);
}
