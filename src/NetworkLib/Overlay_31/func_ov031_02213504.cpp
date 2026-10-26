#include <globaldefs.h>

extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
extern "C" ARM unsigned int func_ov031_022135ac(unsigned int idx);
extern "C" ARM void func_ov031_02215778(int a, void* b);
extern "C" void* func_ov031_0220f084(int a);

struct Struct_ov031_02213504 {
	unsigned char pad0[0x17];
	unsigned char unknown_17_;
	char name[0xa];
	unsigned char field22;
};

struct Struct_ov031_0224e5c4_8 {
	unsigned char pad0[0xc];
	Struct_ov031_02213504* obj;
};

extern Struct_ov031_0224e5c4_8 data_ov031_0224e5c4;

// USA: func_ov031_02213504
extern "C" ARM void func_ov031_02213504(unsigned int idx) {
	Struct_ov031_02213504* obj = data_ov031_0224e5c4.obj;
	unsigned int norm = obj->field22;
	if (norm == 0) {
		norm = func_ov031_022135ac(idx);
	}

	obj = data_ov031_0224e5c4.obj;
	obj->unknown_17_ = norm;
	void* p = func_ov031_0220f084(0);
	if (p != NULL) {
		InvalidateDataCacheRange(p, 0x20);
		obj = data_ov031_0224e5c4.obj;
		func_ov031_02215778((int)p, obj->name);
	}

	int i = 0;
	char* cur = (char*)data_ov031_0224e5c4.obj;
	Struct_ov031_02213504* base = data_ov031_0224e5c4.obj;
	do {
		signed char c = *(cur + 0x18);
		if (c < 0x20 || c > 0x7e) {
			VectorizedMemset(base->name, 0, 0xa);
			return;
		}
		i++;
		cur++;
	} while (i < 0xa);
}
