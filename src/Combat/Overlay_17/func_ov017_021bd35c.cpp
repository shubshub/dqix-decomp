#include <globaldefs.h>

struct Struct_ov017_021bd35c { unsigned short h0, h2, h4, h6, h8; };
struct Struct_ov017_021bd35c_2 { unsigned char pad[
#if defined(jpn)
0x14c
#else
0x150
#endif
]; unsigned short unknown_150_, unknown_152_, unknown_154_, unknown_156_, d8; };

// USA: func_ov017_021bd35c
extern "C" ARM void func_ov017_021bd35c(Struct_ov017_021bd35c_2* obj, Struct_ov017_021bd35c* src) {
	obj->unknown_150_ = src->h0;
	obj->unknown_152_ = src->h2;
	obj->unknown_154_ = src->h4;
	obj->unknown_156_ = src->h6;
	obj->d8 = src->h8;
}
