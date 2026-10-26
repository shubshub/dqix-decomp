#include <globaldefs.h>

#if defined(jpn)
#include "Resource/MessageSystem.h"
#define func_020679d4 func_02069294
#else
enum { Enum_020679d4_88 = 0x58, Enum_020679d4_144 = 0x90, Enum_020679d4_6605 = 0x19cd, Enum_020679d4_64 = 0x40, Enum_020679d4_2388 = 0x954 };
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

// JPN: func_02069294
// USA: func_020679d4
#if defined(jpn)
extern "C" ARM void func_020679d4(MessageSystem* self, int state) {
#else
extern "C" ARM void func_020679d4(char* self, int state) {
#endif
    switch (state) {
    case 0:
        func_0206b104(self);
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
#if defined(jpn)
        func_0206cbe8(self, 0xff16, self->unknown_24_);
#else
        func_0206b2c8((Struct_020678bc*)self, 0xff16, *(void**)(self + Enum_020679d4_88));
#endif
#if defined(jpn)
        func_0205c840(self->unknown_50_);
        self->unknown_19cd_ = 1;
        self->unknown_40_ = 0;
#else
        func_0205c840(self + Enum_020679d4_144);
        *(unsigned char*)(self + Enum_020679d4_6605) = 1;
        *(int*)(self + Enum_020679d4_64) = 0;
#endif
        return;
    case 1:
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
    case -2:
#if defined(jpn)
        self->unknown_94c_[2] = 1;
#else
        *(int*)(self + Enum_020679d4_2388) = 1;
#endif
        func_0206b104(self);
#if defined(jpn)
        func_0206cbe8(self, 0xff17, self->unknown_24_);
#else
        func_0206b2c8((Struct_020678bc*)self, 0xff17, *(void**)(self + Enum_020679d4_88));
#endif
#if defined(jpn)
        func_0205c840(self->unknown_50_);
        self->unknown_19cd_ = 1;
        self->unknown_40_ = 0;
#else
        func_0205c840(self + Enum_020679d4_144);
        *(unsigned char*)(self + Enum_020679d4_6605) = 1;
        *(int*)(self + Enum_020679d4_64) = 0;
#endif
        return;
    default:
        return;
    }
}

#if defined(jpn)
#undef func_020679d4
#undef func_0205c840
#endif
