#include <globaldefs.h>

#if defined(jpn)
#include "Resource/MessageSystem.h"
#define func_020679d4 func_02069294
#else
enum { kCursor = 0x58, kControls = 0x90, kFlag = 0x19cd, kStreamState = 0x40, kValue = 0x954 };
#endif

struct SePlayer;

extern "C" void func_0206b104(void* obj);
#if defined(jpn)
extern "C" void func_0206cbe8(void*, unsigned short, unsigned short*);
#else
struct Ctx0206b2c8;
void InitOrReinitContext0206b2c8(Ctx0206b2c8*, int, void*);
#endif
#if defined(jpn)
void InitBigStructVariant0205c840(char* obj);
#define InitBigStructVariant0205c840(p) InitBigStructVariant0205c840((char*)(p))
#else
void InitBigStructVariant0205c840(char* obj);
#endif
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern char g_sePlayer;

// JPN: func_02069294
// USA: func_020679d4  (semantic: HandleActorStateTransition_020679d4)
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
        func_0206cbe8(self, 0xff16, self->tokenCursor);
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff16, *(void**)(self + kCursor));
#endif
#if defined(jpn)
        InitBigStructVariant0205c840(self->pad50);
        self->b19cd = 1;
        self->stream40 = 0;
#else
        InitBigStructVariant0205c840(self + kControls);
        *(unsigned char*)(self + kFlag) = 1;
        *(int*)(self + kStreamState) = 0;
#endif
        return;
    case 1:
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
    case -2:
#if defined(jpn)
        self->w94c[2] = 1;
#else
        *(int*)(self + kValue) = 1;
#endif
        func_0206b104(self);
#if defined(jpn)
        func_0206cbe8(self, 0xff17, self->tokenCursor);
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff17, *(void**)(self + kCursor));
#endif
#if defined(jpn)
        InitBigStructVariant0205c840(self->pad50);
        self->b19cd = 1;
        self->stream40 = 0;
#else
        InitBigStructVariant0205c840(self + kControls);
        *(unsigned char*)(self + kFlag) = 1;
        *(int*)(self + kStreamState) = 0;
#endif
        return;
    default:
        return;
    }
}

#if defined(jpn)
#undef func_020679d4
#undef InitBigStructVariant0205c840
#endif
