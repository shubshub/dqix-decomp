#include <globaldefs.h>

struct Struct_ov014_02187450_2 {
	char pad[0x1a];
	short unknown_1a_;
};

struct Struct_ov014_02187450 {
	char pad[0xdc];
	int* arr;
};

// USA: func_ov014_02187450
extern "C" ARM int* func_ov014_02187450(struct Struct_ov014_02187450* obj, struct Struct_ov014_02187450_2* b) {
	if (!b) return NULL;
	short idx = b->unknown_1a_ - 1;
	if (idx < 0) goto ret_null;
	if (idx < 0x134) {
		return obj->arr + idx;
	}
ret_null:
	return NULL;
}
