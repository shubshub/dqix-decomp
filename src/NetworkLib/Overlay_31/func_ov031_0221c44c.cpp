#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void*);

struct Struct_ov031_0221c44c { unsigned long long unknown_0_; unsigned long long unknown_8_; int pad; };

// USA: func_ov031_0221c44c
extern "C" ARM int func_ov031_0221c44c(void) {
	struct Struct_ov031_0221c44c buf;
	func_ov031_0221ae00(&buf);
	if (buf.unknown_8_ == 0) {
		if (buf.unknown_0_ == 0) {
			return 1;
		}
	}
	return 0;
}
