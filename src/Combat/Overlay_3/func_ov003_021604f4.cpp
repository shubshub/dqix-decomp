#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021604f4_904 = 0x270 };
enum { kRegion334 = 0x21c };
#else
enum { Enum_ov003_021604f4_904 = 0x388 };
enum { kRegion334 = 0x334 };
#endif

struct Entry021604f4 {
    char pad0[0x14];
    int field14;
    int field18;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char field22;
};

extern "C" void SpriteContext_DrawSprite(void* a, struct Entry021604f4* entry);

// USA: func_ov003_021604f4
extern "C" ARM void func_ov003_021604f4(char* obj, int valA, int valB, short index, unsigned char flag) {
    struct Entry021604f4* entry = (struct Entry021604f4*)(*(char**)(obj + Enum_ov003_021604f4_904) + index * 0x28);
    entry->field14 = valA << 12;
    entry->field18 = valB << 12;
    entry->field22 = flag;
    SpriteContext_DrawSprite((void*)(obj + kRegion334), entry);
}
