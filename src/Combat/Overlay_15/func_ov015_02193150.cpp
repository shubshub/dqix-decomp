#include <globaldefs.h>

struct Struct_ov015_02192700_10 { char pad[0x5c]; short unknown_5c_; short unknown_5e_; short f60; };

// USA: func_ov015_02193150
extern "C" ARM void func_ov015_02193150(struct Struct_ov015_02192700_10* s, int v) {
	s->f60 = v + s->unknown_5c_;
}
