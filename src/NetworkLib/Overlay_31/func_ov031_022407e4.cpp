#include <globaldefs.h>

struct Struct_ov031_022407e4 { unsigned char pad[0xc]; unsigned int unknown_c_; };

// USA: func_ov031_022407e4
extern "C" ARM int func_ov031_022407e4(struct Struct_ov031_022407e4* obj, unsigned int val) {
	return obj->unknown_c_ <= val;
}
