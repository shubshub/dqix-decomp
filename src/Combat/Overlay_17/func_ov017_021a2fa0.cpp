#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Memory/SafeAllocator.h"

struct Struct_02015ef4_5;

struct Struct_ov017_021a2fa0 {
    unsigned char unknown_0_[0xb6];
    unsigned char unknown_b6_;
};

struct Struct_ov017_021a2fa0_2 {
    unsigned short unknown_0_;
    char unknown_2_[6];
    int unknown_8_;
#if defined(jpn)
    char unknown_c_[0x26a4 - 0xc];
#else
    char unknown_c_[0x2664 - 0xc];
#endif
    Struct_ov017_021a2fa0 unknown_2664_;
};

struct Struct_ov017_021a2fa0_3 {
    char unknown_0_[0xf7d];
    unsigned char unknown_f7d_;
};

extern "C" ZoneInfo_021a2fa0* Zone3D_GetInstance(void);
extern "C" void func_ov017_021a316c(unsigned char* obj);
extern "C" void func_ov017_021a2c14(unsigned char* obj, int a, void* b);
extern "C" void func_020a6728(unsigned char* obj, unsigned short zoneId);
extern "C" void func_020aca88(unsigned char* obj, unsigned short zoneId);
void VramState_CopyCurrentTo(struct State0207dfc8* src, struct State0207dfc8* dst);
extern "C" int func_0208f588(Archive_021a2fa0* self, void* allocator, char* pairObj);
extern "C" int func_0208f748(Archive_021a2fa0* obj, int a1);
extern "C" void func_ov017_021a28a8(unsigned char* obj);
extern "C" void func_ov017_021913d0(unsigned char* obj, int count);
void EnqueueEventTag40IfNotBusy_021ce494(void);

// USA: func_ov017_021a2fa0
extern "C" ARM void func_ov017_021a2fa0(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov017_021a2fa0_4676=0x1034, Enum_ov017_021a2fa0_1500=0x58c, Enum_ov017_021a2fa0_4696=0x1048, Enum_ov017_021a2fa0_4412=0xf2c, Enum_ov017_021a2fa0_4432=0xf40, Enum_ov017_021a2fa0_4544=0xfb0, Enum_ov017_021a2fa0_4564=0xfc4};
#else
 enum {Enum_ov017_021a2fa0_4676=0x1244, Enum_ov017_021a2fa0_1500=0x5dc, Enum_ov017_021a2fa0_4696=0x1258, Enum_ov017_021a2fa0_4412=0x113c, Enum_ov017_021a2fa0_4432=0x1150, Enum_ov017_021a2fa0_4544=0x11c0, Enum_ov017_021a2fa0_4564=0x11d4};
#endif
    GameState* gs = GameState::GetInstance();
    ZoneInfo_021a2fa0* zone = Zone3D_GetInstance();
    func_ov017_021a316c(obj);
    func_ov017_021a2c14(obj, zone->field8, zone->fieldC);
    func_020a6728(obj, zone->zoneId);
    func_020aca88(obj, zone->zoneId);

    unsigned int size = ((SafeAllocator*)(obj + 0xc4))->GetMaxPossibleAllocation();
    void* buf = ((SafeAllocator*)(obj + 0xc4))->Allocate(size);
    ((SafeAllocator*)(obj + regionalOffset0))->CreateTypeA(buf, size);
    VramState_CopyCurrentTo((struct State0207dfc8*)(obj + regionalOffset1), (struct State0207dfc8*)(obj + regionalOffset2));

    Struct_ov017_021a2fa0* var4 = &var1->unknown_2664_;
    func_0208f588(var4, arg0 + Enum_ov017_021a2fa0_4676, (char*)(arg0 + Enum_ov017_021a2fa0_4696));

    GrottoStruct* var5 = var0->GetGrottoStruct();
    if (var5->unknown_0[0] != 0
        && (var5->activeMapData.GetDiscoveryState() == DiscoveryState_Discovered
            || var5->activeMapData.GetDiscoveryState() == DiscoveryState_Cleared)
        && *(int*)&var5->entranceZoneId == var1->unknown_0_) {
        var4->unknown_b6_ = 1;
        func_0208f748(var4, 0);
    } else {
        var4->unknown_b6_ = 0;
    }

    size = ((SafeAllocator*)(obj + regionalOffset0))->GetMaxPossibleAllocation();
    buf = ((SafeAllocator*)(obj + regionalOffset0))->Allocate(size);
    ((SafeAllocator*)(obj + regionalOffset3))->CreateTypeA(buf, size);
    VramState_CopyCurrentTo((struct State0207dfc8*)(obj + regionalOffset2), (struct State0207dfc8*)(obj + regionalOffset4));
    func_ov017_021a28a8(obj);

    size = ((SafeAllocator*)(obj + regionalOffset3))->GetMaxPossibleAllocation();
    buf = ((SafeAllocator*)(obj + regionalOffset3))->Allocate(size);
    ((SafeAllocator*)(obj + regionalOffset5))->CreateTypeA(buf, size);
    VramState_CopyCurrentTo((struct State0207dfc8*)(obj + regionalOffset4), (struct State0207dfc8*)(obj + regionalOffset6));

    PartyInfo_021a2fa0* party = (PartyInfo_021a2fa0*)GameState_GetParty(gs);
    if (party->pendingCount != 0) {
        func_ov017_021913d0(obj, party->pendingCount);
    } else {
        func_ov017_021ce494();
    }
}
