#include <globaldefs.h>

extern "C" int func_ov031_022070bc(int x);

struct Struct_ov031_02205620 {
	int field0;
	int field4;
};

// USA: func_ov031_02205620
extern "C" ARM int func_ov031_02205620(int a, struct Struct_ov031_02205620* p, int c) {
	p->field4 = c ? a : 0;
	p->field0 = c;
	return a + func_ov031_022070bc(c);
}
