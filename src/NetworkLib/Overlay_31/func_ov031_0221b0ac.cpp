#include <globaldefs.h>

extern "C" int func_ov031_0221b780(int a0, int a1, int a2);
extern "C" int func_ov031_0221b7fc(int a, int b, int c, int d);
extern "C" int func_ov031_0221b848(void);
extern "C" unsigned short func_020d1cc8(const unsigned short* table, const unsigned char* data, unsigned int len);

struct Struct_ov031_0224e6a0_2 {
	unsigned char pad[8];
	int field8;
};
extern Struct_ov031_0224e6a0_2 data_ov031_0224e6a0;

struct Struct_ov031_0221b0ac {
	unsigned char data[0xfe];
	unsigned short unknown_fe_;
};

struct Struct_ov031_0221b0ac_2 {
	Struct_ov031_0221b0ac blocks[4];
	unsigned char work[0x100];
	unsigned short unknown_500_[0x100];
};

// USA: func_ov031_0221b0ac
extern "C" ARM int func_ov031_0221b0ac(int obj) {
	Struct_ov031_0221b0ac_2* store = (Struct_ov031_0221b0ac_2*)obj;
	int i;
	int var2 = data_ov031_0224e6a0.field8;

	for (i = 0; i < 4; i++) {
		Struct_ov031_0221b0ac* block = &store->blocks[i];
		int src = var2 + i * 0x100;
		store->blocks[i].unknown_fe_ = func_020d1cc8(store->unknown_500_, block->data, 0xfe);
		do {
			func_ov031_0221b780(src, 0x100, (int)block);
		} while (func_ov031_0221b7fc((int)block, src, 0x100, (int)store->work) == 0);
	}

	return func_ov031_0221b848() != 0;
}
