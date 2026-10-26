#include <globaldefs.h>

extern "C" void func_ov031_02210358(int a, int b);
extern "C" void func_ov031_022103dc(void* value);
extern "C" int func_ov031_02210f24(const char* s);
extern "C" int func_ov031_02210f78(int a, int code, void* buf);
extern "C" ARM void func_ov031_022103f8(void* value);
extern "C" int func_ov031_022071d8(int unused, int mode, int extra);
struct Struct_ov031_022078f0;
extern "C" ARM int func_ov031_022078f0(struct Struct_ov031_022078f0* obj, void* v);
struct Struct_ov031_02207230;
extern "C" int func_ov031_02207230(void* ctx, struct Struct_ov031_02207230* arg1);

struct Struct_ov031_02210988 {
	char pad0[0x4];
	int field4;
	char pad1[0x20 - 0x8];
	int field20;
	unsigned short field24;
	char pad2[0x48 - 0x26];
	char field48[1];
	char pad3[0x1b8 - 0x49];
	int unknown_1b8_;
	char pad4[0x1d4 - 0x1bc];
};
extern Struct_ov031_02210988* data_ov031_0224e588;
extern void* data_ov031_022499f8;

// USA: func_ov031_02210988
extern "C" ARM void func_ov031_02210988(void) {
	unsigned char local[8];

	void* r4 = &data_ov031_022499f8;
	int mode = 0xd68f;
	int h = data_ov031_0224e588->field20;
	if (h != 0) {
		r4 = (void*)h;
	} else if (func_ov031_02210f24(data_ov031_0224e588->field48)) {
		r4 = (char*)data_ov031_0224e588 + 0x48;
	}

	int var4 = data_ov031_0224e588->field24;
	if (var4 != 0) mode = var4;

	if (data_ov031_0224e588->field4 == 2) {
		func_ov031_022103dc((void*)5);
		return;
	}

	if (!func_ov031_02210f78((int)r4, mode, local)) {
		func_ov031_02210358(5, 5 - 0x23);
		func_ov031_022103f8((void*)5);
		return;
	}

	if (data_ov031_0224e588->field4 == 2) {
		func_ov031_022103dc((void*)5);
		return;
	}

	int sel = func_ov031_022071d8(2, 1, 0);
	if (sel < 0) {
		func_ov031_02210358(5, 5 - 0x37);
		func_ov031_022103f8((void*)5);
		return;
	}
	data_ov031_0224e588->unknown_1b8_ = sel;

	if (data_ov031_0224e588->field4 == 2) {
		func_ov031_022103dc((void*)5);
		return;
	}

	int val = func_ov031_022078f0((struct Struct_ov031_022078f0*)data_ov031_0224e588->unknown_1b8_, (char*)data_ov031_0224e588 + 0x1d4);
	if (val < 0) {
		func_ov031_02210358(5, 5 - 0x37);
		func_ov031_022103f8((void*)5);
		return;
	}

	if (data_ov031_0224e588->field4 == 2) {
		func_ov031_022103dc((void*)5);
		return;
	}

	int var7 = func_ov031_02207230((void*)data_ov031_0224e588->unknown_1b8_, (struct Struct_ov031_02207230*)local);
	if (var7 < 0) {
		func_ov031_02210358(6, 6 - 0x42);
		func_ov031_022103f8((void*)5);
		return;
	}
	func_ov031_022103dc((void*)6);
}
