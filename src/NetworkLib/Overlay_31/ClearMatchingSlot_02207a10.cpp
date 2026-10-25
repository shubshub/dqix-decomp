#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

struct Entry02207a10 {
	char pad[0x20];
	char copyData[0x30];
	char pad2[0x54 - 0x50];
	int field54;
	unsigned short field58;
	unsigned char field5a;
	char pad3[0x5c - 0x5b];
};

extern Entry02207a10 data_ov031_0224e3b8[4];

extern "C" int memcmp(void* entry, void* arg1, int arg2);

// USA: func_ov031_02207a10  (semantic: ClearMatchingSlot_02207a10)
extern "C" ARM void func_ov031_02207a10(void* obj) {
	int i;
	int oldIRQ;
	Entry02207a10* entry;
	oldIRQ = DisableIRQInterrupts();
	*(unsigned char*)((char*)obj + 0x30) = 0;
	entry = data_ov031_0224e3b8;
	i = 0;
	do {
		if (entry->field5a != 0 && entry->field54 == 0 && entry->field58 == 0) {
			if (memcmp(entry, (char*)obj + 0x74, 0x20) == 0) {
				VectorizedInvertedMemcpy(entry->copyData, obj, 0x30);
				*(unsigned char*)((char*)obj + 0x30) = 1;
				break;
			}
		}
		i++;
		entry++;
	} while (i < 4);
	SetIRQInterruptState(oldIRQ);
}
