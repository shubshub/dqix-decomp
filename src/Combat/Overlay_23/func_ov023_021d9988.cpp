#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov023_021d9988 {
	char pad[0x124];
	char buf[4];
	unsigned char unknown_128_;
};

// USA: func_ov023_021d9988
extern "C" ARM void func_ov023_021d9988(struct Struct_ov023_021d9988 *obj, void *src, unsigned int len) {
	memcpy(obj->buf, src, len);
	obj->unknown_128_ = (unsigned char)len;
}
