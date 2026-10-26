#include <globaldefs.h>

extern "C" int func_ov031_02211484(int flag, unsigned int val);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
extern "C" void* func_ov031_0220f518(void* obj);

struct Struct_ov031_02211310 {
	char pad0[0x10];
	int field10;
	int field14;
	int field18;
	char pad1[4];
	int field20;
	char pad2[4];
	int field28;
	char pad3[0x14];
	int field40;
	int field44;
};
extern Struct_ov031_02211310* data_ov031_0224e590;

// USA: func_ov031_02211310
extern "C" ARM int func_ov031_02211310(int a1, int a2, int a3, int a4, int a5) {
	if (!func_ov031_02211484(0, (unsigned int)a1)) {
		return 0;
	}
	Struct_ov031_02211310* p = data_ov031_0224e590;
	VectorizedMemset((char*)p + 0x14, 0, 0x28);
	p = data_ov031_0224e590;
	p->field14 = 3;
	p = data_ov031_0224e590;
	p->field18 = a1;
	p = data_ov031_0224e590;
	p->field20 = a2;
	p = data_ov031_0224e590;
	p->field28 = a3;
	p = data_ov031_0224e590;
	p->field40 = a4;
	p = data_ov031_0224e590;
	p->field44 = a5;
	p = data_ov031_0224e590;
	if (!func_ov031_0220f518((char*)p + 0x14)) {
		return 0;
	}
	data_ov031_0224e590->field10 = 1;
	return 1;
}
