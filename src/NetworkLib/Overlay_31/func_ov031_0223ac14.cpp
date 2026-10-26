#include <globaldefs.h>

extern "C" int func_ov031_022386d4(void*, unsigned short);
struct Struct_ov031_0223ac14 { char pad[0x648]; unsigned short unknown_648_; char pad2[0xac8 - 0x64a]; void* unknown_ac8_; };
extern struct Struct_ov031_0223ac14* data_ov031_02290d20;

// USA: func_ov031_0223ac14
extern "C" ARM int func_ov031_0223ac14(void) {
	struct Struct_ov031_0223ac14* b = data_ov031_02290d20;
	return func_ov031_022386d4(b->unknown_ac8_, b->unknown_648_);
}
