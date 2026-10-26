#include <globaldefs.h>

struct Struct_ov011_02187da8 {
	char pad[0x39];
	unsigned char val;
};

// USA: func_ov023_021fb284
extern "C" ARM void func_ov023_021fb284(Struct_ov011_02187da8* obj, int v) {
	obj->val = v;
}
