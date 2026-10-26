#include <globaldefs.h>

struct Struct_ov031_0224e5ac {
	void* field0;
	void* field4;
};

extern Struct_ov031_0224e5ac data_ov031_0224e5ac;

extern "C" void* func_ov031_02211b20(void*);

typedef void (*Type_ov031_02211b98)(void*, void*, int);

// USA: func_ov031_02211b98
extern "C" ARM void func_ov031_02211b98(void* a, void* b) {
	if (b == NULL) return;
	void* obj = func_ov031_02211b20(b);
	int off = *(int*)((char*)obj + 4) + 0x20;
	Type_ov031_02211b98 fn = (Type_ov031_02211b98)data_ov031_0224e5ac.field0;
	fn(a, obj, off);
}
