#include <globaldefs.h>

#if defined(jpn)
struct Struct_ov017_02195748 { char pad[0x16c]; unsigned char* p; };
#else
struct Struct_ov017_02195748 { char pad[0x41c]; unsigned char* p; };
#endif

// USA: func_ov017_02195748
extern "C" ARM void func_ov017_02195748(unsigned char* base) {
	Struct_ov017_02195748* s = (Struct_ov017_02195748*)(base + 0x4000);
	unsigned char* p = s->p;
	p[0] = 0;
	p[1] = 0;
}
