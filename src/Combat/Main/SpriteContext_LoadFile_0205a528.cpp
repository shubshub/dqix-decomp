#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* dst, int size);
extern "C" int memcmp(const void* a, const void* b, unsigned int length); // memcmp
extern "C" int SpriteContext_LoadCells(void* context, void* file, int size, int allocator);
extern "C" int SpriteContext_LoadAnimations(void* context, void* file, int size, int allocator);
struct Obj0205aaf8;
extern "C" int func_0205aaf8(Obj0205aaf8*, void*, int);
extern "C" int SpriteContext_LoadPalette(void* context, void* file, int size);

extern char SpriteContext_ncerMagic[];
extern char SpriteContext_nanrMagic[];
extern char SpriteContext_ncgrMagic[];
extern char SpriteContext_nclrMagic[];

// Main, originally func_0205a528 (USA 0x0205a528, EUR 0x0205a538, JPN 0x0205b8c4)
extern "C" ARM int SpriteContext_LoadFile(void* context, void* file, int size, int allocator) {
    char magic[5];

    __clear(magic, 5);
    memcpy(magic, file, 4);

    if (memcmp(magic, SpriteContext_ncerMagic, 4) == 0 && SpriteContext_LoadCells(context, file, size, allocator)) {
        return 1;
    } else if (memcmp(magic, SpriteContext_nanrMagic, 4) == 0) {
        if (SpriteContext_LoadAnimations(context, file, size, allocator)) {
            return 1;
        }
    } else if (memcmp(magic, SpriteContext_ncgrMagic, 4) == 0) {
        if (func_0205aaf8((Obj0205aaf8*)context, file, size)) {
            return 1;
        }
    } else if (memcmp(magic, SpriteContext_nclrMagic, 4) == 0) {
        if (SpriteContext_LoadPalette(context, file, size)) {
            return 1;
        }
    }
    return 0;
}
