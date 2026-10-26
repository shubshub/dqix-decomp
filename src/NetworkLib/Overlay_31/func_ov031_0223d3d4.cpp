#include <globaldefs.h>

struct Struct_ov031_0223d3d4 { unsigned char pad[0x36]; unsigned short unknown_36_; };
struct Struct_ov031_02290d40_5 { unsigned char pad[4]; struct Struct_ov031_0223d3d4* inner; };
extern struct Struct_ov031_02290d40_5 data_ov031_02290d40;

// USA: func_ov031_0223d3d4
extern "C" ARM int func_ov031_0223d3d4(int mask) {
	int v = *(unsigned short*)0x27fffa8 & 0x8000;
	if (v >> 15) {
		return 0;
	}
	int f = data_ov031_02290d40.inner->unknown_36_;
	int w = mask & f;
	return (mask == w) ? 1 : 0;
}
