#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02097ec8_2404 = 0x8cc };
#else
enum { Enum_02097ec8_2404 = 0x964 };
#endif
#include "Resource/GameResources.h"

struct Struct_02054280;
struct Struct_02097ec8;
struct ZoneState { unsigned short zoneId; unsigned short unknown_2_; };
struct Struct_02097ec8_2 {
    char pad0[0x1b3c];
    unsigned int progress;
    char unknown_1b40_[0x1b58 - 0x1b40];
    Struct_02054280* slots;
    Struct_02097ec8* work;
    unsigned char unknown_1b60_;
};
extern "C" ZoneState* Zone3D_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" void func_0201bd3c(ZoneState*, int, int);
extern "C" void func_02082828(Struct_02097ec8*);
extern "C" void func_020542b4(Struct_02054280*, SafeAllocator*, char*);
extern "C" int func_020981e4(int, int);
extern "C" int func_02098240(int, int);
extern "C" int func_02098210(int, int);
extern "C" void func_02054280(Struct_02054280*);

static inline SafeAllocator& GetResourceAllocator(GameResources* resources, int index) {
    return resources->allocator_array_1a0[index];
}

static inline char& inline_0203d028_5(GameResources* resources, int offset) {
    return resources->vramStates_[offset];
}

// USA: func_02097ec8
extern "C" ARM void func_02097ec8(Struct_02097ec8_2* state) {
    ZoneState* zone = Zone3D_GetInstance();
    int zoneId = zone->zoneId;
    int var2 = zone->unknown_2_;
    if (!func_020981e4((int)state, zoneId) &&
        !func_020981e4((int)state, var2)) return;
    if (zoneId != 0xc3b5 && zoneId != 0xc419 && zoneId != 0xc47d && zoneId != 0xc4e1)
        state->unknown_1b60_ = 1;
    LinkSession_GetInstance();
    if (zoneId == 0xc3b5 && state->progress >= 2) {
        func_0201bd3c(zone, 9, 0);
        func_0201bd3c(zone, 10, 0);
    } else if (zoneId == 0xc41b && state->progress >= 4) {
        func_0201bd3c(zone, 20, 0);
        func_0201bd3c(zone, 21, 0);
    }
    if (func_020981e4((int)state, zoneId) &&
        !func_02098240((int)state, zoneId) &&
        !func_02098210((int)state, zoneId) && zoneId != 0xc3bb) {
        GameResources* resources = GetGameResources();
        SafeAllocator* allocator = &GetResourceAllocator(GetGameResources(), 2);
        allocator->Reset();
        state->slots = (Struct_02054280*)allocator->Allocate(0x5ec);
        state->work = (Struct_02097ec8*)allocator->Allocate(Enum_02097ec8_2404);
        func_02054280(state->slots);
        func_02082828(state->work);
        func_020542b4(state->slots, &resources->allocator_array_1a0[3], &inline_0203d028_5(resources, 0x930));
    }
}
