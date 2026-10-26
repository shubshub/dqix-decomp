#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02211ca0_2 {
	int field0;
	unsigned short field4;
	unsigned short pad6;
	unsigned short field8;
	unsigned short fielda;
};

struct Struct_ov031_0224e5b4_3 {
	char pad0[4];
	Struct_ov031_02211ca0_2* field4;
};

extern Struct_ov031_0224e5b4_3 data_ov031_0224e5b4;

extern "C" void func_ov031_02211b08(int a, int b);
extern "C" int func_ov031_02212d40(void* buf);
extern "C" void* func_ov031_02211b54(void*, void*);
extern "C" void func_ov031_02211b98(void*, void*);

struct Struct_ov031_02211ca0 {
	void* (*unknown_0_)(void*, void*);
	void (*unknown_4_)(void*, void*);
	unsigned char b8;
	unsigned char unknown_9_;
	unsigned char pad[2];
};

// USA: func_ov031_02211ca0
extern "C" ARM void func_ov031_02211ca0(void) {
	Struct_ov031_02211ca0_2* q = data_ov031_0224e5b4.field4;
	if (q != 0) {
		if (q->field4 == 1) {
			Struct_ov031_02211ca0 buf;
			VectorizedMemset(&buf, 0, 0xc);

			q = data_ov031_0224e5b4.field4;
			buf.b8 = (unsigned char)q->field8;
			buf.unknown_9_ = (unsigned char)q->fielda;
			buf.unknown_0_ = func_ov031_02211b54;
			buf.unknown_4_ = func_ov031_02211b98;
			q->field4 = 2;

			if (func_ov031_02212d40(&buf) == 0) {
				func_ov031_02211b08(9, 0xffff3be9);
			}
		}
	} else {
		func_ov031_02211b08(9, 0xffff3be9);
	}
}
