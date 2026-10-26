#include <globaldefs.h>

struct Struct_ov017_021b354c { unsigned char pad[0x56e]; unsigned char unknown_56e_; };
#if defined(jpn)
#define SUB_POINTER_OFFSET 0x144
#else
#define SUB_POINTER_OFFSET 0x150
#endif
struct Struct_ov017_021b3444 { unsigned char pad[SUB_POINTER_OFFSET]; Struct_ov017_021b354c* sub; };

// USA: func_ov017_021b354c
extern "C" ARM unsigned char func_ov017_021b354c(Struct_ov017_021b3444* obj) {
	Struct_ov017_021b354c* sub = obj->sub;
	if (sub) return sub->unknown_56e_;
	return 0;
}
