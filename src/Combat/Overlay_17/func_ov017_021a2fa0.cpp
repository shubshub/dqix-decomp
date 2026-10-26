#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Memory/SafeAllocator.h"

struct State0207dfc8;

struct Struct_ov017_021a2fa0 {
    unsigned char pad0[0xb6];
    unsigned char unknown_b6_;
};

struct ZoneInfo_021a2fa0 {
    unsigned short zoneId;
    char pad2[6];
    int field8;
#if defined(jpn)
    char fieldC[0x26a4 - 0xc];
#else
    char fieldC[0x2664 - 0xc];
#endif
    Struct_ov017_021a2fa0 archive;
};

struct PartyInfo_021a2fa0 {
    char pad0[0xf7d];
    unsigned char unknown_f7d_;
};

extern "C" ZoneInfo_021a2fa0* Zone3D_GetInstance(void);
extern "C" void func_ov017_021a316c(unsigned char* obj);
extern "C" void func_ov017_021a2c14(unsigned char* obj, int a, void* b);
extern "C" void func_020a6728(unsigned char* obj, unsigned short zoneId);
extern "C" void func_020aca88(unsigned char* obj, unsigned short zoneId);
extern "C" void VramState_CopyCurrentTo(struct State0207dfc8* src, struct State0207dfc8* dst);
extern "C" int func_0208f588(Struct_ov017_021a2fa0* self, void* allocator, char* pairObj);
extern "C" int func_0208f748(Struct_ov017_021a2fa0* obj, int a1);
extern "C" void func_ov017_021a28a8(unsigned char* obj);
extern "C" void func_ov017_021913d0(unsigned char* obj, int count);
extern "C" void func_ov017_021ce494(void);

// USA: func_ov017_021a2fa0
extern "C" ARM void func_ov017_021a2fa0(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x1034, regionalOffset1=0x58c, regionalOffset2=0x1048, regionalOffset3=0xf2c, regionalOffset4=0xf40, regionalOffset5=0xfb0, regionalOffset6=0xfc4};
#else
 enum {regionalOffset0=0x1244, regionalOffset1=0x5dc, regionalOffset2=0x1258, regionalOffset3=0x113c, regionalOffset4=0x1150, regionalOffset5=0x11c0, regionalOffset6=0x11d4};
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

    Struct_ov017_021a2fa0* archive = &zone->archive;
    func_0208f588(archive, obj + regionalOffset0, (char*)(obj + regionalOffset2));

    GrottoStruct* grotto = gs->GetGrottoStruct();
    if (grotto->unknown_0[0] != 0
        && (grotto->activeMapData.GetDiscoveryState() == DiscoveryState_Discovered
            || grotto->activeMapData.GetDiscoveryState() == DiscoveryState_Cleared)
        && *(int*)&grotto->entranceZoneId == zone->zoneId) {
        archive->unknown_b6_ = 1;
        func_0208f748(archive, 0);
    } else {
        archive->unknown_b6_ = 0;
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
    if (party->unknown_f7d_ != 0) {
        func_ov017_021913d0(obj, party->unknown_f7d_);
    } else {
        func_ov017_021ce494();
    }
}
