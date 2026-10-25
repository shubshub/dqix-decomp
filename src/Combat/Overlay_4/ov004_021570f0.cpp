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
extern "C" ARM signed char func_ov004_021570f0(int arg0) {
    if (arg0 < 0) return -1;
    char* var0 = ((char*)data_ov004_021707e0);
    short var1 = *(short*)(var0 + 0x3a);
    if (arg0 >= var1) return -1;
    return (signed char)(*(short*)(var0 + arg0 * 2 + 0x32));
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
extern "C" unsigned int func_ov023_021f6f08(struct Struct_ov004_02153978* arg0);
extern "C" signed char func_ov004_021570f0(int arg0);

// USA: func_ov004_02157128
extern "C" ARM signed char func_ov004_02157128(void* arg0) {
    void* var0 = func_ov004_02156e68(arg0, 0x5f);
    if (!var0) {
        return (signed char)(*(short*)(data_ov004_021707e0 + 0x3c));
    }

    if (func_ov024_021f6f10(var0) != 8) {
        return 0;
    }

    int var1 = 0;
    unsigned int var2 = func_ov023_021f6f08((struct Struct_ov004_02153978*)var0);
    switch (var2) {
        case 0x322: var1 = 0; break;
        case 0x323: var1 = 1; break;
        case 0x324: var1 = 2; break;
        case 0x325: var1 = 3; break;
        case 0x326: var1 = 4; break;
        case 0x327: return -1;
        default: break;
    }
    return func_ov004_021570f0(var1);
}

#undef func_ov024_021f6f10
#undef func_ov024_021f6f10

// USA: func_ov004_021571d8
extern "C" ARM int func_ov004_021571d8(int arg0) {
    if (((int)func_ov004_02156e68((void*)arg0, 0x65)) != 0) {
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

struct Struct_ov004_021571f4 { int unknown_0_, unknown_4_, unknown_8_; };

class Struct_ov004_021571f4_2 {
public:
    virtual void inline_ov004_021571f4(); virtual void inline_ov004_021571f4_2(); virtual void inline_ov004_021571f4_3(); virtual void inline_ov004_021571f4_4();
    virtual void inline_ov004_021571f4_5(); virtual void inline_ov004_021571f4_6(); virtual void inline_ov004_021571f4_7();
    virtual void inline_ov004_021571f4_8(const Struct_ov004_021571f4* arg0);
};

struct Struct_ov004_021571f4_3 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_[12];
    int unknown_28_;
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021fa078(void* arg0, void* arg1, unsigned short arg2, Struct_ov004_021571f4* arg3, int arg4, int arg5);

// USA: func_ov004_021571f4
extern "C" ARM void func_ov004_021571f4(void* arg0, int arg1) {
    int var0 = arg1 - ((Struct_ov004_021571f4_3*)data_ov004_021707e0)->unknown_28_;
    if (var0 == 0) return;

    for (int var1 = 0; var1 < var0; var1++) {
        int var2 = rand() % 12;
        Struct_ov004_021571f4_3* var3 = ((Struct_ov004_021571f4_3*)data_ov004_021707e0);
        while (var3->unknown_1c_[var2] >= 10) {
            var2 = (var2 + 1) % 12;
        }
        var3->unknown_1c_[var2]++;

        Struct_ov004_021571f4_3* var4 = ((Struct_ov004_021571f4_3*)data_ov004_021707e0);
        int var5 = var4->unknown_1c_[var2];
        int var6 = var4->unknown_28_ + 0x578 + var1;

        Struct_ov004_021571f4_2* var7 = ((Struct_ov004_021571f4_2*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), var6));
        if (var7 == 0 || func_ov023_021f6f10(var7) != 0) {
            var7 = 0;
        }
        if (!var7) return;

        Struct_ov004_021571f4 var8;
        var8.unknown_0_ = (var2 * 21) << 12;
        var8.unknown_4_ = (var5 * -19) << 12;
        var8.unknown_8_ = 0;
        var7->inline_ov004_021571f4_8(&var8);

        Struct_ov004_021571f4 var9;
        var9.unknown_0_ = (var2 * 21) << 12;
        var9.unknown_4_ = (0xc0 - var5 * 19) << 12;
        var9.unknown_8_ = 0;

        void* var10 = ((Struct_ov004_021571f4_2*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), 0xffff));
        if (!var10) return;
        func_ov023_021fa078(var10, arg0, var6, &var9, 0xd000, 0xd000);
    }
    ((Struct_ov004_021571f4_3*)data_ov004_021707e0)->unknown_28_ = arg1;
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

struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey_02072a68(struct TableA68*, int);
int DispatchAdjustmentIfType4_02157018(void*, int);
int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* global);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);

// USA: func_ov004_02157374
extern "C" ARM void func_ov004_02157374(void* arg0, int arg1, int arg2, char* arg3, unsigned char arg4) {
    if (arg1 <= 0) return;

    struct Struct_02072a68_2* var0 = (struct Struct_02072a68_2*)func_ov004_02157018(arg0, 4);
    int var1 = 0;
    const char* var2;

    if ((arg1 >= 0x4e20 && arg1 <= 0x4e84) ||
        (arg1 >= 0x4e86 && arg1 <= 0x4e8b) ||
        (arg1 == 0x4e8d) ||
        (arg1 >= 0x4e8f && arg1 <= 0x5207) ||
        (arg1 >= 0xcb24 && arg1 <= 0xcb29) ||
        (arg1 >= 0xcb2d && arg1 < 0xcb84) ||
        (arg1 >= 0xcb88 && arg1 <= 0xcb8d) ||
        (arg1 >= 0xcb91 && arg1 < 0xcbe8) ||
        (arg1 >= 0xcbec && arg1 <= 0xcbf1) ||
        (arg1 >= 0xcbf5 && arg1 < 0xccb0) ||
        (arg1 >= 0xcf08 && arg1 < 0xd034)) {
        var2 = (const char*)func_02072a68(var0, 0x64);
    } else if ((arg1 == 0x4e85) || (arg1 >= 0x59d8 && arg1 < 0x5dc0)) {
        var2 = (const char*)func_02072a68(var0, 0x65);
    } else if (arg1 == 0x4e8c) {
        var2 = (const char*)func_02072a68(var0, 0x66);
    } else if (arg1 == 0x4e8e) {
        var2 = (const char*)func_02072a68(var0, 0x67);
    } else if (arg1 >= 0xc800 && arg1 < 0xc864) {
        var2 = (const char*)func_02072a68(var0, 0x68);
    } else if (arg1 >= 0xc350 && arg1 < 0xc3b4) {
        var2 = (const char*)func_02072a68(var0, 0x69);
    } else if ((arg1 >= 0xc738 && arg1 <= 0xc79e) ||
               (arg1 >= 0xc7a0 && arg1 < 0xc800) ||
               (arg1 >= 0xc864 && arg1 < 0xc8c8)) {
        var2 = (const char*)func_02072a68(var0, 0x6a);
    } else if (arg1 == 0xc79f) {
#if defined(jpn)
        var2 = (const char*)func_02072a68(var0, 0x6b);
#else
        var2 = (const char*)func_02072a68(var0, 0x6a);
#endif
    } else if ((arg1 >= 0xcb20 && arg1 <= 0xcb23) ||
               (arg1 >= 0xcb2a && arg1 <= 0xcb2c) ||
               (arg1 >= 0xcb84 && arg1 <= 0xcb87) ||
               (arg1 >= 0xcb8e && arg1 <= 0xcb90) ||
               (arg1 >= 0xcbe8 && arg1 <= 0xcbeb) ||
               (arg1 >= 0xcbf2 && arg1 <= 0xcbf4) ||
               (arg1 >= 0xccb0 && arg1 <= 0xccb3) ||
               (arg1 >= 0xccba && arg1 <= 0xccbc) ||
               (arg1 >= 0xcd14 && arg1 <= 0xcd17) ||
               (arg1 >= 0xcd1e && arg1 <= 0xcd20) ||
               (arg1 >= 0xcddc && arg1 <= 0xcddf) ||
               (arg1 >= 0xcde6 && arg1 <= 0xcde8)) {
        var2 = (const char*)func_02072a68(var0, 0x6c);
    } else {
        var1 = 1;
#if defined(jpn)
        if (arg2 == 1) {
            var2 = (const char*)func_02072a68(var0, 0x6d);
        }
#endif
        if (arg2 == 2) {
            var2 = (const char*)func_02072a68(var0, 0x70);
        } else if (arg1 >= 0x7918 && arg1 < 0x7d00) {
            var2 = (const char*)func_02072a68(var0, 0x6f);
        } else {
            var2 = (const char*)func_02072a68(var0, 0x6e);
        }
    }

    if (arg4 != 0) {
        if (var1 == 0) return;
    }
    if (var2 == 0) return;

    void* g = (void*)MessageSystem_GetInstance();
    func_02046380(g);
    StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 0, key);
    memcpy(dst, (void*)name, strlen(name));
}

extern "C" int func_020d4ac8(void);
extern "C" void func_ov023_021f6600(void* arg0, int arg1, int arg2);
extern "C" void func_ov023_021f65d4(void* arg0, int arg1, int arg2);

// USA: func_ov004_0215781c
extern "C" ARM void func_ov004_0215781c(void* arg0) {
    int var0 = func_020d4ac8();
    for (int var1 = 0; var1 < 4; var1++) {
        if (var1 == var0) {
            func_ov023_021f6600(arg0, var1 + 0x29, 8);
        } else {
            func_ov023_021f65d4(arg0, var1 + 0x29, 8);
        }
    }
}

// USA: func_ov004_02157874
extern "C" ARM void func_ov004_02157874(void* arg0) {
    for (int var0 = 0; var0 < 4; var0++) {
        func_ov023_021f65d4(arg0, var0 + 0x29, 8);
    }
}

extern "C" void* func_ov004_02156fa0(void*, int);

class Struct_ov004_021578a8 {
public:
    virtual void inline_ov004_021578a8(); virtual void inline_ov004_021578a8_2(); virtual void inline_ov004_021578a8_3(); virtual void inline_ov004_021578a8_4();
    virtual void inline_ov004_021578a8_5(); virtual void inline_ov004_021578a8_6(); virtual void inline_ov004_021578a8_7();
    virtual void inline_ov004_021578a8_8(Vector3i* arg0);
    virtual Vector3i inline_ov004_021578a8_9();
};

// USA: func_ov004_021578a8
extern "C" ARM void func_ov004_021578a8(void* arg0) {
    Vector3i var0;

    Struct_ov004_021578a8* var1 = (Struct_ov004_021578a8*)func_ov004_02156fa0(arg0, 0x517);
    if (var1) {
        var0 = var1->inline_ov004_021578a8_9();
        int var2 = (0xd1 - (data_ov004_021707e0[0x3e] << 3)) << 0xc;
        var0.x = var2;
        var0.y = 0x26000;
        var1->inline_ov004_021578a8_8(&var0);
    }

    Struct_ov004_021578a8* var3 = (Struct_ov004_021578a8*)func_ov004_02156fa0(arg0, 0x518);
    if (var3) {
        var0 = var3->inline_ov004_021578a8_9();
        int var4 = (0xd1 - (data_ov004_021707e0[0x3e] << 3)) << 0xc;
        var0.x = var4;
        var0.y = 0x34000;
        var3->inline_ov004_021578a8_8(&var0);
    }
}

struct Struct_0207cf30_3 { short* unknown_0_; signed char* unknown_4_; short unknown_8_; };
extern "C" signed char func_020a0b3c(struct Struct_0207cf30_3* arg0, int arg1);
extern "C" int func_02086d20(unsigned char* arg0);
extern "C" int func_0207c7a0(void* arg0, int arg1, int arg2);

// USA: func_ov004_0215799c
extern "C" ARM int func_ov004_0215799c(void* arg0, int arg1, unsigned int arg2, int arg3) {
    int var0 = 0;
    unsigned int var1 = (arg2 >= 8 && arg2 <= 9);
    if (var1) {
        void* var2 = arg0;
        if (arg2 == 9) {
            var2 = (char*)arg0 + 0x204 + 0xc00;
        }
        signed char var3 = func_020a0b3c((struct Struct_0207cf30_3*)var2, arg1);
        int var4 = func_02086d20((unsigned char*)arg0);
        var0 = (arg3 * 8 + 0x63) - (var3 + var4);
    } else {
        unsigned int var5 = (arg2 <= 7);
        if (var5) {
            var0 = 0x63 - func_0207c7a0((char*)arg0 + 0x1d4, arg1, 9);
        }
    }
    return var0;
}

struct ItemTable;
struct Field150Holder02052df8;
struct KeyedList0207c484;
struct HeadNode02046b24;
struct FieldTaskQueue;

struct Struct_ov004_02157a28 {
    unsigned int unknown_0_0_ : 4;
    unsigned int unknown_0_4_ : 14;
    unsigned int unknown_2_2_ : 1;
    unsigned int unknown_2_3_ : 13;
};
struct Struct_ov004_02157a28_2 {
    char unknown_0_[8];
    Struct_ov004_02157a28 unknown_8_;
};
struct Struct_ov004_02157a28_3 {
    char unknown_0_[0xe];
    short unknown_e_;
    char unknown_10_;
    unsigned char unknown_11_;
    char unknown_12_[0x28];
    short unknown_3a_;
    char unknown_3c_[0xb];
    unsigned char unknown_47_;
#if defined(jpn)
    char unknown_48_[0x61];
#else
    char unknown1_48_[0x55];
#endif
    unsigned char unknown_9d_;
};

struct Struct_ov004_0216fb90 { int unknown_0_[8]; };
extern Struct_ov004_0216fb90 data_ov004_0216fb90;

struct TextContext_02157a28 {
    SafeAllocator allocator;
    char list[0x18];
    ItemTable* containerData;
    int field30;
    int field34;
};

extern "C" signed char func_ov004_02157128(void*);
extern "C" void* func_0202ae18(void);
extern "C" int func_ov004_02156fd4(void*, int);
extern "C" void func_0207cc18(void*, Struct_ov004_02157a28_2*);
extern "C" void func_02052d7c(struct Struct_02052d7c*, int, short);
extern "C" int func_0207c378(struct Struct_020732cc*, int, int, int);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" void func_ov011_021848a0(void*, int);

struct Element020de650* ItemTable_Find(struct ItemTable*, int);
void* ItemTable_Construct(void*);
void InitStruct0207cbe8(char*);
void InitStruct0207cc0c(char*);
void* GameState_GetParty(struct GameState*);
int GetHalfwordEntryFromField150(Field150Holder02052df8*, int);
int DecrementKeyedStackAmount0207c484(struct KeyedList0207c484*, int, int, int);
void TrySetFlags0x130_020483f0(unsigned char*, unsigned short);
int CheckField0NonZero_0202b7d8(int*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
void FieldTaskQueue_Update(FieldTaskQueue*);

// USA: func_ov004_02157a28
extern "C" ARM int func_ov004_02157a28(void* a, int flag) {
    short id = ((short)func_ov004_02157128(a));
    int* search = ((int*)func_0202ae18());
    GameState* gs = GameState::GetInstance();
    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, id);
    if (!c) return 0;
    ItemTable* cont = (ItemTable*)((void*)func_ov004_02156fd4(a, 5));
    if (!cont) return 0;
    Element_02157a28* elem = ((Element_02157a28*)ItemTable_Find(cont, ((BattleBlk_02157a28*)data_ov004_021707e0)->key));
    if (!elem) return 0;
    int category = elem->bits.category;
    TextContext_02157a28 context;
    context.allocator.ResetAllocatorPointer();
    ItemTable_Construct(context.list);
    InitStruct0207cbe8((char*)&context);
    InitStruct0207cbe8((char*)&context);
    context.containerData = cont;
    func_0207cc18(&context, elem);
    InitStruct0207cc0c((char*)&context);

    int var8 = 0;
    int var9;
    for (var9 = 0; var9 != 8; var9++) {
        if (var9 == var6) {
            var8 = 1;
            break;
        }
    }
    if (!var8) return 0;
    Struct_ov004_0216fb90 var10 = data_ov004_0216fb90;
    int var11 = var10.unknown_0_[var9];
    if (var11 < 0) return 0;

    char* bag = (char*)GameState_GetParty(gs);
    int equipped = GetHalfwordEntryFromField150((Field150Holder02052df8*)c, slot);
    int same = ((BattleBlk_02157a28*)data_ov004_021707e0)->key == equipped;
    func_02052d7c((Obj02052d7c*)c, slot, ((BattleBlk_02157a28*)data_ov004_021707e0)->key);
    if (((BattleBlk_02157a28*)data_ov004_021707e0)->used == 0) {
        func_0207c378((KeyedList0207c378*)(bag + 0x1d4), ((BattleBlk_02157a28*)data_ov004_021707e0)->key, (signed char)(((BattleBlk_02157a28*)data_ov004_021707e0)->count - 1), category);
        ((BattleBlk_02157a28*)data_ov004_021707e0)->dirty = 0;
    } else {
        func_0207c484((Struct_0207c484*)(var12 + 0x1d4), ((Struct_ov004_02157a28_3*)data_ov004_021707e0)->unknown_e_, 1, var6);
    }
    ((BattleBlk_02157a28*)data_ov004_021707e0)->used++;
    if (((Element_02157a28*)ItemTable_Find(cont, equipped))) {
        func_0207c378((KeyedList0207c378*)(bag + 0x1d4), equipped, 1, category);
    }
    int var15 = 0;
    Struct_ov004_02157a28_3* var16 = ((Struct_ov004_02157a28_3*)data_ov004_021707e0);
    unsigned char var17 = var16->unknown_3a_;
    if (var16->unknown_47_ < var16->unknown_11_) {
        if (var17 >= 2) var15 = 1;
    }
    if (!same || flag) {
        int did = 0;
        Element_02157a28* e2 = ((Element_02157a28*)ItemTable_Find(cont, ((BattleBlk_02157a28*)data_ov004_021707e0)->key));
        if (e2 && e2->bits.flag) {
            TrySetFlags0x130_020483f0((unsigned char*)c, 4);
            did = 1;
        }
        if (func_0202b7d8(var1)) {
            func_ov017_021c3fb4(var0, 1);
            func_ov017_021c4418(var0, -1);
            if (var18) func_ov017_021c9e00(var0, 0, 0, 1);
        }
        GameResources* res = GetGameResources();
        HeadNode02046b24** headA = (HeadNode02046b24**)res->unknown_ptr_array_3700[0];
        FieldTaskQueue* ctxB = (FieldTaskQueue*)res->unknown_ptr_array_3700[1];
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        func_ov017_0218f5a4(res, id, 1, 0, 0);
        while (GetHeadNodeIdOrMinusOne(headA) == 0x13) {
            loader->RemoveAllLocks();
            FieldTaskQueue_Update((FieldTaskQueue*)headA);
            if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)ctxB) == 0x14) {
                FieldTaskQueue_Update(ctxB);
            }
        }
        if (var18) {
            if (var15) func_ov011_021848a0(arg0, 0x3e9);
            else func_ov011_021848a0(arg0, 0x3e8);
            return 0;
        }
    }
    if (var15) func_ov011_021848a0(arg0, 0x23bf);
    else func_ov011_021848a0(arg0, 0x393);
    return 0;
}

struct Struct_0201e830;
struct Struct_020a9ea4;

struct Struct_ov004_02157db8 {
    char unknown_0_[0x56b];
    unsigned char unknown_56b_0_ : 4;
    unsigned char unknown_56b_4_ : 4;
};

#if defined(jpn)
enum { Enum_ov004_021570f0_336 = 0x144 };
#else
enum { Enum_ov004_021570f0_336 = 0x150 };
#endif

struct Struct_ov004_02157db8_2 {
    char unknown_0_[Enum_ov004_021570f0_336];
    struct Struct_ov004_02157db8* unknown_150_;
};

struct Struct_ov004_02157db8_3 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};

struct Struct_ov004_02157db8_4 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned short unknown_c_;
    short unknown_e_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    signed char unknown_12_;
    unsigned char unknown_13_;
    unsigned char unknown_14_;
    unsigned char unknown_15_;
    unsigned char unknown_16_[2];
    Struct_ov004_02157db8_3 unknown_18_;
    unsigned char unknown_1c_[0xc];
    unsigned int unknown_28_;
    unsigned char unknown_2c_;
    unsigned char unknown_2d_;
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
    unsigned char unknown_84_[8];
#if defined(jpn)
    unsigned char unknown_8c_[0x18];
#else
    unsigned char unknown1_8c_[0xc];
#endif
    unsigned int unknown_98_;
    unsigned char unknown_9c_;
    unsigned char unknown_9d_;
    unsigned char unknown_9e_[2];
#if !defined(jpn)
    unsigned char unknown_a0_[0xc];
    unsigned char unknown_ac_[0xc];
#endif
};

#if defined(jpn)
enum { Enum_ov004_02157db8_620 = 0xc, Enum_ov004_02157db8_9088 = 0x120, Enum_ov004_02157db8_16384 = 0x6000, Enum_ov004_02157db8_108 = 0x8c };
#else
enum { Enum_ov004_02157db8_620 = 0x26c, Enum_ov004_02157db8_9088 = 0x2380, Enum_ov004_02157db8_16384 = 0x4000, Enum_ov004_02157db8_108 = 0x6c };
#endif

extern char g_bgmPlayer[];

extern "C" void* func_ov011_021845f8(unsigned char*, unsigned int);
extern "C" void func_020a9ea4(struct Struct_020a9ea4*);
#if defined(jpn)
struct Struct020dfc40;
void KeyTable_Reset(struct Struct020dfc40*);
#else
extern "C" void func_020e526c(void*);
#endif
void Clear12Bytes020e46c4(void*);
extern "C" void* Zone3D_GetInstance(void);
unsigned short GetFieldAt0x7e_0201e830(struct S_e830* p);
void Set3DClearColor_020c5588(int, int, int, int, int);
void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
void SetDataPtr_021f5598(void*);
void RegisterSlotA020cf0fc(int);
void RegisterSlotB020cf1a8(int);
struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc*, int);
unsigned char GetField0xcc0209ca98(char*);
void* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
unsigned char CopyOutRegion0x5718_02011494(char*, void*);

// USA: func_ov004_02157db8
extern "C" ARM int func_ov004_02157db8(void* arg0) {
    GameState* var0 = GameState::GetInstance();
    unsigned char* var1 = (unsigned char*)var0 + Enum_ov004_02157db8_620;
    unsigned char* var2 = (unsigned char*)var0 + Enum_ov004_02157db8_9088;
    unsigned char* var3 = var1 + 0x5c00;
    unsigned char* var4 = var2 + Enum_ov004_02157db8_16384;

    ((Struct_ov004_02157db8_4*)data_ov004_021707e0) = 0;
    void* var5 = func_ov011_021845f8((unsigned char*)arg0, 0);
    if (!var5) return 0;
    SafeAllocator* var6 = (SafeAllocator*)((char*)var5 + 4);
    Struct_ov004_02157db8_4* var7 = (Struct_ov004_02157db8_4*)var6->Allocate(sizeof(Struct_ov004_02157db8_4));
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0) = var7;
    if (!var7) return 0;

    var7->unknown_0_ = 0;
    var7->unknown_4_ = 0;
    var7->unknown_8_ = 0;
    var7->unknown_c_ = 0x3def;
    int var8 = -1;
    var7->unknown_e_ = var8;
    var7->unknown_10_ = 0;
    var7->unknown_11_ = 1;
    var7->unknown_12_ = var8;
    var7->unknown_13_ = 0;
    var7->unknown_14_ = 0;
    var7->unknown_15_ = 0;
    memset(&var7->unknown_18_, 0, 4);
    memset(var7->unknown_1c_, 0, 0xc);
    var7->unknown_28_ = 0;
    var7->unknown_2c_ = 0;
    var7->unknown_2d_ = 5;
    var7->unknown_2e_ = 5;
    var7->unknown_46_ = 0;
    var7->unknown_47_ = 0;
    var7->unknown_2f_ = 0;
    var7->unknown_30_ = 0;
    var7->unknown_31_ = 0;
    var7->unknown_3e_ = 0;
    memset(var7->unknown_3f_, 0, 7);
    unsigned char* var9 = var7->unknown_7c_;
    var9[0] = 0;
    var9[1] = 1;
    var9[2] = 4;
    var9[3] = 2;
    var9[4] = 5;
    var9[5] = 3;
    var9[6] = 6;
    var9[7] = 7;
    int var10 = -1;
    var7->unknown_6c_ = var10;
    var7->unknown_6e_ = 0;
    var7->unknown_6f_ = 0;
    var7->unknown_70_ = var10;
    var7->unknown_74_ = var10;
    var7->unknown_78_ = 0;
    func_020a9ea4((struct Struct_020a9ea4*)var7->unknown_84_);
#if defined(jpn)
    KeyTable_Reset((struct Struct020dfc40*)blk->pad8c);
    blk->word98 = 0;
    blk->b9c = 0;
    blk->b9d = 0;
#else
    func_020e526c(var7->unknown1_8c_);
    var7->unknown_98_ = 0;
    var7->unknown_9c_ = 0;
    var7->unknown_9d_ = 0;
    func_020e46c4(var7->unknown_a0_);
    func_020e46c4(var7->unknown_ac_);
#endif

    void* v = Zone3D_GetInstance();
    if (!v) return 0;
    void* p = (char*)v + stateOffset;
    if (!p) return 0;
    ((Blk_02157db8*)data_ov004_021707e0)->half0c = GetFieldAt0x7e_0201e830((struct S_e830*)p);

    unsigned int* var13 = (unsigned int*)GetGameResources();
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_0_ = GetFlags00((GameResources*)var13);
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_4_ = GetFlags04((GameResources*)var13);
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_8_ = GetFlags08((GameResources*)var13);
    SetFlags00((GameResources*)var13, 4);
    SetFlags04((GameResources*)var13, 0x8de);

    int var14 = 0;
    func_020c5588(0, 0x1f, 0x7fff, 0, 0);
    func_020c54a4(0, 0, 0, 0);

    void* var15 = ((void*)func_ov004_02156fd4(arg0, 5));
    if (var15 != 0) {
        func_ov023_021f5598(var15);
    }
    int var16[4];
    int var17[3];
    func_020cf0fc((int)var16);
    func_020cf1a8((int)var17);

    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_18_.unknown_0_0_ = var16[0] + 0x7d0;
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_18_.unknown_1_4_ = var16[1];
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_18_.unknown_2_0_ = var16[2];
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_18_.unknown_2_5_ = var17[0];
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_18_.unknown_3_2_ = var17[1];

    GameObject_DisableControl((Obj020397cc*)bs->GetUnknownGameObject(), 1);
    ((Blk_02157db8*)data_ov004_021707e0)->b2d = GetField0xcc0209ca98(g_bgmPlayer);
    unsigned int subword = *(unsigned int*)(sub4000 + 0x50);
    ((Blk_02157db8*)data_ov004_021707e0)->b2f = (subword & 1) ? 1 : 0;
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xf);

    short* var19 = (short*)(var3 + 4);
    for (int var20 = 0; var20 < 6; ) {
        if (*var19 > 0) {
            ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_46_++;
        }
        var20++;
        var19 = (short*)((char*)var19 + 0x28);
    }

    void* var21 = func_ov011_021845f8((unsigned char*)arg0, 9);
    if (!var21) return 0;
    SafeAllocator* var22 = (SafeAllocator*)((char*)var21 + 4);
#if defined(jpn)
    void* var23 = var22->Allocate(0x8000);
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_98_ = (unsigned int)var23;
#else
    void* var24 = var22->Allocate(0x10800);
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_98_ = (unsigned int)var24;
    memset((void*)((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_98_, 0, 0x10800);
#endif

    unsigned char var25[4];
    unsigned char var26 = func_02011494((char*)var0, var25);
    for (int var27 = 0; var27 < var26; var27++) {
        ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[var27] = var25[var27];
    }
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[4] = var26;

    for (int var28 = 0; var28 < ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[4]; var28++) {
        void* var29 = (void*)func_0200ff1c(var0, ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[var28]);
        if (var29 != 0) {
            struct Struct_ov004_02157db8* var30 = ((struct Struct_ov004_02157db8_2*)var29)->unknown_150_;
            int var31;
            if (var30 != 0) {
                var31 = var30->unknown_56b_0_ != 0;
            } else {
                var31 = 0;
            }
            if (var31 != 0) {
                int var32 = var28;
                while (var32 < ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[4]) {
                    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[var32] = ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[var32 + 1];
                    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[var32 + 1] = -1;
                    var32++;
                }
                ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[4] = ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[4] - 1;
            }
        }
    }
    ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[5] = ((Struct_ov004_02157db8_4*)data_ov004_021707e0)->unknown_32_[0];
    return 0;
}

#if defined(jpn)
enum { Enum_ov004_02158298_108 = 0x8c, Enum_ov004_02158298_620 = 0xc, Enum_ov004_02158298_14096 = 0x3500 };
#else
enum { Enum_ov004_02158298_108 = 0x6c, Enum_ov004_02158298_620 = 0x26c, Enum_ov004_02158298_14096 = 0x3710 };
#endif

struct Struct_0201e828;
extern "C" void func_0201e828(Struct_0201e828*, unsigned short);

void GameObject_EnableControl(void* obj);

void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

struct Struct_ov004_02158298 { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int unknown_8_; unsigned short unknown_c_; };

struct Struct_ov004_02158298_2 { char unknown_0_[0xc]; unsigned short unknown_c_0_ : 13; unsigned short unknown_d_5_ : 3; };
struct Struct_ov004_02158298_3 { char unknown_0_[0x5d00]; struct Struct_ov004_02158298_2 unknown_5d00_; };

// USA: func_ov004_02158298
extern "C" ARM int func_ov004_02158298(void) {
    GameState* var0 = GameState::GetInstance();
    unsigned int* var1 = (unsigned int*)((int)GetGameResources());
    ClearFlags00((GameResources*)var1, ~0);
    ClearFlags04((GameResources*)var1, ~0);
    ClearFlags08((GameResources*)var1, ~0);
    SetFlags00((GameResources*)var1, ((Struct_ov004_02158298*)data_ov004_021707e0)->unknown_0_);
    SetFlags04((GameResources*)var1, ((Struct_ov004_02158298*)data_ov004_021707e0)->unknown_4_);
    SetFlags08((GameResources*)var1, ((Struct_ov004_02158298*)data_ov004_021707e0)->unknown_8_);

    void* p = Zone3D_GetInstance();
    if (!p) return 0;
    p = (char*)p + stateOffset_02158298;
    if (!p) return 0;
    SetFieldAt0x7e_0201e828((struct S_e828*)p, ((Masks021707d8_02158298*)data_ov004_021707e0)->mc);

    GameObject_EnableControl(battle->GetUnknownGameObject());

    struct Struct_ov004_02158298_3* var3 = (struct Struct_ov004_02158298_3*)((char*)var0 + Enum_ov004_02158298_620);
    var3->unknown_5d00_.unknown_c_0_ &= ~0x20;

    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);

    unsigned char* var4 = *(unsigned char**)((char*)var1 + Enum_ov004_02158298_14096);
    if (var4[2] != 0) {
        var4[0x139] = 1;
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
    char unknown_0_[0x13];
    unsigned char unknown_13_;
    unsigned char unknown_14_;
    char unknown_15_[0x1c - 0x15];
    char unknown_1c_[12];
    int unknown_28_;
};
struct Struct_ov004_021583a8_8 {
    char unknown_0_[Enum_ov004_021583a8_92];
    char* unknown_5c_;
    char unknown_60_[Enum_ov004_021583a8_2456 - Enum_ov004_021583a8_92 - 4];
    int unknown_998_;
    char unknown_99c_[4];
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
struct Struct_02072a68_2;
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
extern "C" ARM int func_ov004_021583a8(void* arg0) {
    static unsigned char sShown3;
    static unsigned char sShown2;
    static unsigned char sShown4;
    static unsigned char sShown0;
    static unsigned char sShown1;
    GameState* game = GameState::GetInstance();
    Ctx021583a8* ctx = (Ctx021583a8*)GetGameResources();
    TableA68* table;
    Obj5* o;
    int count;
    char* buf;
    int adj;
    void* sub;
    adj = *(int*)((char*)ctx + adjustOffset);
    sub = *(void**)((char*)ctx + taskOffset);
    table = ((TableA68*)DispatchAdjustmentIfType4_02157018(self, 4));
    o = (Obj5*)((void*)MessageSystem_GetInstance());
    int state = ((Inner021583a8*)data_ov004_021707e0)->f13;
    if (state == 2) {
        ClearOrMaskNodesByState_0215781c(self);
        count = GetSubWordField394_021b1ffc((Obj24_021b1ffc*)sub);
        int kind = ((int)GetSubByteField398_021b2010((Obj24_021b2010*)sub));
        if (count > 0 && sShown4 == 0) {
            if (sShown3 == 0) {
                var5 = var3->unknown_5c_;
                memset(var5, 0, Enum_ov004_021583a8_2400);
                func_ov004_02157374(arg0, var4, var9, var5, (int)1);
                if (var5[0] != 0) {
#if defined(jpn)
                    func_0204500c(var3, var5, 0);
#else
                    if (var5 == strstr(var5, "<PAGE>")) {
                        var5 += 6;
                    }
                    func_0204500c(var3, var5, 0, 0xe3);
#endif
                    var3->unknown_998_ = 1;
                    sShown3 = 1;
                }
            } else {
                if (var3->unknown_9a0_ != 0) {
                    return 1;
                }
                sShown4 = 1;
            }
        }
        FieldTask_ConnectWifi(sub, adj);
        int v = GetFieldromField_021b1fd4_021b1fd4(sub) >> 12;
        if (sShown4 == 0) {
            func_ov004_021571f4(arg0, var10);
        }
        int var11 = ((int)func_ov017_021b2024((Struct_ov004_021583a8_4*)var7));
        int var12 = ((int)func_ov017_021b2038((Struct_ov004_021583a8_5*)var7));
        if (sShown2 == 0 && var11 == 4 && var12 == 0) {
#if defined(jpn)
            func_0204500c(var3, ((char*)func_02072a68(var2, 0x2e)), 0);
#else
            func_0204500c(var3, ((char*)func_02072a68(var2, 0x2e)), 0, 0xe3);
#endif
            var3->unknown_998_ = 1;
            sShown2 = 1;
        }
        if (sShown0 == 0) {
            if ((var11 == 4 && var12 == 5) || (sShown4 != 0 && var4 > 0)) {
#if defined(jpn)
                if (sShown4 == 0) {
                    func_0204500c(var3, ((char*)func_02072a68(var2, 0x25)), 0);
                } else {
                    func_0204500c(var3, ((char*)func_02072a68(var2, 0x33)), 0);
                }
#else
                if (sShown4 == 0) {
                    func_0204500c(var3, ((char*)func_02072a68(var2, 0x25)), 0, 0xe3);
                } else {
                    func_0204500c(var3, ((char*)func_02072a68(var2, 0x33)), 0, 0xe3);
                }
#endif
                var3->unknown_998_ = 1;
                sShown0 = 1;
            }
        }
        if (*(int*)((char*)ctx + busyOffset) == 0) {
            ((Inner021583a8*)data_ov004_021707e0)->f13++;
            game = GameState::GetInstance();
            GameObject_DisableControl((Obj020397cc*)game->GetUnknownGameObject(), 1);
        }
    } else if (var8 == 3) {
        if (var3->unknown_9a0_ != 3) {
            return 1;
        }
        func_ov004_02157874(arg0);
        char* var13 = var3->unknown_5c_;
        memset(var13, 0, Enum_ov004_021583a8_2400);
        char* var14 = 0;
        int var15 = ((int)func_ov017_021b1fe8((Struct_ov004_021583a8*)var7));
        if (var15 & 1) {
            unsigned char var16[0xb0];
            func_020ac4c0(var16);
            func_020a059c((Struct_020a059c*)var16, 1);
            func_020ac494(var16);
            char* var17 = ((char*)func_02072a68(var2, 0x26));
            memcpy(var13, var17, strlen(var17));
            ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->unknown_14_ = 1;
            func_ov011_021848a0(arg0, 0x3af);
        } else {
#if defined(jpn)
            if (var15 & 0x80) {
                var14 = ((char*)func_02072a68(var2, 0x35));
            } else if (sShown2 == 0) {
                var14 = ((char*)func_02072a68(var2, 0x15));
            } else {
                var14 = ((char*)func_02072a68(var2, 0x2f));
            }
            int var18 = strlen(var14);
            memcpy(var13, var14, var18);
            var13 += var18;
#else
            if (var15 & 0x80) {
                var14 = ((char*)func_02072a68(var2, 0x35));
            } else if (sShown2 != 0) {
                var14 = ((char*)func_02072a68(var2, 0x2f));
            }
            if (var14 != 0) {
                int var19 = strlen(var14);
                memcpy(var13, var14, var19);
                var13 += var19;
            }
#endif
            if (sShown4 == 0) {
                int var20 = func_ov017_021b1ffc((Struct_ov004_021583a8_2*)var7);
                int var21 = ((int)func_ov017_021b2010((Struct_ov004_021583a8_3*)var7));
                func_ov004_02157374(arg0, var20, var21, var13, (int)0);
                var13 += strlen(var13);
            }
            char* var22 = ((char*)func_02072a68(var2, 0x27));
            memcpy(var13, var22, strlen(var22));
            func_ov011_02184be0(arg0, 0x47, 0x46);
            ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->unknown_14_ = 0;
        }
#if defined(jpn)
        func_0204500c(var3, var3->unknown_5c_, 0);
#else
        char* var23 = var3->unknown_5c_;
        if (var23 == strstr(var23, "<PAGE>")) {
            var23 += 6;
        }
        func_0204500c(var3, var23, 0, 0xe3);
#endif
        var3->unknown_998_ = 1;
        *((unsigned char*)var7 + 1) = 1;
        ((Struct_ov004_021583a8_7*)data_ov004_021707e0)->unknown_13_ = 0;
        Struct_ov004_021583a8_7* var24 = ((Struct_ov004_021583a8_7*)data_ov004_021707e0);
        memset(var24->unknown_1c_, 0, 12);
        var24->unknown_28_ = 0;
        return 0;
    }
    return 1;
}

#if defined(jpn)
enum { Enum_ov004_0215883c_1788 = 0x4ec, Enum_ov004_0215883c_2888 = 0x928, Enum_ov004_0215883c_1172 = 0x1e4 };
#else
enum { Enum_ov004_0215883c_1788 = 0x6fc, Enum_ov004_0215883c_2888 = 0xb48, Enum_ov004_0215883c_1172 = 0x494 };
#endif

extern "C" int func_ov017_021b1d44(unsigned char*, int, int);
struct Obj24_021b2060;
unsigned char GetSubByteField439_021b2060(Obj24_021b2060* obj);
struct Obj24_021b204c;
unsigned char GetSubByteField438_021b204c(Obj24_021b204c* obj);
struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
struct Obj_02184548 { char pad[0xb4]; int fieldB4; };
int GetFieldB4_02184548(struct Obj_02184548* obj);
struct Obj_02184540 { char pad[0xb0]; int fieldB0; };
int GetFieldB0_02184540(struct Obj_02184540* obj);

// USA: func_ov004_0215883c
extern "C" ARM int func_ov004_0215883c(void* arg0) {
    void* var0 = GetGameResources();
    void* var1 = *(void**)((char*)var0 + 0x3000 + Enum_ov004_0215883c_1788);
    unsigned char var2 = data_ov004_021707e0[0x13];
    void* var3 = *(void**)((char*)var0 + 0x3000 + Enum_ov004_0215883c_2888);

    if (var2 != 0) goto notZero;
    {
        void* var4 = func_ov011_021845f8((unsigned char*)arg0, (int)1);
        if (!var4) {
            func_ov011_021848a0(arg0, 0x395);
            data_ov004_021707e0[0x13] = 0;
            return 0;
        }
        if (!((void*)func_ov017_021b1d44((unsigned char*)var3, 1, 1))) {
            func_ov011_021848a0(arg0, 0x3ac);
            data_ov004_021707e0[0x13] = 0;
            return 0;
        }
        int state = 0x12;
        data_ov004_021707e4 = state;
        BgmPlayer_FadeOut((Actor0209c678*)g_bgmPlayer, state);
        *(void**)((char*)five + 8) = (char*)obj2 + 4;
        int fieldB4 = GetFieldB4_02184548((struct Obj_02184548*)a);
        int fieldB0 = GetFieldB0_02184540((struct Obj_02184540*)a);
        *(int*)((char*)five + 0x34) = fieldB0;
        *(int*)((char*)five + 0x38) = fieldB4;
        data_ov004_021707e0[0x13]++;
        goto retTrue;
    }
notZero:
    if (var2 == 1) {
        int var8 = data_ov004_021707e4 - 1;
        data_ov004_021707e4 = var8;
        if (var8 > 0) return 1;

        FieldTask_ConnectWifi(five, (int)list);
        if (!GetSubByteField439_021b2060((Obj24_021b2060*)five)) goto retTrue;
        if (GetSubByteField438_021b204c((Obj24_021b204c*)five)) {
            if (*(int*)((char*)actorRaw + 0x4000 + countOffset) == 0) {
                func_ov011_021848a0(a, 0x233d);
                return 0;
            }
        }
        if (func_ov017_021b204c((Struct_ov004_0215883c_3*)var3)) goto retTrue;
        data_ov004_021707e0[0x13]++;
        func_ov011_021848a0(arg0, 0x385);
        return 0;
    }
retTrue:
    return 1;
}

struct Struct_ov004_021589e8 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};

extern "C" int func_ov017_021b213c(PackedField017 a, PackedField017 b);
void MessageSystem_Reset(char* obj);
extern "C" void func_ov023_021f65d4(void* obj, int a, int b);

// USA: func_ov004_021589e8
ARM int DispatchEventAndSetFlag_021589e8(void* obj) {
    char* battle = (char*)GameState::GetInstance() + R(0xc, 0x26c) + 0x5c00;
    PackedField017 a = *(PackedField017*)(battle + 0xf4);
    PackedField017 b = *(PackedField017*)(data_ov004_021707e0 + 0x18);
    if (func_ov017_021b213c(a, b) != 0) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        func_ov011_021848a0(obj, 0x387);
    } else {
        func_ov011_021848a0(arg0, 0x3a2);
    }
    func_ov023_021f65d4(arg0, 2, 8);
    return 0;
}

#if defined(jpn)
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

extern "C" void func_02046380(void* arg0);
struct Struct_0201099c_9;
extern "C" void* func_020e5294(void*, int);
extern "C" int func_0202c540(void* arg0);
extern "C" int func_0202b7d8(int* arg0);

struct Struct_ov004_02158a60 {
    unsigned char unknown_0_[0xf8];
    short unknown_f8_;
    unsigned short unknown_fa_;
    unsigned char unknown_fc_[0x10];
    unsigned short unknown_10c_0_ : 13;
    unsigned short unknown_10d_5_ : 3;
    unsigned char unknown_10e_[2];
};

struct Struct_ov004_02158a60_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x5c0c];
#else
    unsigned char unknown1_0_[0x5e6c];
#endif
    Struct_ov004_02158a60 unknown_5e6c_;
};

// USA: func_ov004_02158a60  (semantic: SetupOrRejectAction_02158a60)
extern "C" ARM int func_ov004_02158a60(void* obj) {
    DownloadedRecord02158a60* downloaded = &((GameStateDownloadView02158a60*)GameState::GetInstance())->downloaded;
    short a = downloaded->itemId;
    if (a > 0 || downloaded->unknownFA != 0) {
        void* g = (void*)MessageSystem_GetInstance();
        func_02046380(g);
        struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
        struct Element020de650* elem = ItemTable_Find(node, downloaded->itemId);
#if defined(jpn)
        char name[80];
        func_020e207c((Container020e0310*)(((char*)data_ov004_021707e0) + 0x8c), name, *(short*)((char*)elem + 0x18));
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        int var6 = ((int)func_020e5294(((char*)data_ov004_021707e0) + 0x8c, *(short*)((char*)var4 + 0x18)));
        *(int*)((char*)var2 + 0x18) = var6;
#endif
        func_ov011_021848a0(arg0, 0x3a3);
        return 0;
    }

    void* var7 = func_0202ae18();
    if (func_0202c540(var7) != 0) {
        func_ov011_021848a0(arg0, 0x3ae);
        return 0;
    }
    if (func_0202b7d8((int*)var7) != 0) {
        func_ov011_021848a0(arg0, 0x24cd);
        return 0;
    }
    if (var0->unknown_10c_0_ & 0x10) {
        func_ov011_021848a0(arg0, 0x3a6);
        return 0;
    }
    func_ov011_021848a0(arg0, 0x3b0);
    return 0;
}

struct Struct_ov004_02158b78 { char unknown_0_[0xf6c]; int unknown_f6c_; };
extern "C" void* func_ov004_02156f38(void*, int);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" int func_ov023_021f809c(void*, void*);

class Struct_ov004_02158b78_2 {
public:
    virtual void inline_ov004_02158b78(); virtual void inline_ov004_02158b78_2(); virtual void inline_ov004_02158b78_3(); virtual void inline_ov004_02158b78_4();
    virtual void inline_ov004_02158b78_5(); virtual void inline_ov004_02158b78_6(); virtual void inline_ov004_02158b78_7(); virtual void inline_ov004_02158b78_8();
    virtual void inline_ov004_02158b78_9(); virtual void inline_ov004_02158b78_10(); virtual void inline_ov004_02158b78_11(); virtual void inline_ov004_02158b78_12();
    virtual void inline_ov004_02158b78_13(); virtual void inline_ov004_02158b78_14(); virtual void inline_ov004_02158b78_15(); virtual void inline_ov004_02158b78_16();
    virtual void inline_ov004_02158b78_17(); virtual void inline_ov004_02158b78_18(); virtual void inline_ov004_02158b78_19(); virtual void inline_ov004_02158b78_20();
    virtual void inline_ov004_02158b78_21(); virtual void inline_ov004_02158b78_22(); virtual void inline_ov004_02158b78_23(); virtual void inline_ov004_02158b78_24();
    virtual void inline_ov004_02158b78_25(); virtual void inline_ov004_02158b78_26(); virtual void inline_ov004_02158b78_27(); virtual void inline_ov004_02158b78_28();
    virtual void inline_ov004_02158b78_29(); virtual void inline_ov004_02158b78_30(); virtual void inline_ov004_02158b78_31(); virtual void inline_ov004_02158b78_32();
    virtual void inline_ov004_02158b78_33(); virtual void inline_ov004_02158b78_34(); virtual void inline_ov004_02158b78_35(); virtual void inline_ov004_02158b78_36();
    virtual void inline_ov004_02158b78_37(); virtual void inline_ov004_02158b78_38(); virtual void inline_ov004_02158b78_39(); virtual void inline_ov004_02158b78_40();
    virtual void inline_ov004_02158b78_41(); virtual void inline_ov004_02158b78_42(); virtual void inline_ov004_02158b78_43(); virtual void inline_ov004_02158b78_44();
    virtual void inline_ov004_02158b78_45(); virtual void inline_ov004_02158b78_46(); virtual void inline_ov004_02158b78_47(); virtual void inline_ov004_02158b78_48();
    virtual void inline_ov004_02158b78_49(); virtual void inline_ov004_02158b78_50(); virtual void inline_ov004_02158b78_51(); virtual void inline_ov004_02158b78_52();
    virtual void inline_ov004_02158b78_53(); virtual void inline_ov004_02158b78_54(); virtual void inline_ov004_02158b78_55(); virtual void inline_ov004_02158b78_56();
    virtual void inline_ov004_02158b78_57(int arg0);
};

// USA: func_ov004_02158b78
ARM int Dispatch02158b78(void* self) {
    VObj02158b78* node = (VObj02158b78*)func_ov004_02156f38(self, 0xc9);
    if (node) {
        struct Field2a04_02158b78* fld = (struct Field2a04_02158b78*)GameState_GetParty(GameState::GetInstance());
        node->MethodE0(fld->f0xf6c);
        void* x = func_ov004_02156f6c(self, 0x16);
        if (x) func_ov023_021f809c(x, self);
    }
    return 0;
}

extern "C" int func_ov004_02156e2c(void* arg0, int arg1);
extern "C" void* func_ov004_021570a4(void*, int);
extern "C" void* func_ov004_02157054(void*, int);

struct Struct_ov004_02158bd4;
extern "C" void func_ov023_021fbdf4(Struct_ov004_02158bd4*, int);
extern "C" void func_ov023_021fbdcc(void*, int);
struct Struct_0201099c_9 { unsigned int unknown_0_[8]; };
extern "C" void func_ov023_021f6eb8(void* arg0, int arg1);
extern "C" int func_ov004_0215d738(void*);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" int func_ov004_0215cec4(void*);
extern "C" int func_ov004_0215d384(void* arg0);
extern "C" void func_ov023_021f6e90(char* arg0, int arg1, const void* arg2);

struct Struct_ov004_02158bd4_2 { char unknown_0_[8]; unsigned int unknown_8_0_ : 4; };

// USA: func_ov004_02158bd4
extern "C" ARM int func_ov004_02158bd4(void* arg0) {
    int var0 = func_ov004_02156e2c(arg0, 0x5b);
    if (var0 < 0) return 0;
    void* var1 = func_ov004_021570a4(arg0, (unsigned char)var0);
    if (!var1) return 0;

    void* var2 = func_ov004_02156f6c(arg0, 0x15);
    if (var2) {
        func_ov023_021f809c(var2, arg0);
    }

    void* var3 = func_ov004_02157054(arg0, 7);
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
        func_ov023_021fbdcc(var3, *(short*)((char*)var1 + 0));
    }

    void* container = (void*)func_ov004_02156fd4(obj, 5);
    if (!container) return 0;
    Element020de650* elem = ItemTable_Find((ItemTable*)container, *(short*)((char*)entry + 0));
    if (!elem) return 0;

    void* var6 = func_ov011_021849c8(arg0);
    func_ov023_021f6eb8(var6, 0);

    char var7[0x16];
    VectorizedMemset(var7, 0, 0x16);
    *(short*)(var7 + 0x14) = -1;
    *(short*)(var7 + 0x12) = 0x384;

    int var8 = ((Struct_ov004_02158bd4_2*)var5)->unknown_8_0_;
    switch (var8) {
        case 8:
        case 9:
            func_ov004_0215d738(arg0);
            func_ov023_021f65d4(arg0, 0x17, 8);
            func_ov023_021f65d4(arg0, 0x1b, 8);
            func_ov023_021f6600(arg0, 0x1c, 8);
            var7[0] = 3;
            *(short*)(var7 + 2) = 0x15;
            *(short*)(var7 + 4) = 0x1c;
            *(short*)(var7 + 6) = 0x16;
            break;
        default:
            func_ov004_0215cec4(arg0);
            func_ov004_0215d384(arg0);
            func_ov023_021f6600(arg0, 0x17, 8);
            func_ov023_021f6600(arg0, 0x1b, 8);
            func_ov023_021f65d4(arg0, 0x1c, 8);
            var7[0] = 4;
            *(short*)(var7 + 2) = 0x15;
            *(short*)(var7 + 4) = 0x17;
            *(short*)(var7 + 6) = 0x1b;
            *(short*)(var7 + 8) = 0x16;
            break;
    }

    func_ov023_021f6e90((char*)var6, 0, var7);
    return 0;
}

struct Struct_ov004_02158dcc_2 {
    char unknown_0_[0xe];
    short unknown_e_;
    char unknown_10_;
    unsigned char unknown_11_;
    signed char unknown_12_;
    char unknown_13_[0x1e];
    unsigned char unknown_31_;
    char unknown_32_[0x8];
    short unknown_3a_;
    char unknown_3c_[0xb];
    unsigned char unknown_47_;
    char unknown_48_[0x44];
    unsigned char unknown_8c_[1];
};

struct Struct_ov004_02158dcc_3 {
    short unknown_0_;
    short unknown_2_;
    unsigned int unknown_4_0_ : 7;
    unsigned int unknown_4_7_ : 25;
};

struct Struct_ov004_02158dcc_4 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    char unknown_9_[0xc];
    short unknown_16_;
};

struct Struct_ov004_02158dcc_5 {
    char unknown_0_[0xf6c];
    unsigned int unknown_f6c_;
};

struct Struct_ov004_02158dcc_6 {
    char unknown_0_[0x18];
    int unknown_18_;
};

struct Struct_ov004_02158dcc_7 {
    char unknown_0_[0x2c];
    Vector3i unknown_2c_;
};
struct Struct_ov004_02158dcc;
#if defined(jpn)
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#else
extern "C" void* func_020e5294(void*, int);
#endif

extern "C" int func_ov004_0215799c(void*, int, unsigned int, int);
extern "C" void func_ov011_021849e0(struct Struct_ov004_02158dcc* arg0, unsigned short arg1);
extern "C" int func_ov004_0215d6f8(void*);
extern "C" void* func_ov004_02156ed0(void*, int);
extern "C" void* __clear(void*, int);

// USA: func_ov004_02158dcc
extern "C" ARM int func_ov004_02158dcc(void* obj) {
    int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (key < 0) return 0;
    Entry02158dcc* entry = ((Entry02158dcc*)GetEntryFor_021570a4(obj, (unsigned char)key));
    if (!entry) return 0;
    Element02158dcc* elem = ((Element02158dcc*)ItemTable_Find(((struct ItemTable*)func_ov004_02156fd4(obj, 5)), entry->id));
    if (!elem) return 0;
#if defined(jpn)
    char name[80];
    func_020e207c((Container020e0310*)(((BattleMenuState02158dcc*)data_ov004_021707e0)->table), name, elem->nameId);
    MessageSystem_SetStringArgument((Obj02046574*)((Message02158dcc*)MessageSystem_GetInstance()), 1, name);
#else
    int name = ((int)CallFunc020e52a0_020e5294(((BattleMenuState02158dcc*)data_ov004_021707e0)->table, elem->nameId));
    ((Message02158dcc*)MessageSystem_GetInstance())->name = name;
#endif
    if (var1->unknown_4_0_ == 0) return 0;

    Wallet02158dcc* wallet = (Wallet02158dcc*)GameState_GetParty(GameState::GetInstance());
    if (func_ov004_0215799c(wallet, entry->id, elem->kind, ((BattleMenuState02158dcc*)data_ov004_021707e0)->level) == 0) {
        SetFieldConditional_021849e0((struct Fields021849e0*)obj, 0);
        func_ov011_021848a0(obj, 0x236b);
        return 0;
    }
    if (var5->unknown_f6c_ < var1->unknown_4_7_) {
        func_ov011_021849e0((struct Struct_ov004_02158dcc*)arg0, 0);
        func_ov011_021848a0(arg0, 0x2365);
        return 0;
    }

    func_ov011_021848a0(arg0, 0x5e);
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_e_ = var1->unknown_0_;
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_11_ = 1;
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_12_ = -1;
    ((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_47_ = 0;
    if (var1->unknown_4_0_ == 1 || (var1->unknown_4_7_ <= var5->unknown_f6c_ && var5->unknown_f6c_ < var1->unknown_4_7_ * 2)) {
        func_ov011_021849e0((struct Struct_ov004_02158dcc*)arg0, 0);
        func_ov004_0215d6f8(arg0);
    }
    func_ov023_021f65d4(arg0, 0x35, 0x18);
    func_ov023_021f65d4(arg0, 0x34, 0x10);
    if (((Struct_ov004_02158dcc_2*)data_ov004_021707e0)->unknown_31_) {
        Struct_ov004_02158dcc_7* var6 = ((Struct_ov004_02158dcc_7*)func_ov004_02156ed0(arg0, 0x5b));
        Vector3i var7;
        __clear(&var7, sizeof(var7));
        Vector3i var8 = var7;
        var6->unknown_2c_ = var8;
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
    char unknown_4_[8];
    unsigned char unknown_c_;
    char unknown_d_[0x20 - 0xd];
    void* unknown_20_;
};
struct Struct_ov004_02153e20 {
    char unknown_0_[0x2c];
    Vector3i unknown_2c_;
    char unknown_38_[0x5c - 0x38];
    short unknown_5c_, unknown_5e_;
};
struct Struct_ov004_02158fec_2 {
    short unknown_0_;
    short unknown_2_;
    unsigned int unknown_4_0_ : 7;
    unsigned int unknown_4_7_ : 25;
};
struct Struct_ov004_02158fec_3 {
    unsigned int unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 23;
};
struct Struct_ov004_02158fec_4 {
    char unknown_0_[0x31];
    unsigned char unknown_31_;
};
struct Struct_ov004_0216fb28 { unsigned char unknown_0_[9]; };
extern const Struct_ov004_0216fb28 data_ov004_0216fb28 __attribute__((aligned(4)));
extern const Vector3i data_ov004_0216fb34;
extern "C" void* func_ov004_02156f04(void*, int);
extern "C" void func_ov023_021fb27c(void*, int);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20*, short, unsigned int, unsigned int);
extern "C" int func_ov004_02158bd4(void*);

// USA: func_ov004_02158fec
extern "C" ARM int func_ov004_02158fec(void* arg0) {
    int var0 = 0x12c;
    int var1 = var0 + 6;
    int var2 = 0x138;
    int var3 = var2 + 6;
    int var4 = 0x144;
    Struct_ov004_02153e20* var5 = ((Struct_ov004_02153e20*)func_ov004_02156ed0(arg0, 0x5b));
    if (var5->unknown_5e_ <= 1) {
        var5->unknown_5c_ = 0;
        var5->unknown_5e_ = 1;
    }
    ItemTable* container = ((ItemTable*)func_ov004_02156fd4(object, 5));
    if (!container) return 0;
    RoleTable02158fec roles = data_ov004_0216fb28;
    for (unsigned char i = 0; i < 6; i++) {
        Entry02158fec* entry = ((Entry02158fec*)GetEntryFor_021570a4(object, i));
        if (entry) {
            int style = 15;
            if (entry->count == 0) style = 3;
            if (entry->id > 0) {
                ItemNode02158fec* text = ((ItemNode02158fec*)func_ov004_02156f04(object, textId));
                if (text) {
                    Element020de650_02158fec* element = ((Element020de650_02158fec*)ItemTable_Find(container, entry->id));
                    if (element) {
                        text->value = element->value;
                        ItemNode02158fec* icon = ((ItemNode02158fec*)func_ov004_02156fa0(object, i + 0x14a));
                        if (element->kind == 0) {
                            if (icon) func_ov023_021fb27c(icon, (unsigned short)(element->variant + 0x26));
                        } else {
                            if (var13) func_ov023_021fb27c(var13, (unsigned short)(var7.unknown_0_[var12->unknown_8_0_] + 9));
                        }
                    }
                    var11->inline_ov004_02158fec_55(var10);
                }
                Struct_ov004_02158fec* var14 = ((Struct_ov004_02158fec*)func_ov004_02156f04(arg0, var1));
                if (var14) var14->inline_ov004_02158fec_55(var10);
                Struct_ov004_02158fec* var15 = ((Struct_ov004_02158fec*)func_ov004_02156f04(arg0, var2));
                if (var15) var15->inline_ov004_02158fec_55(var10);
                Struct_ov004_02158fec* var16 = ((Struct_ov004_02158fec*)func_ov004_02156f38(arg0, var3));
                if (var16) {
                    var16->inline_ov004_02158fec_57(var9->unknown_4_0_);
                    var16->inline_ov004_02158fec_55(var10);
                }
                Struct_ov004_02158fec* var17 = ((Struct_ov004_02158fec*)func_ov004_02156f38(arg0, var4));
                if (var17) {
                    var17->inline_ov004_02158fec_57(var9->unknown_4_7_);
                    var17->inline_ov004_02158fec_55(var10);
                }
            } else {
                Struct_ov004_02158fec* var18 = ((Struct_ov004_02158fec*)func_ov004_02156f04(arg0, var0));
                if (var18) var18->unknown_c_ |= 8;
                Struct_ov004_02158fec* var19 = ((Struct_ov004_02158fec*)func_ov004_02156f04(arg0, var1));
                if (var19) var19->unknown_c_ |= 8;
                Struct_ov004_02158fec* var20 = ((Struct_ov004_02158fec*)func_ov004_02156f04(arg0, var2));
                if (var20) var20->unknown_c_ |= 8;
                Struct_ov004_02158fec* var21 = ((Struct_ov004_02158fec*)func_ov004_02156f38(arg0, var3));
                if (var21) var21->unknown_c_ |= 8;
                Struct_ov004_02158fec* var22 = ((Struct_ov004_02158fec*)func_ov004_02156f38(arg0, var4));
                if (var22) var22->unknown_c_ |= 8;
                func_ov023_021f9b30(var5, 0, var8, 0);
                Struct_ov004_02158fec* var23 = ((Struct_ov004_02158fec*)func_ov004_02156fa0(arg0, var8 + 0x14a));
                if (var23) var23->unknown_c_ |= 8;
            }
        }
        var0++;
        var1++;
        var2++;
        var3++;
        var4++;
    }
    func_ov004_02158bd4(arg0);
    if (((Struct_ov004_02158fec_4*)data_ov004_021707e0)->unknown_31_ == 0) {
        Vector3i var24 = data_ov004_0216fb34;
        var5->unknown_2c_ = var24;
        ((Struct_ov004_02158fec_4*)data_ov004_021707e0)->unknown_31_ = 0;
    }
    return 0;
}

class Struct_ov004_02159384 {
public:
	virtual void inline_ov004_02159384(); virtual void inline_ov004_02159384_2(); virtual void inline_ov004_02159384_3(); virtual void inline_ov004_02159384_4();
	virtual void inline_ov004_02159384_5(); virtual void inline_ov004_02159384_6(); virtual void inline_ov004_02159384_7(); virtual void inline_ov004_02159384_8();
	virtual void inline_ov004_02159384_9(); virtual void inline_ov004_02159384_10(); virtual void inline_ov004_02159384_11(); virtual void inline_ov004_02159384_12();
	virtual void inline_ov004_02159384_13(); virtual void inline_ov004_02159384_14(); virtual void inline_ov004_02159384_15(); virtual void inline_ov004_02159384_16();
	virtual void inline_ov004_02159384_17(); virtual void inline_ov004_02159384_18(); virtual void inline_ov004_02159384_19(); virtual void inline_ov004_02159384_20();
	virtual void inline_ov004_02159384_21(); virtual void inline_ov004_02159384_22(); virtual void inline_ov004_02159384_23(); virtual void inline_ov004_02159384_24();
	virtual void inline_ov004_02159384_25(); virtual void inline_ov004_02159384_26(); virtual void inline_ov004_02159384_27(); virtual void inline_ov004_02159384_28();
	virtual void inline_ov004_02159384_29(); virtual void inline_ov004_02159384_30(); virtual void inline_ov004_02159384_31(); virtual void inline_ov004_02159384_32();
	virtual void inline_ov004_02159384_33(); virtual void inline_ov004_02159384_34(); virtual void inline_ov004_02159384_35(); virtual void inline_ov004_02159384_36();
	virtual void inline_ov004_02159384_37(); virtual void inline_ov004_02159384_38(); virtual void inline_ov004_02159384_39(); virtual void inline_ov004_02159384_40();
	virtual void inline_ov004_02159384_41(); virtual void inline_ov004_02159384_42(); virtual void inline_ov004_02159384_43(); virtual void inline_ov004_02159384_44();
	virtual void inline_ov004_02159384_45(); virtual void inline_ov004_02159384_46(); virtual void inline_ov004_02159384_47(); virtual void inline_ov004_02159384_48();
	virtual void inline_ov004_02159384_49(); virtual void inline_ov004_02159384_50(); virtual void inline_ov004_02159384_51(); virtual void inline_ov004_02159384_52();
	virtual void inline_ov004_02159384_53(); virtual void inline_ov004_02159384_54(); virtual void inline_ov004_02159384_55(); virtual void inline_ov004_02159384_56();
	virtual void inline_ov004_02159384_57(int arg0);
};

// USA: func_ov004_02159384
extern "C" ARM int func_ov004_02159384(void* arg0) {
	int var0 = func_ov004_02156e2c(arg0, 0x5b);
	if (var0 < 0) return 0;
	void* var1 = func_ov004_021570a4(arg0, (unsigned char)var0);
	if (!var1) return 0;

	Struct_ov004_02159384* var2 = (Struct_ov004_02159384*)func_ov004_02156f38(arg0, 0x25a);
	if (var2) {
		var2->inline_ov004_02159384_57(data_ov004_021707e0[0x11]);
	}

	Struct_ov004_02159384* var3 = (Struct_ov004_02159384*)func_ov004_02156f38(arg0, 0x2bd);
	if (var3) {
		unsigned int var4 = *(unsigned int*)((char*)var1 + 4);
		var3->inline_ov004_02159384_57(data_ov004_021707e0[0x11] * (var4 >> 7));
	}

	void* var5 = func_ov004_02156f6c(arg0, 0x19);
	if (var5) func_ov023_021f809c(var5, arg0);

	void* var6 = func_ov004_02156f6c(arg0, 0x1a);
	if (var6) func_ov023_021f809c(var6, arg0);

	return 0;
}

// USA: func_ov004_02159468
extern "C" ARM int func_ov004_02159468(void) {
    return 0;
}
extern "C" int func_020dcc98(signed char);

class Struct_ov004_02159470 {
public:
    virtual void inline_ov004_02159470(); virtual void inline_ov004_02159470_2(); virtual void inline_ov004_02159470_3(); virtual void inline_ov004_02159470_4();
    virtual void inline_ov004_02159470_5(); virtual void inline_ov004_02159470_6(); virtual void inline_ov004_02159470_7(); virtual void inline_ov004_02159470_8();
    virtual void inline_ov004_02159470_9(); virtual void inline_ov004_02159470_10(); virtual void inline_ov004_02159470_11(); virtual void inline_ov004_02159470_12();
    virtual void inline_ov004_02159470_13(); virtual void inline_ov004_02159470_14(); virtual void inline_ov004_02159470_15(); virtual void inline_ov004_02159470_16();
    virtual void inline_ov004_02159470_17(); virtual void inline_ov004_02159470_18(); virtual void inline_ov004_02159470_19(); virtual void inline_ov004_02159470_20();
    virtual void inline_ov004_02159470_21(); virtual void inline_ov004_02159470_22(); virtual void inline_ov004_02159470_23(); virtual void inline_ov004_02159470_24();
    virtual void inline_ov004_02159470_25(); virtual void inline_ov004_02159470_26(); virtual void inline_ov004_02159470_27(); virtual void inline_ov004_02159470_28();
    virtual void inline_ov004_02159470_29(); virtual void inline_ov004_02159470_30(); virtual void inline_ov004_02159470_31(); virtual void inline_ov004_02159470_32();
    virtual void inline_ov004_02159470_33(); virtual void inline_ov004_02159470_34(); virtual void inline_ov004_02159470_35(); virtual void inline_ov004_02159470_36();
    virtual void inline_ov004_02159470_37(); virtual void inline_ov004_02159470_38(); virtual void inline_ov004_02159470_39(); virtual void inline_ov004_02159470_40();
    virtual void inline_ov004_02159470_41(); virtual void inline_ov004_02159470_42(); virtual void inline_ov004_02159470_43(); virtual void inline_ov004_02159470_44();
    virtual void inline_ov004_02159470_45(); virtual void inline_ov004_02159470_46(); virtual void inline_ov004_02159470_47(); virtual void inline_ov004_02159470_48();
    virtual void inline_ov004_02159470_49(); virtual void inline_ov004_02159470_50(); virtual void inline_ov004_02159470_51(); virtual void inline_ov004_02159470_52();
    virtual void inline_ov004_02159470_53(); virtual void inline_ov004_02159470_54();
    virtual void inline_ov004_02159470_55(int arg0);
    int unknown_4_[7];
    void* unknown_20_;
};

// USA: func_ov004_02159470  (semantic: DispatchFlagsWithCombatant_02159470)
extern "C" ARM int func_ov004_02159470(void* self) {
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);
    char* ptr = ((char*)data_ov004_021707e0);
    unsigned char count = (unsigned char)(*(short*)(ptr + 0x3a));
    int key = 0x322;
    for (unsigned char i = 0; i < count; key++, i++) {
        signed char idVal = GetFlagByte_021570f0(i);
        GameObject* c = battle->GetPartyMemberByIndex(idVal);
        if (!c) continue;
        VObj02159470* node = (VObj02159470*)func_ov004_02156f04(self, key);
        if (!node) continue;
        node->field0x20 = c->baseStats_;
        int v = func_020dcc98(idVal);
        node->Handle(v);
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
    int unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    char unknown_c_[0xc];
    short unknown_18_;
    char unknown_1a_[6];
};

class Struct_ov004_0215951c_2 {
public:
    virtual void inline_ov004_0215951c(); virtual void inline_ov004_0215951c_2(); virtual void inline_ov004_0215951c_3(); virtual void inline_ov004_0215951c_4();
    virtual void inline_ov004_0215951c_5(); virtual void inline_ov004_0215951c_6(); virtual void inline_ov004_0215951c_7(); virtual void inline_ov004_0215951c_8();
    virtual void inline_ov004_0215951c_9(); virtual void inline_ov004_0215951c_10(); virtual void inline_ov004_0215951c_11(); virtual void inline_ov004_0215951c_12();
    virtual void inline_ov004_0215951c_13(); virtual void inline_ov004_0215951c_14(); virtual void inline_ov004_0215951c_15(); virtual void inline_ov004_0215951c_16();
    virtual void inline_ov004_0215951c_17(); virtual void inline_ov004_0215951c_18(); virtual void inline_ov004_0215951c_19(); virtual void inline_ov004_0215951c_20();
    virtual void inline_ov004_0215951c_21(); virtual void inline_ov004_0215951c_22(); virtual void inline_ov004_0215951c_23(); virtual void inline_ov004_0215951c_24();
    virtual void inline_ov004_0215951c_25(); virtual void inline_ov004_0215951c_26(); virtual void inline_ov004_0215951c_27(); virtual void inline_ov004_0215951c_28();
    virtual void inline_ov004_0215951c_29(); virtual void inline_ov004_0215951c_30(); virtual void inline_ov004_0215951c_31(); virtual void inline_ov004_0215951c_32();
    virtual void inline_ov004_0215951c_33(); virtual void inline_ov004_0215951c_34(); virtual void inline_ov004_0215951c_35(); virtual void inline_ov004_0215951c_36();
    virtual void inline_ov004_0215951c_37(); virtual void inline_ov004_0215951c_38(); virtual void inline_ov004_0215951c_39(); virtual void inline_ov004_0215951c_40();
    virtual void inline_ov004_0215951c_41(); virtual void inline_ov004_0215951c_42(); virtual void inline_ov004_0215951c_43(); virtual void inline_ov004_0215951c_44();
    virtual void inline_ov004_0215951c_45(); virtual void inline_ov004_0215951c_46(); virtual void inline_ov004_0215951c_47(); virtual void inline_ov004_0215951c_48();
    virtual void inline_ov004_0215951c_49(); virtual void inline_ov004_0215951c_50(); virtual void inline_ov004_0215951c_51(); virtual void inline_ov004_0215951c_52();
    virtual void inline_ov004_0215951c_53(); virtual void inline_ov004_0215951c_54();
    virtual void inline_ov004_0215951c_55(int arg0);
    int unknown_4_[7];
    void* unknown_20_;
};

// USA: func_ov004_0215951c
extern "C" ARM int func_ov004_0215951c(void* arg0) {
    signed char var0 = func_ov004_02157128(arg0);
    GameState* var1 = GameState::GetInstance();
    GameObject* var2 = func_0200ff1c(var1, var0);
    if (!var2) return 0;

    unsigned char* var3 = data_ov004_021707e0;
    var3[0x12] = (unsigned char)var0;

    unsigned char var4[8];
    int var5 = 8;
    unsigned char* var6 = var4;
    unsigned char* var7 = data_ov004_0216fb10;
    do {
        unsigned char var8 = *var7;
        var7++;
        *var6 = var8;
        var6++;
    } while (--var5);

    int var9 = 0x384;
    for (short var10 = 0; var10 < 8; var9++, var10++) {
        int var11 = 3;
        void* var12 = 0;
        int var13 = var4[var10];
        if (var13 != 0xff) {
            Struct_ov004_0215951c* var14 = (Struct_ov004_0215951c*)(*(char**)((char*)var2 + Enum_ov004_0215951c_336) + 0x194);
            Struct_ov004_0215951c* var15 = &var14[var13];
            if (var15) {
                if (var15->unknown_18_ > 0) {
                    unsigned int var16 = var15->unknown_8_0_;
                    if (var16 == 0xb) goto skip;
                    var12 = var15->unknown_4_;
                    if (!var12) goto skip;
                    if (*(signed char*)var12 != 0) var11 = 0xf;
                    else var12 = 0;
                }
            }
        }
    skip:
        Struct_ov004_0215951c_2* var17 = (Struct_ov004_0215951c_2*)func_ov004_02156f04(arg0, var9);
        if (var17) {
            var17->unknown_20_ = var12;
            var17->inline_ov004_0215951c_55(var11);
        }
    }

    void* var18 = func_ov004_02156f6c(arg0, 0x16);
    if (var18) {
        func_ov023_021f809c(var18, arg0);
    }
    return 0;
}

#if defined(jpn)
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

struct Struct_ov004_02159650 {
    unsigned char unknown_0_[0x12];
    signed char unknown_12_;

    signed char inline_ov004_02159650() const { return unknown_12_; }
};

struct Struct_ov004_02159650_2 { short unknown_0_; unsigned int unknown_4_; };

struct Struct_ov004_02159650_3 { int unknown_0_; char unknown_4_[4]; int unknown_8_; char unknown_c_[0xc]; short unknown_18_; };

void NameText_InitFromPartyMember(void* obj, int combatantId);

int StandardStrings_Get(int value);
extern "C" void func_020e4b34(void* obj, int stats1, int stats2, int a, int b, int c, int d, int e, int f, int g, int h, int i);
int GetHalfwordEntryFromField150(struct Field150Holder02052df8* obj, int index);

struct Struct_ov004_0216fbb0 { unsigned int unknown_0_[9]; };
extern struct Struct_ov004_0216fbb0 data_ov004_0216fbb0;

struct Struct_ov004_02159650_4 { char unknown_0_[8]; unsigned int unknown_8_0_ : 4; unsigned int unknown_8_4_ : 28; };
struct Struct_ov004_02159650_5 { unsigned int unknown_0_0_ : 18; unsigned int unknown_2_2_ : 1; unsigned int unknown_2_3_ : 13; };

// USA: func_ov004_02159650  (semantic: PopulateCombatantContextFields_02159650)
extern "C" ARM int func_ov004_02159650(void* obj) {
    int g = MessageSystem_GetInstance();
    func_02046380((void*)g);

    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));

    struct Struct_ov004_02159650_3* var2 = 0;
    struct Struct_ov004_02159650_2* var3 = 0;

    int idx = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (idx >= 0) {
        entry = (struct Entry_021570a4*)GetEntryFor_021570a4(obj, idx & 0xff);
        if (entry != 0 && node != 0) {
            elem = ((struct Element020de650_02159650*)ItemTable_Find(node, entry->field0));
        }
    }

    signed char var5 = ((Struct_ov004_02159650*)data_ov004_021707e0)->inline_ov004_02159650();
    GameObject* var6 = GameState::GetInstance()->GetPartyMemberByIndex(var5);

    if (var6 != 0) {
#if defined(jpn)
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)combatant->baseStats_);
#else
        NameText_InitFromPartyMember(data_ov004_021707e0 + 0xa0, combatantId);
        *(void**)((char*)g + 0x10) = data_ov004_021707e0 + 0xa0;

        void* p150 = *(void**)((char*)combatant + 0x150);
        int statVal = (short)(*(int*)((char*)p150 + 0x950));
        int fmt = StandardStrings_Get(statVal);
        func_020e4b34(data_ov004_021707e0 + 0xac, fmt, fmt, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(void**)((char*)g + 0x28) = data_ov004_021707e0 + 0xac;
#endif
    }

    if (var2 != 0) {
#if defined(jpn)
        char name[80];
        func_020e207c((Container020e0310*)(data_ov004_021707e0 + 0x8c), name, elem->field18);
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        int var11 = ((int)func_020e5294(data_ov004_021707e0 + 0x8c, var2->unknown_18_));
        *(int*)((char*)var0 + 0x18) = var11;
#endif
    }

    if (combatant != 0 && elem != 0 && elem->field0 != 0) {
        struct Ctx_02159650* ctxElem = (struct Ctx_02159650*)elem;
        unsigned int nibble = ctxElem->idx4;
        int inRange = nibble <= 7;
        if (inRange) {
            struct Table9x_02159650 table = data_ov004_0216fbb0;
            int half = GetHalfwordEntryFromField150((struct Field150Holder02052df8*)combatant, table.v[nibble]);
            if (half > 0) {
                struct Element020de650_02159650* elem2 = ((struct Element020de650_02159650*)ItemTable_Find(node, half));
                if (elem2 != 0 && ((struct Field8Bits_02159650*)&elem2->field8)->bit18 != 0) {
#if defined(jpn)
                    MessageSystem_SetStringArgument((Obj02046574*)g, 2, *(char**)((char*)elem2 + 4));
#else
                    int var18 = ((int)func_020e5294(data_ov004_021707e0 + 0x8c, var16));
                    *(int*)((char*)var0 + 0x18) = var18;
#endif
                }
            }
        }
    }

    if (var3 != 0) {
        func_020465c0((struct Struct_020465c0*)var0, 0, data_ov004_021707e0[0x11] * (var3->unknown_4_ >> 7));
    }

    func_020465c0((struct Struct_020465c0*)var0, 1, data_ov004_021707e0[0x11]);
    return 0;
}
extern "C" void func_ov023_021f66bc(void* arg0, int arg1, void* arg2);
extern "C" int func_ov004_02159384(void* arg0);

struct Struct_ov004_02159888 { short unknown_0_; short unknown_2_; unsigned int unknown_4_0_ : 7; };
struct Struct_ov004_02159888_2 { char unknown_0_[8]; unsigned int unknown_8_0_ : 4; };

// USA: func_ov004_02159888
extern "C" ARM int func_ov004_02159888(void* arg0) {
    int var0 = func_ov004_02156e2c(arg0, 0x5b);
    if (var0 < 0) return 0;

    Struct_ov004_02159888* var1 = (Struct_ov004_02159888*)func_ov004_021570a4(arg0, (unsigned char)var0);
    if (!var1) return 0;

    if (data_ov004_021707e0[0x11] >= var1->unknown_4_0_) return 0;

    void* ptr2a04 = GameState_GetParty(GameState::GetInstance());
    unsigned int cap = *(unsigned int*)((char*)entry + 4) >> 7;
    if (*(unsigned int*)((char*)ptr2a04 + 0xf6c) < (data_ov004_021707e0[0x11] + 1) * cap) return 0;

    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    if (!node) return 0;

    struct Element020de650_02159888* elem = ((struct Element020de650_02159888*)ItemTable_Find(node, *(short*)(data_ov004_021707e0 + 0xe)));
    if (!elem) return 0;

    unsigned int var6 = ((unsigned int)func_ov004_0215799c(var2, var1->unknown_0_, (int)var5->unknown_8_0_, *(short*)(data_ov004_021707e0 + 0x3a)));
    if (data_ov004_021707e0[0x11] >= var6) return 0;

    data_ov004_021707e0[0x11] = data_ov004_021707e0[0x11] + 1;
    func_ov023_021f66bc(arg0, 0x25b, (void*)1);
    func_ov004_02159384(arg0);
    return 0;
}

// USA: func_ov004_021599b4
extern "C" ARM int func_ov004_021599b4(void* arg0) {
    int var0 = func_ov004_02156e2c(arg0, 0x5b);
    if (var0 < 0) {
        return 0;
    }
    void* var1 = func_ov004_021570a4(arg0, (unsigned char)var0);
    if (!var1) {
        return 0;
    }
    unsigned char* var2 = data_ov004_021707e0;
    unsigned char var3 = var2[0x11];
    if (var3 <= 1) {
        return 0;
    }
    var2[0x11] = var3 - 1;
    func_ov023_021f66bc(arg0, 0x25c, (void*)1);
    func_ov004_02159384(arg0);
    return 0;
}

#if defined(jpn)
#define data_ov004_0216fb50 data_ov004_021702d8
#define func_ov004_02159bcc func_ov004_0215ac28
#endif

struct Struct_ov004_02159a2c { char unknown_0_[0x32]; short unknown_32_[4]; short unknown_3a_; };

struct Struct_ov004_0216fb50 { int unknown_0_[4]; };
extern Struct_ov004_0216fb50 data_ov004_0216fb50;
struct Struct_ov004_02159a2c_2 { char unknown_0_[8]; unsigned int unknown_8_0_ : 4; };
extern "C" int func_020dd4c4(int, struct Struct_020dd4c4_3*);
extern "C" int func_ov004_02159bcc(void* arg0);

// USA: func_ov004_02159a2c
extern "C" ARM int func_ov004_02159a2c(void* arg0) {
    int var0;
    GameState::GetInstance();
    int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (key < 0) return 0;
    void* entry = GetEntryFor_021570a4(obj, key & 0xff);
    if (!entry) return 0;
    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    if (!node) return 0;
    struct Element020de650_02159a2c* elem = ((struct Element020de650_02159a2c*)ItemTable_Find(node, *(short*)entry));
    if (!elem) return 0;

    int var5 = var4->unknown_8_0_ <= 7;
    if (var5) {
        Struct_ov004_0216fb50 var6 = data_ov004_0216fb50;
        Struct_ov004_02159a2c* var7 = ((Struct_ov004_02159a2c*)data_ov004_021707e0);
        int var8 = var7->unknown_3a_;
        for (var0 = 0; var0 < var8; var0++) {
            var6.unknown_0_[var0] = var7->unknown_32_[var0];
        }
        int var9;
        for (var9 = 0; var9 < var8; var9++) {
            if (!func_020dd4c4((signed char)var6.unknown_0_[var9], (Struct_020dd4c4_3*)var4)) break;
        }
        if (var9 == var8) {
            func_ov004_02159bcc(arg0);
        } else {
            func_ov011_021848a0(arg0, 0x38b);
        }
    } else {
        func_ov011_021848a0(arg0, 0x2384);
    }
    return 0;
}

#undef data_ov004_0216fb50
#undef func_ov004_02159bcc

// USA: func_ov004_02159b74
extern "C" ARM int func_ov004_02159b74(void* arg0) {
    func_ov011_021848a0(arg0, 0x2368);
    return 0;
}

// USA: func_ov004_02159b8c
ARM int EnqueueEventFromFlagByte_02159b8c(void* obj) {
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

struct KeyedStackContext {
    SafeAllocator allocator;
    unsigned char state14[0x18];
    ItemTable* container;
    void* field30;
    int field34;
};
void* ItemTable_Construct(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
extern "C" int func_0207d134(struct Obj0207d134*, short, int);

// USA: func_ov004_02159bcc
extern "C" ARM int func_ov004_02159bcc(void* arg0) {
#if !defined(jpn)
    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    if (node == NULL) return 0;
    struct Element020de650* elem = ItemTable_Find(node, *(short*)(((char*)data_ov004_021707e0) + 0xe));
    if (elem == NULL) return 0;
    int val = ((int)CallFunc020e52a0_020e5294(((char*)data_ov004_021707e0) + 0x8c, *(short*)((char*)elem + 0x18)));
    *(int*)((char*)(int)MessageSystem_GetInstance() + 0x18) = val;
    ((char*)data_ov004_021707e0)[0x12] = (char)0xff;
#endif
    if (*(unsigned char*)(((char*)data_ov004_021707e0) + 0x47) == 0) {
        ItemTable* node2 = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
        if (node2 != NULL) {
            KeyedStackContext context;
            context.allocator.ResetAllocatorPointer();
            ItemTable_Construct(context.state14);
            InitStruct0207cbe8((char*)&context);
            InitStruct0207cbe8((char*)&context);
            context.container = node2;
            func_0207d134((Obj0207d134*)(&context), *(short*)(((char*)data_ov004_021707e0) + 0xe), *(signed char*)(((char*)data_ov004_021707e0) + 0x11));
            InitStruct0207cc0c((char*)&context);
        }
        func_ov011_021848a0(arg0, 0x38c);
        ((char*)data_ov004_021707e0)[R(0xa9, 0x9d)] = 0;
        return 0;
    }
    func_ov011_021848a0(arg0, 0x2379);
    return 0;
}

#undef func_ov004_02159bcc

extern "C" void func_020dd7ac(void* arg0);
extern "C" void func_020ddaf4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" void func_ov023_021fbdf4(struct Struct_ov004_02158bd4* arg0, int arg1);

typedef void (*Type_01ff8b48_11)(void*, int);
struct Struct_ov004_02159ce0 { char unknown_0_[0xe0]; Type_01ff8b48_11 unknown_e0_; };
struct Struct_ov004_02159ce0_2 { Struct_ov004_02159ce0* unknown_0_; };

typedef void (*Type_01ff8b48_12)(void*, int);
struct Struct_ov004_02159ce0_3 { char unknown_0_[0xd8]; Type_01ff8b48_12 unknown_d8_; };
struct Struct_ov004_02159ce0_4 { Struct_ov004_02159ce0_3* unknown_0_; };

struct Struct_ov004_02159ce0_5 { char unknown_0_[0x20]; int unknown_20_; };
struct Struct_ov004_02159ce0_6 { char unknown_0_[0x38]; short unknown_38_; };

struct Struct_ov004_02159ce0_7 { unsigned int unknown_0_0_ : 4; unsigned int unknown_0_4_ : 28; };

// USA: func_ov004_02159ce0
extern "C" ARM int func_ov004_02159ce0(void* a) {
    int idxVal = func_ov004_02157128(a);
    ItemTable* node = (ItemTable*)((void*)func_ov004_02156fd4(a, 5));
    if (!node) return 0;

    short key = *(short*)(data_ov004_021707e0 + 0xe);
    Element020de650* elem = ItemTable_Find(node, key);
    if (!elem) return 0;

    Struct_020dd7ac var4;
    func_020dd7ac(&var4);
    int var5 = 1;
    unsigned int var6 = ((Struct_ov004_02159ce0_7*)((char*)var3 + 8))->unknown_0_0_;

    unsigned short var7, var8;
    if (var6 == 0) {
        func_020ddaf4((int)&var4, var0, (int)var3, 0, (int)&var7, (int)&var8);
    } else {
        func_020ddaf4((int)&var4, var0, (int)var3, var5, (int)&var7, (int)&var8);
        var5 = 3;
    }

    Struct_ov004_02159ce0_5* var9 = (Struct_ov004_02159ce0_5*)func_ov004_02156f04(arg0, 0x3e8);
    if (var9) var9->unknown_20_ = *(int*)((char*)var3 + 4);

    Struct_ov004_02159ce0_6* var10 = (Struct_ov004_02159ce0_6*)func_ov004_02156f04(arg0, 0x3ea);
    if (var10) var10->unknown_38_ = (short)(var5 + 0xb);

    if (func_020dd4c4((int)((void*)var0), (Struct_020dd4c4_3*)var3) != 0) {
        func_ov023_021f65d4(arg0, 0x3eb, 8);
        func_ov023_021f65d4(arg0, 0x3ec, 8);
        func_ov023_021f65d4(arg0, 0x3ed, 8);
        func_ov023_021f6600(arg0, 0x3ee, 8);
    } else {
        Struct_ov004_02159ce0_2* var11 = (Struct_ov004_02159ce0_2*)func_ov004_02156f38(arg0, 0x3eb);
        if (var11) var11->unknown_0_->unknown_e0_(var11, var7);

        Struct_ov004_02159ce0_2* var12 = (Struct_ov004_02159ce0_2*)func_ov004_02156f38(arg0, 0x3ed);
        if (var12) var12->unknown_0_->unknown_e0_(var12, var8);

        Struct_ov004_02159ce0_4* var13 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), 0x3eb);
        if (var13) var13->unknown_0_->unknown_d8_(var13, 0xf);

        if (var7 == var8) {
            Struct_ov004_02159ce0_4* var14 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), 0x3ed);
            if (var14) var14->unknown_0_->unknown_d8_(var14, 0xf);
        } else if (var7 < var8) {
            Struct_ov004_02159ce0_4* var15 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), 0x3ed);
            if (var15) var15->unknown_0_->unknown_d8_(var15, 0x5);
        } else {
            Struct_ov004_02159ce0_4* var16 = (Struct_ov004_02159ce0_4*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), 0x3ed);
            if (var16) var16->unknown_0_->unknown_d8_(var16, 0x9);
        }

        func_ov023_021f6600(arg0, 0x3eb, 8);
        func_ov023_021f6600(arg0, 0x3ec, 8);
        func_ov023_021f6600(arg0, 0x3ed, 8);
        func_ov023_021f65d4(arg0, 0x3ee, 8);
    }

    Struct_ov004_02159ce0_2* var17 = (Struct_ov004_02159ce0_2*)func_ov004_02156f6c(arg0, 0x17);
    if (var17) func_ov023_021f809c(var17, arg0);

    void* var18 = func_ov004_02157054(arg0, 7);
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
extern "C" ARM int func_ov004_02159fb0(int arg0) {
    func_ov004_0215951c((void*)arg0);
    func_ov004_02159ce0((void*)arg0);
    return 0;
}

struct Struct_ov004_02159fcc { unsigned int unknown_0_0_ : 27; unsigned int unknown_3_3_ : 1; unsigned int unknown_3_4_ : 1; unsigned int unknown_3_5_ : 1; unsigned int unknown_3_6_ : 2; };
struct Struct_ov000_0215767c_10 { int unknown_0_; Struct_ov004_02159fcc unknown_4_; };
struct Struct_ov000_0215767c_8 { Struct_ov000_0215767c_10* unknown_0_; void* unknown_4_; unsigned int unknown_8_0_ : 4; unsigned int unknown_8_4_ : 14; unsigned int unknown_a_2_ : 1; unsigned int unknown_a_3_ : 13; char unknown_c_[12]; short unknown_18_; char unknown_1a_[6]; };
struct Struct_ov004_02159fcc_2 { char unknown_0_[0x194]; Struct_ov000_0215767c_8 unknown_194_[24]; char unknown_494_[8]; unsigned char unknown_49c_0_ : 1; unsigned char unknown_49c_1_ : 7; };
#if defined(jpn)
enum { Enum_ov004_021570f0_336_2 = 0x144, Enum_ov004_021570f0_16 = 0x1c };
#else
enum { Enum_ov004_021570f0_336_2 = 0x150, Enum_ov004_021570f0_16 = 0x10 };
#endif
struct Struct_ov004_02159fcc_3 { char unknown_0_[Enum_ov004_021570f0_336_2]; Struct_ov004_02159fcc_2* unknown_150_; };
struct Struct_ov004_02159fcc_4 { char unknown_0_[0xe]; short unknown_e_; char unknown_10_[0x2c]; short unknown_3c_; char unknown_3e_[0x4e]; char unknown_8c_[Enum_ov004_021570f0_16]; unsigned char unknown_9c_; };
struct Struct_ov004_0216fbf8 { int unknown_0_[9]; };
struct Struct_ov004_0216fb18 { unsigned char unknown_0_[8]; };
struct Struct_ov004_02159fcc_5 { char unknown_0_[0x18]; void* unknown_18_; };
extern Struct_ov004_0216fbf8 data_ov004_0216fbf8;
extern Struct_ov004_0216fb18 data_ov004_0216fb18;
extern "C" int func_ov004_02159650(void*);
#if defined(jpn)
struct Container020e0310;
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

extern "C" int func_ov004_02157a28(void*, int);

static inline Struct_ov004_02159fcc_2* inline_ov004_02159fcc(Struct_ov004_02159fcc_3* arg0) { return arg0->unknown_150_; }

// USA: func_ov004_02159fcc
extern "C" ARM int func_ov004_02159fcc(void* arg0) {
    int var0 = func_ov004_02157128(arg0);
    ((Struct_ov004_02159fcc_4*)data_ov004_021707e0)->unknown_3c_ = var0;
    func_0202ae18();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), flag);
    if (!combatant) return 0;
    ItemTable* container = ((ItemTable*)func_ov004_02156fd4(obj, 5));
    if (!container) return 0;
    ActionEntry* entry = ((ActionEntry*)ItemTable_Find(container, ((BattleActionState*)data_ov004_021707e0)->key));
    if (!entry) return 0;
    unsigned int type = entry->type;
    if (func_020dd4c4(flag, (Entry020dd4c4*)entry)) {
        func_ov011_021848a0(obj, 0x392);
        return 0;
    }
    ActionKeys keys = data_ov004_0216fbf8;
    int key = GetHalfwordEntryFromField150((Field150Holder02052df8*)combatant, keys.keys[entry->type]);
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
            var8->unknown_18_ = func_020e5294(((Struct_ov004_02159fcc_4*)data_ov004_021707e0)->unknown_8c_, var7->unknown_18_);
#endif
            func_ov011_021848a0(arg0, 0x23b6);
            return 0;
        }
    }
    if (var4 == 7 && func_02052df8((Struct_02052df8*)var1, 9) == 0x4680) {
        int var10;
        if (!var1) var10 = 0;
        else {
            Struct_ov004_0216fb18 var11 = data_ov004_0216fb18;
            unsigned char var12[2];
            for (unsigned char var13 = 0; var13 < 8; var13++) {
                unsigned char var14 = var11.unknown_0_[var13];
                if (var14 == 0xff) break;
                Struct_ov000_0215767c_8* var15;
                Struct_ov004_02159fcc_2* var16 = inline_ov004_02159fcc((Struct_ov004_02159fcc_3*)var1);
                var15 = &var16->unknown_194_[var14];
                if (var15 && var15->unknown_18_ >= 0) {
                    Struct_ov000_0215767c_10* var17 = var15->unknown_0_;
                    if (var17 && !var17->unknown_4_.unknown_3_5_) {
                        unsigned int var18 = var17->unknown_4_.unknown_3_3_ ? 1 : 0;
                        var12[0] = var18;
                        var12[1] = var17->unknown_4_.unknown_3_4_ ? 1 : 0;
                        if (!var12[var16->unknown_49c_0_]) {
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
            func_ov011_021848a0(arg0, 0x23b5);
            return 0;
        }
    }
    Struct_ov004_02158bd4* var19 = ((Struct_ov004_02158bd4*)func_ov004_02157054(arg0, 7));
    if (var19) {
        func_ov023_021fbdf4(var19, -1);
        ((Struct_ov004_02159fcc_4*)data_ov004_021707e0)->unknown_9c_ = 1;
    }
    return func_ov004_02157a28(arg0, 0);
}
extern "C" void* func_ov004_0215a2f8(void*);
extern "C" void func_ov023_021f65d4(void* arg0, int arg1, int arg2);

// USA: func_ov004_0215a294  (semantic: UpdateThenResetAndFlag_0215a294)
extern "C" ARM int func_ov004_0215a294(void* obj) {
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);
    unsigned char* fieldPtr __attribute__((aligned(4))) = data_ov004_021707e0;
    unsigned char byteVal = (unsigned char)*(short*)(fieldPtr + 0x3a);
    short base0x396 = 0x396;
    short f32 = *(short*)(fieldPtr + 0x32);
    *(short*)(fieldPtr + 0x3c) = f32;
    func_ov011_021848a0(obj, base0x396 + byteVal);
    ResetCombatantFields_0215a2f8(data_ov004_021707e0);
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}

// USA: func_ov004_0215a2f8
extern "C" ARM void* func_ov004_0215a2f8(void* arg0) {
	*(short*)((char*)arg0 + 0x6c) = -1;
	*(char*)((char*)arg0 + 0x6e) = 0;
	*(char*)((char*)arg0 + 0x6f) = 0;
	*(char*)((char*)arg0 + 0x70) = -1;
	*(int*)((char*)arg0 + 0x74) = -1;
	*(int*)((char*)arg0 + 0x78) = 0;
	return arg0;
}

class Struct_ov004_0215a31c {
public:
    virtual void inline_ov004_0215a31c(); virtual void inline_ov004_0215a31c_2(); virtual void inline_ov004_0215a31c_3(); virtual void inline_ov004_0215a31c_4();
    virtual void inline_ov004_0215a31c_5(); virtual void inline_ov004_0215a31c_6(); virtual void inline_ov004_0215a31c_7(); virtual void inline_ov004_0215a31c_8();
    virtual void inline_ov004_0215a31c_9(); virtual void inline_ov004_0215a31c_10(); virtual void inline_ov004_0215a31c_11(); virtual void inline_ov004_0215a31c_12();
    virtual void inline_ov004_0215a31c_13(); virtual void inline_ov004_0215a31c_14(); virtual void inline_ov004_0215a31c_15(); virtual void inline_ov004_0215a31c_16();
    virtual void inline_ov004_0215a31c_17(); virtual void inline_ov004_0215a31c_18(); virtual void inline_ov004_0215a31c_19(); virtual void inline_ov004_0215a31c_20();
    virtual void inline_ov004_0215a31c_21(); virtual void inline_ov004_0215a31c_22(); virtual void inline_ov004_0215a31c_23(); virtual void inline_ov004_0215a31c_24();
    virtual void inline_ov004_0215a31c_25(); virtual void inline_ov004_0215a31c_26(); virtual void inline_ov004_0215a31c_27(); virtual void inline_ov004_0215a31c_28();
    virtual void inline_ov004_0215a31c_29(); virtual void inline_ov004_0215a31c_30(); virtual void inline_ov004_0215a31c_31(); virtual void inline_ov004_0215a31c_32();
    virtual void inline_ov004_0215a31c_33(); virtual void inline_ov004_0215a31c_34(); virtual void inline_ov004_0215a31c_35(); virtual void inline_ov004_0215a31c_36();
    virtual void inline_ov004_0215a31c_37(); virtual void inline_ov004_0215a31c_38(); virtual void inline_ov004_0215a31c_39(); virtual void inline_ov004_0215a31c_40();
    virtual void inline_ov004_0215a31c_41(); virtual void inline_ov004_0215a31c_42(); virtual void inline_ov004_0215a31c_43(); virtual void inline_ov004_0215a31c_44();
    virtual void inline_ov004_0215a31c_45(); virtual void inline_ov004_0215a31c_46(); virtual void inline_ov004_0215a31c_47(); virtual void inline_ov004_0215a31c_48();
    virtual void inline_ov004_0215a31c_49(); virtual void inline_ov004_0215a31c_50(); virtual void inline_ov004_0215a31c_51(); virtual void inline_ov004_0215a31c_52();
    virtual void inline_ov004_0215a31c_53(); virtual void inline_ov004_0215a31c_54();
    virtual void inline_ov004_0215a31c_55(int arg0);
    virtual void inline_ov004_0215a31c_56();
    virtual void inline_ov004_0215a31c_57(int arg0);
    char unknown_4_[8];
    unsigned char unknown_c_;
    char unknown_d_[0x13];
    void* unknown_20_;
};

struct Struct_ov004_0215a31c_2 {
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
};

struct Struct_ov004_0215a31c_3 {
    char unknown_0_[4];
    void* unknown_4_;
};
struct Struct_020a0b8c;
extern "C" int func_020a0b8c(Struct_020a0b8c* arg0);
extern "C" int func_02053c6c(unsigned char*);
extern "C" int func_020dcc98(signed char arg0);
typedef int (*Type_ov004_0215a31c)(Struct_ov004_0215a31c_2*, unsigned short, unsigned int, unsigned int);
extern "C" void func_ov023_021f9ba8(Struct_ov004_0215a31c_2* arg0, int arg1);
extern "C" void* func_ov004_02157088(void* arg0, int arg1);
extern "C" void func_ov023_021dcae0(struct Struct_ov003_02178910*, int);

// USA: func_ov004_0215a31c
extern "C" ARM int func_ov004_0215a31c(void* obj) {
    signed char flag = func_ov004_02157128(obj);
    ItemTable* items = ((ItemTable*)func_ov004_02156fd4(obj, 5));
    TableA68* table = ((TableA68*)DispatchAdjustmentIfType4_02157018(obj, 3));
    short* keys;
    Grid021f9b30_0215a31c* grid = ((Grid021f9b30_0215a31c*)func_ov004_02156ed0(obj, 0x63));
    int i;
    int slot;

    if (flag == -1) {
        unsigned char* list = (unsigned char*)GameState_GetParty(GameState::GetInstance());
        if (!list) return 0;
        keys = (short*)(list + 0xc);
        signed char* counts = (signed char*)(list + 0x13c);
        Node0215a31c* node = ((Node0215a31c*)func_ov004_02156f04(obj, 0x454));
        if (node) {
            node->data = FindEntryByKey_02072a68(table, 0xb);
        }
        short var10 = var4->unknown_5c_;
        short var11 = var4->unknown_5e_;
        if (!(var10 > 0 && var11 > 0)) {
            var10 = 0;
            var11 = (func_020a0b8c((Struct_020a0b8c*)var7) - 1) / 8 + 1;
            if (var11 < 1) var11 = 1;
            var4->unknown_5c_ = 0;
            var4->unknown_5e_ = var11;
        }
        var3 += var10 * 8;
        var9 = ((Struct_ov004_0215a31c*)func_ov004_02156f04(arg0, 0x458));
        if (var9) var9->unknown_c_ &= ~8;
        ((Struct_ov004_0215a31c*)func_ov004_02156f38(arg0, 0x456))->inline_ov004_0215a31c_57(var10 + 1);
        ((Struct_ov004_0215a31c*)func_ov004_02156f38(arg0, 0x457))->inline_ov004_0215a31c_57(var11);
        func_ov023_021f6600(arg0, 0x456, 8);
        func_ov023_021f6600(arg0, 0x457, 8);
        func_ov023_021f6600(arg0, 0x469, 8);
        func_ov023_021f6600(arg0, 0x46a, 8);
        for (var5 = 0; var5 < 8; var5++) {
            func_ov023_021f6600(arg0, var5 + 0x459, 8);
            func_ov023_021f6600(arg0, var5 + 0x461, 8);
            ((Struct_ov004_0215a31c*)func_ov004_02156f38(arg0, var5 + 0x461))->inline_ov004_0215a31c_57(var8[var5]);
        }
    } else {
        GameObject* var12 = func_0200ff1c(GameState::GetInstance(), var0);
        if (!var12) return 0;
        var3 = (short*)(((unsigned char*)func_02053c6c((unsigned char*)var12)) + 0x454);
        Struct_ov004_0215a31c* var13 = ((Struct_ov004_0215a31c*)func_ov004_02156f04(arg0, 0x454));
        if (var13) {
            var13->unknown_20_ = var12->baseStats_;
            var13->inline_ov004_0215a31c_55(func_020dcc98(var0));
        }
        var13 = ((Struct_ov004_0215a31c*)func_ov004_02156f04(arg0, 0x458));
        if (var13) var13->unknown_c_ |= 8;
        func_ov023_021f65d4(arg0, 0x456, 8);
        func_ov023_021f65d4(arg0, 0x457, 8);
        func_ov023_021f65d4(arg0, 0x469, 8);
        func_ov023_021f65d4(arg0, 0x46a, 8);
        for (var6 = 0; var6 < 8; var6++) {
            func_ov023_021f65d4(arg0, var6 + 0x459, 8);
            func_ov023_021f65d4(arg0, var6 + 0x461, 8);
        }
    }

    for (slot = 0; slot < 8; slot++) {
        Element0215a31c* elem = ((Element0215a31c*)ItemTable_Find(items, keys[slot]));
        Node0215a31c* node = ((Node0215a31c*)func_ov004_02156f04(obj, slot + 0x44c));
        if (!elem) {
            node->flags |= 8;
            func_ov023_021f65d4(obj, slot + 0x459, 8);
            func_ov023_021f65d4(obj, slot + 0x461, 8);
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, 0, (unsigned short)slot, 0);
        } else {
            void* var16 = var14->unknown_4_ ? var14->unknown_4_ : 0;
            if (var15) {
                var15->unknown_c_ &= ~8;
                var15->unknown_20_ = var16;
                ((Type_ov004_0215a31c)func_ov023_021f9b30)(var4, (unsigned short)(var6 + 0x44c), (unsigned short)var6, 0);
            }
        }
    }
    func_ov023_021f9ba8(var4, 0);
    void* var17 = func_ov004_02156f6c(arg0, 0x17);
    if (var17) func_ov023_021f809c(var17, arg0);
    void* var18 = func_ov004_02157088(arg0, 7);
    if (var18) func_ov023_021dcae0((Struct_ov003_02178910*)var18, -1);
    return 0;
}
extern "C" int func_ov004_021571d8(int arg0);
extern "C" void* func_0207c5f8(unsigned char*, unsigned int);
extern "C" void* func_0207c60c(void*, unsigned int);
extern "C" void func_ov023_021f65d4(void* arg0, int arg1, int arg2);

struct Struct_ov004_0215a738 {
    char unknown_0_[0x20];
    short* unknown_20_;
    unsigned short unknown_24_;
    unsigned short unknown_26_;
    char unknown_28_[0x34];
    short unknown_5c_;
    short unknown_5e_;
};

struct Struct_ov004_0215a738_2 {
    char unknown_0_[4];
    int unknown_4_;
};

struct Struct_ov004_0215a738_3 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    char unknown_d_[0x13];
    int unknown_20_;
};

class Struct_ov004_0215a738_4 {
public:
    virtual void inline_ov004_0215a738(); virtual void inline_ov004_0215a738_2(); virtual void inline_ov004_0215a738_3(); virtual void inline_ov004_0215a738_4();
    virtual void inline_ov004_0215a738_5(); virtual void inline_ov004_0215a738_6(); virtual void inline_ov004_0215a738_7(); virtual void inline_ov004_0215a738_8();
    virtual void inline_ov004_0215a738_9(); virtual void inline_ov004_0215a738_10(); virtual void inline_ov004_0215a738_11(); virtual void inline_ov004_0215a738_12();
    virtual void inline_ov004_0215a738_13(); virtual void inline_ov004_0215a738_14(); virtual void inline_ov004_0215a738_15(); virtual void inline_ov004_0215a738_16();
    virtual void inline_ov004_0215a738_17(); virtual void inline_ov004_0215a738_18(); virtual void inline_ov004_0215a738_19(); virtual void inline_ov004_0215a738_20();
    virtual void inline_ov004_0215a738_21(); virtual void inline_ov004_0215a738_22(); virtual void inline_ov004_0215a738_23(); virtual void inline_ov004_0215a738_24();
    virtual void inline_ov004_0215a738_25(); virtual void inline_ov004_0215a738_26(); virtual void inline_ov004_0215a738_27(); virtual void inline_ov004_0215a738_28();
    virtual void inline_ov004_0215a738_29(); virtual void inline_ov004_0215a738_30(); virtual void inline_ov004_0215a738_31(); virtual void inline_ov004_0215a738_32();
    virtual void inline_ov004_0215a738_33(); virtual void inline_ov004_0215a738_34(); virtual void inline_ov004_0215a738_35(); virtual void inline_ov004_0215a738_36();
    virtual void inline_ov004_0215a738_37(); virtual void inline_ov004_0215a738_38(); virtual void inline_ov004_0215a738_39(); virtual void inline_ov004_0215a738_40();
    virtual void inline_ov004_0215a738_41(); virtual void inline_ov004_0215a738_42(); virtual void inline_ov004_0215a738_43(); virtual void inline_ov004_0215a738_44();
    virtual void inline_ov004_0215a738_45(); virtual void inline_ov004_0215a738_46(); virtual void inline_ov004_0215a738_47(); virtual void inline_ov004_0215a738_48();
    virtual void inline_ov004_0215a738_49(); virtual void inline_ov004_0215a738_50(); virtual void inline_ov004_0215a738_51(); virtual void inline_ov004_0215a738_52();
    virtual void inline_ov004_0215a738_53(); virtual void inline_ov004_0215a738_54(); virtual void inline_ov004_0215a738_55(); virtual void inline_ov004_0215a738_56();
    virtual void inline_ov004_0215a738_57(int arg0);
};

// USA: func_ov004_0215a738
extern "C" ARM int func_ov004_0215a738(void* obj) {
    short base;
    short saved;
    GameState* bs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GameState_GetParty(bs);
    if (!p) return 0;
    Grid021f9b30_0215a738* grid = ((Grid021f9b30_0215a738*)func_ov004_02156ed0(obj, 0x63));
    base = grid->field5c;
    saved = grid->field5e;
    short* keys;
    signed char* bytes;
    if (HasFlag101_021571d8((int)obj)) {
        int idx = DispatchNodeIfType7_02156e2c(obj, 0x65);
        if (idx < 0) return 0;
        keys = (short*)GetPointerFromArray0xbd0_0207c5f8(p + 0x1d4, *(data_ov004_021707e0 + idx + 0x7c));
        bytes = (signed char*)GetPointerAt0xbf0_0207c60c(p + 0x1d4, *(data_ov004_021707e0 + idx + 0x7c));
    } else {
        if (((int)func_ov004_02157128(arg0)) >= 0) return 0;
        var5 = (short*)(var3 + 0xc);
        var6 = (signed char*)(var3 + 0x13c);
    }
    ItemTable* node = (ItemTable*)((void*)func_ov004_02156fd4(obj, 5));
    for (int i = 0; i < 8; i++) {
        int k = i + base * 8;
        Element020de650_0215a738* elem = ((Element020de650_0215a738*)ItemTable_Find(node, keys[k]));
        Slot02156f04* slot = ((Slot02156f04*)func_ov004_02156f04(obj, i + 0x44c));
        if (elem == 0) {
            slot->flags |= 8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((Grid021f9b30_0215a31c*)grid, 0, (unsigned short)i, (unsigned short)0);
            func_ov023_021f65d4(obj, i + 0x459, 8);
            func_ov023_021f65d4(obj, i + 0x461, 8);
        } else {
            int var13 = var11->unknown_4_ ? var11->unknown_4_ : 0;
            if (var12) {
                var12->unknown_c_ &= ~8;
                var12->unknown_20_ = var13;
                ((Type_ov004_0215a31c)func_ov023_021f9b30)((Struct_ov004_0215a31c_2*)var4, var9 + 0x44c, (unsigned short)var9, (unsigned short)0);
                func_ov023_021f6600(arg0, var9 + 0x459, 8);
                func_ov023_021f6600(arg0, var9 + 0x461, 8);
                ((Struct_ov004_0215a738_4*)func_ov004_02156f38(arg0, var9 + 0x461))->inline_ov004_0215a738_57(var6[var10]);
            }
        }
    }
    ((Struct_ov004_0215a738_4*)func_ov004_02156f38(arg0, 0x456))->inline_ov004_0215a738_57(var0 + 1);
    ((Struct_ov004_0215a738_4*)func_ov004_02156f38(arg0, 0x457))->inline_ov004_0215a738_57(var1);
    func_ov023_021f6600(arg0, 0x456, 8);
    func_ov023_021f6600(arg0, 0x457, 8);
    func_ov023_021f6600(arg0, 0x469, 8);
    func_ov023_021f6600(arg0, 0x46a, 8);
    void* var14 = func_ov004_02156f6c(arg0, 0x17);
    if (var14) func_ov023_021f809c(var14, arg0);
    void* var15 = (void*)func_ov004_02157088(arg0, 7);
    int var16 = func_ov004_02156e2c(arg0, 0x63);
    if (var15) func_ov023_021dcae0((Struct_ov003_02178910*)var15, var5[var16 + var0 * 8]);
    return 0;
}
extern "C" struct GameObject* func_0200ff1c(struct GameState*, int);
struct Struct_0207d300;
extern "C" int func_02083960(struct Struct_0207d300* arg0);
extern "C" short func_0207c638(void*, unsigned int);

// USA: func_ov004_0215aa10
extern "C" ARM int func_ov004_0215aa10(void* obj) {
    GameState* bs = GameState::GetInstance();
    int result;
    if (HasFlag101_021571d8((int)obj)) {
        int idx = DispatchNodeIfType7_02156e2c(obj, 0x65);
        if (idx < 0) return 0;
        void* p = GameState_GetParty(bs);
        if (!p) return 0;
        unsigned char key = *(data_ov004_021707e0 + idx + 0x7c);
        result = CountPositiveEntries0207c638((char*)p + 0x1d4, key);
        *(int*)(data_ov004_021707e0 + 0x74) = key;
    } else {
        int val = ((int)func_ov004_02157128(obj));
        if (val == -1) {
            void* p = GameState_GetParty(bs);
            if (!p) return 0;
            result = CountNonZeroValues020a0b8c((struct S_a0b8c*)p);
        } else {
            GameObject* var7 = func_0200ff1c(var0, var5);
            if (!var7) return 0;
            int var8 = func_02053c6c((unsigned char*)var7);
            var1 = func_02083960((struct Struct_0207d300*)var8);
        }
    }
    if (var1 > 0) {
        func_ov011_021848a0(arg0, 0x6a);
    }
    return 0;
}

struct Struct_ov004_0215aaf0 { char unknown_0_[0x5c]; short unknown_5c_; };

struct Struct_ov004_0215aaf0_2 { unsigned int unknown_0_0_ : 12; unsigned int unknown_1_4_ : 2; unsigned int unknown_1_6_ : 18; };
struct Struct_ov004_0215aaf0_3 { char unknown_0_[8]; Struct_ov004_0215aaf0_2 unknown_8_; };

extern "C" int func_020de194(void* arg0);

// USA: func_ov004_0215aaf0
extern "C" ARM int func_ov004_0215aaf0(void* obj) {
    GameState* bs = GameState::GetInstance();
    struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
    unsigned char* ptr2a04 = (unsigned char*)GameState_GetParty(bs);
    if (!ptr2a04) return 0;

    int var3 = func_ov004_02156e2c(arg0, 0x63);
    if (var3 < 0) return 0;

    Struct_ov004_0215aaf0* var4 = ((Struct_ov004_0215aaf0*)func_ov004_02156ed0(arg0, 0x63));
    int var5 = var3 + var4->unknown_5c_ * 8;

    struct Struct_ov004_0215aaf0_3* var6;

    if (HasFlag101_021571d8((int)obj)) {
        unsigned char* keyArr = (unsigned char*)GetPointerFromArray0xbd0_0207c5f8(ptr2a04 + 0x1d4, *(unsigned int*)(data_ov004_021707e0 + 0x74));
        unsigned char* byteArr = (unsigned char*)GetPointerAt0xbf0_0207c60c(ptr2a04 + 0x1d4, *(unsigned int*)(data_ov004_021707e0 + 0x74));
        elem = ((struct Element020de650_0215aaf0*)ItemTable_Find(node, ((short*)keyArr)[slot]));
        if (elem->bits.field2 == 0) {
            func_ov011_021848a0(obj, 0x3a1);
            return 0;
        }
        *(short*)(data_ov004_021707e0 + 0x6c) = ((short*)var7)[var5];
        data_ov004_021707e0[0x6f] = *(signed char*)(var8 + var5);
    } else {
        int flagVal = ((int)func_ov004_02157128(obj));
        if (flagVal == -1) {
            elem = ((struct Element020de650_0215aaf0*)ItemTable_Find(node, *(short*)(ptr2a04 + slot * 2 + 0xc)));
            if (elem->bits.field2 == 0) {
                func_ov011_021848a0(obj, 0x3a1);
                return 0;
            }
            *(short*)(data_ov004_021707e0 + 0x6c) = ((short*)(var2 + 0xc))[var5];
            unsigned char* var10 = var2 + var5 + 0x100;
            data_ov004_021707e0[0x6f] = *(signed char*)(var10 + 0x3c);
        } else {
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, flagVal);
            if (!combatant) return 0;
            int field150 = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
            elem = ((struct Element020de650_0215aaf0*)ItemTable_Find(node, ((short*)((char*)field150 + 0x400 + 0x54))[idx]));
            if (elem->bits.field2 == 0) {
                func_ov011_021848a0(obj, 0x3a1);
                return 0;
            }
            *(short*)(data_ov004_021707e0 + 0x6c) = ((short*)((char*)var12 + 0x400 + 0x54))[var3];
            data_ov004_021707e0[0x6f] = 1;
        }
        data_ov004_021707e0[0x70] = (unsigned char)var9;
    }

    int var13 = func_020de194(var6);
    int var14 = (int)((float)(unsigned int)var13 * 0.75f);
    *(int*)(data_ov004_021707e0 + 0x78) = var14;
    data_ov004_021707e0[0x6e] = 1;
    func_ov011_021848a0(arg0, 0x6c);
    return 0;
}
extern "C" void func_ov023_021fb27c(void* arg0, int arg1);

// USA: func_ov004_0215ad34
ARM int StoreDigitsAndNotify_0215ad34(void* obj) {
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
extern "C" ARM int func_ov004_0215adf8(void* arg0) {
    int var0;
    *(int*)(((char*)data_ov004_021707e0) + 0x78) = 0;
    for (var0 = 0; var0 < 7; var0++) {
        double var1 = _dflt(var0);
        int var2 = _dfix(func_020095a4(10.0, var1));
        signed char var3 = *(signed char*)(((char*)data_ov004_021707e0) + var0 + 0x3f);
        int var4 = *(int*)(((char*)data_ov004_021707e0) + 0x78);
        var4 = var2 * var3 + var4;
        *(int*)(((char*)data_ov004_021707e0) + 0x78) = var4;
    }
    *(unsigned char*)(((char*)data_ov004_021707e0) + 0x6e) = 1;
    if (*(unsigned char*)(((char*)data_ov004_021707e0) + 0x6f) == 1) {
        func_ov011_021848a0(arg0, 0x39c);
    } else {
        func_ov011_021848a0(arg0, 0x6d);
    }
    return 0;
}

// USA: func_ov004_0215aea8
extern "C" ARM int func_ov004_0215aea8(void* arg0) {
    char* var0 = ((char*)data_ov004_021707e0);
    signed char* var1 = (signed char*)(var0 + 0x3f);
    unsigned char var2 = *(unsigned char*)(var0 + 0x3e);
    signed char var3 = var1[var2];
    var3 = var3 + 1;
    var1[var2] = var3;
    var3 = var1[var2];
    if (var3 >= 10) {
        var3 = 0;
        var1[var2] = var3;
    }
    void* var4 = func_ov004_02156fa0(arg0, *(unsigned char*)(((char*)data_ov004_021707e0) + 0x3e) + 0x2d);
    if (var4) {
        signed char var5 = var1[var2];
        func_ov023_021fb27c(var4, (unsigned short)(var5 + 0x1a));
    }
    return 0;
}

// USA: func_ov004_0215af14
extern "C" ARM int func_ov004_0215af14(void* arg0) {
    char* var0 = ((char*)data_ov004_021707e0);
    signed char* var1 = (signed char*)(var0 + 0x3f);
    unsigned char var2 = *(unsigned char*)(var0 + 0x3e);
    signed char var3 = var1[var2];
    var3 = var3 - 1;
    var1[var2] = var3;
    var3 = var1[var2];
    if (var3 < 0) {
        var3 = 9;
        var1[var2] = var3;
    }
    void* var4 = func_ov004_02156fa0(arg0, *(unsigned char*)(((char*)data_ov004_021707e0) + 0x3e) + 0x2d);
    if (var4) {
        signed char var5 = var1[var2];
        func_ov023_021fb27c(var4, (unsigned short)(var5 + 0x1a));
    }
    return 0;
}

class Struct_ov004_0215af80 {
public:
    virtual void inline_ov004_0215af80(); virtual void inline_ov004_0215af80_2(); virtual void inline_ov004_0215af80_3(); virtual void inline_ov004_0215af80_4();
    virtual void inline_ov004_0215af80_5(); virtual void inline_ov004_0215af80_6(); virtual void inline_ov004_0215af80_7(); virtual void inline_ov004_0215af80_8();
    virtual void inline_ov004_0215af80_9(); virtual void inline_ov004_0215af80_10(); virtual void inline_ov004_0215af80_11(); virtual void inline_ov004_0215af80_12();
    virtual void inline_ov004_0215af80_13(); virtual void inline_ov004_0215af80_14(); virtual void inline_ov004_0215af80_15(); virtual void inline_ov004_0215af80_16();
    virtual void inline_ov004_0215af80_17(); virtual void inline_ov004_0215af80_18(); virtual void inline_ov004_0215af80_19(); virtual void inline_ov004_0215af80_20();
    virtual void inline_ov004_0215af80_21(); virtual void inline_ov004_0215af80_22(); virtual void inline_ov004_0215af80_23(); virtual void inline_ov004_0215af80_24();
    virtual void inline_ov004_0215af80_25(); virtual void inline_ov004_0215af80_26(); virtual void inline_ov004_0215af80_27(); virtual void inline_ov004_0215af80_28();
    virtual void inline_ov004_0215af80_29(); virtual void inline_ov004_0215af80_30(); virtual void inline_ov004_0215af80_31(); virtual void inline_ov004_0215af80_32();
    virtual void inline_ov004_0215af80_33(); virtual void inline_ov004_0215af80_34(); virtual void inline_ov004_0215af80_35(); virtual void inline_ov004_0215af80_36();
    virtual void inline_ov004_0215af80_37(); virtual void inline_ov004_0215af80_38(); virtual void inline_ov004_0215af80_39(); virtual void inline_ov004_0215af80_40();
    virtual void inline_ov004_0215af80_41(); virtual void inline_ov004_0215af80_42(); virtual void inline_ov004_0215af80_43(); virtual void inline_ov004_0215af80_44();
    virtual void inline_ov004_0215af80_45(); virtual void inline_ov004_0215af80_46(); virtual void inline_ov004_0215af80_47(); virtual void inline_ov004_0215af80_48();
    virtual void inline_ov004_0215af80_49(); virtual void inline_ov004_0215af80_50(); virtual void inline_ov004_0215af80_51(); virtual void inline_ov004_0215af80_52();
    virtual void inline_ov004_0215af80_53(); virtual void inline_ov004_0215af80_54(); virtual void inline_ov004_0215af80_55(); virtual void inline_ov004_0215af80_56();
    virtual void inline_ov004_0215af80_57(int arg0);
};

// USA: func_ov004_0215af80
extern "C" ARM int func_ov004_0215af80(void* arg0) {
    Struct_ov004_0215af80* var0 = (Struct_ov004_0215af80*)func_ov004_02156f38(arg0, 0x25a);
    if (var0) {
        var0->inline_ov004_0215af80_57(data_ov004_021707e0[0x6e]);
    }
    Struct_ov004_0215af80* var1 = (Struct_ov004_0215af80*)func_ov004_02156f38(arg0, 0x2bd);
    if (var1) {
        var1->inline_ov004_0215af80_57(*(int*)(data_ov004_021707e0 + 0x78));
    }
    return 0;
}

// USA: func_ov004_0215aff0
extern "C" ARM int func_ov004_0215aff0(void* arg0) {
    if (data_ov004_021707e0[0x6e] == 1) {
        func_ov011_021848a0(arg0, 0x39c);
    } else {
        func_ov011_021848a0(arg0, 0x39b);
    }
    return 0;
}

typedef void (*Type_01ff8b48_13)(void*, int);
struct Struct_ov004_0215b02c { char unknown_0_[0xe0]; Type_01ff8b48_13 unknown_e0_; };
struct Struct_ov004_0215b02c_2 { Struct_ov004_0215b02c* unknown_0_; };

// USA: func_ov004_0215b02c
extern "C" ARM int func_ov004_0215b02c(void* arg0) {
    if (data_ov004_021707e0[0x6e] < data_ov004_021707e0[0x6f]) {
        data_ov004_021707e0[0x6e]++;
        Struct_ov004_0215b02c_2* var0 = ((Struct_ov004_0215b02c_2*)func_ov004_02156f38(arg0, 0x25a));
        if (var0) {
            var0->unknown_0_->unknown_e0_(var0, data_ov004_021707e0[0x6e]);
        }
        int var1 = ((int)func_ov004_02156f6c(arg0, 0x19));
        if (var1) {
            func_ov023_021f809c((void*)var1, arg0);
        }
    }
    return 0;
}

class Struct_ov004_0215b0a8 {
public:
    virtual void inline_ov004_0215b0a8(); virtual void inline_ov004_0215b0a8_2(); virtual void inline_ov004_0215b0a8_3(); virtual void inline_ov004_0215b0a8_4();
    virtual void inline_ov004_0215b0a8_5(); virtual void inline_ov004_0215b0a8_6(); virtual void inline_ov004_0215b0a8_7(); virtual void inline_ov004_0215b0a8_8();
    virtual void inline_ov004_0215b0a8_9(); virtual void inline_ov004_0215b0a8_10(); virtual void inline_ov004_0215b0a8_11(); virtual void inline_ov004_0215b0a8_12();
    virtual void inline_ov004_0215b0a8_13(); virtual void inline_ov004_0215b0a8_14(); virtual void inline_ov004_0215b0a8_15(); virtual void inline_ov004_0215b0a8_16();
    virtual void inline_ov004_0215b0a8_17(); virtual void inline_ov004_0215b0a8_18(); virtual void inline_ov004_0215b0a8_19(); virtual void inline_ov004_0215b0a8_20();
    virtual void inline_ov004_0215b0a8_21(); virtual void inline_ov004_0215b0a8_22(); virtual void inline_ov004_0215b0a8_23(); virtual void inline_ov004_0215b0a8_24();
    virtual void inline_ov004_0215b0a8_25(); virtual void inline_ov004_0215b0a8_26(); virtual void inline_ov004_0215b0a8_27(); virtual void inline_ov004_0215b0a8_28();
    virtual void inline_ov004_0215b0a8_29(); virtual void inline_ov004_0215b0a8_30(); virtual void inline_ov004_0215b0a8_31(); virtual void inline_ov004_0215b0a8_32();
    virtual void inline_ov004_0215b0a8_33(); virtual void inline_ov004_0215b0a8_34(); virtual void inline_ov004_0215b0a8_35(); virtual void inline_ov004_0215b0a8_36();
    virtual void inline_ov004_0215b0a8_37(); virtual void inline_ov004_0215b0a8_38(); virtual void inline_ov004_0215b0a8_39(); virtual void inline_ov004_0215b0a8_40();
    virtual void inline_ov004_0215b0a8_41(); virtual void inline_ov004_0215b0a8_42(); virtual void inline_ov004_0215b0a8_43(); virtual void inline_ov004_0215b0a8_44();
    virtual void inline_ov004_0215b0a8_45(); virtual void inline_ov004_0215b0a8_46(); virtual void inline_ov004_0215b0a8_47(); virtual void inline_ov004_0215b0a8_48();
    virtual void inline_ov004_0215b0a8_49(); virtual void inline_ov004_0215b0a8_50(); virtual void inline_ov004_0215b0a8_51(); virtual void inline_ov004_0215b0a8_52();
    virtual void inline_ov004_0215b0a8_53(); virtual void inline_ov004_0215b0a8_54(); virtual void inline_ov004_0215b0a8_55(); virtual void inline_ov004_0215b0a8_56();
    virtual void inline_ov004_0215b0a8_57(int arg0);
};

// USA: func_ov004_0215b0a8
extern "C" ARM int func_ov004_0215b0a8(void* arg0) {
    unsigned char var0 = data_ov004_021707e0[0x6e];
    if (var0 <= 1) {
        goto end;
    }
    data_ov004_021707e0[0x6e] = var0 - 1;
    {
        Struct_ov004_0215b0a8* var1 = (Struct_ov004_0215b0a8*)func_ov004_02156f38(arg0, 0x25a);
        if (var1) {
            var1->inline_ov004_0215b0a8_57(data_ov004_021707e0[0x6e]);
        }
    }
    {
        void* var2 = func_ov004_02156f6c(arg0, 0x19);
        if (var2) {
            func_ov023_021f809c(var2, arg0);
        }
    }
end:
    return 0;
}

#if defined(jpn)
struct Container020e0310;
extern "C" char* func_020e207c(struct Container020e0310*, char*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#endif

struct Struct_ov004_0215b120 {
    unsigned char unknown_0_[0x18];
    short unknown_18_;
    unsigned char unknown_1a_[6];
};

#if defined(jpn)
struct Struct_020e0028 { int unknown_0_; int unknown_4_; };
struct Struct_0201099c_3 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
    Struct_020e0028* unknown_4_;
};
typedef Struct_0201099c_3 Struct_ov004_0215b120_2;
#else
struct Struct_01ff8b48_19 {
    void* unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
};
struct Struct_ov004_0215b120_2 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
    Struct_01ff8b48_19* unknown_4_;
};
#endif
struct Struct_ov004_0215b120_3 {
    unsigned char unknown_0_[0x6c];
    short unknown_6c_;
    unsigned char unknown_6e_;
    unsigned char unknown_6f_;
    unsigned char unknown_70_[8];
    int unknown_78_;
    unsigned char unknown_7c_[0x10];
    Struct_ov004_0215b120_2 unknown_8c_;
};

// USA: func_ov004_0215b120  (semantic: StoreCallResultAndDispatch_0215b120)
extern "C" ARM int func_ov004_0215b120(void* self) {
    void* g = (void*)MessageSystem_GetInstance();
    func_02046380(g);

    struct ItemTable* c = ((struct ItemTable*)func_ov004_02156fd4(self, 5));
    struct Element020de650_0215b120* elem = ((struct Element020de650_0215b120*)ItemTable_Find(c, ((ItemSelection0215b120*)data_ov004_021707e0)->itemId));

    Struct_ov004_0215b120_3* var3 = ((Struct_ov004_0215b120_3*)data_ov004_021707e0);
    unsigned char var4 = var3->unknown_6e_;
    Struct_ov004_0215b120_2* var5 = &var3->unknown_8c_;

    if (var4 == 1) {
#if defined(jpn)
        char name[80];
        func_020e207c(names, name, elem->key);
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        void* var7 = func_020e5294(var5, var2->unknown_18_);
        *(void**)((char*)var0 + 0x18) = var7;
#endif
        func_020465c0((struct Struct_020465c0*)var0, 0, ((Struct_ov004_0215b120_3*)data_ov004_021707e0)->unknown_78_);
    } else {
#if defined(jpn)
        char name[80];
        func_020e207c(names, name, elem->key);
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, name);
#else
        void* var9 = func_020e5294(var5, var2->unknown_18_);
        *(void**)((char*)var0 + 0x18) = var9;
#endif
        func_020465c0((struct Struct_020465c0*)var0, 0, ((Struct_ov004_0215b120_3*)data_ov004_021707e0)->unknown_78_);
        func_020465c0((struct Struct_020465c0*)var0, 1, ((Struct_ov004_0215b120_3*)data_ov004_021707e0)->unknown_6e_);
    }
    return 0;
}
struct Struct_02061c04_23;
extern "C" int func_020a0a08(struct Struct_02061c04_23* arg0, int arg1, int arg2);
struct Struct_020838c4;
extern "C" int func_020838c4(struct Struct_020838c4* arg0, int arg1);

struct Struct_ov004_0215b1d4 { unsigned short unknown_0_0_ : 13; unsigned short unknown_1_5_ : 3; };

#if defined(jpn)
void* GameState_GetParty(struct GameState*);
struct GameObject* GetCombatantWithFlag0x100_0200ff1c(struct GameState*, int);

#endif
// USA: func_ov004_0215b1d4
extern "C" ARM int func_ov004_0215b1d4(void* arg0) {
    GameState* var0 = GameState::GetInstance();
#if defined(jpn)
    char* var1 = (char*)var0 + 0xc + 0x5c00;
#else
    char* var1 = (char*)var0 + 0x26c + 0x5c00;
#endif

    *(short*)(var1 + 0xf8) = *(short*)(data_ov004_021707e0 + 0x6c);
    *(short*)(var1 + 0xfa) = *(unsigned char*)(data_ov004_021707e0 + 0x6e);
    *(short*)(var1 + 0xfc) = *(int*)(data_ov004_021707e0 + 0x78);

    int cnt = *(int*)(data_ov004_021707e0 + 0x74);
    if (cnt >= 0) {
        void* result = GameState_GetParty(bs);
        if (!result) return 0;
        short key = *(short*)(data_ov004_021707e0 + 0x6c);
        signed char amt = *(signed char*)(data_ov004_021707e0 + 0x6e);
        int key2 = *(int*)(data_ov004_021707e0 + 0x74);
        DecrementKeyedStackAmount0207c484((struct KeyedList0207c484*)((char*)result + 0x1d4), key, amt, key2);
    } else if (*(signed char*)(data_ov004_021707e0 + 0x70) == -1) {
        void* result = GameState_GetParty(bs);
        if (!result) return 0;
        short key = *(short*)(data_ov004_021707e0 + 0x6c);
        signed char amt = *(signed char*)(data_ov004_021707e0 + 0x6e);
        DecrementKeyValue020a0a08((struct KeyMap020a0a08*)result, key, amt);
    } else {
        int var10 = *(signed char*)(data_ov004_021707e0 + 0x70);
        GameObject* var11 = func_0200ff1c(var0, var10);
        if (!var11) return 0;
        int var12 = func_02053c6c((unsigned char*)var11);
        short var13 = *(short*)(data_ov004_021707e0 + 0x6c);
        func_020838c4((struct Struct_020838c4*)var12, var13);
    }

    func_ov004_0215a2f8(data_ov004_021707e0);

    Struct_ov004_0215b1d4* var14 = (Struct_ov004_0215b1d4*)(var1 + 0x10c);
    var14->unknown_0_0_ |= 0x10;

    unsigned char var15 = *(data_ov004_021707e0 + 0x6e);
    if (var15 > 1) {
        func_ov011_021848a0(arg0, 0x2423);
    } else {
        func_ov011_021848a0(arg0, 0x39d);
    }
    return 0;
}

// USA: func_ov004_0215b330
extern "C" ARM void* func_ov004_0215b330(void* arg0) {
    func_ov004_0215a2f8(data_ov004_021707e0);
    func_ov011_021848a0(arg0, 0x39e);
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
    virtual void inline_ov004_0215b360_57(int);
    char unknown_4_[8];
    unsigned char unknown_c_;
    char unknown_d_[0x20 - 0xd];
    void* unknown_20_;
};
struct Struct_ov004_0215b360_2 {
    char unknown_0_[0x5c];
    short unknown_5c_, unknown_5e_;
};
struct Struct_ov004_0215b360_3 {
    char unknown_0_[0x7c];
    unsigned char unknown_7c_[8];
};
struct Struct_ov004_0215b360_4 {
    char unknown_0_[0x1d4];
    unsigned char unknown_1d4_[1];
};
struct Struct_ov004_0215b360_5 {
    unsigned int unknown_0_;
    void* unknown_4_;
};
extern "C" int func_ov004_02156e2c(void*, int);
extern "C" void func_ov023_021f65d4(void*, int, int);
typedef void (*Type_ov004_021561b0)(Struct_ov004_0215b360_2*, unsigned short, unsigned int, unsigned int);
typedef void* (*Type_ov004_0215b360)(void*, int);

// USA: func_ov004_0215b360
extern "C" ARM int func_ov004_0215b360(void* object) {
    short* items = NULL;
    signed char* amounts = NULL;
    int count = 0;
    ItemTable* container = ((ItemTable*)func_ov004_02156fd4(object, 5));
    TableA68* table = ((TableA68*)DispatchAdjustmentIfType4_02157018(object, 3));
    int selected = DispatchNodeIfType7_02156e2c(object, 0x65);
    if (selected < 0) return 0;
    PartyState0215b360* party = (PartyState0215b360*)GameState_GetParty(GameState::GetInstance());
    if (!party) return 0;
    for (int i = 0; i < 8; i++) {
        if (i == selected) {
            ItemNode0215b360* node = ((ItemNode0215b360*)func_ov004_02156f04(object, 0x454));
            if (node) node->value = FindEntryByKey_02072a68(table, (short)(i + 0x1b));
            ClearNodeMaskById_021f6600(object, i + 0x38c, 8);
            items = ((short*)GetPointerFromArray0xbd0_0207c5f8(party->inventory, ((ItemLists0215b360*)data_ov004_021707e0)->listIds[selected]));
            amounts = ((signed char*)GetPointerAt0xbf0_0207c60c(party->inventory, ((ItemLists0215b360*)data_ov004_021707e0)->listIds[selected]));
            count = ((int)CountPositiveEntries0207c638(party->inventory, ((ItemLists0215b360*)data_ov004_021707e0)->listIds[selected]));
        } else {
            func_ov023_021f65d4(arg0, var7 + 0x38c, 8);
        }
    }
    Grid021f9b30_0215b360* grid = ((Grid021f9b30_0215b360*)func_ov004_02156ed0(object, 0x63));
    if (!grid) return 0;
    short pages = (count - 1) / 8 + 1;
    if (pages < 1) pages = 1;
    grid->page = 0;
    grid->pages = pages;
    ((ItemNode0215b360*)func_ov004_02156f38(object, 0x456))->notify(1);
    ((ItemNode0215b360*)func_ov004_02156f38(object, 0x457))->notify(pages);
    for (int i = 0; i < 8; i++)
        ((ItemNode0215b360*)func_ov004_02156f38(object, i + 0x461))->notify(amounts[i]);
    for (int i = 0; i < 8; i++) {
        Element020de650_0215b360* entry = ((Element020de650_0215b360*)ItemTable_Find(container, items[i]));
        ItemNode0215b360* node = ((ItemNode0215b360*)func_ov004_02156f04(object, i + 0x44c));
        if (!entry) {
            node->flags |= 8;
            func_ov023_021f65d4(object, i + 0x459, 8);
            func_ov023_021f65d4(object, i + 0x461, 8);
            SetCellIfInBounds_021f9b30((Grid021f9b30*)grid, 0, (unsigned short)i, 0);
        } else {
            void* var15 = var13->unknown_4_ ? var13->unknown_4_ : NULL;
            if (var14) {
                var14->unknown_c_ &= ~8;
                var14->unknown_20_ = var15;
                func_ov023_021f6600(arg0, var12 + 0x459, 8);
                func_ov023_021f6600(arg0, var12 + 0x461, 8);
                ((Type_ov004_021561b0)func_ov023_021f9b30)(var9, (unsigned short)(var12 + 0x44c), (unsigned short)var12, 0);
            }
        }
    }
    void* var16 = func_ov004_02156f6c(arg0, 0x17);
    if (var16) func_ov023_021f809c(var16, arg0);
    void* var17 = ((Type_ov004_0215b360)func_ov004_02157088)(arg0, 7);
    if (var17) func_ov023_021dcae0((Struct_ov003_02178910*)var17, -1);
    return 0;
}
extern "C" int func_0207c51c(unsigned char* arg0, int arg1);

// USA: func_ov004_0215b694  (semantic: CompactAndResetCombatants_0215b694)
extern "C" ARM int func_ov004_0215b694(void* obj) {
    void* ptr = GameState_GetParty(GameState::GetInstance());
    if (!ptr) {
        return 0;
    }
    for (int var1 = 0; var1 < 8; var1++) {
        int var2 = *(data_ov004_021707e0 + var1 + 0x7c);
        func_0207c51c((unsigned char*)var0 + 0x1d4, var2);
    }
    func_ov004_0215a2f8(data_ov004_021707e0);
    func_ov011_021848a0(arg0, 0x3a0);
    func_ov023_021f65d4(arg0, 2, 8);
    return 0;
}

// USA: func_ov004_0215b710
extern "C" ARM int func_ov004_0215b710(void* arg0) {
    int var0 = func_ov004_02156e2c(arg0, 0x65);
    if (var0 >= 0) {
        func_ov023_021f6600(arg0, var0 + 0x38c, 8);
    }
    return 0;
}
extern "C" void func_0207d300(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov004_0215b7c8(struct Struct_ov004_0215b740*);

// USA: func_ov004_0215b740
extern "C" ARM int func_ov004_0215b740(void* arg0) {
#if defined(jpn)
    enum { Enum_ov004_0215b740_620 = 0xc };
#else
    enum { Enum_ov004_0215b740_620 = 0x26c };
#endif
    char* p = (char*)GameState::GetInstance() + memberOffset + 0x5c00;
    void* node = ((void*)func_ov004_02156fd4(obj, 5));
    char buf[0x38];
    ((SafeAllocator*)buf)->ResetAllocatorPointer();
    ItemTable_Construct(buf + 0x14);
    InitStruct0207cbe8(buf);
    InitStruct0207cbe8(buf);
    *(void**)(buf + 0x2c) = node;
    short a = *(short*)(p + 0xf8);
    signed char b = *(unsigned short*)(p + 0xfa);
    func_0207d300(buf, a, b, 0);
    func_ov004_0215b7c8((ShortTriple_0215b7c8*)(p + 0xf8));
    func_ov011_021848a0(obj, 0x3a4);
    return 0;
}

struct Struct_ov004_0215b740 { short unknown_0_, unknown_2_, unknown_4_; };

// USA: func_ov004_0215b7c8
extern "C" ARM void func_ov004_0215b7c8(Struct_ov004_0215b740* arg0) {
    arg0->unknown_0_ = -1;
    arg0->unknown_2_ = 0;
    arg0->unknown_4_ = 0;
}

// USA: func_ov004_0215b7e0
extern "C" ARM int func_ov004_0215b7e0(void* arg0) {
    func_ov011_021848a0(arg0, 0x3a5);
    return 0;
}

#if defined(jpn)
enum { Enum_ov004_0215b7f8_620 = 0xc, Enum_ov004_0215b7f8_2456 = 0x868 };
#else
enum { Enum_ov004_0215b7f8_620 = 0x26c, Enum_ov004_0215b7f8_2456 = 0x998 };
#endif

struct Struct_ov004_0215b7f8 {
    char unknown_0_[0x18];
    Struct_ov004_021589e8 unknown_18_;
    char unknown_1c_[0x14];
    unsigned char unknown_30_;
    char unknown_31_[9];
    short unknown_3a_;
};

struct Struct_ov004_0215b7f8_2 {
    Struct_ov004_021589e8 unknown_0_;
    char unknown_4_[0xc];
    int unknown_10_;
    char unknown_14_[0x200];
    char unknown_214_[0x200];
};
struct Struct_ov004_0215b7f8_3 { char unknown_0_[0x100]; Struct_ov004_0215b7f8_2 unknown_100_; };
struct Struct_ov004_0215b7f8_4 { char unknown_0_[Enum_ov004_0215b7f8_620 + 0x5d00]; Struct_ov004_0215b7f8_2 unknown_5f6c_; };

struct Struct_ov004_0215b7f8_5 {
    char unknown_0_[Enum_ov004_0215b7f8_2456];
    int unknown_998_;
    int unknown_99c_;
};
extern "C" int func_0202c508(struct Struct_0202c508*);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif

static inline void inline_ov004_0215b7f8(char* arg0, const char* arg1) {
    int var0 = strlen(arg1);
    const char* var1 = "<PAD_WAIT><ADD>";
    memcpy(arg0, arg1, var0);
    strcpy(arg0 + var0, var1);
}

#if defined(jpn)
extern "C" void func_02096660(Struct_0208cb08*, int, char*, int);
#endif

// USA: func_ov004_0215b7f8
extern "C" ARM int func_ov004_0215b7f8(void* arg0) {
    if (!((struct Struct_02072a68_2*)func_ov004_02157018(arg0, 4))) return 0;
    GameState* var0 = GameState::GetInstance();
    Struct_ov004_0215b7f8_3* var1 = (Struct_ov004_0215b7f8_3*)((char*)var0 + Enum_ov004_0215b7f8_620 + 0x5c00);
    if (func_0202c508((Struct_0202c508*)(func_0202ae18())) && func_ov017_021b213c(var1->unknown_100_.unknown_0_, ((Struct_ov004_0215b7f8*)data_ov004_021707e0)->unknown_18_)) {
        char var2[0x200];
        char var3[0x220];
        int var4 = ((Struct_ov004_0215b7f8_4*)var0)->unknown_5f6c_.unknown_10_;
        memcpy(var2, ((Struct_ov004_0215b7f8_4*)var0)->unknown_5f6c_.unknown_214_, var4);
#if defined(jpn)
        func_02096660(FontBankLoader_GetInstance(), 5001, data, size);
#else
        AlwaysFalse02094b54(FontBankLoader_GetInstance(), 5001, data, size);
#endif
        AddPadWait0215b7f8(text, ((Full0215b7f8*)gs)->slot.name);
        TextRenderer0215b7f8* tr = ((TextRenderer0215b7f8*)MessageSystem_GetInstance());
#if defined(jpn)
        func_0204500c(var5, var3, 0);
#else
        func_0204500c(var5, var3, 0, 0xe3);
#endif
        var5->unknown_998_ = 1;
        var5->unknown_99c_ = 2;
        ((Struct_ov004_0215b7f8*)data_ov004_021707e0)->unknown_30_ = 1;
    }
    short var6 = ((Struct_ov004_0215b7f8*)data_ov004_021707e0)->unknown_3a_;
    int var7;
    for (var7 = 0; var7 < var6; var7++) {
    }
    func_ov011_021848a0(arg0, var6 + 0x2486);
    return 0;
}

#if defined(jpn)
enum{Enum_ov004_0215b934_620=0xc};
#else
enum{Enum_ov004_0215b934_620=0x26c};
#endif

struct Struct_ov004_0215b934 {
    char unknown_0_[0x14];
    unsigned char unknown_14_;
    char unknown_15_[0x77];
    unsigned char unknown_8c_[1];
};

struct Struct_ov004_0215b934_2 {
    short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    char unknown_6_[0xe];
    unsigned short unknown_14_0_ : 13;
};

struct Struct_ov004_0215b934_3 {
    char unknown_0_[0xf8];
    Struct_ov004_0215b934_2 unknown_f8_;
};

struct Struct_ov004_0215b934_4 {
    char unknown_0_[0xf6c];
    unsigned int unknown_f6c_;
};

struct Struct_ov004_0215b934_5 {
    char unknown_0_[0x18];
    short unknown_18_;
};

struct Struct_ov004_0215b934_6 {
    char unknown_0_[0x18];
    int unknown_18_;
};
struct Struct_02046574_2;
#if defined(jpn)
extern "C" char* func_020e207c(struct Struct_0201099c_3*, char*, int);
#else
extern "C" void* func_020e5294(void*, int);
#endif

void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);

// USA: func_ov004_0215b934
extern "C" ARM int func_ov004_0215b934(void* obj) {
    if (((BattleMenuState0215b934*)data_ov004_021707e0)->active) {
        GameState* gs = GameState::GetInstance();
        Wallet0215b934* wallet = (Wallet0215b934*)GameState_GetParty(gs);
        Element0215b934* elem;
        Message0215b934* msg;
        unsigned int amount;
        RewardArea0215b934* area = (RewardArea0215b934*)((char*)gs + regionalAreaOffset_0215b934 + 0x5c00);
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
            amount = area->reward.count * area->reward.unitValue;
            if (9999999 - wallet->gold < amount) {
                amount = 9999999 - wallet->gold;
            }
            var1->unknown_f6c_ += var4;
            struct Struct_02072a68_2* var8 = ((struct Struct_02072a68_2*)func_ov004_02157018(arg0, 9));
#if defined(jpn)
            char name[80];
            func_020e207c((Container020e0310*)(((BattleMenuState0215b934*)data_ov004_021707e0)->table), name, elem->nameId);
            MessageSystem_SetStringArgument((Obj02046574*)msg, 1, name);
#else
            var3->unknown_18_ = ((int)func_020e5294(((Struct_ov004_0215b934*)data_ov004_021707e0)->unknown_8c_, var2->unknown_18_));
#endif
            MessageSystem_SetStringArgument((struct Obj02046574*)msg, 2, ((char*)FindEntryByKey_02072a68(names, (short)(rand() % 0x3a))));
            MessageSystem_SetStringArgument((struct Obj02046574*)msg, 3, ((char*)FindEntryByKey_02072a68(names, (short)(rand() % 6 + 1000))));
            StoreInArray0x8b0_020465c0((struct StoreStruct*)msg, 0, amount);
            func_ov011_021848a0(obj, 0x3a8);
        } else if (kind & 2) {
            char buf[0x38];
            ((SafeAllocator*)buf)->ResetAllocatorPointer();
            ItemTable_Construct(buf + 0x14);
            InitStruct0207cbe8(buf);
            InitStruct0207cbe8(buf);
            func_0207d300(buf, area->reward.itemId, (signed char)area->reward.count, 0);
#if defined(jpn)
            char name[80];
            func_020e207c((Container020e0310*)(((BattleMenuState0215b934*)data_ov004_021707e0)->table), name, elem->nameId);
            MessageSystem_SetStringArgument((Obj02046574*)msg, 1, name);
#else
            var3->unknown_18_ = ((int)func_020e5294(((Struct_ov004_0215b934*)data_ov004_021707e0)->unknown_8c_, var2->unknown_18_));
#endif
            func_ov011_021848a0(arg0, 0x3a9);
        } else {
            func_ov011_021848a0(arg0, 0x387);
        }
        func_ov004_0215b7c8((Struct_ov004_0215b740*)(&var5->unknown_f8_));
    } else {
        func_ov011_021848a0(arg0, 0x387);
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
extern "C" ARM int func_ov004_0215bb54(void* arg0) {
    void* var0 = *(void**)((unsigned char*)GetGameResources() + Enum_ov004_0215bb54_15176);
    unsigned char var1 = data_ov004_021707e0[0x13];
    if (var1 == 0) {
        void* var2 = func_ov011_021845f8((unsigned char*)arg0, (int)1);
        if (var2 == 0) {
            func_ov004_0215a2f8(data_ov004_021707e0);
            func_ov011_021848a0(arg0, 0x39e);
            data_ov004_021707e0[0x13] = 0;
            return 0;
        }
        func_ov017_021b1d44((unsigned char*)var0, 4, 1);
        *(void**)((char*)var0 + 8) = (char*)var2 + 4;
        int var3 = func_ov011_02184548((struct Struct_ov004_0215883c_2*)arg0);
        int var4 = func_ov011_02184540((struct Struct_ov004_0215883c*)arg0);
        *(int*)((char*)var0 + 0x34) = var4;
        *(int*)((char*)var0 + 0x38) = var3;
        data_ov004_021707e0[0x13]++;
        func_ov011_021848a0(obj, 0x3aa);
        void* node = (void*)DispatchAdjustmentIfType4_02157018(obj, 4);
        int g = MessageSystem_GetInstance();
        void* found = FindEntryByKey_02072a68((struct TableA68*)node, 0x13);
#if defined(jpn)
        func_0204500c((void*)var6, (const char*)var7, 0);
#else
        func_0204500c((void*)var6, (const char*)var7, 0, 0xe3);
#endif
        *(int*)((char*)var6 + Enum_ov004_0215bb54_2456) = 1;
    } else if (var1 == 1) {
        func_ov011_021848a0(arg0, 0x3ab);
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

extern "C" ARM void func_ov004_0215781c(void* arg0);
extern "C" ARM int func_ov017_021b1fd4(void* arg0);
extern "C" void func_ov004_021571f4(void* arg0, int arg1);
extern "C" ARM void func_ov004_02157874(void* arg0);
extern "C" int func_ov017_021b1ffc(Struct_ov004_021583a8_2* arg0);
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
    void* table = (void*)DispatchAdjustmentIfType4_02157018(obj, 4);
    g = MessageSystem_GetInstance();
    unsigned char flag = data_ov004_021707e0[0x13];

    if (flag == 2) {
        ClearOrMaskNodesByState_0215781c(obj);
        FieldTask_ConnectWifi(five, (int)list);
        int t = GetFieldromField_021b1fd4_021b1fd4(five) >> 12;
        func_ov004_021571f4(obj, t);
        GetSubByteField34_021b2024((Obj24_021b2024*)five);
        GetSubByteField35_021b2038((Obj24_021b2038*)five);
        if (*(int*)(resources->unknown_4490 + 4) == 0) {
            data_ov004_021707e0[0x13]++;
        }
        goto returnOne;
    } else if (var5 == 3) {
        func_ov004_02157874(arg0);
        char* var7 = *(char**)((char*)var0 + Enum_ov004_0215bc9c_92);
        memset(var7, 0, Enum_ov004_0215bc9c_2400);

        if (func_ov017_021b1fe8((Struct_ov004_021583a8*)var3) & 4) {
            data_ov004_021707e0[0x15] = 1;
            const char* var8 = (const char*)func_02072a68((struct Struct_02072a68_2*)var4, 0x26);
            memcpy(var7, var8, strlen(var8));
            func_ov011_021848a0(arg0, 0x3af);
        } else {
            data_ov004_021707e0[0x15] = 0;
            const char* var9 = (const char*)func_02072a68((struct Struct_02072a68_2*)var4, 0x15);
            int var10 = strlen(var9);
            memcpy(var7, var9, var10);

            int var11 = func_ov017_021b1ffc((Struct_ov004_021583a8_2*)var3);
            int var12 = func_ov017_021b2010((Struct_ov004_021583a8_3*)var3);
            func_ov004_02157374(arg0, var11, var12, var7 + var10, 0);
            strlen(var7 + var10);
            func_ov011_021848a0(arg0, 0x242d);
        }

        *((unsigned char*)var3 + 1) = 1;
        data_ov004_021707e0[0x13] = 0;
        unsigned char* var13 = data_ov004_021707e0;
        memset(var13 + 0x1c, 0, 0xc);
        *(int*)(var13 + 0x28) = 0;
#if defined(jpn)
        func_0204500c((void*)var0, (const char*)(*(char**)((char*)var0 + Enum_ov004_0215bc9c_92)), 0);
#else
        func_0204500c((void*)var0, *(char**)((char*)var0 + Enum_ov004_0215bc9c_92), 0, 0xe3);
#endif
        *(int*)((char*)var0 + Enum_ov004_0215bc9c_2456) = 1;
        return 0;
    }

returnOne:
    return 1;
}

struct Struct_ov004_0215be9c { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; };
extern "C" int func_ov004_021571d8(int arg0);
extern "C" int func_ov004_02156e2c(void* arg0, int arg1);

// USA: func_ov004_0215be9c
extern "C" ARM int func_ov004_0215be9c(int obj) {
    GameState* gs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GameState_GetParty(gs);
    if (p == 0) {
        return 0;
    }
    Struct_ov004_0215be9c* var2 = ((Struct_ov004_0215be9c*)func_ov004_02156ed0((void*)arg0, 0x63));
    int var3 = var2->unknown_5c_ << 3;
    unsigned char* var4;
    if (func_ov004_021571d8(arg0)) {
        int var5 = func_ov004_02156e2c((void*)arg0, 0x65);
        if (var5 < 0) {
            return 0;
        }
        var4 = (unsigned char*)func_0207c5f8(var1 + 0x1d4, *(data_ov004_021707e0 + var5 + 0x7c));
    } else {
        signed char var6 = func_ov004_02157128((void*)arg0);
        if (var6 >= 0) {
            void* var7 = func_0200ff1c(var0, var6);
            if (var7 == 0) {
                return 0;
            }
            unsigned char* var8 = (unsigned char*)((void*)func_02053c6c((unsigned char*)var7)) + 0x54;
            var4 = var8 + 0x400;
            var3 = 0;
        } else {
            var4 = var1 + 0xc;
        }
    }
    void* var9 = func_ov004_02157088((void*)arg0, 7);
    int var10 = func_ov004_02156e2c((void*)arg0, 0x63);
    if (var9 != 0) {
        func_ov023_021dcae0((Struct_ov003_02178910*)((void*)var9), (short)(((short*)var4)[var3 + var10]));
    }
    return 0;
}

#if defined(jpn)
int KeyTable_LoadInPlace(void*, void*, int);
#endif

#if defined(jpn)
typedef Struct_0201099c_3 Struct_01ff8b48_21;
#else
struct Struct_01ff8b48_20 {
    void* unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
};
struct Struct_01ff8b48_21 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
    Struct_01ff8b48_20* unknown_4_;
};
#endif
struct Struct_ov004_0215bf94 {
    unsigned char unknown_0_[0x2d];
    unsigned char unknown_2d_;
    unsigned char unknown_2e_[0x8c - 0x2e];
    Struct_01ff8b48_21 unknown_8c_;
#if defined(jpn)
    unsigned char unknown_94_[0x10];
#else
    unsigned char unknown1_94_[4];
#endif
    void* unknown_98_;
};

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG3ScreenBase(void);
struct Struct_0209c3b4_2;
extern "C" void func_0209c3b4(struct Struct_0209c3b4_2* arg0, int arg1);
extern "C" void func_0209ca70(void* arg0, int arg1);
extern "C" void func_020dc2bc(void);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);
extern "C" int func_020e56fc(void* arg0, int arg1, int arg2);

#if defined(jpn)
// USA: func_ov004_0215bf94
extern "C" ARM int func_ov004_0215cfdc() {
#else
// USA: func_ov004_0215bf94
extern "C" ARM int func_ov004_0215bf94() {
#endif
    unsigned short* var0 = (unsigned short*)GetSubBG0ScreenBase();
    int var1;
    for (var1 = 0; var1 < 0x800; var1++) {
        *var0++ = 0;
    }
    memset((void*)GetMainBG3ScreenBase(), 0, 0x1000);
    struct Struct_ov004_0215bf94_2 {
        unsigned char unknown_0_[0xd];
        unsigned char unknown_d_0_ : 7;
        unsigned char unknown_d_7_ : 1;
    };
    struct Struct_ov004_0215bf94_3 {
        unsigned char unknown_0_[8];
        Struct_ov004_0215bf94_2* unknown_8_;
    };
    GlobalState0215bf94* owner = (GlobalState0215bf94*)Zone3D_GetInstance();
    unsigned char v = owner->current->state;
    SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)g_bgmPlayer, v);
    SetModeClamped0209ca70(g_bgmPlayer, ((ItemNameLoader0215bf94*)data_ov004_021707e0)->mode);
    OrGlobalFlag0x40_020dc2bc();
#if defined(jpn)
    unsigned int size;
    LoadFileIntoMemory("data/prm/itemname.nat", ((ItemNameLoader0215bf94*)data_ov004_021707e0)->fileBuffer, &size);
    KeyTable_LoadInPlace(&((ItemNameLoader0215bf94*)data_ov004_021707e0)->names, ((ItemNameLoader0215bf94*)data_ov004_021707e0)->fileBuffer, (int)size);
#else
    BackgroundLoader::AddLockGlobal();
    unsigned int var5;
    void* var6 = ExtractFileFromGP2("data/prm/itemname.gp2", "itemname_<LG>.nat", &var5);
    if (var5 <= 0x10800) {
        memcpy(((Struct_ov004_0215bf94*)data_ov004_021707e0)->unknown_98_, var6, var5);
        func_020e56fc(&((Struct_ov004_0215bf94*)data_ov004_021707e0)->unknown_8c_, (int)((Struct_ov004_0215bf94*)data_ov004_021707e0)->unknown_98_, (int)var5);
    }
    BackgroundLoader::RemoveLockGlobal();
#endif
    return 0;
}

// USA: func_ov004_0215c064
extern "C" ARM int func_ov004_0215c064(void* arg0) {
	func_ov011_021848a0(arg0, 0x50);
	func_ov023_021f65d4(arg0, 2, 8);
	return 0;
}

// USA: func_ov004_0215c08c
extern "C" ARM int func_ov004_0215c08c(void) {
    return 0;
}

// USA: func_ov004_0215c094
extern "C" ARM int func_ov004_0215c094(void* arg0) {
    func_ov011_021848a0(arg0, 0x387);
    return 0;
}

// USA: func_ov004_0215c0ac
extern "C" ARM int func_ov004_0215c0ac(int arg0) {
	func_ov011_021848a0((void*)arg0, 0x65);
	return 0;
}

struct Struct_ov004_0215c0c0 { unsigned int unknown_0_0_ : 7; unsigned int unknown_0_7_ : 25; };
struct Struct_ov004_0215c0c0_2 { char unknown_0_[0xf6c]; int unknown_f6c_; };

// USA: func_ov004_0215c0c0  (semantic: TickCounterAndConsumeResource_0215c0c0)
extern "C" ARM int func_ov004_0215c0c0(void* obj) {
    int code = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (code < 0) return 0;
    void* entry = GetEntryFor_021570a4(obj, code & 0xff);
    if (!entry) return 0;
    struct Field2a04_0215c0c0* fld = (struct Field2a04_0215c0c0*)GameState_GetParty(GameState::GetInstance());
    struct Combined0215c0c0* c = (struct Combined0215c0c0*)((char*)entry + 4);
    unsigned char rate = data_ov004_021707e0[0x11];
    unsigned int restVal = c->rest;
    int product1 = rate * restVal;
    c->low7 = c->low7 - rate;
    unsigned char rate2 = data_ov004_021707e0[0x11];
    unsigned int restVal2 = c->rest;
    int product2 = rate2 * restVal2;
    fld->f0xf6c -= product2;
#if defined(jpn)
    data_ov004_021707e0[0xa9] = 1;
#else
    data_ov004_021707e0[0x9d] = 1;
#endif
    if (var6 >= 50000) {
        func_ov011_021848a0(arg0, 0x2366);
    } else {
        func_ov011_021848a0(arg0, 0x2364);
    }
    return 0;
}

// USA: func_ov004_0215c194
extern "C" ARM int func_ov004_0215c194(void* arg0) {
    func_ov011_021848a0(arg0, 0x39f);
    return 0;
}
extern "C" void func_ov023_021f8240(void*, void*);

class Struct_ov004_0215c1ac {
public:
    virtual void inline_ov004_0215c1ac(); virtual void inline_ov004_0215c1ac_2(); virtual void inline_ov004_0215c1ac_3(); virtual void inline_ov004_0215c1ac_4();
    virtual void inline_ov004_0215c1ac_5(); virtual void inline_ov004_0215c1ac_6(); virtual void inline_ov004_0215c1ac_7(); virtual void inline_ov004_0215c1ac_8();
    virtual void inline_ov004_0215c1ac_9(); virtual void inline_ov004_0215c1ac_10(); virtual void inline_ov004_0215c1ac_11(); virtual void inline_ov004_0215c1ac_12();
    virtual void inline_ov004_0215c1ac_13(); virtual void inline_ov004_0215c1ac_14(); virtual void inline_ov004_0215c1ac_15(); virtual void inline_ov004_0215c1ac_16();
    virtual void inline_ov004_0215c1ac_17(); virtual void inline_ov004_0215c1ac_18(); virtual void inline_ov004_0215c1ac_19(); virtual void inline_ov004_0215c1ac_20();
    virtual void inline_ov004_0215c1ac_21(); virtual void inline_ov004_0215c1ac_22(); virtual void inline_ov004_0215c1ac_23(); virtual void inline_ov004_0215c1ac_24();
    virtual void inline_ov004_0215c1ac_25(); virtual void inline_ov004_0215c1ac_26(); virtual void inline_ov004_0215c1ac_27(); virtual void inline_ov004_0215c1ac_28();
    virtual void inline_ov004_0215c1ac_29(); virtual void inline_ov004_0215c1ac_30(); virtual void inline_ov004_0215c1ac_31(); virtual void inline_ov004_0215c1ac_32();
    virtual void inline_ov004_0215c1ac_33(); virtual void inline_ov004_0215c1ac_34(); virtual void inline_ov004_0215c1ac_35(); virtual void inline_ov004_0215c1ac_36();
    virtual void inline_ov004_0215c1ac_37(); virtual void inline_ov004_0215c1ac_38(); virtual void inline_ov004_0215c1ac_39(); virtual void inline_ov004_0215c1ac_40();
    virtual void inline_ov004_0215c1ac_41(); virtual void inline_ov004_0215c1ac_42(); virtual void inline_ov004_0215c1ac_43(); virtual void inline_ov004_0215c1ac_44();
    virtual void inline_ov004_0215c1ac_45(); virtual void inline_ov004_0215c1ac_46(); virtual void inline_ov004_0215c1ac_47(); virtual void inline_ov004_0215c1ac_48();
    virtual void inline_ov004_0215c1ac_49(); virtual void inline_ov004_0215c1ac_50(); virtual void inline_ov004_0215c1ac_51(); virtual void inline_ov004_0215c1ac_52();
    virtual void inline_ov004_0215c1ac_53(); virtual void inline_ov004_0215c1ac_54();
    virtual void inline_ov004_0215c1ac_55(int arg0);
};

// USA: func_ov004_0215c1ac
extern "C" ARM int func_ov004_0215c1ac(void* arg0) {
    for (int var0 = 0; var0 < 8; var0++) {
        void* var1 = func_ov004_02156f04(arg0, var0 + 0x44c);
        *(unsigned char*)((char*)var1 + 0x45) &= ~1;
        ((Struct_ov004_0215c1ac*)var1)->inline_ov004_0215c1ac_55(0xf);
    }
    void* var2 = func_ov004_02156f6c(arg0, 0x17);
    if (var2) {
        func_ov023_021f8240(var2, arg0);
    }
    func_ov011_021848a0(arg0, 0x6b);
    return 0;
}

// USA: func_ov004_0215c228
extern "C" ARM int func_ov004_0215c228(int arg0) {
	func_ov011_021848a0((void*)arg0, 0x6a);
	return 0;
}

// USA: func_ov004_0215c23c
extern "C" ARM int func_ov004_0215c23c(int arg0) {
	func_ov011_021848a0((void*)arg0, 0x6c);
	return 0;
}

// USA: func_ov004_0215c250
extern "C" ARM int func_ov004_0215c250(void* arg0) {
    func_ov011_021848a0(arg0, 0x396);
    return 0;
}

extern "C" int func_ov004_021589e8(void*);

// USA: func_ov004_0215c268
extern "C" ARM int func_ov004_0215c268(void* arg0) {
	int var0;
	unsigned char* var1 = (unsigned char*)((char*)data_ov004_021707e0);
	if (var1[0x30] == 0) goto skip;
	{
		FontBankLoader* g = FontBankLoader_GetInstance();
		unsigned char* p2 = (unsigned char*)((char*)data_ov004_021707e0);
		if (p2[0x2c] != 0) goto elseBranch;
		BlankFunction02094b34(g, 0x72, 0x202, 0, 0);
		{
			unsigned char* var4 = (unsigned char*)((char*)data_ov004_021707e0);
			var4[0x2c] = var4[0x2c] + 1;
		}
		var0 = 1;
		goto done;
	elseBranch:
		if (func_02094b4c(var2)) {
			unsigned char* var5 = (unsigned char*)((char*)data_ov004_021707e0);
			var5[0x2c] = 0;
			goto skip;
		}
		var0 = 1;
		goto done;
	}
skip:
	func_ov004_021589e8(arg0);
	var0 = 0;
done:
	return var0;
}

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
extern "C" void* func_ov004_0215c448(void* obj);
extern "C" void* func_ov004_0215c474(void* obj);
ARM int InitObjWithMisc_021f6f20(void* obj, int p1, int p3, int p4, int arg5, unsigned int arg6);
ARM void* AddOffset20_021f7318(void* p);
ARM void SetField1cTo2_021f7320(void* p);

struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
extern "C" void SprSprite_Init(void* obj);
void SprSprite_LoadFile(void* a, int b, int c, int d);

struct Struct_ov004_0215c30c;
struct Struct_ov004_0215c30c_2;
extern "C" void func_ov023_021f67ac(struct Struct_ov004_0215c30c* arg0, struct Struct_ov004_0215c30c_2* arg1);

static inline char* GetPairTable(GameResources* res, int index) { return res->vramStates_ + index * 0x70; }

struct Struct_ov004_0215c30c_3 {
    int unknown_0_[0xac / 4];
};

// USA: func_ov004_0215c30c
extern "C" ARM int func_ov004_0215c30c(void* arg0) {
    void* var0 = func_ov011_021845f8((unsigned char*)arg0, (int)6);
    if (var0 == 0) return 0;

    ((SafeAllocator*)((char*)var0 + 4))->GetSizeWithLargestBlockRemoved();
    void* var1 = ((SafeAllocator*)((char*)var0 + 4))->Allocate(0xac);
    if (var1 == 0) return 0;

    Struct_ov004_0215c30c_3 var2;
    func_ov004_0215c448(&var2);
    memcpy(var1, &var2, sizeof(var2));

    if (func_ov023_021f6f20(var1, (int)arg0, 0x6a4, 6, 0, 0) == 0) {
        int var3 = 0;
        func_ov004_0215c474(&var2);
        return var3;
    }

    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = LoadFileIntoMemory("data/menu/dqa_rox.spr", g_fileLoadBuffer, &size);
    char* pairs = GetPairTable(GetGameResources(), 0);
    void* model = AddOffset20_021f7318(block);
    VramState_Rewind((struct Foo0207df50*)pairs);
    VramState_Restore(pairs);
    SprSprite_Init(model);
    if (file != 0) {
        SprSprite_LoadFile(model, (int)file, size, (int)((char*)node + 4));
    }
    VramState_Save(pairs);
    BackgroundLoader::RemoveLockGlobal();
    func_ov023_021f7320(var1);
    func_ov023_021f67ac((struct Struct_ov004_0215c30c*)func_ov011_021849c8(arg0), (struct Struct_ov004_0215c30c_2*)var1);

    int var8 = 0;
    func_ov004_0215c474(&var2);
    return var8;
}

struct Struct_0204719c;
extern "C" void func_02048080(struct Struct_0204719c* arg0);
extern int data_ov023_021fe3e4;

// USA: func_ov004_0215c448  (semantic: InitStructVtableAndClear_0215c448)
extern "C" ARM void* func_ov004_0215c448(void* obj) {
    NameTable02048080* names = (NameTable02048080*)((char*)obj + 0x34);
    void* model = (char*)obj + 0x20;
    *(void**)obj = &data_ov023_021fe3e4;
    ClearNameTable(names);
    SprSprite_Init(model);
	return obj;
}

struct Foo02048004;
void SprSprite_Unload(struct Foo02048004* obj);

// USA: func_ov004_0215c474  (semantic: InvokeAndClearNameTable_0215c474)
extern "C" ARM void* func_ov004_0215c474(void* self) {
    SprSprite_Unload((struct Foo02048004*)((int)self + 0x20));
    ClearNameTable((struct NameTable02048080*)((int)self + 0x34));
    return self;
}

// USA: func_ov004_0215c494
extern "C" ARM int func_ov004_0215c494(void* arg0) {
    int var0 = func_ov004_02156e2c(arg0, 0x5b);
    if (var0 < 0) {
        return 0;
    }
    void* var1 = func_ov004_021570a4(arg0, (unsigned char)var0);
    if (!var1) {
        return 0;
    }
    unsigned char var2 = data_ov004_021707e0[0x11];
    data_ov004_021707e0[0x11] = 1;
    if (data_ov004_021707e0[0x11] < var2) {
        func_ov023_021f66bc(arg0, 0x25c, (void*)1);
    }
    func_ov004_02159384(arg0);
    return 0;
}

struct Struct_ov004_0215c50c { short unknown_0_; short unknown_2_; int unknown_4_; };

// USA: func_ov004_0215c50c
extern "C" ARM int func_ov004_0215c50c(void* arg0) {
    int var0 = func_ov004_02156e2c(arg0, 0x5b);
    if (var0 < 0) return 0;

    Struct_ov004_0215c50c* var1 = (Struct_ov004_0215c50c*)func_ov004_021570a4(arg0, (unsigned char)var0);
    if (!var1) return 0;

    unsigned char var2 = data_ov004_021707e0[0x11];
    data_ov004_021707e0[0x11] = (unsigned char)((unsigned int)(var1->unknown_4_ << 25) >> 25);

    void* ptr2a04 = GameState_GetParty(GameState::GetInstance());
    unsigned int hi = (unsigned int)entry->field4 >> 7;
    unsigned int product = data_ov004_021707e0[0x11] * hi;
    int f6c = *(int*)((char*)ptr2a04 + 0xf6c);
    if ((unsigned int)f6c < product) {
        unsigned int q = (unsigned int)f6c / hi;
        data_ov004_021707e0[0x11] = (unsigned char)q;
        if (data_ov004_021707e0[0x11] < 1) data_ov004_021707e0[0x11] = 1;
    }

    int var8 = func_ov004_02156fd4(arg0, 5);
    if (!var8) return 0;

    short shortE = *(short*)(data_ov004_021707e0 + 0xe);
    Element020de650* elem = ItemTable_Find((ItemTable*)contPtr, shortE);
    if (!elem) return 0;

    int var11 = *(int*)((char*)var10 + 8);
    int var12 = func_ov004_0215799c(var3, var1->unknown_0_, (unsigned int)(var11 << 28) >> 28, *(short*)(data_ov004_021707e0 + 0x3a));

    if (data_ov004_021707e0[0x11] >= (unsigned int)var12) {
        data_ov004_021707e0[0x11] = (unsigned char)var12;
        if (data_ov004_021707e0[0x11] < 1) data_ov004_021707e0[0x11] = 1;
    }

    if (data_ov004_021707e0[0x11] == 0) data_ov004_021707e0[0x11] = 1;

    if (var2 < data_ov004_021707e0[0x11]) {
        func_ov023_021f66bc(arg0, 0x25b, (void*)1);
    }

    func_ov004_02159384(arg0);
    return 0;
}

typedef void (*Type_01ff8b48_14)(void*, int);
struct Struct_ov004_0215c684 { char unknown_0_[0xe0]; Type_01ff8b48_14 unknown_e0_; };
struct Struct_ov004_0215c684_2 { Struct_ov004_0215c684* unknown_0_; };

// USA: func_ov004_0215c684
extern "C" ARM int func_ov004_0215c684(void* arg0) {
    if (data_ov004_021707e0[0x6e] > 1) {
        data_ov004_021707e0[0x6e] = 1;
        Struct_ov004_0215c684_2* var0 = ((Struct_ov004_0215c684_2*)func_ov004_02156f38(arg0, 0x25a));
        if (var0) {
            var0->unknown_0_->unknown_e0_(var0, data_ov004_021707e0[0x6e]);
        }
        int var1 = ((int)func_ov004_02156f6c(arg0, 0x19));
        if (var1) {
            func_ov023_021f809c((void*)var1, arg0);
        }
    }
    return 0;
}

typedef void (*Type_01ff8b48_15)(void*, int);
struct Struct_ov004_0215c6fc { char unknown_0_[0xe0]; Type_01ff8b48_15 unknown_e0_; };
struct Struct_ov004_0215c6fc_2 { Struct_ov004_0215c6fc* unknown_0_; };

// USA: func_ov004_0215c6fc
extern "C" ARM int func_ov004_0215c6fc(void* arg0) {
    if (data_ov004_021707e0[0x6e] < data_ov004_021707e0[0x6f]) {
        data_ov004_021707e0[0x6e] = data_ov004_021707e0[0x6f];
        Struct_ov004_0215c6fc_2* var0 = ((Struct_ov004_0215c6fc_2*)func_ov004_02156f38(arg0, 0x25a));
        if (var0) {
            var0->unknown_0_->unknown_e0_(var0, data_ov004_021707e0[0x6e]);
        }
        int var1 = ((int)func_ov004_02156f6c(arg0, 0x19));
        if (var1) {
            func_ov023_021f809c((void*)var1, arg0);
        }
    }
    return 0;
}

struct Struct_ov004_0215c774 {
    unsigned int unknown_0_;
    SafeAllocator unknown_4_;
};

struct Struct_ov004_0215c30c_2 {
    char unknown_0_[6];
    unsigned short unknown_6_;
    char unknown_8_[12];
    Struct_ov004_0215c30c_2* unknown_14_;
    Struct_ov004_0215c30c_2* unknown_18_;
};

struct Struct_ov004_0215c774_2 {
    Struct_ov004_0215c30c_2 unknown_0_;
    char unknown_1c_[0x90];
};

struct Struct_ov004_0215c774_3 {
    unsigned int unknown_0_;
    char unknown_4_[0x70];
};

struct Struct_ov004_0215c774_4 {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};
extern "C" void* func_ov004_0215c448(void*);
extern "C" void* func_ov004_0215c474(void*);
extern "C" int func_ov023_021f6f20(void*, int, int, int, int, unsigned int);
extern "C" void* ExtractFileFromGP2(const char*, const char*, unsigned int*);
void* AddOffset20_021f7318(void*);
PairTableNode0215c774* FindNodeById0218466c(void*, unsigned short);
void VramState_Restore(char*);
extern "C" void SprSprite_Init(void*);
void SprSprite_LoadFile(void*, int, int, int);
void VramState_Save(char*);
void SetField1cTo2_021f7320(void*);
void AppendNodeToList_021f67ac(ListHead_021f67ac*, ListNode_021f67ac*);

// USA: func_ov004_0215c774
extern "C" ARM int func_ov004_0215c774(void* arg0) {
    Struct_ov004_0215c774* var0 = ((Struct_ov004_0215c774*)func_ov011_021845f8((unsigned char*)arg0, (int)10));
    if (var0 == 0) return 0;
    var0->unknown_4_.GetSizeWithLargestBlockRemoved();
    Struct_ov004_0215c774_2* var1 = (Struct_ov004_0215c774_2*)var0->unknown_4_.Allocate(sizeof(Struct_ov004_0215c774_2));
    if (var1 == 0) return 0;
    Struct_ov004_0215c774_2 var2;
    func_ov004_0215c448(&var2);
    memcpy(var1, &var2, sizeof(var2));
    if (func_ov023_021f6f20(var1, (int)arg0, 0x640, 10, 0, 0) == 0) {
#if defined(jpn)
        int var3 = 0;
        func_ov004_0215c474(&var2);
        return var3;
#else
        func_ov004_0215c474(&var2);
        return 0;
#endif
    }
#if defined(jpn)
    char var4[32];
    __clear(var4, (unsigned int)(sizeof(var4)));
    sprintf(var4, "data/menu/dqa_%02d.spr", ((Struct_ov004_0215c774_4*)data_ov004_021707e0)->unknown_19_4_);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = LoadFileIntoMemory(path, g_fileLoadBuffer, &size);
#else
    char var5[32];
    char var6[32];
    __clear(var5, (unsigned int)(sizeof(var5)));
    __clear(var6, (unsigned int)(sizeof(var6)));
    sprintf(var5, "data/menu/dqa_%02d.gp2", ((Struct_ov004_0215c774_4*)data_ov004_021707e0)->unknown_19_4_);
    sprintf(var6, "dqa_%02d_<LG>.spr", ((Struct_ov004_0215c774_4*)data_ov004_021707e0)->unknown_19_4_);
    BackgroundLoader::AddLockGlobal();
    unsigned int var7;
    void* var8 = ExtractFileFromGP2(var5, var6, &var7);
#endif
    void* model = AddOffset20_021f7318(node);
    PairTableNode0215c774* pairs = FindNodeById0218466c(context, 0);
    char* tables = pairs->tables;
    VramState_Restore(tables);
    SprSprite_Init(model);
    if (file != 0) {
        SprSprite_LoadFile(model, (int)file, size, (int)&owner->allocator);
    }
    VramState_Save(tables);
    BackgroundLoader::RemoveLockGlobal();
    func_ov023_021f7320(var1);
    func_ov023_021f67ac(((Struct_ov004_0215c30c*)func_ov011_021849c8(arg0)), &var1->unknown_0_);
#if defined(jpn)
    int var12 = 0;
    func_ov004_0215c474(&var2);
    return var12;
#else
    func_ov004_0215c474(&var2);
    return 0;
#endif
}

struct Struct_01ff8b48_18 {
    short unknown_0_;
    unsigned short unknown_2_;
    unsigned int unknown_4_0_ : 7;
    unsigned int unknown_4_7_ : 25;
    unsigned char unknown_8_[0x20];
};

struct Struct_ov004_0215c900 {
    short unknown_0_;
    unsigned short unknown_2_;
    Struct_01ff8b48_18 unknown_4_[6];
    Struct_ov004_021589e8 unknown_f4_;
    short unknown_f8_;
    unsigned short unknown_fa_;
    unsigned short unknown_fc_;
    unsigned short unknown_fe_;
    Struct_ov004_021589e8 unknown_100_;
    Struct_ov004_021589e8 unknown_104_;
    unsigned int unknown_108_;
    unsigned short unknown_10c_0_ : 13;
    unsigned short unknown_10d_5_ : 3;
    unsigned short unknown_10e_;
};

// USA: func_ov004_0215c900
extern "C" ARM int func_ov004_0215c900(void* arg0) {
#if defined(jpn)
    const Struct_ov004_0215c900* var0 = (const Struct_ov004_0215c900*)((const char*)GameState::GetInstance() + 0x5c0c);
#else
    const Struct_ov004_0215c900* var0 = (const Struct_ov004_0215c900*)((const char*)GameState::GetInstance() + 0x5e6c);
#endif
    if (var0->unknown_10c_0_ & 0x20) {
        func_ov011_021848a0(arg0, 2);
    } else {
        func_ov011_021848a0(arg0, 1);
    }
    return 0;
}

// USA: func_ov004_0215c948
extern "C" ARM int func_ov004_0215c948(int arg0) {
	func_ov011_021848a0((void*)arg0, 0x384);
	return 0;
}

// USA: func_ov004_0215c95c
extern "C" ARM int func_ov004_0215c95c(void* arg0) {
    func_ov011_021848a0(arg0, 0x395);
    return 0;
}
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" int func_020aad1c(void* loader, void* name, int a, int b);
extern "C" int func_ov004_0215b1d4(void* obj);
void* GetOffsetPtrromField_021b1fc0_021b1fc0(void* obj);
struct Obj_02184534;
void SetFieldsB0B4_02184534(struct Obj_02184534* obj, int b0, int b4);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif

struct Struct_ov004_0215c974_2 { unsigned char unknown_0_0_ : 7; unsigned char unknown_0_7_ : 1; };

#if defined(jpn)
enum { Enum_ov004_0215c974_12 = 0xc, Enum_ov004_0215c974_15176 = 0x3928, Enum_ov004_0215c974_92 = 0x28, Enum_ov004_0215c974_2400 = 0x800, Enum_ov004_0215c974_2456 = 0x868 };
#else
enum { Enum_ov004_0215c974_620 = 0x26c, Enum_ov004_0215c974_15176 = 0x3b48, Enum_ov004_0215c974_92 = 0x5c, Enum_ov004_0215c974_2400 = 0x960, Enum_ov004_0215c974_2456 = 0x998 };
#endif

// USA: func_ov004_0215c974
extern "C" ARM int func_ov004_0215c974(void* arg0) {
    void* var0;
    bool var1;
    char* var2;
    int var3;
    char* var4;
    struct Struct_02072a68_2* var5;
    const char* var6;
    int var7;
    char* var8;
    char* var9;
    int var10;

    func_ov023_021f6600(arg0, 0x36, 8);

    data = GlobalFlags_GetInstance();
    FlagWord_SetBits((unsigned int*)data, 0x80);

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    queued = func_020aad1c(data_ov004_021707e0 + 0x84, g_fileLoadBuffer, 0xa, 0) != 0;
    BackgroundLoader::RemoveLockGlobal();
    if (!var1) return 1;

    FlagWord_ClearBits((struct FlagWord020466f4*)data, 0x80);

    func_ov023_021f65d4(arg0, 0x36, 8);

    g = MessageSystem_GetInstance();
    cur = *(char**)((char*)g + messageBufferOffset_0215c974);
    memset(cur, 0, messageBufferSize_0215c974);

#if defined(jpn)
    GameState* var11 = GameState::GetInstance();
    var2 = (char*)var11 + Enum_ov004_0215c974_12;
    int* var12 = (int*)((char*)var11 + 0x6120);
#else
    var2 = (char*)GameState::GetInstance() + Enum_ov004_0215c974_620;
#endif
    var5 = (struct Struct_02072a68_2*)func_ov004_02157018(arg0, 4);

    var6 = (const char*)func_02072a68(var5, 0x21);
    var7 = strlen(var6);
    memcpy(var4, var6, var7);
    var4 += var7;

    if (data_ov004_021707e0[0x15] != 0) {
        func_ov004_0215b1d4(obj);
        void* q = Zone3D_GetInstance();
        Bits7_0215c974* b = (Bits7_0215c974*)((char*)(*(void**)((char*)q + 8)) + 0xd);
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)g_bgmPlayer, b->low7);
        SetModeClamped0209ca70(g_bgmPlayer, data_ov004_021707e0[0x2d]);
    } else if (data_ov004_021707e0[0x14] != 0) {
        void* var15 = GetGameResources();
        void* var16 = *(void**)((char*)var15 + Enum_ov004_0215c974_15176);
        var8 = (char*)func_ov017_021b1fc0(var16);
        var9 = *(char**)((char*)var16 + 0x34);

        for (var10 = 0; var10 < 4; var10++) {
            if (strstr((char*)var8 + 0x88, "info")) {
                func_ov011_02184534((struct Struct_ov004_0215c974*)arg0, (int)var9, *(int*)((char*)var8 + 0xac));
                break;
            }
            var9 += *(int*)((char*)var8 + 0xac);
            var8 += 0xb0;
        }

        if (var10 != 4) {
            func_ov011_021848a0(arg0, 0x394);
        } else {
            func_ov011_021848a0(arg0, 0x3ad);
        }

        int var17 = *(unsigned short*)(var2 + 0x5d00 + 0xc);
        var17 = var17 << 0x13;
        var17 = (unsigned)var17 >> 0x13;
        if (var17 & 0x40) {
            const char* var18 = (const char*)func_02072a68(var5, 0x1c);
            int var19 = strlen(var18);
            memcpy(var4, var18, var19);
            var4 += var19;
        }
#if defined(jpn)
        int var20 = (var12[0x50 / 4] & 1) != 0;
        if (data_ov004_021707e0[0x2f] != var20) {
            const char* var21;
            if (var20) {
                var21 = (const char*)func_02072a68(var5, 0x1d);
            } else {
                var21 = (const char*)func_02072a68(var5, 0x1e);
            }
            int var22 = strlen(var21);
            memcpy(var4, var21, var22);
            var4 += var22;
        }
#endif
        var17 = *(unsigned short*)(var2 + 0x5d00 + 0xc);
        var17 = var17 << 0x13;
        var17 = (unsigned)var17 >> 0x13;
        if (var17 & 0x200) {
            const char* var23 = (const char*)func_02072a68(var5, 0x1f);
            memcpy(var4, var23, strlen(var23));
        }
    }

#if defined(jpn)
    func_0204500c((void*)var3, *(char**)((char*)var3 + Enum_ov004_0215c974_92), 0);
#else
    func_0204500c((void*)var3, *(char**)((char*)var3 + Enum_ov004_0215c974_92), 0, 0xe3);
#endif
    *(int*)((char*)var3 + Enum_ov004_0215c974_2456) = 1;
    return 0;
}

// USA: func_ov004_0215cbec
extern "C" ARM int func_ov004_0215cbec(void* arg0) {
    func_ov023_021f65d4(arg0, 2, 8);
    func_ov011_021848a0(arg0, 0x68);
    return 0;
}

// USA: func_ov004_0215cc14
extern "C" ARM int func_ov004_0215cc14(void* arg0) {
    func_ov023_021f65d4(arg0, 2, 8);
    func_ov011_021848a0(arg0, 0x396);
    return 0;
}

// USA: func_ov004_0215cc40
extern "C" ARM int func_ov004_0215cc40(void* arg0) {
    func_ov011_021848a0(arg0, 0x3b1);
    return 0;
}

extern "C" void func_ov004_021578a8(void* arg0);

// USA: func_ov004_0215cc58
extern "C" ARM int func_ov004_0215cc58(void* arg0) {
	if (data_ov004_021707e0[0x3e] < 6) {
		data_ov004_021707e0[0x3e]++;
	}
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215cc84
extern "C" ARM int func_ov004_0215cc84(void* arg0) {
	if (data_ov004_021707e0[0x3e] != 0) {
		data_ov004_021707e0[0x3e]--;
	}
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215ccb0
extern "C" ARM int func_ov004_0215ccb0(void* arg0) {
	((char*)data_ov004_021707e0)[0x3e] = 0;
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215ccd4
extern "C" ARM int func_ov004_0215ccd4(void* arg0) {
	((char*)data_ov004_021707e0)[0x3e] = 1;
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215ccf8
extern "C" ARM int func_ov004_0215ccf8(void* arg0) {
	((char*)data_ov004_021707e0)[0x3e] = 2;
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215cd1c
extern "C" ARM int func_ov004_0215cd1c(void* arg0) {
	((char*)data_ov004_021707e0)[0x3e] = 3;
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215cd40
extern "C" ARM int func_ov004_0215cd40(void* arg0) {
	((char*)data_ov004_021707e0)[0x3e] = 4;
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215cd64
extern "C" ARM int func_ov004_0215cd64(void* arg0) {
	((char*)data_ov004_021707e0)[0x3e] = 5;
	func_ov004_021578a8(arg0);
	return 0;
}

// USA: func_ov004_0215cd88
extern "C" ARM int func_ov004_0215cd88(void* arg0) {
	((char*)data_ov004_021707e0)[0x3e] = 6;
	func_ov004_021578a8(arg0);
	return 0;
}

struct Struct_ov004_0215cdac { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; };
extern "C" int func_ov004_02158fec(void*);

// USA: func_ov004_0215cdac
extern "C" ARM int func_ov004_0215cdac(void* arg0) {
    Struct_ov004_0215cdac* var0 = ((Struct_ov004_0215cdac*)func_ov004_02156ed0(arg0, 0x5b));
    short var1 = var0->unknown_5c_;
    short var2 = var0->unknown_5e_;
    short var3 = var1 + 1;
    if (var2 <= var3) var3 = 0;
    var0->unknown_5c_ = var3;
    var0->unknown_5e_ = var2;
    func_ov004_02158fec(arg0);
    return 0;
}

struct Struct_ov004_0215cdf0 { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; };

// USA: func_ov004_0215cdf0
extern "C" ARM int func_ov004_0215cdf0(void* arg0) {
    Struct_ov004_0215cdf0* var0 = ((Struct_ov004_0215cdf0*)func_ov004_02156ed0(arg0, 0x5b));
    short var1 = var0->unknown_5c_;
    short var2 = var0->unknown_5e_;
    short var3 = var1 - 1;
    if (var3 < 0) var3 = var2 - 1;
    var0->unknown_5c_ = var3;
    var0->unknown_5e_ = var2;
    func_ov004_02158fec(arg0);
    return 0;
}

struct Struct_ov004_0215ce38 { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; };
extern "C" int func_ov004_0215a738(void*);

// USA: func_ov004_0215ce38
extern "C" ARM int func_ov004_0215ce38(void* arg0) {
    Struct_ov004_0215ce38* var0 = ((Struct_ov004_0215ce38*)func_ov004_02156ed0(arg0, 0x63));
    short var1 = var0->unknown_5c_;
    short var2 = var0->unknown_5e_;
    short var3 = var1 + 1;
    if (var2 <= var3) var3 = 0;
    var0->unknown_5c_ = var3;
    var0->unknown_5e_ = var2;
    func_ov004_0215a738(arg0);
    return 0;
}

struct Struct_ov004_0215ce7c { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; };

// USA: func_ov004_0215ce7c
extern "C" ARM int func_ov004_0215ce7c(void* arg0) {
    Struct_ov004_0215ce7c* var0 = ((Struct_ov004_0215ce7c*)func_ov004_02156ed0(arg0, 0x63));
    short var1 = var0->unknown_5c_;
    short var2 = var0->unknown_5e_;
    short var3 = var1 - 1;
    if (var3 < 0) var3 = var2 - 1;
    var0->unknown_5c_ = var3;
    var0->unknown_5e_ = var2;
    func_ov004_0215a738(arg0);
    return 0;
}

struct Struct_ov004_0215cec4 { char unknown_0_[0x32]; short unknown_32_[4]; short unknown_3a_; };

struct Struct_ov004_0216fb70 { int unknown_0_[4]; };
extern Struct_ov004_0216fb70 data_ov004_0216fb70;
struct Struct_ov004_0215cec4_2 { short unknown_0_; };
struct Struct_ov004_0215cec4_3 { char unknown_0_[8]; unsigned int unknown_8_0_ : 4; };
extern "C" int func_020dd718(int arg0, int arg1);

typedef void (*Type_01ff8b48_16)(void*, int);
struct Struct_ov004_0215cec4_4 { char unknown_0_[0xe0]; Type_01ff8b48_16 unknown_e0_; };
struct Struct_ov004_0215cec4_5 { Struct_ov004_0215cec4_4* unknown_0_; };

typedef void (*Type_01ff8b48_17)(void*, int);
struct Struct_ov004_0215cec4_6 { char unknown_0_[0xd8]; Type_01ff8b48_17 unknown_d8_; };
struct Struct_ov004_0215cec4_7 { Struct_ov004_0215cec4_6* unknown_0_; };

class Struct_ov004_0215cec4_8 {
public:
    virtual void inline_ov004_0215cec4(); virtual void inline_ov004_0215cec4_2(); virtual void inline_ov004_0215cec4_3(); virtual void inline_ov004_0215cec4_4();
    virtual void inline_ov004_0215cec4_5(); virtual void inline_ov004_0215cec4_6(); virtual void inline_ov004_0215cec4_7(); virtual void inline_ov004_0215cec4_8();
    virtual void inline_ov004_0215cec4_9(); virtual void inline_ov004_0215cec4_10(); virtual void inline_ov004_0215cec4_11(); virtual void inline_ov004_0215cec4_12();
    virtual void inline_ov004_0215cec4_13(); virtual void inline_ov004_0215cec4_14(); virtual void inline_ov004_0215cec4_15(); virtual void inline_ov004_0215cec4_16();
    virtual void inline_ov004_0215cec4_17(); virtual void inline_ov004_0215cec4_18(); virtual void inline_ov004_0215cec4_19(); virtual void inline_ov004_0215cec4_20();
    virtual void inline_ov004_0215cec4_21(); virtual void inline_ov004_0215cec4_22(); virtual void inline_ov004_0215cec4_23(); virtual void inline_ov004_0215cec4_24();
    virtual void inline_ov004_0215cec4_25(); virtual void inline_ov004_0215cec4_26(); virtual void inline_ov004_0215cec4_27(); virtual void inline_ov004_0215cec4_28();
    virtual void inline_ov004_0215cec4_29(); virtual void inline_ov004_0215cec4_30(); virtual void inline_ov004_0215cec4_31(); virtual void inline_ov004_0215cec4_32();
    virtual void inline_ov004_0215cec4_33(); virtual void inline_ov004_0215cec4_34(); virtual void inline_ov004_0215cec4_35(); virtual void inline_ov004_0215cec4_36();
    virtual void inline_ov004_0215cec4_37(); virtual void inline_ov004_0215cec4_38(); virtual void inline_ov004_0215cec4_39(); virtual void inline_ov004_0215cec4_40();
    virtual void inline_ov004_0215cec4_41(); virtual void inline_ov004_0215cec4_42(); virtual void inline_ov004_0215cec4_43(); virtual void inline_ov004_0215cec4_44();
    virtual void inline_ov004_0215cec4_45(); virtual void inline_ov004_0215cec4_46(); virtual void inline_ov004_0215cec4_47(); virtual void inline_ov004_0215cec4_48();
    virtual void inline_ov004_0215cec4_49(); virtual void inline_ov004_0215cec4_50(); virtual void inline_ov004_0215cec4_51(); virtual void inline_ov004_0215cec4_52();
    virtual void inline_ov004_0215cec4_53(); virtual void inline_ov004_0215cec4_54();
    virtual void inline_ov004_0215cec4_55(int arg0);
    char unknown_4_[0x1c];
    BaseCombatStats* unknown_20_;
};
struct Struct_ov004_0215cec4_9 { char unknown_0_[0x38]; short unknown_38_; };

// USA: func_ov004_0215cec4
extern "C" ARM int func_ov004_0215cec4(void* a) {
    GameState* bs = GameState::GetInstance();
    int key = DispatchNodeIfType7_02156e2c(a, 0x5b);
    if (key < 0) return 0;
    Entry_0215cec4* entry = ((Entry_0215cec4*)GetEntryFor_021570a4(a, key & 0xff));
    if (!entry) return 0;
    ItemTable* node = ((ItemTable*)func_ov004_02156fd4(a, 5));
    if (!node) return 0;
    Element020de650_0215cec4* elem = ((Element020de650_0215cec4*)ItemTable_Find(node, entry->key));
    if (!elem) return 0;

    Struct_020dd7ac var5;
    func_020dd7ac(&var5);
    int var6 = 1;
    if (var4->unknown_8_0_ != 0) var6 = 3;

    Struct_ov004_0215cec4_9* var7 = (Struct_ov004_0215cec4_9*)func_ov004_02156f04(arg0, 0x1d6);
    if (var7) var7->unknown_38_ = var6 + 0xb;

    Struct_ov004_0216fb70 var8 = data_ov004_0216fb70;
    int var9;
    int var10;
    Struct_ov004_0215cec4* var11 = (Struct_ov004_0215cec4*)data_ov004_021707e0;
    var9 = var11->unknown_3a_;
    for (var10 = 0; var10 < var9; var10++) {
        var8.unknown_0_[var10] = var11->unknown_32_[var10];
    }

    for (unsigned char var12 = 0; var12 < 4; var12++) {
        int var13 = var8.unknown_0_[var12];
        GameObject* var14 = var0->GetPartyMemberByIndex(var13);
        if (var14) {
            Struct_ov004_0215cec4_8* var15 = (Struct_ov004_0215cec4_8*)func_ov004_02156f04(arg0, var12 + 0x1c2);
            if (!var15) return 0;
            var15->unknown_20_ = var14->baseStats_;
            var15->inline_ov004_0215cec4_55(func_020dcc98(var8.unknown_0_[var12]));
            if (func_020dd718((signed char)var8.unknown_0_[var12], var2->unknown_0_)) {
                func_ov023_021f65d4(arg0, var12 + 0x1c6, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1ce, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1ca, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1d2, 8);
                func_ov023_021f6600(arg0, var12 + 0x1d7, 8);
            } else if (func_020dd4c4((signed char)var13, (Struct_020dd4c4_3*)var4)) {
                func_ov023_021f65d4(arg0, var12 + 0x1c6, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1ce, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1ca, 8);
                func_ov023_021f6600(arg0, var12 + 0x1d2, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1d7, 8);
            } else {
                func_ov023_021f6600(arg0, var12 + 0x1c6, 8);
                func_ov023_021f6600(arg0, var12 + 0x1ce, 8);
                func_ov023_021f6600(arg0, var12 + 0x1ca, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1d2, 8);
                func_ov023_021f65d4(arg0, var12 + 0x1d7, 8);

                func_020dd7ac(&var5);
                unsigned short var16, var17;
                if (var4->unknown_8_0_ == 0) {
                    func_020ddaf4((int)&var5, var13, (int)var4, 0, (int)&var16, (int)&var17);
                } else {
                    func_020ddaf4((int)&var5, var13, (int)var4, 1, (int)&var16, (int)&var17);
                }

                Struct_ov004_0215cec4_5* var18 = (Struct_ov004_0215cec4_5*)func_ov004_02156f38(arg0, var12 + 0x1c6);
                if (var18) var18->unknown_0_->unknown_e0_(var18, var16);
                Struct_ov004_0215cec4_5* var19 = (Struct_ov004_0215cec4_5*)func_ov004_02156f38(arg0, var12 + 0x1ca);
                if (var19) var19->unknown_0_->unknown_e0_(var19, var17);

                Struct_ov004_0215cec4_7* var20 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), var12 + 0x1c6);
                if (var20) var20->unknown_0_->unknown_d8_(var20, 0xf);

                if (var16 == var17) {
                    Struct_ov004_0215cec4_7* var21 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), var12 + 0x1ca);
                    if (var21) var21->unknown_0_->unknown_d8_(var21, 0xf);
                } else if (var16 < var17) {
                    Struct_ov004_0215cec4_7* var22 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), var12 + 0x1ca);
                    if (var22) var22->unknown_0_->unknown_d8_(var22, 5);
                } else {
                    Struct_ov004_0215cec4_7* var23 = (Struct_ov004_0215cec4_7*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), var12 + 0x1ca);
                    if (var23) var23->unknown_0_->unknown_d8_(var23, 9);
                }
            }
        } else {
            func_ov023_021f65d4(arg0, var12 + 0x1c2, 8);
            func_ov023_021f65d4(arg0, var12 + 0x1c6, 8);
            func_ov023_021f65d4(arg0, var12 + 0x1ce, 8);
            func_ov023_021f65d4(arg0, var12 + 0x1ca, 8);
            func_ov023_021f65d4(arg0, var12 + 0x1d2, 8);
            func_ov023_021f65d4(arg0, var12 + 0x1d7, 8);
        }
    }

    void* var24 = func_ov004_02156f6c(arg0, 0x17);
    if (var24) func_ov023_021f809c(var24, arg0);
    return 0;
}
struct Obj02086aec;
short Party_CountItem(struct Obj02086aec* obj, int key);
int ScaleStatsIfType12_021f6f10(void*);
struct Struct0200fb08;
unsigned char GameState_GetLanguage(struct Struct0200fb08*);

struct Struct_ov004_0215d384 { int unknown_0_; int unknown_4_; int unknown_8_; };

class Struct_ov004_0215d384_2 {
public:
    virtual void inline_ov004_0215d384(); virtual void inline_ov004_0215d384_2(); virtual void inline_ov004_0215d384_3(); virtual void inline_ov004_0215d384_4();
    virtual void inline_ov004_0215d384_5(); virtual void inline_ov004_0215d384_6(); virtual void inline_ov004_0215d384_7(); virtual void inline_ov004_0215d384_8();
    virtual void inline_ov004_0215d384_9(); virtual void inline_ov004_0215d384_10(); virtual void inline_ov004_0215d384_11(); virtual void inline_ov004_0215d384_12();
    virtual void inline_ov004_0215d384_13(); virtual void inline_ov004_0215d384_14(); virtual void inline_ov004_0215d384_15(); virtual void inline_ov004_0215d384_16();
    virtual void inline_ov004_0215d384_17(); virtual void inline_ov004_0215d384_18(); virtual void inline_ov004_0215d384_19(); virtual void inline_ov004_0215d384_20();
    virtual void inline_ov004_0215d384_21(); virtual void inline_ov004_0215d384_22(); virtual void inline_ov004_0215d384_23(); virtual void inline_ov004_0215d384_24();
    virtual void inline_ov004_0215d384_25(); virtual void inline_ov004_0215d384_26(); virtual void inline_ov004_0215d384_27(); virtual void inline_ov004_0215d384_28();
    virtual void inline_ov004_0215d384_29(); virtual void inline_ov004_0215d384_30(); virtual void inline_ov004_0215d384_31(); virtual void inline_ov004_0215d384_32();
    virtual void inline_ov004_0215d384_33(); virtual void inline_ov004_0215d384_34(); virtual void inline_ov004_0215d384_35(); virtual void inline_ov004_0215d384_36();
    virtual void inline_ov004_0215d384_37(); virtual void inline_ov004_0215d384_38(); virtual void inline_ov004_0215d384_39(); virtual void inline_ov004_0215d384_40();
    virtual void inline_ov004_0215d384_41(); virtual void inline_ov004_0215d384_42(); virtual void inline_ov004_0215d384_43(); virtual void inline_ov004_0215d384_44();
    virtual void inline_ov004_0215d384_45(); virtual void inline_ov004_0215d384_46(); virtual void inline_ov004_0215d384_47(); virtual void inline_ov004_0215d384_48();
    virtual void inline_ov004_0215d384_49(); virtual void inline_ov004_0215d384_50(); virtual void inline_ov004_0215d384_51(); virtual void inline_ov004_0215d384_52();
    virtual void inline_ov004_0215d384_53(); virtual void inline_ov004_0215d384_54(); virtual void inline_ov004_0215d384_55(); virtual void inline_ov004_0215d384_56();
    virtual void inline_ov004_0215d384_57(int arg0);
};

class Struct_ov004_0215d384_3 {
public:
    virtual void inline_ov004_0215d384_58(); virtual void inline_ov004_0215d384_59(); virtual void inline_ov004_0215d384_60(); virtual void inline_ov004_0215d384_61();
    virtual void inline_ov004_0215d384_62(); virtual void inline_ov004_0215d384_63(); virtual void inline_ov004_0215d384_64();
    virtual void inline_ov004_0215d384_65(const Struct_ov004_0215d384& arg0);
};

// USA: func_ov004_0215d384
extern "C" ARM int func_ov004_0215d384(void* arg0) {
    GameState* var0 = GameState::GetInstance();
    int var1 = func_ov004_02156e2c(arg0, 0x5b);
    if (var1 < 0) return 0;
    void* var2 = func_ov004_021570a4(arg0, var1 & 0xff);
    if (!var2) return 0;
    Struct_ov004_0215d384_2* var3 = (Struct_ov004_0215d384_2*)func_ov004_02156f38(arg0, 0x1dc);
    if (!var3) return 0;

    int matches = Party_CountItem((struct Obj02086aec*)GameState_GetParty(bs), *(short*)entry);
    nodeA->MethodE0(matches);

    void* var5 = func_ov004_02156f6c(arg0, 0x1b);
    if (var5) func_ov023_021f809c(var5, arg0);

#if !defined(jpn)
    Struct_ov004_0215d384_3* var6 = (Struct_ov004_0215d384_3*)func_ov023_021f6880((void**)(func_ov011_021849c8(arg0)), 0x1dd);
    if (!var6) return 0;
    if (func_ov024_021f6f10(var6) != 8) return 0;

    Args0215d384 args;
    args.b = 0x4000;
    args.c = 0;
    int kind = ((int)GameState_GetLanguage((struct Struct0200fb08*)bs));
    switch (kind) {
    case 1: args.a = 0x14000; nodeB->Method1c(args); break;
    case 2: args.a = 0xe000; nodeB->Method1c(args); break;
    case 3: args.a = 0xb000; nodeB->Method1c(args); break;
    case 4: args.a = 0x6000; nodeB->Method1c(args); break;
    case 5: args.a = 0x9000; nodeB->Method1c(args); break;
    default: break;
    }
#endif
    return 0;
}

struct Struct_ov004_0215d534 { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; };
struct Struct_ov004_0215d534_2 { short unknown_0_; short unknown_2_; unsigned int unknown_4_0_ : 7; };
struct Struct_ov004_0215d534_3 { char unknown_0_[0x11]; unsigned char unknown_11_; };

struct Struct_0202b2f0;
extern "C" int func_ov004_02156e2c(void* arg0, int arg1);
extern "C" int func_ov004_0215c0c0(void* arg0);
extern "C" void func_ov017_021d3bbc(int arg0, int arg1, int arg2, int arg3);
extern "C" int func_0202c578(Struct_0202b2f0* arg0, int arg1);
extern "C" void func_ov011_02184a40(void* arg0, int arg1);

// USA: func_ov004_0215d534
extern "C" ARM int func_ov004_0215d534(void* arg0) {
#if defined(jpn)
 enum { Enum_ov004_0215d534_620 = 0xc };
#else
 enum { Enum_ov004_0215d534_620 = 0x26c };
#endif
    int var0 = func_ov004_02156e2c(arg0, 0x5b);
    if (var0 < 0) return 0;

    Struct_0202b2f0* var1 = ((Struct_0202b2f0*)func_0202ae18());
    if (!func_0202b7d8((int*)var1)) {
        func_ov004_0215c0c0(arg0);
    } else {
        int var2 = ((Struct_ov004_0215d534*)func_ov004_02156ed0(arg0, 0x5b))->unknown_5c_ * 6 + var0;
        Struct_ov004_0215d534_2* var3 = (Struct_ov004_0215d534_2*)func_ov004_021570a4(arg0, (unsigned char)var0);

        if (func_0202c508((Struct_0202c508*)var1)) {
            if (var3->unknown_4_0_ >= ((Struct_ov004_0215d534_3*)data_ov004_021707e0)->unknown_11_) {
                func_ov004_0215c0c0(arg0);
                func_ov017_021d3bbc(var2, ((Struct_ov004_0215d534_3*)data_ov004_021707e0)->unknown_11_, 1, 0);
            } else {
                func_ov011_021848a0(arg0, 0x2367);
            }
        } else if (!func_0202c578(var1, 0)) {
            char* var4 = (char*)GameState::GetInstance() + Enum_ov004_0215d534_620;
            *(unsigned short*)(var4 + 0x5d00 + 0xc) &= ~0xe000;
            func_ov017_021d3bbc(var2, ((Struct_ov004_0215d534_3*)data_ov004_021707e0)->unknown_11_, 3, 0);
            func_ov011_02184a40(arg0, 0x5c);
        } else {
            func_ov011_021848a0(arg0, 0x2369);
        }
    }
    return 0;
}

// USA: func_ov004_0215d670
extern "C" ARM int func_ov004_0215d670(void* arg0) {
#if defined(jpn)
 enum { Enum_ov004_0215d670_620 = 0xc };
#else
 enum { Enum_ov004_0215d670_620 = 0x26c };
#endif
    char* var0 = (char*)GameState::GetInstance() + Enum_ov004_0215d670_620;
    void* var1 = func_0202ae18();
    unsigned short var2 = *(unsigned short*)(var0 + 0x5d00 + 0xc);
    int var3 = (unsigned int)(var2 << 16) >> 29;
    if (var3 == 1) {
        func_ov004_0215c0c0(arg0);
        return 0;
    }
    if (var3 == 2) {
        func_ov011_021848a0(arg0, 0x2367);
        return 0;
    }
    if (!func_0202c578((struct Struct_0202b2f0*)var1, 0)) {
        return 1;
    }
    func_ov011_021848a0(arg0, 0x2369);
    return 0;
}

// USA: func_ov004_0215d6f8
extern "C" ARM int func_ov004_0215d6f8(void* arg0) {
    void* var0 = data_ov004_021707e0;
    if (*(unsigned char*)((char*)var0 + 0x11) == 1) {
        func_ov011_021848a0(arg0, 0x236a);
    } else {
        func_ov011_021848a0(arg0, 0x38a);
    }
    return 0;
}
extern "C" int func_02086c4c(unsigned char* arg0, int arg1, int arg2);
extern "C" short func_02086bf4(char* arg0, int arg1);

class Struct_ov004_0215d738 {
public:
    virtual void inline_ov004_0215d738(); virtual void inline_ov004_0215d738_2(); virtual void inline_ov004_0215d738_3(); virtual void inline_ov004_0215d738_4();
    virtual void inline_ov004_0215d738_5(); virtual void inline_ov004_0215d738_6(); virtual void inline_ov004_0215d738_7(); virtual void inline_ov004_0215d738_8();
    virtual void inline_ov004_0215d738_9(); virtual void inline_ov004_0215d738_10(); virtual void inline_ov004_0215d738_11(); virtual void inline_ov004_0215d738_12();
    virtual void inline_ov004_0215d738_13(); virtual void inline_ov004_0215d738_14(); virtual void inline_ov004_0215d738_15(); virtual void inline_ov004_0215d738_16();
    virtual void inline_ov004_0215d738_17(); virtual void inline_ov004_0215d738_18(); virtual void inline_ov004_0215d738_19(); virtual void inline_ov004_0215d738_20();
    virtual void inline_ov004_0215d738_21(); virtual void inline_ov004_0215d738_22(); virtual void inline_ov004_0215d738_23(); virtual void inline_ov004_0215d738_24();
    virtual void inline_ov004_0215d738_25(); virtual void inline_ov004_0215d738_26(); virtual void inline_ov004_0215d738_27(); virtual void inline_ov004_0215d738_28();
    virtual void inline_ov004_0215d738_29(); virtual void inline_ov004_0215d738_30(); virtual void inline_ov004_0215d738_31(); virtual void inline_ov004_0215d738_32();
    virtual void inline_ov004_0215d738_33(); virtual void inline_ov004_0215d738_34(); virtual void inline_ov004_0215d738_35(); virtual void inline_ov004_0215d738_36();
    virtual void inline_ov004_0215d738_37(); virtual void inline_ov004_0215d738_38(); virtual void inline_ov004_0215d738_39(); virtual void inline_ov004_0215d738_40();
    virtual void inline_ov004_0215d738_41(); virtual void inline_ov004_0215d738_42(); virtual void inline_ov004_0215d738_43(); virtual void inline_ov004_0215d738_44();
    virtual void inline_ov004_0215d738_45(); virtual void inline_ov004_0215d738_46(); virtual void inline_ov004_0215d738_47(); virtual void inline_ov004_0215d738_48();
    virtual void inline_ov004_0215d738_49(); virtual void inline_ov004_0215d738_50(); virtual void inline_ov004_0215d738_51(); virtual void inline_ov004_0215d738_52();
    virtual void inline_ov004_0215d738_53(); virtual void inline_ov004_0215d738_54();
    virtual void inline_ov004_0215d738_55(int arg0);
    virtual void inline_ov004_0215d738_56();
    virtual void inline_ov004_0215d738_57(int arg0);
};

struct Struct_ov004_0215d738_2 { void* unknown_0_; char unknown_4_[0x1c]; int unknown_20_; };

struct Struct_ov004_0215d738_3 { char unknown_0_[0x32]; short unknown_32_[4]; short unknown_3a_; };

struct Struct_ov004_0216fb80 { int unknown_0_[4]; };
extern const Struct_ov004_0216fb80 data_ov004_0216fb80;

// USA: func_ov004_0215d738
extern "C" ARM int func_ov004_0215d738(void* a) {
    GameState* bs = GameState::GetInstance();
    unsigned char* p = (unsigned char*)GameState_GetParty(bs);
    int idx = DispatchNodeIfType7_02156e2c(a, 0x5b);
    if (idx < 0) return 0;
    short* entry = (short*)GetEntryFor_021570a4(a, idx & 0xff);
    if (!entry) return 0;
    void* container = ((void*)func_ov004_02156fd4(a, 5));
    if (!container) return 0;
    if (!ItemTable_Find((struct ItemTable*)container, *entry)) return 0;

    int var5[4];
    *(Struct_ov004_0216fb80*)var5 = data_ov004_0216fb80;
    int var6;
    int var7;
    Struct_ov004_0215d738_3* var8 = (Struct_ov004_0215d738_3*)data_ov004_021707e0;
    var6 = var8->unknown_3a_;
    for (var7 = 0; var7 < var6; var7++) {
        var5[var7] = var8->unknown_32_[var7];
    }

    for (unsigned char var9 = 0; var9 < 5; var9++) {
        int var10 = var5[var9];
        GameObject* var11 = var0->GetPartyMemberByIndex(var10);
        if (var11) {
            Struct_ov004_0215d738_2* var12 = ((Struct_ov004_0215d738_2*)func_ov004_02156f04(arg0, var9 + 0x1df));
            if (!var12) return 0;
            var12->unknown_20_ = *(int*)((char*)var11 + 0x134);
            var10 = var5[var9];
            ((Struct_ov004_0215d738*)var12)->inline_ov004_0215d738_55(func_020dcc98((signed char)var10));
            int var13 = func_02086c4c(var1, var10, *var3);
            if (var13 == 0) {
                func_ov023_021f65d4(arg0, var9 + 0x1e4, 8);
                func_ov023_021f65d4(arg0, var9 + 0x1ee, 8);
                func_ov023_021f6600(arg0, var9 + 0x1e9, 8);
            } else {
                func_ov023_021f6600(arg0, var9 + 0x1e4, 8);
                func_ov023_021f6600(arg0, var9 + 0x1ee, 8);
                func_ov023_021f65d4(arg0, var9 + 0x1e9, 8);
                Struct_ov004_0215d738* var14 = ((Struct_ov004_0215d738*)func_ov004_02156f38(arg0, var9 + 0x1e4));
                if (var14) var14->inline_ov004_0215d738_57(var13);
            }
        } else if (var9 == var6) {
            func_ov023_021f6600(arg0, var9 + 0x1df, 8);
            func_ov023_021f6600(arg0, var9 + 0x1e4, 8);
            func_ov023_021f6600(arg0, var9 + 0x1ee, 8);
            func_ov023_021f65d4(arg0, var9 + 0x1e9, 8);
            int var15 = func_02086bf4((char*)var1, *var3);
            Struct_ov004_0215d738* var16 = ((Struct_ov004_0215d738*)func_ov004_02156f38(arg0, var9 + 0x1e4));
            if (var16) var16->inline_ov004_0215d738_57(var15);
        } else {
            func_ov023_021f65d4(arg0, var9 + 0x1df, 8);
            func_ov023_021f65d4(arg0, var9 + 0x1e4, 8);
            func_ov023_021f65d4(arg0, var9 + 0x1ee, 8);
            func_ov023_021f65d4(arg0, var9 + 0x1e9, 8);
        }
    }

    void* var17 = func_ov004_02156f6c(arg0, 0x1c);
    if (var17) func_ov023_021f809c(var17, arg0);
    return 0;
}
extern "C" void func_0207cf30(void*, int, int, int);

// USA: func_ov004_0215da0c
extern "C" ARM int func_ov004_0215da0c(void* obj) {
    void* p = GameState_GetParty(GameState::GetInstance());
    int result4 = SumKeyedLookups02086bf4((char*)p, *(short*)(data_ov004_021707e0 + 0xe));

#if !defined(jpn)
    unsigned char var2 = data_ov004_021707e0[0x9d];
    if (!var2) return 0;
#endif

    int container = func_ov004_02156fd4(obj, 5);
    if (container) {
        unsigned char local[0x38];
        ((SafeAllocator*)local)->ResetAllocatorPointer();
        ItemTable_Construct(local + 0x14);
        InitStruct0207cbe8((char*)local);
        InitStruct0207cbe8((char*)local);

        *(int*)(var4 + 0x2c) = var3;
        func_0207cf30(var4, *(short*)(data_ov004_021707e0 + 0xe), data_ov004_021707e0[0x11], 1);

        func_0207cc0c((char*)var4);
#if defined(jpn)
        data_ov004_021707e0[0xa9] = 0;
#else
        data_ov004_021707e0[0x9d] = 0;
#endif
    }

    int var5 = var1 + data_ov004_021707e0[0x11];
    if (var5 > 0x63) {
        func_ov011_021848a0(arg0, 0x2385);
    } else {
        func_ov011_021848a0(arg0, 0x38d);
    }
    func_ov023_021f65d4(arg0, 2, 8);
    return 0;
}

struct Struct_ov004_0215db14 {
    char unknown_0_[0xe];
    short unknown_e_;
    char unknown_10_;
    unsigned char unknown_11_;
    signed char unknown_12_;
    char unknown_13_[0x1f];
    short unknown_32_[4];
    short unknown_3a_;
#if defined(jpn)
    char unknown_3c_[0x6d];
#else
    char unknown1_3c_[0x61];
#endif
    unsigned char unknown_9d_;
};
struct Struct_ov004_0216fb40 { int unknown_0_[4]; };
extern Struct_ov004_0216fb40 data_ov004_0216fb40;
struct Struct_ov004_0215db14_2 { SafeAllocator unknown_0_; char unknown_14_[0x18]; int unknown_2c_; char unknown_30_[8]; };
struct Struct_ov004_0215db14_3 { char unknown_0_[0x130]; unsigned int* unknown_130_; };
extern "C" int func_ov004_0215da0c(void*);
extern "C" int func_02083960(Struct_0207d300*);
extern "C" short func_02086bf4(char*, int);
extern "C" void func_0207ccf0(void*, int, int, int, int, int, int);

// USA: func_ov004_0215db14
extern "C" ARM int func_ov004_0215db14(void* arg0) {
    GameState* var0 = GameState::GetInstance();
#if !defined(jpn)
    if (!((Struct_ov004_0215db14*)data_ov004_021707e0)->unknown_9d_) return 0;
#endif
    int var1 = func_ov004_02156e2c(arg0, 0x5f);
    if (var1 < 0) return 0;
    GameObject* var2;
    int var3;
    int var4;
    Struct_ov004_0216fb40 var5;
    COPY_ARRAY(var5.unknown_0_, data_ov004_0216fb40.unknown_0_);
    int var6;
    int var7;
    Struct_ov004_0215db14* var8;
    var8 = ((Struct_ov004_0215db14*)data_ov004_021707e0);
    var6 = var8->unknown_3a_;
    for (var7 = 0; var7 < var6; var7++) var5.unknown_0_[var7] = var8->unknown_32_[var7];
    if (var6 == var1) {
        func_ov004_0215da0c(arg0);
        return 0;
    }
    var4 = var5.unknown_0_[var1];
    var8->unknown_12_ = var4;
    var2 = func_0200ff1c(var0, ((Struct_ov004_0215db14*)data_ov004_021707e0)->unknown_12_);
    var3 = 0;
    if (var2) {
        Struct_0207d300* var9 = ((Struct_0207d300*)func_02053c6c((unsigned char*)var2));
        if (var9) var3 = 8 - func_02083960(var9);
    }
    int total = SumKeyedLookups02086bf4((char*)GameState_GetParty(state), ((Menu0215db14*)data_ov004_021707e0)->key);
    int container = func_ov004_02156fd4(obj, 5);
    if (container) {
        ItemTransferContext0215db14 work;
        work.allocator.ResetAllocatorPointer();
        ItemTable_Construct(work.state);
        InitStruct0207cbe8((char*)&work);
        InitStruct0207cbe8((char*)&work);
        work.container = container;
        func_0207ccf0(&work, ((Menu0215db14*)data_ov004_021707e0)->key, ((Menu0215db14*)data_ov004_021707e0)->quantity, selected, 1, 1, 0);
        InitStruct0207cc0c((char*)&work);
        ((Menu0215db14*)data_ov004_021707e0)->active = 0;
    }
    if (((Struct_ov004_0215db14*)data_ov004_021707e0)->unknown_11_ > var3 && var10 < 99) {
        func_ov011_021848a0(arg0, 0x2383);
    } else if (((Struct_ov004_0215db14*)data_ov004_021707e0)->unknown_11_ > var3 && var10 >= 99) {
        func_ov011_021848a0(arg0, 0x2386);
    } else if (var2 && (*((Struct_ov004_0215db14_3*)var2)->unknown_130_ & 1)) {
        func_ov011_021848a0(arg0, 0x2387);
    } else {
        func_ov011_021848a0(arg0, 0x2382);
    }
    func_ov023_021f65d4(arg0, 2, 8);
    return 0;
}
extern "C" int func_ov004_02157a28(void* arg0, int arg1);
struct Struct_ov004_0216fb20 { unsigned char unknown_0_[8]; };
extern Struct_ov004_0216fb20 data_ov004_0216fb20;
extern int data_ov004_0216fc1c[];
struct Entry { unsigned int unknown_0_; unsigned int unknown_4_; unsigned int unknown_8_0_ : 4; unsigned int unknown_8_4_ : 28; };
struct Struct_ov000_021540fc_2 { unsigned int unknown_0_0_ : 27; unsigned int unknown_3_3_ : 1; unsigned int unknown_3_4_ : 1;
              unsigned int unknown_3_5_ : 1;  unsigned int unknown_3_6_ : 2; };
struct Struct_ov000_0215b278 { unsigned int unknown_0_; Struct_ov000_021540fc_2 unknown_4_; };
struct Struct_ov004_0215dd3c { unsigned char unknown_0_0_ : 1; unsigned char unknown_0_1_ : 7; };
#if defined(jpn)

extern "C" struct GameObject* func_0200ff1c(struct GameState*, int);
#endif

// USA: func_ov004_0215dd3c
extern "C" ARM int func_ov004_0215dd3c(void* a) {
    int prev = ((int)func_ov004_02157128(a));
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, prev);
    if (!combatant) return 0;
    void* ptr = GameState_GetParty(bs);
    Bytes8 buf;
    buf = data_ov004_0216fb20;
    unsigned char flags[2];
    for (unsigned char i = 0; i < 8; i++) {
        unsigned char byte = buf.b[i];
        if (byte == 0xff) break;
#if defined(jpn)
        char* var8 = (char*)(*(unsigned char**)((char*)var2 + 0x144) + 0x194) + var7 * 0x20;
#else
        char* var8 = (char*)(*(unsigned char**)((char*)var2 + 0x150) + 0x194) + var7 * 0x20;
#endif
        if (var8) {
            char* var9 = *(char**)var8;
            if (var9) {
                if (!((Struct_ov000_0215b278*)var9)->unknown_4_.unknown_3_5_) {
                    int var10 = ((Struct_ov000_0215b278*)var9)->unknown_4_.unknown_3_3_ ? 1 : 0;
                    var5[1] = ((Struct_ov000_0215b278*)var9)->unknown_4_.unknown_3_4_ ? 1 : 0;
                    var5[0] = var10;
#if defined(jpn)
                    unsigned int var11 = ((Struct_ov004_0215dd3c*)(*(unsigned char**)((char*)var2 + 0x144) + 0x49c))->unknown_0_0_;
#else
                    unsigned int var11 = ((Struct_ov004_0215dd3c*)(*(unsigned char**)((char*)var2 + 0x150) + 0x49c))->unknown_0_0_;
#endif
                    if (!var5[var11]) {
                        func_02052d7c((Struct_02052d7c*)var2, data_ov004_0216fc1c[var6], (int)(-1));
                        if (var8) {
                            unsigned int var12 = ((Entry*)var8)->unknown_8_0_;
                            short var13 = *(short*)(var8 + 0x18);
                            func_0207c378((Struct_020732cc*)((char*)var3 + 0x1d4), var13, 1, var12);
                        }
                    }
                }
            }
        }
    }
    return func_ov004_02157a28(arg0, 1);
}

struct Struct_02109bf4_2;
extern "C" void func_0209c830(Struct_02109bf4_2*, int);

// USA: func_ov004_0215de80
extern "C" ARM int func_ov004_0215de80(void) {
    SetValueAndActivate0209c830((Struct0209c830*)g_bgmPlayer, 0x3d);
    return 0;
}
#if !defined(jpn)
struct Struct_ov004_0215de9c;
extern "C" void func_ov023_021fb25c(Struct_ov004_0215de9c* arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, int arg4);

struct Struct_ov004_0215de9c_2 { int unknown_0_; int unknown_4_; int unknown_8_; };

class Struct_ov004_0215de9c_3 {
public:
	virtual void inline_ov004_0215de9c(); virtual void inline_ov004_0215de9c_2(); virtual void inline_ov004_0215de9c_3(); virtual void inline_ov004_0215de9c_4();
	virtual void inline_ov004_0215de9c_5(); virtual void inline_ov004_0215de9c_6(); virtual void inline_ov004_0215de9c_7();
	virtual void inline_ov004_0215de9c_8(Struct_ov004_0215de9c_2* arg0);
};

// USA: func_ov004_0215de9c
extern "C" ARM int func_ov004_0215de9c(void* a) {
	GameState* battle = GameState::GetInstance();
	void* base = func_ov011_021849c8(a);
	VObjDE9C* node = (VObjDE9C*)func_ov023_021f6880((void**)base, 0x2be);
	if (!node) return 0;
	if (ScaleStatsIfType12_021f6f10(node) != 1) return 0;
	ParamsDE9C p;
	p.x = 0x5a000;
	p.y = 0;
	switch (GameState_GetLanguage((struct Struct0200fb08*)battle)) {
	case 1:
		var3.unknown_0_ = 0x90000;
		var2->inline_ov004_0215de9c_8(&var3);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)var2, 0, 0, 0x2c, 0xc);
		break;
	case 2:
		var3.unknown_0_ = 0x90000;
		var2->inline_ov004_0215de9c_8(&var3);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)var2, 0, 0, 0x2c, 0xc);
		break;
	case 3:
		var3.unknown_0_ = 0x98000;
		var2->inline_ov004_0215de9c_8(&var3);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)var2, 0, 0, 0x20, 0xc);
		break;
	case 4:
		var3.unknown_0_ = 0x8c000;
		var2->inline_ov004_0215de9c_8(&var3);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)var2, 0, 0, 0x32, 0xc);
		break;
	case 5:
		var3.unknown_0_ = 0x8c000;
		var2->inline_ov004_0215de9c_8(&var3);
		func_ov023_021fb25c((struct Struct_ov004_0215de9c*)var2, 0, 0, 0x32, 0xc);
		break;
	}
	void* node2 = func_ov023_021f6880((void**)base, 0x2bf);
	if (!node2) return 0;
	if (ScaleStatsIfType12_021f6f10(node2) != 1) return 0;
	switch (GameState_GetLanguage((struct Struct0200fb08*)battle)) {
	case 1: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x2c, 0xc); break;
	case 2: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x2c, 0xc); break;
	case 3: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x24, 0xc); break;
	case 4: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x30, 0xc); break;
	case 5: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x30, 0xc); break;
	}
	return 0;
}
#endif

struct Struct_ov004_0215e148 { char unknown_0_[8]; unsigned int unknown_8_0_ : 4; };
extern "C" void func_0207cf30(void* arg0, int arg1, int arg2, int arg3);

#if defined(jpn)
#define MESSAGE_FLAG_OFFSET 0xa9
#else
#define MESSAGE_FLAG_OFFSET 0x9d
#endif

// USA: func_ov004_0215e148
extern "C" ARM int func_ov004_0215e148(void* arg0) {
    if (((char*)data_ov004_021707e0) != NULL && *(unsigned char*)(((char*)data_ov004_021707e0) + MESSAGE_FLAG_OFFSET) != 0) {
        GameState::GetInstance();
        int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
        if (key < 0) return 0;
        void* entry = GetEntryFor_021570a4(obj, key & 0xff);
        if (!entry) return 0;
        struct ItemTable* node = ((struct ItemTable*)func_ov004_02156fd4(obj, 5));
        if (!node) return 0;
        struct Element020de650_0215e148* elem = ((struct Element020de650_0215e148*)ItemTable_Find(node, *(short*)entry));
        if (!elem) return 0;

        char buf[0x38];
        ((SafeAllocator*)buf)->ResetAllocatorPointer();
        ItemTable_Construct(buf + 0x14);
        InitStruct0207cbe8(buf);
        InitStruct0207cbe8(buf);
        *(void**)(buf + 0x2c) = node;
        int ok = elem->field8 <= 7;
        if (ok) {
            func_0207d134((Obj0207d134*)buf, (int)(*(short*)(((char*)data_ov004_021707e0) + 0xe)), *(signed char*)(((char*)data_ov004_021707e0) + 0x11));
        } else {
            func_0207cf30(var4, *(short*)(((char*)data_ov004_021707e0) + 0xe), *(unsigned char*)(((char*)data_ov004_021707e0) + 0x11), 1);
        }
        func_0207cc0c(var4);
    }
    return 0;
}

#undef MESSAGE_FLAG_OFFSET
