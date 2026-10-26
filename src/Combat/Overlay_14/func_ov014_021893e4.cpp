#include <globaldefs.h>

struct Struct_ov014_021893e4_2 {
	unsigned short idx;
	int unused1;
	int unknown_8_;
	int* arr;
};

struct Struct_ov014_021893e4 {
	short unused0;
	unsigned short field : 12;
};

// USA: func_ov014_021893e4
extern "C" ARM int* func_ov014_021893e4(struct Struct_ov014_021893e4_2* a, struct Struct_ov014_021893e4* b) {
	if (!b) return NULL;
	return a->arr + a->idx + b->field;
}
