#include <globaldefs.h>

struct Struct_ov031_0223bd28 { unsigned int packed; unsigned int pad; };
struct Struct_ov031_02222f44_2 { unsigned char pad[8]; struct Struct_ov031_0223bd28* arr; };

// USA: func_ov031_0223bd28
extern "C" ARM void func_ov031_0223bd28(struct Struct_ov031_02222f44_2* h, int index, unsigned int* arg2, unsigned int* arg3) {
	struct Struct_ov031_0223bd28* arr = h->arr;
	*arg2 = (arr[index].packed & 0x1ff0000) >> 16;
	*arg3 = arr[index].packed & 0xff;
}
