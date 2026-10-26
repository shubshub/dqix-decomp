#include <globaldefs.h>
#if defined(jpn)
enum { kRegion98 = 0xb0 };
enum { Enum_ov003_0215ddc0_56 = 0x50 };
enum { Enum_ov003_0215ddc0_58 = 0x52 };
enum { Enum_ov003_0215ddc0_60 = 0x54 };
enum { Enum_ov003_0215ddc0_62 = 0x56 };
enum { Enum_ov003_0215ddc0_64 = 0x58 };
enum { Enum_ov003_0215ddc0_66 = 0x5a };
enum { Enum_ov003_0215ddc0_68 = 0x5c };
enum { Enum_ov003_0215ddc0_70 = 0x5e };
enum { Enum_ov003_0215ddc0_335 = 0x167 };
enum { Enum_ov003_0215ddc0_329 = 0x161 };
enum { Enum_ov003_0215ddc0_333 = 0x165 };
enum { kRegion7c = 0x94 };
enum { Enum_ov003_0215ddc0_2400 = 0x800 };
#else
enum { kRegion98 = 0x98 };
enum { Enum_ov003_0215ddc0_56 = 0x38 };
enum { Enum_ov003_0215ddc0_58 = 0x3a };
enum { Enum_ov003_0215ddc0_60 = 0x3c };
enum { Enum_ov003_0215ddc0_62 = 0x3e };
enum { Enum_ov003_0215ddc0_64 = 0x40 };
enum { Enum_ov003_0215ddc0_66 = 0x42 };
enum { Enum_ov003_0215ddc0_68 = 0x44 };
enum { Enum_ov003_0215ddc0_70 = 0x46 };
enum { Enum_ov003_0215ddc0_335 = 0x14f };
enum { Enum_ov003_0215ddc0_329 = 0x149 };
enum { Enum_ov003_0215ddc0_333 = 0x14d };
enum { kRegion7c = 0x7c };
enum { Enum_ov003_0215ddc0_2400 = 0x960 };
#endif

#if defined(jpn)
enum { Enum_ov003_0215ddc0_2 = 4 };
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#else
enum { Enum_ov003_0215ddc0_2 = 2 };
#endif
#include "std_library_functions.h"

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov003_0215de6c(char* base, void* buf);
#if !defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

// USA: func_ov003_0215ddc0
extern "C" ARM void func_ov003_0215ddc0(char* base) {
    func_0205de24((struct Struct0205de24*)(base + kRegion98), 0, 2);

    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_56) = 0xb;
    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_58) = 2;
    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_60) = 0x14;
    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_62) = 0;
    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_64) = 0x10;
    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_66) = Enum_ov003_0215ddc0_2;
    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_68) = 8;
    *(unsigned short*)(base + 0x100 + Enum_ov003_0215ddc0_70) = 8;

    *(unsigned char*)(base + Enum_ov003_0215ddc0_335) = 8;
    *(unsigned char*)(base + Enum_ov003_0215ddc0_329) = 0;
    *(unsigned char*)(base + Enum_ov003_0215ddc0_333) = 1;

    memset(*(void**)(base + kRegion7c), 0, Enum_ov003_0215ddc0_2400);
    func_ov003_0215de6c(base, *(void**)(base + kRegion7c));

#if defined(jpn)
    Window_OpenPane(base + kRegion98, *(void**)(base + kRegion7c), 0, 0, 0, 1, 0);
#else
    Window_OpenPane(base + kRegion98, *(void**)(base + kRegion7c), 0, 0, 0, 1, 0, 0);
#endif
}
