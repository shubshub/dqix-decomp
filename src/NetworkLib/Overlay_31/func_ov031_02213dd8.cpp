#include <globaldefs.h>
#include "NitroSDK/Timing.h"

extern "C" int func_ov031_0220d540(void);
struct Struct_ov031_02213dd8;
extern "C" unsigned int func_ov031_022140b0(Struct_ov031_02213dd8*);
struct Struct_ov031_02213dd8_2;
extern "C" unsigned int func_ov031_022140cc(Struct_ov031_02213dd8_2*);
extern "C" void func_ov031_0220d010(void*, void*, unsigned int);

// USA: func_ov031_02213dd8
extern "C" ARM int func_ov031_02213dd8(char* e) {
	int state = func_ov031_0220d540();
	char* slot = e + 0x470 + (*(unsigned char*)(e + 0xd13)) * 0xc0;
	if (state == 3) {
		unsigned int var2 = func_ov031_022140b0((Struct_ov031_02213dd8*)e);
		int var3 = *(unsigned char*)(e + 0xd15) + 1;
		*(unsigned char*)(e + 0xd15) = var3;
		if (((unsigned)var3 & 0xff) > 3) {
			*(unsigned char*)(e + 0xd15) = 0;
			*(char*)(e + (*(unsigned char*)(e + 0xd13)) * 4 + 0x444) = 1;
			return 9;
		}
		if (((unsigned)var3 & 0xff) != 1) {
			unsigned char sub = *(unsigned char*)(e + 0xd14);
			if (sub == 1) {
				*(unsigned char*)(e + 0xd0b) &= ~0xc;
			} else if (sub == 2) {
				*(unsigned char*)(e + 0xd15) = 0;
				*(char*)(e + (*(unsigned char*)(e + 0xd13)) * 4 + 0x444) = 3;
				return 9;
			} else if (sub == 3) {
				*(unsigned char*)(e + 0xd15) = 0;
				*(char*)(e + (*(unsigned char*)(e + 0xd13)) * 4 + 0x444) = 4;
				return 9;
			} else if (((unsigned)var3 & 0xff) == 3) {
				*(unsigned char*)(e + 0xd0b) &= ~0xc;
			}
		}
		unsigned int var5 = func_ov031_022140cc((Struct_ov031_02213dd8_2*)e);
		func_ov031_0220d010(slot, e + 0xcb8, var2 | var5);
	} else if (state == 9) {
		*(unsigned char*)(e + 0xd15) = 0;
		*(unsigned long long*)(e + 0xcb0) = GetCurrentTimestamp();
		return 0xa;
	}
	return 8;
}
