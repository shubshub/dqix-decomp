#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0207fcb8_44 = 0x20 };
#else
enum { Enum_0207fcb8_44 = 0x2c };
#endif

struct BackgroundGraphics;

extern "C" void Background_ClearMap(struct BackgroundGraphics* obj, void* p);

struct Struct_0207fcb8 {
    char pad0[Enum_0207fcb8_44];
    char* entries;
    char unknown_30_[8];
    unsigned char count;
};

// USA: func_0207fcb8
extern "C" ARM void func_0207fcb8(struct Struct_0207fcb8* obj) {
    unsigned char i;
    if (obj->entries != NULL) {
        for (i = 0; i < obj->count; i++) {
            Background_ClearMap((struct BackgroundGraphics*)(obj->entries + i * 0x20), NULL);
        }
    }
}
