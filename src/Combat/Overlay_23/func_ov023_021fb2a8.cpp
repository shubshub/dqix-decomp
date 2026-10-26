#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021fb2a8_74 = 0x4e };
#else
enum { Enum_ov023_021fb2a8_74 = 0x4a };
#endif

struct Struct_ov023_021fb2a8 { char pad[Enum_ov023_021fb2a8_74]; unsigned char unknown_4a_; };

// USA: func_ov023_021fb2a8
extern "C" ARM void func_ov023_021fb2a8(struct Struct_ov023_021fb2a8 *obj, unsigned char v) {
	obj->unknown_4a_ = v;
}
