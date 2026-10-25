#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

struct Struct_02011544;
struct Struct_02038598_4;

extern int g_fileLoadBuffer;
extern int data_02108e00;

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" void func_02075acc(int id, void* p, int a1, int a2);
extern "C" int func_020a9eb8(void* s, int a1, int a2, int a3);
void* GlobalFlags_GetInstance();
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int bits);
void FlagWord_SetBits(unsigned int* word, unsigned int bits);
void SetBrightness(struct GameResources* res, int a, int b);
extern "C" void func_02011544(struct Struct_02011544* arg0);
extern "C" int func_02075ca0();
extern "C" void func_02075cb8();

struct Struct_020aad1c {
    unsigned char unknown_0_;
    int unknown_4_;
};

// USA: func_020aad1c
extern "C" ARM int func_020aad1c(struct Struct_020aad1c* arg0, int arg1, int arg2, int arg3) {
    if (arg0->unknown_0_ == 0) {
        GameState* var0 = GameState::GetInstance();
#if defined(jpn)
        var0->unknown_5cc8_ = 1;
#else
        var0->unknown_5cc8_ = 1;
        GameResources* var1 = GetGameResources();
#endif
        unsigned int var2;
        if (func_02075910(0, &var2, 1, 0) == 0) {
#if defined(jpn)
            SetBrightness(GetGameResources(), -16, 10);
#else
            SetBrightness(var1, -16, 10);
#endif
            func_02011544((struct Struct_02011544*)var0);
            arg0->unknown_0_ = 4;
            return 1;
        } else {
            BackgroundLoader::FreeAllocationsGlobal();
#if !defined(jpn)
            unsigned int* flags = (unsigned int*)GlobalFlags_GetInstance();
            FlagWord_SetBits(flags, 0x2000000);
            SetFlags00(flagv, 0x10);
#endif
            int ptr = (int)&g_fileLoadBuffer + 0x1c + 0x29000;
            if (func_02075910(0x8000, (void*)(s->field4 = ptr), 0x6fe4, 1) == 0) {
#if !defined(jpn)
                flags = (unsigned int*)GlobalFlags_GetInstance();
                FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x2000000);
                ClearFlags00(flagv, 0x10);
#endif
                arg0->unknown_0_ = 4;
                return 1;
            } else {
                arg0->unknown_0_ = 1;
            }
        }
    } else if (arg0->unknown_0_ == 1) {
        if (func_02075ca0() == 0) {
            return 0;
        }
        func_02075cb8();
        data_02108e00 = arg0->unknown_4_;
        if (func_020a9eb8(arg0, arg1, arg2, arg3) == 0) {
#if !defined(jpn)
            FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x2000000);
            ClearFlags00(GetGameResources(), 0x10);
#endif
            arg0->unknown_0_ = 4;
            return 1;
        } else {
            data_02108e00 = 0;
            func_02075acc(arg3 ? 0x8010 : 0x10, (void*)(arg0->unknown_4_ + 0x10), 0x6fe4, 1);
            arg0->unknown_0_ = 2;
        }
    } else if (arg0->unknown_0_ == 2) {
        if (func_02075ca0() == 0) {
            return 0;
        }
        func_02075cb8();
        if (arg3 != 0) {
#if !defined(jpn)
            FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x2000000);
            ClearFlags00(GetGameResources(), 0x10);
#endif
            arg0->unknown_0_ = 4;
            return 1;
        } else {
            func_02075acc(0x8010, (void*)(arg0->unknown_4_ + 0x10), 0x6fe4, 1);
            arg0->unknown_0_ = 3;
        }
    } else if (arg0->unknown_0_ == 3) {
        if (func_02075ca0() == 0) {
            return 0;
        }
        func_02075cb8();
#if !defined(jpn)
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x2000000);
        ClearFlags00(GetGameResources(), 0x10);
#endif
        arg0->unknown_0_ = 4;
        return 1;
    }
    return 0;
}
