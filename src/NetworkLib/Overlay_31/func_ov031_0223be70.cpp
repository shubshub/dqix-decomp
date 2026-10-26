#include <globaldefs.h>

struct Struct_ov031_0223be70 { unsigned short f0; short pad; int f4; };
extern Struct_ov031_0223be70* data_ov031_02290d2c[];

extern "C" void* func_ov031_0223b8c4(int, int, int);
extern "C" void* func_ov031_0223baa0(void*, int);
extern "C" void func_ov031_0223bdb0(int, int, void*);

// USA: func_ov031_0223be70
extern "C" ARM void* func_ov031_0223be70(int a, int b, int c) {
	int s = data_ov031_02290d2c[a][b].f0;
	void* arr = func_ov031_0223b8c4(a, s, c);
	void* e = func_ov031_0223baa0(arr, 0);
	func_ov031_0223bdb0(a, b, e);
	return arr;
}
