#include <globaldefs.h>

extern "C" ARM void func_ov031_02211e08(void);
extern "C" ARM int func_ov031_02212248(void);
extern "C" ARM int func_ov031_02213024(void);
extern "C" ARM int func_ov031_0220d540(void);
extern "C" ARM void func_ov031_02211b08(int a, int b);

// USA: func_ov031_022123d4
extern "C" ARM int func_ov031_022123d4(void) {
	func_ov031_02211e08();
	if (func_ov031_02212248()) {
		unsigned int var0 = func_ov031_02213024();
		if (var0 == 0xff || var0 > 0x63) var0 = 0x63;

		if (func_ov031_0220d540() == 0xb) {
			func_ov031_02211b08(9, (int)0xffff298c - var0);
		} else {
			func_ov031_02211b08(8, (int)0xffff2d10 - var0);
		}
		return 1;
	}
	return 0;
}
