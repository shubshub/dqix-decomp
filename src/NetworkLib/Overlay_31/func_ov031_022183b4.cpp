#include <globaldefs.h>

extern "C" void* VectorizedMemset(void* dst, int val, int n);

struct Struct_ov031_022183b4;
extern "C" void func_ov031_02218f18(void* obj, Struct_ov031_022183b4* arr, int count);
extern "C" void func_ov031_022187fc(int obj, void* buf);

extern int data_ov031_02249e2c;
extern int data_ov031_02249e44;

typedef void (*Type_ov031_022183b4)(void*, int, int);

// USA: func_ov031_022183b4
extern "C" ARM void func_ov031_022183b4(void* arg0) {
	char* obj = (char*)arg0;
	Type_ov031_022183b4 fn = *(Type_ov031_022183b4*)(obj + 0x1014);
	if (arg0 == 0) return;

	func_ov031_02218f18(obj, (Struct_ov031_022183b4*)(obj + 0x1a38), 0x20);
	func_ov031_022187fc((int)obj, obj + 0x1a08);
	func_ov031_022187fc((int)obj, obj + 0x19f8);

	int v0 = *(int*)(obj + 0x19cc);
	if (v0 != 0) {
		fn(&data_ov031_02249e2c, v0, 0);
		*(int*)(obj + 0x19cc) = 0;
	}

	int v1 = *(int*)(obj + 0x19d0);
	if (v1 != 0) {
		fn(&data_ov031_02249e44, v1, 0);
		*(int*)(obj + 0x19d0) = 0;
	}

	VectorizedMemset(obj, 0, 0x1c14);
}
