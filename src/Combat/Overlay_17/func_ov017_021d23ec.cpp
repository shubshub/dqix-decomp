#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov017_021d23ec_2 { unsigned char pad[4]; unsigned short h4; };
struct DstObj_021d23ec { unsigned char pad[0x24]; unsigned short unknown_24_; };

// USA: func_ov017_021d23ec
extern "C" ARM void func_ov017_021d23ec(int unused0, Struct_ov017_021d23ec_2* src, int arg2, GameResources* ov) {
	DstObj_021d23ec* dst = (DstObj_021d23ec*)ov->unknown_ptr_array_3700[3];
	dst->unknown_24_ = src->h4;
}
