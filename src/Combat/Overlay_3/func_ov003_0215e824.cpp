#include <globaldefs.h>

struct Struct_ov003_0215e824_2 {
	char pad0[0x10];
	short key;   // 0x10
	char pad1[2];
};

struct List0215e824 {
	struct Struct_ov003_0215e824_2* base; // 0x0
	char pad0[2];
	short count;               // 0x6
};

// USA: func_ov003_0215e824
extern "C" ARM struct Struct_ov003_0215e824_2* func_ov003_0215e824(struct List0215e824* list, int key) {
	struct Struct_ov003_0215e824_2* e = list->base;
	int count = list->count;
	for (int i = 0; i < count; i++, e++) {
		if (e->key == key) return e;
	}
	return NULL;
}
