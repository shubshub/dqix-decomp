#include <globaldefs.h>

struct Struct_ov031_0224e5ac {
	void* field0;
	void* field4;
};

extern Struct_ov031_0224e5ac data_ov031_0224e5ac;

// USA: func_ov031_02211b40
extern "C" ARM void func_ov031_02211b40(void* a, void* b) {
	data_ov031_0224e5ac.field4 = a;
	data_ov031_0224e5ac.field0 = b;
}
