#pragma ipa file
#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Matrix.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "Combat/Main/MessageSlotTable.h"
#include "Resource/FontBankLoader.h"
#include "World/ZoneLootableRecord.h"
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Filesystem/FileIO.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define R(j, u) (j)
#else
#define R(j, u) (u)
#endif

unsigned char* data_ov004_021707e0;
int data_ov004_021707e4;

// USA: func_ov004_021570f0
extern "C" ARM signed char func_ov004_021570f0(int idx) {
    if (idx < 0) return -1;
    char* ptr = ((char*)data_ov004_021707e0);
    short count = *(short*)(ptr + 0x3a);
    if (idx >= count) return -1;
    return (signed char)(*(short*)(ptr + idx * 2 + 0x32));
}

#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
#endif

extern "C" void* func_ov004_02156e68(void*, int);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void*);
#else
extern "C" int func_ov024_021f6f10(void*);
#endif
struct Struct_ov004_02153978;
extern "C" unsigned int func_ov023_021f6f08(struct Struct_ov004_02153978* obj);
extern "C" signed char func_ov004_021570f0(int idx);

// USA: func_ov004_02157128
extern "C" ARM signed char func_ov004_02157128(void* obj) {
    void* node = func_ov004_02156e68(obj, 0x5f);
    if (!node) {
        return (signed char)(*(short*)(data_ov004_021707e0 + 0x3c));
    }

    if (func_ov024_021f6f10(node) != 8) {
        return 0;
    }

    int idx = 0;
    unsigned int v = func_ov023_021f6f08((struct Struct_ov004_02153978*)node);
    switch (v) {
        case 0x322: idx = 0; break;
        case 0x323: idx = 1; break;
        case 0x324: idx = 2; break;
        case 0x325: idx = 3; break;
        case 0x326: idx = 4; break;
        case 0x327: return -1;
        default: break;
    }
    return func_ov004_021570f0(idx);
}

#undef func_ov024_021f6f10
#undef func_ov024_021f6f10

// USA: func_ov004_021571d8
extern "C" ARM int func_ov004_021571d8(int a) {
    if (((int)func_ov004_02156e68((void*)a, 0x65)) != 0) {
        return 1;
    }
    return 0;
}

#if defined(jpn)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#endif

extern "C" int rand(void);

struct Struct_ov004_021571f4 { int x, y, z; };

class Struct_ov004_021571f4_2 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_021571f4_8(const Struct_ov004_021571f4* v);
};

struct Struct_ov004_021571f4_3 {
    char pad0[0x1c];
    unsigned char counts[12];
    int unknown_28_;
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021fa078(void* obj, void* ctx, unsigned short val, Struct_ov004_021571f4* arg3, int p5, int p6);

// USA: func_ov004_021571f4
extern "C" ARM void func_ov004_021571f4(void* self, int total) {
    int count = total - ((Struct_ov004_021571f4_3*)data_ov004_021707e0)->unknown_28_;
    if (count == 0) return;

    for (int i = 0; i < count; i++) {
        int slot = rand() % 12;
        Struct_ov004_021571f4_3* blk = ((Struct_ov004_021571f4_3*)data_ov004_021707e0);
        while (blk->counts[slot] >= 10) {
            slot = (slot + 1) % 12;
        }
        blk->counts[slot]++;

        Struct_ov004_021571f4_3* block = ((Struct_ov004_021571f4_3*)data_ov004_021707e0);
        int n = block->counts[slot];
        int id = block->unknown_28_ + 0x578 + i;

        Struct_ov004_021571f4_2* node = ((Struct_ov004_021571f4_2*)func_ov023_021f6880((void**)(func_ov011_021849c8(self)), id));
        if (node == 0 || func_ov023_021f6f10(node) != 0) {
            node = 0;
        }
        if (!node) return;

        Struct_ov004_021571f4 pos;
        pos.x = (slot * 21) << 12;
        pos.y = (n * -19) << 12;
        pos.z = 0;
        node->inline_ov004_021571f4_8(&pos);

        Struct_ov004_021571f4 dst;
        dst.x = (slot * 21) << 12;
        dst.y = (0xc0 - n * 19) << 12;
        dst.z = 0;

        void* effect = ((Struct_ov004_021571f4_2*)func_ov023_021f6880((void**)(func_ov011_021849c8(self)), 0xffff));
        if (!effect) return;
        func_ov023_021fa078(effect, self, id, &dst, 0xd000, 0xd000);
    }
    ((Struct_ov004_021571f4_3*)data_ov004_021707e0)->unknown_28_ = total;
}

#undef data_ov015_02193d14
#undef data_ov015_02193d2c
#undef data_ov015_02193d38
#undef data_ov027_021dd8e0
#undef func_ov003_021594c4
#undef func_ov003_0215a740
#undef func_ov014_0218854c
#undef func_ov014_021885bc
#undef func_ov015_0219050c

struct Struct_02072a68 { short key; void* value; };
struct TableA68 { struct Struct_02072a68* entries; short count; };
extern "C" void* func_02072a68(struct TableA68*, int);
extern "C" int func_ov004_02157018(void*, int);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* global);
struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);

// USA: func_ov004_02157374
extern "C" ARM void func_ov004_02157374(void* obj, int key, int arg2, char* dst, unsigned char flag5) {
    if (key <= 0) return;

    struct TableA68* table = (struct TableA68*)func_ov004_02157018(obj, 4);
    int var1 = 0;
    const char* name;

    if ((key >= 0x4e20 && key <= 0x4e84) ||
        (key >= 0x4e86 && key <= 0x4e8b) ||
        (key == 0x4e8d) ||
        (key >= 0x4e8f && key <= 0x5207) ||
        (key >= 0xcb24 && key <= 0xcb29) ||
        (key >= 0xcb2d && key < 0xcb84) ||
        (key >= 0xcb88 && key <= 0xcb8d) ||
        (key >= 0xcb91 && key < 0xcbe8) ||
        (key >= 0xcbec && key <= 0xcbf1) ||
        (key >= 0xcbf5 && key < 0xccb0) ||
        (key >= 0xcf08 && key < 0xd034)) {
        name = (const char*)func_02072a68(table, 0x64);
    } else if ((key == 0x4e85) || (key >= 0x59d8 && key < 0x5dc0)) {
        name = (const char*)func_02072a68(table, 0x65);
    } else if (key == 0x4e8c) {
        name = (const char*)func_02072a68(table, 0x66);
    } else if (key == 0x4e8e) {
        name = (const char*)func_02072a68(table, 0x67);
    } else if (key >= 0xc800 && key < 0xc864) {
        name = (const char*)func_02072a68(table, 0x68);
    } else if (key >= 0xc350 && key < 0xc3b4) {
        name = (const char*)func_02072a68(table, 0x69);
    } else if ((key >= 0xc738 && key <= 0xc79e) ||
               (key >= 0xc7a0 && key < 0xc800) ||
               (key >= 0xc864 && key < 0xc8c8)) {
        name = (const char*)func_02072a68(table, 0x6a);
    } else if (key == 0xc79f) {
#if defined(jpn)
        name = (const char*)func_02072a68(table, 0x6b);
#else
        name = (const char*)func_02072a68(table, 0x6a);
#endif
    } else if ((key >= 0xcb20 && key <= 0xcb23) ||
               (key >= 0xcb2a && key <= 0xcb2c) ||
               (key >= 0xcb84 && key <= 0xcb87) ||
               (key >= 0xcb8e && key <= 0xcb90) ||
               (key >= 0xcbe8 && key <= 0xcbeb) ||
               (key >= 0xcbf2 && key <= 0xcbf4) ||
               (key >= 0xccb0 && key <= 0xccb3) ||
               (key >= 0xccba && key <= 0xccbc) ||
               (key >= 0xcd14 && key <= 0xcd17) ||
               (key >= 0xcd1e && key <= 0xcd20) ||
               (key >= 0xcddc && key <= 0xcddf) ||
               (key >= 0xcde6 && key <= 0xcde8)) {
        name = (const char*)func_02072a68(table, 0x6c);
    } else {
        var1 = 1;
#if defined(jpn)
        if (arg2 == 1) {
            name = (const char*)func_02072a68(table, 0x6d);
        }
#endif
        if (arg2 == 2) {
            name = (const char*)func_02072a68(table, 0x70);
        } else if (key >= 0x7918 && key < 0x7d00) {
            name = (const char*)func_02072a68(table, 0x6f);
        } else {
            name = (const char*)func_02072a68(table, 0x6e);
        }
    }

    if (flag5 != 0) {
        if (var1 == 0) return;
    }
    if (name == 0) return;

    void* g = (void*)MessageSystem_GetInstance();
    func_02046380(g);
    func_020465c0((struct StoreStruct*)g, 0, key);
    memcpy(dst, (void*)name, strlen(name));
}

extern "C" int func_020d4ac8(void);
extern "C" void func_ov023_021f6600(void* obj, int id, int mask);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);

// USA: func_ov004_0215781c
extern "C" ARM void func_ov004_0215781c(void* obj) {
    int state = func_020d4ac8();
    for (int i = 0; i < 4; i++) {
        if (i == state) {
            func_ov023_021f6600(obj, i + 0x29, 8);
        } else {
            func_ov023_021f65d4(obj, i + 0x29, 8);
        }
    }
}

// USA: func_ov004_02157874
extern "C" ARM void func_ov004_02157874(void* obj) {
    for (int i = 0; i < 4; i++) {
        func_ov023_021f65d4(obj, i + 0x29, 8);
    }
}

extern "C" void* func_ov004_02156fa0(void*, int);

class Struct_ov004_021578a8 {
public:
    virtual void v00(); virtual void inline_ov004_021578a8_2(); virtual void inline_ov004_021578a8_3(); virtual void inline_ov004_021578a8_4();
    virtual void v04(); virtual void inline_ov004_021578a8_6(); virtual void inline_ov004_021578a8_7();
    virtual void inline_ov004_021578a8_8(Vector3i* v);
    virtual Vector3i inline_ov004_021578a8_9();
};

// USA: func_ov004_021578a8
extern "C" ARM void func_ov004_021578a8(void* obj) {
    Vector3i vec;

    Struct_ov004_021578a8* node = (Struct_ov004_021578a8*)func_ov004_02156fa0(obj, 0x517);
    if (node) {
        vec = node->inline_ov004_021578a8_9();
        int x = (0xd1 - (data_ov004_021707e0[0x3e] << 3)) << 0xc;
        vec.x = x;
        vec.y = 0x26000;
        node->inline_ov004_021578a8_8(&vec);
    }

    Struct_ov004_021578a8* node2 = (Struct_ov004_021578a8*)func_ov004_02156fa0(obj, 0x518);
    if (node2) {
        vec = node2->inline_ov004_021578a8_9();
        int x2 = (0xd1 - (data_ov004_021707e0[0x3e] << 3)) << 0xc;
        vec.x = x2;
        vec.y = 0x34000;
        node2->inline_ov004_021578a8_8(&vec);
    }
}

struct KeyMap020a0b3c { short* keys; signed char* values; short count; };
extern "C" signed char func_020a0b3c(struct KeyMap020a0b3c* map, int key);
extern "C" int func_02086d20(unsigned char* p);
extern "C" int func_0207c7a0(void* p, int e, int c);

// USA: func_ov004_0215799c
extern "C" ARM int func_ov004_0215799c(void* a, int e, unsigned int kind, int d) {
    int result = 0;
    unsigned int flag = (kind >= 8 && kind <= 9);
    if (flag) {
        void* ptr = a;
        if (kind == 9) {
            ptr = (char*)a + 0x204 + 0xc00;
        }
        signed char val1 = func_020a0b3c((struct KeyMap020a0b3c*)ptr, e);
        int val2 = func_02086d20((unsigned char*)a);
        result = (d * 8 + 0x63) - (val1 + val2);
    } else {
        unsigned int flag2 = (kind <= 7);
        if (flag2) {
            result = 0x63 - func_0207c7a0((char*)a + 0x1d4, e, 9);
        }
    }
    return result;
}

struct ItemTable;
struct Struct_02052df8;
struct Struct_0207c484;
struct HeadNode02046b24;
struct FieldTaskQueue;

struct Struct_ov004_02157a28 {
    unsigned int category : 4;
    unsigned int unknown : 14;
    unsigned int flag : 1;
    unsigned int rest : 13;
};
struct Element_02157a28 {
    char pad0[8];
    Struct_ov004_02157a28 bits;
};
struct BattleBlk_02157a28 {
    char pad0[0xe];
    short key;
    char pad10;
    unsigned char count;
    char pad12[0x28];
    short extra;
    char unknown_3c_[0xb];
    unsigned char used;
#if defined(jpn)
    char unknown_48_[0x61];
#else
    char unknown1_48_[0x55];
#endif
    unsigned char dirty;
};

struct Struct_ov004_0216fb90 { int v[8]; };
extern Struct_ov004_0216fb90 data_ov004_0216fb90;

struct Struct_ov004_02157a28_4 {
    SafeAllocator allocator;
    char list[0x18];
    ItemTable* containerData;
    int unknown_30_;
    int field34;
};

extern "C" signed char func_ov004_02157128(void*);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_ov004_02156fd4(void*, int);
extern "C" void func_0207cc18(void*, Element_02157a28*);
extern "C" void func_02052d7c(struct Struct_02052d7c*, int, short);
extern "C" int func_0207c378(struct Struct_020732cc*, int, int, int);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" void func_ov011_021848a0(void*, int);

extern "C" struct Element020de650* ItemTable_Find(struct ItemTable*, int);
extern "C" void* ItemTable_Construct(void*);
extern "C" void func_0207cbe8(char*);
extern "C" void func_0207cc0c(char*);
extern "C" void* GameState_GetParty(struct GameState*);
extern "C" int func_02052df8(Struct_02052df8*, int);
extern "C" int func_0207c484(struct Struct_0207c484*, int, int, int);
extern "C" void func_020483f0(unsigned char*, unsigned short);
extern "C" int LinkSession_IsActive(int*);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void FieldTaskQueue_Update(FieldTaskQueue*);

// USA: func_ov004_02157a28
extern "C" ARM int func_ov004_02157a28(void* a, int flag) {
    short id = ((short)func_ov004_02157128(a));
    int* search = ((int*)LinkSession_GetInstance());
    GameState* gs = GameState::GetInstance();
    GameObject* c = func_0200ff1c(gs, id);
    if (!c) return 0;
    ItemTable* cont = (ItemTable*)((void*)func_ov004_02156fd4(a, 5));
    if (!cont) return 0;
    Element_02157a28* elem = ((Element_02157a28*)ItemTable_Find(cont, ((BattleBlk_02157a28*)data_ov004_021707e0)->key));
    if (!elem) return 0;
    int category = elem->bits.category;
    Struct_ov004_02157a28_4 context;
    context.allocator.ResetAllocatorPointer();
    ItemTable_Construct(context.list);
    func_0207cbe8((char*)&context);
    func_0207cbe8((char*)&context);
    context.containerData = cont;
    func_0207cc18(&context, elem);
    func_0207cc0c((char*)&context);

    int found = 0;
    int i;
    for (i = 0; i != 8; i++) {
        if (i == category) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    Struct_ov004_0216fb90 table = data_ov004_0216fb90;
    int slot = table.v[i];
    if (slot < 0) return 0;

    char* bag = (char*)GameState_GetParty(gs);
    int equipped = func_02052df8((Struct_02052df8*)c, slot);
    int same = ((BattleBlk_02157a28*)data_ov004_021707e0)->key == equipped;
    func_02052d7c((Struct_02052d7c*)c, slot, ((BattleBlk_02157a28*)data_ov004_021707e0)->key);
    if (((BattleBlk_02157a28*)data_ov004_021707e0)->used == 0) {
        func_0207c378((Struct_020732cc*)(bag + 0x1d4), ((BattleBlk_02157a28*)data_ov004_021707e0)->key, (signed char)(((BattleBlk_02157a28*)data_ov004_021707e0)->count - 1), category);
        ((BattleBlk_02157a28*)data_ov004_021707e0)->dirty = 0;
    } else {
        func_0207c484((Struct_0207c484*)(bag + 0x1d4), ((BattleBlk_02157a28*)data_ov004_021707e0)->key, 1, category);
    }
    ((BattleBlk_02157a28*)data_ov004_021707e0)->used++;
    if (((Element_02157a28*)ItemTable_Find(cont, equipped))) {
        func_0207c378((Struct_020732cc*)(bag + 0x1d4), equipped, 1, category);
    }
    int var15 = 0;
    BattleBlk_02157a28* blk = ((BattleBlk_02157a28*)data_ov004_021707e0);
    unsigned char level = blk->extra;
    if (blk->used < blk->count) {
        if (level >= 2) var15 = 1;
    }
    if (!same || flag) {
        int var18 = 0;
        Element_02157a28* e2 = ((Element_02157a28*)ItemTable_Find(cont, ((BattleBlk_02157a28*)data_ov004_021707e0)->key));
        if (e2 && e2->bits.flag) {
            func_020483f0((unsigned char*)c, 4);
            var18 = 1;
        }
        if (LinkSession_IsActive(search)) {
            func_ov017_021c3fb4(id, 1);
            func_ov017_021c4418(id, -1);
            if (var18) func_ov017_021c9e00(id, 0, 0, 1);
        }
        GameResources* res = GetGameResources();
        HeadNode02046b24** headA = (HeadNode02046b24**)res->unknown_ptr_array_3700[0];
        FieldTaskQueue* ctxB = (FieldTaskQueue*)res->unknown_ptr_array_3700[1];
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        func_ov017_0218f5a4(res, id, 1, 0, 0);
        while (FieldTaskQueue_GetCurrentKind(headA) == 0x13) {
            loader->RemoveAllLocks();
            FieldTaskQueue_Update((FieldTaskQueue*)headA);
            if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)ctxB) == 0x14) {
                FieldTaskQueue_Update(ctxB);
            }
        }
        if (var18) {
            if (var15) func_ov011_021848a0(a, 0x3e9);
            else func_ov011_021848a0(a, 0x3e8);
            return 0;
        }
    }
    if (var15) func_ov011_021848a0(a, 0x23bf);
    else func_ov011_021848a0(a, 0x393);
    return 0;
}

struct S_e830;
struct Struct020a9ea4;

struct Struct_ov004_02157db8 {
    char pad[0x56b];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

#if defined(jpn)
enum { Enum_ov004_021570f0_336 = 0x144 };
#else
enum { Enum_ov004_021570f0_336 = 0x150 };
#endif

struct Struct_ov004_02157db8_2 {
    char pad[Enum_ov004_021570f0_336];
    struct Struct_ov004_02157db8* f150;
};

struct Struct_ov004_02157db8_3 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};

struct Blk_02157db8 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned short unknown_c_;
    short unknown_e_;
    unsigned char b10;
    unsigned char unknown_11_;
    signed char unknown_12_;
    unsigned char unknown_13_;
    unsigned char b14;
    unsigned char unknown_15_;
    unsigned char pad16[2];
    Struct_ov004_02157db8_3 unknown_18_;
    unsigned char unknown_1c_[0xc];
    unsigned int unknown_28_;
    unsigned char unknown_2c_;
    unsigned char b2d;
    unsigned char unknown_2e_;
    unsigned char unknown_2f_;
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    signed short unknown_32_[6];
    unsigned char unknown_3e_;
    unsigned char unknown_3f_[7];
    unsigned char unknown_46_;
    unsigned char unknown_47_;
    unsigned char unknown_48_[0x24];
    short unknown_6c_;
    unsigned char unknown_6e_;
    unsigned char unknown_6f_;
    signed char unknown_70_;
    unsigned char unknown_71_[3];
    unsigned int unknown_74_;
    unsigned int unknown_78_;
    unsigned char unknown_7c_[8];
    unsigned char pad84[8];
#if defined(jpn)
    unsigned char pad8c[0x18];
#else
    unsigned char pad8c[0xc];
#endif
    unsigned int unknown_98_;
    unsigned char b9c;
    unsigned char unknown_9d_;
    unsigned char unknown_9e_[2];
#if !defined(jpn)
    unsigned char padA0[0xc];
    unsigned char padAC[0xc];
#endif
};

#if defined(jpn)
enum { Enum_ov004_02157db8_620 = 0xc, Enum_ov004_02157db8_9088 = 0x120, Enum_ov004_02157db8_16384 = 0x6000, stateOffset = 0x8c };
#else
enum { Enum_ov004_02157db8_620 = 0x26c, Enum_ov004_02157db8_9088 = 0x2380, Enum_ov004_02157db8_16384 = 0x4000, stateOffset = 0x6c };
#endif

extern char g_bgmPlayer[];

extern "C" void* func_ov011_021845f8(unsigned char*, unsigned int);
extern "C" void func_020a9ea4(struct Struct020a9ea4*);
#if defined(jpn)
struct Struct020dfc40;
extern "C" void KeyTable_Reset(struct Struct020dfc40*);
#else
extern "C" void func_020e526c(void*);
#endif
extern "C" void NameText_Clear(void*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" unsigned short func_0201e830(struct S_e830* p);
extern "C" void Set3DClearColor(int, int, int, int, int);
extern "C" void func_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" void func_ov023_021f5598(void*);
extern "C" void func_020cf0fc(int);
extern "C" void RTC_GetTime(int);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" unsigned char func_0209ca98(char*);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" unsigned char GameState_GetOwnPartyOrder(char*, void*);

// USA: func_ov004_02157db8
extern "C" ARM int func_ov004_02157db8(void* a) {
    GameState* bs = GameState::GetInstance();
    unsigned char* var1 = (unsigned char*)bs + Enum_ov004_02157db8_620;
    unsigned char* var2 = (unsigned char*)bs + Enum_ov004_02157db8_9088;
    unsigned char* var3 = var1 + 0x5c00;
    unsigned char* var4 = var2 + Enum_ov004_02157db8_16384;

    ((Blk_02157db8*)data_ov004_021707e0) = 0;
    void* ctx = func_ov011_021845f8((unsigned char*)a, 0);
    if (!ctx) return 0;
    SafeAllocator* alloc = (SafeAllocator*)((char*)ctx + 4);
    Blk_02157db8* blk = (Blk_02157db8*)alloc->Allocate(sizeof(Blk_02157db8));
    ((Blk_02157db8*)data_ov004_021707e0) = blk;
    if (!blk) return 0;

    blk->unknown_0_ = 0;
    blk->unknown_4_ = 0;
    blk->unknown_8_ = 0;
    blk->unknown_c_ = 0x3def;
    int var8 = -1;
    blk->unknown_e_ = var8;
    blk->b10 = 0;
    blk->unknown_11_ = 1;
    blk->unknown_12_ = var8;
    blk->unknown_13_ = 0;
    blk->b14 = 0;
    blk->unknown_15_ = 0;
    memset(&blk->unknown_18_, 0, 4);
    memset(blk->unknown_1c_, 0, 0xc);
    blk->unknown_28_ = 0;
    blk->unknown_2c_ = 0;
    blk->b2d = 5;
    blk->unknown_2e_ = 5;
    blk->unknown_46_ = 0;
    blk->unknown_47_ = 0;
    blk->unknown_2f_ = 0;
    blk->unknown_30_ = 0;
    blk->unknown_31_ = 0;
    blk->unknown_3e_ = 0;
    memset(blk->unknown_3f_, 0, 7);
    unsigned char* mp = blk->unknown_7c_;
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 4;
    mp[3] = 2;
    mp[4] = 5;
    mp[5] = 3;
    mp[6] = 6;
    mp[7] = 7;
    int var10 = -1;
    blk->unknown_6c_ = var10;
    blk->unknown_6e_ = 0;
    blk->unknown_6f_ = 0;
    blk->unknown_70_ = var10;
    blk->unknown_74_ = var10;
    blk->unknown_78_ = 0;
    func_020a9ea4((struct Struct020a9ea4*)blk->pad84);
#if defined(jpn)
    KeyTable_Reset((struct Struct020dfc40*)blk->pad8c);
    blk->unknown_98_ = 0;
    blk->b9c = 0;
    blk->unknown_9d_ = 0;
#else
    func_020e526c(blk->pad8c);
    blk->unknown_98_ = 0;
    blk->b9c = 0;
    blk->unknown_9d_ = 0;
    NameText_Clear(blk->padA0);
    NameText_Clear(blk->padAC);
#endif

    void* v = Zone3D_GetInstance();
    if (!v) return 0;
    void* p = (char*)v + stateOffset;
    if (!p) return 0;
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_c_ = func_0201e830((struct S_e830*)p);

    unsigned int* obj = (unsigned int*)GetGameResources();
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_0_ = GetFlags00((GameResources*)obj);
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_4_ = GetFlags04((GameResources*)obj);
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_8_ = GetFlags08((GameResources*)obj);
    SetFlags00((GameResources*)obj, 4);
    SetFlags04((GameResources*)obj, 0x8de);

    int pad0 = 0;
    Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
    func_020c54a4(0, 0, 0, 0);

    void* d = ((void*)func_ov004_02156fd4(a, 5));
    if (d != 0) {
        func_ov023_021f5598(d);
    }
    int var16[4];
    int slotB[3];
    func_020cf0fc((int)var16);
    RTC_GetTime((int)slotB);

    ((Blk_02157db8*)data_ov004_021707e0)->unknown_18_.unknown_0_0_ = var16[0] + 0x7d0;
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_18_.unknown_1_4_ = var16[1];
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_18_.unknown_2_0_ = var16[2];
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_18_.unknown_2_5_ = slotB[0];
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_18_.unknown_3_2_ = slotB[1];

    GameObject_DisableControl((Obj020397cc*)bs->GetLeader(), 1);
    ((Blk_02157db8*)data_ov004_021707e0)->b2d = func_0209ca98(g_bgmPlayer);
    unsigned int var18 = *(unsigned int*)(var4 + 0x50);
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_2f_ = (var18 & 1) ? 1 : 0;
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xf);

    short* var19 = (short*)(var3 + 4);
    for (int i = 0; i < 6; ) {
        if (*var19 > 0) {
            ((Blk_02157db8*)data_ov004_021707e0)->unknown_46_++;
        }
        i++;
        var19 = (short*)((char*)var19 + 0x28);
    }

    void* var21 = func_ov011_021845f8((unsigned char*)a, 9);
    if (!var21) return 0;
    SafeAllocator* var22 = (SafeAllocator*)((char*)var21 + 4);
#if defined(jpn)
    void* big = var22->Allocate(0x8000);
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_98_ = (unsigned int)big;
#else
    void* big = var22->Allocate(0x10800);
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_98_ = (unsigned int)big;
    memset((void*)((Blk_02157db8*)data_ov004_021707e0)->unknown_98_, 0, 0x10800);
#endif

    unsigned char ids[4];
    unsigned char count = GameState_GetOwnPartyOrder((char*)bs, ids);
    for (int i = 0; i < count; i++) {
        ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[i] = ids[i];
    }
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[4] = count;

    for (int i = 0; i < ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[4]; i++) {
        void* combatant = (void*)func_0200ff1c(bs, ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[i]);
        if (combatant != 0) {
            struct Struct_ov004_02157db8* field150 = ((struct Struct_ov004_02157db8_2*)combatant)->f150;
            int flag;
            if (field150 != 0) {
                flag = field150->lo != 0;
            } else {
                flag = 0;
            }
            if (flag != 0) {
                int j = i;
                while (j < ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[4]) {
                    ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[j] = ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[j + 1];
                    ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[j + 1] = -1;
                    j++;
                }
                ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[4] = ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[4] - 1;
            }
        }
    }
    ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[5] = ((Blk_02157db8*)data_ov004_021707e0)->unknown_32_[0];
    return 0;
}

#if defined(jpn)
enum { Enum_ov004_02158298_108 = 0x8c, Enum_ov004_02158298_620 = 0xc, Enum_ov004_02158298_14096 = 0x3500 };
#else
enum { Enum_ov004_02158298_108 = 0x6c, Enum_ov004_02158298_620 = 0x26c, Enum_ov004_02158298_14096 = 0x3710 };
#endif

struct Struct_0201e828;
extern "C" void func_0201e828(Struct_0201e828*, unsigned short);

extern "C" void GameObject_EnableControl(void* obj);

extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

struct Struct_ov004_02158298 { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int unknown_8_; unsigned short unknown_c_; };

struct Struct_ov004_02158298_2 { char pad[0xc]; unsigned short unknown_c_0_ : 13; unsigned short unknown_d_5_ : 3; };
struct Struct_ov004_02158298_3 { char pad[0x5d00]; struct Struct_ov004_02158298_2 area; };

// USA: func_ov004_02158298
extern "C" ARM int func_ov004_02158298(void) {
    GameState* battle = GameState::GetInstance();
    unsigned int* word = (unsigned int*)((int)GetGameResources());
    ClearFlags00((GameResources*)word, ~0);
    ClearFlags04((GameResources*)word, ~0);
    ClearFlags08((GameResources*)word, ~0);
    SetFlags00((GameResources*)word, ((Struct_ov004_02158298*)data_ov004_021707e0)->unknown_0_);
    SetFlags04((GameResources*)word, ((Struct_ov004_02158298*)data_ov004_021707e0)->unknown_4_);
    SetFlags08((GameResources*)word, ((Struct_ov004_02158298*)data_ov004_021707e0)->unknown_8_);

    void* p = Zone3D_GetInstance();
    if (!p) return 0;
    p = (char*)p + Enum_ov004_02158298_108;
    if (!p) return 0;
    func_0201e828((struct Struct_0201e828*)p, ((Struct_ov004_02158298*)data_ov004_021707e0)->unknown_c_);

    GameObject_EnableControl(battle->GetLeader());

    struct Struct_ov004_02158298_3* outer = (struct Struct_ov004_02158298_3*)((char*)battle + Enum_ov004_02158298_620);
    outer->area.unknown_c_0_ &= ~0x20;

    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);

    unsigned char* p2 = *(unsigned char**)((char*)word + Enum_ov004_02158298_14096);
    if (p2[2] != 0) {
        p2[0x139] = 1;
    }
    return 0;
}

#if defined(jpn)
enum { Enum_ov004_021583a8_14076 = 0x34ec, Enum_ov004_021583a8_15176 = 0x3928, Enum_ov004_021583a8_17556 = 0x41e4 };
enum { Enum_ov004_021583a8_92 = 0x28, Enum_ov004_021583a8_2400 = 0x800, Enum_ov004_021583a8_2456 = 0x868 };
#else
enum { Enum_ov004_021583a8_14076 = 0x36fc, Enum_ov004_021583a8_15176 = 0x3b48, Enum_ov004_021583a8_17556 = 0x4494 };
enum { Enum_ov004_021583a8_92 = 0x5c, Enum_ov004_021583a8_2400 = 0x960, Enum_ov004_021583a8_2456 = 0x998 };
#endif

struct Struct_ov004_021583a8_6;
struct Struct_ov004_021583a8_7 {
    char pad0[0x13];
    unsigned char unknown_13_;
    unsigned char f14;
    char pad1[0x1c - 0x15];
    char f1c[12];
    int f28;
};
struct Obj5 {
    char pad0[Enum_ov004_021583a8_92];
    char* buf;
    char pad1[Enum_ov004_021583a8_2456 - Enum_ov004_021583a8_92 - 4];
    int unknown_998_;
    char pad2[4];
    int unknown_9a0_;
};

extern "C" void* FieldTask_ConnectWifi(void*, int);
extern "C" void func_ov004_02157374(void*, int, int, char*, unsigned char);
extern "C" void func_ov004_021571f4(void*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
extern "C" char* strstr(const char*, const char*);
extern "C" unsigned int strlen(const char*);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void* memset(void*, int, unsigned int);
struct TableA68;
extern "C" void func_ov004_0215781c(void*);
struct Struct_ov004_021583a8_2;
extern "C" int func_ov017_021b1ffc(Struct_ov004_021583a8_2*);
struct Struct_ov004_021583a8_3;
extern "C" unsigned char func_ov017_021b2010(struct Struct_ov004_021583a8_3*);
extern "C" int func_ov017_021b1fd4(void*);
struct Struct_ov004_021583a8_4;
extern "C" unsigned char func_ov017_021b2024(struct Struct_ov004_021583a8_4*);
struct Struct_ov004_021583a8_5;
extern "C" unsigned char func_ov017_021b2038(struct Struct_ov004_021583a8_5*);
extern "C" void func_ov004_02157874(void*);
struct Struct_ov004_021583a8;
extern "C" unsigned char func_ov017_021b1fe8(struct Struct_ov004_021583a8*);
extern "C" void func_020ac4c0(void*);
struct Struct_020a059c;
extern "C" void func_020a059c(Struct_020a059c*, unsigned int);
extern "C" void func_020ac494(void*);
extern "C" void func_ov011_02184be0(void*, int, int);

// USA: func_ov004_021583a8
extern "C" ARM int func_ov004_021583a8(void* self) {
    static unsigned char sShown3;
    static unsigned char sShown2;
    static unsigned char sShown4;
    static unsigned char sShown0;
    static unsigned char sShown1;
    GameState* game = GameState::GetInstance();
    Struct_ov004_021583a8_6* ctx = (Struct_ov004_021583a8_6*)GetGameResources();
    TableA68* table;
    Obj5* o;
    int count;
    char* buf;
    int adj;
    void* sub;
    adj = *(int*)((char*)ctx + Enum_ov004_021583a8_14076);
    sub = *(void**)((char*)ctx + Enum_ov004_021583a8_15176);
    table = ((TableA68*)func_ov004_02157018(self, 4));
    o = (Obj5*)((void*)MessageSystem_GetInstance());
    int state = ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->unknown_13_;
    if (state == 2) {
        func_ov004_0215781c(self);
        count = func_ov017_021b1ffc((Struct_ov004_021583a8_2*)sub);
        int kind = ((int)func_ov017_021b2010((Struct_ov004_021583a8_3*)sub));
        if (count > 0 && sShown4 == 0) {
            if (sShown3 == 0) {
                buf = o->buf;
                memset(buf, 0, Enum_ov004_021583a8_2400);
                func_ov004_02157374(self, count, kind, buf, (int)1);
                if (buf[0] != 0) {
#if defined(jpn)
                    func_0204500c(o, buf, 0);
#else
                    if (buf == strstr(buf, "<PAGE>")) {
                        buf += 6;
                    }
                    func_0204500c(o, buf, 0, 0xe3);
#endif
                    o->unknown_998_ = 1;
                    sShown3 = 1;
                }
            } else {
                if (o->unknown_9a0_ != 0) {
                    return 1;
                }
                sShown4 = 1;
            }
        }
        FieldTask_ConnectWifi(sub, adj);
        int v = func_ov017_021b1fd4(sub) >> 12;
        if (sShown4 == 0) {
            func_ov004_021571f4(self, v);
        }
        int var11 = ((int)func_ov017_021b2024((Struct_ov004_021583a8_4*)sub));
        int var12 = ((int)func_ov017_021b2038((Struct_ov004_021583a8_5*)sub));
        if (sShown2 == 0 && var11 == 4 && var12 == 0) {
#if defined(jpn)
            func_0204500c(o, ((char*)func_02072a68(table, 0x2e)), 0);
#else
            func_0204500c(o, ((char*)func_02072a68(table, 0x2e)), 0, 0xe3);
#endif
            o->unknown_998_ = 1;
            sShown2 = 1;
        }
        if (sShown0 == 0) {
            if ((var11 == 4 && var12 == 5) || (sShown4 != 0 && count > 0)) {
#if defined(jpn)
                if (sShown4 == 0) {
                    func_0204500c(o, ((char*)func_02072a68(table, 0x25)), 0);
                } else {
                    func_0204500c(o, ((char*)func_02072a68(table, 0x33)), 0);
                }
#else
                if (sShown4 == 0) {
                    func_0204500c(o, ((char*)func_02072a68(table, 0x25)), 0, 0xe3);
                } else {
                    func_0204500c(o, ((char*)func_02072a68(table, 0x33)), 0, 0xe3);
                }
#endif
                o->unknown_998_ = 1;
                sShown0 = 1;
            }
        }
        if (*(int*)((char*)ctx + Enum_ov004_021583a8_17556) == 0) {
            ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->unknown_13_++;
            game = GameState::GetInstance();
            GameObject_DisableControl((Obj020397cc*)game->GetLeader(), 1);
        }
    } else if (state == 3) {
        if (o->unknown_9a0_ != 3) {
            return 1;
        }
        func_ov004_02157874(self);
        char* buf = o->buf;
        memset(buf, 0, Enum_ov004_021583a8_2400);
        char* entry = 0;
        int flags = ((int)func_ov017_021b1fe8((Struct_ov004_021583a8*)sub));
        if (flags & 1) {
            unsigned char tmp[0xb0];
            func_020ac4c0(tmp);
            func_020a059c((Struct_020a059c*)tmp, 1);
            func_020ac494(tmp);
            char* e = ((char*)func_02072a68(table, 0x26));
            memcpy(buf, e, strlen(e));
            ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->f14 = 1;
            func_ov011_021848a0(self, 0x3af);
        } else {
#if defined(jpn)
            if (flags & 0x80) {
                entry = ((char*)func_02072a68(table, 0x35));
            } else if (sShown2 == 0) {
                entry = ((char*)func_02072a68(table, 0x15));
            } else {
                entry = ((char*)func_02072a68(table, 0x2f));
            }
            int len = strlen(entry);
            memcpy(buf, entry, len);
            buf += len;
#else
            if (flags & 0x80) {
                entry = ((char*)func_02072a68(table, 0x35));
            } else if (sShown2 != 0) {
                entry = ((char*)func_02072a68(table, 0x2f));
            }
            if (entry != 0) {
                int len = strlen(entry);
                memcpy(buf, entry, len);
                buf += len;
            }
#endif
            if (sShown4 == 0) {
                int w = func_ov017_021b1ffc((Struct_ov004_021583a8_2*)sub);
                int b = ((int)func_ov017_021b2010((Struct_ov004_021583a8_3*)sub));
                func_ov004_02157374(self, w, b, buf, (int)0);
                buf += strlen(buf);
            }
            char* e = ((char*)func_02072a68(table, 0x27));
            memcpy(buf, e, strlen(e));
            func_ov011_02184be0(self, 0x47, 0x46);
            ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->f14 = 0;
        }
#if defined(jpn)
        func_0204500c(o, o->buf, 0);
#else
        char* msg = o->buf;
        if (msg == strstr(msg, "<PAGE>")) {
            msg += 6;
        }
        func_0204500c(o, msg, 0, 0xe3);
#endif
        o->unknown_998_ = 1;
        *((unsigned char*)sub + 1) = 1;
        ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->unknown_13_ = 0;
        Struct_ov004_021583a8_7* inner = ((Struct_ov004_021583a8_7*)data_ov004_021707e0);
        memset(inner->f1c, 0, 12);
        inner->f28 = 0;
        return 0;
    }
    return 1;
}

#if defined(jpn)
enum { listOffset = 0x4ec, Enum_ov004_0215883c_2888 = 0x928, Enum_ov004_0215883c_1172 = 0x1e4 };
#else
enum { listOffset = 0x6fc, Enum_ov004_0215883c_2888 = 0xb48, Enum_ov004_0215883c_1172 = 0x494 };
#endif

extern "C" int func_ov017_021b1d44(unsigned char*, int, int);
struct Struct_ov004_0215883c_4;
extern "C" unsigned char func_ov017_021b2060(Struct_ov004_0215883c_4* obj);
struct Struct_ov004_0215883c_3;
extern "C" unsigned char func_ov017_021b204c(Struct_ov004_0215883c_3* obj);
struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
struct Struct_ov004_0215883c_2 { char pad[0xb4]; int fieldB4; };
extern "C" int func_ov011_02184548(struct Struct_ov004_0215883c_2* obj);
struct Obj_02184540 { char pad[0xb0]; int fieldB0; };
extern "C" int func_ov011_02184540(struct Obj_02184540* obj);

// USA: func_ov004_0215883c
extern "C" ARM int func_ov004_0215883c(void* a) {
    void* var0 = GetGameResources();
    void* list = *(void**)((char*)var0 + 0x3000 + listOffset);
    unsigned char flag = data_ov004_021707e0[0x13];
    void* five = *(void**)((char*)var0 + 0x3000 + Enum_ov004_0215883c_2888);

    if (flag != 0) goto notZero;
    {
        void* obj2 = func_ov011_021845f8((unsigned char*)a, (int)1);
        if (!obj2) {
            func_ov011_021848a0(a, 0x395);
            data_ov004_021707e0[0x13] = 0;
            return 0;
        }
        if (!((void*)func_ov017_021b1d44((unsigned char*)five, 1, 1))) {
            func_ov011_021848a0(a, 0x3ac);
            data_ov004_021707e0[0x13] = 0;
            return 0;
        }
        int state = 0x12;
        data_ov004_021707e4 = state;
        BgmPlayer_FadeOut((Actor0209c678*)g_bgmPlayer, state);
        *(void**)((char*)five + 8) = (char*)obj2 + 4;
        int fieldB4 = func_ov011_02184548((struct Struct_ov004_0215883c_2*)a);
        int fieldB0 = func_ov011_02184540((struct Obj_02184540*)a);
        *(int*)((char*)five + 0x34) = fieldB0;
        *(int*)((char*)five + 0x38) = fieldB4;
        data_ov004_021707e0[0x13]++;
        goto retTrue;
    }
notZero:
    if (flag == 1) {
        int counter = data_ov004_021707e4 - 1;
        data_ov004_021707e4 = counter;
        if (counter > 0) return 1;

        FieldTask_ConnectWifi(five, (int)list);
        if (!func_ov017_021b2060((Struct_ov004_0215883c_4*)five)) goto retTrue;
        if (func_ov017_021b204c((Struct_ov004_0215883c_3*)five)) {
            if (*(int*)((char*)var0 + 0x4000 + Enum_ov004_0215883c_1172) == 0) {
                func_ov011_021848a0(a, 0x233d);
                return 0;
            }
        }
        if (func_ov017_021b204c((Struct_ov004_0215883c_3*)five)) goto retTrue;
        data_ov004_021707e0[0x13]++;
        func_ov011_021848a0(a, 0x385);
        return 0;
    }
retTrue:
    return 1;
}

struct Struct_ov004_021589e8 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int top : 6;
};

extern "C" int func_ov017_021b213c(Struct_ov004_021589e8 a, Struct_ov004_021589e8 b);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_ov023_021f65d4(void* obj, int a, int b);

// USA: func_ov004_021589e8
extern "C" ARM int func_ov004_021589e8(void* obj) {
    char* battle = (char*)GameState::GetInstance() + R(0xc, 0x26c) + 0x5c00;
    Struct_ov004_021589e8 a = *(Struct_ov004_021589e8*)(battle + 0xf4);
    Struct_ov004_021589e8 b = *(Struct_ov004_021589e8*)(data_ov004_021707e0 + 0x18);
    if (func_ov017_021b213c(a, b) != 0) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        func_ov011_021848a0(obj, 0x387);
    } else {
        func_ov011_021848a0(obj, 0x3a2);
    }
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}

#if defined(jpn)
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

extern "C" void func_02046380(void* g);
struct Element020de650;
extern "C" void* func_020e5294(void*, int);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int LinkSession_IsActive(int* obj);

struct Struct_ov004_02158a60 {
    unsigned char unknown_0_[0xf8];
    short itemId;
    unsigned short unknown_fa_;
    unsigned char unknown_fc_[0x10];
    unsigned short flags : 13;
    unsigned short unknown_10d_5_ : 3;
    unsigned char unknown_10e_[2];
};

struct Struct_ov004_02158a60_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x5c0c];
#else
    unsigned char unknown1_0_[0x5e6c];
#endif
    Struct_ov004_02158a60 downloaded;
};

// USA: func_ov004_02158a60
extern "C" ARM int func_ov004_02158a60(void* obj) {
    Struct_ov004_02158a60* downloaded = &((Struct_ov004_02158a60_2*)GameState::GetInstance())->downloaded;
    short a = downloaded->itemId;
    if (a > 0 || downloaded->unknown_fa_ != 0) {
        void* g = (void*)MessageSystem_GetInstance();
        func_02046380(g);
        struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
        struct Element020de650* elem = ItemTable_Find(node, downloaded->itemId);
#if defined(jpn)
        char name[80];
        func_020e207c((Container020e0310*)(((char*)data_ov004_021707e0) + 0x8c), name, *(short*)((char*)elem + 0x18));
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        int val = ((int)func_020e5294(((char*)data_ov004_021707e0) + 0x8c, *(short*)((char*)elem + 0x18)));
        *(int*)((char*)g + 0x18) = val;
#endif
        func_ov011_021848a0(obj, 0x3a3);
        return 0;
    }

    void* s = LinkSession_GetInstance();
    if (LinkSession_IsGuest(s) != 0) {
        func_ov011_021848a0(obj, 0x3ae);
        return 0;
    }
    if (LinkSession_IsActive((int*)s) != 0) {
        func_ov011_021848a0(obj, 0x24cd);
        return 0;
    }
    if (downloaded->flags & 0x10) {
        func_ov011_021848a0(obj, 0x3a6);
        return 0;
    }
    func_ov011_021848a0(obj, 0x3b0);
    return 0;
}

struct Field2a04_02158b78 { char pad[0xf6c]; int unknown_f6c_; };
extern "C" void* func_ov004_02156f38(void*, int);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" int func_ov023_021f809c(void*, void*);

class Struct_ov004_02158b78_2 {
public:
    virtual void v00(); virtual void inline_ov004_02158b78_2(); virtual void inline_ov004_02158b78_3(); virtual void inline_ov004_02158b78_4();
    virtual void v04(); virtual void inline_ov004_02158b78_6(); virtual void inline_ov004_02158b78_7(); virtual void inline_ov004_02158b78_8();
    virtual void v08(); virtual void inline_ov004_02158b78_10(); virtual void v10(); virtual void inline_ov004_02158b78_12();
    virtual void inline_ov004_02158b78_13(); virtual void inline_ov004_02158b78_14(); virtual void v14(); virtual void inline_ov004_02158b78_16();
    virtual void inline_ov004_02158b78_17(); virtual void inline_ov004_02158b78_18(); virtual void v18(); virtual void inline_ov004_02158b78_20();
    virtual void v20(); virtual void inline_ov004_02158b78_22(); virtual void inline_ov004_02158b78_23(); virtual void inline_ov004_02158b78_24();
    virtual void v24(); virtual void inline_ov004_02158b78_26(); virtual void inline_ov004_02158b78_27(); virtual void inline_ov004_02158b78_28();
    virtual void v28(); virtual void inline_ov004_02158b78_30(); virtual void v30(); virtual void inline_ov004_02158b78_32();
    virtual void inline_ov004_02158b78_33(); virtual void inline_ov004_02158b78_34(); virtual void v34(); virtual void inline_ov004_02158b78_36();
    virtual void inline_ov004_02158b78_37(); virtual void inline_ov004_02158b78_38(); virtual void v38(); virtual void inline_ov004_02158b78_40();
    virtual void v40(); virtual void inline_ov004_02158b78_42(); virtual void inline_ov004_02158b78_43(); virtual void inline_ov004_02158b78_44();
    virtual void v44(); virtual void inline_ov004_02158b78_46(); virtual void inline_ov004_02158b78_47(); virtual void inline_ov004_02158b78_48();
    virtual void v48(); virtual void inline_ov004_02158b78_50(); virtual void v50(); virtual void inline_ov004_02158b78_52();
    virtual void inline_ov004_02158b78_53(); virtual void inline_ov004_02158b78_54(); virtual void v54(); virtual void inline_ov004_02158b78_56();
    virtual void inline_ov004_02158b78_57(int a);
};

// USA: func_ov004_02158b78
extern "C" ARM int func_ov004_02158b78(void* self) {
    Struct_ov004_02158b78_2* node = (Struct_ov004_02158b78_2*)func_ov004_02156f38(self, 0xc9);
    if (node) {
        struct Field2a04_02158b78* fld = (struct Field2a04_02158b78*)GameState_GetParty(GameState::GetInstance());
        node->inline_ov004_02158b78_57(fld->unknown_f6c_);
        void* x = func_ov004_02156f6c(self, 0x16);
        if (x) func_ov023_021f809c(x, self);
    }
    return 0;
}

extern "C" int func_ov004_02156e2c(void* a, int key);
extern "C" void* func_ov004_021570a4(void*, int);
extern "C" void* func_ov004_02157054(void*, int);

struct Struct_ov004_02158bd4;
extern "C" void func_ov023_021fbdf4(Struct_ov004_02158bd4*, int);
extern "C" void func_ov023_021fbdcc(void*, int);
struct Element020de650 { unsigned int v[8]; };
extern "C" void func_ov023_021f6eb8(void* obj, int idx);
extern "C" int func_ov004_0215d738(void*);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" int func_ov004_0215cec4(void*);
extern "C" int func_ov004_0215d384(void* a);
extern "C" void func_ov023_021f6e90(char* obj, int idx, const void* src);

struct Struct_ov004_02158bd4_2 { char pad[8]; unsigned int nibble : 4; };

// USA: func_ov004_02158bd4
extern "C" ARM int func_ov004_02158bd4(void* obj) {
    int var0 = func_ov004_02156e2c(obj, 0x5b);
    if (var0 < 0) return 0;
    void* entry = func_ov004_021570a4(obj, (unsigned char)var0);
    if (!entry) return 0;

    void* node2 = func_ov004_02156f6c(obj, 0x15);
    if (node2) {
        func_ov023_021f809c(node2, obj);
    }

    void* var3 = func_ov004_02157054(obj, 7);
    if (var3) {
#if defined(jpn)
        if (data_ov004_021707e0[0xa8] == 0) {
#else
        if (data_ov004_021707e0[0x9c] == 0) {
#endif
            func_ov023_021fbdf4((Struct_ov004_02158bd4*)var3, -1);
#if defined(jpn)
            data_ov004_021707e0[0xa8] = 1;
#else
            data_ov004_021707e0[0x9c] = 1;
#endif
        }
        func_ov023_021fbdcc(var3, *(short*)((char*)entry + 0));
    }

    void* container = (void*)func_ov004_02156fd4(obj, 5);
    if (!container) return 0;
    Element020de650* elem = ItemTable_Find((ItemTable*)container, *(short*)((char*)entry + 0));
    if (!elem) return 0;

    void* thing = func_ov011_021849c8(obj);
    func_ov023_021f6eb8(thing, 0);

    char buf[0x16];
    VectorizedMemset(buf, 0, 0x16);
    *(short*)(buf + 0x14) = -1;
    *(short*)(buf + 0x12) = 0x384;

    int nibble = ((Struct_ov004_02158bd4_2*)elem)->nibble;
    switch (nibble) {
        case 8:
        case 9:
            func_ov004_0215d738(obj);
            func_ov023_021f65d4(obj, 0x17, 8);
            func_ov023_021f65d4(obj, 0x1b, 8);
            func_ov023_021f6600(obj, 0x1c, 8);
            buf[0] = 3;
            *(short*)(buf + 2) = 0x15;
            *(short*)(buf + 4) = 0x1c;
            *(short*)(buf + 6) = 0x16;
            break;
        default:
            func_ov004_0215cec4(obj);
            func_ov004_0215d384(obj);
            func_ov023_021f6600(obj, 0x17, 8);
            func_ov023_021f6600(obj, 0x1b, 8);
            func_ov023_021f65d4(obj, 0x1c, 8);
            buf[0] = 4;
            *(short*)(buf + 2) = 0x15;
            *(short*)(buf + 4) = 0x17;
            *(short*)(buf + 6) = 0x1b;
            *(short*)(buf + 8) = 0x16;
            break;
    }

    func_ov023_021f6e90((char*)thing, 0, buf);
    return 0;
}

struct Struct_ov004_02158dcc_2 {
    char unknown_0_[0xe];
    short unknown_e_;
    char pad10;
    unsigned char count;
    signed char unknown_12_;
    char unknown_13_[0x1e];
    unsigned char unknown_31_;
    char unknown_32_[0x8];
    short level;
    char unknown_3c_[0xb];
    unsigned char unknown_47_;
    char unknown_48_[0x44];
    unsigned char table[1];
};

struct Struct_ov004_02158dcc_3 {
    short id;
    short pad2;
    unsigned int count : 7;
    unsigned int unknown_4_7_ : 25;
};

struct Element02158dcc {
    char pad[8];
    unsigned int kind : 4;
    char unknown_9_[0xc];
    short nameId;
};

struct Wallet02158dcc {
    char pad[0xf6c];
    unsigned int unknown_f6c_;
};

struct Message02158dcc {
    char pad[0x18];
    int name;
};

struct Struct_ov004_02158dcc_7 {
    char pad[0x2c];
    Vector3i pos;
};
struct Struct_ov004_02158dcc;
#if defined(jpn)
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#else
extern "C" void* func_020e5294(void*, int);
#endif

extern "C" int func_ov004_0215799c(void*, int, unsigned int, int);
extern "C" void func_ov011_021849e0(struct Struct_ov004_02158dcc* obj, unsigned short val);
extern "C" int func_ov004_0215d6f8(void*);
extern "C" void* func_ov004_02156ed0(void*, int);
extern "C" void* __clear(void*, int);

// USA: func_ov004_02158dcc
extern "C" ARM int func_ov004_02158dcc(void* obj) {
    int key = func_ov004_02156e2c(obj, 0x5b);
    if (key < 0) return 0;
    Struct_ov004_02158dcc_3* entry = ((Struct_ov004_02158dcc_3*)func_ov004_021570a4(obj, (unsigned char)key));
    if (!entry) return 0;
    Element02158dcc* elem = ((Element02158dcc*)ItemTable_Find(((struct ItemTable*)func_ov004_02156fd4(obj, 5)), entry->id));
    if (!elem) return 0;
#if defined(jpn)
    char name[80];
    func_020e207c((Container020e0310*)(((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->table), name, elem->nameId);
    MessageSystem_SetStringArgument((Obj02046574*)((Message02158dcc*)MessageSystem_GetInstance()), 1, name);
#else
    int name = ((int)func_020e5294(((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->table, elem->nameId));
    ((Message02158dcc*)MessageSystem_GetInstance())->name = name;
#endif
    if (entry->count == 0) return 0;

    Wallet02158dcc* wallet = (Wallet02158dcc*)GameState_GetParty(GameState::GetInstance());
    if (func_ov004_0215799c(wallet, entry->id, elem->kind, ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->level) == 0) {
        func_ov011_021849e0((struct Struct_ov004_02158dcc*)obj, 0);
        func_ov011_021848a0(obj, 0x236b);
        return 0;
    }
    if (wallet->unknown_f6c_ < entry->unknown_4_7_) {
        func_ov011_021849e0((struct Struct_ov004_02158dcc*)obj, 0);
        func_ov011_021848a0(obj, 0x2365);
        return 0;
    }

    func_ov011_021848a0(obj, 0x5e);
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_e_ = entry->id;
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->count = 1;
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_12_ = -1;
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_47_ = 0;
    if (entry->count == 1 || (entry->unknown_4_7_ <= wallet->unknown_f6c_ && wallet->unknown_f6c_ < entry->unknown_4_7_ * 2)) {
        func_ov011_021849e0((struct Struct_ov004_02158dcc*)obj, 0);
        func_ov004_0215d6f8(obj);
    }
    func_ov023_021f65d4(obj, 0x35, 0x18);
    func_ov023_021f65d4(obj, 0x34, 0x10);
    if (((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_31_) {
        Struct_ov004_02158dcc_7* marker = ((Struct_ov004_02158dcc_7*)func_ov004_02156ed0(obj, 0x5b));
        Vector3i zero;
        __clear(&zero, sizeof(zero));
        Vector3i tmp = zero;
        marker->pos = tmp;
        ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_31_ = 0;
    }
    return 0;
}

struct Struct_ov004_02158fec {
    virtual void inline_ov004_02158fec();
    virtual void inline_ov004_02158fec_2();
    virtual void inline_ov004_02158fec_3();
    virtual void inline_ov004_02158fec_4();
    virtual void inline_ov004_02158fec_5();
    virtual void inline_ov004_02158fec_6();
    virtual void inline_ov004_02158fec_7();
    virtual void inline_ov004_02158fec_8();
    virtual void inline_ov004_02158fec_9();
    virtual void inline_ov004_02158fec_10();
    virtual void inline_ov004_02158fec_11();
    virtual void inline_ov004_02158fec_12();
    virtual void inline_ov004_02158fec_13();
    virtual void inline_ov004_02158fec_14();
    virtual void inline_ov004_02158fec_15();
    virtual void inline_ov004_02158fec_16();
    virtual void inline_ov004_02158fec_17();
    virtual void inline_ov004_02158fec_18();
    virtual void inline_ov004_02158fec_19();
    virtual void inline_ov004_02158fec_20();
    virtual void inline_ov004_02158fec_21();
    virtual void inline_ov004_02158fec_22();
    virtual void inline_ov004_02158fec_23();
    virtual void inline_ov004_02158fec_24();
    virtual void inline_ov004_02158fec_25();
    virtual void inline_ov004_02158fec_26();
    virtual void inline_ov004_02158fec_27();
    virtual void inline_ov004_02158fec_28();
    virtual void inline_ov004_02158fec_29();
    virtual void inline_ov004_02158fec_30();
    virtual void inline_ov004_02158fec_31();
    virtual void inline_ov004_02158fec_32();
    virtual void inline_ov004_02158fec_33();
    virtual void inline_ov004_02158fec_34();
    virtual void inline_ov004_02158fec_35();
    virtual void inline_ov004_02158fec_36();
    virtual void inline_ov004_02158fec_37();
    virtual void inline_ov004_02158fec_38();
    virtual void inline_ov004_02158fec_39();
    virtual void inline_ov004_02158fec_40();
    virtual void inline_ov004_02158fec_41();
    virtual void inline_ov004_02158fec_42();
    virtual void inline_ov004_02158fec_43();
    virtual void inline_ov004_02158fec_44();
    virtual void inline_ov004_02158fec_45();
    virtual void inline_ov004_02158fec_46();
    virtual void inline_ov004_02158fec_47();
    virtual void inline_ov004_02158fec_48();
    virtual void inline_ov004_02158fec_49();
    virtual void inline_ov004_02158fec_50();
    virtual void inline_ov004_02158fec_51();
    virtual void inline_ov004_02158fec_52();
    virtual void inline_ov004_02158fec_53();
    virtual void inline_ov004_02158fec_54();
    virtual void inline_ov004_02158fec_55(int);
    virtual void inline_ov004_02158fec_56();
    virtual void inline_ov004_02158fec_57(unsigned int);
    char unknown_4[8];
    unsigned char flags;
    char unknown_d_[0x20 - 0xd];
    void* value;
};
struct Struct_ov004_02153e20 {
    char unknown_0[0x2c];
    Vector3i position;
    char unknown_38_[0x5c - 0x38];
    short page, pages;
};
struct Struct_ov004_02158fec_2 {
    short id;
    short unknown_2_;
    unsigned int count : 7;
    unsigned int unknown_4_7_ : 25;
};
struct Element020de650_02158fec {
    unsigned int field_0;
    void* value;
    unsigned int kind : 4;
    unsigned int variant : 5;
    unsigned int unknown_9_1_ : 23;
};
struct Struct_ov004_02158fec_4 {
    char unknown_0[0x31];
    unsigned char unknown_31_;
};
struct Struct_ov004_0216fb28 { unsigned char indices[9]; };
extern const Struct_ov004_0216fb28 data_ov004_0216fb28 __attribute__((aligned(4)));
extern const Vector3i data_ov004_0216fb34;
extern "C" void* func_ov004_02156f04(void*, int);
extern "C" void func_ov023_021fb27c(void*, int);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20*, short, unsigned int, unsigned int);
extern "C" int func_ov004_02158bd4(void*);

// USA: func_ov004_02158fec
extern "C" ARM int func_ov004_02158fec(void* object) {
    int textId = 0x12c;
    int var1 = textId + 6;
    int nameId = 0x138;
    int var3 = nameId + 6;
    int var4 = 0x144;
    Struct_ov004_02153e20* grid = ((Struct_ov004_02153e20*)func_ov004_02156ed0(object, 0x5b));
    if (grid->pages <= 1) {
        grid->page = 0;
        grid->pages = 1;
    }
    ItemTable* container = ((ItemTable*)func_ov004_02156fd4(object, 5));
    if (!container) return 0;
    Struct_ov004_0216fb28 var7 = data_ov004_0216fb28;
    for (unsigned char i = 0; i < 6; i++) {
        Struct_ov004_02158fec_2* entry = ((Struct_ov004_02158fec_2*)func_ov004_021570a4(object, i));
        if (entry) {
            int style = 15;
            if (entry->count == 0) style = 3;
            if (entry->id > 0) {
                Struct_ov004_02158fec* text = ((Struct_ov004_02158fec*)func_ov004_02156f04(object, textId));
                if (text) {
                    Element020de650_02158fec* element = ((Element020de650_02158fec*)ItemTable_Find(container, entry->id));
                    if (element) {
                        text->value = element->value;
                        Struct_ov004_02158fec* icon = ((Struct_ov004_02158fec*)func_ov004_02156fa0(object, i + 0x14a));
                        if (element->kind == 0) {
                            if (icon) func_ov023_021fb27c(icon, (unsigned short)(element->variant + 0x26));
                        } else {
                            if (icon) func_ov023_021fb27c(icon, (unsigned short)(var7.indices[element->kind] + 9));
                        }
                    }
                    text->inline_ov004_02158fec_55(style);
                }
                Struct_ov004_02158fec* var14 = ((Struct_ov004_02158fec*)func_ov004_02156f04(object, var1));
                if (var14) var14->inline_ov004_02158fec_55(style);
                Struct_ov004_02158fec* name = ((Struct_ov004_02158fec*)func_ov004_02156f04(object, nameId));
                if (name) name->inline_ov004_02158fec_55(style);
                Struct_ov004_02158fec* amount = ((Struct_ov004_02158fec*)func_ov004_02156f38(object, var3));
                if (amount) {
                    amount->inline_ov004_02158fec_57(entry->count);
                    amount->inline_ov004_02158fec_55(style);
                }
                Struct_ov004_02158fec* var17 = ((Struct_ov004_02158fec*)func_ov004_02156f38(object, var4));
                if (var17) {
                    var17->inline_ov004_02158fec_57(entry->unknown_4_7_);
                    var17->inline_ov004_02158fec_55(style);
                }
            } else {
                Struct_ov004_02158fec* text = ((Struct_ov004_02158fec*)func_ov004_02156f04(object, textId));
                if (text) text->flags |= 8;
                Struct_ov004_02158fec* var19 = ((Struct_ov004_02158fec*)func_ov004_02156f04(object, var1));
                if (var19) var19->flags |= 8;
                Struct_ov004_02158fec* name = ((Struct_ov004_02158fec*)func_ov004_02156f04(object, nameId));
                if (name) name->flags |= 8;
                Struct_ov004_02158fec* amount = ((Struct_ov004_02158fec*)func_ov004_02156f38(object, var3));
                if (amount) amount->flags |= 8;
                Struct_ov004_02158fec* var22 = ((Struct_ov004_02158fec*)func_ov004_02156f38(object, var4));
                if (var22) var22->flags |= 8;
                func_ov023_021f9b30(grid, 0, i, 0);
                Struct_ov004_02158fec* icon = ((Struct_ov004_02158fec*)func_ov004_02156fa0(object, i + 0x14a));
                if (icon) icon->flags |= 8;
            }
        }
        textId++;
        var1++;
        nameId++;
        var3++;
        var4++;
    }
    func_ov004_02158bd4(object);
    if (((Struct_ov004_02158fec_4*)data_ov004_021707e0)->unknown_31_ == 0) {
        Vector3i position = data_ov004_0216fb34;
        grid->position = position;
        ((Struct_ov004_02158fec_4*)data_ov004_021707e0)->unknown_31_ = 0;
    }
    return 0;
}

class Struct_ov004_02159384 {
public:
	virtual void v00(); virtual void inline_ov004_02159384_2(); virtual void inline_ov004_02159384_3(); virtual void inline_ov004_02159384_4();
	virtual void v04(); virtual void inline_ov004_02159384_6(); virtual void inline_ov004_02159384_7(); virtual void inline_ov004_02159384_8();
	virtual void v08(); virtual void inline_ov004_02159384_10(); virtual void v10(); virtual void inline_ov004_02159384_12();
	virtual void inline_ov004_02159384_13(); virtual void inline_ov004_02159384_14(); virtual void v14(); virtual void inline_ov004_02159384_16();
	virtual void inline_ov004_02159384_17(); virtual void inline_ov004_02159384_18(); virtual void v18(); virtual void inline_ov004_02159384_20();
	virtual void v20(); virtual void inline_ov004_02159384_22(); virtual void inline_ov004_02159384_23(); virtual void inline_ov004_02159384_24();
	virtual void v24(); virtual void inline_ov004_02159384_26(); virtual void inline_ov004_02159384_27(); virtual void inline_ov004_02159384_28();
	virtual void v28(); virtual void inline_ov004_02159384_30(); virtual void v30(); virtual void inline_ov004_02159384_32();
	virtual void inline_ov004_02159384_33(); virtual void inline_ov004_02159384_34(); virtual void v34(); virtual void inline_ov004_02159384_36();
	virtual void inline_ov004_02159384_37(); virtual void inline_ov004_02159384_38(); virtual void v38(); virtual void inline_ov004_02159384_40();
	virtual void v40(); virtual void inline_ov004_02159384_42(); virtual void inline_ov004_02159384_43(); virtual void inline_ov004_02159384_44();
	virtual void v44(); virtual void inline_ov004_02159384_46(); virtual void inline_ov004_02159384_47(); virtual void inline_ov004_02159384_48();
	virtual void v48(); virtual void inline_ov004_02159384_50(); virtual void v50(); virtual void inline_ov004_02159384_52();
	virtual void inline_ov004_02159384_53(); virtual void inline_ov004_02159384_54(); virtual void v54(); virtual void inline_ov004_02159384_56();
	virtual void inline_ov004_02159384_57(int n);
};

// USA: func_ov004_02159384
extern "C" ARM int func_ov004_02159384(void* self) {
	int b = func_ov004_02156e2c(self, 0x5b);
	if (b < 0) return 0;
	void* entry = func_ov004_021570a4(self, (unsigned char)b);
	if (!entry) return 0;

	Struct_ov004_02159384* var2 = (Struct_ov004_02159384*)func_ov004_02156f38(self, 0x25a);
	if (var2) {
		var2->inline_ov004_02159384_57(data_ov004_021707e0[0x11]);
	}

	Struct_ov004_02159384* node2 = (Struct_ov004_02159384*)func_ov004_02156f38(self, 0x2bd);
	if (node2) {
		unsigned int field4 = *(unsigned int*)((char*)entry + 4);
		node2->inline_ov004_02159384_57(data_ov004_021707e0[0x11] * (field4 >> 7));
	}

	void* node3 = func_ov004_02156f6c(self, 0x19);
	if (node3) func_ov023_021f809c(node3, self);

	void* node4 = func_ov004_02156f6c(self, 0x1a);
	if (node4) func_ov023_021f809c(node4, self);

	return 0;
}

// USA: func_ov004_02159468
extern "C" ARM int func_ov004_02159468(void) {
    return 0;
}
extern "C" int func_020dcc98(signed char);

class Struct_ov004_02159470 {
public:
    virtual void v00(); virtual void inline_ov004_02159470_2(); virtual void inline_ov004_02159470_3(); virtual void inline_ov004_02159470_4();
    virtual void v04(); virtual void inline_ov004_02159470_6(); virtual void inline_ov004_02159470_7(); virtual void inline_ov004_02159470_8();
    virtual void v08(); virtual void inline_ov004_02159470_10(); virtual void v10(); virtual void inline_ov004_02159470_12();
    virtual void inline_ov004_02159470_13(); virtual void inline_ov004_02159470_14(); virtual void v14(); virtual void inline_ov004_02159470_16();
    virtual void inline_ov004_02159470_17(); virtual void inline_ov004_02159470_18(); virtual void v18(); virtual void inline_ov004_02159470_20();
    virtual void v20(); virtual void inline_ov004_02159470_22(); virtual void inline_ov004_02159470_23(); virtual void inline_ov004_02159470_24();
    virtual void v24(); virtual void inline_ov004_02159470_26(); virtual void inline_ov004_02159470_27(); virtual void inline_ov004_02159470_28();
    virtual void v28(); virtual void inline_ov004_02159470_30(); virtual void v30(); virtual void inline_ov004_02159470_32();
    virtual void inline_ov004_02159470_33(); virtual void inline_ov004_02159470_34(); virtual void v34(); virtual void inline_ov004_02159470_36();
    virtual void inline_ov004_02159470_37(); virtual void inline_ov004_02159470_38(); virtual void v38(); virtual void inline_ov004_02159470_40();
    virtual void v40(); virtual void inline_ov004_02159470_42(); virtual void inline_ov004_02159470_43(); virtual void inline_ov004_02159470_44();
    virtual void v44(); virtual void inline_ov004_02159470_46(); virtual void inline_ov004_02159470_47(); virtual void inline_ov004_02159470_48();
    virtual void v48(); virtual void inline_ov004_02159470_50(); virtual void v50(); virtual void inline_ov004_02159470_52();
    virtual void inline_ov004_02159470_53(); virtual void inline_ov004_02159470_54();
    virtual void inline_ov004_02159470_55(int v);
    int pad4[7];
    void* unknown_20_;
};

// USA: func_ov004_02159470
extern "C" ARM int func_ov004_02159470(void* self) {
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);
    char* ptr = ((char*)data_ov004_021707e0);
    unsigned char count = (unsigned char)(*(short*)(ptr + 0x3a));
    int key = 0x322;
    for (unsigned char i = 0; i < count; key++, i++) {
        signed char var5 = func_ov004_021570f0(i);
        GameObject* c = battle->GetPartyMemberByIndex(var5);
        if (!c) continue;
        Struct_ov004_02159470* node = (Struct_ov004_02159470*)func_ov004_02156f04(self, key);
        if (!node) continue;
        node->unknown_20_ = c->baseStats_;
        int v = func_020dcc98(var5);
        node->inline_ov004_02159470_55(v);
    }
    return 0;
}

#if defined(jpn)
enum { Enum_ov004_0215951c_336 = 0x144 };
#else
enum { Enum_ov004_0215951c_336 = 0x150 };
#endif

extern unsigned char data_ov004_0216fb10[8];

struct Struct_ov004_0215951c {
    int f0;
    void* f4;
    unsigned int type : 4;
    unsigned int unknown_8_4_ : 28;
    char pad[0xc];
    short f18;
    char pad2[6];
};

class Struct_ov004_0215951c_2 {
public:
    virtual void v00(); virtual void inline_ov004_0215951c_2(); virtual void inline_ov004_0215951c_3(); virtual void inline_ov004_0215951c_4();
    virtual void v04(); virtual void inline_ov004_0215951c_6(); virtual void inline_ov004_0215951c_7(); virtual void inline_ov004_0215951c_8();
    virtual void v08(); virtual void inline_ov004_0215951c_10(); virtual void v10(); virtual void inline_ov004_0215951c_12();
    virtual void inline_ov004_0215951c_13(); virtual void inline_ov004_0215951c_14(); virtual void v14(); virtual void inline_ov004_0215951c_16();
    virtual void inline_ov004_0215951c_17(); virtual void inline_ov004_0215951c_18(); virtual void v18(); virtual void inline_ov004_0215951c_20();
    virtual void v20(); virtual void inline_ov004_0215951c_22(); virtual void inline_ov004_0215951c_23(); virtual void inline_ov004_0215951c_24();
    virtual void v24(); virtual void inline_ov004_0215951c_26(); virtual void inline_ov004_0215951c_27(); virtual void inline_ov004_0215951c_28();
    virtual void v28(); virtual void inline_ov004_0215951c_30(); virtual void v30(); virtual void inline_ov004_0215951c_32();
    virtual void inline_ov004_0215951c_33(); virtual void inline_ov004_0215951c_34(); virtual void v34(); virtual void inline_ov004_0215951c_36();
    virtual void inline_ov004_0215951c_37(); virtual void inline_ov004_0215951c_38(); virtual void v38(); virtual void inline_ov004_0215951c_40();
    virtual void v40(); virtual void inline_ov004_0215951c_42(); virtual void inline_ov004_0215951c_43(); virtual void inline_ov004_0215951c_44();
    virtual void v44(); virtual void inline_ov004_0215951c_46(); virtual void inline_ov004_0215951c_47(); virtual void inline_ov004_0215951c_48();
    virtual void v48(); virtual void inline_ov004_0215951c_50(); virtual void v50(); virtual void inline_ov004_0215951c_52();
    virtual void inline_ov004_0215951c_53(); virtual void inline_ov004_0215951c_54();
    virtual void inline_ov004_0215951c_55(int n);
    int pad4[7];
    void* unknown_20_;
};

// USA: func_ov004_0215951c
extern "C" ARM int func_ov004_0215951c(void* obj) {
    signed char flag = func_ov004_02157128(obj);
    GameState* battle = GameState::GetInstance();
    GameObject* c = func_0200ff1c(battle, flag);
    if (!c) return 0;

    unsigned char* fieldPtr = data_ov004_021707e0;
    fieldPtr[0x12] = (unsigned char)flag;

    unsigned char buf[8];
    int n = 8;
    unsigned char* dst = buf;
    unsigned char* src = data_ov004_0216fb10;
    do {
        unsigned char v = *src;
        src++;
        *dst = v;
        dst++;
    } while (--n);

    int key = 0x384;
    for (short i = 0; i < 8; key++, i++) {
        int var11 = 3;
        void* var12 = 0;
        int idx = buf[i];
        if (idx != 0xff) {
            Struct_ov004_0215951c* arr = (Struct_ov004_0215951c*)(*(char**)((char*)c + Enum_ov004_0215951c_336) + 0x194);
            Struct_ov004_0215951c* e = &arr[idx];
            if (e) {
                if (e->f18 > 0) {
                    unsigned int type = e->type;
                    if (type == 0xb) goto skip;
                    var12 = e->f4;
                    if (!var12) goto skip;
                    if (*(signed char*)var12 != 0) var11 = 0xf;
                    else var12 = 0;
                }
            }
        }
    skip:
        Struct_ov004_0215951c_2* node = (Struct_ov004_0215951c_2*)func_ov004_02156f04(obj, key);
        if (node) {
            node->unknown_20_ = var12;
            node->inline_ov004_0215951c_55(var11);
        }
    }

    void* node2 = func_ov004_02156f6c(obj, 0x16);
    if (node2) {
        func_ov023_021f809c(node2, obj);
    }
    return 0;
}

#if defined(jpn)
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

struct Struct_ov004_02159650 {
    unsigned char unknown_0_[0x12];
    signed char partyIndex;

    signed char inline_ov004_02159650() const { return partyIndex; }
};

struct Struct_ov004_02159650_2 { short field0; unsigned int field4; };

struct Element020de650_02159650 { int field0; char pad2[4]; int field8; char pad3[0xc]; short field18; };

extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);

extern "C" int StandardStrings_Get(int value);
extern "C" void func_020e4b34(void* obj, int arg1, int arg2, int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" int func_02052df8(struct Struct_02052df8* obj, int index);

struct Struct_ov004_0216fbb0 { unsigned int v[9]; };
extern struct Struct_ov004_0216fbb0 data_ov004_0216fbb0;

struct Struct_ov004_02159650_4 { char pad[8]; unsigned int unknown_8_0_ : 4; unsigned int rest : 28; };
struct Struct_ov004_02159650_5 { unsigned int unknown_0_0_ : 18; unsigned int unknown_2_2_ : 1; unsigned int unknown_2_3_ : 13; };

// USA: func_ov004_02159650
extern "C" ARM int func_ov004_02159650(void* obj) {
    int g = MessageSystem_GetInstance();
    func_02046380((void*)g);

    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));

    struct Element020de650_02159650* elem = 0;
    struct Struct_ov004_02159650_2* entry = 0;

    int idx = func_ov004_02156e2c(obj, 0x5b);
    if (idx >= 0) {
        entry = (struct Struct_ov004_02159650_2*)func_ov004_021570a4(obj, idx & 0xff);
        if (entry != 0 && node != 0) {
            elem = ((struct Element020de650_02159650*)ItemTable_Find(node, entry->field0));
        }
    }

    signed char combatantId = ((Struct_ov004_02159650*)data_ov004_021707e0)->inline_ov004_02159650();
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);

    if (combatant != 0) {
#if defined(jpn)
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)combatant->baseStats_);
#else
        NameText_InitFromPartyMember(data_ov004_021707e0 + 0xa0, combatantId);
        *(void**)((char*)g + 0x10) = data_ov004_021707e0 + 0xa0;

        void* var7 = *(void**)((char*)combatant + 0x150);
        int statVal = (short)(*(int*)((char*)var7 + 0x950));
        int fmt = StandardStrings_Get(statVal);
        func_020e4b34(data_ov004_021707e0 + 0xac, fmt, fmt, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(void**)((char*)g + 0x28) = data_ov004_021707e0 + 0xac;
#endif
    }

    if (elem != 0) {
#if defined(jpn)
        char name[80];
        func_020e207c((Container020e0310*)(data_ov004_021707e0 + 0x8c), name, elem->field18);
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        int val = ((int)func_020e5294(data_ov004_021707e0 + 0x8c, elem->field18));
        *(int*)((char*)g + 0x18) = val;
#endif
    }

    if (combatant != 0 && elem != 0 && elem->field0 != 0) {
        struct Struct_ov004_02159650_4* var12 = (struct Struct_ov004_02159650_4*)elem;
        unsigned int nibble = var12->unknown_8_0_;
        int inRange = nibble <= 7;
        if (inRange) {
            struct Struct_ov004_0216fbb0 table = data_ov004_0216fbb0;
            int half = func_02052df8((struct Struct_02052df8*)combatant, table.v[nibble]);
            if (half > 0) {
                struct Element020de650_02159650* elem2 = ((struct Element020de650_02159650*)ItemTable_Find(node, half));
                if (elem2 != 0 && ((struct Struct_ov004_02159650_5*)&elem2->field8)->unknown_2_2_ != 0) {
#if defined(jpn)
                    MessageSystem_SetStringArgument((Obj02046574*)g, 2, *(char**)((char*)elem2 + 4));
#else
                    int val2 = ((int)func_020e5294(data_ov004_021707e0 + 0x8c, half));
                    *(int*)((char*)g + 0x18) = val2;
#endif
                }
            }
        }
    }

    if (entry != 0) {
        func_020465c0((struct StoreStruct*)g, 0, data_ov004_021707e0[0x11] * (entry->field4 >> 7));
    }

    func_020465c0((struct StoreStruct*)g, 1, data_ov004_021707e0[0x11]);
    return 0;
}
extern "C" void func_ov023_021f66bc(void* a, int key, void* arg2);
extern "C" int func_ov004_02159384(void* self);

struct Struct_ov004_02159888 { short field0; short pad2; unsigned int field4 : 7; };
struct Element020de650_02159888 { char pad[8]; unsigned int field8 : 4; };

// USA: func_ov004_02159888
extern "C" ARM int func_ov004_02159888(void* obj) {
    int key = func_ov004_02156e2c(obj, 0x5b);
    if (key < 0) return 0;

    Struct_ov004_02159888* entry = (Struct_ov004_02159888*)func_ov004_021570a4(obj, (unsigned char)key);
    if (!entry) return 0;

    if (data_ov004_021707e0[0x11] >= entry->field4) return 0;

    void* ptr2a04 = GameState_GetParty(GameState::GetInstance());
    unsigned int cap = *(unsigned int*)((char*)entry + 4) >> 7;
    if (*(unsigned int*)((char*)ptr2a04 + 0xf6c) < (data_ov004_021707e0[0x11] + 1) * cap) return 0;

    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    if (!node) return 0;

    struct Element020de650_02159888* elem = ((struct Element020de650_02159888*)ItemTable_Find(node, *(short*)(data_ov004_021707e0 + 0xe)));
    if (!elem) return 0;

    unsigned int r = ((unsigned int)func_ov004_0215799c(ptr2a04, entry->field0, (int)elem->field8, *(short*)(data_ov004_021707e0 + 0x3a)));
    if (data_ov004_021707e0[0x11] >= r) return 0;

    data_ov004_021707e0[0x11] = data_ov004_021707e0[0x11] + 1;
    func_ov023_021f66bc(obj, 0x25b, (void*)1);
    func_ov004_02159384(obj);
    return 0;
}

// USA: func_ov004_021599b4
extern "C" ARM int func_ov004_021599b4(void* obj) {
    int key = func_ov004_02156e2c(obj, 0x5b);
    if (key < 0) {
        return 0;
    }
    void* entry = func_ov004_021570a4(obj, (unsigned char)key);
    if (!entry) {
        return 0;
    }
    unsigned char* p = data_ov004_021707e0;
    unsigned char val = p[0x11];
    if (val <= 1) {
        return 0;
    }
    p[0x11] = val - 1;
    func_ov023_021f66bc(obj, 0x25c, (void*)1);
    func_ov004_02159384(obj);
    return 0;
}

#if defined(jpn)
#define data_ov004_0216fb50 data_ov004_021702d8
#define func_ov004_02159bcc func_ov004_0215ac28
#endif

struct Struct_ov004_02159a2c { char pad[0x32]; short members[4]; short memberCount; };

struct Struct_ov004_0216fb50 { int ids[4]; };
extern Struct_ov004_0216fb50 data_ov004_0216fb50;
struct Element020de650_02159a2c { char pad[8]; unsigned int field8 : 4; };
extern "C" int func_020dd4c4(int, struct Struct_020dd4c4_3*);
extern "C" int func_ov004_02159bcc(void* obj);

// USA: func_ov004_02159a2c
extern "C" ARM int func_ov004_02159a2c(void* obj) {
    int i;
    GameState::GetInstance();
    int key = func_ov004_02156e2c(obj, 0x5b);
    if (key < 0) return 0;
    void* entry = func_ov004_021570a4(obj, key & 0xff);
    if (!entry) return 0;
    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    if (!node) return 0;
    struct Element020de650_02159a2c* elem = ((struct Element020de650_02159a2c*)ItemTable_Find(node, *(short*)entry));
    if (!elem) return 0;

    int ok = elem->field8 <= 7;
    if (ok) {
        Struct_ov004_0216fb50 members = data_ov004_0216fb50;
        Struct_ov004_02159a2c* battle = ((Struct_ov004_02159a2c*)data_ov004_021707e0);
        int count = battle->memberCount;
        for (i = 0; i < count; i++) {
            members.ids[i] = battle->members[i];
        }
        int j;
        for (j = 0; j < count; j++) {
            if (!func_020dd4c4((signed char)members.ids[j], (Struct_020dd4c4_3*)elem)) break;
        }
        if (j == count) {
            func_ov004_02159bcc(obj);
        } else {
            func_ov011_021848a0(obj, 0x38b);
        }
    } else {
        func_ov011_021848a0(obj, 0x2384);
    }
    return 0;
}

#undef data_ov004_0216fb50
#undef func_ov004_02159bcc

// USA: func_ov004_02159b74
extern "C" ARM int func_ov004_02159b74(void* obj) {
    func_ov011_021848a0(obj, 0x2368);
    return 0;
}

// USA: func_ov004_02159b8c
extern "C" ARM int func_ov004_02159b8c(void* obj) {
    GameState_GetParty(GameState::GetInstance());
    short v = *(short*)(((char*)data_ov004_021707e0) + 0x3a);
    int arg = 0x38d;
    arg += v & 0xff;
    func_ov011_021848a0(obj, arg);
    return 0;
}

#if defined(jpn)
#define func_ov004_02159bcc func_ov004_0215ac28
#endif

struct Struct_ov004_02159bcc {
    SafeAllocator allocator;
    unsigned char state14[0x18];
    ItemTable* container;
    void* unknown_30_;
    int field34;
};
extern "C" void* ItemTable_Construct(void* obj);
extern "C" void func_0207cbe8(char* obj);
extern "C" void func_0207cc0c(char* obj);
extern "C" int func_0207d134(struct Struct_0207d134*, short, int);

// USA: func_ov004_02159bcc
extern "C" ARM int func_ov004_02159bcc(void* obj) {
#if !defined(jpn)
    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    if (node == NULL) return 0;
    struct Element020de650* elem = ItemTable_Find(node, *(short*)(((char*)data_ov004_021707e0) + 0xe));
    if (elem == NULL) return 0;
    int val = ((int)func_020e5294(((char*)data_ov004_021707e0) + 0x8c, *(short*)((char*)elem + 0x18)));
    *(int*)((char*)(int)MessageSystem_GetInstance() + 0x18) = val;
    ((char*)data_ov004_021707e0)[0x12] = (char)0xff;
#endif
    if (*(unsigned char*)(((char*)data_ov004_021707e0) + 0x47) == 0) {
        ItemTable* node2 = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
        if (node2 != NULL) {
            Struct_ov004_02159bcc context;
            context.allocator.ResetAllocatorPointer();
            ItemTable_Construct(context.state14);
            func_0207cbe8((char*)&context);
            func_0207cbe8((char*)&context);
            context.container = node2;
            func_0207d134((Struct_0207d134*)(&context), *(short*)(((char*)data_ov004_021707e0) + 0xe), *(signed char*)(((char*)data_ov004_021707e0) + 0x11));
            func_0207cc0c((char*)&context);
        }
        func_ov011_021848a0(obj, 0x38c);
        ((char*)data_ov004_021707e0)[R(0xa9, 0x9d)] = 0;
        return 0;
    }
    func_ov011_021848a0(obj, 0x2379);
    return 0;
}

#undef func_ov004_02159bcc

extern "C" void func_020dd7ac(void* buf);
extern "C" void func_020ddaf4(int a, int b, int c, int d, int e, int f);
extern "C" void func_ov023_021fbdf4(struct Struct_ov004_02158bd4* obj, int v);

typedef void (*Type_01ff8b48_11)(void*, int);
struct Struct_ov004_02159ce0 { char pad[0xe0]; Type_01ff8b48_11 func; };
struct Struct_ov004_02159ce0_2 { Struct_ov004_02159ce0* handler; };

typedef void (*Type_01ff8b48_12)(void*, int);
struct Struct_ov004_02159ce0_3 { char pad[0xd8]; Type_01ff8b48_12 func; };
struct Struct_ov004_02159ce0_4 { Struct_ov004_02159ce0_3* handler; };

struct Struct_ov004_02159ce0_5 { char pad[0x20]; int field20; };
struct Struct_ov004_02159ce0_6 { char pad[0x38]; short field38; };

struct Struct_ov004_02159ce0_7 { unsigned int nibble : 4; unsigned int rest : 28; };

// USA: func_ov004_02159ce0
extern "C" ARM int func_ov004_02159ce0(void* a) {
    int var0 = func_ov004_02157128(a);
    ItemTable* node = (ItemTable*)((void*)func_ov004_02156fd4(a, 5));
    if (!node) return 0;

    short key = *(short*)(data_ov004_021707e0 + 0xe);
    Element020de650* elem = ItemTable_Find(node, key);
    if (!elem) return 0;

    Struct_020dd7ac var4;
    func_020dd7ac(&var4);
    int var5 = 1;
    unsigned int nibble = ((Struct_ov004_02159ce0_7*)((char*)elem + 8))->nibble;

    unsigned short valA, valB;
    if (nibble == 0) {
        func_020ddaf4((int)&var4, var0, (int)elem, 0, (int)&valA, (int)&valB);
    } else {
        func_020ddaf4((int)&var4, var0, (int)elem, var5, (int)&valA, (int)&valB);
        var5 = 3;
    }

    Struct_ov004_02159ce0_5* var9 = (Struct_ov004_02159ce0_5*)func_ov004_02156f04(a, 0x3e8);
    if (var9) var9->field20 = *(int*)((char*)elem + 4);

    Struct_ov004_02159ce0_6* var10 = (Struct_ov004_02159ce0_6*)func_ov004_02156f04(a, 0x3ea);
    if (var10) var10->field38 = (short)(var5 + 0xb);

    if (func_020dd4c4((int)((void*)var0), (Struct_020dd4c4_3*)elem) != 0) {
        func_ov023_021f65d4(a, 0x3eb, 8);
        func_ov023_021f65d4(a, 0x3ec, 8);
        func_ov023_021f65d4(a, 0x3ed, 8);
        func_ov023_021f6600(a, 0x3ee, 8);
    } else {
        Struct_ov004_02159ce0_2* var11 = (Struct_ov004_02159ce0_2*)func_ov004_02156f38(a, 0x3eb);
        if (var11) var11->handler->func(var11, valA);

        Struct_ov004_02159ce0_2* var12 = (Struct_ov004_02159ce0_2*)func_ov004_02156f38(a, 0x3ed);
        if (var12) var12->handler->func(var12, valB);

        Struct_ov004_02159ce0_4* var13 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), 0x3eb);
        if (var13) var13->handler->func(var13, 0xf);

        if (valA == valB) {
            Struct_ov004_02159ce0_4* var14 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), 0x3ed);
            if (var14) var14->handler->func(var14, 0xf);
        } else if (valA < valB) {
            Struct_ov004_02159ce0_4* var15 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), 0x3ed);
            if (var15) var15->handler->func(var15, 0x5);
        } else {
            Struct_ov004_02159ce0_4* var16 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), 0x3ed);
            if (var16) var16->handler->func(var16, 0x9);
        }

        func_ov023_021f6600(a, 0x3eb, 8);
        func_ov023_021f6600(a, 0x3ec, 8);
        func_ov023_021f6600(a, 0x3ed, 8);
        func_ov023_021f65d4(a, 0x3ee, 8);
    }

    Struct_ov004_02159ce0_2* var17 = (Struct_ov004_02159ce0_2*)func_ov004_02156f6c(a, 0x17);
    if (var17) func_ov023_021f809c(var17, a);

    void* var18 = func_ov004_02157054(a, 7);
    if (var18) {
        func_ov023_021fbdf4((Struct_ov004_02158bd4*)var18, var0);
#if defined(jpn)
        data_ov004_021707e0[0xa8] = 0;
#else
        data_ov004_021707e0[0x9c] = 0;
#endif
    }

    return 0;
}

extern "C" int func_ov004_0215951c(void*);
extern "C" int func_ov004_02159ce0(void*);

// USA: func_ov004_02159fb0
extern "C" ARM int func_ov004_02159fb0(int a) {
    func_ov004_0215951c((void*)a);
    func_ov004_02159ce0((void*)a);
    return 0;
}

struct Struct_ov004_02159fcc { unsigned int low : 27; unsigned int unknown_3_3_ : 1; unsigned int unknown_3_4_ : 1; unsigned int disabled : 1; unsigned int high : 2; };
struct Struct_ov000_0215767c_10 { int field0; Struct_ov004_02159fcc flags; };
struct ActionEntry { Struct_ov000_0215767c_10* node; void* field4; unsigned int type : 4; unsigned int rest : 14; unsigned int marked : 1; unsigned int high : 13; char pad[12]; short value; char tail[6]; };
struct Struct_ov004_02159fcc_2 { char pad[0x194]; ActionEntry entries[24]; char tail[8]; unsigned char selection : 1; unsigned char rest : 7; };
#if defined(jpn)
enum { Enum_ov004_021570f0_336_2 = 0x144, Enum_ov004_021570f0_16 = 0x1c };
#else
enum { Enum_ov004_021570f0_336_2 = 0x150, Enum_ov004_021570f0_16 = 0x10 };
#endif
struct Struct_ov004_02159fcc_3 { char pad[Enum_ov004_021570f0_336_2]; Struct_ov004_02159fcc_2* extension; };
struct BattleActionState { char pad[0xe]; short key; char pad10[0x2c]; short combatant; char unknown_3e_[0x4e]; char controller[Enum_ov004_021570f0_16]; unsigned char active; };
struct Struct_ov004_0216fbf8 { int keys[9]; };
struct Struct_ov004_0216fb18 { unsigned char indices[8]; };
struct GlobalController { char pad[0x18]; void* selected; };
extern Struct_ov004_0216fbf8 data_ov004_0216fbf8;
extern Struct_ov004_0216fb18 data_ov004_0216fb18;
extern "C" int func_ov004_02159650(void*);
#if defined(jpn)
struct Container020e0310;
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

extern "C" int func_ov004_02157a28(void*, int);

static inline Struct_ov004_02159fcc_2* inline_ov004_02159fcc(Struct_ov004_02159fcc_3* combatant) { return combatant->extension; }

// USA: func_ov004_02159fcc
extern "C" ARM int func_ov004_02159fcc(void* obj) {
    int flag = func_ov004_02157128(obj);
    ((BattleActionState*)data_ov004_021707e0)->combatant = flag;
    LinkSession_GetInstance();
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), flag);
    if (!combatant) return 0;
    ItemTable* container = ((ItemTable*)func_ov004_02156fd4(obj, 5));
    if (!container) return 0;
    ActionEntry* entry = ((ActionEntry*)ItemTable_Find(container, ((BattleActionState*)data_ov004_021707e0)->key));
    if (!entry) return 0;
    unsigned int type = entry->type;
    if (func_020dd4c4(flag, (Struct_020dd4c4_3*)entry)) {
        func_ov011_021848a0(obj, 0x392);
        return 0;
    }
    Struct_ov004_0216fbf8 keys = data_ov004_0216fbf8;
    int key = func_02052df8((Struct_02052df8*)combatant, keys.keys[entry->type]);
    if (key > 0) {
        ActionEntry* selected = ((ActionEntry*)ItemTable_Find(container, key));
        if (selected && selected->marked) {
            func_ov004_02159650(obj);
            GlobalController* controller = ((GlobalController*)MessageSystem_GetInstance());
#if defined(jpn)
            char name[80];
            func_020e207c((Container020e0310*)((BattleActionState*)data_ov004_021707e0)->controller, name, selected->value);
            MessageSystem_SetStringArgument((Obj02046574*)controller, 1, name);
#else
            controller->selected = func_020e5294(((BattleActionState*)data_ov004_021707e0)->controller, selected->value);
#endif
            func_ov011_021848a0(obj, 0x23b6);
            return 0;
        }
    }
    if (type == 7 && func_02052df8((Struct_02052df8*)combatant, 9) == 0x4680) {
        int var10;
        if (!combatant) var10 = 0;
        else {
            Struct_ov004_0216fb18 indices = data_ov004_0216fb18;
            unsigned char flags[2];
            for (unsigned char i = 0; i < 8; i++) {
                unsigned char index = indices.indices[i];
                if (index == 0xff) break;
                ActionEntry* action;
                Struct_ov004_02159fcc_2* extension = inline_ov004_02159fcc((Struct_ov004_02159fcc_3*)combatant);
                action = &extension->entries[index];
                if (action && action->value >= 0) {
                    Struct_ov000_0215767c_10* node = action->node;
                    if (node && !node->flags.disabled) {
                        unsigned int enabled = node->flags.unknown_3_3_ ? 1 : 0;
                        flags[0] = enabled;
                        flags[1] = node->flags.unknown_3_4_ ? 1 : 0;
                        if (!flags[extension->selection]) {
                            var10 = 1;
                            goto checked;
                        }
                    }
                }
            }
            var10 = 0;
        }
    checked:
        if (var10) {
            func_ov011_021848a0(obj, 0x23b5);
            return 0;
        }
    }
    Struct_ov004_02158bd4* node = ((Struct_ov004_02158bd4*)func_ov004_02157054(obj, 7));
    if (node) {
        func_ov023_021fbdf4(node, -1);
        ((BattleActionState*)data_ov004_021707e0)->active = 1;
    }
    return func_ov004_02157a28(obj, 0);
}
extern "C" void* func_ov004_0215a2f8(void*);
extern "C" void func_ov023_021f65d4(void* a, int key, int mask);

// USA: func_ov004_0215a294
extern "C" ARM int func_ov004_0215a294(void* obj) {
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);
    unsigned char* fieldPtr __attribute__((aligned(4))) = data_ov004_021707e0;
    unsigned char byteVal = (unsigned char)*(short*)(fieldPtr + 0x3a);
    short var3 = 0x396;
    short var4 = *(short*)(fieldPtr + 0x32);
    *(short*)(fieldPtr + 0x3c) = var4;
    func_ov011_021848a0(obj, var3 + byteVal);
    func_ov004_0215a2f8(data_ov004_021707e0);
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}

// USA: func_ov004_0215a2f8
extern "C" ARM void* func_ov004_0215a2f8(void* obj) {
	*(short*)((char*)obj + 0x6c) = -1;
	*(char*)((char*)obj + 0x6e) = 0;
	*(char*)((char*)obj + 0x6f) = 0;
	*(char*)((char*)obj + 0x70) = -1;
	*(int*)((char*)obj + 0x74) = -1;
	*(int*)((char*)obj + 0x78) = 0;
	return obj;
}

class Struct_ov004_0215a31c {
public:
    virtual void v00(); virtual void inline_ov004_0215a31c_2(); virtual void inline_ov004_0215a31c_3(); virtual void inline_ov004_0215a31c_4();
    virtual void v04(); virtual void inline_ov004_0215a31c_6(); virtual void inline_ov004_0215a31c_7(); virtual void inline_ov004_0215a31c_8();
    virtual void v08(); virtual void inline_ov004_0215a31c_10(); virtual void v10(); virtual void inline_ov004_0215a31c_12();
    virtual void inline_ov004_0215a31c_13(); virtual void inline_ov004_0215a31c_14(); virtual void v14(); virtual void inline_ov004_0215a31c_16();
    virtual void inline_ov004_0215a31c_17(); virtual void inline_ov004_0215a31c_18(); virtual void v18(); virtual void inline_ov004_0215a31c_20();
    virtual void v20(); virtual void inline_ov004_0215a31c_22(); virtual void inline_ov004_0215a31c_23(); virtual void inline_ov004_0215a31c_24();
    virtual void v24(); virtual void inline_ov004_0215a31c_26(); virtual void inline_ov004_0215a31c_27(); virtual void inline_ov004_0215a31c_28();
    virtual void v28(); virtual void inline_ov004_0215a31c_30(); virtual void v30(); virtual void inline_ov004_0215a31c_32();
    virtual void inline_ov004_0215a31c_33(); virtual void inline_ov004_0215a31c_34(); virtual void v34(); virtual void inline_ov004_0215a31c_36();
    virtual void inline_ov004_0215a31c_37(); virtual void inline_ov004_0215a31c_38(); virtual void v38(); virtual void inline_ov004_0215a31c_40();
    virtual void v40(); virtual void inline_ov004_0215a31c_42(); virtual void inline_ov004_0215a31c_43(); virtual void inline_ov004_0215a31c_44();
    virtual void v44(); virtual void inline_ov004_0215a31c_46(); virtual void inline_ov004_0215a31c_47(); virtual void inline_ov004_0215a31c_48();
    virtual void v48(); virtual void inline_ov004_0215a31c_50(); virtual void v50(); virtual void inline_ov004_0215a31c_52();
    virtual void inline_ov004_0215a31c_53(); virtual void inline_ov004_0215a31c_54();
    virtual void inline_ov004_0215a31c_55(int v);
    virtual void inline_ov004_0215a31c_56();
    virtual void inline_ov004_0215a31c_57(int v);
    char pad04[8];
    unsigned char flags;
    char pad0d[0x13];
    void* data;
};

struct Struct_ov004_0215a31c_2 {
    char pad[0x5c];
    short page;
    short pageCount;
};

struct Element0215a31c {
    char pad[4];
    void* data;
};
struct Struct_020a0b8c;
extern "C" int func_020a0b8c(Struct_020a0b8c* p);
extern "C" int func_02053c6c(unsigned char*);
extern "C" int func_020dcc98(signed char combatantId);
typedef int (*Type_ov004_0215a31c)(Struct_ov004_0215a31c_2*, unsigned short, unsigned int, unsigned int);
extern "C" void func_ov023_021f9ba8(Struct_ov004_0215a31c_2* grid, int v);
extern "C" void* func_ov004_02157088(void* object, int key);
extern "C" void func_ov023_021dcae0(struct Struct_ov003_02178910*, int);

// USA: func_ov004_0215a31c
extern "C" ARM int func_ov004_0215a31c(void* obj) {
    signed char flag = func_ov004_02157128(obj);
    ItemTable* items = ((ItemTable*)func_ov004_02156fd4(obj, 5));
    TableA68* table = ((TableA68*)func_ov004_02157018(obj, 3));
    short* keys;
    Struct_ov004_0215a31c_2* grid = ((Struct_ov004_0215a31c_2*)func_ov004_02156ed0(obj, 0x63));
    int i;
    int slot;

    if (flag == -1) {
        unsigned char* list = (unsigned char*)GameState_GetParty(GameState::GetInstance());
        if (!list) return 0;
        keys = (short*)(list + 0xc);
        signed char* counts = (signed char*)(list + 0x13c);
        Struct_ov004_0215a31c* node = ((Struct_ov004_0215a31c*)func_ov004_02156f04(obj, 0x454));
        if (node) {
            node->data = func_02072a68(table, 0xb);
        }
        short page = grid->page;
        short pageCount = grid->pageCount;
        if (!(page > 0 && pageCount > 0)) {
            page = 0;
            pageCount = (func_020a0b8c((Struct_020a0b8c*)list) - 1) / 8 + 1;
            if (pageCount < 1) pageCount = 1;
            grid->page = 0;
            grid->pageCount = pageCount;
        }
        keys += page * 8;
        node = ((Struct_ov004_0215a31c*)func_ov004_02156f04(obj, 0x458));
        if (node) node->flags &= ~8;
        ((Struct_ov004_0215a31c*)func_ov004_02156f38(obj, 0x456))->inline_ov004_0215a31c_57(page + 1);
        ((Struct_ov004_0215a31c*)func_ov004_02156f38(obj, 0x457))->inline_ov004_0215a31c_57(pageCount);
        func_ov023_021f6600(obj, 0x456, 8);
        func_ov023_021f6600(obj, 0x457, 8);
        func_ov023_021f6600(obj, 0x469, 8);
        func_ov023_021f6600(obj, 0x46a, 8);
        for (i = 0; i < 8; i++) {
            func_ov023_021f6600(obj, i + 0x459, 8);
            func_ov023_021f6600(obj, i + 0x461, 8);
            ((Struct_ov004_0215a31c*)func_ov004_02156f38(obj, i + 0x461))->inline_ov004_0215a31c_57(counts[i]);
        }
    } else {
        GameObject* combatant = func_0200ff1c(GameState::GetInstance(), flag);
        if (!combatant) return 0;
        keys = (short*)(((unsigned char*)func_02053c6c((unsigned char*)combatant)) + 0x454);
        Struct_ov004_0215a31c* node = ((Struct_ov004_0215a31c*)func_ov004_02156f04(obj, 0x454));
        if (node) {
            node->data = combatant->baseStats_;
            node->inline_ov004_0215a31c_55(func_020dcc98(flag));
        }
        node = ((Struct_ov004_0215a31c*)func_ov004_02156f04(obj, 0x458));
        if (node) node->flags |= 8;
        func_ov023_021f65d4(obj, 0x456, 8);
        func_ov023_021f65d4(obj, 0x457, 8);
        func_ov023_021f65d4(obj, 0x469, 8);
        func_ov023_021f65d4(obj, 0x46a, 8);
        for (slot = 0; slot < 8; slot++) {
            func_ov023_021f65d4(obj, slot + 0x459, 8);
            func_ov023_021f65d4(obj, slot + 0x461, 8);
        }
    }

    for (slot = 0; slot < 8; slot++) {
        Element0215a31c* elem = ((Element0215a31c*)ItemTable_Find(items, keys[slot]));
        Struct_ov004_0215a31c* node = ((Struct_ov004_0215a31c*)func_ov004_02156f04(obj, slot + 0x44c));
        if (!elem) {
            node->flags |= 8;
            func_ov023_021f65d4(obj, slot + 0x459, 8);
            func_ov023_021f65d4(obj, slot + 0x461, 8);
            ((Type_ov004_0215a31c)func_ov023_021f9b30)(grid, 0, (unsigned short)slot, 0);
        } else {
            void* data = elem->data ? elem->data : 0;
            if (node) {
                node->flags &= ~8;
                node->data = data;
                ((Type_ov004_0215a31c)func_ov023_021f9b30)(grid, (unsigned short)(slot + 0x44c), (unsigned short)slot, 0);
            }
        }
    }
    func_ov023_021f9ba8(grid, 0);
    void* list = func_ov004_02156f6c(obj, 0x17);
    if (list) func_ov023_021f809c(list, obj);
    void* var18 = func_ov004_02157088(obj, 7);
    if (var18) func_ov023_021dcae0((Struct_ov003_02178910*)var18, -1);
    return 0;
}
extern "C" int func_ov004_021571d8(int a);
extern "C" void* func_0207c5f8(unsigned char*, unsigned int);
extern "C" void* func_0207c60c(void*, unsigned int);
extern "C" void func_ov023_021f65d4(void* obj, int key, int mask);

struct Struct_ov004_0215a738 {
    char pad0[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
    char pad1[0x34];
    short unknown_5c_;
    short unknown_5e_;
};

struct Element020de650_0215a738 {
    char pad[4];
    int field4;
};

struct Struct_ov004_0215a738_3 {
    char pad[0xc];
    unsigned char flags;
    char pad2[0x13];
    int field20;
};

class Struct_ov004_0215a738_4 {
public:
    virtual void v00(); virtual void inline_ov004_0215a738_2(); virtual void inline_ov004_0215a738_3(); virtual void inline_ov004_0215a738_4();
    virtual void v04(); virtual void inline_ov004_0215a738_6(); virtual void inline_ov004_0215a738_7(); virtual void inline_ov004_0215a738_8();
    virtual void v08(); virtual void inline_ov004_0215a738_10(); virtual void v10(); virtual void inline_ov004_0215a738_12();
    virtual void inline_ov004_0215a738_13(); virtual void inline_ov004_0215a738_14(); virtual void v14(); virtual void inline_ov004_0215a738_16();
    virtual void inline_ov004_0215a738_17(); virtual void inline_ov004_0215a738_18(); virtual void v18(); virtual void inline_ov004_0215a738_20();
    virtual void v20(); virtual void inline_ov004_0215a738_22(); virtual void inline_ov004_0215a738_23(); virtual void inline_ov004_0215a738_24();
    virtual void v24(); virtual void inline_ov004_0215a738_26(); virtual void inline_ov004_0215a738_27(); virtual void inline_ov004_0215a738_28();
    virtual void v28(); virtual void inline_ov004_0215a738_30(); virtual void v30(); virtual void inline_ov004_0215a738_32();
    virtual void inline_ov004_0215a738_33(); virtual void inline_ov004_0215a738_34(); virtual void v34(); virtual void inline_ov004_0215a738_36();
    virtual void inline_ov004_0215a738_37(); virtual void inline_ov004_0215a738_38(); virtual void v38(); virtual void inline_ov004_0215a738_40();
    virtual void v40(); virtual void inline_ov004_0215a738_42(); virtual void inline_ov004_0215a738_43(); virtual void inline_ov004_0215a738_44();
    virtual void v44(); virtual void inline_ov004_0215a738_46(); virtual void inline_ov004_0215a738_47(); virtual void inline_ov004_0215a738_48();
    virtual void v48(); virtual void inline_ov004_0215a738_50(); virtual void v50(); virtual void inline_ov004_0215a738_52();
    virtual void inline_ov004_0215a738_53(); virtual void inline_ov004_0215a738_54(); virtual void v54(); virtual void inline_ov004_0215a738_56();
    virtual void inline_ov004_0215a738_57(int n);
};

// USA: func_ov004_0215a738
extern "C" ARM int func_ov004_0215a738(void* obj) {
    short base;
    short saved;
    GameState* bs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GameState_GetParty(bs);
    if (!p) return 0;
    Struct_ov004_0215a738* grid = ((Struct_ov004_0215a738*)func_ov004_02156ed0(obj, 0x63));
    base = grid->unknown_5c_;
    saved = grid->unknown_5e_;
    short* keys;
    signed char* bytes;
    if (func_ov004_021571d8((int)obj)) {
        int idx = func_ov004_02156e2c(obj, 0x65);
        if (idx < 0) return 0;
        keys = (short*)func_0207c5f8(p + 0x1d4, *(data_ov004_021707e0 + idx + 0x7c));
        bytes = (signed char*)func_0207c60c(p + 0x1d4, *(data_ov004_021707e0 + idx + 0x7c));
    } else {
        if (((int)func_ov004_02157128(obj)) >= 0) return 0;
        keys = (short*)(p + 0xc);
        bytes = (signed char*)(p + 0x13c);
    }
    ItemTable* node = (ItemTable*)((void*)func_ov004_02156fd4(obj, 5));
    for (int i = 0; i < 8; i++) {
        int k = i + base * 8;
        Element020de650_0215a738* elem = ((Element020de650_0215a738*)ItemTable_Find(node, keys[k]));
        Struct_ov004_0215a738_3* slot = ((Struct_ov004_0215a738_3*)func_ov004_02156f04(obj, i + 0x44c));
        if (elem == 0) {
            slot->flags |= 8;
            ((Type_ov004_0215a31c)func_ov023_021f9b30)((Struct_ov004_0215a31c_2*)grid, 0, (unsigned short)i, (unsigned short)0);
            func_ov023_021f65d4(obj, i + 0x459, 8);
            func_ov023_021f65d4(obj, i + 0x461, 8);
        } else {
            int v = elem->field4 ? elem->field4 : 0;
            if (slot) {
                slot->flags &= ~8;
                slot->field20 = v;
                ((Type_ov004_0215a31c)func_ov023_021f9b30)((Struct_ov004_0215a31c_2*)grid, i + 0x44c, (unsigned short)i, (unsigned short)0);
                func_ov023_021f6600(obj, i + 0x459, 8);
                func_ov023_021f6600(obj, i + 0x461, 8);
                ((Struct_ov004_0215a738_4*)func_ov004_02156f38(obj, i + 0x461))->inline_ov004_0215a738_57(bytes[k]);
            }
        }
    }
    ((Struct_ov004_0215a738_4*)func_ov004_02156f38(obj, 0x456))->inline_ov004_0215a738_57(base + 1);
    ((Struct_ov004_0215a738_4*)func_ov004_02156f38(obj, 0x457))->inline_ov004_0215a738_57(saved);
    func_ov023_021f6600(obj, 0x456, 8);
    func_ov023_021f6600(obj, 0x457, 8);
    func_ov023_021f6600(obj, 0x469, 8);
    func_ov023_021f6600(obj, 0x46a, 8);
    void* n = func_ov004_02156f6c(obj, 0x17);
    if (n) func_ov023_021f809c(n, obj);
    void* r = (void*)func_ov004_02157088(obj, 7);
    int idx2 = func_ov004_02156e2c(obj, 0x63);
    if (r) func_ov023_021dcae0((Struct_ov003_02178910*)r, keys[idx2 + base * 8]);
    return 0;
}
extern "C" struct GameObject* func_0200ff1c(struct GameState*, int);
struct Struct_0207d300;
extern "C" int func_02083960(struct Struct_0207d300* s);
extern "C" short func_0207c638(void*, unsigned int);

// USA: func_ov004_0215aa10
extern "C" ARM int func_ov004_0215aa10(void* obj) {
    GameState* bs = GameState::GetInstance();
    int result;
    if (func_ov004_021571d8((int)obj)) {
        int idx = func_ov004_02156e2c(obj, 0x65);
        if (idx < 0) return 0;
        void* p = GameState_GetParty(bs);
        if (!p) return 0;
        unsigned char key = *(data_ov004_021707e0 + idx + 0x7c);
        result = func_0207c638((char*)p + 0x1d4, key);
        *(int*)(data_ov004_021707e0 + 0x74) = key;
    } else {
        int val = ((int)func_ov004_02157128(obj));
        if (val == -1) {
            void* p = GameState_GetParty(bs);
            if (!p) return 0;
            result = func_020a0b8c((struct Struct_020a0b8c*)p);
        } else {
            GameObject* c = func_0200ff1c(bs, val);
            if (!c) return 0;
            int var8 = func_02053c6c((unsigned char*)c);
            result = func_02083960((struct Struct_0207d300*)var8);
        }
    }
    if (result > 0) {
        func_ov011_021848a0(obj, 0x6a);
    }
    return 0;
}

struct Struct_ov004_0215aaf0 { char pad[0x5c]; short unknown_5c_; };

struct Struct_ov004_0215aaf0_2 { unsigned int unknown_0_0_ : 12; unsigned int field2 : 2; unsigned int rest : 18; };
struct Element020de650_0215aaf0 { char pad[8]; Struct_ov004_0215aaf0_2 bits; };

extern "C" int func_020de194(void* s);

// USA: func_ov004_0215aaf0
extern "C" ARM int func_ov004_0215aaf0(void* obj) {
    GameState* bs = GameState::GetInstance();
    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    unsigned char* ptr2a04 = (unsigned char*)GameState_GetParty(bs);
    if (!ptr2a04) return 0;

    int idx = func_ov004_02156e2c(obj, 0x63);
    if (idx < 0) return 0;

    Struct_ov004_0215aaf0* var4 = ((Struct_ov004_0215aaf0*)func_ov004_02156ed0(obj, 0x63));
    int slot = idx + var4->unknown_5c_ * 8;

    struct Element020de650_0215aaf0* elem;

    if (func_ov004_021571d8((int)obj)) {
        unsigned char* keyArr = (unsigned char*)func_0207c5f8(ptr2a04 + 0x1d4, *(unsigned int*)(data_ov004_021707e0 + 0x74));
        unsigned char* var8 = (unsigned char*)func_0207c60c(ptr2a04 + 0x1d4, *(unsigned int*)(data_ov004_021707e0 + 0x74));
        elem = ((struct Element020de650_0215aaf0*)ItemTable_Find(node, ((short*)keyArr)[slot]));
        if (elem->bits.field2 == 0) {
            func_ov011_021848a0(obj, 0x3a1);
            return 0;
        }
        *(short*)(data_ov004_021707e0 + 0x6c) = ((short*)keyArr)[slot];
        data_ov004_021707e0[0x6f] = *(signed char*)(var8 + slot);
    } else {
        int flagVal = ((int)func_ov004_02157128(obj));
        if (flagVal == -1) {
            elem = ((struct Element020de650_0215aaf0*)ItemTable_Find(node, *(short*)(ptr2a04 + slot * 2 + 0xc)));
            if (elem->bits.field2 == 0) {
                func_ov011_021848a0(obj, 0x3a1);
                return 0;
            }
            *(short*)(data_ov004_021707e0 + 0x6c) = ((short*)(ptr2a04 + 0xc))[slot];
            unsigned char* var10 = ptr2a04 + slot + 0x100;
            data_ov004_021707e0[0x6f] = *(signed char*)(var10 + 0x3c);
        } else {
            GameObject* combatant = func_0200ff1c(bs, flagVal);
            if (!combatant) return 0;
            int field150 = func_02053c6c((unsigned char*)combatant);
            elem = ((struct Element020de650_0215aaf0*)ItemTable_Find(node, ((short*)((char*)field150 + 0x400 + 0x54))[idx]));
            if (elem->bits.field2 == 0) {
                func_ov011_021848a0(obj, 0x3a1);
                return 0;
            }
            *(short*)(data_ov004_021707e0 + 0x6c) = ((short*)((char*)field150 + 0x400 + 0x54))[idx];
            data_ov004_021707e0[0x6f] = 1;
        }
        data_ov004_021707e0[0x70] = (unsigned char)flagVal;
    }

    int var13 = func_020de194(elem);
    int var14 = (int)((float)(unsigned int)var13 * 0.75f);
    *(int*)(data_ov004_021707e0 + 0x78) = var14;
    data_ov004_021707e0[0x6e] = 1;
    func_ov011_021848a0(obj, 0x6c);
    return 0;
}
extern "C" void func_ov023_021fb27c(void* node, int val);

// USA: func_ov004_0215ad34
extern "C" ARM int func_ov004_0215ad34(void* obj) {
    struct Element020de650* elem = ItemTable_Find(((struct ItemTable*)func_ov004_02156fd4(obj, 5)), *(short*)(((char*)data_ov004_021707e0) + 0x6c));
    int val;
    int i;
    if (elem == NULL) return 0;
    val = *(int*)(((char*)data_ov004_021707e0) + 0x78);
    for (i = 0; i < 7; i++) {
        signed char digit = val % 10;
        *(signed char*)(((char*)data_ov004_021707e0) + i + 0x3f) = digit;
        val = val / 10;
        void* node = func_ov004_02156fa0(obj, i + 0x2d);
        if (node != NULL) {
            signed char d = *(signed char*)(((char*)data_ov004_021707e0) + i + 0x3f);
            func_ov023_021fb27c(node, (unsigned short)(d + 0x1a));
        }
    }
    *(signed char*)(((char*)data_ov004_021707e0) + 0x3e) = 0;
    return 0;
}

extern "C" double _dflt(int);
extern "C" double func_020095a4(double, double);
extern "C" int _dfix(double);

// USA: func_ov004_0215adf8
extern "C" ARM int func_ov004_0215adf8(void* obj) {
    int i;
    *(int*)(((char*)data_ov004_021707e0) + 0x78) = 0;
    for (i = 0; i < 7; i++) {
        double var1 = _dflt(i);
        int weight = _dfix(func_020095a4(10.0, var1));
        signed char digit = *(signed char*)(((char*)data_ov004_021707e0) + i + 0x3f);
        int total = *(int*)(((char*)data_ov004_021707e0) + 0x78);
        total = weight * digit + total;
        *(int*)(((char*)data_ov004_021707e0) + 0x78) = total;
    }
    *(unsigned char*)(((char*)data_ov004_021707e0) + 0x6e) = 1;
    if (*(unsigned char*)(((char*)data_ov004_021707e0) + 0x6f) == 1) {
        func_ov011_021848a0(obj, 0x39c);
    } else {
        func_ov011_021848a0(obj, 0x6d);
    }
    return 0;
}

// USA: func_ov004_0215aea8
extern "C" ARM int func_ov004_0215aea8(void* obj) {
    char* ptr = ((char*)data_ov004_021707e0);
    signed char* arr = (signed char*)(ptr + 0x3f);
    unsigned char idx = *(unsigned char*)(ptr + 0x3e);
    signed char v = arr[idx];
    v = v + 1;
    arr[idx] = v;
    v = arr[idx];
    if (v >= 10) {
        v = 0;
        arr[idx] = v;
    }
    void* node = func_ov004_02156fa0(obj, *(unsigned char*)(((char*)data_ov004_021707e0) + 0x3e) + 0x2d);
    if (node) {
        signed char d = arr[idx];
        func_ov023_021fb27c(node, (unsigned short)(d + 0x1a));
    }
    return 0;
}

// USA: func_ov004_0215af14
extern "C" ARM int func_ov004_0215af14(void* obj) {
    char* ptr = ((char*)data_ov004_021707e0);
    signed char* arr = (signed char*)(ptr + 0x3f);
    unsigned char idx = *(unsigned char*)(ptr + 0x3e);
    signed char v = arr[idx];
    v = v - 1;
    arr[idx] = v;
    v = arr[idx];
    if (v < 0) {
        v = 9;
        arr[idx] = v;
    }
    void* node = func_ov004_02156fa0(obj, *(unsigned char*)(((char*)data_ov004_021707e0) + 0x3e) + 0x2d);
    if (node) {
        signed char d = arr[idx];
        func_ov023_021fb27c(node, (unsigned short)(d + 0x1a));
    }
    return 0;
}

class Struct_ov004_0215af80 {
public:
    virtual void v00(); virtual void inline_ov004_0215af80_2(); virtual void inline_ov004_0215af80_3(); virtual void inline_ov004_0215af80_4();
    virtual void v04(); virtual void inline_ov004_0215af80_6(); virtual void inline_ov004_0215af80_7(); virtual void inline_ov004_0215af80_8();
    virtual void v08(); virtual void inline_ov004_0215af80_10(); virtual void v10(); virtual void inline_ov004_0215af80_12();
    virtual void inline_ov004_0215af80_13(); virtual void inline_ov004_0215af80_14(); virtual void v14(); virtual void inline_ov004_0215af80_16();
    virtual void inline_ov004_0215af80_17(); virtual void inline_ov004_0215af80_18(); virtual void v18(); virtual void inline_ov004_0215af80_20();
    virtual void v20(); virtual void inline_ov004_0215af80_22(); virtual void inline_ov004_0215af80_23(); virtual void inline_ov004_0215af80_24();
    virtual void v24(); virtual void inline_ov004_0215af80_26(); virtual void inline_ov004_0215af80_27(); virtual void inline_ov004_0215af80_28();
    virtual void v28(); virtual void inline_ov004_0215af80_30(); virtual void v30(); virtual void inline_ov004_0215af80_32();
    virtual void inline_ov004_0215af80_33(); virtual void inline_ov004_0215af80_34(); virtual void v34(); virtual void inline_ov004_0215af80_36();
    virtual void inline_ov004_0215af80_37(); virtual void inline_ov004_0215af80_38(); virtual void v38(); virtual void inline_ov004_0215af80_40();
    virtual void v40(); virtual void inline_ov004_0215af80_42(); virtual void inline_ov004_0215af80_43(); virtual void inline_ov004_0215af80_44();
    virtual void v44(); virtual void inline_ov004_0215af80_46(); virtual void inline_ov004_0215af80_47(); virtual void inline_ov004_0215af80_48();
    virtual void v48(); virtual void inline_ov004_0215af80_50(); virtual void v50(); virtual void inline_ov004_0215af80_52();
    virtual void inline_ov004_0215af80_53(); virtual void inline_ov004_0215af80_54(); virtual void v54(); virtual void inline_ov004_0215af80_56();
    virtual void inline_ov004_0215af80_57(int n);
};

// USA: func_ov004_0215af80
extern "C" ARM int func_ov004_0215af80(void* a) {
    Struct_ov004_0215af80* node = (Struct_ov004_0215af80*)func_ov004_02156f38(a, 0x25a);
    if (node) {
        node->inline_ov004_0215af80_57(data_ov004_021707e0[0x6e]);
    }
    Struct_ov004_0215af80* node2 = (Struct_ov004_0215af80*)func_ov004_02156f38(a, 0x2bd);
    if (node2) {
        node2->inline_ov004_0215af80_57(*(int*)(data_ov004_021707e0 + 0x78));
    }
    return 0;
}

// USA: func_ov004_0215aff0
extern "C" ARM int func_ov004_0215aff0(void* a) {
    if (data_ov004_021707e0[0x6e] == 1) {
        func_ov011_021848a0(a, 0x39c);
    } else {
        func_ov011_021848a0(a, 0x39b);
    }
    return 0;
}

typedef void (*Type_01ff8b48_13)(void*, int);
struct Struct_ov004_0215b02c { char pad[0xe0]; Type_01ff8b48_13 func; };
struct Struct_ov004_0215b02c_2 { Struct_ov004_0215b02c* handler; };

// USA: func_ov004_0215b02c
extern "C" ARM int func_ov004_0215b02c(void* obj) {
    if (data_ov004_021707e0[0x6e] < data_ov004_021707e0[0x6f]) {
        data_ov004_021707e0[0x6e]++;
        Struct_ov004_0215b02c_2* node = ((Struct_ov004_0215b02c_2*)func_ov004_02156f38(obj, 0x25a));
        if (node) {
            node->handler->func(node, data_ov004_021707e0[0x6e]);
        }
        int result = ((int)func_ov004_02156f6c(obj, 0x19));
        if (result) {
            func_ov023_021f809c((void*)result, obj);
        }
    }
    return 0;
}

class Struct_ov004_0215b0a8 {
public:
    virtual void v00(); virtual void inline_ov004_0215b0a8_2(); virtual void inline_ov004_0215b0a8_3(); virtual void inline_ov004_0215b0a8_4();
    virtual void v04(); virtual void inline_ov004_0215b0a8_6(); virtual void inline_ov004_0215b0a8_7(); virtual void inline_ov004_0215b0a8_8();
    virtual void v08(); virtual void inline_ov004_0215b0a8_10(); virtual void v10(); virtual void inline_ov004_0215b0a8_12();
    virtual void inline_ov004_0215b0a8_13(); virtual void inline_ov004_0215b0a8_14(); virtual void v14(); virtual void inline_ov004_0215b0a8_16();
    virtual void inline_ov004_0215b0a8_17(); virtual void inline_ov004_0215b0a8_18(); virtual void v18(); virtual void inline_ov004_0215b0a8_20();
    virtual void v20(); virtual void inline_ov004_0215b0a8_22(); virtual void inline_ov004_0215b0a8_23(); virtual void inline_ov004_0215b0a8_24();
    virtual void v24(); virtual void inline_ov004_0215b0a8_26(); virtual void inline_ov004_0215b0a8_27(); virtual void inline_ov004_0215b0a8_28();
    virtual void v28(); virtual void inline_ov004_0215b0a8_30(); virtual void v30(); virtual void inline_ov004_0215b0a8_32();
    virtual void inline_ov004_0215b0a8_33(); virtual void inline_ov004_0215b0a8_34(); virtual void v34(); virtual void inline_ov004_0215b0a8_36();
    virtual void inline_ov004_0215b0a8_37(); virtual void inline_ov004_0215b0a8_38(); virtual void v38(); virtual void inline_ov004_0215b0a8_40();
    virtual void v40(); virtual void inline_ov004_0215b0a8_42(); virtual void inline_ov004_0215b0a8_43(); virtual void inline_ov004_0215b0a8_44();
    virtual void v44(); virtual void inline_ov004_0215b0a8_46(); virtual void inline_ov004_0215b0a8_47(); virtual void inline_ov004_0215b0a8_48();
    virtual void v48(); virtual void inline_ov004_0215b0a8_50(); virtual void v50(); virtual void inline_ov004_0215b0a8_52();
    virtual void inline_ov004_0215b0a8_53(); virtual void inline_ov004_0215b0a8_54(); virtual void v54(); virtual void inline_ov004_0215b0a8_56();
    virtual void inline_ov004_0215b0a8_57(int n);
};

// USA: func_ov004_0215b0a8
extern "C" ARM int func_ov004_0215b0a8(void* obj) {
    unsigned char cur = data_ov004_021707e0[0x6e];
    if (cur <= 1) {
        goto end;
    }
    data_ov004_021707e0[0x6e] = cur - 1;
    {
        Struct_ov004_0215b0a8* node = (Struct_ov004_0215b0a8*)func_ov004_02156f38(obj, 0x25a);
        if (node) {
            node->inline_ov004_0215b0a8_57(data_ov004_021707e0[0x6e]);
        }
    }
    {
        void* node2 = func_ov004_02156f6c(obj, 0x19);
        if (node2) {
            func_ov023_021f809c(node2, obj);
        }
    }
end:
    return 0;
}

#if defined(jpn)
struct Container020e0310;
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

struct Element020de650_0215b120 {
    unsigned char unknown0[0x18];
    short key;
    unsigned char unknown_1a_[6];
};

#if defined(jpn)
struct Struct_020e0028 { int key; int value; };
struct Container020e0310 {
    unsigned int count : 12;
    unsigned int rest : 20;
    Struct_020e0028* base;
};
typedef Container020e0310 Struct_ov004_0215b120_2;
#else
struct Struct_01ff8b48_19 {
    void* first;
    void* second;
    unsigned int unknown8;
    unsigned short key;
    unsigned short unknownE;
};
struct Struct_ov004_0215b120_2 {
    unsigned int count : 12;
    unsigned int rest : 20;
    Struct_01ff8b48_19* entries;
};
#endif
struct ItemSelection0215b120 {
    unsigned char unknown0[0x6c];
    short itemId;
    unsigned char unknown_6e_;
    unsigned char unknown_6f_;
    unsigned char unknown_70_[8];
    int value;
    unsigned char unknown_7c_[0x10];
    Struct_ov004_0215b120_2 names;
};

// USA: func_ov004_0215b120
extern "C" ARM int func_ov004_0215b120(void* self) {
    void* g = (void*)MessageSystem_GetInstance();
    func_02046380(g);

    struct ItemTable* c = ((struct ItemTable*)func_ov004_02156fd4(self, 5));
    struct Element020de650_0215b120* elem = ((struct Element020de650_0215b120*)ItemTable_Find(c, ((ItemSelection0215b120*)data_ov004_021707e0)->itemId));

    ItemSelection0215b120* selection = ((ItemSelection0215b120*)data_ov004_021707e0);
    unsigned char var4 = selection->unknown_6e_;
    Struct_ov004_0215b120_2* names = &selection->names;

    if (var4 == 1) {
#if defined(jpn)
        char name[80];
        func_020e207c(names, name, elem->key);
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        void* r = func_020e5294(names, elem->key);
        *(void**)((char*)g + 0x18) = r;
#endif
        func_020465c0((struct StoreStruct*)g, 0, ((ItemSelection0215b120*)data_ov004_021707e0)->value);
    } else {
#if defined(jpn)
        char name[80];
        func_020e207c(names, name, elem->key);
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        void* r = func_020e5294(names, elem->key);
        *(void**)((char*)g + 0x18) = r;
#endif
        func_020465c0((struct StoreStruct*)g, 0, ((ItemSelection0215b120*)data_ov004_021707e0)->value);
        func_020465c0((struct StoreStruct*)g, 1, ((ItemSelection0215b120*)data_ov004_021707e0)->unknown_6e_);
    }
    return 0;
}
struct Struct_02061c04_23;
extern "C" int func_020a0a08(struct Struct_02061c04_23* map, int key, int amount);
struct Struct_020838c4;
extern "C" int func_020838c4(struct Struct_020838c4* s, int value);

struct Struct_ov004_0215b1d4 { unsigned short unknown_0_0_ : 13; unsigned short unknown_1_5_ : 3; };

#if defined(jpn)
extern "C" void* GameState_GetParty(struct GameState*);
extern "C" struct GameObject* func_0200ff1c(struct GameState*, int);

#endif
// USA: func_ov004_0215b1d4
extern "C" ARM int func_ov004_0215b1d4(void* obj) {
    GameState* bs = GameState::GetInstance();
#if defined(jpn)
    char* base = (char*)bs + 0xc + 0x5c00;
#else
    char* base = (char*)bs + 0x26c + 0x5c00;
#endif

    *(short*)(base + 0xf8) = *(short*)(data_ov004_021707e0 + 0x6c);
    *(short*)(base + 0xfa) = *(unsigned char*)(data_ov004_021707e0 + 0x6e);
    *(short*)(base + 0xfc) = *(int*)(data_ov004_021707e0 + 0x78);

    int cnt = *(int*)(data_ov004_021707e0 + 0x74);
    if (cnt >= 0) {
        void* result = GameState_GetParty(bs);
        if (!result) return 0;
        short key = *(short*)(data_ov004_021707e0 + 0x6c);
        signed char var5 = *(signed char*)(data_ov004_021707e0 + 0x6e);
        int key2 = *(int*)(data_ov004_021707e0 + 0x74);
        func_0207c484((struct Struct_0207c484*)((char*)result + 0x1d4), key, var5, key2);
    } else if (*(signed char*)(data_ov004_021707e0 + 0x70) == -1) {
        void* result = GameState_GetParty(bs);
        if (!result) return 0;
        short key = *(short*)(data_ov004_021707e0 + 0x6c);
        signed char var9 = *(signed char*)(data_ov004_021707e0 + 0x6e);
        func_020a0a08((struct Struct_02061c04_23*)result, key, var9);
    } else {
        int combatantId = *(signed char*)(data_ov004_021707e0 + 0x70);
        GameObject* c = func_0200ff1c(bs, combatantId);
        if (!c) return 0;
        int field = func_02053c6c((unsigned char*)c);
        short key = *(short*)(data_ov004_021707e0 + 0x6c);
        func_020838c4((struct Struct_020838c4*)field, key);
    }

    func_ov004_0215a2f8(data_ov004_021707e0);

    Struct_ov004_0215b1d4* bits = (Struct_ov004_0215b1d4*)(base + 0x10c);
    bits->unknown_0_0_ |= 0x10;

    unsigned char v = *(data_ov004_021707e0 + 0x6e);
    if (v > 1) {
        func_ov011_021848a0(obj, 0x2423);
    } else {
        func_ov011_021848a0(obj, 0x39d);
    }
    return 0;
}

// USA: func_ov004_0215b330
extern "C" ARM void* func_ov004_0215b330(void* obj) {
    func_ov004_0215a2f8(data_ov004_021707e0);
    func_ov011_021848a0(obj, 0x39e);
    return 0;
}

struct Struct_ov004_0215b360 {
    virtual void inline_ov004_0215b360();
    virtual void inline_ov004_0215b360_2();
    virtual void inline_ov004_0215b360_3();
    virtual void inline_ov004_0215b360_4();
    virtual void inline_ov004_0215b360_5();
    virtual void inline_ov004_0215b360_6();
    virtual void inline_ov004_0215b360_7();
    virtual void inline_ov004_0215b360_8();
    virtual void inline_ov004_0215b360_9();
    virtual void inline_ov004_0215b360_10();
    virtual void inline_ov004_0215b360_11();
    virtual void inline_ov004_0215b360_12();
    virtual void inline_ov004_0215b360_13();
    virtual void inline_ov004_0215b360_14();
    virtual void inline_ov004_0215b360_15();
    virtual void inline_ov004_0215b360_16();
    virtual void inline_ov004_0215b360_17();
    virtual void inline_ov004_0215b360_18();
    virtual void inline_ov004_0215b360_19();
    virtual void inline_ov004_0215b360_20();
    virtual void inline_ov004_0215b360_21();
    virtual void inline_ov004_0215b360_22();
    virtual void inline_ov004_0215b360_23();
    virtual void inline_ov004_0215b360_24();
    virtual void inline_ov004_0215b360_25();
    virtual void inline_ov004_0215b360_26();
    virtual void inline_ov004_0215b360_27();
    virtual void inline_ov004_0215b360_28();
    virtual void inline_ov004_0215b360_29();
    virtual void inline_ov004_0215b360_30();
    virtual void inline_ov004_0215b360_31();
    virtual void inline_ov004_0215b360_32();
    virtual void inline_ov004_0215b360_33();
    virtual void inline_ov004_0215b360_34();
    virtual void inline_ov004_0215b360_35();
    virtual void inline_ov004_0215b360_36();
    virtual void inline_ov004_0215b360_37();
    virtual void inline_ov004_0215b360_38();
    virtual void inline_ov004_0215b360_39();
    virtual void inline_ov004_0215b360_40();
    virtual void inline_ov004_0215b360_41();
    virtual void inline_ov004_0215b360_42();
    virtual void inline_ov004_0215b360_43();
    virtual void inline_ov004_0215b360_44();
    virtual void inline_ov004_0215b360_45();
    virtual void inline_ov004_0215b360_46();
    virtual void inline_ov004_0215b360_47();
    virtual void inline_ov004_0215b360_48();
    virtual void inline_ov004_0215b360_49();
    virtual void inline_ov004_0215b360_50();
    virtual void inline_ov004_0215b360_51();
    virtual void inline_ov004_0215b360_52();
    virtual void inline_ov004_0215b360_53();
    virtual void inline_ov004_0215b360_54();
    virtual void inline_ov004_0215b360_55();
    virtual void inline_ov004_0215b360_56();
    virtual void notify(int);
    char unknown_4[8];
    unsigned char flags;
    char unknown_d_[0x20 - 0xd];
    void* value;
};
struct Struct_ov004_0215b360_2 {
    char unknown_0[0x5c];
    short page, pages;
};
struct Struct_ov004_0215b360_3 {
    char unknown_0[0x7c];
    unsigned char unknown_7c_[8];
};
struct PartyState0215b360 {
    char unknown_0[0x1d4];
    unsigned char inventory[1];
};
struct Element020de650_0215b360 {
    unsigned int field_0;
    void* value;
};
extern "C" int func_ov004_02156e2c(void*, int);
extern "C" void func_ov023_021f65d4(void*, int, int);
typedef void (*Type_ov004_021561b0)(Struct_ov004_0215b360_2*, unsigned short, unsigned int, unsigned int);
typedef void* (*Type_ov004_0215b360)(void*, int);

// USA: func_ov004_0215b360
extern "C" ARM int func_ov004_0215b360(void* object) {
    short* items = NULL;
    signed char* var1 = NULL;
    int count = 0;
    ItemTable* container = ((ItemTable*)func_ov004_02156fd4(object, 5));
    TableA68* table = ((TableA68*)func_ov004_02157018(object, 3));
    int selected = func_ov004_02156e2c(object, 0x65);
    if (selected < 0) return 0;
    PartyState0215b360* party = (PartyState0215b360*)GameState_GetParty(GameState::GetInstance());
    if (!party) return 0;
    for (int i = 0; i < 8; i++) {
        if (i == selected) {
            Struct_ov004_0215b360* node = ((Struct_ov004_0215b360*)func_ov004_02156f04(object, 0x454));
            if (node) node->value = func_02072a68(table, (short)(i + 0x1b));
            func_ov023_021f6600(object, i + 0x38c, 8);
            items = ((short*)func_0207c5f8(party->inventory, ((Struct_ov004_0215b360_3*)data_ov004_021707e0)->unknown_7c_[selected]));
            var1 = ((signed char*)func_0207c60c(party->inventory, ((Struct_ov004_0215b360_3*)data_ov004_021707e0)->unknown_7c_[selected]));
            count = ((int)func_0207c638(party->inventory, ((Struct_ov004_0215b360_3*)data_ov004_021707e0)->unknown_7c_[selected]));
        } else {
            func_ov023_021f65d4(object, i + 0x38c, 8);
        }
    }
    Struct_ov004_0215b360_2* grid = ((Struct_ov004_0215b360_2*)func_ov004_02156ed0(object, 0x63));
    if (!grid) return 0;
    short pages = (count - 1) / 8 + 1;
    if (pages < 1) pages = 1;
    grid->page = 0;
    grid->pages = pages;
    ((Struct_ov004_0215b360*)func_ov004_02156f38(object, 0x456))->notify(1);
    ((Struct_ov004_0215b360*)func_ov004_02156f38(object, 0x457))->notify(pages);
    for (int i = 0; i < 8; i++)
        ((Struct_ov004_0215b360*)func_ov004_02156f38(object, i + 0x461))->notify(var1[i]);
    for (int i = 0; i < 8; i++) {
        Element020de650_0215b360* entry = ((Element020de650_0215b360*)ItemTable_Find(container, items[i]));
        Struct_ov004_0215b360* node = ((Struct_ov004_0215b360*)func_ov004_02156f04(object, i + 0x44c));
        if (!entry) {
            node->flags |= 8;
            func_ov023_021f65d4(object, i + 0x459, 8);
            func_ov023_021f65d4(object, i + 0x461, 8);
            func_ov023_021f9b30((Struct_ov004_02153e20*)grid, 0, (unsigned short)i, 0);
        } else {
            void* value = entry->value ? entry->value : NULL;
            if (node) {
                node->flags &= ~8;
                node->value = value;
                func_ov023_021f6600(object, i + 0x459, 8);
                func_ov023_021f6600(object, i + 0x461, 8);
                ((Type_ov004_021561b0)func_ov023_021f9b30)(grid, (unsigned short)(i + 0x44c), (unsigned short)i, 0);
            }
        }
    }
    void* node = func_ov004_02156f6c(object, 0x17);
    if (node) func_ov023_021f809c(node, object);
    void* var17 = ((Type_ov004_0215b360)func_ov004_02157088)(object, 7);
    if (var17) func_ov023_021dcae0((Struct_ov003_02178910*)var17, -1);
    return 0;
}
extern "C" int func_0207c51c(unsigned char* base, int key);

// USA: func_ov004_0215b694
extern "C" ARM int func_ov004_0215b694(void* obj) {
    void* ptr = GameState_GetParty(GameState::GetInstance());
    if (!ptr) {
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        int key = *(data_ov004_021707e0 + i + 0x7c);
        func_0207c51c((unsigned char*)ptr + 0x1d4, key);
    }
    func_ov004_0215a2f8(data_ov004_021707e0);
    func_ov011_021848a0(obj, 0x3a0);
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}

// USA: func_ov004_0215b710
extern "C" ARM int func_ov004_0215b710(void* obj) {
    int id = func_ov004_02156e2c(obj, 0x65);
    if (id >= 0) {
        func_ov023_021f6600(obj, id + 0x38c, 8);
    }
    return 0;
}
extern "C" void func_0207d300(void* buf, int a, int b, int c);
extern "C" void func_ov004_0215b7c8(struct Struct_ov004_0215b740*);

// USA: func_ov004_0215b740
extern "C" ARM int func_ov004_0215b740(void* obj) {
#if defined(jpn)
    enum { Enum_ov004_0215b740_620 = 0xc };
#else
    enum { Enum_ov004_0215b740_620 = 0x26c };
#endif
    char* p = (char*)GameState::GetInstance() + Enum_ov004_0215b740_620 + 0x5c00;
    void* node = ((void*)func_ov004_02156fd4(obj, 5));
    char buf[0x38];
    ((SafeAllocator*)buf)->ResetAllocatorPointer();
    ItemTable_Construct(buf + 0x14);
    func_0207cbe8(buf);
    func_0207cbe8(buf);
    *(void**)(buf + 0x2c) = node;
    short a = *(short*)(p + 0xf8);
    signed char b = *(unsigned short*)(p + 0xfa);
    func_0207d300(buf, a, b, 0);
    func_ov004_0215b7c8((Struct_ov004_0215b740*)(p + 0xf8));
    func_ov011_021848a0(obj, 0x3a4);
    return 0;
}

struct Struct_ov004_0215b740 { short a, b, c; };

// USA: func_ov004_0215b7c8
extern "C" ARM void func_ov004_0215b7c8(Struct_ov004_0215b740* s) {
    s->a = -1;
    s->b = 0;
    s->c = 0;
}

// USA: func_ov004_0215b7e0
extern "C" ARM int func_ov004_0215b7e0(void* obj) {
    func_ov011_021848a0(obj, 0x3a5);
    return 0;
}

#if defined(jpn)
enum { Enum_ov004_0215b7f8_620 = 0xc, Enum_ov004_0215b7f8_2456 = 0x868 };
#else
enum { Enum_ov004_0215b7f8_620 = 0x26c, Enum_ov004_0215b7f8_2456 = 0x998 };
#endif

struct State0215b7f8 {
    char unknown_0_[0x18];
    Struct_ov004_021589e8 key;
    char unknown_1c_[0x14];
    unsigned char saved;
    char unknown_31_[9];
    short count;
};

struct Struct_ov004_0215b7f8_2 {
    Struct_ov004_021589e8 handle;
    char pad4[0xc];
    int size;
    char name[0x200];
    char data[0x200];
};
struct Struct_ov004_0215b7f8_3 { char pad[0x100]; Struct_ov004_0215b7f8_2 slot; };
struct Struct_ov004_0215b7f8_4 { char pad[Enum_ov004_0215b7f8_620 + 0x5d00]; Struct_ov004_0215b7f8_2 slot; };

struct TextRenderer0215b7f8 {
    char pad[Enum_ov004_0215b7f8_2456];
    int unknown_998_;
    int unknown_99c_;
};
extern "C" int LinkSession_IsHostOrSolo(struct CheckField0AndGlobalHalfStruct0202c508*);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif

static inline void inline_ov004_0215b7f8(char* dst, const char* src) {
    int len = strlen(src);
    const char* s = "<PAD_WAIT><ADD>";
    memcpy(dst, src, len);
    strcpy(dst + len, s);
}

#if defined(jpn)
extern "C" void func_02096660(FontBankLoader*, int, char*, int);
#endif

// USA: func_ov004_0215b7f8
extern "C" ARM int func_ov004_0215b7f8(void* obj) {
    if (!((struct TableA68*)func_ov004_02157018(obj, 4))) return 0;
    GameState* gs = GameState::GetInstance();
    Struct_ov004_0215b7f8_3* battle = (Struct_ov004_0215b7f8_3*)((char*)gs + Enum_ov004_0215b7f8_620 + 0x5c00);
    if (LinkSession_IsHostOrSolo((CheckField0AndGlobalHalfStruct0202c508*)(LinkSession_GetInstance())) && func_ov017_021b213c(battle->slot.handle, ((State0215b7f8*)data_ov004_021707e0)->key)) {
        char data[0x200];
        char text[0x220];
        int size = ((Struct_ov004_0215b7f8_4*)gs)->slot.size;
        memcpy(data, ((Struct_ov004_0215b7f8_4*)gs)->slot.data, size);
#if defined(jpn)
        func_02096660(FontBankLoader_GetInstance(), 5001, data, size);
#else
        func_02094b54(FontBankLoader_GetInstance(), 5001, data, size);
#endif
        inline_ov004_0215b7f8(text, ((Struct_ov004_0215b7f8_4*)gs)->slot.name);
        TextRenderer0215b7f8* tr = ((TextRenderer0215b7f8*)MessageSystem_GetInstance());
#if defined(jpn)
        func_0204500c(tr, text, 0);
#else
        func_0204500c(tr, text, 0, 0xe3);
#endif
        tr->unknown_998_ = 1;
        tr->unknown_99c_ = 2;
        ((State0215b7f8*)data_ov004_021707e0)->saved = 1;
    }
    short n = ((State0215b7f8*)data_ov004_021707e0)->count;
    int i;
    for (i = 0; i < n; i++) {
    }
    func_ov011_021848a0(obj, n + 0x2486);
    return 0;
}

#if defined(jpn)
enum{Enum_ov004_0215b934_620=0xc};
#else
enum{Enum_ov004_0215b934_620=0x26c};
#endif

struct Struct_ov004_0215b934 {
    char unknown_0_[0x14];
    unsigned char active;
    char pad15[0x77];
    unsigned char table[1];
};

struct Struct_ov004_0215b934_2 {
    short itemId;
    unsigned short count;
    unsigned short unknown_4_;
    char pad6[0xe];
    unsigned short kind : 13;
};

struct Struct_ov004_0215b934_3 {
    char pad[0xf8];
    Struct_ov004_0215b934_2 reward;
};

struct Wallet0215b934 {
    char pad[0xf6c];
    unsigned int unknown_f6c_;
};

struct Element0215b934 {
    char pad[0x18];
    short nameId;
};

struct Message0215b934 {
    char pad[0x18];
    int name;
};
struct Obj02046574;
#if defined(jpn)
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
#else
extern "C" void* func_020e5294(void*, int);
#endif

extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);

// USA: func_ov004_0215b934
extern "C" ARM int func_ov004_0215b934(void* obj) {
    if (((Struct_ov004_0215b934*)data_ov004_021707e0)->active) {
        GameState* gs = GameState::GetInstance();
        Wallet0215b934* wallet = (Wallet0215b934*)GameState_GetParty(gs);
        Element0215b934* elem;
        Message0215b934* msg;
        unsigned int amount;
        Struct_ov004_0215b934_3* area = (Struct_ov004_0215b934_3*)((char*)gs + Enum_ov004_0215b934_620 + 0x5c00);
        if (area->reward.itemId <= 0 || area->reward.count == 0) {
            func_ov011_021848a0(obj, 0x387);
            return 0;
        }
        struct ItemTable* items = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
        elem = ((Element0215b934*)ItemTable_Find(items, area->reward.itemId));
        if (!elem) return 0;
        msg = ((Message0215b934*)MessageSystem_GetInstance());
        func_02046380(msg);
        unsigned int kind = area->reward.kind;
        if (kind & 1) {
            amount = area->reward.count * area->reward.unknown_4_;
            if (9999999 - wallet->unknown_f6c_ < amount) {
                amount = 9999999 - wallet->unknown_f6c_;
            }
            wallet->unknown_f6c_ += amount;
            struct TableA68* names = ((struct TableA68*)func_ov004_02157018(obj, 9));
#if defined(jpn)
            char name[80];
            func_020e207c((Container020e0310*)(((Struct_ov004_0215b934*)data_ov004_021707e0)->table), name, elem->nameId);
            MessageSystem_SetStringArgument((Obj02046574*)msg, 1, name);
#else
            msg->name = ((int)func_020e5294(((Struct_ov004_0215b934*)data_ov004_021707e0)->table, elem->nameId));
#endif
            MessageSystem_SetStringArgument((struct Obj02046574*)msg, 2, ((char*)func_02072a68(names, (short)(rand() % 0x3a))));
            MessageSystem_SetStringArgument((struct Obj02046574*)msg, 3, ((char*)func_02072a68(names, (short)(rand() % 6 + 1000))));
            func_020465c0((struct StoreStruct*)msg, 0, amount);
            func_ov011_021848a0(obj, 0x3a8);
        } else if (kind & 2) {
            char buf[0x38];
            ((SafeAllocator*)buf)->ResetAllocatorPointer();
            ItemTable_Construct(buf + 0x14);
            func_0207cbe8(buf);
            func_0207cbe8(buf);
            func_0207d300(buf, area->reward.itemId, (signed char)area->reward.count, 0);
#if defined(jpn)
            char name[80];
            func_020e207c((Container020e0310*)(((Struct_ov004_0215b934*)data_ov004_021707e0)->table), name, elem->nameId);
            MessageSystem_SetStringArgument((Obj02046574*)msg, 1, name);
#else
            msg->name = ((int)func_020e5294(((Struct_ov004_0215b934*)data_ov004_021707e0)->table, elem->nameId));
#endif
            func_ov011_021848a0(obj, 0x3a9);
        } else {
            func_ov011_021848a0(obj, 0x387);
        }
        func_ov004_0215b7c8((Struct_ov004_0215b740*)(&area->reward));
    } else {
        func_ov011_021848a0(obj, 0x387);
    }
    return 0;
}
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif

#if defined(jpn)
enum { Enum_ov004_0215bb54_15176 = 0x3928, Enum_ov004_0215bb54_2456 = 0x868 };
#else
enum { Enum_ov004_0215bb54_15176 = 0x3b48, Enum_ov004_0215bb54_2456 = 0x998 };
#endif

// USA: func_ov004_0215bb54
extern "C" ARM int func_ov004_0215bb54(void* obj) {
    void* five = *(void**)((unsigned char*)GetGameResources() + Enum_ov004_0215bb54_15176);
    unsigned char flag = data_ov004_021707e0[0x13];
    if (flag == 0) {
        void* obj2 = func_ov011_021845f8((unsigned char*)obj, (int)1);
        if (obj2 == 0) {
            func_ov004_0215a2f8(data_ov004_021707e0);
            func_ov011_021848a0(obj, 0x39e);
            data_ov004_021707e0[0x13] = 0;
            return 0;
        }
        func_ov017_021b1d44((unsigned char*)five, 4, 1);
        *(void**)((char*)five + 8) = (char*)obj2 + 4;
        int fieldB4 = func_ov011_02184548((struct Struct_ov004_0215883c_2*)obj);
        int fieldB0 = func_ov011_02184540((struct Obj_02184540*)obj);
        *(int*)((char*)five + 0x34) = fieldB0;
        *(int*)((char*)five + 0x38) = fieldB4;
        data_ov004_021707e0[0x13]++;
        func_ov011_021848a0(obj, 0x3aa);
        void* node = (void*)func_ov004_02157018(obj, 4);
        int g = MessageSystem_GetInstance();
        void* found = func_02072a68((struct TableA68*)node, 0x13);
#if defined(jpn)
        func_0204500c((void*)g, (const char*)found, 0);
#else
        func_0204500c((void*)g, (const char*)found, 0, 0xe3);
#endif
        *(int*)((char*)g + Enum_ov004_0215bb54_2456) = 1;
    } else if (flag == 1) {
        func_ov011_021848a0(obj, 0x3ab);
        data_ov004_021707e0[0x13]++;
        return 0;
    }
    return 1;
}

#if defined(jpn)
enum { Enum_ov004_0215bc9c_92 = 0x28, Enum_ov004_0215bc9c_2400 = 0x800, Enum_ov004_0215bc9c_2456 = 0x868 };
#else
enum { Enum_ov004_0215bc9c_92 = 0x5c, Enum_ov004_0215bc9c_2400 = 0x960, Enum_ov004_0215bc9c_2456 = 0x998 };
#endif

extern "C" ARM void func_ov004_0215781c(void* obj);
extern "C" ARM int func_ov017_021b1fd4(void* obj);
extern "C" void func_ov004_021571f4(void* obj, int val);
extern "C" ARM void func_ov004_02157874(void* obj);
extern "C" int func_ov017_021b1ffc(Struct_ov004_021583a8_2* obj);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif

// USA: func_ov004_0215bc9c
extern "C" ARM int func_ov004_0215bc9c(void* obj) {
    int g;
    GameResources* resources = GetGameResources();
    void* list = resources->fieldTaskQueue_;
    void* five = resources->fieldTasks_[19];
    void* table = (void*)func_ov004_02157018(obj, 4);
    g = MessageSystem_GetInstance();
    unsigned char flag = data_ov004_021707e0[0x13];

    if (flag == 2) {
        func_ov004_0215781c(obj);
        FieldTask_ConnectWifi(five, (int)list);
        int t = func_ov017_021b1fd4(five) >> 12;
        func_ov004_021571f4(obj, t);
        func_ov017_021b2024((Struct_ov004_021583a8_4*)five);
        func_ov017_021b2038((Struct_ov004_021583a8_5*)five);
        if (*(int*)(resources->unknown_4490_ + 4) == 0) {
            data_ov004_021707e0[0x13]++;
        }
        goto returnOne;
    } else if (flag == 3) {
        func_ov004_02157874(obj);
        char* buf = *(char**)((char*)g + Enum_ov004_0215bc9c_92);
        memset(buf, 0, Enum_ov004_0215bc9c_2400);

        if (func_ov017_021b1fe8((Struct_ov004_021583a8*)five) & 4) {
            data_ov004_021707e0[0x15] = 1;
            const char* name = (const char*)func_02072a68((struct TableA68*)table, 0x26);
            memcpy(buf, name, strlen(name));
            func_ov011_021848a0(obj, 0x3af);
        } else {
            data_ov004_021707e0[0x15] = 0;
            const char* name = (const char*)func_02072a68((struct TableA68*)table, 0x15);
            int len = strlen(name);
            memcpy(buf, name, len);

            int var11 = func_ov017_021b1ffc((Struct_ov004_021583a8_2*)five);
            int var12 = func_ov017_021b2010((Struct_ov004_021583a8_3*)five);
            func_ov004_02157374(obj, var11, var12, buf + len, 0);
            strlen(buf + len);
            func_ov011_021848a0(obj, 0x242d);
        }

        *((unsigned char*)five + 1) = 1;
        data_ov004_021707e0[0x13] = 0;
        unsigned char* ptr = data_ov004_021707e0;
        memset(ptr + 0x1c, 0, 0xc);
        *(int*)(ptr + 0x28) = 0;
#if defined(jpn)
        func_0204500c((void*)g, (const char*)(*(char**)((char*)g + Enum_ov004_0215bc9c_92)), 0);
#else
        func_0204500c((void*)g, *(char**)((char*)g + Enum_ov004_0215bc9c_92), 0, 0xe3);
#endif
        *(int*)((char*)g + Enum_ov004_0215bc9c_2456) = 1;
        return 0;
    }

returnOne:
    return 1;
}

struct Struct_ov004_0215be9c { char pad[0x5c]; short cur; short max; };
extern "C" int func_ov004_021571d8(int flag);
extern "C" int func_ov004_02156e2c(void* node, int type);

// USA: func_ov004_0215be9c
extern "C" ARM int func_ov004_0215be9c(int obj) {
    GameState* gs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GameState_GetParty(gs);
    if (p == 0) {
        return 0;
    }
    Struct_ov004_0215be9c* var2 = ((Struct_ov004_0215be9c*)func_ov004_02156ed0((void*)obj, 0x63));
    int idx = var2->cur << 3;
    unsigned char* node;
    if (func_ov004_021571d8(obj)) {
        int id = func_ov004_02156e2c((void*)obj, 0x65);
        if (id < 0) {
            return 0;
        }
        node = (unsigned char*)func_0207c5f8(p + 0x1d4, *(data_ov004_021707e0 + id + 0x7c));
    } else {
        signed char flag = func_ov004_02157128((void*)obj);
        if (flag >= 0) {
            void* found = func_0200ff1c(gs, flag);
            if (found == 0) {
                return 0;
            }
            unsigned char* field = (unsigned char*)((void*)func_02053c6c((unsigned char*)found)) + 0x54;
            node = field + 0x400;
            idx = 0;
        } else {
            node = p + 0xc;
        }
    }
    void* var9 = func_ov004_02157088((void*)obj, 7);
    int id2 = func_ov004_02156e2c((void*)obj, 0x63);
    if (var9 != 0) {
        func_ov023_021dcae0((Struct_ov003_02178910*)((void*)var9), (short)(((short*)node)[idx + id2]));
    }
    return 0;
}

#if defined(jpn)
extern "C" int KeyTable_LoadInPlace(void*, void*, int);
#endif

#if defined(jpn)
typedef Container020e0310 Struct_01ff8b48_21;
#else
struct Struct_01ff8b48_20 {
    void* first;
    void* second;
    unsigned int unknown8;
    unsigned short key;
    unsigned short unknownE;
};
struct Struct_01ff8b48_21 {
    unsigned int count : 12;
    unsigned int rest : 20;
    Struct_01ff8b48_20* entries;
};
#endif
struct ItemNameLoader0215bf94 {
    unsigned char unknown0[0x2d];
    unsigned char mode;
    unsigned char unknown_2e_[0x8c - 0x2e];
    Struct_01ff8b48_21 names;
#if defined(jpn)
    unsigned char unknown94[0x10];
#else
    unsigned char unknown94[4];
#endif
    void* fileBuffer;
};

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG3ScreenBase(void);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(struct Actor0209c3b4* actor, int val);
extern "C" void func_0209ca70(void* obj, int val);
extern "C" void func_020dc2bc(void);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020e56fc(void* a0, int a1, int a2);

#if defined(jpn)
// USA: func_ov004_0215bf94
extern "C" ARM int func_ov004_0215cfdc() {
#else
// USA: func_ov004_0215bf94
extern "C" ARM int func_ov004_0215bf94() {
#endif
    unsigned short* var0 = (unsigned short*)GetSubBG0ScreenBase();
    int i;
    for (i = 0; i < 0x800; i++) {
        *var0++ = 0;
    }
    memset((void*)GetMainBG3ScreenBase(), 0, 0x1000);
    struct Struct_ov004_0215bf94_2 {
        unsigned char unknown0[0xd];
        unsigned char state : 7;
        unsigned char unknown_d_7_ : 1;
    };
    struct GlobalState0215bf94 {
        unsigned char unknown0[8];
        Struct_ov004_0215bf94_2* current;
    };
    GlobalState0215bf94* owner = (GlobalState0215bf94*)Zone3D_GetInstance();
    unsigned char v = owner->current->state;
    func_0209c3b4((struct Actor0209c3b4*)g_bgmPlayer, v);
    func_0209ca70(g_bgmPlayer, ((ItemNameLoader0215bf94*)data_ov004_021707e0)->mode);
    func_020dc2bc();
#if defined(jpn)
    unsigned int size;
    LoadFileIntoMemory("data/prm/itemname.nat", ((ItemNameLoader0215bf94*)data_ov004_021707e0)->fileBuffer, &size);
    KeyTable_LoadInPlace(&((ItemNameLoader0215bf94*)data_ov004_021707e0)->names, ((ItemNameLoader0215bf94*)data_ov004_021707e0)->fileBuffer, (int)size);
#else
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* buf = ExtractFileFromGP2("data/prm/itemname.gp2", "itemname_<LG>.nat", &size);
    if (size <= 0x10800) {
        memcpy(((ItemNameLoader0215bf94*)data_ov004_021707e0)->fileBuffer, buf, size);
        func_020e56fc(&((ItemNameLoader0215bf94*)data_ov004_021707e0)->names, (int)((ItemNameLoader0215bf94*)data_ov004_021707e0)->fileBuffer, (int)size);
    }
    BackgroundLoader::RemoveLockGlobal();
#endif
    return 0;
}

// USA: func_ov004_0215c064
extern "C" ARM int func_ov004_0215c064(void* obj) {
	func_ov011_021848a0(obj, 0x50);
	func_ov023_021f65d4(obj, 2, 8);
	return 0;
}

// USA: func_ov004_0215c08c
extern "C" ARM int func_ov004_0215c08c(void) {
    return 0;
}

// USA: func_ov004_0215c094
extern "C" ARM int func_ov004_0215c094(void* obj) {
    func_ov011_021848a0(obj, 0x387);
    return 0;
}

// USA: func_ov004_0215c0ac
extern "C" ARM int func_ov004_0215c0ac(int a) {
	func_ov011_021848a0((void*)a, 0x65);
	return 0;
}

struct Struct_ov004_0215c0c0 { unsigned int low7 : 7; unsigned int rest : 25; };
struct Field2a04_0215c0c0 { char pad[0xf6c]; int unknown_f6c_; };

// USA: func_ov004_0215c0c0
extern "C" ARM int func_ov004_0215c0c0(void* obj) {
    int code = func_ov004_02156e2c(obj, 0x5b);
    if (code < 0) return 0;
    void* entry = func_ov004_021570a4(obj, code & 0xff);
    if (!entry) return 0;
    struct Field2a04_0215c0c0* fld = (struct Field2a04_0215c0c0*)GameState_GetParty(GameState::GetInstance());
    struct Struct_ov004_0215c0c0* c = (struct Struct_ov004_0215c0c0*)((char*)entry + 4);
    unsigned char rate = data_ov004_021707e0[0x11];
    unsigned int var5 = c->rest;
    int var6 = rate * var5;
    c->low7 = c->low7 - rate;
    unsigned char var7 = data_ov004_021707e0[0x11];
    unsigned int var8 = c->rest;
    int var9 = var7 * var8;
    fld->unknown_f6c_ -= var9;
#if defined(jpn)
    data_ov004_021707e0[0xa9] = 1;
#else
    data_ov004_021707e0[0x9d] = 1;
#endif
    if (var6 >= 50000) {
        func_ov011_021848a0(obj, 0x2366);
    } else {
        func_ov011_021848a0(obj, 0x2364);
    }
    return 0;
}

// USA: func_ov004_0215c194
extern "C" ARM int func_ov004_0215c194(void* obj) {
    func_ov011_021848a0(obj, 0x39f);
    return 0;
}
extern "C" void func_ov023_021f8240(void*, void*);

class Struct_ov004_0215c1ac {
public:
    virtual void v00(); virtual void inline_ov004_0215c1ac_2(); virtual void inline_ov004_0215c1ac_3(); virtual void inline_ov004_0215c1ac_4();
    virtual void v04(); virtual void inline_ov004_0215c1ac_6(); virtual void inline_ov004_0215c1ac_7(); virtual void inline_ov004_0215c1ac_8();
    virtual void v08(); virtual void inline_ov004_0215c1ac_10(); virtual void v10(); virtual void inline_ov004_0215c1ac_12();
    virtual void inline_ov004_0215c1ac_13(); virtual void inline_ov004_0215c1ac_14(); virtual void v14(); virtual void inline_ov004_0215c1ac_16();
    virtual void inline_ov004_0215c1ac_17(); virtual void inline_ov004_0215c1ac_18(); virtual void v18(); virtual void inline_ov004_0215c1ac_20();
    virtual void v20(); virtual void inline_ov004_0215c1ac_22(); virtual void inline_ov004_0215c1ac_23(); virtual void inline_ov004_0215c1ac_24();
    virtual void v24(); virtual void inline_ov004_0215c1ac_26(); virtual void inline_ov004_0215c1ac_27(); virtual void inline_ov004_0215c1ac_28();
    virtual void v28(); virtual void inline_ov004_0215c1ac_30(); virtual void v30(); virtual void inline_ov004_0215c1ac_32();
    virtual void inline_ov004_0215c1ac_33(); virtual void inline_ov004_0215c1ac_34(); virtual void v34(); virtual void inline_ov004_0215c1ac_36();
    virtual void inline_ov004_0215c1ac_37(); virtual void inline_ov004_0215c1ac_38(); virtual void v38(); virtual void inline_ov004_0215c1ac_40();
    virtual void v40(); virtual void inline_ov004_0215c1ac_42(); virtual void inline_ov004_0215c1ac_43(); virtual void inline_ov004_0215c1ac_44();
    virtual void v44(); virtual void inline_ov004_0215c1ac_46(); virtual void inline_ov004_0215c1ac_47(); virtual void inline_ov004_0215c1ac_48();
    virtual void v48(); virtual void inline_ov004_0215c1ac_50(); virtual void v50(); virtual void inline_ov004_0215c1ac_52();
    virtual void inline_ov004_0215c1ac_53(); virtual void inline_ov004_0215c1ac_54();
    virtual void inline_ov004_0215c1ac_55(int n);
};

// USA: func_ov004_0215c1ac
extern "C" ARM int func_ov004_0215c1ac(void* obj) {
    for (int i = 0; i < 8; i++) {
        void* node = func_ov004_02156f04(obj, i + 0x44c);
        *(unsigned char*)((char*)node + 0x45) &= ~1;
        ((Struct_ov004_0215c1ac*)node)->inline_ov004_0215c1ac_55(0xf);
    }
    void* node2 = func_ov004_02156f6c(obj, 0x17);
    if (node2) {
        func_ov023_021f8240(node2, obj);
    }
    func_ov011_021848a0(obj, 0x6b);
    return 0;
}

// USA: func_ov004_0215c228
extern "C" ARM int func_ov004_0215c228(int a) {
	func_ov011_021848a0((void*)a, 0x6a);
	return 0;
}

// USA: func_ov004_0215c23c
extern "C" ARM int func_ov004_0215c23c(int a) {
	func_ov011_021848a0((void*)a, 0x6c);
	return 0;
}

// USA: func_ov004_0215c250
extern "C" ARM int func_ov004_0215c250(void* obj) {
    func_ov011_021848a0(obj, 0x396);
    return 0;
}

extern "C" int func_ov004_021589e8(void*);

// USA: func_ov004_0215c268
extern "C" ARM int func_ov004_0215c268(void* obj) {
	int result;
	unsigned char* p = (unsigned char*)((char*)data_ov004_021707e0);
	if (p[0x30] == 0) goto skip;
	{
		FontBankLoader* g = FontBankLoader_GetInstance();
		unsigned char* p2 = (unsigned char*)((char*)data_ov004_021707e0);
		if (p2[0x2c] != 0) goto elseBranch;
		func_02094b34(g, 0x72, 0x202, 0, 0);
		{
			unsigned char* p3 = (unsigned char*)((char*)data_ov004_021707e0);
			p3[0x2c] = p3[0x2c] + 1;
		}
		result = 1;
		goto done;
	elseBranch:
		if (func_02094b4c(g)) {
			unsigned char* p4 = (unsigned char*)((char*)data_ov004_021707e0);
			p4[0x2c] = 0;
			goto skip;
		}
		result = 1;
		goto done;
	}
skip:
	func_ov004_021589e8(obj);
	result = 0;
done:
	return result;
}

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
extern "C" void* func_ov004_0215c448(void* obj);
extern "C" void* func_ov004_0215c474(void* obj);
extern "C" ARM int func_ov023_021f6f20(void* obj, int p1, int p3, int p4, int arg4, unsigned int arg5);
extern "C" ARM void* func_ov023_021f7318(void* p);
extern "C" ARM void func_ov023_021f7320(void* p);

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void SprSprite_Init(void* obj);
extern "C" void SprSprite_LoadFile(void* a, int b, int c, int d);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* head, struct Struct_ov004_0215c30c_2* node);

static inline char* GetPairTable(GameResources* res, int index) { return res->vramStates_ + index * 0x70; }

struct Struct_ov004_0215c30c_3 {
    int words[0xac / 4];
};

// USA: func_ov004_0215c30c
extern "C" ARM int func_ov004_0215c30c(void* ctx) {
    void* node = func_ov011_021845f8((unsigned char*)ctx, (int)6);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0xac);
    if (block == 0) return 0;

    Struct_ov004_0215c30c_3 local;
    func_ov004_0215c448(&local);
    memcpy(block, &local, sizeof(local));

    if (func_ov023_021f6f20(block, (int)ctx, 0x6a4, 6, 0, 0) == 0) {
        int result = 0;
        func_ov004_0215c474(&local);
        return result;
    }

    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = LoadFileIntoMemory("data/menu/dqa_rox.spr", g_fileLoadBuffer, &size);
    char* pairs = GetPairTable(GetGameResources(), 0);
    void* model = func_ov023_021f7318(block);
    VramState_Rewind((struct Foo0207df50*)pairs);
    VramState_Restore(pairs);
    SprSprite_Init(model);
    if (file != 0) {
        SprSprite_LoadFile(model, (int)file, size, (int)((char*)node + 4));
    }
    VramState_Save(pairs);
    BackgroundLoader::RemoveLockGlobal();
    func_ov023_021f7320(block);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(ctx), (struct Struct_ov004_0215c30c_2*)block);

    int result = 0;
    func_ov004_0215c474(&local);
    return result;
}

struct Struct_0204719c;
extern "C" void func_02048080(struct Struct_0204719c* table);
extern int data_ov023_021fe3e4;

// USA: func_ov004_0215c448
extern "C" ARM void* func_ov004_0215c448(void* obj) {
    Struct_0204719c* names = (Struct_0204719c*)((char*)obj + 0x34);
    void* model = (char*)obj + 0x20;
    *(void**)obj = &data_ov023_021fe3e4;
    func_02048080(names);
    SprSprite_Init(model);
	return obj;
}

struct Foo02048004;
extern "C" void SprSprite_Unload(struct Foo02048004* obj);

// USA: func_ov004_0215c474
extern "C" ARM void* func_ov004_0215c474(void* self) {
    SprSprite_Unload((struct Foo02048004*)((int)self + 0x20));
    func_02048080((struct Struct_0204719c*)((int)self + 0x34));
    return self;
}

// USA: func_ov004_0215c494
extern "C" ARM int func_ov004_0215c494(void* obj) {
    int key = func_ov004_02156e2c(obj, 0x5b);
    if (key < 0) {
        return 0;
    }
    void* entry = func_ov004_021570a4(obj, (unsigned char)key);
    if (!entry) {
        return 0;
    }
    unsigned char old = data_ov004_021707e0[0x11];
    data_ov004_021707e0[0x11] = 1;
    if (data_ov004_021707e0[0x11] < old) {
        func_ov023_021f66bc(obj, 0x25c, (void*)1);
    }
    func_ov004_02159384(obj);
    return 0;
}

struct Struct_ov004_0215c50c { short field0; short pad2; int field4; };

// USA: func_ov004_0215c50c
extern "C" ARM int func_ov004_0215c50c(void* a) {
    int b = func_ov004_02156e2c(a, 0x5b);
    if (b < 0) return 0;

    Struct_ov004_0215c50c* entry = (Struct_ov004_0215c50c*)func_ov004_021570a4(a, (unsigned char)b);
    if (!entry) return 0;

    unsigned char var2 = data_ov004_021707e0[0x11];
    data_ov004_021707e0[0x11] = (unsigned char)((unsigned int)(entry->field4 << 25) >> 25);

    void* ptr2a04 = GameState_GetParty(GameState::GetInstance());
    unsigned int hi = (unsigned int)entry->field4 >> 7;
    unsigned int var5 = data_ov004_021707e0[0x11] * hi;
    int f6c = *(int*)((char*)ptr2a04 + 0xf6c);
    if ((unsigned int)f6c < var5) {
        unsigned int q = (unsigned int)f6c / hi;
        data_ov004_021707e0[0x11] = (unsigned char)q;
        if (data_ov004_021707e0[0x11] < 1) data_ov004_021707e0[0x11] = 1;
    }

    int contPtr = func_ov004_02156fd4(a, 5);
    if (!contPtr) return 0;

    short shortE = *(short*)(data_ov004_021707e0 + 0xe);
    Element020de650* elem = ItemTable_Find((ItemTable*)contPtr, shortE);
    if (!elem) return 0;

    int var11 = *(int*)((char*)elem + 8);
    int var12 = func_ov004_0215799c(ptr2a04, entry->field0, (unsigned int)(var11 << 28) >> 28, *(short*)(data_ov004_021707e0 + 0x3a));

    if (data_ov004_021707e0[0x11] >= (unsigned int)var12) {
        data_ov004_021707e0[0x11] = (unsigned char)var12;
        if (data_ov004_021707e0[0x11] < 1) data_ov004_021707e0[0x11] = 1;
    }

    if (data_ov004_021707e0[0x11] == 0) data_ov004_021707e0[0x11] = 1;

    if (var2 < data_ov004_021707e0[0x11]) {
        func_ov023_021f66bc(a, 0x25b, (void*)1);
    }

    func_ov004_02159384(a);
    return 0;
}

typedef void (*Type_01ff8b48_14)(void*, int);
struct Struct_ov004_0215c684 { char pad[0xe0]; Type_01ff8b48_14 func; };
struct Struct_ov004_0215c684_2 { Struct_ov004_0215c684* handler; };

// USA: func_ov004_0215c684
extern "C" ARM int func_ov004_0215c684(void* obj) {
    if (data_ov004_021707e0[0x6e] > 1) {
        data_ov004_021707e0[0x6e] = 1;
        Struct_ov004_0215c684_2* node = ((Struct_ov004_0215c684_2*)func_ov004_02156f38(obj, 0x25a));
        if (node) {
            node->handler->func(node, data_ov004_021707e0[0x6e]);
        }
        int result = ((int)func_ov004_02156f6c(obj, 0x19));
        if (result) {
            func_ov023_021f809c((void*)result, obj);
        }
    }
    return 0;
}

typedef void (*Type_01ff8b48_15)(void*, int);
struct Struct_ov004_0215c6fc { char pad[0xe0]; Type_01ff8b48_15 func; };
struct Struct_ov004_0215c6fc_2 { Struct_ov004_0215c6fc* handler; };

// USA: func_ov004_0215c6fc
extern "C" ARM int func_ov004_0215c6fc(void* obj) {
    if (data_ov004_021707e0[0x6e] < data_ov004_021707e0[0x6f]) {
        data_ov004_021707e0[0x6e] = data_ov004_021707e0[0x6f];
        Struct_ov004_0215c6fc_2* node = ((Struct_ov004_0215c6fc_2*)func_ov004_02156f38(obj, 0x25a));
        if (node) {
            node->handler->func(node, data_ov004_021707e0[0x6e]);
        }
        int result = ((int)func_ov004_02156f6c(obj, 0x19));
        if (result) {
            func_ov023_021f809c((void*)result, obj);
        }
    }
    return 0;
}

struct Struct_ov004_0215c774 {
    unsigned int unknown_0_;
    SafeAllocator allocator;
};

struct Struct_ov004_0215c30c_2 {
    char unknown_0_[6];
    unsigned short flag;
    char unknown_8_[12];
    Struct_ov004_0215c30c_2* previous;
    Struct_ov004_0215c30c_2* next;
};

struct Struct_ov004_0215c774_2 {
    Struct_ov004_0215c30c_2 unknown_0_;
    char payload[0x90];
};

struct Struct_ov004_0215c774_3 {
    unsigned int unknown_0_;
    char tables[0x70];
};

struct Struct_ov004_0215c774_4 {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 12;
    unsigned int variant : 4;
    unsigned int unknown_1a_0_ : 16;
};
extern "C" void* func_ov004_0215c448(void*);
extern "C" void* func_ov004_0215c474(void*);
extern "C" int func_ov023_021f6f20(void*, int, int, int, int, unsigned int);
extern "C" void* ExtractFileFromGP2(const char*, const char*, unsigned int*);
extern "C" void* func_ov023_021f7318(void*);
extern "C" Struct_ov004_0215c774_3* func_ov011_0218466c(void*, unsigned short);
extern "C" void VramState_Restore(char*);
extern "C" void SprSprite_Init(void*);
extern "C" void SprSprite_LoadFile(void*, int, int, int);
extern "C" void VramState_Save(char*);
extern "C" void func_ov023_021f7320(void*);
extern "C" void func_ov023_021f67ac(Struct_ov004_0215c30c*, Struct_ov004_0215c30c_2*);

// USA: func_ov004_0215c774
extern "C" ARM int func_ov004_0215c774(void* context) {
    Struct_ov004_0215c774* owner = ((Struct_ov004_0215c774*)func_ov011_021845f8((unsigned char*)context, (int)10));
    if (owner == 0) return 0;
    owner->allocator.GetSizeWithLargestBlockRemoved();
    Struct_ov004_0215c774_2* node = (Struct_ov004_0215c774_2*)owner->allocator.Allocate(sizeof(Struct_ov004_0215c774_2));
    if (node == 0) return 0;
    Struct_ov004_0215c774_2 var2;
    func_ov004_0215c448(&var2);
    memcpy(node, &var2, sizeof(var2));
    if (func_ov023_021f6f20(node, (int)context, 0x640, 10, 0, 0) == 0) {
#if defined(jpn)
        int result = 0;
        func_ov004_0215c474(&var2);
        return result;
#else
        func_ov004_0215c474(&var2);
        return 0;
#endif
    }
#if defined(jpn)
    char path[32];
    __clear(path, (unsigned int)(sizeof(path)));
    sprintf(path, "data/menu/dqa_%02d.spr", ((Struct_ov004_0215c774_4*)data_ov004_021707e0)->variant);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = LoadFileIntoMemory(path, g_fileLoadBuffer, &size);
#else
    char var5[32];
    char var6[32];
    __clear(var5, (unsigned int)(sizeof(var5)));
    __clear(var6, (unsigned int)(sizeof(var6)));
    sprintf(var5, "data/menu/dqa_%02d.gp2", ((Struct_ov004_0215c774_4*)data_ov004_021707e0)->variant);
    sprintf(var6, "dqa_%02d_<LG>.spr", ((Struct_ov004_0215c774_4*)data_ov004_021707e0)->variant);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = ExtractFileFromGP2(var5, var6, &size);
#endif
    void* model = func_ov023_021f7318(node);
    Struct_ov004_0215c774_3* pairs = func_ov011_0218466c(context, 0);
    char* tables = pairs->tables;
    VramState_Restore(tables);
    SprSprite_Init(model);
    if (file != 0) {
        SprSprite_LoadFile(model, (int)file, size, (int)&owner->allocator);
    }
    VramState_Save(tables);
    BackgroundLoader::RemoveLockGlobal();
    func_ov023_021f7320(node);
    func_ov023_021f67ac(((Struct_ov004_0215c30c*)func_ov011_021849c8(context)), &node->unknown_0_);
#if defined(jpn)
    int result = 0;
    func_ov004_0215c474(&var2);
    return result;
#else
    func_ov004_0215c474(&var2);
    return 0;
#endif
}

struct Struct_01ff8b48_18 {
    short id;
    unsigned short unknown_2_;
    unsigned int value : 7;
    unsigned int unknown_4_7_ : 25;
    unsigned char unknown_8_[0x20];
};

struct Struct_ov004_0215c900 {
    short unknown_0_;
    unsigned short unknown_2_;
    Struct_01ff8b48_18 entries[6];
    Struct_ov004_021589e8 start;
    short itemId;
    unsigned short unknown_fa_;
    unsigned short unknown_fc_;
    unsigned short unknown_fe_;
    Struct_ov004_021589e8 end;
    Struct_ov004_021589e8 unknown_104_;
    unsigned int unknown_108_;
    unsigned short flags : 13;
    unsigned short unknown_10d_5_ : 3;
    unsigned short unknown_10e_;
};

// USA: func_ov004_0215c900
extern "C" ARM int func_ov004_0215c900(void* obj) {
#if defined(jpn)
    const Struct_ov004_0215c900* data = (const Struct_ov004_0215c900*)((const char*)GameState::GetInstance() + 0x5c0c);
#else
    const Struct_ov004_0215c900* data = (const Struct_ov004_0215c900*)((const char*)GameState::GetInstance() + 0x5e6c);
#endif
    if (data->flags & 0x20) {
        func_ov011_021848a0(obj, 2);
    } else {
        func_ov011_021848a0(obj, 1);
    }
    return 0;
}

// USA: func_ov004_0215c948
extern "C" ARM int func_ov004_0215c948(int a) {
	func_ov011_021848a0((void*)a, 0x384);
	return 0;
}

// USA: func_ov004_0215c95c
extern "C" ARM int func_ov004_0215c95c(void* obj) {
    func_ov011_021848a0(obj, 0x395);
    return 0;
}
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" int func_020aad1c(void* loader, void* name, int a, int b);
extern "C" int func_ov004_0215b1d4(void* obj);
extern "C" void* func_ov017_021b1fc0(void* obj);
struct Struct_ov004_0215c974;
extern "C" void func_ov011_02184534(struct Struct_ov004_0215c974* obj, int b0, int arg2);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif

struct Struct_ov004_0215c974_2 { unsigned char low7 : 7; unsigned char unknown_0_7_ : 1; };

#if defined(jpn)
enum { Enum_ov004_0215c974_12 = 0xc, Enum_ov004_0215c974_15176 = 0x3928, Enum_ov004_0215c974_92 = 0x28, Enum_ov004_0215c974_2400 = 0x800, Enum_ov004_0215c974_2456 = 0x868 };
#else
enum { Enum_ov004_0215c974_620 = 0x26c, Enum_ov004_0215c974_15176 = 0x3b48, Enum_ov004_0215c974_92 = 0x5c, Enum_ov004_0215c974_2400 = 0x960, Enum_ov004_0215c974_2456 = 0x998 };
#endif

// USA: func_ov004_0215c974
extern "C" ARM int func_ov004_0215c974(void* obj) {
    void* data;
    bool queued;
    char* gs;
    int g;
    char* cur;
    struct TableA68* table;
    const char* head;
    int len;
    char* rec;
    char* base;
    int i;

    func_ov023_021f6600(obj, 0x36, 8);

    data = GlobalFlags_GetInstance();
    FlagWord_SetBits((unsigned int*)data, 0x80);

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    queued = func_020aad1c(data_ov004_021707e0 + 0x84, g_fileLoadBuffer, 0xa, 0) != 0;
    BackgroundLoader::RemoveLockGlobal();
    if (!queued) return 1;

    FlagWord_ClearBits((struct FlagWord020466f4*)data, 0x80);

    func_ov023_021f65d4(obj, 0x36, 8);

    g = MessageSystem_GetInstance();
    cur = *(char**)((char*)g + Enum_ov004_0215c974_92);
    memset(cur, 0, Enum_ov004_0215c974_2400);

#if defined(jpn)
    GameState* state = GameState::GetInstance();
    gs = (char*)state + Enum_ov004_0215c974_12;
    int* var12 = (int*)((char*)state + 0x6120);
#else
    gs = (char*)GameState::GetInstance() + Enum_ov004_0215c974_620;
#endif
    table = (struct TableA68*)func_ov004_02157018(obj, 4);

    head = (const char*)func_02072a68(table, 0x21);
    len = strlen(head);
    memcpy(cur, head, len);
    cur += len;

    if (data_ov004_021707e0[0x15] != 0) {
        func_ov004_0215b1d4(obj);
        void* q = Zone3D_GetInstance();
        Struct_ov004_0215c974_2* b = (Struct_ov004_0215c974_2*)((char*)(*(void**)((char*)q + 8)) + 0xd);
        func_0209c3b4((struct Actor0209c3b4*)g_bgmPlayer, b->low7);
        func_0209ca70(g_bgmPlayer, data_ov004_021707e0[0x2d]);
    } else if (data_ov004_021707e0[0x14] != 0) {
        void* raw = GetGameResources();
        void* five = *(void**)((char*)raw + Enum_ov004_0215c974_15176);
        rec = (char*)func_ov017_021b1fc0(five);
        base = *(char**)((char*)five + 0x34);

        for (i = 0; i < 4; i++) {
            if (strstr((char*)rec + 0x88, "info")) {
                func_ov011_02184534((struct Struct_ov004_0215c974*)obj, (int)base, *(int*)((char*)rec + 0xac));
                break;
            }
            base += *(int*)((char*)rec + 0xac);
            rec += 0xb0;
        }

        if (i != 4) {
            func_ov011_021848a0(obj, 0x394);
        } else {
            func_ov011_021848a0(obj, 0x3ad);
        }

        int flags = *(unsigned short*)(gs + 0x5d00 + 0xc);
        flags = flags << 0x13;
        flags = (unsigned)flags >> 0x13;
        if (flags & 0x40) {
            const char* s = (const char*)func_02072a68(table, 0x1c);
            int l = strlen(s);
            memcpy(cur, s, l);
            cur += l;
        }
#if defined(jpn)
        int var20 = (var12[0x50 / 4] & 1) != 0;
        if (data_ov004_021707e0[0x2f] != var20) {
            const char* s;
            if (var20) {
                s = (const char*)func_02072a68(table, 0x1d);
            } else {
                s = (const char*)func_02072a68(table, 0x1e);
            }
            int l = strlen(s);
            memcpy(cur, s, l);
            cur += l;
        }
#endif
        flags = *(unsigned short*)(gs + 0x5d00 + 0xc);
        flags = flags << 0x13;
        flags = (unsigned)flags >> 0x13;
        if (flags & 0x200) {
            const char* s = (const char*)func_02072a68(table, 0x1f);
            memcpy(cur, s, strlen(s));
        }
    }

#if defined(jpn)
    func_0204500c((void*)g, *(char**)((char*)g + Enum_ov004_0215c974_92), 0);
#else
    func_0204500c((void*)g, *(char**)((char*)g + Enum_ov004_0215c974_92), 0, 0xe3);
#endif
    *(int*)((char*)g + Enum_ov004_0215c974_2456) = 1;
    return 0;
}

// USA: func_ov004_0215cbec
extern "C" ARM int func_ov004_0215cbec(void* obj) {
    func_ov023_021f65d4(obj, 2, 8);
    func_ov011_021848a0(obj, 0x68);
    return 0;
}

// USA: func_ov004_0215cc14
extern "C" ARM int func_ov004_0215cc14(void* obj) {
    func_ov023_021f65d4(obj, 2, 8);
    func_ov011_021848a0(obj, 0x396);
    return 0;
}

// USA: func_ov004_0215cc40
extern "C" ARM int func_ov004_0215cc40(void* obj) {
    func_ov011_021848a0(obj, 0x3b1);
    return 0;
}

extern "C" void func_ov004_021578a8(void* obj);

// USA: func_ov004_0215cc58
extern "C" ARM int func_ov004_0215cc58(void* obj) {
	if (data_ov004_021707e0[0x3e] < 6) {
		data_ov004_021707e0[0x3e]++;
	}
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215cc84
extern "C" ARM int func_ov004_0215cc84(void* obj) {
	if (data_ov004_021707e0[0x3e] != 0) {
		data_ov004_021707e0[0x3e]--;
	}
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215ccb0
extern "C" ARM int func_ov004_0215ccb0(void* obj) {
	((char*)data_ov004_021707e0)[0x3e] = 0;
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215ccd4
extern "C" ARM int func_ov004_0215ccd4(void* obj) {
	((char*)data_ov004_021707e0)[0x3e] = 1;
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215ccf8
extern "C" ARM int func_ov004_0215ccf8(void* obj) {
	((char*)data_ov004_021707e0)[0x3e] = 2;
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215cd1c
extern "C" ARM int func_ov004_0215cd1c(void* obj) {
	((char*)data_ov004_021707e0)[0x3e] = 3;
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215cd40
extern "C" ARM int func_ov004_0215cd40(void* obj) {
	((char*)data_ov004_021707e0)[0x3e] = 4;
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215cd64
extern "C" ARM int func_ov004_0215cd64(void* obj) {
	((char*)data_ov004_021707e0)[0x3e] = 5;
	func_ov004_021578a8(obj);
	return 0;
}

// USA: func_ov004_0215cd88
extern "C" ARM int func_ov004_0215cd88(void* obj) {
	((char*)data_ov004_021707e0)[0x3e] = 6;
	func_ov004_021578a8(obj);
	return 0;
}

struct Struct_ov004_0215cdac { char pad[0x5c]; short cur; short max; };
extern "C" int func_ov004_02158fec(void*);

// USA: func_ov004_0215cdac
extern "C" ARM int func_ov004_0215cdac(void* obj) {
    Struct_ov004_0215cdac* var0 = ((Struct_ov004_0215cdac*)func_ov004_02156ed0(obj, 0x5b));
    short cur = var0->cur;
    short max = var0->max;
    short var3 = cur + 1;
    if (max <= var3) var3 = 0;
    var0->cur = var3;
    var0->max = max;
    func_ov004_02158fec(obj);
    return 0;
}

struct Struct_ov004_0215cdf0 { char pad[0x5c]; short cur; short max; };

// USA: func_ov004_0215cdf0
extern "C" ARM int func_ov004_0215cdf0(void* obj) {
    Struct_ov004_0215cdf0* var0 = ((Struct_ov004_0215cdf0*)func_ov004_02156ed0(obj, 0x5b));
    short cur = var0->cur;
    short max = var0->max;
    short var3 = cur - 1;
    if (var3 < 0) var3 = max - 1;
    var0->cur = var3;
    var0->max = max;
    func_ov004_02158fec(obj);
    return 0;
}

struct Struct_ov004_0215ce38 { char pad[0x5c]; short cur; short max; };
extern "C" int func_ov004_0215a738(void*);

// USA: func_ov004_0215ce38
extern "C" ARM int func_ov004_0215ce38(void* obj) {
    Struct_ov004_0215ce38* var0 = ((Struct_ov004_0215ce38*)func_ov004_02156ed0(obj, 0x63));
    short cur = var0->cur;
    short max = var0->max;
    short var3 = cur + 1;
    if (max <= var3) var3 = 0;
    var0->cur = var3;
    var0->max = max;
    func_ov004_0215a738(obj);
    return 0;
}

struct Struct_ov004_0215ce7c { char pad[0x5c]; short cur; short max; };

// USA: func_ov004_0215ce7c
extern "C" ARM int func_ov004_0215ce7c(void* obj) {
    Struct_ov004_0215ce7c* var0 = ((Struct_ov004_0215ce7c*)func_ov004_02156ed0(obj, 0x63));
    short cur = var0->cur;
    short max = var0->max;
    short var3 = cur - 1;
    if (var3 < 0) var3 = max - 1;
    var0->cur = var3;
    var0->max = max;
    func_ov004_0215a738(obj);
    return 0;
}

struct Struct_ov004_0215cec4 { char pad[0x32]; short members[4]; short memberCount; };

struct Struct_ov004_0216fb70 { int ids[4]; };
extern Struct_ov004_0216fb70 data_ov004_0216fb70;
struct Struct_ov004_0215cec4_2 { short key; };
struct Element020de650_0215cec4 { char pad[8]; unsigned int kind : 4; };
extern "C" int func_020dd718(int combatantId, int value);

typedef void (*Type_01ff8b48_16)(void*, int);
struct Struct_ov004_0215cec4_4 { char pad[0xe0]; Type_01ff8b48_16 func; };
struct Struct_ov004_0215cec4_5 { Struct_ov004_0215cec4_4* handler; };

typedef void (*Type_01ff8b48_17)(void*, int);
struct Struct_ov004_0215cec4_6 { char pad[0xd8]; Type_01ff8b48_17 func; };
struct Struct_ov004_0215cec4_7 { Struct_ov004_0215cec4_6* handler; };

class Struct_ov004_0215cec4_8 {
public:
    virtual void v00(); virtual void inline_ov004_0215cec4_2(); virtual void inline_ov004_0215cec4_3(); virtual void inline_ov004_0215cec4_4();
    virtual void v04(); virtual void inline_ov004_0215cec4_6(); virtual void inline_ov004_0215cec4_7(); virtual void inline_ov004_0215cec4_8();
    virtual void v08(); virtual void inline_ov004_0215cec4_10(); virtual void v10(); virtual void inline_ov004_0215cec4_12();
    virtual void inline_ov004_0215cec4_13(); virtual void inline_ov004_0215cec4_14(); virtual void v14(); virtual void inline_ov004_0215cec4_16();
    virtual void inline_ov004_0215cec4_17(); virtual void inline_ov004_0215cec4_18(); virtual void v18(); virtual void inline_ov004_0215cec4_20();
    virtual void v20(); virtual void inline_ov004_0215cec4_22(); virtual void inline_ov004_0215cec4_23(); virtual void inline_ov004_0215cec4_24();
    virtual void v24(); virtual void inline_ov004_0215cec4_26(); virtual void inline_ov004_0215cec4_27(); virtual void inline_ov004_0215cec4_28();
    virtual void v28(); virtual void inline_ov004_0215cec4_30(); virtual void v30(); virtual void inline_ov004_0215cec4_32();
    virtual void inline_ov004_0215cec4_33(); virtual void inline_ov004_0215cec4_34(); virtual void v34(); virtual void inline_ov004_0215cec4_36();
    virtual void inline_ov004_0215cec4_37(); virtual void inline_ov004_0215cec4_38(); virtual void v38(); virtual void inline_ov004_0215cec4_40();
    virtual void v40(); virtual void inline_ov004_0215cec4_42(); virtual void inline_ov004_0215cec4_43(); virtual void inline_ov004_0215cec4_44();
    virtual void v44(); virtual void inline_ov004_0215cec4_46(); virtual void inline_ov004_0215cec4_47(); virtual void inline_ov004_0215cec4_48();
    virtual void v48(); virtual void inline_ov004_0215cec4_50(); virtual void v50(); virtual void inline_ov004_0215cec4_52();
    virtual void inline_ov004_0215cec4_53(); virtual void inline_ov004_0215cec4_54();
    virtual void inline_ov004_0215cec4_55(int icon);
    char pad[0x1c];
    BaseCombatStats* stats;
};
struct Struct_ov004_0215cec4_9 { char pad[0x38]; short style; };

// USA: func_ov004_0215cec4
extern "C" ARM int func_ov004_0215cec4(void* a) {
    GameState* bs = GameState::GetInstance();
    int key = func_ov004_02156e2c(a, 0x5b);
    if (key < 0) return 0;
    Struct_ov004_0215cec4_2* entry = ((Struct_ov004_0215cec4_2*)func_ov004_021570a4(a, key & 0xff));
    if (!entry) return 0;
    ItemTable* node = ((ItemTable*)func_ov004_02156fd4(a, 5));
    if (!node) return 0;
    Element020de650_0215cec4* elem = ((Element020de650_0215cec4*)ItemTable_Find(node, entry->key));
    if (!elem) return 0;

    Struct_020dd7ac buf;
    func_020dd7ac(&buf);
    int var6 = 1;
    if (elem->kind != 0) var6 = 3;

    Struct_ov004_0215cec4_9* title = (Struct_ov004_0215cec4_9*)func_ov004_02156f04(a, 0x1d6);
    if (title) title->style = var6 + 0xb;

    Struct_ov004_0216fb70 members = data_ov004_0216fb70;
    int count;
    int i;
    Struct_ov004_0215cec4* battle = (Struct_ov004_0215cec4*)data_ov004_021707e0;
    count = battle->memberCount;
    for (i = 0; i < count; i++) {
        members.ids[i] = battle->members[i];
    }

    for (unsigned char j = 0; j < 4; j++) {
        int id = members.ids[j];
        GameObject* member = bs->GetPartyMemberByIndex(id);
        if (member) {
            Struct_ov004_0215cec4_8* var15 = (Struct_ov004_0215cec4_8*)func_ov004_02156f04(a, j + 0x1c2);
            if (!var15) return 0;
            var15->stats = member->baseStats_;
            var15->inline_ov004_0215cec4_55(func_020dcc98(members.ids[j]));
            if (func_020dd718((signed char)members.ids[j], entry->key)) {
                func_ov023_021f65d4(a, j + 0x1c6, 8);
                func_ov023_021f65d4(a, j + 0x1ce, 8);
                func_ov023_021f65d4(a, j + 0x1ca, 8);
                func_ov023_021f65d4(a, j + 0x1d2, 8);
                func_ov023_021f6600(a, j + 0x1d7, 8);
            } else if (func_020dd4c4((signed char)id, (Struct_020dd4c4_3*)elem)) {
                func_ov023_021f65d4(a, j + 0x1c6, 8);
                func_ov023_021f65d4(a, j + 0x1ce, 8);
                func_ov023_021f65d4(a, j + 0x1ca, 8);
                func_ov023_021f6600(a, j + 0x1d2, 8);
                func_ov023_021f65d4(a, j + 0x1d7, 8);
            } else {
                func_ov023_021f6600(a, j + 0x1c6, 8);
                func_ov023_021f6600(a, j + 0x1ce, 8);
                func_ov023_021f6600(a, j + 0x1ca, 8);
                func_ov023_021f65d4(a, j + 0x1d2, 8);
                func_ov023_021f65d4(a, j + 0x1d7, 8);

                func_020dd7ac(&buf);
                unsigned short valA, valB;
                if (elem->kind == 0) {
                    func_020ddaf4((int)&buf, id, (int)elem, 0, (int)&valA, (int)&valB);
                } else {
                    func_020ddaf4((int)&buf, id, (int)elem, 1, (int)&valA, (int)&valB);
                }

                Struct_ov004_0215cec4_5* var18 = (Struct_ov004_0215cec4_5*)func_ov004_02156f38(a, j + 0x1c6);
                if (var18) var18->handler->func(var18, valA);
                Struct_ov004_0215cec4_5* var19 = (Struct_ov004_0215cec4_5*)func_ov004_02156f38(a, j + 0x1ca);
                if (var19) var19->handler->func(var19, valB);

                Struct_ov004_0215cec4_7* var20 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), j + 0x1c6);
                if (var20) var20->handler->func(var20, 0xf);

                if (valA == valB) {
                    Struct_ov004_0215cec4_7* var21 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), j + 0x1ca);
                    if (var21) var21->handler->func(var21, 0xf);
                } else if (valA < valB) {
                    Struct_ov004_0215cec4_7* var22 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), j + 0x1ca);
                    if (var22) var22->handler->func(var22, 5);
                } else {
                    Struct_ov004_0215cec4_7* var23 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), j + 0x1ca);
                    if (var23) var23->handler->func(var23, 9);
                }
            }
        } else {
            func_ov023_021f65d4(a, j + 0x1c2, 8);
            func_ov023_021f65d4(a, j + 0x1c6, 8);
            func_ov023_021f65d4(a, j + 0x1ce, 8);
            func_ov023_021f65d4(a, j + 0x1ca, 8);
            func_ov023_021f65d4(a, j + 0x1d2, 8);
            func_ov023_021f65d4(a, j + 0x1d7, 8);
        }
    }

    void* var24 = func_ov004_02156f6c(a, 0x17);
    if (var24) func_ov023_021f809c(var24, a);
    return 0;
}
struct Obj02086aec;
extern "C" short Party_CountItem(struct Obj02086aec* obj, int key);
extern "C" int func_ov024_021f6f10(void*);
struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08*);

struct Struct_ov004_0215d384 { int a; int b; int c; };

class Struct_ov004_0215d384_2 {
public:
    virtual void v00(); virtual void inline_ov004_0215d384_2(); virtual void inline_ov004_0215d384_3(); virtual void inline_ov004_0215d384_4();
    virtual void v04(); virtual void inline_ov004_0215d384_6(); virtual void inline_ov004_0215d384_7(); virtual void inline_ov004_0215d384_8();
    virtual void v08(); virtual void inline_ov004_0215d384_10(); virtual void v10(); virtual void inline_ov004_0215d384_12();
    virtual void inline_ov004_0215d384_13(); virtual void inline_ov004_0215d384_14(); virtual void v14(); virtual void inline_ov004_0215d384_16();
    virtual void inline_ov004_0215d384_17(); virtual void inline_ov004_0215d384_18(); virtual void v18(); virtual void inline_ov004_0215d384_20();
    virtual void v20(); virtual void inline_ov004_0215d384_22(); virtual void inline_ov004_0215d384_23(); virtual void inline_ov004_0215d384_24();
    virtual void v24(); virtual void inline_ov004_0215d384_26(); virtual void inline_ov004_0215d384_27(); virtual void inline_ov004_0215d384_28();
    virtual void v28(); virtual void inline_ov004_0215d384_30(); virtual void v30(); virtual void inline_ov004_0215d384_32();
    virtual void inline_ov004_0215d384_33(); virtual void inline_ov004_0215d384_34(); virtual void v34(); virtual void inline_ov004_0215d384_36();
    virtual void inline_ov004_0215d384_37(); virtual void inline_ov004_0215d384_38(); virtual void v38(); virtual void inline_ov004_0215d384_40();
    virtual void v40(); virtual void inline_ov004_0215d384_42(); virtual void inline_ov004_0215d384_43(); virtual void inline_ov004_0215d384_44();
    virtual void v44(); virtual void inline_ov004_0215d384_46(); virtual void inline_ov004_0215d384_47(); virtual void inline_ov004_0215d384_48();
    virtual void v48(); virtual void inline_ov004_0215d384_50(); virtual void v50(); virtual void inline_ov004_0215d384_52();
    virtual void inline_ov004_0215d384_53(); virtual void inline_ov004_0215d384_54(); virtual void v54(); virtual void inline_ov004_0215d384_56();
    virtual void inline_ov004_0215d384_57(int arg);
};

class Struct_ov004_0215d384_3 {
public:
    virtual void v00(); virtual void inline_ov004_0215d384_59(); virtual void inline_ov004_0215d384_60(); virtual void inline_ov004_0215d384_61();
    virtual void v04(); virtual void inline_ov004_0215d384_63(); virtual void inline_ov004_0215d384_64();
    virtual void inline_ov004_0215d384_65(const Struct_ov004_0215d384& args);
};

// USA: func_ov004_0215d384
extern "C" ARM int func_ov004_0215d384(void* a) {
    GameState* bs = GameState::GetInstance();
    int idx = func_ov004_02156e2c(a, 0x5b);
    if (idx < 0) return 0;
    void* entry = func_ov004_021570a4(a, idx & 0xff);
    if (!entry) return 0;
    Struct_ov004_0215d384_2* nodeA = (Struct_ov004_0215d384_2*)func_ov004_02156f38(a, 0x1dc);
    if (!nodeA) return 0;

    int matches = Party_CountItem((struct Obj02086aec*)GameState_GetParty(bs), *(short*)entry);
    nodeA->inline_ov004_0215d384_57(matches);

    void* var5 = func_ov004_02156f6c(a, 0x1b);
    if (var5) func_ov023_021f809c(var5, a);

#if !defined(jpn)
    Struct_ov004_0215d384_3* nodeB = (Struct_ov004_0215d384_3*)func_ov023_021f6880((void**)(func_ov011_021849c8(a)), 0x1dd);
    if (!nodeB) return 0;
    if (func_ov024_021f6f10(nodeB) != 8) return 0;

    Struct_ov004_0215d384 args;
    args.b = 0x4000;
    args.c = 0;
    int kind = ((int)GameState_GetLanguage((struct Struct0200fb08*)bs));
    switch (kind) {
    case 1: args.a = 0x14000; nodeB->inline_ov004_0215d384_65(args); break;
    case 2: args.a = 0xe000; nodeB->inline_ov004_0215d384_65(args); break;
    case 3: args.a = 0xb000; nodeB->inline_ov004_0215d384_65(args); break;
    case 4: args.a = 0x6000; nodeB->inline_ov004_0215d384_65(args); break;
    case 5: args.a = 0x9000; nodeB->inline_ov004_0215d384_65(args); break;
    default: break;
    }
#endif
    return 0;
}

struct Struct_ov004_0215d534 { char pad[0x5c]; short cur; short max; };
struct Struct_ov004_0215d534_2 { short id; short pad2; unsigned int limit : 7; };
struct Struct_ov004_0215d534_3 { char pad[0x11]; unsigned char count; };

struct SearchStruct;
extern "C" int func_ov004_02156e2c(void* obj, int key);
extern "C" int func_ov004_0215c0c0(void* obj);
extern "C" void func_ov017_021d3bbc(int a, int b, int c, int d);
extern "C" int LinkSession_IsSlotLost(SearchStruct* obj, int value);
extern "C" void func_ov011_02184a40(void* obj, int val);

// USA: func_ov004_0215d534
extern "C" ARM int func_ov004_0215d534(void* obj) {
#if defined(jpn)
 enum { Enum_ov004_0215d534_620 = 0xc };
#else
 enum { Enum_ov004_0215d534_620 = 0x26c };
#endif
    int key = func_ov004_02156e2c(obj, 0x5b);
    if (key < 0) return 0;

    SearchStruct* search = ((SearchStruct*)LinkSession_GetInstance());
    if (!LinkSession_IsActive((int*)search)) {
        func_ov004_0215c0c0(obj);
    } else {
        int slot = ((Struct_ov004_0215d534*)func_ov004_02156ed0(obj, 0x5b))->cur * 6 + key;
        Struct_ov004_0215d534_2* entry = (Struct_ov004_0215d534_2*)func_ov004_021570a4(obj, (unsigned char)key);

        if (LinkSession_IsHostOrSolo((CheckField0AndGlobalHalfStruct0202c508*)search)) {
            if (entry->limit >= ((Struct_ov004_0215d534_3*)data_ov004_021707e0)->count) {
                func_ov004_0215c0c0(obj);
                func_ov017_021d3bbc(slot, ((Struct_ov004_0215d534_3*)data_ov004_021707e0)->count, 1, 0);
            } else {
                func_ov011_021848a0(obj, 0x2367);
            }
        } else if (!LinkSession_IsSlotLost(search, 0)) {
            char* p = (char*)GameState::GetInstance() + Enum_ov004_0215d534_620;
            *(unsigned short*)(p + 0x5d00 + 0xc) &= ~0xe000;
            func_ov017_021d3bbc(slot, ((Struct_ov004_0215d534_3*)data_ov004_021707e0)->count, 3, 0);
            func_ov011_02184a40(obj, 0x5c);
        } else {
            func_ov011_021848a0(obj, 0x2369);
        }
    }
    return 0;
}

// USA: func_ov004_0215d670
extern "C" ARM int func_ov004_0215d670(void* obj) {
#if defined(jpn)
 enum { Enum_ov004_0215d670_620 = 0xc };
#else
 enum { Enum_ov004_0215d670_620 = 0x26c };
#endif
    char* p = (char*)GameState::GetInstance() + Enum_ov004_0215d670_620;
    void* s = LinkSession_GetInstance();
    unsigned short v = *(unsigned short*)(p + 0x5d00 + 0xc);
    int state = (unsigned int)(v << 16) >> 29;
    if (state == 1) {
        func_ov004_0215c0c0(obj);
        return 0;
    }
    if (state == 2) {
        func_ov011_021848a0(obj, 0x2367);
        return 0;
    }
    if (!LinkSession_IsSlotLost((struct SearchStruct*)s, 0)) {
        return 1;
    }
    func_ov011_021848a0(obj, 0x2369);
    return 0;
}

// USA: func_ov004_0215d6f8
extern "C" ARM int func_ov004_0215d6f8(void* obj) {
    void* p = data_ov004_021707e0;
    if (*(unsigned char*)((char*)p + 0x11) == 1) {
        func_ov011_021848a0(obj, 0x236a);
    } else {
        func_ov011_021848a0(obj, 0x38a);
    }
    return 0;
}
extern "C" int func_02086c4c(unsigned char* obj, int id, int key);
extern "C" short func_02086bf4(char* obj, int key);

class Struct_ov004_0215d738 {
public:
    virtual void v00(); virtual void inline_ov004_0215d738_2(); virtual void inline_ov004_0215d738_3(); virtual void inline_ov004_0215d738_4();
    virtual void v04(); virtual void inline_ov004_0215d738_6(); virtual void inline_ov004_0215d738_7(); virtual void inline_ov004_0215d738_8();
    virtual void v08(); virtual void inline_ov004_0215d738_10(); virtual void v10(); virtual void inline_ov004_0215d738_12();
    virtual void inline_ov004_0215d738_13(); virtual void inline_ov004_0215d738_14(); virtual void v14(); virtual void inline_ov004_0215d738_16();
    virtual void inline_ov004_0215d738_17(); virtual void inline_ov004_0215d738_18(); virtual void v18(); virtual void inline_ov004_0215d738_20();
    virtual void v20(); virtual void inline_ov004_0215d738_22(); virtual void inline_ov004_0215d738_23(); virtual void inline_ov004_0215d738_24();
    virtual void v24(); virtual void inline_ov004_0215d738_26(); virtual void inline_ov004_0215d738_27(); virtual void inline_ov004_0215d738_28();
    virtual void v28(); virtual void inline_ov004_0215d738_30(); virtual void v30(); virtual void inline_ov004_0215d738_32();
    virtual void inline_ov004_0215d738_33(); virtual void inline_ov004_0215d738_34(); virtual void v34(); virtual void inline_ov004_0215d738_36();
    virtual void inline_ov004_0215d738_37(); virtual void inline_ov004_0215d738_38(); virtual void v38(); virtual void inline_ov004_0215d738_40();
    virtual void v40(); virtual void inline_ov004_0215d738_42(); virtual void inline_ov004_0215d738_43(); virtual void inline_ov004_0215d738_44();
    virtual void v44(); virtual void inline_ov004_0215d738_46(); virtual void inline_ov004_0215d738_47(); virtual void inline_ov004_0215d738_48();
    virtual void v48(); virtual void inline_ov004_0215d738_50(); virtual void v50(); virtual void inline_ov004_0215d738_52();
    virtual void inline_ov004_0215d738_53(); virtual void inline_ov004_0215d738_54();
    virtual void inline_ov004_0215d738_55(int arg);
    virtual void inline_ov004_0215d738_56();
    virtual void inline_ov004_0215d738_57(int arg);
};

struct Struct_ov004_0215d738_2 { void* unknown_0_; char pad[0x1c]; int f20; };

struct Struct_ov004_0215d738_3 { char pad[0x32]; short ids[4]; short count; };

struct Struct_ov004_0216fb80 { int id[4]; };
extern const Struct_ov004_0216fb80 data_ov004_0216fb80;

// USA: func_ov004_0215d738
extern "C" ARM int func_ov004_0215d738(void* a) {
    GameState* bs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GameState_GetParty(bs);
    int idx = func_ov004_02156e2c(a, 0x5b);
    if (idx < 0) return 0;
    short* entry = (short*)func_ov004_021570a4(a, idx & 0xff);
    if (!entry) return 0;
    void* container = ((void*)func_ov004_02156fd4(a, 5));
    if (!container) return 0;
    if (!ItemTable_Find((struct ItemTable*)container, *entry)) return 0;

    int ids[4];
    *(Struct_ov004_0216fb80*)ids = data_ov004_0216fb80;
    int count;
    int j;
    Struct_ov004_0215d738_3* party = (Struct_ov004_0215d738_3*)data_ov004_021707e0;
    count = party->count;
    for (j = 0; j < count; j++) {
        ids[j] = party->ids[j];
    }

    for (unsigned char i = 0; i < 5; i++) {
        int id = ids[i];
        GameObject* member = bs->GetPartyMemberByIndex(id);
        if (member) {
            Struct_ov004_0215d738_2* node = ((Struct_ov004_0215d738_2*)func_ov004_02156f04(a, i + 0x1df));
            if (!node) return 0;
            node->f20 = *(int*)((char*)member + 0x134);
            id = ids[i];
            ((Struct_ov004_0215d738*)node)->inline_ov004_0215d738_55(func_020dcc98((signed char)id));
            int r = func_02086c4c(p, id, *entry);
            if (r == 0) {
                func_ov023_021f65d4(a, i + 0x1e4, 8);
                func_ov023_021f65d4(a, i + 0x1ee, 8);
                func_ov023_021f6600(a, i + 0x1e9, 8);
            } else {
                func_ov023_021f6600(a, i + 0x1e4, 8);
                func_ov023_021f6600(a, i + 0x1ee, 8);
                func_ov023_021f65d4(a, i + 0x1e9, 8);
                Struct_ov004_0215d738* n = ((Struct_ov004_0215d738*)func_ov004_02156f38(a, i + 0x1e4));
                if (n) n->inline_ov004_0215d738_57(r);
            }
        } else if (i == count) {
            func_ov023_021f6600(a, i + 0x1df, 8);
            func_ov023_021f6600(a, i + 0x1e4, 8);
            func_ov023_021f6600(a, i + 0x1ee, 8);
            func_ov023_021f65d4(a, i + 0x1e9, 8);
            int sum = func_02086bf4((char*)p, *entry);
            Struct_ov004_0215d738* n = ((Struct_ov004_0215d738*)func_ov004_02156f38(a, i + 0x1e4));
            if (n) n->inline_ov004_0215d738_57(sum);
        } else {
            func_ov023_021f65d4(a, i + 0x1df, 8);
            func_ov023_021f65d4(a, i + 0x1e4, 8);
            func_ov023_021f65d4(a, i + 0x1ee, 8);
            func_ov023_021f65d4(a, i + 0x1e9, 8);
        }
    }

    void* n = func_ov004_02156f6c(a, 0x1c);
    if (n) func_ov023_021f809c(n, a);
    return 0;
}
extern "C" void func_0207cf30(void*, int, int, int);

// USA: func_ov004_0215da0c
extern "C" ARM int func_ov004_0215da0c(void* obj) {
    void* p = GameState_GetParty(GameState::GetInstance());
    int var1 = func_02086bf4((char*)p, *(short*)(data_ov004_021707e0 + 0xe));

#if !defined(jpn)
    unsigned char flag = data_ov004_021707e0[0x9d];
    if (!flag) return 0;
#endif

    int container = func_ov004_02156fd4(obj, 5);
    if (container) {
        unsigned char local[0x38];
        ((SafeAllocator*)local)->ResetAllocatorPointer();
        ItemTable_Construct(local + 0x14);
        func_0207cbe8((char*)local);
        func_0207cbe8((char*)local);

        *(int*)(local + 0x2c) = container;
        func_0207cf30(local, *(short*)(data_ov004_021707e0 + 0xe), data_ov004_021707e0[0x11], 1);

        func_0207cc0c((char*)local);
#if defined(jpn)
        data_ov004_021707e0[0xa9] = 0;
#else
        data_ov004_021707e0[0x9d] = 0;
#endif
    }

    int sum = var1 + data_ov004_021707e0[0x11];
    if (sum > 0x63) {
        func_ov011_021848a0(obj, 0x2385);
    } else {
        func_ov011_021848a0(obj, 0x38d);
    }
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}

struct Menu0215db14 {
    char unknown_0_[0xe];
    short key;
    char pad10;
    unsigned char unknown_11_;
    signed char combatant;
    char unknown_13_[0x1f];
    short entries[4];
    short count;
#if defined(jpn)
    char unknown_3c_[0x6d];
#else
    char unknown1_3c_[0x61];
#endif
    unsigned char active;
};
struct Struct_ov004_0216fb40 { int entries[4]; };
extern Struct_ov004_0216fb40 data_ov004_0216fb40;
struct Struct_ov004_0215db14_2 { SafeAllocator allocator; char state[0x18]; int container; char pad[8]; };
struct Struct_ov004_0215db14_3 { char pad[0x130]; unsigned int* flags; };
extern "C" int func_ov004_0215da0c(void*);
extern "C" int func_02083960(Struct_0207d300*);
extern "C" short func_02086bf4(char*, int);
extern "C" void func_0207ccf0(void*, int, int, int, int, int, int);

// USA: func_ov004_0215db14
extern "C" ARM int func_ov004_0215db14(void* obj) {
    GameState* state = GameState::GetInstance();
#if !defined(jpn)
    if (!((Menu0215db14*)data_ov004_021707e0)->active) return 0;
#endif
    int index = func_ov004_02156e2c(obj, 0x5f);
    if (index < 0) return 0;
    GameObject* combatant;
    int var3;
    int selected;
    Struct_ov004_0216fb40 list;
    COPY_ARRAY(list.entries, data_ov004_0216fb40.entries);
    int count;
    int i;
    Menu0215db14* menu;
    menu = ((Menu0215db14*)data_ov004_021707e0);
    count = menu->count;
    for (i = 0; i < count; i++) list.entries[i] = menu->entries[i];
    if (count == index) {
        func_ov004_0215da0c(obj);
        return 0;
    }
    selected = list.entries[index];
    menu->combatant = selected;
    combatant = func_0200ff1c(state, ((Menu0215db14*)data_ov004_021707e0)->combatant);
    var3 = 0;
    if (combatant) {
        Struct_0207d300* slots = ((Struct_0207d300*)func_02053c6c((unsigned char*)combatant));
        if (slots) var3 = 8 - func_02083960(slots);
    }
    int total = func_02086bf4((char*)GameState_GetParty(state), ((Menu0215db14*)data_ov004_021707e0)->key);
    int container = func_ov004_02156fd4(obj, 5);
    if (container) {
        Struct_ov004_0215db14_2 work;
        work.allocator.ResetAllocatorPointer();
        ItemTable_Construct(work.state);
        func_0207cbe8((char*)&work);
        func_0207cbe8((char*)&work);
        work.container = container;
        func_0207ccf0(&work, ((Menu0215db14*)data_ov004_021707e0)->key, ((Menu0215db14*)data_ov004_021707e0)->unknown_11_, selected, 1, 1, 0);
        func_0207cc0c((char*)&work);
        ((Menu0215db14*)data_ov004_021707e0)->active = 0;
    }
    if (((Menu0215db14*)data_ov004_021707e0)->unknown_11_ > var3 && total < 99) {
        func_ov011_021848a0(obj, 0x2383);
    } else if (((Menu0215db14*)data_ov004_021707e0)->unknown_11_ > var3 && total >= 99) {
        func_ov011_021848a0(obj, 0x2386);
    } else if (combatant && (*((Struct_ov004_0215db14_3*)combatant)->flags & 1)) {
        func_ov011_021848a0(obj, 0x2387);
    } else {
        func_ov011_021848a0(obj, 0x2382);
    }
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}
extern "C" int func_ov004_02157a28(void* a, int flag);
struct Struct_ov004_0216fb20 { unsigned char b[8]; };
extern Struct_ov004_0216fb20 data_ov004_0216fb20;
extern int data_ov004_0216fc1c[];
struct Entry { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int unknown_8_0_ : 4; unsigned int unknown_8_4_ : 28; };
struct Struct_ov000_021540fc_2 { unsigned int lo : 27; unsigned int unknown_3_3_ : 1; unsigned int unknown_3_4_ : 1;
              unsigned int unknown_3_5_ : 1;  unsigned int hi : 2; };
struct Struct_ov000_0215b278 { unsigned int unknown_0_; Struct_ov000_021540fc_2 f; };
struct Struct_ov004_0215dd3c { unsigned char bit0 : 1; unsigned char unknown_0_1_ : 7; };
#if defined(jpn)

extern "C" struct GameObject* func_0200ff1c(struct GameState*, int);
#endif

// USA: func_ov004_0215dd3c
extern "C" ARM int func_ov004_0215dd3c(void* a) {
    int prev = ((int)func_ov004_02157128(a));
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(bs, prev);
    if (!combatant) return 0;
    void* ptr = GameState_GetParty(bs);
    Struct_ov004_0216fb20 buf;
    buf = data_ov004_0216fb20;
    unsigned char flags[2];
    for (unsigned char i = 0; i < 8; i++) {
        unsigned char var7 = buf.b[i];
        if (var7 == 0xff) break;
#if defined(jpn)
        char* entry = (char*)(*(unsigned char**)((char*)combatant + 0x144) + 0x194) + var7 * 0x20;
#else
        char* entry = (char*)(*(unsigned char**)((char*)combatant + 0x150) + 0x194) + var7 * 0x20;
#endif
        if (entry) {
            char* p2 = *(char**)entry;
            if (p2) {
                if (!((Struct_ov000_0215b278*)p2)->f.unknown_3_5_) {
                    int var10 = ((Struct_ov000_0215b278*)p2)->f.unknown_3_3_ ? 1 : 0;
                    flags[1] = ((Struct_ov000_0215b278*)p2)->f.unknown_3_4_ ? 1 : 0;
                    flags[0] = var10;
#if defined(jpn)
                    unsigned int idx = ((Struct_ov004_0215dd3c*)(*(unsigned char**)((char*)combatant + 0x144) + 0x49c))->bit0;
#else
                    unsigned int idx = ((Struct_ov004_0215dd3c*)(*(unsigned char**)((char*)combatant + 0x150) + 0x49c))->bit0;
#endif
                    if (!flags[idx]) {
                        func_02052d7c((Struct_02052d7c*)combatant, data_ov004_0216fc1c[i], (int)(-1));
                        if (entry) {
                            unsigned int var12 = ((Entry*)entry)->unknown_8_0_;
                            short s18 = *(short*)(entry + 0x18);
                            func_0207c378((Struct_020732cc*)((char*)ptr + 0x1d4), s18, 1, var12);
                        }
                    }
                }
            }
        }
    }
    return func_ov004_02157a28(a, 1);
}

struct Struct0209c830;
extern "C" void func_0209c830(Struct0209c830*, int);

// USA: func_ov004_0215de80
extern "C" ARM int func_ov004_0215de80(void) {
    func_0209c830((Struct0209c830*)g_bgmPlayer, 0x3d);
    return 0;
}
#if !defined(jpn)
struct Struct_ov004_0215de9c;
extern "C" void func_ov023_021fb25c(Struct_ov004_0215de9c* obj, unsigned int a, unsigned int b, unsigned int c, int d);

struct Struct_ov004_0215de9c_2 { int type; int x; int y; };

class Struct_ov004_0215de9c_3 {
public:
	virtual void v00(); virtual void inline_ov004_0215de9c_2(); virtual void inline_ov004_0215de9c_3(); virtual void inline_ov004_0215de9c_4();
	virtual void v04(); virtual void inline_ov004_0215de9c_6(); virtual void inline_ov004_0215de9c_7();
	virtual void inline_ov004_0215de9c_8(Struct_ov004_0215de9c_2* p);
};

// USA: func_ov004_0215de9c
extern "C" ARM int func_ov004_0215de9c(void* a) {
	GameState* battle = GameState::GetInstance();
	void* base = func_ov011_021849c8(a);
	Struct_ov004_0215de9c_3* node = (Struct_ov004_0215de9c_3*)func_ov023_021f6880((void**)base, 0x2be);
	if (!node) return 0;
	if (func_ov024_021f6f10(node) != 1) return 0;
	Struct_ov004_0215de9c_2 p;
	p.x = 0x5a000;
	p.y = 0;
	switch (GameState_GetLanguage((struct Struct0200fb08*)battle)) {
	case 1:
		p.type = 0x90000;
		node->inline_ov004_0215de9c_8(&p);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node, 0, 0, 0x2c, 0xc);
		break;
	case 2:
		p.type = 0x90000;
		node->inline_ov004_0215de9c_8(&p);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node, 0, 0, 0x2c, 0xc);
		break;
	case 3:
		p.type = 0x98000;
		node->inline_ov004_0215de9c_8(&p);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node, 0, 0, 0x20, 0xc);
		break;
	case 4:
		p.type = 0x8c000;
		node->inline_ov004_0215de9c_8(&p);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node, 0, 0, 0x32, 0xc);
		break;
	case 5:
		p.type = 0x8c000;
		node->inline_ov004_0215de9c_8(&p);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node, 0, 0, 0x32, 0xc);
		break;
	}
	void* node2 = func_ov023_021f6880((void**)base, 0x2bf);
	if (!node2) return 0;
	if (func_ov024_021f6f10(node2) != 1) return 0;
	switch (GameState_GetLanguage((struct Struct0200fb08*)battle)) {
	case 1: func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node2, 0, 0, 0x2c, 0xc); break;
	case 2: func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node2, 0, 0, 0x2c, 0xc); break;
	case 3: func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node2, 0, 0, 0x24, 0xc); break;
	case 4: func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node2, 0, 0, 0x30, 0xc); break;
	case 5: func_ov023_021fb25c((struct Struct_ov004_0215de9c*)node2, 0, 0, 0x30, 0xc); break;
	}
	return 0;
}
#endif

struct Element020de650_0215e148 { char pad[8]; unsigned int field8 : 4; };
extern "C" void func_0207cf30(void* buf, int a, int b, int c);

#if defined(jpn)
#define MESSAGE_FLAG_OFFSET 0xa9
#else
#define MESSAGE_FLAG_OFFSET 0x9d
#endif

// USA: func_ov004_0215e148
extern "C" ARM int func_ov004_0215e148(void* obj) {
    if (((char*)data_ov004_021707e0) != NULL && *(unsigned char*)(((char*)data_ov004_021707e0) + MESSAGE_FLAG_OFFSET) != 0) {
        GameState::GetInstance();
        int key = func_ov004_02156e2c(obj, 0x5b);
        if (key < 0) return 0;
        void* entry = func_ov004_021570a4(obj, key & 0xff);
        if (!entry) return 0;
        struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
        if (!node) return 0;
        struct Element020de650_0215e148* elem = ((struct Element020de650_0215e148*)ItemTable_Find(node, *(short*)entry));
        if (!elem) return 0;

        char buf[0x38];
        ((SafeAllocator*)buf)->ResetAllocatorPointer();
        ItemTable_Construct(buf + 0x14);
        func_0207cbe8(buf);
        func_0207cbe8(buf);
        *(void**)(buf + 0x2c) = node;
        int ok = elem->field8 <= 7;
        if (ok) {
            func_0207d134((Struct_0207d134*)buf, (int)(*(short*)(((char*)data_ov004_021707e0) + 0xe)), *(signed char*)(((char*)data_ov004_021707e0) + 0x11));
        } else {
            func_0207cf30(buf, *(short*)(((char*)data_ov004_021707e0) + 0xe), *(unsigned char*)(((char*)data_ov004_021707e0) + 0x11), 1);
        }
        func_0207cc0c(buf);
    }
    return 0;
}

#undef MESSAGE_FLAG_OFFSET
