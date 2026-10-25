#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216af14_4800 = 0x1150 };
enum { Enum_ov003_0216af14_4804 = 0x1154 };
enum { Enum_ov003_0216af14_4820 = 0x1164 };
enum { Enum_ov003_0216af14_5098 = 0x127a };
#else
enum { Enum_ov003_0216af14_4800 = 0x12c0 };
enum { Enum_ov003_0216af14_4804 = 0x12c4 };
enum { Enum_ov003_0216af14_4820 = 0x12d4 };
enum { Enum_ov003_0216af14_5098 = 0x13ea };
#endif
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_ov003_0216af14_2 {
    unsigned char unknown_0_[0x4];
    short unknown_4_;
    unsigned char unknown_6_[0x10 - 0x6];
    int unknown_10_;
    unsigned char unknown_14_[Enum_ov003_0216af14_4800 - 0x14];
    void* unknown_12c0_;
    unsigned char unknown_12c4_[Enum_ov003_0216af14_4820 - Enum_ov003_0216af14_4804];
    SafeAllocator unknown_12d4_;
    unsigned char unknown_12e8_[Enum_ov003_0216af14_5098 - Enum_ov003_0216af14_4820 - sizeof(SafeAllocator)];
    unsigned char unknown_13ea_;
    unsigned char unknown_13eb_;
    unsigned char unknown_13ec_;
};

struct Pair0216af14 { unsigned int a; unsigned int b; };
extern struct Pair0216af14 __ptmf_null;

struct Struct_ov003_0216af14 { unsigned int unknown_0_; unsigned int unknown_4_; };
struct Struct_ov003_0217f578 { struct Struct_ov003_0216af14 unknown_0_[8]; };
extern struct Struct_ov003_0217f578 data_ov003_0217f578;

extern AllocatorUnion g_mainAllocator;

extern "C" int func_ov003_0215c924(void* p, int scale);
extern "C" void func_ov003_0215c800(void* p);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void ResetGlobalsAndReinit_0216d818(char* obj);
extern "C" void func_ov003_0216d84c(void* p);
extern "C" int Window_Update(void* p, unsigned int tick);

// USA: func_ov003_0216af14
extern "C" ARM int func_ov003_0216af14(Scene_0216af14* scene) {
    GameState* gs = GameState::GetInstance();
    if (scene->flags & 2) {
        if (scene->state == 3) {
            if (func_ov003_0215c924(scene->field_0x14, 1) != 1) return 1;
            func_ov003_0215c800(scene->field_0x14);
            void* p = scene->allocator.GetSignedAllocator();
            if (p != 0) {
                scene->allocator.Destroy();
                AllocatorUnion_Free(&g_mainAllocator, p);
            }
        }
        func_ov003_0216d818((char*)arg0);
        return 0;
    }
    if (arg0->unknown_13ea_ != 0) {
        func_ov003_0216d84c(arg0);
        if (arg0->unknown_13ec_ & 1) return 1;
    }
    unsigned int tick = gs->GetTickCount();
    if (scene->field_0x12c0 != 0 && scene->state == 2) {
        scene->field_0x10 = Window_Update(scene->field_0x12c0, tick);
    }

    struct Table0216af14 buf;
    buf = data_ov003_0217f578;
    unsigned int locator = __ptmf_null.b;
    unsigned int fn = __ptmf_null.a;
    buf.entries[7].locator = locator;
    buf.entries[7].fn = fn;

    if (var3.unknown_0_[arg0->unknown_4_].unknown_0_ == 0) return 0;
    struct Struct_ov003_0216af14* var6 = &var3.unknown_0_[arg0->unknown_4_];
    void* var7 = (char*)arg0 + ((int)var6->unknown_4_ >> 1);
    void* var8;
    if (var6->unknown_4_ & 1) {
        var8 = *(void**)((char*)*(void**)var7 + var6->unknown_0_);
    } else {
        var8 = (void*)var6->unknown_0_;
    }
    ((void(*)(void*))var8)(var7);
    return 1;
}
