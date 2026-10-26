#include <globaldefs.h>

struct Struct_ov014_02189380;
extern "C" int* func_ov014_02189380(struct Struct_ov014_02189380* s);

struct Struct_ov014_02189398 {
	char pad0[4];
	unsigned short count;
	char pad6[6];
	int* arr;
};

// USA: func_ov014_02189398
extern "C" ARM int* func_ov014_02189398(struct Struct_ov014_02189398* s) {
	int* arr = s->arr;
	int off = (int)func_ov014_02189380((struct Struct_ov014_02189380*)s) + (s->count << 1) - (int)arr;
	off = (off + 3) & ~3;
	return (int*)((char*)arr + off);
}
