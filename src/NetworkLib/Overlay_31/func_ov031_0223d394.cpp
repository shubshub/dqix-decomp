#include <globaldefs.h>

struct Struct_ov031_0223d394 { unsigned char pad[0x34]; unsigned short field34; };
struct Struct_ov031_02290d40_4 { unsigned char pad[4]; struct Struct_ov031_0223d394* inner; };
extern struct Struct_ov031_02290d40_4 data_ov031_02290d40;

// USA: func_ov031_0223d394
extern "C" ARM int func_ov031_0223d394(int mask) {
	int v = *(unsigned short*)0x27fffa8 & 0x8000;
	if (v >> 15) {
		return 0;
	}
	int f = data_ov031_02290d40.inner->field34;
	int w = mask & f;
	return (mask == w) ? 1 : 0;
}
