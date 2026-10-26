#include <globaldefs.h>

#if defined(jpn)
enum { BUFFER_OFFSET = 0x24 };
#else
enum { BUFFER_OFFSET = 0x28 };
#endif

struct BackgroundGraphics;
extern "C" void Background_ClearMap(struct BackgroundGraphics* obj, void* p);

struct Struct_ov023_021f7864 { char pad[0xc]; unsigned char flags; };

// USA: func_ov023_021f7864
extern "C" ARM void func_ov023_021f7864(struct Struct_ov023_021f7864* obj) {
	if (obj->flags & 1) return;
	Background_ClearMap((struct BackgroundGraphics*)((char*)obj + BUFFER_OFFSET), NULL);
}
