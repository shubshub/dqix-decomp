#include <globaldefs.h>

struct Struct_ov031_022358b4;
struct Struct_02101680;
extern "C" int func_020d5340(int a0, struct Struct_02101680* ctx);
extern char* data_ov031_02290cf8;
extern "C" void func_ov031_022359e0(void);

// USA: func_ov031_022358b4
extern "C" ARM int func_ov031_022358b4(struct Struct_ov031_022358b4* obj) {
	int r = func_020d5340((int)func_ov031_022359e0, (struct Struct_02101680*)(data_ov031_02290cf8 + 0x248 + 0x1400));
	return r == 2;
}
