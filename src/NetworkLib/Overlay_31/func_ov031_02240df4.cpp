#include <globaldefs.h>

extern "C" void (*data_ov031_02290fc8)(void*);
extern "C" void func_ov031_02240e70(void*);

struct Struct_ov031_0223edb4 {
	char pad[0x30];
	void* unknown_30_;
};

// USA: func_ov031_02240df4
extern "C" ARM void func_ov031_02240df4(struct Struct_ov031_0223edb4* obj) {
	data_ov031_02290fc8(obj->unknown_30_);
	func_ov031_02240e70(obj);
}
