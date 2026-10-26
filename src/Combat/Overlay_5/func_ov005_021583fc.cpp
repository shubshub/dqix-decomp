#include <globaldefs.h>

#if defined(jpn)
struct Struct_ov005_021583fc { char pad[0x144]; void* ptr; };
#else
struct Struct_ov005_021583fc { char pad[0x150]; void* ptr; };
#endif

// USA: func_ov005_021583fc
extern "C" ARM void func_ov005_021583fc(Struct_ov005_021583fc* obj, char val) {
	char* p = (char*)obj->ptr;
	if (p) {
		p[0x56e] = val;
	}
}
