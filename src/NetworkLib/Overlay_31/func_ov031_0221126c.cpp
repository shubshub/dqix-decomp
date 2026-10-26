#include <globaldefs.h>

extern "C" int func_ov031_0220f4bc(void);
extern "C" int func_ov031_022101e0(void);
extern "C" int func_ov031_02211410(void);
extern "C" void func_ov031_02211b98(int magic, void* p, int size);

struct Struct_ov031_0221126c {
	int field0;
};

extern Struct_ov031_0221126c* data_ov031_0224e590;

// USA: func_ov031_0221126c
extern "C" ARM int func_ov031_0221126c(void) {
	int ok = 1;
	Struct_ov031_0221126c* p = data_ov031_0224e590;
	if (p == NULL) return ok;
	p->field0 = 3;
	if (!func_ov031_0220f4bc()) ok = 0;
	if (!func_ov031_022101e0()) ok = 0;
	if (ok) {
		int size = func_ov031_02211410();
		func_ov031_02211b98(0x53574300, data_ov031_0224e590, size);
		data_ov031_0224e590 = NULL;
	}
	return ok;
}
