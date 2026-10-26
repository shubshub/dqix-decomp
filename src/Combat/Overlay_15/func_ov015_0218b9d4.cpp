#include <globaldefs.h>

struct Struct_ov015_0218b5c8 {
	int a;
	int b;
	unsigned short c;
	unsigned char d;
	unsigned char e;
};

struct Struct_ov015_0218b9d4 {
	Struct_ov015_0218b5c8* arr;
	int pad4;
	int count;
};

// USA: func_ov015_0218b9d4
extern "C" ARM void func_ov015_0218b9d4(struct Struct_ov015_0218b9d4* list, struct Struct_ov015_0218b5c8* src) {
	int index = list->count;
	Struct_ov015_0218b5c8* dst;
	list->count = index + 1;
	dst = list->arr + index;
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
	dst->d = src->d;
	dst->e = src->e;
}
