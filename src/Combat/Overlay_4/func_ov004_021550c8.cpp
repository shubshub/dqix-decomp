#include <globaldefs.h>

struct Struct_ov004_02155090 {
	short id;
	char pad[4];
};

// USA: func_ov004_021550c8
extern "C" ARM void* func_ov004_021550c8(Struct_ov004_02155090* arr, int key) {
	unsigned char i;
	for (i = 0; i < 2; i++) {
		short v = arr[i].id;
		if (v == key) return &arr[i];
	}
	return NULL;
}
