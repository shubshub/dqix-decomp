#include <globaldefs.h>

struct Struct_02101680;
extern "C" int func_020d5340(int a0, struct Struct_02101680* ctx);
extern char* data_ov031_02290d0c;
extern "C" void func_ov031_022376fc(void);

// USA: func_ov031_022375cc
extern "C" ARM int func_ov031_022375cc(void) {
	int r = func_020d5340((int)func_ov031_022376fc, (struct Struct_02101680*)(data_ov031_02290d0c + 0x374 + 0x1000));
	return r == 2;
}
