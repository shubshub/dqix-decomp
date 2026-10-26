#include <globaldefs.h>

struct Struct_ov001_0215758c_2 {
	int x, y, z;
};

struct Struct_ov001_02158348 {
	int f0;
	struct Struct_ov001_0215758c_2 v1;
	struct Struct_ov001_0215758c_2 v2;
};

struct Struct_ov001_0215758c;
extern "C" int func_ov001_0215758c(struct Struct_ov001_0215758c* buf, struct Struct_ov001_0215758c_2 v1, struct Struct_ov001_0215758c_2 v2);

// USA: func_ov001_02158348
extern "C" ARM int func_ov001_02158348(struct Struct_ov001_02158348* self, char* dest) {
	func_ov001_0215758c((struct Struct_ov001_0215758c*)(dest + 0x15c), self->v1, self->v2);
	return 0;
}
