#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern char* data_ov031_0224e53c;

struct Struct_ov031_0220d61c { int x; int len; int total; int h; };

#define REG0220D61C(off) (*(unsigned int*)((data_ov031_0224e53c + 0x2000) + (off)))

// USA: func_ov031_0220d61c
extern "C" ARM void func_ov031_0220d61c(Struct_ov031_0220d61c* r, int flag) {
	if (r == NULL) {
		REG0220D61C(0x26c) = 3;
		REG0220D61C(0x270) = 0;
		REG0220D61C(0x274) = 0;
		REG0220D61C(0x278) = 0;
	} else {
		REG0220D61C(0x26c) = r->x & 3;
		if ((((4 - (r->len & 3)) & 3) + 0xc) > (unsigned int)r->total) {
			REG0220D61C(0x270) = 0;
			REG0220D61C(0x274) = 0;
		} else {
			REG0220D61C(0x270) = (r->len + 3) & ~3;
			REG0220D61C(0x274) = r->total - ((4 - (r->len & 3)) & 3);
			VectorizedMemset((void*)REG0220D61C(0x270), 0, REG0220D61C(0x274));
		}
		REG0220D61C(0x278) = r->h;
	}
	REG0220D61C(0x27c) = flag;
}
