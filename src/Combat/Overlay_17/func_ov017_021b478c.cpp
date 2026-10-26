#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Object3D.h"
#include "std_library_functions.h"
#include "World/GrottoTileGraph.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
void* GameState_GetZoneTable(void* obj);
int ZoneId_IsMainGrottoFloor(int id);
void ClearHalfword0x18_0209bffc(void* obj);
void ClearBuffer0209bc84(void* obj);
struct ResetObject0209af34Struct;
void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
void Clear12Bytes0206efc4(void* obj);
struct ZeroWordAndByte0206ee60Struct;
void ZeroWordAndByte0206ee60(struct ZeroWordAndByte0206ee60Struct* obj);
void Clear12Bytes020a8e88(void* obj);

extern const char data_ov017_021d7afc[];
extern const char data_ov017_021d7b06[];
extern const char data_ov017_021d7b0d[];
extern const char data_ov017_021d7b24[];
extern const char data_ov017_021d7b3a[];

struct Struct_ov017_021b478c_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[3];
    char unknown_5_[1];
};

struct SearchTable;
MonsterEntry021b478c* ZoneTable_FindEntry(struct SearchTable* table, int key);

struct Struct_ov017_021b478c {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[8 - 2];
    Struct_0201a300_4* unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
};

// USA: func_ov017_021b478c
extern "C" ARM void func_ov017_021b478c(Struct_ov017_021b478c* arg0) {
#if defined(jpn)
 enum {Enum_ov017_021b478c_9228=0x240c, Enum_ov017_021b478c_68=0x40, Enum_ov017_021b478c_96=0x5c, Enum_ov017_021b478c_292=0x120, Enum_ov017_021b478c_760=0x2f4, Enum_ov017_021b478c_772=0x300, Enum_ov017_021b478c_780=0x308, Enum_ov017_021b478c_1092=0x444};
#else
 enum {Enum_ov017_021b478c_9196=0x23ec, Enum_ov017_021b478c_68=0x44, Enum_ov017_021b478c_96=0x60, Enum_ov017_021b478c_292=0x124, Enum_ov017_021b478c_760=0x2f8, Enum_ov017_021b478c_772=0x304, Enum_ov017_021b478c_780=0x30c, Enum_ov017_021b478c_1060=0x424};
#endif
    GameState* var0;
    BackgroundLoader* var1;
    struct Struct_02095924_2* var2;
    Zone3D* var3;
    int var4;
    Struct_ov017_021b478c_2* var5;
    char* var6;
    ActiveGrottoClass* var7;

    battle = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    table = (struct SearchTable*)GameState_GetZoneTable(battle);
    zone = Zone3D_GetInstance();
    grotto = &zone->grotto_;
    id = request->monster->zoneId;
    entry = ZoneTable_FindEntry(table, id);

    var6 = (char*)arg0->unknown_8_;
    func_0209bffc(var6 + Enum_ov017_021b478c_68);
    func_0209bc84(var6 + Enum_ov017_021b478c_96);
    func_0209af34((struct Struct_020287b4_2*)(var6 + Enum_ov017_021b478c_292));
    func_0206efc4(var6 + Enum_ov017_021b478c_760);
    func_0206ee60((struct Struct_020287b4_4*)(var6 + Enum_ov017_021b478c_772));
    func_020a8e88(var6 + Enum_ov017_021b478c_780);

    if (arg0->unknown_8_->unknown_0_ == 3 || arg0->unknown_8_->unknown_10_->GetSignedAllocator() == NULL) {
        arg0->unknown_1_ = 1;
        return;
    }

    if (!ZoneId_IsMainGrottoFloor(id)) {
        char name[0x14];
        char path[0x50];
        if (strlen(entry->name) < 6) {
            sprintf(name, data_ov017_021d7afc, entry->name);
        } else {
            sprintf(var8, data_ov017_021d7b06, var5->unknown_5_);
        }
        var8[3] = 'P';
        strcpy(var9, var8);
        arg0->unknown_c_ = var1->QueueLoadFileInGP2(data_ov017_021d7b0d, var9, NULL);
        arg0->unknown_10_ = 1;
        return;
    }

    if (var4 != var0->GetProtagonist()->obj3D_.GetField06()) {
        char var10[0x50];
        sprintf(var10, data_ov017_021d7b24, var7->GetActiveGrottoEnviron());
        arg0->unknown_c_ = var1->QueueLoadFile(var10, NULL);
        arg0->unknown_10_ = 2;
        return;
    }

    if (ZoneId_IsMainGrottoFloor(id)) {
        int floor = id % 20;
        if (grotto->floorMap_.pMapData == NULL || zone->unknown_424_ != 0) {
            return;
        }
        func_0201a300(var3, var11, arg0->unknown_8_, 0, 0);
    }
    arg0->unknown_8_->unknown_c_ = 1;
    arg0->unknown_c_ = var1->QueueLoadFile(data_ov017_021d7b3a, NULL);
    arg0->unknown_10_ = 3;
}
