#include <globaldefs.h>


extern "C" void HaltSystem(void);

struct Struct_ov027_021da690 {
	unsigned char pad0[0x28];
	unsigned int unknown_28_;
	unsigned int sizeA;
	unsigned char pad1[0x38 - 0x30];
	unsigned int unknown_38_;
	unsigned int sizeB;
};

struct Struct_ov027_021da690_2 {
	unsigned int field0;
	unsigned int addr;
	unsigned int size;
	unsigned int flags;
};

// USA: func_ov027_021da690
#pragma optimize_for_size off
extern "C" ARM void func_ov027_021da690(Struct_ov027_021da690 *obj, int *arg1, Struct_ov027_021da690_2 *out, unsigned int *extra) {
	int mode = *arg1;
	switch (mode) {
	case 0: {
		unsigned int addr = obj->unknown_28_;
		if (addr >= 0x2000000 && addr < 0x22c0000 && addr + obj->sizeA <= 0x22c0000) {
			out->size = obj->sizeA;
			unsigned int var2 = obj->unknown_28_;
			out->addr = var2;
			out->field0 = var2;
			out->flags = out->flags & ~1;
			return;
		}
		HaltSystem();
		return;
	}
	case 1: {
		int outOfRange = 0;
		int var4 = 0;
		unsigned int size = obj->sizeB;
		unsigned int end = obj->unknown_38_ + size;
		unsigned int addr = obj->unknown_38_;
		if (addr >= 0x2000000 && addr < 0x23fe800) {
			if (end <= 0x2300000) {
			} else if (end < 0x23fe800 && size <= 0x40000) {
				var4 = 1;
			} else {
				outOfRange = 1;
			}
		} else {
			if (addr < 0x37f8000) goto rangeFail2;
			if (addr >= 0x37f8000 + 0x17000) goto rangeFail2;
			if (end <= 0x37f8000 + 0x17000) {
				var4 = 1;
			} else {
				outOfRange = 1;
			}
			goto afterRange2;
		rangeFail2:
			outOfRange = 1;
		afterRange2:;
		}
		if (outOfRange == 1) {
			HaltSystem();
		}
		out->size = obj->sizeB;
		out->addr = obj->unknown_38_;
		if (!var4) {
			out->field0 = out->addr;
		} else {
			out->field0 = *extra;
			*extra = *extra + out->size;
		}
		out->flags = (out->flags & ~1) | 1;
		return;
	}
	case 2: {
		unsigned int var8 = 0x27ffe00;
		out->size = 0x160;
		out->addr = var8;
		out->field0 = var8;
		out->flags = out->flags & ~1;
		return;
	}
	default:
		return;
	}
}
