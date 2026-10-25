#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02097ec8_2404 = 0x8cc };
#else
enum { Enum_02097ec8_2404 = 0x964 };
#endif
#include "Resource/GameResources.h"

struct Struct_02054280;
struct Struct_02097ec8;
struct Struct_0208fa8c { unsigned short unknown_0_; unsigned short unknown_2_; };
struct Struct_02097ec8_2 {
    char unknown_0_[0x1b3c];
    unsigned int unknown_1b3c_;
    char unknown_1b40_[0x1b58 - 0x1b40];
    Struct_02054280* unknown_1b58_;
    Struct_02097ec8* unknown_1b5c_;
    unsigned char unknown_1b60_;
};
extern "C" ZoneState* Zone3D_GetInstance();
extern "C" void* func_0202ae18();
extern "C" void func_0201bd3c(Struct_0208fa8c*, int, int);
extern "C" void func_02082828(Struct_02097ec8*);
extern "C" void func_020542b4(Struct_02054280*, SafeAllocator*, char*);
extern "C" int func_020981e4(int, int);
extern "C" int func_02098240(int, int);
extern "C" int func_02098210(int, int);
extern "C" void func_02054280(Struct_02054280*);

static inline SafeAllocator& inline_02021578(GameResources* arg0, int arg1) {
    return arg0->allocator_array_1a0[arg1];
}

static inline char& GetResourceBuffer(GameResources* resources, int offset) {
    return resources->vramStates_[offset];
}

// USA: func_02097ec8
extern "C" ARM void func_02097ec8(ZoneResourceState* state) {
    ZoneState* zone = Zone3D_GetInstance();
    int zoneId = zone->zoneId;
    int previousZoneId = zone->previousZoneId;
    if (!IsIdInRange020981e4((int)state, zoneId) &&
        !IsIdInRange020981e4((int)state, previousZoneId)) return;
    if (zoneId != 0xc3b5 && zoneId != 0xc419 && zoneId != 0xc47d && zoneId != 0xc4e1)
        state->entered = 1;
    func_0202ae18();
    if (var1 == 0xc3b5 && arg0->unknown_1b3c_ >= 2) {
        func_0201bd3c(var0, 9, 0);
        func_0201bd3c(var0, 10, 0);
    } else if (var1 == 0xc41b && arg0->unknown_1b3c_ >= 4) {
        func_0201bd3c(var0, 20, 0);
        func_0201bd3c(var0, 21, 0);
    }
    if (func_020981e4((int)arg0, var1) &&
        !func_02098240((int)arg0, var1) &&
        !func_02098210((int)arg0, var1) && var1 != 0xc3bb) {
        GameResources* var3 = GetGameResources();
        SafeAllocator* var4 = &inline_02021578(GetGameResources(), 2);
        var4->Reset();
        arg0->unknown_1b58_ = (Struct_02054280*)var4->Allocate(0x5ec);
        arg0->unknown_1b5c_ = (Struct_02097ec8*)var4->Allocate(Enum_02097ec8_2404);
        func_02054280(arg0->unknown_1b58_);
        func_02082828(arg0->unknown_1b5c_);
        func_020542b4(arg0->unknown_1b58_, &var3->allocator_array_1a0[3], &inline_0203d028_5(var3, 0x930));
    }
}
