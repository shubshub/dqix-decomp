#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Grotto/Main/TreasureMapDataStructs.h"

struct Struct_ov004_021636b0 {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData details[8];
    unsigned char count;
    char unknown_18f5_;
    short page;
    short unknown_18f8_;
};
struct Struct_ov004_02171010_2 { Struct_ov004_021636b0* buffer; void* scratch; void* file; };
struct Struct_ov004_02162dd8 {
    int field0;
    SafeAllocator allocator;
    SafeAllocator* inline_ov004_02164084_48() { return &allocator; }
};

struct Struct_ov004_02153e20 {
    char pad[0x5c];
    short page;
    short unknown_5e_;
    char pad60;
    unsigned char unknown_61_;
};

class Struct_ov004_02164084 {
public:
    virtual void v00();
    virtual void inline_ov004_02164084_50();
    virtual void inline_ov004_02164084_51();
    virtual void inline_ov004_02164084_52();
    virtual void v04();
    virtual void inline_ov004_02164084_54();
    virtual void inline_ov004_02164084_55();
    virtual void inline_ov004_02164084_56();
    virtual void v08();
    virtual void inline_ov004_02164084_2();
    virtual void v10();
    virtual void inline_ov004_02164084_4();
    virtual void inline_ov004_02164084_5();
    virtual void inline_ov004_02164084_6();
    virtual void v14();
    virtual void inline_ov004_02164084_8();
    virtual void inline_ov004_02164084_9();
    virtual void inline_ov004_02164084_10();
    virtual void v18();
    virtual void inline_ov004_02164084_12();
    virtual void v20();
    virtual void inline_ov004_02164084_14();
    virtual void inline_ov004_02164084_15();
    virtual void inline_ov004_02164084_16();
    virtual void v24();
    virtual void inline_ov004_02164084_18();
    virtual void inline_ov004_02164084_19();
    virtual void inline_ov004_02164084_20();
    virtual void v28();
    virtual void inline_ov004_02164084_22();
    virtual void v30();
    virtual void inline_ov004_02164084_24();
    virtual void inline_ov004_02164084_25();
    virtual void inline_ov004_02164084_26();
    virtual void v34();
    virtual void inline_ov004_02164084_28();
    virtual void inline_ov004_02164084_29();
    virtual void inline_ov004_02164084_30();
    virtual void v38();
    virtual void inline_ov004_02164084_32();
    virtual void v40();
    virtual void inline_ov004_02164084_34();
    virtual void inline_ov004_02164084_35();
    virtual void inline_ov004_02164084_36();
    virtual void v44();
    virtual void inline_ov004_02164084_38();
    virtual void inline_ov004_02164084_39();
    virtual void inline_ov004_02164084_40();
    virtual void v48();
    virtual void inline_ov004_02164084_42();
    virtual void v50();
    virtual void inline_ov004_02164084_44();
    virtual void inline_ov004_02164084_45();
    virtual void inline_ov004_02164084_46();
    virtual void inline_ov004_02164084_47(int code);

    char pad4[8];
    unsigned char flags;
    char unknown_d_[0x13];
    char* text;
    char pad24[0xe0];
    short page;
    short unknown_106_;
};

extern Struct_ov004_02171010_2 data_ov004_02171010;
extern char data_ov004_02170584[];
extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_02164084* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021f65d4(void*, int, int);
extern "C" void func_ov023_021f9d14(void*, void*);
extern "C" void func_ov023_021f809c(void*, void*);
extern "C" Struct_ov004_02162dd8* func_ov011_021845f8(void*, int);
extern "C" void func_ov004_021634b8(void*, int, int);
extern "C" void func_ov023_021f9b30(Struct_ov004_02153e20*, unsigned short, unsigned int, unsigned int);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" int func_020119f8(char*, void*);
struct Struct_02011930;
extern "C" int func_02011930(void*, Struct_02011930*, void*, void*);

// USA: func_ov004_02164084
extern "C" ARM int func_ov004_02164084(void* obj) {
    void* var0 = func_ov011_021849c8(obj);
    Struct_ov004_02153e20* grid = (Struct_ov004_02153e20*)func_ov023_021f6880(var0, 10);
    if (!grid) return 0;
    if (func_ov023_021f6f10(grid) != 7) return 0;
    short var2 = data_ov004_02171010.buffer->page;
    short field0 = data_ov004_02171010.buffer->unknown_18f8_;
    grid->page = var2;
    grid->unknown_5e_ = field0;
    BackgroundLoader::AddLockGlobal();
    Struct_ov004_02162dd8* node = func_ov011_021845f8(obj, 0);
    if (!node) return 0;
    SafeAllocator* const allocator = node->inline_ov004_02164084_48();
    if (!allocator) return 0;
    unsigned char* scratch = (unsigned char*)allocator->Allocate(0x8000);
    unsigned int length = 0;
    if (!LoadFileIntoMemory(data_ov004_02170584, scratch, &length)) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        int index = i + data_ov004_02171010.buffer->page * 8;
        Struct_ov004_02164084* left = func_ov023_021f6880(var0, i + 0x3c);
        if (!left) continue;
        if (func_ov023_021f6f10(left) != 8) return 0;
        Struct_ov004_02164084* right = func_ov023_021f6880(var0, i + 0x46);
        if (!right) continue;
        if (func_ov023_021f6f10(right) != 8) return 0;
        func_ov023_021f65d4(obj, i + 0x226, 8);
        func_ov004_021634b8(obj, i + 0x226, 0);
        func_ov023_021f65d4(obj, i + 0x230, 8);
        func_ov004_021634b8(obj, i + 0x230, 0);
        func_ov023_021f65d4(obj, i + 0x23a, 8);
        func_ov004_021634b8(obj, i + 0x23a, 0);
        DetailedTreasureMapData* var12 = &data_ov004_02171010.buffer->details[i];
        var12->BlankFunction();
        left->text = 0;
        left->flags |= 8;
        func_ov023_021f9b30(grid, 0, i & 0xffff, 0);
        right->text = 0;
        right->flags |= 8;
        if (index >= data_ov004_02171010.buffer->count) continue;
        ExportDetailedTreasureMapData(&data_ov004_02171010.buffer->unknown_0_[index], &data_ov004_02171010.buffer->details[i], true, scratch);
        left->flags &= ~8;
        func_ov023_021f9b30(grid, (unsigned short)(i + 0x3c), (unsigned short)i, 0);
        right->flags &= ~8;
        if (var12->mapType_ == 1) {
            left->text = var12->regular_.nameNoLevel_;
            right->text = var12->regular_.levelString_;
        } else if (var12->mapType_ == 2) {
            left->text = var12->legacy_.mapNameNoLevel_;
            right->text = var12->legacy_.mapLevelString_;
        }
        GameState* gs = GameState::GetInstance();
        left->inline_ov004_02164084_47(0xf);
        right->inline_ov004_02164084_47(0xf);
        if (var12->discoveryState_ == 1) {
            func_ov023_021f6600(obj, i + 0x230, 8);
        } else if (var12->discoveryState_ == 2) {
            func_ov023_021f6600(obj, i + 0x226, 8);
        } else if (var12->discoveryState_ == 3) {
            func_ov023_021f6600(obj, i + 0x23a, 8);
        }
        if (func_020119f8((char*)gs, 0)) {
            if (var12->discoveryState_ == 1) {
                left->inline_ov004_02164084_47(4);
                right->inline_ov004_02164084_47(4);
            } else if (var12->discoveryState_ == 2) {
                left->inline_ov004_02164084_47(4);
                right->inline_ov004_02164084_47(4);
            }
        } else {
            if (!func_02011930(gs, 0, 0, 0)) continue;
            if (!data_ov004_02171010.buffer->unknown_0_[index].GetInitialByteUnknownBit()) continue;
            left->inline_ov004_02164084_47(4);
            right->inline_ov004_02164084_47(4);
        }
    }
    allocator->Free(scratch);
    BackgroundLoader::RemoveLockGlobal();
    if (data_ov004_02171010.buffer->count == 0) {
        grid->page = 1;
        grid->unknown_5e_ = 1;
        func_ov023_021f9b30(grid, 0x3c, 0, 0);
        Struct_ov004_02164084* w = func_ov023_021f6880(func_ov011_021849c8(obj), 0x1f4);
        if (w) w->flags |= 8;
        w = func_ov023_021f6880(func_ov011_021849c8(obj), 0x14);
        if (w) w->flags &= ~4;
        for (unsigned short j = 0; j < 0x10;) {
            w = func_ov023_021f6880(func_ov011_021849c8(obj), j + 0x3c);
            if (w) w->flags |= 8;
            j++;
        }
        w = func_ov023_021f6880(func_ov011_021849c8(obj), 0x36);
        if (w) w->flags &= ~8;
        w = func_ov023_021f6880(var0, 0x16);
        if (!w) return 0;
        if (func_ov023_021f6f10(w) != 6) return 0;
        w->flags |= 8;
    } else {
        Struct_ov004_02164084* w = func_ov023_021f6880(func_ov011_021849c8(obj), 0x36);
        if (w) w->flags |= 8;
    }
    func_ov023_021f9d14(grid, obj);
    Struct_ov004_02164084* w = func_ov023_021f6880(var0, 0x14);
    if (!w) return 0;
    if (func_ov023_021f6f10(w) != 6) return 0;
    if (data_ov004_02171010.buffer->count <= 8) w->flags &= ~4;
    else w->flags |= 4;
    short page = data_ov004_02171010.buffer->page;
    short var19 = data_ov004_02171010.buffer->unknown_18f8_;
    w->page = page;
    w->unknown_106_ = var19;
    func_ov023_021f809c(w, obj);
    grid->unknown_61_ = 1;
    return 0;
}
