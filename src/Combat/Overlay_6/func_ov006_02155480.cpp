#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" void func_ov023_021dcd90(void* p, int x);
extern "C" void func_ov006_02155508(void* s);
extern int data_0210a010[];

struct Struct_ov006_02155480 {
	char pad[0xe2];
	unsigned short unknown_e2_;
};

struct Struct_ov006_02155480_2 {
	char pad0[LOW_REGION(0x880, 0xa00)];
	Struct_ov006_02155480 sub;
	char unknown_ae4_[0x1000 - (LOW_REGION(0x880, 0xa00) + sizeof(Struct_ov006_02155480))];
	char unknown_1000_[LOW_REGION(0xb9, 0x2bd)];
	unsigned char unknown_12bd_;
};

// USA: func_ov006_02155480
extern "C" ARM void func_ov006_02155480(Struct_ov006_02155480_2* o) {
	o->unknown_12bd_ = 1;
	*(unsigned int*)((char*)data_0210a010 + 0xa0) = 0xbfff0000;

	volatile unsigned short* reg = (volatile unsigned short*)0x4000008;
	reg[0] = (reg[0] & ~3) | 2;
	reg[1] = (reg[1] & ~3);
	reg[2] = (reg[2] & ~3) | 1;

	o->sub.unknown_e2_ &= ~0x40;

	func_ov023_021dcd90((char*)o + LOW_REGION(0x164, 0x2e4) + 0x800, 0);
	func_ov006_02155508(o);
}
