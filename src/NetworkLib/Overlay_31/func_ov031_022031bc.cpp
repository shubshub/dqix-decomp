#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" unsigned short func_ov031_02203078(void);

struct Struct_ov031_0224c980_6 {
	char pad[0x50];
	unsigned int unknown_50_;
};

extern Struct_ov031_0224c980_6 data_ov031_0224c980;

struct Struct_ov031_022031bc {
	char pad0[0xa];
	unsigned short fieldA;
	char pad1[0x18 - 0xa - 2];
	unsigned short field18;
	unsigned short unknown_1a_;
	unsigned int field1c;
	unsigned int field20;
};

// USA: func_ov031_022031bc
extern "C" ARM void func_ov031_022031bc(int a, unsigned short b, unsigned int c) {
	Struct_ov031_022031bc* obj = (Struct_ov031_022031bc*)data_02111304.activeContext->unknown_A4;
	if (obj == NULL) {
		return;
	}
	unsigned int val = (c == 0x7f000001) ? data_ov031_0224c980.unknown_50_ : c;
	obj->unknown_1a_ = b;
	obj->field18 = obj->unknown_1a_;
	obj->field20 = val;
	obj->field1c = val;
	if (a != 0) {
		obj->fieldA = (unsigned short)a;
		return;
	}
	obj->fieldA = func_ov031_02203078();
}
