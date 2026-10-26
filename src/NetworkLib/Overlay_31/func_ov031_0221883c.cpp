#include <globaldefs.h>
#include "NitroSDK/Memory.h"

typedef void* (*Type_ov031_0221883c)(void*, int);
typedef void (*Type_ov031_0221883c_2)(void*, void*, int);

struct Struct_ov031_0221883c {
	unsigned char pad0[0x10];
	Type_ov031_0221883c unknown_10_;
	Type_ov031_0221883c_2 notify;
};

struct Struct_ov031_02218528 {
	void* field0;
	int field4;
	int field8;
	int fieldc;
};

extern int data_ov031_02249f14;
extern int data_ov031_02249f00;

// USA: func_ov031_0221883c
extern "C" ARM int func_ov031_0221883c(void* obj, Struct_ov031_02218528* b, int len) {
	Struct_ov031_0221883c* var0 = (Struct_ov031_0221883c*)((char*)obj + 0x1000);
	Type_ov031_0221883c var1 = var0->unknown_10_;
	Type_ov031_0221883c_2 notify = var0->notify;
	if (len <= 0) return 0;

	void* r4 = var1(&data_ov031_02249f14, b->fieldc + len);
	if (r4 == NULL) return 0;

	VectorizedInvertedMemcpy(b->field0, r4, (unsigned int)b->fieldc);
	notify(&data_ov031_02249f00, b->field0, 0);
	if (r4 == NULL) return 0;

	b->field4 = b->field4 + ((int)r4 - (int)b->field0);
	b->fieldc = b->fieldc + len;
	b->field0 = r4;
	b->field8 = (int)r4 + b->fieldc;
	return 1;
}
