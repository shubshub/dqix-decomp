#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021e6a14_881 = 0x341, Enum_ov023_021e6a14_172 = 0x90, Enum_ov023_021e6a14_868 = 0x33c, Enum_ov023_021e6a14_860 = 0x334 };
#else
enum { Enum_ov023_021e6a14_881 = 0x371, Enum_ov023_021e6a14_172 = 0xac, Enum_ov023_021e6a14_868 = 0x364, Enum_ov023_021e6a14_860 = 0x35c };
#endif

struct Struct_0205d81c;

extern "C" void* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void SpriteContext_DrawSprite(void* a, void* b);

// USA: func_ov023_021e6a14
extern "C" ARM void func_ov023_021e6a14(void* a) {
    unsigned char v = ((unsigned char*)a)[0x1000 + Enum_ov023_021e6a14_881];
    if (v != 7 && v != 8 && v != 9) return;
    void* e = func_0205d81c((struct Struct_0205d81c*)((char*)a + Enum_ov023_021e6a14_172), 0x10);
    if (!e) return;
    short ea = *(short*)((char*)e + 0xac);
    short eb = *(short*)((char*)e + 0xae);
    unsigned char* s = *(unsigned char**)((char*)a + 0x1000 + Enum_ov023_021e6a14_868);
    *(int*)(s + 0x1cc) = ((short)(ea << 3) + 5) << 0xc;
    *(int*)(s + 0x1d0) = ((short)(eb << 3) + 3) << 0xc;
    void* var5 = *(void**)((char*)a + 0x1000 + Enum_ov023_021e6a14_860);
    SpriteContext_DrawSprite(var5, s + 0x1b8);
}
