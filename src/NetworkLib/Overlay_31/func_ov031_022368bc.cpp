#include <globaldefs.h>

struct Struct_020bc1cc { char pad[0x3c]; unsigned char f3c; };
struct Struct_020bc1cc_2 { struct Struct_020bc1cc* f0; };

extern "C" void func_020bc1cc(struct Struct_020bc1cc_2*, int, int);
extern void* data_ov031_02290d00;

// USA: func_ov031_022368bc
extern "C" ARM void func_ov031_022368bc(int arg0, int arg1) {
	func_020bc1cc((struct Struct_020bc1cc_2*)((char*)data_ov031_02290d00 + 0x94), arg0, arg1);
}
