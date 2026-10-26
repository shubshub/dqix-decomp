#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void*);

struct Struct_ov031_0221c3f8_2 { unsigned long long unknown_0_; unsigned long long unknown_8_; int pad; };
struct Struct_ov031_0221c3f8 { unsigned long long unknown_0_; unsigned long long unknown_8_; int flag; };

// USA: func_ov031_0221c3f8
extern "C" ARM void func_ov031_0221c3f8(struct Struct_ov031_0221c3f8* dest) {
	struct Struct_ov031_0221c3f8_2 buf;
	func_ov031_0221ae00(&buf);
	dest->unknown_0_ = buf.unknown_0_;
	dest->unknown_8_ = buf.unknown_8_;
	dest->flag = buf.unknown_0_ != 0;
}
