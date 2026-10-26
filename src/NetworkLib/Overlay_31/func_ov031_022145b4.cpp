#include <globaldefs.h>

struct Struct_ov031_022145b4 {
	char pad[0xd0c];
	unsigned char field : 4;
};

extern "C" struct Struct_ov031_022145b4* func_ov031_022133f8(int a0);
extern "C" int strncmp(const void*, const void*, unsigned int);

extern char data_ov031_02245fe0[8];

// USA: func_ov031_022145b4
extern "C" ARM int func_ov031_022145b4(char* obj) {
	unsigned int v = func_ov031_022133f8(0x10)->field;
	if (v == 0 || v == 6) {
		if (strncmp(obj + 0xc, data_ov031_02245fe0, 8) == 0) {
			return 8;
		}
	}
	return 0;
}
