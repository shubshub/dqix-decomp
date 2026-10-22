#include <globaldefs.h>

#if defined(jpn)
#include "Resource/MessageSystem.h"
#define func_020678bc func_0206917c
#else
enum { kIndex = 0x78, kBuffer = 0x4c, kCursor = 0x58, kControls = 0x90, kFlag = 0x19cd, kStreamState = 0x40, kValue = 0x954 };
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

// JPN: func_0206917c
// USA: func_020678bc  (semantic: DispatchStateChange_020678bc)
#if defined(jpn)
extern "C" ARM void func_020678bc(MessageSystem* self, int state) {
    int idx = self->tokenIndex;
    unsigned short* table = self->firstLineBuffer;
#else
extern "C" ARM void func_020678bc(char* self, int state) {
    int idx = *(int*)(self + kIndex);
    unsigned short* table = *(unsigned short**)(self + kBuffer);
#endif
    unsigned short value = table[idx];
    int isFF06 = (value == 0xff06);
    int isFF07 = (value == 0xff07);

    switch (state) {
    case 0:
        func_0206b104(self);
        if (!isFF06) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        }
#if defined(jpn)
        func_0206cbe8(self, 0xff14, self->tokenCursor);
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff14, *(void**)(self + kCursor));
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
        if (!isFF06 && !isFF07) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        }
    case -2:
#if defined(jpn)
        self->w94c[2] = 1;
#else
        *(int*)(self + kValue) = 1;
#endif
        func_0206b104(self);
#if defined(jpn)
        func_0206cbe8(self, 0xff15, self->tokenCursor);
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff15, *(void**)(self + kCursor));
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
#undef func_020678bc
#undef InitBigStructVariant0205c840
#endif
