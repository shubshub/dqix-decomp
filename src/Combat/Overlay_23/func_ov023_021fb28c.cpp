#include <globaldefs.h>

struct Struct_ov023_021fb28c {
	char pad[0xc];
	unsigned char flags;
};

// USA: func_ov023_021fb28c
extern "C" ARM int func_ov023_021fb28c(struct Struct_ov023_021fb28c *obj) {
	return (obj->flags & 0x20) != 0;
}
