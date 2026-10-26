#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
extern "C" int func_ov031_02214410(void*);

struct Struct_ov031_02214358 { unsigned char pad[0xb]; unsigned char unknown_b_; };

extern "C" int func_ov031_022143a8(unsigned int c);
extern "C" int func_ov031_022143ec(void);
extern "C" int func_ov031_022143f4(struct Struct_ov031_02214358* e);
extern "C" void* func_ov031_022134f0(void);

// USA: func_ov031_02214358
extern "C" ARM int func_ov031_02214358(void) {
	char* var0 = func_ov031_022133f8(1);
	int val = (int)func_ov031_022134f0();
	if (val < 4) return func_ov031_022143a8(val);
	if (val < 5) return func_ov031_022143ec();
	if (val == 5) return func_ov031_022143f4((struct Struct_ov031_02214358*)var0);
	return func_ov031_02214410(var0);
}
