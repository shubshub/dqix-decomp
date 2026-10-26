#include <globaldefs.h>
#include "NitroSDK/Memory.h"

typedef void* (*Type_ov031_0221a434)(void*, unsigned int);

extern "C" void func_ov031_02211b08(int a, int b);

extern char* data_ov031_0224e69c;
extern void* data_ov031_0224a244;

struct Struct_ov031_0221a434 {
	Type_ov031_0221a434 unknown_0_;
	void* other;
};

// USA: func_ov031_0221a434
extern "C" ARM int func_ov031_0221a434(Type_ov031_0221a434 arg0, void* other) {
	if (data_ov031_0224e69c != NULL) {
		func_ov031_02211b08(9, 0xffffa1dc);
		return 0;
	}
	void* obj = arg0(&data_ov031_0224a244, 0x1c20);
	data_ov031_0224e69c = (char*)obj;
	if (obj == NULL) {
		func_ov031_02211b08(9, 0xffffa1dc);
		return 0;
	}
	VectorizedMemset(obj, 0, 0x1c20);
	((Struct_ov031_0221a434*)data_ov031_0224e69c)->unknown_0_ = arg0;
	((Struct_ov031_0221a434*)data_ov031_0224e69c)->other = other;
	return 1;
}
