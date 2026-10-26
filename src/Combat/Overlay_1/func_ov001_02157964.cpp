#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov001_02157964_2 {
	int x, y, z;
};

struct Struct_ov001_02157964 {
	struct Struct_ov001_02157964_2 slots[16];
	int unknown_c0_;
	int count;
};

// USA: func_ov001_02157964
extern "C" ARM int func_ov001_02157964(struct Struct_ov001_02157964* buf, struct Struct_ov001_02157964_2 v) {
	if (buf->count >= 16) {
		return 1;
	}
	memcpy(&buf->slots[buf->count], &v, 0xc);
	buf->count++;
	return 0;
}
