#include <globaldefs.h>

struct Struct_ov031_0222b918_2 {
	unsigned short unknown_0_;
	unsigned short unknown_2_;
	unsigned short unknown_4_;
};
struct Struct_ov031_0222b918 {
	unsigned char pad[0x10];
	Struct_ov031_0222b918_2* objA[5];
	Struct_ov031_0222b918_2* objB[5];
	unsigned char pad2[0x42 - 0x38];
	unsigned short unknown_42_[3];
	unsigned short unknown_48_[4];
	unsigned char pad3[0x51 - 0x50];
	unsigned char unknown_51_;
};
struct Struct_ov031_02290c8c_4 {
	unsigned char pad[2];
	unsigned short field2;
	Struct_ov031_0222b918* field4;
};
extern Struct_ov031_02290c8c_4 data_ov031_02290c8c;
extern const unsigned char data_ov031_02248eac[3];
extern const unsigned char data_ov031_02248eb0[4];

extern "C" ARM Struct_ov031_0222b918_2* func_ov031_0223be44(int a, int b);
extern "C" int func_ov031_0223bdb0(int, int, void*);

// USA: func_ov031_0222b918
extern "C" ARM void func_ov031_0222b918(void) {
	int n;
	int i;
	n = data_ov031_02290c8c.field4->unknown_51_;
	if (n > 5) {
		n = 5;
	}
	for (i = 0; i < n; i++) {
		data_ov031_02290c8c.field4->objA[i] = func_ov031_0223be44(0, 0x2e);
		data_ov031_02290c8c.field4->objB[i] = func_ov031_0223be44(0, 0x18);
	}
	for (i = 0; i < sizeof(data_ov031_02248eac); i++) {
		func_ov031_0223bdb0(0, data_ov031_02248eac[i], data_ov031_02290c8c.field4->objA[0]);
		data_ov031_02290c8c.field4->unknown_42_[i] = data_ov031_02290c8c.field4->objA[0]->unknown_4_ & 0x3ff;
	}
	for (i = 0; i < sizeof(data_ov031_02248eb0); i++) {
		func_ov031_0223bdb0(0, data_ov031_02248eb0[i], data_ov031_02290c8c.field4->objB[0]);
		data_ov031_02290c8c.field4->unknown_48_[i] = data_ov031_02290c8c.field4->objB[0]->unknown_4_ & 0x3ff;
	}
	for (i = 0; i < n; i++) {
		data_ov031_02290c8c.field4->objA[i]->unknown_4_ = (data_ov031_02290c8c.field4->objA[i]->unknown_4_ & ~0xc00) | 0xc00;
		data_ov031_02290c8c.field4->objB[i]->unknown_4_ = (data_ov031_02290c8c.field4->objB[i]->unknown_4_ & ~0xc00) | 0xc00;
	}
}
