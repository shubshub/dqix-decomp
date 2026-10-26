#include <globaldefs.h>

struct Struct_ov027_021e33e0_3 {
	unsigned char pad0[8];
	unsigned char* ptr;
	unsigned char* ptrC;
};

extern Struct_ov027_021e33e0_3 data_ov027_021e33e0;

typedef void (*Type_ov027_021db4e0)(int, int);

// USA: func_ov027_021db4e0
extern "C" ARM void func_ov027_021db4e0(int a) {
	data_ov027_021e33e0.ptr[0x50d] = 0;
	*(unsigned short*)(data_ov027_021e33e0.ptrC + 0x1300 + 0x16) = 0;
	Type_ov027_021db4e0 fn = *(Type_ov027_021db4e0*)(data_ov027_021e33e0.ptr + 0x51c);
	if (fn) fn(0x11, a);
}
