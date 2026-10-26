#include <globaldefs.h>

struct Struct_ov031_0221a4cc {
	unsigned int unk0;
	void (*func)(void*, void*, int);
};

extern "C" void func_ov031_022183b4(void* p);
extern Struct_ov031_0221a4cc* data_ov031_0224e69c;
extern void* data_ov031_0224a254;

// USA: func_ov031_0221a4cc
extern "C" ARM void func_ov031_0221a4cc() {
	Struct_ov031_0221a4cc* obj = data_ov031_0224e69c;
	if (obj == NULL) return;
	func_ov031_022183b4((char*)obj + 8);
	obj = data_ov031_0224e69c;
	obj->func(&data_ov031_0224a254, obj, 0);
	data_ov031_0224e69c = NULL;
}
