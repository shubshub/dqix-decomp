#include <globaldefs.h>

extern "C" int func_ov031_022305a4(int);
extern "C" void func_ov031_022307fc(void);
extern unsigned char data_ov031_02290ca0;
extern unsigned char data_ov031_02249054;

// USA: func_ov031_02230984
extern "C" ARM void func_ov031_02230984(int idx) {
	(&data_ov031_02290ca0)[0] = (unsigned char)idx;
	int v = (&data_ov031_02249054)[idx];
	int r = func_ov031_022305a4(v);
	(&data_ov031_02290ca0)[2] = (unsigned char)r;
	func_ov031_022307fc();
}
