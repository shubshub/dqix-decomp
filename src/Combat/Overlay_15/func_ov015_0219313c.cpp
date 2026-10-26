#include <globaldefs.h>

struct Struct_ov015_02192700_9 { char pad[0x5c]; short unknown_5c_; short unknown_5e_; short f60; };

// USA: func_ov015_0219313c
extern "C" ARM void func_ov015_0219313c(Struct_ov015_02192700_9* s, int a, int b) {
	s->unknown_5c_ = a;
	s->f60 = s->unknown_5c_;
	s->unknown_5e_ = b;
}
