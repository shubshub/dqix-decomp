#include <globaldefs.h>

struct Struct_020bc158;
extern "C" void func_020bc158(Struct_020bc158*, unsigned char);
extern void* data_ov031_02290d00;

// USA: func_ov031_0223689c
extern "C" ARM void func_ov031_0223689c(unsigned char val) {
	func_020bc158((Struct_020bc158*)((char*)data_ov031_02290d00 + 0x94), val);
}
