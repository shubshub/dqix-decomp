#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"
#include "World/Zone3D.h"

struct Struct_ov004_02164928 {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData unknown_ad4_[8];
    unsigned char unknown_18f4_;
};
struct MapCoordinates02164928 { int x, y, z; };
struct Payload0201165c { MapCoordinates02164928 coordinates; unsigned int environment, monsterRank; };
struct Obj021f9bb0;
struct Obj020d8080;
struct TailList020469b4;
struct TailNode020469b4;
extern MapList02164928* data_ov004_02171010;
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
extern "C" int* func_0202ae18();
extern "C" int func_0202b7d8(int*);
extern "C" int func_0202c508(int*);
extern "C" void func_ov017_021cfabc();
extern "C" void func_ov017_021cf730(int, int);
extern "C" void func_ov017_021d3ec8();
extern "C" void func_020d8080(Struct_020d8080*);
extern "C" void func_020469b4(Struct_0201bdac_2*, Struct_0201bdac*);

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
        data_ov004_02171010->maps[i].ClearInitialByteUnknownBit();
    int mapIndex = GetScaledStat_021634dc_021634dc(self);
    for (int i = 0; i < 99; ++i)
        data_ov004_02171010->maps[i].ClearInitialByteUnknownBit();
    data_ov004_02171010->maps[mapIndex].SetInitialByteUnknownBit();
    Obj021f9bb0* node = func_ov023_021f6880(func_ov011_021849c8(self), 10);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;
    unsigned int detailIndex = GetShort28_021f9bb0(node);
#if defined(jpn)
    if (data_ov004_02171010->unknown_ad4_[var9].mapType_ == 1) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(var0)), &data_ov004_02171010->unknown_0_[var6], data_ov004_02171010->unknown_ad4_[var9].entranceZoneID_, *((Struct_ov004_02164928_2*)(&data_ov004_02171010->unknown_ad4_[var9].entranceX_)), data_ov004_02171010->unknown_ad4_[var9].regular_.environ_, data_ov004_02171010->unknown_ad4_[var9].regular_.startingMonsterRank_);
        var4->unknown_8 = func_02090294(var3);
    } else if (data_ov004_02171010->unknown_ad4_[var9].mapType_ == 2) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(var0)), &data_ov004_02171010->unknown_0_[var6], data_ov004_02171010->unknown_ad4_[var9].entranceZoneID_, *((Struct_ov004_02164928_2*)(&data_ov004_02171010->unknown_ad4_[var9].entranceX_)), 0, 0);
        var4->unknown_8 = func_02090294(var3);
    }
    strcpy(var4->activeMapImageName, data_ov004_02171010->unknown_ad4_[var9].mapImageName_);
    if (data_ov004_02171010->unknown_ad4_[var9].mapType_ == 1) {
        DetailedTreasureMapData::RegularMapData* var10 = &data_ov004_02171010->unknown_ad4_[var9].regular_;
        sprintf(var4->activeMapNameNoLevel, var10->nameNoLevel_);
        var4->activeMapLevel = data_ov004_02171010->unknown_ad4_[var9].regular_.level_;
    } else if (data_ov004_02171010->unknown_ad4_[var9].mapType_ == 2) {
        DetailedTreasureMapData::LegacyBossMapData* var11 = &data_ov004_02171010->unknown_ad4_[var9].legacy_;
        sprintf(var4->activeMapNameNoLevel, var11->mapNameNoLevel_);
        var4->activeMapLevel = data_ov004_02171010->unknown_ad4_[var9].legacy_.level_;
    }
#else
    Struct_ov004_02164928* var12 = data_ov004_02171010;
    DetailedTreasureMapData* var13 = &var12->unknown_ad4_[var9];
    if (var13->mapType_ == 1) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(var0)), &var12->unknown_0_[var6], var13->entranceZoneID_, *((Struct_ov004_02164928_2*)(&var13->entranceX_)), var13->regular_.environ_, var13->regular_.startingMonsterRank_);
        var4->unknown_8 = func_02090294(var3);
    } else if (var13->mapType_ == 2) {
        ((Type_ov004_02164928)(func_0201165c))(((char*)(var0)), &var12->unknown_0_[var6], var13->entranceZoneID_, *((Struct_ov004_02164928_2*)(&var13->entranceX_)), 0, 0);
        var4->unknown_8 = func_02090294(var3);
    }
    strcpy(var4->activeMapImageName, var13->mapImageName_);
    if (var13->mapType_ == 1) {
        DetailedTreasureMapData::RegularMapData* var14 = &var13->regular_;
        sprintf(var4->activeMapNameNoLevel, var14->nameNoLevel_);
        var4->activeMapLevel = var13->regular_.level_;
        *((unsigned short*)(var4->unk_a)) = var13->regular_.suffix_;
    } else if (var13->mapType_ == 2) {
        DetailedTreasureMapData::LegacyBossMapData* var15 = &var13->legacy_;
        sprintf(var4->activeMapNameNoLevel, var15->mapNameNoLevel_);
        var4->activeMapLevel = var13->legacy_.level_;
        *((unsigned short*)(var4->unk_a)) = 0;
    }
#endif
    GrottoStruct* var16 = var0->GetGrottoStruct();
    char* var17 = var2->unk_2664;
    if (var16->unknown_0[0]) {
        if (var16->activeMapData.GetDiscoveryState() == DiscoveryState_Discovered ||
            var16->activeMapData.GetDiscoveryState() == DiscoveryState_Cleared) {
            func_0208f748(var17, &var16->entranceX);
        }
    }
    var16->unknown_0[3] = 0;
    func_ov017_021cfcec(1);
    func_02011408(var0);
    int* var18 = func_0202ae18();
    if (func_0202b7d8(var18) && func_0202c508(var18)) {
        func_ov017_021cfabc();
        func_ov017_021cf730(-1, 0);
        func_ov017_021d3ec8();
    }
#if defined(jpn)
    if (data_ov004_02171010->unknown_ad4_[var9].discoveryState_ == 1) {
#else
    if (var13->discoveryState_ == 1) {
#endif
        TailList020469b4* list;
        Obj020d8080* object = static_cast<Obj020d8080*>(resources->fieldTasks_[42]);
        list = (TailList020469b4*)resources->fieldTaskQueue_;
        InitObject020d8080(object);
        AppendNodeToTail(list, ((TailNode020469b4*)(object)));
    }
    return 0;
}
