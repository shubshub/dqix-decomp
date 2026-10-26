#include <globaldefs.h>

extern int data_ov017_021d83ac;
extern "C" void func_ov002_0216c2d8(int a, int b, int c, int d, unsigned char e);

// USA: func_ov017_021a5a88
extern "C" ARM void func_ov017_021a5a88(int arg0, int b, int c, int d, unsigned char e) {
	if (data_ov017_021d83ac != 0) {
		func_ov002_0216c2d8(data_ov017_021d83ac, b, c, d, e);
	}
}
