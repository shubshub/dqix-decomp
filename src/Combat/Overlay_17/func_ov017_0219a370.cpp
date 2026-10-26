#include <globaldefs.h>

#if defined(jpn)
struct Struct_ov017_0219a370 { char pad[0xe58]; int count; };
#else
struct Struct_ov017_0219a370 { char pad[0x78]; int count; };
#endif

// USA: func_ov017_0219a370
extern "C" ARM int func_ov017_0219a370(unsigned char* base) {
#if defined(jpn)
	Struct_ov017_0219a370* s = (Struct_ov017_0219a370*)(base + 0x3000);
#else
	Struct_ov017_0219a370* s = (Struct_ov017_0219a370*)(base + 0x4000);
#endif
	return s->count >= 4;
}
