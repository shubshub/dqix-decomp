#include <globaldefs.h>

extern "C" void SpriteContext_DrawSprite(void* obj, void* entry);

// USA: func_ov002_02154bcc
ARM void SetEntryFields02154bcc(int a, int b, void* obj, int idx, unsigned char arg5, unsigned char arg6) {
    int base = *(int*)((char*)obj + 0x40);
    char* entry = NULL;
    if (base != 0) {
        unsigned short lim = *(unsigned short*)((char*)obj + 0x4e);
        if ((unsigned int)idx < lim) {
            entry = (char*)base + idx * 0x28;
        }
    }
    if (entry == NULL) {
        return;
    }
    *(int*)(entry + 0x14) = a << 12;
    *(int*)(entry + 0x18) = b << 12;
    if (arg6 != 0xff) {
        entry[0x25] = arg6;
    }
    if (arg5 != 0xff) {
        entry[0x22] = arg5;
    }
    SpriteContext_DrawSprite(obj, entry);
}
