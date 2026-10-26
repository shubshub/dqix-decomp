#include <globaldefs.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Filesystem/NitroVM.h"
#include "std_library_functions.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define func_0203e8f8 func_0203edf4
#define data_020efdc4 data_020efcdc
#define data_020efdda data_020efcf2
#define data_020efde9 data_020efd01
#define data_020efdf0 data_020efd08
#define data_020efe08 data_020efd20
#define data_020efe0e data_020efd26
#define data_020efe20 data_020efd38
#define data_020efe27 data_020efd3f
#define data_020efe30 data_020efd48
#define data_020efe38 data_020efd50
#endif
struct Struct_0203d028_5 {
    char pad0[6];
    unsigned char field6;
};
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
#if defined(jpn)
    char unknown_3ac_[0x7c38 - 0x3ac];
#else
    char unknown1_3ac_[0x7e78 - 0x3ac];
#endif
    struct Struct_0203d028_5 unknown_7e78_;
    struct Struct_0203d028_5* inline_0203d028() { return &unknown_7e78_; }
};

struct Struct_020652b4 { int field0; };
extern "C" int func_020652b4(struct Struct_020652b4* p);
extern "C" int func_0206dda4(int* p);

struct Struct_0203d028_6 {
    unsigned int count;
    unsigned char field4;
    unsigned char field5;
    unsigned char pad6[2];
    void* elements;
};
extern "C" void func_020401fc(struct Struct_0203d028_6* pool, unsigned int count, SafeAllocator* alloc);

extern "C" int func_020652c8(int* obj);

struct Struct_0203d028_7 {
    char pad0[0xb5c];
    unsigned char* unknown_b5c_;
};
struct Global02012fe4 {
    unsigned short id;
    char pad2[0x1840 - 2];
    struct Struct_0203d028_7 unknown_1840_;
    struct Struct_0203d028_7* inline_0203d028_2() { return &unknown_1840_; }
};
extern "C" struct Global02012fe4* Zone3D_GetInstance(void);
extern "C" unsigned int* GlobalFlags_GetInstance(void);

extern "C" int func_020981e4(int a, int id);
extern "C" int func_02098210(int a, int id);

extern "C" void func_020404c0(int* obj);

struct Struct_0203d028_9 {
    char pad0[0xa];
    unsigned char unknown_a_0_ : 7;
    unsigned char flag7 : 1;
    unsigned char unknown_b_;
    int fieldC;
    int field10;
    int field14;
    int field18;
    short field1c;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    char pad20[0x38 - 0x20];
    int field38;
    int field3c;
    char unknown_40_[0x54 - 0x40];
    int field54;
    int unknown_58_;
};
extern "C" struct Struct_0203d028_9* func_0206db20(void* base, int key);

extern "C" void func_02040520(int* obj, int value);
extern "C" void func_02040530(int* obj, int value);

struct Struct_0203d028_10 {
    char unknown_0_[0xac];
    unsigned short field_ac;
    char unknown_ae_[2];
    int unknown_b0_;
    char unknown_b4_[0xc];
    int unknown_c0_;
    unsigned char field_c4;
    char unknown_c5_[3];
    int unknown_c8_;
    int field_cc;
    int field_d0;
    unsigned char unknown_d4_;
};
extern "C" void func_02041244(struct Struct_0203d028_10* obj);

struct Struct_203dafc {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
};
extern "C" void func_0203dafc(struct Struct_203dafc* obj);

extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

struct Struct_0203d028_12;
extern "C" struct Struct_0203d028_12* func_0209854c(struct Struct_0203d028_12* list, int target);

extern "C" void* ObjLoading_GetInstance(void);
extern "C" int func_020db2d4(void* obj);
extern "C" void func_020daf9c(int a, int b, int c, int d);

void SetMainBrightness(GameResources*, int, int);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" int IsLcdPowerOn(void);
extern "C" int SetLcdPower(int a);

extern "C" void func_ov017_0218f064(void* mgr, int a, int b, int c, int d);

struct CombatantStruct;

struct Struct_0203d028_13 { char unk[6]; unsigned short field; };
extern "C" void _ZN8Object3D10SetField06Et(struct Struct_0203d028_13* obj, int v);

extern "C" int* func_ov017_021a4658(void* mgr, int a);

struct FieldTaskQueue;
extern "C" void FieldTaskQueue_Update(struct FieldTaskQueue* ctx);

struct HeadNode02046b24 { signed char id; };
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

extern "C" void NpcWalker_Init(void* obj);
extern "C" void func_0203db24(unsigned char* obj, int val);

struct Struct_0203d028_14;
extern "C" void func_0203f02c(struct Struct_0203d028_14* obj, int param1, int param2, char* param3, int arg4, int arg5);

extern "C" void func_0203f138(void* obj, int b);

extern "C" void func_0203e8f8(void* a, void* b, void* c);

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);

struct GameState;
extern "C" void func_0200fd48(GameState*, int);

struct FlagWord020466f4 { unsigned int flags; };
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

struct Struct_02040774 { char pad4[4]; int a; int b; int c; };
struct Struct_0203d028_15 {
    char pad[0x14];
    struct Struct_02040774* f14;
    void* f18;
    void* f1c;
};
extern "C" void func_02040774(struct Struct_0203d028_15* obj, int a, int b, int c);

struct Struct_0203cda8;
struct Struct_0203d028_16 {
    char pad[0x14];
    struct Struct_0203cda8* field14;
    unsigned char* field18;
    unsigned char* field1c;
};
extern "C" void func_0204085c(struct Struct_0203d028_16* obj, int a, int b, int c);

struct Struct_0203cec4;
struct S02037418;
struct Struct_02040540 { char pad[0xc]; unsigned int val; };
struct Struct_0203d028_17 {
    unsigned int flags;
    unsigned int unk4;
    unsigned int unknown_8_;
    struct Struct_02040540* child;
    unsigned int unk10;
    struct Struct_0203cec4* b;
    struct S02037418* c;
};
extern "C" void func_02040540(struct Struct_0203d028_17* obj);

struct ObjectArchiveLoadInfo;

struct Struct_0203d028_18 { char unk0[0x5c]; short a; short b; short c; };

struct Struct_020408c8 { char unknown_0_[0x1c]; int a; int b; int c; };
struct Struct_0203d028_19 {
    char pad[0x14];
    struct Struct_020408c8* f14;
    void* f18;
    void* f1c;
};
extern "C" void func_020408c8(struct Struct_0203d028_19* obj, short a, short b, short c);

struct Struct_0203d028_20 {
    char unknown_0_[0xc4];
    char field_c4;
    char unknown_c5_[0xb];
    int field_d0;
};
extern "C" int func_02041598(struct Struct_0203d028_20* obj, int value, int z);

extern "C" void func_0203db34(unsigned char* obj, int a, int b, int c);

struct Struct_0203d028_21 {
    char unknown_0_[0xcc];
    int field_cc;
    int field_d0;
};
extern "C" int func_020415b0(Struct_0203d028_21*, int, int);

extern "C" void func_0203db44(void* a, void* b, void* c);

extern "C" void func_02041628(void* obj, int v, int z);
extern "C" void func_02041640(void* obj, int v, int z);
struct Vector3i;

extern "C" int Zone3D_GetGroundHeight(void* globalStruct, int* vec3);

struct Struct_02040bfc { char unk[0x8c]; int value; };
struct Struct_02040bfc_2 { char unk[0xc8]; int value; };
struct Struct_02040bfc_3 { char unk[0x2ec]; int value; };
struct Struct_0203d028_22 {
    char unk[0x14];
    struct Struct_02040bfc* a;
    struct Struct_02040bfc_2* b;
    struct Struct_02040bfc_3* c;
};
extern "C" void func_02040bfc(struct Struct_0203d028_22* obj, int value);

struct Struct_0203d028_23 {
    unsigned short id;
    unsigned char type;
    unsigned char unknown_3_;
#if defined(jpn)
    char pad4[0xc];
#endif
    char name[12];
    struct Struct_0203d028_23* next;
};

struct Struct_0203d028_24 {
    unsigned int flags;
    int unknown_4_;
    struct Struct_0203d028_23* entry;
    struct Struct_0203d028_9* info;
    void* unknown_10_;
    void* stateB;
    struct Struct_0203d028_10* state;
    struct CombatantStruct* combatant;
};

struct Struct_0203d028_25 {
    struct Struct_0203d028_6 pool;
    struct Struct_0203d028_24* entries[0x20];
    int unknown_8c_;
    int listHead;
    void* unknown_94_;
    char unknown_98_[4];
    unsigned char unknown_9c_;
};

extern char data_020efdc4;
extern char data_020efdda;
extern char data_020efde9;
extern char data_020efdf0;
extern char data_020efe08;
extern char data_020efe0e;
extern char data_020efe20;
extern char data_020efe27;
extern char data_020efe30;
extern char data_020efe38;

struct Struct_0203d028_26 { unsigned int b0 : 1; };

static inline void inline_0203d028_3(void* m, short v) { *(short*)((char*)m + 0x2e) = v; }
static inline void inline_0203d028_4(void* m, unsigned char v) { *((unsigned char*)m + 0x95) = v; }

static inline SafeAllocator& GetResourceAllocator(GameResources* resources, int index) {
    return resources->allocator_array_1a0[index];
}

static inline char& inline_0203d028_5(GameResources* resources, int offset) {
    return resources->vramStates_[offset];
}

static inline void inline_0203d028_6(void* motion, int v)
{
    if (motion != 0) {
        *(int*)((char*)motion + 0x90) = v;
    }
}

// USA: func_0203d028
extern "C" ARM void func_0203d028(struct Struct_0203d028_25* self, void* unused1, SafeAllocator* sb, char* fp)
{
    if (func_020652b4((struct Struct_020652b4*)&self->listHead) ||
        func_0206dda4((int*)&self->unknown_94_))
    {
        func_020401fc(&self->pool, 0xc, sb);
        return;
    }

    struct BattleStruct* battleStruct = (BattleStruct*)GameState::GetInstance();
    GameResources* mgr = GetGameResources();
    struct Struct_0203d028_23* entry = (struct Struct_0203d028_23*)func_020652c8(&self->listHead);
    struct Global02012fe4* globalStruct = Zone3D_GetInstance();
#if defined(jpn)
    char* var4 = (char*)globalStruct + 0x860;
#define GLOBAL_SUB var4
#else
#define GLOBAL_SUB ((char*)globalStruct + 0x840)
#endif
    unsigned int* dataFlags = GlobalFlags_GetInstance();
    unsigned int var6 = *(unsigned short*)globalStruct;
    void* var7 = 0;
    unsigned int var8 = 0;
    int var9 = 0;
    func_020401fc(&self->pool, 0xc, sb);

    if (func_020981e4((int)GLOBAL_SUB, var6) &&
        func_02098210((int)GLOBAL_SUB, var6) == 0) {
        self->pool.field5 = 1;
    } else {
        self->pool.field5 = 0;
    }
    self->unknown_8c_ = 0;
    self->unknown_9c_ = 0;
    BackgroundLoader::AddLockGlobal();

    while (entry != 0) {
        struct Struct_0203d028_24* node = (struct Struct_0203d028_24*)sb->Allocate(0x20);
        if (node == 0) goto abort_unlock;
        func_020404c0((int*)node);
        struct Struct_0203d028_9* info = func_0206db20(&self->unknown_94_, entry->id);
        func_02040520((int*)node, (int)entry);
        func_02040530((int*)node, (int)info);

        if (battleStruct->inline_0203d028()->field6 != 0xff && info != 0 && info->unknown_1f_ != 0) {
            node->flags |= 0x40000;
        }

        int var12 = 0;
        unsigned int outLen;
        unsigned int length2;
        unsigned int var15;
        unsigned int fileSize;
        const void* filePtr;
        unsigned int decompSize;
        unsigned int var19;
        unsigned int var20;
        void* var21;
        void* var22;
        void* decompressed;

        if (entry->type == 2) {
            node->state = (struct Struct_0203d028_10*)sb->Allocate(0xd8);
            if (node->state == 0) goto abort_unlock;
            func_02041244(node->state);
            char pathBuf[40];
            sprintf(pathBuf, &data_020efdc4, entry->name);
            void* var25 = LoadFileIntoNewAllocation(pathBuf, *sb, &outLen);
            if (var25 == 0) goto abort_unlock;
            struct Struct_203dafc params;
            func_0203dafc(&params);
            VramState_Restore(fp);
            params.fieldc = (int)sb;
            params.field4 = (int)var25;
            params.field8 = (int)outLen;
            ((Object3D*)node->state)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
            VramState_Save(fp);
        }
        else if (entry->type == 4) {
#if defined(jpn)
            unsigned char* table = ((struct Struct_0203d028_7*)(var4 + 0x1000))->unknown_b5c_;
#else
            unsigned char* table = globalStruct->inline_0203d028_2()->unknown_b5c_;
#endif
            int slot = 5;
            struct Struct_0203d028_12* found = func_0209854c((struct Struct_0203d028_12*)GLOBAL_SUB, entry->id);
            if (found != 0) {
                {
                    if (func_020db2d4(ObjLoading_GetInstance()) == 0) {
                        func_020daf9c(1, 0, 1, 0);
                        SetMainBrightness(mgr, ~0xf, 0);
                    }
                    FlagWord_SetBits(dataFlags, 0x400000);
                    if (!IsLcdPowerOn()) {
                        while (SetLcdPower(1) == 0) {
                        }
                        SleepCurrentContext(1);
                    }
                    *(short*)(table + 0x568) = slot;
                    ((unsigned char*)table)[0x56a] = ((unsigned char*)found)[0x4f];
                    memcpy(table + 0x488, (unsigned char*)found + 0x1a, 0x1c);

                    func_ov017_0218f064(mgr, 5, 0x4000, 1, 0);

                    node->combatant = (CombatantStruct*)((GameState*)battleStruct)->GetGameObjectByIndex(5);
                    _ZN8Object3D10SetField06Et((struct Struct_0203d028_13*)node->combatant, var6);

                    int* extra = func_ov017_021a4658(mgr, 5);
                    extra[3] = 1;

                    char* base = (char*)mgr + 0x3000;
#if defined(jpn)
                    void* ctxA = *(void**)(base + 0x4f0);
                    void* ctxB = *(void**)(base + 0x4f4);
#else
                    void* ctxA = *(void**)(base + 0x700);
                    void* ctxB = *(void**)(base + 0x704);
#endif
                    BackgroundLoader* instance = BackgroundLoader::GetInstance();

                    while (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)ctxA) == 0x13) {
                        instance->RemoveAllLocks();
                        FieldTaskQueue_Update((struct FieldTaskQueue*)ctxA);
                        if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)ctxB) == 0x14) {
                            FieldTaskQueue_Update((struct FieldTaskQueue*)ctxB);
                        }
                    }

                    node->stateB = sb->Allocate(0x9c);
                    if (node->stateB == 0) goto abort_unlock;
                    NpcWalker_Init(node->stateB);
                    func_0203db24((unsigned char*)node, (int)self);

                    const char* var35 = &data_020efdda;
                    if (node->stateB != 0) {
                        func_0203f02c(*(struct Struct_0203d028_14**)((char*)node + 0x14), (int)var35, (int)sb, fp, 0, 0);
                    }
                    if (node->stateB != 0) {
                        func_0203f138(node->stateB, 1);
                    }
                    inline_0203d028_3(node->stateB, 0x3d);
                    inline_0203d028_4(node->stateB, 1);
                    func_0203db24((unsigned char*)node, (int)self);

                    SafeAllocator* var36 = &GetResourceAllocator(mgr, 8);
                    var36->Reset();
                    func_0203e8f8(self, node, var36);

                    node->combatant = 0;
                    SafeAllocator* var37 = &GetResourceAllocator(mgr, 3);
                    char* buf930 = &inline_0203d028_5(mgr, 0x930);
                    entry->type = 0;
                    var37->Reset();
                    VramState_Rewind((struct Foo0207df50*)buf930);
                    func_0200fd48((GameState*)battleStruct, 5);
                    FlagWord_ClearBits((struct FlagWord020466f4*)dataFlags, 0x400000);
                }
            }
        }
        else if (entry->type == 5) {
            node->state = (struct Struct_0203d028_10*)sb->Allocate(0xd8);
            if (node->state == 0) goto abort_unlock;
            func_02041244(node->state);
            BackgroundLoader::FreeAllocationsGlobal();

            GPCReadPair pair;
#if defined(jpn)
            GPCReadPair* var40 = &pair;
#define PAIR (*var40)
#else
#define PAIR pair
#endif
            ZeroInitGPCPointer(&PAIR.pGPCFile);
            PAIR.ZeroInitializeMachine();

            char var41[16];
            sprintf(var41, &data_020efde9, entry->name);

            if (!LoadAndDecompressGPCHeaderAndInnerFileInfo(&PAIR.pGPCFile, pair.machine,
                    &data_020efdf0, g_fileLoadBuffer, length2, 0x30000, false, NULL))
            {
                PAIR.Reset();
                ZeroDestroyGPCPointer(&PAIR.pGPCFile);
                goto abort_unlock;
            }

            unsigned char* dst = g_fileLoadBuffer + length2;
            if (!DecompressFileFromGPCByName(pair.pGPCFile, pair.machine,
                    dst, var15, 0x30000 - length2, var41))
            {
                pair.Reset();
                pair.Reset();
                ZeroDestroyGPCPointer(&pair.pGPCFile);
                goto abort_unlock;
            }

            if (!FindFilesInNarcBySubstring(dst, &data_020efe08, &filePtr, &fileSize, 1)) {
                pair.Reset();
                pair.Reset();
                ZeroDestroyGPCPointer(&pair.pGPCFile);
                goto abort_unlock;
            }

            decompressed = DecompressLZ77FileIntoAllocatedSpace(*sb, filePtr, decompSize);

            struct Struct_203dafc params;
            func_0203dafc(&params);
            VramState_Restore(fp);
            params.fieldc = (int)sb;
            params.field4 = (int)decompressed;
            params.field8 = (int)decompSize;
            ((Object3D*)node->state)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
            VramState_Save(fp);

            node->state->unknown_d4_ |= 2;
            pair.Reset();
            pair.Reset();
            ZeroDestroyGPCPointer(&pair.pGPCFile);
        }
        else {
            node->stateB = sb->Allocate(0x9c);
            if (node->stateB == 0) goto abort_unlock;
            NpcWalker_Init(node->stateB);
            func_0203db24((unsigned char*)node, (int)self);

            if (entry->name[0] != 0 && entry->type == 0) {
                int var44 = 0;
                char pathBuf[40];
                if (info != 0 && (info->fieldC & 0x800)) {
                    var44 = 1;
                    sprintf(pathBuf, &data_020efe0e, entry->name);
                    NitroVM vm;
                    NitroVM_Initialize(&vm);
                    if (!NitroVM_PrepareReadFileByPath(&vm, pathBuf)) {
                        var44 = 0;
                    }
                }
                if (var44 == 0) {
                    sprintf(pathBuf, &data_020efe20, entry->name);
                } else {
                    sprintf(pathBuf, &data_020efe27, entry->name);
                }
                if (node->stateB != 0) {
                    func_0203f02c(*(struct Struct_0203d028_14**)((char*)node + 0x14), (int)pathBuf, (int)sb, fp, 0, 0);
                }
                if (node->stateB != 0) {
                    func_0203f138(node->stateB, 1);
                }
                inline_0203d028_3(node->stateB, 0x3d);
                var12 = 1;
            }
        }

        if (var8 < 0x20) {
            self->entries[var8] = node;
        }

        if (info != 0) {
            func_02040774((struct Struct_0203d028_15*)node, info->field10, info->field14, info->field18);
            func_0204085c((struct Struct_0203d028_16*)node, 0, info->field1c, 0);
            func_02040540((struct Struct_0203d028_17*)node);

            if (var12 == 0 && info->field54 != 0) {
                char buf[60];
                sprintf(buf, &data_020efe30, info->field54);
                void* var48 = LoadFileIntoNewAllocation(buf, *sb, &var19);
                if (var48 != 0) {
                    int bit = 0;
                    struct Struct_0203d028_26* p = 0;
                    if (node->state != 0) p = *(struct Struct_0203d028_26**)((char*)node->state + 0xc);
                    else if (node->combatant != 0) p = *(struct Struct_0203d028_26**)((char*)node->combatant + 0xc);
                    if (p != 0) bit = p->b0;

                    struct Struct_203dafc var51;
                    var51.field4 = (int)var48;
                    var51.fieldc = (int)sb;
                    var51.field8 = (int)var19;
                    var51.field1c = 1;

                    if (bit == 0) {
                        ((Object3D*)((int)node->state))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)((int)&var51));
                    } else if (bit == 1) {
                        ((Object3D*)node->state)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&var51, 0);
                    }
                }
            }

            if (info->fieldC & 0x2000) {
                if (var7 == 0) {
                    var7 = sb->Allocate(0xac);
                    if (var7 == 0) goto abort_unlock;
                    ((Object3D*)var7)->Initialize();
                    var22 = LoadFileIntoNewAllocation(&data_020efe38, *sb, &var20);
                    if (var22 != 0) {
                        struct Struct_203dafc var52;
                        func_0203dafc(&var52);
                        VramState_Restore(fp);
                        var52.field4 = (int)var22;
                        var52.field8 = (int)var20;
                        var52.fieldc = (int)sb;
                        ((Object3D*)((int)var7))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)((int)&var52));
                        VramState_Save(fp);
                    }
                    ((Object3D*)((struct Struct_0203d028_18*)var7))->SetScale(0x10a, 0x10a, 0x10a);
                    ((Object3D*)((unsigned char*)var7))->SetFlag16();
                }
                if (var9 == 0) {
                    node->unknown_10_ = var7;
                    var9 = 1;
                } else {
                    var21 = sb->Allocate(0xac);
                    if (var21 == 0) goto abort_unlock;
                    ((Object3D*)var21)->Initialize();
                    ((Object3D*)var7)->ShallowCloneTo((Object3D*)var21);
                    ((Object3D*)((unsigned char*)var21))->SetFlag16();
                    node->unknown_10_ = var21;
                }
            }

            if (node->stateB != 0) {
                func_020408c8((struct Struct_0203d028_19*)node, 0x8f, 0x8f, 0x8f);
            }
            else if (node->state != 0) {
                ((Object3D*)((struct Struct_0203d028_18*)node->state))->SetScale(0x10a, 0x10a, 0x10a);
                func_02041598((struct Struct_0203d028_20*)node->state, info->unknown_1e_, 0);
                if (node->flags & 0x800) {
                    ((Object3D*)((unsigned char*)node->state))->SetFlag16();
                    ((Object3D*)((unsigned char*)node->state))->EnableFlag(0x2000000);
                    func_0203db34((unsigned char*)node->state, 0x4b5c, info->field1c, 0);
                }
                if (info->unknown_58_ != 0) {
                    func_020415b0((struct Struct_0203d028_21*)node->state, info->unknown_58_, 0);
                }
                if (info->flag7) {
                    func_0203db44(self, node, sb);
                }
            }
            else if (node->combatant != 0) {
                ((Object3D*)((struct Struct_0203d028_18*)node->combatant))->SetScale(0x10a, 0x10a, 0x10a);
                func_02041628(node->combatant, info->unknown_1e_, 0);
                if (node->flags & 0x800) {
                    ((Object3D*)((unsigned char*)node->combatant))->SetFlag16();
                    func_0203db34((unsigned char*)node->combatant, 0x4b5c, info->field1c, 0);
                }
                if (info->unknown_58_ != 0) {
                    func_02041640(node->combatant, info->unknown_58_, 0);
                }
                int localVec3[3];
                *(Vector3i*)localVec3 = *(Vector3i const*)((int*)((char*)node->combatant + 0x44));
                localVec3[1] = Zone3D_GetGroundHeight(globalStruct, localVec3);
                *(Vector3i*)((int*)((char*)node->combatant + 0x44)) = *(Vector3i const*)localVec3;
            }
            func_02040bfc((struct Struct_0203d028_22*)node, info->field38);

            inline_0203d028_6(node->stateB, info->field3c);
        }

        var8++;
        self->unknown_8c_++;
        entry = entry->next;
    }

abort_unlock:
    BackgroundLoader::RemoveLockGlobal();
}
