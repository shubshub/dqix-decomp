#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov001_021587c4 {
	int header;
	int x, y, z;
};

// USA: func_ov001_021587c4
extern "C" ARM int func_ov001_021587c4(struct Struct_ov001_021587c4* delta, char* obj) {
	int* src = *(int**)(obj + 0xa20);
	if (src == NULL) {
		return 0;
	}
	memcpy(obj + 0x58, (char*)src + 0x74, 0xc);
	*(int*)(obj + 0x58) = *(int*)(obj + 0x58) + delta->x;
	*(int*)(obj + 0x5c) = *(int*)(obj + 0x5c) + delta->y;
	*(int*)(obj + 0x60) = *(int*)(obj + 0x60) + delta->z;
	return 1;
}
