#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov014_021845ec;
extern "C" int func_ov014_02188d10(struct Struct_ov014_021845ec* s);

struct Struct_ov014_021844c4 {
	char pad[0x14];
	short field14;
	int handle;
	int field1c;
};

// USA: func_ov014_02188bd0
extern "C" ARM int func_ov014_02188bd0(struct Struct_ov014_021844c4* s) {
	memset(s, 0, 0x14);
	s->field14 = -1;
	s->handle = -1;
	return func_ov014_02188d10((struct Struct_ov014_021845ec*)s);
}
