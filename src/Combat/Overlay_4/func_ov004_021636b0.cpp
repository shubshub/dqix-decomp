#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct Struct_ov004_021549e4_2;
struct Struct_0202656c;
struct TableA68;

struct Struct_ov004_021636b0 {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData details[8];

    DetailedTreasureMapData::RegularMapData* inline_ov004_021636b0(int index) {
        return &details[index].regular_;
    }

    DetailedTreasureMapData::LegacyBossMapData* inline_ov004_021636b0_2(int index) {
        return &details[index].legacy_;
    }
};

struct Struct_ov004_02171010 {
    Struct_ov004_021636b0* base;
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
extern "C" int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* obj);
extern "C" void func_02026428(void* dst, const char* src);
extern "C" void func_02026470(void* dst, int value);
extern "C" void func_020264e4(char* dst, char* src);
extern "C" void func_02026528(char* dst, char* src);
extern "C" void func_0202656c(struct Struct_0202656c* obj, int value);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_020265a8(char* dst, int index, const char* name, int rate);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void func_0206819c(const char* source, char* destination, int tableIndex);
extern "C" void* func_020e5294(void* obj, int index);
extern "C" void func_020263c8(unsigned char* obj, int value);
extern "C" void func_02026418(unsigned char* buf, unsigned char val);
extern "C" void func_020dc3d4(void);

#if defined(jpn)
extern "C" int func_ov004_0216ff54(unsigned short id, char* text);
extern "C" void func_02041f50(const char* src, char* dst);
#endif

// USA: func_ov004_021636b0
extern "C" ARM void func_ov004_021636b0(void* a0, const char* a1) {
#if !defined(jpn)
    char var0[0x80];
#endif
    char bufA[0x80];

    char* zone = (char*)Zone3D_GetInstance();
#if !defined(jpn)
    DetailedTreasureMapData* var3;
#endif
    void* var4;
    char* slot;
    struct TableA68* table;
    unsigned char* buf;
    GameResources* res = GetGameResources();
    buf = (unsigned char*)res->unknown_ptr_36d0;
    strcpy(zone + 0x26, a1);
    func_020dc3d4();
    func_02026418(buf, 1);
    *(int*)(buf + 0x14) = 1;

    void* obj = func_ov023_021f6880(func_ov011_021849c8(a0), 0xa);
    if (obj == NULL) return;
    if (func_ov023_021f6f10(obj) != 7) return;

    int idx = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)obj);
#if !defined(jpn)
    var3 = &data_ov004_02171010.base->details[idx];
#endif

#if defined(jpn)
    if (data_ov004_02171010.base->details[idx].mapType_ == 1) {
        func_02026428(buf, data_ov004_02171010.base->inline_ov004_021636b0(idx)->nameNoLevel_);
        func_02026470(buf, data_ov004_02171010.base->details[idx].regular_.level_);
    } else if (data_ov004_02171010.base->details[idx].mapType_ == 2) {
        func_02026428(buf, data_ov004_02171010.base->inline_ov004_021636b0_2(idx)->mapNameNoLevel_);
        func_02026470(buf, data_ov004_02171010.base->details[idx].legacy_.level_);
    }
    func_020264e4((char*)buf, data_ov004_02171010.base->details[idx].discoveredBy_);
    func_02026528((char*)buf, data_ov004_02171010.base->details[idx].clearedBy_);
    if (data_ov004_02171010.base->details[idx].mapType_ == 2) {
        func_0202656c((struct Struct_0202656c*)buf, data_ov004_02171010.base->details[idx].legacy_.minTurns_);
    }

#else
    if (var3->mapType_ == 1) {
        func_02026428(buf, var3->regular_.nameNoLevel_);
        func_02026470(buf, var3->regular_.level_);
    } else if (var3->mapType_ == 2) {
        func_02026428(buf, var3->legacy_.mapNameNoLevel_);
        func_02026470(buf, var3->legacy_.level_);
    }
    func_020264e4((char*)buf, var3->discoveredBy_);
    func_02026528((char*)buf, var3->clearedBy_);
    if (var3->mapType_ == 2) {
        func_0202656c((struct Struct_0202656c*)buf, var3->legacy_.minTurns_);
    }

#endif

    var4 = func_ov011_021849c8(a0);
#if defined(jpn)
    void* obj2 = func_ov023_021f6880(var4, 0x258);
    if (obj2 == NULL) return;
    if (func_ov023_021f6f10(obj2) != 4) return;
    table = func_ov023_021fa598(obj2);
    for (int i = 0; i < 3; i++) {
        __clear(bufA, sizeof(bufA));
        if (data_ov004_02171010.base->details[idx].discoveredTreasures_[i] == 0) {
            func_020265a8((char*)buf, (unsigned char)i, NULL, data_ov004_02171010.base->details[idx].treasureDropRates_[i]);
            continue;
        }
        if (!func_ov004_0216ff54(data_ov004_02171010.base->details[idx].treasureItemIDs_[i], bufA)) {
            const char* name = (const char*)func_02072a68(table, (short)data_ov004_02171010.base->details[idx].treasureItemIDs_[i]);
            if (name != NULL) {
                func_02041f50(name, bufA);
            }
        }
        unsigned char rate = data_ov004_02171010.base->details[idx].treasureDropRates_[i];
        func_020265a8((char*)buf, (unsigned char)i, bufA, rate);
    }
#else
    memset(data_ov004_02171010.unknown_4_, 0, 0x333);

    for (int i = 0; i < 3; i++) {
        __clear(var0, 0x80);
        __clear(bufA, 0x80);
        int tableRoot = MessageSystem_GetInstance();
        if (var3->discoveredTreasures_[i] == 0) {
            func_020265a8((char*)buf, (unsigned char)i, NULL, var3->treasureDropRates_[i]);
            continue;
        }

        slot = data_ov004_02171010.unknown_4_ + i * 0x80;
        memset(slot, 0, 0x80);
        int key = func_ov004_0216f8c0(var3->treasureItemIDs_[i]);
        if (key != 0) {
            void* obj2 = func_ov023_021f6880(var4, 0x32);
            if (obj2 == NULL) return;
            if (func_ov023_021f6f10(obj2) != 4) return;
            struct TableA68* table = func_ov023_021fa598(obj2);
            func_0206819c((const char*)func_02072a68(table, (short)key), bufA, 0);
            MessageSystem_FormatText(tableRoot, 0, bufA, slot, 0x60, 0, 0);
        } else {
            char** entry = (char**)func_020e5294(data_ov004_02171010.unknown_8_, (short)var3->treasureItemIDs_[i]);
            func_0206819c(*entry, bufA, 0);
            MessageSystem_FormatText(tableRoot, 0, bufA, slot, 0x60, 0, 0);
        }
        func_020265a8((char*)buf, (unsigned char)i, slot, var3->treasureDropRates_[i]);
    }

#endif
    func_020263c8(buf, 1);
}
