#include <globaldefs.h>

extern "C" int func_ov031_022134b0(void);
extern "C" int func_ov031_02214358(void);

// USA: func_ov031_02212fb8
extern "C" ARM int func_ov031_02212fb8(void) {
	unsigned int v = func_ov031_022134b0();
	if (v <= 1) return 0;
	if (v < 7) return 1;
	if (v == 9) return 4;
	if (v < 0xa) return 2;
	if (v == 0xb) return 4;
	if (v < 0x10) return 3;
	if (v == 0x10) return 5;
	if (v == 0x11) return 4;
	return func_ov031_02214358();
}
