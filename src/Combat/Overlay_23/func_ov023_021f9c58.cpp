#include <globaldefs.h>

struct Struct_ov011_02186cb8 {
	char pad[0x44];
	short val;
};

// USA: func_ov023_021f9c58
extern "C" ARM void func_ov023_021f9c58(Struct_ov011_02186cb8* obj, unsigned short v) {
	obj->val = v;
}
