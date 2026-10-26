#include <globaldefs.h>

struct Struct_ov014_02185c90_3 {
	unsigned short count;
	unsigned short unknown_2_;
	int unused1;
	int unknown_8_;
	void* arr;
};

extern "C" int func_ov014_02188b18(void* item);
extern "C" void* func_ov014_021892d4(struct Struct_ov014_02185c90_3* s, int key, int (*arg2)(void*));

// USA: func_ov014_021893c4
extern "C" ARM void* func_ov014_021893c4(struct Struct_ov014_02185c90_3* s, int id) {
	if (id < 0) return s->arr;
	return func_ov014_021892d4(s, id, func_ov014_02188b18);
}
