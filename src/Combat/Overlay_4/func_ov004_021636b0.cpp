#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct Struct_ov004_021549e4_2;
struct Struct_0202656c;
struct Struct_02072a68_2;

struct Struct_ov004_021636b0 {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData unknown_ad4_[8];

    DetailedTreasureMapData::RegularMapData* inline_ov004_021636b0(int arg0) {
        return &unknown_ad4_[arg0].regular_;
    }

    DetailedTreasureMapData::LegacyBossMapData* inline_ov004_021636b0_2(int arg0) {
        return &unknown_ad4_[arg0].legacy_;
    }
};

struct Struct_ov004_02171010 {
    Struct_ov004_021636b0* unknown_0_;
    char* unknown_4_;
    void* unknown_8_;
};

extern struct Struct_ov004_02171010 data_ov004_02171010;

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int index);
extern "C" struct TableA68* func_ov023_021fa598(void* obj);
extern "C" int func_ov004_0216f8c0(unsigned short id);
extern "C" void MessageSystem_FormatText(int a, int b, char* text, char* slot, int c, int d, int e);
extern "C" void* __clear(void* destination, int count);

extern "C" unsigned int func_ov023_021f6f10(void* self);
int GetShort28_021f9bb0(struct Obj021f9bb0* obj);
void CopyStringOrDefault02026428(void* dst, const char* src);
void SetEventStringAndAccumulateLength02026470(void* dst, int value);
void SetString020264e4(char* dst, char* src);
void SetString02026528(char* dst, char* src);
void SetField766AndNotify0202656c(struct Obj0202656c* obj, int value);
int MessageSystem_GetInstance(void);
void SetIndexedRecord020265a8(char* dst, int index, const char* name, int rate);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
void CopyTextAndUppercaseIfFlagged0206819c(const char* source, char* destination, int tableIndex);
void* CallFunc020e52a0_020e5294(void* obj, int index);
void SetBoolFlag020263c8(unsigned char* obj, int value);
void SetByteFieldAt0x764_02026418(unsigned char* buf, unsigned char val);
void RestartTaskWithDebugLog020dc3d4(void);

#if defined(jpn)
extern "C" int func_ov004_0216ff54(unsigned short arg0, char* arg1);
extern "C" void func_02041f50(const char* arg0, char* arg1);
#endif

// USA: func_ov004_021636b0
extern "C" ARM void func_ov004_021636b0(void* arg0, const char* arg1) {
#if !defined(jpn)
    char var0[0x80];
#endif
    char var1[0x80];

    char* zone = (char*)Zone3D_GetInstance();
#if !defined(jpn)
    DetailedTreasureMapData* var3;
#endif
    void* var4;
    char* var5;
    struct Struct_02072a68_2* var6;
    unsigned char* var7;
    GameResources* var8 = GetGameResources();
    var7 = (unsigned char*)var8->unknown_ptr_36d0;
    strcpy(var2 + 0x26, arg1);
    func_020dc3d4();
    func_02026418(var7, 1);
    *(int*)(var7 + 0x14) = 1;

    void* var9 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0xa);
    if (var9 == NULL) return;
    if (func_ov023_021f6f10(var9) != 7) return;

    int var10 = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)var9);
#if !defined(jpn)
    var3 = &data_ov004_02171010.unknown_0_->unknown_ad4_[var10];
#endif

#if defined(jpn)
    if (data_ov004_02171010.unknown_0_->unknown_ad4_[var10].mapType_ == 1) {
        func_02026428(var7, data_ov004_02171010.unknown_0_->inline_ov004_021636b0(var10)->nameNoLevel_);
        func_02026470(var7, data_ov004_02171010.unknown_0_->unknown_ad4_[var10].regular_.level_);
    } else if (data_ov004_02171010.unknown_0_->unknown_ad4_[var10].mapType_ == 2) {
        func_02026428(var7, data_ov004_02171010.unknown_0_->inline_ov004_021636b0_2(var10)->mapNameNoLevel_);
        func_02026470(var7, data_ov004_02171010.unknown_0_->unknown_ad4_[var10].legacy_.level_);
    }
    func_020264e4((char*)var7, data_ov004_02171010.unknown_0_->unknown_ad4_[var10].discoveredBy_);
    func_02026528((char*)var7, data_ov004_02171010.unknown_0_->unknown_ad4_[var10].clearedBy_);
    if (data_ov004_02171010.unknown_0_->unknown_ad4_[var10].mapType_ == 2) {
        func_0202656c((struct Struct_0202656c*)var7, data_ov004_02171010.unknown_0_->unknown_ad4_[var10].legacy_.minTurns_);
    }

#else
    if (var3->mapType_ == 1) {
        func_02026428(var7, var3->regular_.nameNoLevel_);
        func_02026470(var7, var3->regular_.level_);
    } else if (var3->mapType_ == 2) {
        func_02026428(var7, var3->legacy_.mapNameNoLevel_);
        func_02026470(var7, var3->legacy_.level_);
    }
    func_020264e4((char*)var7, var3->discoveredBy_);
    func_02026528((char*)var7, var3->clearedBy_);
    if (var3->mapType_ == 2) {
        func_0202656c((struct Struct_0202656c*)var7, var3->legacy_.minTurns_);
    }

#endif

    var4 = func_ov011_021849c8(arg0);
#if defined(jpn)
    void* var11 = func_ov023_021f6880(var4, 0x258);
    if (var11 == NULL) return;
    if (func_ov023_021f6f10(var11) != 4) return;
    var6 = func_ov023_021fa598(var11);
    for (int var12 = 0; var12 < 3; var12++) {
        __clear(var1, sizeof(var1));
        if (data_ov004_02171010.unknown_0_->unknown_ad4_[var10].discoveredTreasures_[var12] == 0) {
            func_020265a8((char*)var7, (unsigned char)var12, NULL, data_ov004_02171010.unknown_0_->unknown_ad4_[var10].treasureDropRates_[var12]);
            continue;
        }
        if (!func_ov004_0216ff54(data_ov004_02171010.unknown_0_->unknown_ad4_[var10].treasureItemIDs_[var12], var1)) {
            const char* var13 = (const char*)func_02072a68(var6, (short)data_ov004_02171010.unknown_0_->unknown_ad4_[var10].treasureItemIDs_[var12]);
            if (var13 != NULL) {
                func_02041f50(var13, var1);
            }
        }
        unsigned char var14 = data_ov004_02171010.unknown_0_->unknown_ad4_[var10].treasureDropRates_[var12];
        func_020265a8((char*)var7, (unsigned char)var12, var1, var14);
    }
#else
    memset(data_ov004_02171010.unknown_4_, 0, 0x333);

    for (int i = 0; i < 3; i++) {
        __clear(bufB, 0x80);
        __clear(bufA, 0x80);
        int tableRoot = MessageSystem_GetInstance();
        if (det->discoveredTreasures_[i] == 0) {
            SetIndexedRecord020265a8((char*)buf, (unsigned char)i, NULL, det->treasureDropRates_[i]);
            continue;
        }

        slot = data_ov004_02171010.slotBuffer + i * 0x80;
        memset(slot, 0, 0x80);
        int key = func_ov004_0216f8c0(det->treasureItemIDs_[i]);
        if (key != 0) {
            void* obj2 = func_ov023_021f6880(ov011, 0x32);
            if (obj2 == NULL) return;
            if (func_ov023_021f6f10(obj2) != 4) return;
            struct TableA68* table = func_ov023_021fa598(obj2);
            CopyTextAndUppercaseIfFlagged0206819c((const char*)FindEntryByKey_02072a68(table, (short)key), bufA, 0);
            MessageSystem_FormatText(tableRoot, 0, bufA, slot, 0x60, 0, 0);
        } else {
            char** entry = (char**)CallFunc020e52a0_020e5294(data_ov004_02171010.callTarget, (short)det->treasureItemIDs_[i]);
            CopyTextAndUppercaseIfFlagged0206819c(*entry, bufA, 0);
            MessageSystem_FormatText(tableRoot, 0, bufA, slot, 0x60, 0, 0);
        }
        func_020265a8((char*)var7, (unsigned char)var15, var5, var3->treasureDropRates_[var15]);
    }

#endif
    func_020263c8(var7, 1);
}
