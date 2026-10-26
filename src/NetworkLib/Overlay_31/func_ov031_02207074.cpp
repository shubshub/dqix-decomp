#include <globaldefs.h>

struct Struct_ov031_02207074_2 {
	char pad[4];
	unsigned short field4;
};

struct Struct_ov031_02207074 {
	char pad[0xf8];
	unsigned int field0xf8;
	char pad2[0x104 - 0xfc];
	Struct_ov031_02207074_2* unknown_104_;
};

struct Struct_ov031_02206fa4 {
	char pad[0x44];
	unsigned int field44;
	char pad2[0x64 - 0x48];
	Struct_ov031_02207074* unknown_64_;
	char pad3[0x73 - 0x68];
	signed char unknown_73_;
};

// USA: func_ov031_02207074
extern "C" ARM int func_ov031_02207074(Struct_ov031_02206fa4* obj) {
	Struct_ov031_02207074* ctx = obj->unknown_64_;
	int result = 0;
	if (ctx) {
		signed char var2 = obj->unknown_73_;
		if (var2 == 1) {
			Struct_ov031_02207074_2* p = ctx->unknown_104_;
			if (p) result = p->field4;
		} else if (var2 == 0 || var2 == 4) {
			result = obj->field44 - ctx->field0xf8;
		}
	}
	return result;
}
