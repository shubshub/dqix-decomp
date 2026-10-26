#include <globaldefs.h>

struct Struct_ov031_02290da0_4 { void* field0; char pad[0x10]; int field14; };
extern struct Struct_ov031_02290da0_4 data_ov031_02290da0;
extern "C" int func_ov031_0223fd9c(void*);
extern "C" void func_ov031_0223e868(void);

// USA: func_ov031_0223e8ac
extern "C" ARM int func_ov031_0223e8ac(void* arg) {
	data_ov031_02290da0.field14 = 0;
	data_ov031_02290da0.field0 = arg;
	return func_ov031_0223fd9c((void*)func_ov031_0223e868);
}
