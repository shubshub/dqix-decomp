#include <globaldefs.h>

extern "C" int func_020d6830(int a, unsigned short* b, int c);

struct Struct_ov031_02290d18_25 { unsigned char pad[4]; unsigned char* inner; };
extern struct Struct_ov031_02290d18_25 data_ov031_02290d18;

// USA: func_ov031_0223a288
extern "C" ARM int func_ov031_0223a288(int c) {
	unsigned char* inner = data_ov031_02290d18.inner;
	return func_020d6830((int)(inner + 0x13e0), (unsigned short*)(inner + 0x1c00), c);
}
