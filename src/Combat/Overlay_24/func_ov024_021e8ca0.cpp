#include <globaldefs.h>

extern "C" int func_ov000_0215e958(int a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215ffc4(void* obj, void* node, int idx);

struct Struct_ov024_021e2bd0 { char unknown_0_[0xc]; void* field0c; void* field10; };

// USA: func_ov024_021e8ca0
extern "C" ARM void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id) {
	void* entry = (void*)func_ov000_0215e958((int)obj->field10);
	if (!entry) return 0;
	func_ov000_0215a88c(obj->field10, entry, id);
	func_ov000_0215ffc4(obj->field0c, entry, 1);
	((unsigned char*)obj->field10)[0x8e02] = ((unsigned char*)obj->field10)[0x8e02] + 1;
	return entry;
}
