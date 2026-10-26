#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov027_021e3424_2 {
	char pad[4];
	void *arr;
};

extern struct Struct_ov027_021e3424_2 data_ov027_021e3424;

// USA: func_ov027_021dd5f4
extern "C" ARM void func_ov027_021dd5f4(int index) {
	void *base = data_ov027_021e3424.arr;
	if (base != NULL) {
		int idx = index - 1;
		VectorizedMemset((char *)base + (idx << 5), 0, 0x1e);
		*(int *)((char *)data_ov027_021e3424.arr + (idx << 2) + 0x1e0) = 0;
	}
}
