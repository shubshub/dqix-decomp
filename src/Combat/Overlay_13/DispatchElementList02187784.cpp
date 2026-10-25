#include <globaldefs.h>

extern "C" void SpriteContext_DrawSprite(void* obj, void* entry);

struct Entry02187784 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x22 - 0x1c];
    unsigned char f22;
    char pad2[0x25 - 0x23];
    unsigned char f25;
    unsigned char f26;
};

// USA: func_ov013_02187784  (semantic: DispatchElementList02187784)
extern "C" ARM void func_ov013_02187784(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    if (*(void**)(o + 0x48) == 0) return;
    if (o[0x69] & 1) return;
    signed char slot = *(signed char*)(o + 0x6a);
    if (slot < 0) return;

    char* base = *(char**)(o + 0x4c);
    Entry02187784* entry = (Entry02187784*)(base + slot * 0x28);

    for (int i = 0; i < 10; i++) {
        short* arr1 = *(short**)(o + 0x50);
        short a = arr1[i];
        if (a >= 0) {
            short* arr2 = *(short**)(o + 0x54);
            short b = arr2[i];
            if (b >= 0) {
                entry->f14 = a << 12;
                entry->f18 = b << 12;
                entry->f22 = i + 0x20;
                entry->f26 = 0;
                unsigned char* arr3 = *(unsigned char**)(o + 0x58);
                entry->f25 = arr3[i];
                SpriteContext_DrawSprite(*(void**)(o + 0x48), entry);
            }
        }
    }
}
