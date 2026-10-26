#include <globaldefs.h>

struct Struct_ov023_021e27f8 {
	unsigned short field0;
	unsigned short unknown_2_;
	short* list;
};

struct Struct_ov023_021e257c_3 {
	int pad0[2];
	struct Struct_ov023_021e27f8* arr;
	int pad2[2];
	unsigned short count;
};

// USA: func_ov023_021e27f8
extern "C" ARM void* func_ov023_021e27f8(struct Struct_ov023_021e257c_3* obj, int key) {
	struct Struct_ov023_021e27f8* arr = obj->arr;
	unsigned short count = obj->count;
	unsigned short i;
	for (i = 0; i < count; i++) {
		struct Struct_ov023_021e27f8* elem = (struct Struct_ov023_021e27f8*)((char*)arr + i * 0x18);
		unsigned short var4 = elem->unknown_2_;
		unsigned short j;
		for (j = 0; j < var4; j++) {
			if (elem->list[j] == key) return elem;
		}
	}
	return NULL;
}
