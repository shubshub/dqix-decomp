#include <globaldefs.h>

struct Struct_ov031_0220520c;
extern "C" int func_ov031_0220520c(void*, Struct_ov031_0220520c*);

struct Struct_ov031_0220528c {
	char pad[0x68];
	int field68;
};

// USA: func_ov031_0220528c
extern "C" ARM int func_ov031_0220528c(Struct_ov031_0220528c* obj, void* extra) {
	return func_ov031_0220520c((void*)obj->field68, (Struct_ov031_0220520c*)extra);
}
