#include <globaldefs.h>

#if defined(jpn)
#include "Resource/MessageSystem.h"
#define func_020678bc func_0206917c
#else
enum { Enum_020678bc_120 = 0x78, Enum_020678bc_76 = 0x4c, Enum_020678bc_88 = 0x58, Enum_020678bc_144 = 0x90, Enum_020678bc_6605 = 0x19cd, Enum_020678bc_64 = 0x40, Enum_020678bc_2388 = 0x954 };
#endif

struct SePlayer;

extern "C" void func_0206b104(void* obj);
#if defined(jpn)
extern "C" void func_0206cbe8(void*, unsigned short, unsigned short*);
#else
struct Struct_020678bc;
extern "C" void func_0206b2c8(Struct_020678bc*, int, void*);
#endif
#if defined(jpn)
extern "C" void func_0205c840(char* obj);
#define func_0205c840(p) func_0205c840((char*)(p))
#else
extern "C" void func_0205c840(char* obj);
#endif
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern char g_sePlayer;

// JPN: func_0206917c
// USA: func_020678bc
#if defined(jpn)
extern "C" ARM void func_020678bc(MessageSystem* self, int state) {
    int idx = self->unknown_78_;
    unsigned short* table = self->unknown_4c_;
#else
extern "C" ARM void func_020678bc(char* self, int state) {
    int idx = *(int*)(self + Enum_020678bc_120);
    unsigned short* table = *(unsigned short**)(self + Enum_020678bc_76);
#endif
    unsigned short value = table[idx];
    int var3 = (value == 0xff06);
    int var4 = (value == 0xff07);

    switch (state) {
    case 0:
        func_0206b104(self);
        if (!var3) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        }
#if defined(jpn)
        func_0206cbe8(self, 0xff14, self->unknown_24_);
#else
        func_0206b2c8((Struct_020678bc*)self, 0xff14, *(void**)(self + Enum_020678bc_88));
#endif
#if defined(jpn)
        func_0205c840(self->unknown_50_);
        self->unknown_19cd_ = 1;
        self->unknown_40_ = 0;
#else
        func_0205c840(self + Enum_020678bc_144);
        *(unsigned char*)(self + Enum_020678bc_6605) = 1;
        *(int*)(self + Enum_020678bc_64) = 0;
#endif
        return;
    case 1:
        if (!var3 && !var4) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        }
    case -2:
#if defined(jpn)
        self->unknown_94c_[2] = 1;
#else
        *(int*)(self + Enum_020678bc_2388) = 1;
#endif
        func_0206b104(self);
#if defined(jpn)
        func_0206cbe8(self, 0xff15, self->unknown_24_);
#else
        func_0206b2c8((Struct_020678bc*)self, 0xff15, *(void**)(self + Enum_020678bc_88));
#endif
#if defined(jpn)
        func_0205c840(self->unknown_50_);
        self->unknown_19cd_ = 1;
        self->unknown_40_ = 0;
#else
        func_0205c840(self + Enum_020678bc_144);
        *(unsigned char*)(self + Enum_020678bc_6605) = 1;
        *(int*)(self + Enum_020678bc_64) = 0;
#endif
        return;
    default:
        return;
    }
}

#if defined(jpn)
#undef func_020678bc
#undef func_0205c840
#endif
