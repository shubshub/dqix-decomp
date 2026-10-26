#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021e6a90_881 = 0x341, Enum_ov023_021e6a90_172 = 0x90, Enum_ov023_021e6a90_868 = 0x33c, Enum_ov023_021e6a90_860 = 0x334 };
#else
enum { Enum_ov023_021e6a90_881 = 0x371, Enum_ov023_021e6a90_172 = 0xac, Enum_ov023_021e6a90_868 = 0x364, Enum_ov023_021e6a90_860 = 0x35c };
#endif

struct Struct_0205d81c;

extern "C" void* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void SpriteContext_DrawSprite(void* a, void* b);

// USA: func_ov023_021e6a90
extern "C" ARM void func_ov023_021e6a90(void* a) {
	if (((unsigned char*)a)[0x1000 + Enum_ov023_021e6a90_881] == 6) return;
	void* e = func_0205d81c((struct Struct_0205d81c*)((char*)a + Enum_ov023_021e6a90_172), 0x11);
	if (!e) return;
	short ea = *(short*)((char*)e + 0xac);
	short eb = *(short*)((char*)e + 0xae);
	unsigned char* s = *(unsigned char**)((char*)a + 0x1000 + Enum_ov023_021e6a90_868);
	*(int*)(s + 0x1f4) = ((short)(ea << 3) + 0xa) << 0xc;
	*(int*)(s + 0x1f8) = ((short)(eb << 3) + 3) << 0xc;
	void* var4 = *(void**)((char*)a + 0x1000 + Enum_ov023_021e6a90_860);
	SpriteContext_DrawSprite(var4, s + 0x1e0);
}
