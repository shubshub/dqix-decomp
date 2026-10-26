#include <globaldefs.h>

struct Struct_ov031_02235620 {
	short a;
	short b;
	short c;
	short d;
};

extern "C" void func_ov031_0223566c(int arg0, Struct_ov031_02235620* out);
extern "C" int func_ov031_0223d414(Struct_ov031_02235620* buf);

// USA: func_ov031_02235620
extern "C" ARM int func_ov031_02235620(void) {
	int i = 2;
	Struct_ov031_02235620 buf;
	do {
		func_ov031_0223566c(i, &buf);
		if (func_ov031_0223d414(&buf) != 0) return i;
		i++;
	} while (i <= 3);
	return 0;
}
