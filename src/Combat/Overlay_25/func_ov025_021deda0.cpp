#include <globaldefs.h>

struct Struct_ov025_021ded50_2 {
	unsigned short a;
	unsigned short b;
	unsigned short c;
};

extern "C" void func_ov025_021ded84(struct Struct_ov025_021ded50_2* dst, struct Struct_ov025_021ded50_2* src);

struct Struct_ov025_021ded50 {
#if defined(jpn)
	char pad[0x78dc];
#else
	char pad[0x76ec];
#endif
	struct Struct_ov025_021ded50_2 rows[5];
	unsigned short count;
};

// USA: func_ov025_021deda0
extern "C" ARM int func_ov025_021deda0(struct Struct_ov025_021ded50* t, struct Struct_ov025_021ded50_2* out) {
	if (t->count != 0) {
		func_ov025_021ded84(out, t->rows);
		t->count = t->count - 1;
		for (int i = 0; i < t->count; i++) {
			func_ov025_021ded84(&t->rows[i], &t->rows[i + 1]);
		}
		return 1;
	}
	return 0;
}
