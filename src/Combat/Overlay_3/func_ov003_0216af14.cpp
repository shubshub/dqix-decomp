#include <globaldefs.h>
#if defined(jpn)
enum { kRegion12c0 = 0x1150 };
enum { Enum_ov003_0216af14_4804 = 0x1154 };
enum { Enum_ov003_0216af14_4820 = 0x1164 };
enum { Enum_ov003_0216af14_5098 = 0x127a };
#else
enum { kRegion12c0 = 0x12c0 };
enum { Enum_ov003_0216af14_4804 = 0x12c4 };
enum { Enum_ov003_0216af14_4820 = 0x12d4 };
enum { Enum_ov003_0216af14_5098 = 0x13ea };
#endif
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_ov003_0216af14_2 {
    unsigned char pad0[0x4];
    short state;
    unsigned char pad6[0x10 - 0x6];
    int field_0x10;
    unsigned char unknown_14_[kRegion12c0 - 0x14];
    void* field_0x12c0;
    unsigned char unknown_12c4_[Enum_ov003_0216af14_4820 - Enum_ov003_0216af14_4804];
    SafeAllocator allocator;
    unsigned char unknown_12e8_[Enum_ov003_0216af14_5098 - Enum_ov003_0216af14_4820 - sizeof(SafeAllocator)];
    unsigned char unknown_13ea_;
    unsigned char unknown_13eb_;
    unsigned char flags;
};

struct Struct_020e6d5c_16 { unsigned int a; unsigned int b; };
extern struct Struct_020e6d5c_16 __ptmf_null;

struct Struct_ov003_0216af14 { unsigned int fn; unsigned int unknown_4_; };
struct Struct_ov003_0217f578 { struct Struct_ov003_0216af14 entries[8]; };
extern struct Struct_ov003_0217f578 data_ov003_0217f578;

extern AllocatorUnion g_mainAllocator;

extern "C" int func_ov003_0215c924(void* p, int scale);
extern "C" void func_ov003_0215c800(void* p);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_ov003_0216d818(char* obj);
extern "C" void func_ov003_0216d84c(void* p);
extern "C" int Window_Update(void* p, unsigned int tick);

// USA: func_ov003_0216af14
extern "C" ARM int func_ov003_0216af14(Struct_ov003_0216af14_2* scene) {
    GameState* gs = GameState::GetInstance();
    if (scene->flags & 2) {
        if (scene->state == 3) {
            if (func_ov003_0215c924(scene->unknown_14_, 1) != 1) return 1;
            func_ov003_0215c800(scene->unknown_14_);
            void* p = scene->allocator.GetSignedAllocator();
            if (p != 0) {
                scene->allocator.Destroy();
                AllocatorUnion_Free(&g_mainAllocator, p);
            }
        }
        func_ov003_0216d818((char*)scene);
        return 0;
    }
    if (scene->unknown_13ea_ != 0) {
        func_ov003_0216d84c(scene);
        if (scene->flags & 1) return 1;
    }
    unsigned int tick = gs->GetTickCount();
    if (scene->field_0x12c0 != 0 && scene->state == 2) {
        scene->field_0x10 = Window_Update(scene->field_0x12c0, tick);
    }

    struct Struct_ov003_0217f578 buf;
    buf = data_ov003_0217f578;
    unsigned int var4 = __ptmf_null.b;
    unsigned int fn = __ptmf_null.a;
    buf.entries[7].unknown_4_ = var4;
    buf.entries[7].fn = fn;

    if (buf.entries[scene->state].fn == 0) return 0;
    struct Struct_ov003_0216af14* d = &buf.entries[scene->state];
    void* base = (char*)scene + ((int)d->unknown_4_ >> 1);
    void* callback;
    if (d->unknown_4_ & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    ((void(*)(void*))callback)(base);
    return 1;
}
