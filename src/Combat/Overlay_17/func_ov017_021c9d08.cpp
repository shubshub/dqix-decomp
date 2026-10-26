#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov017_021c9d08_3764 = 0xe30 };
#else
enum { Enum_ov017_021c9d08_3764 = 0xeb4 };
#endif

extern "C" void* func_ov017_021b8468(void*);

struct Struct_ov017_021c9d08 {
    unsigned char unknown0[4];
    unsigned char value;
};

struct Struct_ov017_021c9d08_2 {
    unsigned char unknown0[Enum_ov017_021c9d08_3764];
    unsigned char unknown_eb4_;
};

// USA: func_ov017_021c9d08
extern "C" ARM void func_ov017_021c9d08(void* unused0, void* src, void* arg2, void* obj) {
	Struct_ov017_021c9d08_2* dst = (Struct_ov017_021c9d08_2*)func_ov017_021b8468(((GameResources*)obj)->unknown_ptr_3718);
	if (dst) {
		dst->unknown_eb4_ = ((Struct_ov017_021c9d08*)src)->value;
	}
}
