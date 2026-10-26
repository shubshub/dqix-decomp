#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov001_0215758c_2 {
	int x, y, z;
};

struct Struct_ov001_0215758c {
	struct Struct_ov001_0215758c_2 slots[16];
	struct Struct_ov001_0215758c_2 unknown_c0_[16];
	int count;
};

// USA: func_ov001_0215758c
extern "C" ARM int func_ov001_0215758c(struct Struct_ov001_0215758c* buf, struct Struct_ov001_0215758c_2 v1, struct Struct_ov001_0215758c_2 v2) {
	if (buf->count >= 16) {
		return 1;
	}
	memcpy(&buf->slots[buf->count], &v1, 0xc);
	memcpy(&buf->unknown_c0_[buf->count], &v2, 0xc);
	buf->count++;
	return 0;
}
