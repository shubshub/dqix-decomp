#if defined(jpn)
#define data_ov015_021942a2 data_ov015_02194f64
#define data_ov015_021943a5 data_ov015_02194f37
#define data_ov015_021943b0 data_ov015_02194f48
#define data_ov015_021943b7 data_ov015_02194f57
#define data_ov015_021943bd data_ov015_02194f71
#define data_ov015_021943c6 data_ov015_02194f7e
#define data_ov015_021943d0 data_ov015_02194f8b
#define data_ov015_021943d9 data_ov015_02194f98
#define data_ov015_021943df data_ov015_02194f9e
#define data_ov015_021943ef data_ov015_02194fb1
#define data_ov015_021943f8 data_ov015_02194fb8
#define data_ov015_021943ff data_ov015_02194fbd
#define data_ov015_0219440c data_ov015_02194fc4
#define data_ov015_0219441a data_ov015_02194fcb
#define data_ov015_02194426 data_ov015_02194fd0
#define data_ov015_02194434 data_ov015_02194fd7
#define data_ov015_0219443d data_ov015_02194fe0
#define data_ov015_02194442 data_ov015_02194fe5
#define data_ov015_0219444b data_ov015_02194fee
#define data_ov015_02194452 data_ov015_02194ff5
#define data_ov015_02194459 data_ov015_02194ffc
#define data_ov015_0219445e data_ov015_02195001
#define data_ov015_02194463 data_ov015_02195006
#define data_ov015_02194470 data_ov015_02195017
#define data_ov015_0219447f data_ov015_0219502e
#define data_ov015_0219448e data_ov015_02195041
#define data_ov015_02194496 data_ov015_02195048
#define data_ov015_0219449e data_ov015_02195053
#define data_ov015_021944a9 data_ov015_0219505a
#define data_ov015_021944b6 data_ov015_0219506e
#define data_ov015_021944c5 data_ov015_02195083
#define data_ov015_021944d4 data_ov015_02195096
#define data_ov015_021944e3 data_ov015_021950b6
#define data_ov015_021944ec data_ov015_021950d0
#define data_ov015_021944f3 data_ov015_021950d7
#define data_ov015_021944fa data_ov015_021950de
#define data_ov015_02194503 data_ov015_021950eb
#define data_ov015_02194508 data_ov015_021950f5
#define data_ov015_0219450f data_ov015_021950fc
#define data_ov015_02194517 data_ov015_02195104
#define data_ov015_0219451b data_ov015_02195109
#define data_ov015_0219451f data_ov015_0219510e
extern const char data_ov015_021950a5[];
extern const char data_ov015_021950c3[];
extern const char data_ov015_021950f0[];
#endif
#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/BCFG.h"

struct Struct_ov015_02192700 { char unknown_0_[0x40]; };

struct Struct_ov015_02192700_2 {
    char unknown_0_[0x62];
    unsigned short unknown_62_;
    char unknown_64_[0x6d - 0x64];
    unsigned char unknown_6d_;
};

struct Struct_ov015_02192700_3 {
    char unknown_0_[0xc];
    char* unknown_c_;
};

struct Struct_ov015_02192700_4 {
    struct Struct_ov015_02192700_3* unknown_0_;
    struct Struct_ov015_02192700_4* unknown_4_;
};

struct Struct_ov015_0218bb14 { char* unknown_0_; int unknown_4_; };
struct Struct_ov015_0218bb14_2 { void* unknown_0_; struct Struct_ov015_0218bb14* unknown_4_; void* unknown_8_; int unknown_c_; };

struct Struct_ov015_02192700_5 {
    char* unknown_0_;
    int unknown_4_;
    short unknown_8_;
};

struct Struct_ov015_02192700_6 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov002_0215a658 {
    int unknown_0_;
    char* unknown_4_;
};

struct BCFG;

struct Struct_ov015_02192700_7 {
    int unknown_0_;
    char unknown_4_[0x24];
    struct Struct_ov015_02192700_7* unknown_28_;
};

struct Struct_ov015_02192700_8 {
    char unknown_0_[0x2c];
    struct Struct_ov015_02192700_4* unknown_2c_;
    void* unknown_30_;
    struct Struct_ov015_02192700_3* unknown_34_;
    char unknown_38_[0x3c - 0x38];
    struct Struct_ov015_0218bb14_2 unknown_3c_;
    char unknown_4c_[0x64 - 0x4c];
    char unknown_64_[0x194 - 0x64];
    int unknown_194_;
    char unknown_198_[0x19c - 0x198];
    unsigned char unknown_19c_[5];
    char unknown_1a1_[0x1a4 - 0x1a1];
    int unknown_1a4_;
    char unknown_1a8_[0x268 - 0x1a8];
    short unknown_268_[(0x2c4 - 0x268) / 2];
    struct Struct_ov015_02192700_2 unknown_2c4_;
    char unknown_332_[0x344 - 0x332];
    struct Struct_ov015_02192700* unknown_344_;
    int unknown_348_;
    float unknown_34c_;
    unsigned char unknown_350_;
    char unknown_351_[0x354 - 0x351];
    int unknown_354_;
};

extern "C" void __clear(void* buf, int n);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
struct Callback_0202a91c;
void SetState0x6cAndInvoke(Callback_0202a91c*);
extern "C" void func_02029568(struct MenuList02192700* menu);
extern "C" void func_020294cc(void* self, const char* src);
void Init0202949c(char*);
const char* StandardStrings_Get(int id);
struct ListHead0202a944;
struct ListNode0202a944;
void AppendNodeToList0202a944(ListHead0202a944*, ListNode0202a944*);
struct Entry8_0218bb14* GetEntry8_0218bb14(struct List8_0218bb14* list, int idx);
extern "C" struct MenuEntry02192700* func_ov015_02193160(struct Obj02192700* obj, int state, int* pIdx);
struct BinarySearchByComparatorStruct;
struct SearchResult02192700* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
extern "C" int func_ov015_02190d08(struct Obj02192700* obj);
struct ItemTable;
struct Element020dedd0* ItemTable_Find(ItemTable*, int);
struct Struct0219313c;
void SetShortFields0219313c(Struct0219313c*, int, int);
struct Struct02193150;
void AddToShortField02193150(Struct02193150*, int);
extern "C" void func_0202a6c4(struct MenuList02192700* menu);
void Deactivate0202a8cc(char*, int);
extern "C" struct HolderNode02192700* func_ov015_0218f344(void* obj);

extern AllocatorUnion g_mainAllocator;
extern const char data_ov015_021942a2[];
extern const char data_ov015_021943a5[];
extern const char data_ov015_021943b0[];
extern const char data_ov015_021943b7[];
extern const char data_ov015_021943bd[];
extern const char data_ov015_021943c6[];
extern const char data_ov015_021943d0[];
extern const char data_ov015_021943d9[];
extern const char data_ov015_021943df[];
extern const char data_ov015_021943ef[];
extern const char data_ov015_021943f8[];
extern const char data_ov015_021943ff[];
extern const char data_ov015_0219440c[];
extern const char data_ov015_0219441a[];
extern const char data_ov015_02194426[];
extern const char data_ov015_02194434[];
extern const char data_ov015_0219443d[];
extern const char data_ov015_02194442[];
extern const char data_ov015_0219444b[];
extern const char data_ov015_02194452[];
extern const char data_ov015_02194459[];
extern const char data_ov015_0219445e[];
extern const char data_ov015_02194463[];
extern const char data_ov015_02194470[];
extern const char data_ov015_0219447f[];
extern const char data_ov015_0219448e[];
extern const char data_ov015_02194496[];
extern const char data_ov015_0219449e[];
extern const char data_ov015_021944a9[];
extern const char data_ov015_021944b6[];
extern const char data_ov015_021944c5[];
extern const char data_ov015_021944d4[];
extern const char data_ov015_021944e3[];
extern const char data_ov015_021944ec[];
extern const char data_ov015_021944f3[];
extern const char data_ov015_021944fa[];
extern const char data_ov015_02194503[];
extern const char data_ov015_02194508[];
extern const char data_ov015_0219450f[];
extern const char data_ov015_02194517[];
extern const char data_ov015_0219451b[];
extern const char data_ov015_0219451f[];

static inline const char* inline_ov015_02192700(struct Struct_ov015_02192700_3* arg0) {
    return arg0->unknown_c_;
}

// USA: func_ov015_02192700
extern "C" ARM void func_ov015_02192700(struct Struct_ov015_02192700_8* arg0, int arg1) {
    char var0[0x80];
    char var1[0x100];
    char var2[0x80];
    int var3;
    int var4;

    if (obj->items != 0) {
        AllocatorUnion_Free(&g_mainAllocator, obj->items);
        obj->items = 0;
    }
    arg0->unknown_354_ = arg1;
    __clear(var0, 0x80);
    func_0202a91c((Struct_02029634_3*)&arg0->unknown_2c4_);
    func_02029568(&arg0->unknown_2c4_);
    arg0->unknown_2c4_.unknown_6d_ |= 6;

    if (arg0->unknown_194_ == 0 || arg0->unknown_194_ == 2) {
        switch (arg0->unknown_1a4_) {
        case 0:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943a5);
            break;
        case 1:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943b0);
            break;
        case 2:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943b7);
            break;
        case 3:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021942a2);
            break;
        case 4:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943bd);
            break;
        case 6:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943c6);
            break;
        case 7:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943d0);
            break;
        case 5:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943d9);
            break;
        case 8:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943df);
            break;
        case 15:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943ef);
            break;
        case 17:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943f8);
            break;
        case 18:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021943ff);
            break;
        case 19:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219440c);
            break;
        case 20:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219441a);
            break;
        case 21:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194426);
            break;
        case 23:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194434);
            break;
        case 24:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219443d);
            break;
        case 25:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194442);
            break;
        case 26:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219444b);
            break;
        case 27:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194452);
            break;
        case 28:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194459);
            break;
        case 22:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219445e);
            break;
        case 29:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194463);
            break;
        case 30:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194470);
            break;
        case 31:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219447f);
            break;
        case 16:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219448e);
            break;
        case 11:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_02194496);
            break;
        case 12:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_0219449e);
            break;
        case 33:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944a9);
            break;
        case 32:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944b6);
            break;
        case 13:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944c5);
            break;
        case 14:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944d4);
            break;
        case 34:
#if defined(jpn)
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021950a5);
#else
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021942a2);
#endif
            break;
        case 35:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944e3);
            break;
        case 36:
#if defined(jpn)
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021950c3);
#else
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021942a2);
#endif
            break;
        case 38:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944ec);
            break;
        case 39:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944f3);
            break;
        case 40:
            func_020294cc(&arg0->unknown_2c4_, data_ov015_021944fa);
            break;
        case 37:
            if (arg0->unknown_34_ != 0) {
                sprintf(var0, data_ov015_02194503, arg0->unknown_34_->unknown_c_);
            }
            func_020294cc(&arg0->unknown_2c4_, var0);
            break;
        }

        var4 = 0;
        if (arg0->unknown_1a4_ == 2 || arg0->unknown_1a4_ == 3 || arg0->unknown_1a4_ == 36) {
            struct Struct_ov015_02192700_4* var5;
            for (var5 = arg0->unknown_2c_; var5 != 0; var5 = var5->unknown_4_) {
                var4++;
            }
            if (count == 0) {
                obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(struct MenuItem02192700));
            } else {
                obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count * sizeof(struct MenuItem02192700));
            }
            if (var4 == 0) {
                func_0202949c((char*)arg0->unknown_344_);
#if defined(jpn)
                func_020294cc(arg0->unknown_344_, data_ov015_021950f0);
#else
                func_020294cc(obj->items, StandardStrings_Get(1000));
#endif
                func_0202a944((Struct_0202a944_2*)&arg0->unknown_2c4_, (Struct_0202a944*)arg0->unknown_344_);
                var4 = 1;
            } else {
                struct Struct_ov015_02192700_4* var6 = arg0->unknown_2c_;
                for (var4 = 0; var6 != 0; var4++) {
                    func_0202949c((char*)&arg0->unknown_344_[var4]);
                    func_020294cc(&arg0->unknown_344_[var4], inline_ov015_02192700(var6->unknown_0_));
                    func_0202a944((Struct_0202a944_2*)&arg0->unknown_2c4_, (Struct_0202a944*)&arg0->unknown_344_[var4]);
                    var6 = var6->unknown_4_;
                }
            }
        } else if (obj->state == 40) {
            obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, obj->entries.count * sizeof(struct MenuItem02192700));
            for (; count < obj->entries.count; count++) {
                struct Entry8_0218bb14* entry = GetEntry8_0218bb14(&obj->entries, count);
                Init0202949c((char*)&obj->items[count]);
                func_020294cc(&obj->items[count], entry->name);
                AppendNodeToList0202a944((ListHead0202a944*)&obj->menu, (ListNode0202a944*)&obj->items[count]);
            }
        } else {
            struct Struct_ov015_02192700_5* var8;

            var3 = 0;
            var8 = func_ov015_02193160(arg0, arg0->unknown_1a4_, &var3);
            while (var8 != 0) {
                var3++;
                var4++;
                var8 = func_ov015_02193160(arg0, arg0->unknown_1a4_, &var3);
            }
            obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count * sizeof(struct MenuItem02192700));
            count = 0;
            idx = 0;
            entry = func_ov015_02193160(obj, obj->state, &idx);
            while (entry != 0) {
                Init0202949c((char*)&obj->items[count]);
                if (obj->state == 6) {
                    struct SearchResult02192700* found = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)obj->search, entry->key);
                    if (found != 0) {
                        __clear(line, 0x100);
                        sprintf(line, data_ov015_02194508, found->f4 + 1, found->f0);
                        func_020294cc(&obj->items[count], line);
                    } else if ((unsigned short)entry->key == 0) {
                        func_020294cc(&obj->items[count], entry->name);
                    } else {
                        func_020294cc(&arg0->unknown_344_[var4], data_ov015_0219450f);
                    }
                } else if (func_ov015_02190d08(obj) != 0) {
                    struct Element020dedd0* elem = ItemTable_Find((ItemTable*)obj->container, entry->key);
                    if (elem != 0) {
                        if (elem->name != 0) {
                            func_020294cc(&obj->items[count], elem->name);
                        } else {
                            func_020294cc(&arg0->unknown_344_[var4], var8->unknown_0_);
                        }
                    } else {
                        func_020294cc(&arg0->unknown_344_[var4], var8->unknown_0_);
                    }
                } else if (arg0->unknown_1a4_ == 38) {
                    unsigned char var11;

                    __clear(var2, 0x80);
                    var11 = 0;
                    switch (var4) {
                    case 0:
                        var11 = arg0->unknown_19c_[0];
                        break;
                    case 1:
                        var11 = arg0->unknown_19c_[1];
                        break;
                    case 2:
                        var11 = arg0->unknown_19c_[2];
                        break;
                    case 3:
                        var11 = arg0->unknown_19c_[3];
                        break;
                    case 4:
                        var11 = arg0->unknown_19c_[4];
                        break;
                    }
                    if (var11 != 0) {
                        sprintf(var2, data_ov015_02194517);
                    } else {
                        sprintf(var2, data_ov015_0219451b);
                    }
                    strcat(var2, var8->unknown_0_);
                    func_020294cc(&arg0->unknown_344_[var4], var2);
                } else {
                    func_020294cc(&arg0->unknown_344_[var4], var8->unknown_0_);
                }
                func_0202a944((Struct_0202a944_2*)&arg0->unknown_2c4_, (Struct_0202a944*)&arg0->unknown_344_[var4]);
                var4++;
                var3++;
                var8 = func_ov015_02193160(arg0, arg0->unknown_1a4_, &var3);
            }
        }
        func_ov015_0219313c((Struct_ov015_02192700_9*)&arg0->unknown_2c4_, 0, var4 - 1);
        func_ov015_02193150((Struct_ov015_02192700_10*)&arg0->unknown_2c4_, arg0->unknown_268_[arg0->unknown_1a4_]);
        func_0202a6c4(&arg0->unknown_2c4_);
        func_0202a8cc((char*)&arg0->unknown_2c4_, 1);
    } else {
        struct Struct_ov015_02192700_7* var12;
        struct Struct_ov015_02192700_7* var13;

        func_020294cc(&arg0->unknown_2c4_, data_ov015_0219451f);
        var4 = 0;
        for (var12 = func_ov015_0218f344(arg0->unknown_30_); var12 != 0; var12 = var12->unknown_28_) {
            struct BCFG* var14 = (struct BCFG*)var12->unknown_4_;
            if (var14 != 0) {
                var4 += var14->GetNumAnimations();
            }
        }
        obj->items = (struct MenuItem02192700*)AllocatorUnion_AllocateRounded(&g_mainAllocator, count * sizeof(struct MenuItem02192700));
        holder = func_ov015_0218f344(obj->field30);
        idx = 0;
        for (; holder != 0; holder = holder->next) {
            struct BCFG* bcfg = (struct BCFG*)holder->bcfg;
            if (bcfg != 0) {
                int num = bcfg->GetNumAnimations();
                for (int i = 0; i < num; i++) {
                    const char* name = (const char*)bcfg->GetAnimationRecord(i);
                    if (name != 0) {
                        Init0202949c((char*)&obj->items[idx]);
                        func_020294cc(&obj->items[idx], name);
                        AppendNodeToList0202a944((ListHead0202a944*)&obj->menu, (ListNode0202a944*)&obj->items[idx++]);
                    }
                }
            }
        }
        func_ov015_0219313c((Struct_ov015_02192700_9*)&arg0->unknown_2c4_, 0, var4 - 1);
        func_ov015_02193150((Struct_ov015_02192700_10*)&arg0->unknown_2c4_, 0);
        func_0202a6c4(&arg0->unknown_2c4_);
        func_0202a8cc((char*)&arg0->unknown_2c4_, 1);
    }

    int var19 = arg0->unknown_2c4_.unknown_62_;
    float var20 = (float)var19 / (float)var4;
    if (var20 > 1.0f) {
        var20 = 1.0f;
    }
    arg0->unknown_348_ = (int)(156.0f * var20);
    int var21 = var4 - var19;
    arg0->unknown_34c_ = (float)(156 - arg0->unknown_348_) / (float)var21;
    if (arg0->unknown_348_ < 4) {
        arg0->unknown_34c_ -= (float)(4 - arg0->unknown_348_) / (float)var21;
        arg0->unknown_348_ = 4;
    }
    arg0->unknown_350_ = 1;
}
