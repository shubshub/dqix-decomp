#include <globaldefs.h>
#include "Resource/ItemTable.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Combat/ResourceScriptEntry.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_02086f24_3 {
    unsigned int x : 10;
    unsigned int y : 10;
    unsigned int z : 10;
    unsigned int reserved : 2;
};

struct Struct_02086f24_8 {
    short equipment[10];
    unsigned char gender : 1;
    unsigned char hairStyle : 3;
    unsigned char hairColor : 4;
    unsigned char face : 4;
    short unknown_16_;
    short height;
    short width;
};

struct CombatSelection {
    signed char selected : 6;
    unsigned char active : 1;
    unsigned char reserved : 1;
    unsigned char count : 4;
    unsigned char unknown_1_4_ : 1;
    unsigned char mode : 3;
    unsigned char levels[13];
    unsigned char status[13];
    int experience[13];
    int current;
    unsigned short unknown_54_;
    char unknown_56_[2];
    Struct_02086f24_3 triples[13][3];
    unsigned short skillPoints;
    unsigned char flags[27];
    unsigned char unknown_111_[9];
    unsigned char unknown_11a_[36];
    unsigned char unknown_13e_;
    unsigned char cursor : 3;
    unsigned char capacity : 5;
    unsigned char name[12];
    Struct_02086f24_3 unknown_14c_[4];
    unsigned int timer : 10;
    unsigned int unknown_15d_2_ : 10;
    unsigned int unknown_15e_4_ : 12;
    Struct_02086f24_8 appearance;
    unsigned char unknown_17c_[0xc0];
};

struct Struct_02086f24 {
    signed char id;
    char pad1[3];
    const char* name;
    unsigned char gender;
    char unknown_9_;
    short unknown_a_;
    char unknown_c_[4];
    unsigned char hairStyle;
    unsigned char face;
    unsigned char hairColor;
    char unknown_13_;
    float height;
    float width;
    short equipment[10];
    unsigned char levels[13];
    unsigned char vocation;
    unsigned char count;
    unsigned char cursor;
};

struct ResetFieldsStruct {
    Struct_02086f24* entries;
    short count;
    short unknown_6_;
    short f8;
    char unknown_a_[2];
    int fc;
    short f10;
    char pad12[2];
    int f14;
    short f18;
};

struct Struct_01ff8b48 {
    char name[0x30];
    unsigned short unknown_30_;
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
};

struct Element020de650 {
    unsigned int v[8];
};

struct Struct_02086f24_2 {
    Struct_02086f24_3 base[4];
    unsigned char pad10[0x2c];
    Struct_01ff8b48 profile;
    unsigned char unknown_74_[0x120];
    Element020de650 equipment[11];
#if defined(jpn)
    unsigned char unknown_2f4_[0x5d8];
#else
    unsigned char unknown1_2f4_[0x670];
#endif
};

struct Party02086f24 {
    unsigned char pad[0xf70];
    unsigned int memberCount;
};

struct Struct_02086f24_5;
struct Ctx0209a8b4 { void* field0; };
struct Struct_02086f24_7;
struct StreamHeader;

extern "C" void PresetTable_Reset(ResetFieldsStruct* s);
extern "C" void PresetTable_Destroy(ResetFieldsStruct* s);
extern "C" void PresetTable_Load(void* param0, void* param1, const char* param2);
extern "C" Struct_02086f24* func_02089fb0(Struct_02086f24_5* arr, int id);
extern "C" void PartyMemberRecord_Init(CombatSelection* selection);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" int Font_EncodeText(const void* a, void* b, int flag);
extern "C" void func_02082828(Struct_02086f24_2* record);
extern "C" void func_02082d6c(Struct_02086f24_2* dst, CombatSelection* src);
extern "C" void func_02082fc4(void* a, void* b);
extern "C" void ItemTable_Construct(void* p);
extern "C" void ItemTable_Init(void* p);
extern "C" int func_020def44(int a0, int a1, int a2, short a3);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);
extern "C" void func_0209a804(int* p);
extern "C" void func_0209a8b4(Ctx0209a8b4* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
extern "C" int func_0209ab20(Struct_02086f24_7* h, int slot, int threshold, unsigned char* out);
extern "C" int Party_AddMemberRecord(Party02086f24* party, CombatSelection* sel, unsigned char c, unsigned char d);

extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern const signed char data_020e8a94[10];
extern const char data_020f102e[];
extern unsigned char g_fileLoadBuffer[];
#if defined(jpn)
extern "C" void* func_020e0968(const char* filename, unsigned int* outLength);
extern const char data_020f1150[];
#define HEAP_SIZE_02086f24 0xc00
#else
#define HEAP_SIZE_02086f24 0x800
#endif

#define FX_F32_TO_FX16(x) ((short)(((x) > 0) ? (short)((x) * 4096.0f + 0.5f) : (short)((x) * 4096.0f - 0.5f)))

static inline void inline_02086f24(CombatSelection* s, int n) {
    s->unknown_54_ |= 1 << n;
    s->current = n;
}

static inline int inline_02086f24_2(int n) { return n / 8; }

static inline int inline_02086f24_3(int n) { return n % 8; }

static inline short inline_02086f24_4(const Struct_02086f24* t, int k) { return t->equipment[k]; }

static inline unsigned short inline_02086f24_5(const Struct_01ff8b48* profile) { SDK_NULL_ASSERT(profile); return profile->unknown_30_; }

static inline unsigned short inline_02086f24_6(const Struct_01ff8b48* profile) { SDK_NULL_ASSERT(profile); return profile->unknown_32_; }

static inline unsigned short inline_02086f24_7(const Struct_01ff8b48* profile) { SDK_NULL_ASSERT(profile); return profile->unknown_34_; }

static inline unsigned short inline_02086f24_8(const Struct_01ff8b48* profile) { SDK_NULL_ASSERT(profile); return profile->unknown_36_; }

// USA: func_02086f24
extern "C" ARM int func_02086f24(Party02086f24* party, unsigned char id, SafeAllocator* heap) {
    CombatSelection sel;
    ResourceScriptEntry entry;
    Struct_02086f24_2 record;
    ResetFieldsStruct templates;
    SafeAllocator scriptAlloc;
#if !defined(jpn)
    unsigned char nameBuf[12];
#endif
    ItemTable items;
    unsigned char var7[20];
    unsigned int itemSize;
    unsigned int size;
    Ctx0209a8b4 ctx;

    if (heap->GetMaxPossibleAllocation() < HEAP_SIZE_02086f24) {
        return 0;
    }
    scriptAlloc.ResetAllocatorPointer();
    scriptAlloc.ResetAllocatorPointer();
    scriptAlloc.CreateTypeA(heap->Allocate(HEAP_SIZE_02086f24), HEAP_SIZE_02086f24);
    scriptAlloc.Reset();
    PresetTable_Reset(&templates);
    PresetTable_Load(&templates, &scriptAlloc, NULL);
    Struct_02086f24* t = func_02089fb0((Struct_02086f24_5*)&templates, (short)(id + 7));
    PartyMemberRecord_Init(&sel);
    int vocation = 0;
    int ok;
    if (t != NULL) {
        sel.active = 1;
        sel.count = t->count;
        sel.cursor = t->cursor;
        inline_02086f24(&sel, t->vocation);
#if defined(jpn)
        sprintf((char*)sel.name, data_020f1150, t->name);
#else
        __clear(nameBuf, sizeof(nameBuf));
        Font_EncodeText(t->name, nameBuf, 1);
        memcpy(sel.name, nameBuf, sizeof(nameBuf));
#endif
        VectorizedInvertedMemcpy(t->levels, sel.levels, sizeof(sel.levels));
        Struct_02086f24_8* look = &sel.appearance;
        VectorizedInvertedMemcpy(t->equipment, look->equipment, sizeof(look->equipment));
        look->gender = t->gender;
        look->hairStyle = t->hairStyle;
        look->hairColor = t->hairColor;
        look->face = t->face;
        look->unknown_16_ = t->unknown_a_;
        look->height = FX_F32_TO_FX16(t->height);
        look->width = FX_F32_TO_FX16(t->width);
        func_02082828(&record);
        func_02082d6c(&record, &sel);
        func_02082fc4(&record, &entry);
        BackgroundLoader::AddLockGlobal();
        itemSize = 0;
        ItemTable_Construct(&items);
        ItemTable_Init(&items);
#if defined(jpn)
        func_020e0968(g_itemDataArchive, &itemSize);
#else
        void* itemData = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &itemSize);
#endif
        for (int k = 0; k < 10; k++) {
            short equip = inline_02086f24_4(t, k);
#if defined(jpn)
            func_020def44((int)&record.equipment[data_020e8a94[k]], (int)g_fileLoadBuffer, itemSize, equip);
#else
            func_020def44((int)&record.equipment[data_020e8a94[k]], (int)itemData, itemSize, equip);
#endif
        }
        BackgroundLoader::RemoveLockGlobal();
        PartyMember_RecalculateStats(&record, 0);
        sel.unknown_14c_[0].x = record.base[0].x;
        sel.unknown_14c_[0].y = record.base[0].y;
        sel.unknown_14c_[0].z = record.base[0].z;
        sel.unknown_14c_[1].x = record.base[1].x;
        sel.unknown_14c_[1].y = record.base[1].y;
        sel.unknown_14c_[1].z = record.base[1].z;
        sel.unknown_14c_[2].x = record.base[2].x;
        sel.unknown_14c_[2].y = inline_02086f24_5(&record.profile);
        sel.unknown_14c_[3].x = inline_02086f24_5(&record.profile) & 0x3ff;
        sel.unknown_14c_[2].z = inline_02086f24_6(&record.profile);
        sel.unknown_14c_[3].y = inline_02086f24_6(&record.profile);
        sel.unknown_14c_[3].z = inline_02086f24_7(&record.profile);
        sel.timer = inline_02086f24_8(&record.profile);
        sel.unknown_15d_2_ = record.base[3].x;
        sel.skillPoints = entry.initial.value4High;
        sel.experience[t->vocation] = entry.initial.value0;
        vocation = t->vocation;
    } else {
        ok = 0;
    }
    PresetTable_Destroy(&templates);
    scriptAlloc.Reset();
    if (ok) {
        void* data = LoadFileIntoMemory(data_020f102e, g_fileLoadBuffer, &size);
        if (data != NULL) {
            func_0209a804((int*)&ctx);
            func_0209a8b4(&ctx, &scriptAlloc, (StreamHeader*)data, size);
            int count = func_0209ab20((Struct_02086f24_7*)&ctx, vocation, sel.levels[vocation], var7);
            unsigned char* p = var7;
            for (int i = 0; i < count; i++) {
                int skill = *p;
                int var23 = inline_02086f24_2(skill);
                int bit = inline_02086f24_3(skill);
                sel.unknown_111_[var23] |= 1 << bit;
                p++;
            }
        }
    }
    if (ok) {
        ok = Party_AddMemberRecord(party, &sel, 1, 0);
        party->memberCount++;
        if (party->memberCount > 4) {
            party->memberCount = 4;
        }
    }
    scriptAlloc.Destroy();
    return ok;
}
