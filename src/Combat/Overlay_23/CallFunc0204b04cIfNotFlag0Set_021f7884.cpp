#include <globaldefs.h>

#if defined(jpn)
enum { BUFFER_OFFSET = 0x24 };
#else
enum { BUFFER_OFFSET = 0x28 };
#endif

extern "C" void Background_FlushMap(void* obj, void* p);

struct Obj28_021f7884 { char pad[0xc]; unsigned char flags; };

// USA: func_ov023_021f7884
ARM void CallFunc0204b04cIfNotFlag0Set_021f7884(struct Obj28_021f7884* obj) {
	if (obj->flags & 1) return;
	Background_FlushMap((char*)obj + BUFFER_OFFSET, NULL);
}
