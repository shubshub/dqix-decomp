#include <globaldefs.h>

struct Struct_ov031_02290ca0_22 {
	unsigned char idx;
	unsigned char pad[7];
	unsigned char* ptr;
};
extern struct Struct_ov031_02290ca0_22 data_ov031_02290ca0;
extern unsigned char data_ov031_02248f58[];
extern "C" int func_ov031_02234ff8(int, int, int);

// USA: func_ov031_02230ca4
extern "C" ARM int func_ov031_02230ca4(void) {
	unsigned char b = data_ov031_02248f58[data_ov031_02290ca0.idx - 0xb];
	int v = *(int*)(data_ov031_02290ca0.ptr + 0x10);
	return func_ov031_02234ff8(v, b, b);
}
