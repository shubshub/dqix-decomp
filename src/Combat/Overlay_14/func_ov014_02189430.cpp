#include <globaldefs.h>

struct Struct_ov014_02189398;
struct Struct_ov014_021893e4_2;
struct Struct_ov014_021893e4;
extern "C" ARM int* func_ov014_0218940c(struct Struct_ov014_021893e4_2* table, int index, struct Struct_ov014_021893e4* key);
extern "C" ARM int* func_ov014_02189398(struct Struct_ov014_02189398* s);

// USA: func_ov014_02189430
extern "C" ARM int* func_ov014_02189430(struct Struct_ov014_02189398* obj, int index, struct Struct_ov014_021893e4* key) {
	if (!key) return 0;
	int* slot = func_ov014_0218940c((struct Struct_ov014_021893e4_2*)obj, index, key);
	if (!slot) return 0;
	int* base = func_ov014_02189398(obj);
	return base + *(unsigned short*)slot;
}
