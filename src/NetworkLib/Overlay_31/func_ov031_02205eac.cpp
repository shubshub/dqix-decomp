#include <globaldefs.h>

extern "C" int func_ov031_02205ebc(int a);

struct Struct_ov031_02205eac {
	char pad[0x4];
	int field4;
};

// USA: func_ov031_02205eac
extern "C" ARM int func_ov031_02205eac(Struct_ov031_02205eac* obj) {
	return func_ov031_02205ebc(obj->field4);
}
