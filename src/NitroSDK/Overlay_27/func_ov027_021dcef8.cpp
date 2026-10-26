#include <globaldefs.h>

extern "C" int func_020d59bc(int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_ov027_021dd0cc(int a, int b);

// USA: func_ov027_021dcef8
extern "C" ARM int func_ov027_021dcef8(int p0, int p1, int p2, int p3, unsigned short p4) {
	int result = func_020d59bc(p0, 0, p1, p2, p4, 1, 3);
	func_ov027_021dd0cc(0xf, result);
	return result;
}
