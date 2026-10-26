#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"
#include "World/Zone3D.h"

struct Struct_ov004_02164928 {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData details[8];
    unsigned char count;
};
struct Struct_ov004_02164928_2 { int x, y, z; };
struct Struct_0201165c { Struct_ov004_02164928_2 coordinates; unsigned int environment, unknown_10_; };
struct Struct_ov004_021549e4_2;
struct Obj020d8080;
struct TailList020469b4;
struct TailNode020469b4;
extern Struct_ov004_02164928* data_ov004_02171010;
extern "C" Zone3D* Zone3D_GetInstance();
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_ov004_021634dc(void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_021549e4_2* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(Struct_ov004_021549e4_2*);
extern "C" unsigned int func_ov023_021f9bb0(Struct_ov004_021549e4_2*);
extern "C" void func_0201165c(char*, const void*, int, Struct_0201165c);
typedef void (*Type_ov004_02164928)(char*, const void*, int, Struct_ov004_02164928_2, unsigned int, unsigned int);
extern "C" unsigned char func_02090294(ActiveGrottoClass*);
extern "C" void func_0208f748(char*, int*);
extern "C" void func_ov017_021cfcec(unsigned char);
extern "C" void func_02011408(void*);
extern "C" int* LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsHostOrSolo(int*);
extern "C" void func_ov017_021cfabc();
extern "C" void func_ov017_021cf730(int, int);
extern "C" void func_ov017_021d3ec8();
extern "C" void func_020d8080(Obj020d8080*);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);

// JPN: 0x02164fe8; USA/EUR: 0x02164928.
extern "C" ARM int func_ov004_02164928(void* self) {
    if (data_ov004_02171010->count == 0) return 0;
    GameState* state = GameState::GetInstance();
    GameResources* resources = ((GameState*)((state)))->GetResources();
    Zone3D* zone = Zone3D_GetInstance();
    ActiveGrottoClass* area = zone->GetActiveGrotto();
    GrottoStruct* grotto = state->GetGrottoStruct();
    if (IsBrightnessTransitionActive(resources)) return 0;
    for (int i = 0; i < data_ov004_02171010->count; ++i)
        data_ov004_02171010->unknown_0_[i].ClearInitialByteUnknownBit();
    int var6 = func_ov004_021634dc(self);
    for (int i = 0; i < 99; ++i)
        data_ov004_02171010->unknown_0_[i].ClearInitialByteUnknownBit();
    data_ov004_02171010->unknown_0_[var6].SetInitialByteUnknownBit();
    Struct_ov004_021549e4_2* node = func_ov023_021f6880(func_ov011_021849c8(self), 10);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;
    unsigned int var9 = func_ov023_021f9bb0(node);
#if defined(jpn)
    if (data_ov004_02171010->details[var9].mapType_ == 1) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(state)), &data_ov004_02171010->unknown_0_[var6], data_ov004_02171010->details[var9].entranceZoneID_, *((Struct_ov004_02164928_2*)(&data_ov004_02171010->details[var9].entranceX_)), data_ov004_02171010->details[var9].regular_.environ_, data_ov004_02171010->details[var9].regular_.startingMonsterRank_);
        grotto->unknown_8 = func_02090294(area);
    } else if (data_ov004_02171010->details[var9].mapType_ == 2) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(state)), &data_ov004_02171010->unknown_0_[var6], data_ov004_02171010->details[var9].entranceZoneID_, *((Struct_ov004_02164928_2*)(&data_ov004_02171010->details[var9].entranceX_)), 0, 0);
        grotto->unknown_8 = func_02090294(area);
    }
    strcpy(grotto->activeMapImageName, data_ov004_02171010->details[var9].mapImageName_);
    if (data_ov004_02171010->details[var9].mapType_ == 1) {
        DetailedTreasureMapData::RegularMapData* var10 = &data_ov004_02171010->details[var9].regular_;
        sprintf(grotto->activeMapNameNoLevel, var10->nameNoLevel_);
        grotto->activeMapLevel = data_ov004_02171010->details[var9].regular_.level_;
    } else if (data_ov004_02171010->details[var9].mapType_ == 2) {
        DetailedTreasureMapData::LegacyBossMapData* var11 = &data_ov004_02171010->details[var9].legacy_;
        sprintf(grotto->activeMapNameNoLevel, var11->mapNameNoLevel_);
        grotto->activeMapLevel = data_ov004_02171010->details[var9].legacy_.level_;
    }
#else
    Struct_ov004_02164928* var12 = data_ov004_02171010;
    DetailedTreasureMapData* detail = &var12->details[var9];
    if (detail->mapType_ == 1) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(state)), &var12->unknown_0_[var6], detail->entranceZoneID_, *((Struct_ov004_02164928_2*)(&detail->entranceX_)), detail->regular_.environ_, detail->regular_.startingMonsterRank_);
        grotto->unknown_8 = func_02090294(area);
    } else if (detail->mapType_ == 2) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(state)), &var12->unknown_0_[var6], detail->entranceZoneID_, *((Struct_ov004_02164928_2*)(&detail->entranceX_)), 0, 0);
        grotto->unknown_8 = func_02090294(area);
    }
    strcpy(grotto->activeMapImageName, detail->mapImageName_);
    if (detail->mapType_ == 1) {
        DetailedTreasureMapData::RegularMapData* var14 = &detail->regular_;
        sprintf(grotto->activeMapNameNoLevel, var14->nameNoLevel_);
        grotto->activeMapLevel = detail->regular_.level_;
        *((unsigned short*)(grotto->unk_a)) = detail->regular_.suffix_;
    } else if (detail->mapType_ == 2) {
        DetailedTreasureMapData::LegacyBossMapData* var15 = &detail->legacy_;
        sprintf(grotto->activeMapNameNoLevel, var15->mapNameNoLevel_);
        grotto->activeMapLevel = detail->legacy_.level_;
        *((unsigned short*)(grotto->unk_a)) = 0;
    }
#endif
    GrottoStruct* active = state->GetGrottoStruct();
    char* event = zone->unk_2664;
    if (active->unknown_0[0]) {
        if (active->activeMapData.GetDiscoveryState() == DiscoveryState_Discovered ||
            active->activeMapData.GetDiscoveryState() == DiscoveryState_Cleared) {
            func_0208f748(event, &active->entranceX);
        }
    }
    active->unknown_0[3] = 0;
    func_ov017_021cfcec(1);
    func_02011408(state);
    int* context = LinkSession_GetInstance();
    if (LinkSession_IsActive(context) && LinkSession_IsHostOrSolo(context)) {
        func_ov017_021cfabc();
        func_ov017_021cf730(-1, 0);
        func_ov017_021d3ec8();
    }
#if defined(jpn)
    if (data_ov004_02171010->details[var9].discoveryState_ == 1) {
#else
    if (detail->discoveryState_ == 1) {
#endif
        TailList020469b4* list;
        Obj020d8080* object = static_cast<Obj020d8080*>(resources->fieldTasks_[42]);
        list = (TailList020469b4*)resources->fieldTaskQueue_;
        func_020d8080(object);
        func_020469b4(list, ((TailNode020469b4*)(object)));
    }
    return 0;
}
