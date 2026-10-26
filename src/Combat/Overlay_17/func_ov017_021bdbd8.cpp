#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x11c
#else
#define REGION_FIELD 0x33c
#endif

struct Struct_ov017_021bdbd8 { char pad[REGION_FIELD]; int value; };

// USA: func_ov017_021bdbd8
extern "C" ARM int func_ov017_021bdbd8(unsigned char* base) {
	Struct_ov017_021bdbd8* s = (Struct_ov017_021bdbd8*)(base + 0x4000);
	return s->value;
}
