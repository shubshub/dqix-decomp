#include <globaldefs.h>

extern "C" int FastIntModulus(int a, int b);
extern "C" int FastIntDivide(int a, unsigned int b);
extern "C" void func_ov031_0223bdb0(int a0, int val, void* obj);

struct Struct_ov031_02222b0c { unsigned int word0; unsigned short unknown_4_; unsigned short pad6; };
struct Struct_ov031_02222b0c_2 {
	unsigned char pad0[4];
	Struct_ov031_02222b0c* field4;
	unsigned char byte8;
	unsigned char byte9;
};
extern Struct_ov031_02222b0c_2* data_ov031_02250ba4;
extern unsigned char data_ov031_02248910[];

// USA: func_ov031_02222c18
extern "C" ARM void func_ov031_02222c18(void) {
	data_ov031_02250ba4->byte9 = FastIntModulus(data_ov031_02250ba4->byte9 + 1, 0x28);
	int d = FastIntDivide(data_ov031_02250ba4->byte9, 5);
	func_ov031_0223bdb0(0, d + 0x47, data_ov031_02250ba4->field4);

	data_ov031_02250ba4->field4->unknown_4_ = (data_ov031_02250ba4->field4->unknown_4_ & ~0xc00) | 0x400;

	unsigned char t = data_ov031_02248910[data_ov031_02250ba4->byte8];
	Struct_ov031_02222b0c* e = data_ov031_02250ba4->field4;
	e->word0 &= ~0xc00;
	e->unknown_4_ = (e->unknown_4_ & ~0xf000) | (t << 12);

	data_ov031_02250ba4->field4->word0 = (data_ov031_02250ba4->field4->word0 & 0xfe00ff00) | 0x8b | 0xe60000;
}
