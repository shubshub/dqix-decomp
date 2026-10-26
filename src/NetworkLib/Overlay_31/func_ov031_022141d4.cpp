#include <globaldefs.h>

struct Struct_ov031_022141d4 { unsigned char state; };

extern "C" int func_ov031_0221425c(void);
extern "C" void func_ov031_02219178(void);
extern "C" void func_ov031_02219080(void);
extern "C" int func_ov031_022142ec(void);

// USA: func_ov031_022141d4
extern "C" ARM int func_ov031_022141d4(Struct_ov031_022141d4* p) {
	unsigned char st = p->state;
	if (st <= 0xa) {
		int r = func_ov031_0221425c();
		if (r == 1) {
			p->state = 0;
			return 1;
		}
		if (r == -1) {
			p->state = 0x12;
			return 1;
		}
	} else if (st == 0xe) {
		func_ov031_02219178();
		func_ov031_02219080();
		p->state = 0xc;
	} else if (st < 0x12) {
		if (func_ov031_022142ec() == 1) {
			p->state = 0xa;
		}
	}
	return 0;
}
