#include <globaldefs.h>

extern "C" void func_ov031_0220572c(void* ctx, unsigned short a, unsigned int b);

struct Struct_ov031_02207230 {
	char pad0[2];
	unsigned short half;
	unsigned int word;
};

// USA: func_ov031_02207230
extern "C" ARM void func_ov031_02207230(void* ctx, Struct_ov031_02207230* arg1) {
	unsigned short h = arg1->half;
	unsigned int w = arg1->word;
	unsigned short var2 = (unsigned short)(((h >> 8) & 0xff) | ((h << 8) & 0xff00));
	unsigned int var3 = ((w >> 24) & 0xff) | ((w >> 8) & 0xff00) | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
	func_ov031_0220572c(ctx, var2, var3);
}
