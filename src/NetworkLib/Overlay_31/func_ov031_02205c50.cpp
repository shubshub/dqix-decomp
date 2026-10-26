#include <globaldefs.h>

struct Struct_ov031_02205c50_2 {
	unsigned char pad0[0x8];
	unsigned char field8;
	unsigned char pad1[1];
	unsigned short fieldA;
	unsigned char pad2[0xc];
	unsigned short field18;
	unsigned char pad3[2];
	int field1c;
	unsigned char pad4[0x20];
	int field40;
	int field44;
};

struct Struct_ov031_02205c50 {
	unsigned char pad0[0xc4];
	struct Struct_ov031_02205c50_2* a;
	unsigned char pad1[0x30];
	int b;
};

struct Struct_ov031_02205c50_3 { unsigned char pad[0x64]; struct Struct_ov031_02205c50* ctx; };

// USA: func_ov031_02205c50
extern "C" ARM int func_ov031_02205c50(struct Struct_ov031_02205c50_3* obj, int* arg1, unsigned short* outA, unsigned short* arg3, int* arg4) {
	struct Struct_ov031_02205c50* ctx = obj->ctx;
	struct Struct_ov031_02205c50_2* a = ctx->a;
	int b = ctx->b;
	int diff = a->field44 - b;
	if (diff < 0) {
		goto negative;
	}
	*outA = a->fieldA;
	*arg3 = a->field18;
	*arg4 = a->field1c;
	*arg1 = diff;
	if (diff != 0) {
		goto ret_sum;
	}
	if (a->field8 == 4) {
		goto ret_sum;
	}
	return 0;
negative:
	*arg1 = -1;
	return 0;
ret_sum:
	return a->field40 + b;
}
