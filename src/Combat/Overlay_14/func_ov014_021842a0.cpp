#include <globaldefs.h>

struct Struct_ov014_021842a0 {
	short id;
	char pad[0x16];
};

struct Struct_ov014_021842a0_2 {
	char pad0[8];
	struct Struct_ov014_021842a0* arr;
	char unknown_c_[8];
	unsigned short count;
};

// USA: func_ov014_021842a0
extern "C" ARM struct Struct_ov014_021842a0* func_ov014_021842a0(struct Struct_ov014_021842a0_2* obj, short id) {
	struct Struct_ov014_021842a0* arr = obj->arr;
	if (arr == 0) return 0;
	unsigned short count = obj->count;
	if (count == 0) return 0;
	for (unsigned short i = 0; i < count; i++) {
		short v = arr[i].id;
		if (v == id) return &arr[i];
	}
	return 0;
}
