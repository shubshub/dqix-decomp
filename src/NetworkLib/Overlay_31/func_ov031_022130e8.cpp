#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void* func_ov031_022133f8(int);
extern "C" void func_ov031_0221314c(int, int, int);

struct Struct_ov031_022130e8 {
	unsigned char pad0[0x18];
	unsigned char arr[0xa];
	unsigned char field22;
};

// USA: func_ov031_022130e8
extern "C" ARM void func_ov031_022130e8(int a0, int a1, int a2, int a3, int a4) {
	Struct_ov031_022130e8* obj = (Struct_ov031_022130e8*)func_ov031_022133f8(1);
	if (a3 != 0) {
		VectorizedInvertedMemcpy((void*)a3, obj->arr, 0xa);
	} else {
		VectorizedMemset(obj->arr, 0, 0xa);
	}
	obj->field22 = a4;
	func_ov031_0221314c(a0, a1, a2);
}
