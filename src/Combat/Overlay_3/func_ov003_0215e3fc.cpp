#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
enum { Enum_ov003_0215e3fc_948 = 0x3cc };
#else
enum { Enum_ov003_0215e3fc_948 = 0x3b4 };
#endif

extern "C" int func_0209ca2c(void* obj);
extern "C" void* func_020e2ff8(void);

extern "C" void func_0205e944(void* data, int flag);
extern "C" void func_ov003_0215c800(void* self);

extern int g_bgmPlayer;
extern int g_sePlayer;

struct Struct_ov003_0215c924_2 {
    char pad0[Enum_ov003_0215e3fc_948];
    int* unknown_3b4_;
    unsigned char unknown_3b8_;
    char pad1[0x3bc - 0x3b9];
    unsigned char unknown_3bc_;
    char pad2[0x3ec - 0x3bd];
    unsigned char unknown_3ec_;
};

// USA: func_ov003_0215e3fc
extern "C" ARM void func_ov003_0215e3fc(struct Struct_ov003_0215c924_2* self) {
    if (func_0209ca2c(&g_bgmPlayer) != 0) {
        return;
    }
    if (self->unknown_3ec_ != 0) {
        return;
    }

    func_0205e944(&g_sePlayer, 0x7f);
    func_020e2ff8();

    if (self->unknown_3b4_ != NULL) {
        int x = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(x))->FreeAllocations();
        int i;
#if defined(jpn)
        for (i = 0; i < 4; i++) {
#else
        for (i = 0; i < 3; i++) {
#endif
            ((BackgroundLoader*)(x))->RemoveTask((int)(self->unknown_3b4_[i]));
            self->unknown_3b4_[i] = -1;
        }
    }

    func_ov003_0215c800(self);
    self->unknown_3bc_ = 5;
    self->unknown_3b8_ = 0;
}
