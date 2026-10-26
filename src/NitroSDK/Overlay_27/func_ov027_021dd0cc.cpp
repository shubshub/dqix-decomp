#include <globaldefs.h>

struct Struct_ov027_021e33e0_20 {
	unsigned char pad0[8];
	unsigned char* ptr;
};

extern Struct_ov027_021e33e0_20 data_ov027_021e33e0;

struct Struct_ov027_021dd0cc { unsigned short a; unsigned short b; };
typedef void (*Type_ov027_021dd0cc)(int, Struct_ov027_021dd0cc*);

// USA: func_ov027_021dd0cc
extern "C" ARM void func_ov027_021dd0cc(int a, int b) {
	if (b == 2 || b == 0) return;
	volatile unsigned short sb;
	volatile unsigned short sa;
	sa = (unsigned short)a;
	unsigned char* p = data_ov027_021e33e0.ptr;
	sb = (unsigned short)b;
	Type_ov027_021dd0cc fn = *(Type_ov027_021dd0cc*)(p + 0x51c);
	fn(0xff, (Struct_ov027_021dd0cc*)&sa);
}
