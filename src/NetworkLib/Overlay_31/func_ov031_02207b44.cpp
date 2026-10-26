#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"

struct Struct_ov031_0224e3b8_3 {
	char pad[0x20];
	char unknown_20_[0x30];
	int unknown_50_;
	int field54;
	unsigned short unknown_58_;
	unsigned char unknown_5a_;
	char pad2[0x5c - 0x5b];
};

extern Struct_ov031_0224e3b8_3 data_ov031_0224e3b8[4];

// USA: func_ov031_02207b44
extern "C" ARM void func_ov031_02207b44(void* obj, int a, int b) {
	int i;
	Struct_ov031_0224e3b8_3* best;
	unsigned int var2;
	int var3;
	unsigned int now;
	Struct_ov031_0224e3b8_3* entry;
	var3 = DisableIRQInterrupts();
	now = (unsigned int)(GetCurrentTimestamp() >> 16);
	best = data_ov031_0224e3b8;
	var2 = 0;
	i = 0;
	entry = best;
	do {
		if (entry->unknown_5a_ != 0 && a != 0 && a == entry->field54 && b != 0 && b == entry->unknown_58_) {
			best = entry;
			break;
		}
		if (var2 != 0xffffffffu) {
			if (entry->unknown_5a_ == 0) {
				var2 = 0xffffffffu;
				best = entry;
			} else {
				unsigned int age = now - (unsigned int)entry->unknown_50_;
				if (age > var2) {
					var2 = age;
					best = entry;
				}
			}
		}
		i++;
		entry++;
	} while (i < 4);
	VectorizedInvertedMemcpy((char*)obj + 0x74, best, 0x20);
	VectorizedInvertedMemcpy(obj, (char*)best + 0x20, 0x30);
	best->unknown_50_ = (int)now;
	best->unknown_5a_ = 1;
	best->field54 = a;
	best->unknown_58_ = b;
	SetIRQInterruptState(var3);
}
