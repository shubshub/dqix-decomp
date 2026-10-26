#include <globaldefs.h>

struct Struct_ov014_02189380 {
	unsigned short a;
	unsigned short b;
	int unused1;
	int unknown_8_;
	int* arr;
};

// USA: func_ov014_02189380
extern "C" ARM int* func_ov014_02189380(struct Struct_ov014_02189380* s) {
	return s->arr + s->a + s->b;
}
