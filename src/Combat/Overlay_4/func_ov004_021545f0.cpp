#include <globaldefs.h>

struct Struct_ov004_021545f0 {
	short a;
	short b;
	unsigned char c;
	unsigned char d;
};

// USA: func_ov004_021545f0
extern "C" ARM void func_ov004_021545f0(Struct_ov004_021545f0* arr, int idx, short v0, short v1, unsigned char v2, unsigned char v3) {
	arr[idx].a = v0;
	arr[idx].b = v1;
	arr[idx].c = v2;
	arr[idx].d = v3;
}
