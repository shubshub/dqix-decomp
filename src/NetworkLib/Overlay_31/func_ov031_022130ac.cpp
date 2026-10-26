#include <globaldefs.h>

extern "C" int func_ov031_022134b0(void);
extern "C" void func_ov031_022132d4(void);
extern "C" int func_ov031_022141d4(void*);
extern "C" void func_ov031_02213450(int);

// USA: func_ov031_022130ac
extern "C" ARM int func_ov031_022130ac(void) {
	unsigned char b = (unsigned char)func_ov031_022134b0();
	if (b == 0 || b == 0x12) {
		func_ov031_022132d4();
		return 1;
	}
	func_ov031_022141d4(&b);
	func_ov031_02213450(b);
	return 0;
}
