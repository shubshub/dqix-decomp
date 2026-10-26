#include <globaldefs.h>

struct Struct_ov017_021907dc { int x[4]; };
extern "C" void func_ov017_02190884(int b, Struct_ov017_021907dc* outBuf, int* zero, int c, int d, int e);

// USA: func_ov017_021907dc
extern "C" ARM void func_ov017_021907dc(int a, int b, int c, int d, int e) {
	Struct_ov017_021907dc buf;
	int zero = 0;
	func_ov017_02190884(b, &buf, &zero, c, d, e);
}
