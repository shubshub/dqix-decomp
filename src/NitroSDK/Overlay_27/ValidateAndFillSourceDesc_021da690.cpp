#include <globaldefs.h>


extern "C" void HaltSystem(void);

struct Base_021da690 {
	unsigned char pad0[0x28];
	unsigned int addrA;
	unsigned int sizeA;
	unsigned char pad1[0x38 - 0x30];
	unsigned int addrB;
	unsigned int sizeB;
};

struct OutDesc_021da690 {
	unsigned int field0;
	unsigned int addr;
	unsigned int size;
	unsigned int flags;
};

// USA: func_ov027_021da690  (semantic: ValidateAndFillSourceDesc_021da690)
#pragma optimize_for_size off
extern "C" ARM void func_ov027_021da690(Base_021da690 *obj, int *modePtr, OutDesc_021da690 *out, unsigned int *extra) {
	int mode = *modePtr;
	switch (mode) {
	case 0: {
		unsigned int addr = obj->addrA;
		if (addr >= 0x2000000 && addr < 0x22c0000 && addr + obj->sizeA <= 0x22c0000) {
			out->size = obj->sizeA;
			unsigned int addr2 = obj->addrA;
			out->addr = addr2;
			out->field0 = addr2;
			out->flags = out->flags & ~1;
			return;
		}
		HaltSystem();
		return;
	}
	case 1: {
		int outOfRange = 0;
		int useExtra = 0;
		unsigned int size = obj->sizeB;
		unsigned int end = obj->addrB + size;
		unsigned int addr = obj->addrB;
		if (addr >= 0x2000000 && addr < 0x23fe800) {
			if (end <= 0x2300000) {
			} else if (end < 0x23fe800 && size <= 0x40000) {
				useExtra = 1;
			} else {
				outOfRange = 1;
			}
		} else {
			if (addr < 0x37f8000) goto rangeFail2;
			if (addr >= 0x37f8000 + 0x17000) goto rangeFail2;
			if (end <= 0x37f8000 + 0x17000) {
				useExtra = 1;
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
		out->addr = obj->addrB;
		if (!useExtra) {
			out->field0 = out->addr;
		} else {
			out->field0 = *extra;
			*extra = *extra + out->size;
		}
		out->flags = (out->flags & ~1) | 1;
		return;
	}
	case 2: {
		unsigned int fixedAddr = 0x27ffe00;
		out->size = 0x160;
		out->addr = fixedAddr;
		out->field0 = fixedAddr;
		out->flags = out->flags & ~1;
		return;
	}
	default:
		return;
	}
}
