#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215b8a0_2400 = 0x800 };
#else
enum { Enum_ov003_0215b8a0_2400 = 0x960 };
#endif

#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#endif
#include "std_library_functions.h"

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

extern "C" void func_ov003_0215b964(void* self, void* p, int flag);
#if !defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov003_0215b8a0
extern "C" ARM void func_ov003_0215b8a0(unsigned char* self) {
    func_0205de24((struct Struct0205de24*)(self + 0xf4), 0, 2);
    short mul = self[0x590];
    int step = (mul * (short)14 + 31) / 8;
    *(short*)(self + 0x100 + 0x94) = 14;
    *(short*)(self + 0x100 + 0x96) = step;
    *(short*)(self + 0x100 + 0x98) = 1;
    *(short*)(self + 0x100 + 0x9a) = 2;
    *(short*)(self + 0x100 + 0x9c) = 0xc;
    *(short*)(self + 0x100 + 0x9e) = 8;
    *(short*)(self + 0x100 + 0xa0) = 0xa;
    *(short*)(self + 0x100 + 0xa2) = 14;
    self[0x1a5] = 2;
    self[0x1a9] = 1;
    void* p = *(void**)(self + 0x7c);
    memset(p, 0, Enum_ov003_0215b8a0_2400);
    func_ov003_0215b964(self, *(void**)(self + 0x7c), 0);
#if defined(jpn)
    Window_OpenPane(self + 0xf4, *(void**)(self + 0x7c), 0, 1, 0, 1, 0);
#else
    Window_OpenPane(self + 0xf4, *(void**)(self + 0x7c), 0, 1, 0, 0, 0, 0);
#endif
}
