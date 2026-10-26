#include <globaldefs.h>

struct Struct_ov031_02290ca0_23 {
	unsigned char idx;
	unsigned char pad[7];
	unsigned char* ptr;
};
extern struct Struct_ov031_02290ca0_23 data_ov031_02290ca0;
extern "C" void func_ov031_0222f9ec(void);

// USA: func_ov031_02230cd8
extern "C" ARM void func_ov031_02230cd8(void) {
	int i = 0;
	do {
		unsigned char *p = data_ov031_02290ca0.ptr + i;
		if (p[4] != 0) {
			p[4]--;
			if (*(data_ov031_02290ca0.ptr + i + 4) == 0) func_ov031_0222f9ec();
		}
		i++;
	} while (i < 4);
}
