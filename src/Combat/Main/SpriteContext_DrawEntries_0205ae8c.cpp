#include <globaldefs.h>

extern "C" void func_0205addc(void* obj, unsigned char idx);

struct Struct_0205ae8c {
    char pad[4];
    unsigned short count;
};

// Main, originally func_0205ae8c (USA 0x0205ae8c, EUR 0x0205ae9c, JPN 0x0205c228)
extern "C" ARM void SpriteContext_DrawEntries(void* obj) {
    unsigned short count;
    struct Struct_0205ae8c* h;
    unsigned short i;

    h = *(struct Struct_0205ae8c**)((char*)obj + 0x3c);
    if (h == 0) {
        return;
    }
    count = h->count;
    i = 0;
    while (i < count) {
        func_0205addc(obj, (unsigned char)i);
        i++;
    }
}
