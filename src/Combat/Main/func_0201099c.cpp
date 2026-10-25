#include <globaldefs.h>
#include "Resource/ItemTable.h"
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Util/Random.h"
#include "Combat/ResourceScriptEntry.h"
#include "std_library_functions.h"

struct Struct_0201099c_12 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_0201099c_19 {
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_0201099c_20 {
    signed char unknown_0_0_ : 6;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 1;
    unsigned char unknown_1_5_ : 3;
    unsigned char unknown_2_[13];
    unsigned char unknown_f_[13];
    int unknown_1c_[13];
    int unknown_50_;
    unsigned short unknown_54_;
    char unknown_56_[2];
    Struct_0201099c_12 unknown_58_[13][3];
    unsigned short unknown_f4_;
    unsigned char unknown_f6_[27];
    unsigned char unknown_111_[9];
    unsigned char unknown_11a_[36];
    unsigned char unknown_13e_;
    unsigned char unknown_13f_0_ : 3;
    unsigned char unknown_13f_3_ : 5;
    unsigned char unknown_140_[12];
    Struct_0201099c_12 unknown_14c_[4];
    unsigned int unknown_15c_0_ : 10;
    unsigned int unknown_15d_2_ : 10;
    unsigned int unknown_15e_4_ : 12;
    Struct_0201099c_19 unknown_160_;
    unsigned char unknown_17c_[0xc0];
};

struct Struct_0201099c_4 {
#if defined(jpn)
    unsigned char unknown_0_[0x3724];
#else
    unsigned char unknown1_0_[0x3984];
#endif
    Struct_0201099c_20 unknown_3984_[13];
    unsigned char unknown_5690_;
};

struct Struct_0201099c_5 {
    unsigned char unknown_0_[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    short unknown_a_;
    unsigned char unknown_c_[0x10];
    short unknown_1c_[10];
    unsigned char unknown_30_[13];
    unsigned char unknown_3d_;
    unsigned char unknown_3e_;
};

struct Struct_0201099c_6 {
    Struct_0201099c_5* unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    char unknown_a_[2];
#if defined(jpn)
    const char** unknown_c_;
#else
    int unknown1_c_;
#endif
    short unknown_10_;
    char unknown_12_[2];
#if defined(jpn)
    const char** unknown_14_;
#else
    int unknown1_14_;
#endif
    short unknown_18_;
};

struct Struct_0201099c_7 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

struct Struct_0201099c_8 {
    unsigned char unknown_0_[0x10c];
    Struct_0201099c_7 unknown_10c_[13][20];
    unsigned char unknown_51c_[0x34];
};

struct Struct_0201099c_9 {
    unsigned int unknown_0_[8];
};

struct CharacterProfile0201099c {
    char name[0x30];
    unsigned short stat6c;
    unsigned short stat6e;
    unsigned short stat70;
    unsigned short stat72;
};

struct Struct_0201099c_13 {
    Struct_0201099c_12 unknown_0_[4];
    unsigned char unknown_10_[0x2c];
    Struct_0201099c_11 unknown_3c_;
    unsigned char unknown_74_[0x120];
    Struct_0201099c_9 unknown_194_[8];
#if defined(jpn)
    unsigned char unknown_294_[0x638];
#else
    unsigned char unknown1_294_[0x6d0];
#endif
};

struct Struct_020e6d98 {
    short unknown_0_;
    short unknown_2_;
};

struct Struct_020e6d64 {
    short unknown_0_[2];
};

struct Struct_020e6d74 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
};

struct Container020e0310;
struct SetFlagBitStruct;
struct Struct020865b0;
struct SetBitArrayStruct020865b8;
struct Ctx0209a810 {
    int handle;
};

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void ResetAndReturnSelf020dfc2c(void* p);
void KeyTable_Reset(Struct020dfc40* p);
void ResetAndDetach020dfc6c(Struct020dfc40* p);
extern "C" void KeyTable_Load(Struct020dfc40* table, SafeAllocator* alloc, void* data, unsigned int size);
void ResetStructFields_02089db4(ResetFieldsStruct* s);
void ForwardResetStructFields02089ddc(ResetFieldsStruct* s);
void SetupHeaderAndRunBufferedScript02089de8(void* param0, void* param1, const char* param2);
void* GetElementStride0x40_0208a018(unsigned char* obj, int index);
extern "C" void PartyMemberRecord_Init(CombatSelection* selection);
void SetFlagBitAndIndex_02086598(SetFlagBitStruct* s, int n);
char* KeyTable_Get(Container020e0310* c, int key);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" int Font_EncodeText(void* a, void* b, int flag);
void ClearField00209a804(int* p);
void SpellTable_Load(Ctx0209a810* ctx, void* value);
int GetFieldAt0x50(Struct020865b0* p);
void SetBitInArray020865b8(SetBitArrayStruct020865b8* s, int n);
void ItemTable_Construct(void* p);
void ItemTable_Init(void* p);
extern "C" int func_020dea64(void* a, void* b, void* c, unsigned int d, const void* e, short f);
void* ResourceScriptEntry_Init(void* obj);
extern "C" void func_02082828(CharacterRecord0201099c* record);
extern "C" void PartyMember_ApplyLevelStats(void* dst, void* src, void* tail);
Element020de650* ItemTable_Find(ItemTable* c, int key);
extern "C" void PartyMember_RecalculateStats(void* a, int arg2);

extern AllocatorUnion g_mainAllocator;
extern char data_020ef08c[];
extern char data_020ef0a5[];
extern const IdPair0201099c data_020e6d64;
extern const ShortPair0201099c data_020e6d98[];
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern const char data_020e6d6c[];
extern const char data_020ef0b5[];
extern unsigned char g_fileLoadBuffer[];
extern const SlotMap0201099c data_020e6d74[];
#if defined(jpn)
extern const Struct_020e6d98 data_020e763c[];
extern const Struct_020e6d74 data_020e7618[];
extern unsigned char data_020e7610[];
extern const char data_020eeff3[];
extern "C" int func_020e052c(void*, void*, const char*, void*, short, unsigned char);
int STD_GetStringLength(const char*);
#endif

static inline const Struct_020e6d98* inline_0201099c(int arg0) {
#if defined(jpn)
    return &data_020e763c[arg0];
#else
    return &data_020e6d98[arg0];
#endif
}

static inline const Struct_020e6d74* inline_0201099c_2(int arg0) {
#if defined(jpn)
    return &data_020e7618[arg0];
#else
    return &data_020e6d74[arg0];
#endif
}

static inline unsigned short inline_0201099c_3(const Struct_0201099c_11* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_30_; }

static inline unsigned short inline_0201099c_4(const Struct_0201099c_11* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_32_; }

static inline unsigned short inline_0201099c_5(const Struct_0201099c_11* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_34_; }

static inline unsigned short inline_0201099c_6(const Struct_0201099c_11* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_36_; }

// USA: func_0201099c
extern "C" ARM void func_0201099c(Struct_0201099c_4* arg0) {
    Struct_0201099c_8 var0;
    Struct_0201099c_2 var1;
    Random* var2 = GetBTRandom();
    Struct_0201099c_5* var3;
    Struct_0201099c_20* var4;
    long var5;
    int var6;
    unsigned char var7[3];
    var7[0] = NextRandomMax(var2, 4);
    var7[1] = NextRandomMax(var2, 2) + 4;
    unsigned char var8 = var7[0] % 2 + var7[1] % 2;
    if (var8 == 0) {
        var7[2] = 7;
    } else if (var8 == 2) {
        var7[2] = 6;
    } else {
        var7[2] = NextRandomMax(var2, 2) + 6;
    }

#if !defined(jpn)
    SafeAllocator nameAlloc;
    nameAlloc.ResetAllocatorPointer();
    nameAlloc.ResetAllocatorPointer();
    nameAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x5000), 0x5000);
    Struct020dfc40 names;
    ResetAndReturnSelf020dfc2c(&names);
    KeyTable_Reset(&names);
    BackgroundLoader::AddLockGlobal();
    unsigned int nameSize = 0;
    void* nameData = ExtractFileFromGP2(data_020ef08c, data_020ef0a5, &nameSize);
    if (nameData != NULL) {
        KeyTable_Load(&names, &nameAlloc, nameData, nameSize);
    }
    BackgroundLoader::RemoveLockGlobal();

    Struct_020e6d64 var13 = data_020e6d64;
#endif
    Struct_0201099c_6 var14;
    SafeAllocator var15;
    var15.ResetAllocatorPointer();
#if defined(jpn)
    scriptAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1400), 0x1400);
#else
    scriptAlloc.ResetAllocatorPointer();
    scriptAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800), 0x800);
#endif
    func_02089db4(&var14);
    func_02089de8(&var14, &var15, NULL);
    int var16 = var14.unknown_4_;

    for (var5 = 0; var5 < 3; var5++) {
        var3 = (Struct_0201099c_5*)func_0208a018((unsigned char*)&var14, var7[var5]);
        if (var3 == NULL) {
            break;
        }
        var6 = -1;
        if (var3->unknown_3d_ == 1) {
            var6 = 0;
        } else if (var3->unknown_3d_ == 4) {
            var6 = 0;
        } else if (var3->unknown_3d_ == 2) {
            var6 = 1;
        } else if (var3->unknown_3d_ == 3) {
            var6 = 2;
        }
        if (var6 < 0) {
            continue;
        }
        m = &gs->members[slot];
        PartyMemberRecord_Init(m);
        m->selected = slot;
        m->active = 0;
        m->reserved = 0;
        m->count = t->count;
        Appearance0201099c* look = &m->appearance;
        look->voice = t->voice;
        look->hairStyle = NextRandomMax(rng, 8);
        look->hairColor = NextRandomMax(rng, 8);
        look->face = NextRandomMax(rng, 10);
        look->gender = t->gender;
        int size = look->gender * 5 + NextRandomMax(rng, 5);
        look->height = GetBodySize0201099c(size)->a;
        look->width = GetBodySize0201099c(size)->b;
        SetFlagBitAndIndex_02086598((SetFlagBitStruct*)m, t->vocation);
        for (int j = 0; j < 13; j++) {
            m->levels[j] = t->levels[j];
        }
#if defined(jpn)
        const char** var20 = var17->unknown_14_0_ == 0 ? var14.unknown_c_ : var14.unknown_14_;
        unsigned char var21 = func_020865b0((Struct_0201099c_16*)var4);
        if (var21 == 1) {
            var20 += NextRandomMax(var2, 5);
        } else if (var21 == 4) {
            var20 += NextRandomMax(var2, 5) + 5;
        } else if (var21 == 2) {
            var20 += NextRandomMax(var2, 5) + 10;
        } else if (var21 == 3) {
            var20 += NextRandomMax(var2, 5) + 15;
        } else {
            var20 += NextRandomMax(var2, 5);
        }
        memcpy(m->name, *name, STD_GetStringLength(*name));
#else
        short var22 = 20000;
        if (var17->unknown_14_0_ == 1) {
            var22 += 1000;
        }
        short var23;
        int var24;
        do {
            var24 = 0;
            var23 = var22 + NextRandomMax(var2, 101);
            for (int var25 = var5 - 1; var25 >= 0; var25--) {
                if (var23 == var13.unknown_0_[var25]) {
                    var24 = 1;
                }
            }
        } while (found);
        used.ids[i] = nameId;
        char* nameStr = KeyTable_Get((Container020e0310*)&names, nameId);
        unsigned char nameBuf[12];
        __clear(nameBuf, sizeof(nameBuf));
        Font_EncodeText(nameStr, nameBuf, 1);
        memcpy(m->name, nameBuf, sizeof(nameBuf));
#endif
        short* var28 = var4->unknown_160_.unknown_0_;
        for (int var29 = 0; var29 < 10; var29++) {
            if (var29 == 2) {
                var28[var29] = NextRandomMax(var2, 10) + 0x233c;
            } else if (var29 == 3) {
                var28[var29] = NextRandomMax(var2, 10) + 0x2328;
            } else {
                var28[var29] = var3->unknown_1c_[var29];
            }
        }
        arg0->unknown_5690_++;
    }

    ForwardResetStructFields02089ddc(&templates);
    SignedAllocatorHeader* scriptHeader = scriptAlloc.GetSignedAllocator();
    scriptAlloc.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, scriptHeader);
#if !defined(jpn)
    ResetAndDetach020dfc6c(&names);
    SignedAllocatorHeader* nameHeader = nameAlloc.GetSignedAllocator();
    if (nameHeader != NULL) {
        nameAlloc.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, nameHeader);
    }

#endif

    if (templateCount > 0) {
        CharacterRecord0201099c record;
        Ctx0209a810 ctx;
        ClearField00209a804(&ctx.handle);
        SpellTable_Load(&ctx, &skills);
        for (int j = 0; j < gs->memberCount; j++) {
            m = &gs->members[j];
            unsigned char vocation = GetFieldAt0x50((Struct020865b0*)m);
            unsigned char level = m->levels[vocation];
            SkillUnlock0201099c* row = skills.rows[vocation];
            for (int k = 0; k < 20; k++) {
                if (level >= row[k].level && row[k].level != 0) {
                    SetBitInArray020865b8((SetBitArrayStruct020865b8*)m, row[k].skill);
                }
            }
        }

        SafeAllocator var39;
        var39.ResetAllocatorPointer();
        var39.ResetAllocatorPointer();
#if defined(jpn)
        itemAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x12c00), 0x12c00);
#else
        itemAlloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x13800), 0x13800);
#endif
        itemAlloc.Reset();
        ItemTable items;
        ItemTable_Construct(&items);
        ItemTable_Init(&items);
#if defined(jpn)
        func_020e052c(&items, &itemAlloc, g_itemDataArchive, data_020e7610, 8, 1);
#else
        BackgroundLoader::AddLockGlobal();
        unsigned int itemSize = 0;
        void* itemData = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &itemSize);
        if (itemData != NULL) {
            func_020dea64(&items, &itemAlloc, itemData, itemSize, data_020e6d6c, 8);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        BackgroundLoader::AddLockGlobal();
        Struct_0201099c_13* var43;
        for (int var44 = 0; var44 < 13; var44++) {
            char var45[0x19];
            unsigned int var46;
#if defined(jpn)
            sprintf(var45, data_020eeff3, var44);
#else
            sprintf(var45, data_020ef0b5, var44);
#endif
            if (LoadFileIntoMemory(path, g_fileLoadBuffer, &size) != NULL) {
                ResourceScriptEntry* res = &entry;
                for (int j = 0; j < gs->memberCount; j++) {
                    m = &gs->members[j];
                    ResourceScriptEntry_Init(res);
                    ResourceScriptEntry_LoadLevel(res, g_fileLoadBuffer, size, m->levels[v], 0);
                    m->experience[v] = res->initial.value0;
                    m->skillPoints += res->initial.value4High;
                    if (v == GetFieldAt0x50((Struct020865b0*)m)) {
                        rec = &record;
                        CharacterProfile0201099c* profile = &rec->profile;
                        func_02082828(rec);
                        PartyMember_ApplyLevelStats(rec, &entry, entry.variants);
                        short* equipment = m->appearance.equipment;
                        for (int k = 0; k < 8; k++) {
                            Element020de650* item = ItemTable_Find(&items, equipment[GetSlotMap0201099c(k)->appearanceIndex]);
                            if (item != NULL) {
                                memcpy(&record.equipment[GetSlotMap0201099c(k)->recordIndex], item, sizeof(Element020de650));
                            }
                        }
                        PartyMember_RecalculateStats(&record, 0);
                        m->vectors[0].x = rec->base[0].x;
                        m->vectors[0].y = rec->base[0].y;
                        m->vectors[0].z = rec->base[0].z;
                        m->vectors[1].x = rec->base[1].x;
                        m->vectors[1].y = rec->base[1].y;
                        m->vectors[1].z = rec->base[1].z;
                        m->vectors[2].x = rec->base[2].x;
                        m->vectors[2].y = GetStat6c0201099c(profile);
                        m->vectors[2].z = GetStat6e0201099c(profile);
                        PackedTriple0201099c* current = &m->vectors[3];
                        current->x = GetStat6c0201099c(profile);
                        current->y = GetStat6e0201099c(profile);
                        current->z = GetStat700201099c(profile);
                        m->timer = GetStat720201099c(profile);
                        m->timerLimit = rec->base[3].x;
                    }
                }
            }
        }
        BackgroundLoader::RemoveLockGlobal();
        SignedAllocatorHeader* itemHeader = itemAlloc.GetSignedAllocator();
        itemAlloc.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, itemHeader);
    }
}
