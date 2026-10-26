#include <globaldefs.h>

#if defined(jpn)
#define POINTER_OFFSET 0x16c
#else
#define POINTER_OFFSET 0x41c
#endif
struct Struct_ov017_02195760 { char pad[POINTER_OFFSET]; unsigned char* p; };

// USA: func_ov017_02195760
extern "C" ARM int func_ov017_02195760(unsigned char* base) {
	Struct_ov017_02195760* s = (Struct_ov017_02195760*)(base + 0x4000);
	return s->p[0] == 0;
}
