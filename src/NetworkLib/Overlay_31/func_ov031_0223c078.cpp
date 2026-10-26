#include <globaldefs.h>

extern "C" void func_ov031_0223c150();
extern "C" void ColorEffect_ConfigureBrightnessAdjust(unsigned short* dst, int flag, int value);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);

extern unsigned char data_ov031_022493a0[];

struct Struct_ov031_0223c078 {
	unsigned int result;
	unsigned short unknown_4_;
	unsigned short extra;
	unsigned char idx;
	unsigned char unknown_9_;
	unsigned char pad[2];
};
extern Struct_ov031_0223c078* data_ov031_02290d34;

// USA: func_ov031_0223c078
extern "C" ARM int func_ov031_0223c078(int idx, int arg1, int flag, int extra) {
	signed char buf[4];
	buf[0] = data_ov031_022493a0[0x8];
	buf[1] = data_ov031_022493a0[0x9];
	buf[2] = data_ov031_022493a0[0xa];
	buf[3] = data_ov031_022493a0[0xb];

	Struct_ov031_0223c078* entry = (arg1 == 1) ? data_ov031_02290d34 : (Struct_ov031_0223c078*)((char*)data_ov031_02290d34 + 0xc);
	if (entry->unknown_9_ != 0) {
		return 0;
	}

	if (arg1 == 1) {
		ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4001050, flag, buf[idx]);
	} else {
		ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4000050, flag, buf[idx]);
	}

	entry->result = (unsigned int)func_ov031_0223e218((void*)1, (void*)func_ov031_0223c150, entry, 0xc8);
	entry->unknown_4_ = 0;
	entry->idx = (unsigned char)idx;
	entry->extra = (unsigned short)extra;
	entry->unknown_9_ = 1;
	return 1;
}
