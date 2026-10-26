#include <globaldefs.h>

struct Struct_ov004_02153860 {
	short id;
	char pad[4];
};

// USA: func_ov004_021538b4
extern "C" ARM void* func_ov004_021538b4(Struct_ov004_02153860* arr, int key) {
	unsigned char i;
	for (i = 0; i < 20; i++) {
		short v = arr[i].id;
		if (v == key) return &arr[i];
	}
	return NULL;
}
