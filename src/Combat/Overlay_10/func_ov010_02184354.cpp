#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_ov010_02184a80 data_ov010_02185b40
#define data_ov010_02184aa6 data_ov010_02185b54
#endif

extern AllocatorUnion g_mainAllocator;
extern int g_sePlayer;
extern const char data_ov010_02184a80[];
extern const char data_ov010_02184a95[];
extern const char data_ov010_02184aa6[];

struct Struct_ov010_021842d8;
extern "C" void func_ov010_021842d8(struct Struct_ov010_021842d8* arg0);

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

struct Struct_020727d8 {
    void* unknown_0_;
    short unknown_4_;
    short unknown_6_;
};
extern "C" void func_020727d8(struct Struct_020727d8* arg0);
extern "C" void func_020728ac(void* arg0, void* arg1, void* arg2, int arg3, int arg4, int arg5, int arg6);

struct Struct_02072a68_2;
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void SePlayer_LoadExtraArchiveB(void* obj, int a, int b);
void SePlayer_PlayExtra(void* obj, int a, int b);
void SePlayer_UnloadExtraArchiveB(void* obj);

struct Struct_0204bd7c;
extern "C" unsigned short func_0204bd7c(struct Struct_0204bd7c* arg0);

struct Struct_02099950 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[0xc];
    unsigned char unknown_e_0_ : 2;
    unsigned char unknown_e_2_ : 4;
    unsigned char unknown_e_6_ : 2;
    unsigned char unknown_f_;
};
struct SearchTable;
struct SearchEntry* ZoneTable_FindEntry(struct SearchTable* table, int key);

void* GameObject_GetFloorAttribute(void* obj);
void* GameState_GetZoneTable(void* obj);
int GameState_GetProtagonistIndex(GameState* b);
void* GameState_GetPlayerLocation(char* base, unsigned int index);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);

struct Struct_020340b4;
extern "C" void func_020340b4(struct Struct_020340b4* arg0);

void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" void func_02046380(void* global);
extern "C" int func_020457e0(void* global);

struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);

struct Struct_02057de0_2;
extern "C" void* func_02057924(void);
extern "C" int func_02057de0(struct Struct_02057de0_2* arg0, int arg1, SafeAllocator* arg2, int arg3, int arg4);
extern "C" int func_02057fb4(void* arg0, int arg1, void* arg2);

struct Vector3i;

extern "C" void* func_02079e2c(char* arg0, int arg1);

struct Struct_02048350_2;
extern "C" int func_02048350(struct Struct_02048350_2* arg0, int arg1);

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);

struct Struct_ov010_02184354 { short unknown_0_; short unknown_2_; short unknown_4_; };
extern "C" void func_ov017_021d360c(int arg0, unsigned char arg1, int arg2, struct Struct_ov010_02184354 arg3);

struct Struct_ov010_02184354_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[6];
    struct Struct_ov010_02184354_3* unknown_8_;
};
struct Struct_ov010_02184354_3 {
    unsigned char unknown_0_[0xc];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 4;
    unsigned char unknown_d_;
    unsigned char unknown_e_0_ : 6;
    unsigned char unknown_e_6_ : 1;
    unsigned char unknown_e_7_ : 1;
};

struct Struct_ov010_02184354_4 {
    unsigned char unknown_0_[0xc];
    unsigned char unknown_c_;
};
MessageSystem* MessageSystem_GetInstance(void);

struct Struct_ov010_02184354_5 {
    unsigned char unknown_0_[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
};

struct Struct_ov010_02184354_6 { int unknown_0_; int unknown_4_; int unknown_8_; };

struct Struct_ov010_02184354_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_; int unknown_24_; int unknown_28_;
    int unknown_2c_; int unknown_30_; int unknown_34_;
    int unknown_38_; int unknown_3c_; int unknown_40_;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

struct Struct_ov010_02184354_8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    int unknown_4_;
    int unknown_8_;
    struct Struct_020727d8 unknown_c_;
    SafeAllocator unknown_14_;
};

// USA: func_ov010_02184354
extern "C" ARM int func_ov010_02184354(struct Ctx02184354* obj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    MessageSystem* presenter = MessageSystem_GetInstance();
    GameState* bs = GameState::GetInstance();
    GameObject* caster;
    struct MoveRecord02184354* move;
#if defined(jpn)
    struct Struct_ov010_02184354_4* var5 = *(Struct_ov010_02184354_4**)((char*)GetGameResources() + 0x3988);
#else
    struct Struct_ov010_02184354_4* var5 = *(Struct_ov010_02184354_4**)((char*)GetGameResources() + 0x3ba8);
#endif
    caster = bs->GetPartyMemberByIndex(actorInfo->combatantId);
    GameObject* active = bs->GetPartyMemberByIndex(GameState_GetLeaderIndex(bs));
    void* scene = LinkSession_GetInstance();
    void* ov17 = GetGameResources();
    move = (struct MoveRecord02184354*)Zone3D_GetInstance();
#if defined(jpn)
    char var9[200];
#endif

    if (var3 == NULL || var6 == NULL) {
        func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
        return 1;
    }

    unsigned char state = obj->state;
    if (state == 0) {
        GameObject_DisableControl((struct Obj020397cc*)active, 1);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x7800);
        if (buffer == NULL) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }
        arg0->unknown_14_.CreateTypeA(var11, 0x7800);
#if defined(jpn)
        arg0->unknown_4_ = var0->QueueLoadFile(data_ov010_02184a80, NULL);
#else
        arg0->unknown_4_ = var0->QueueLoadFileInGP2(data_ov010_02184a80, data_ov010_02184a95, NULL);
#endif
        arg0->unknown_0_ = 1;
    } else if (var10 == 1) {
        if (var0->GetTaskStatus(arg0->unknown_4_) == 0) return 0;
        if (var0->GetDetailedTaskStatus(arg0->unknown_4_) != 2) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
        void* var12;
        unsigned int var13;
        var0->GetLoadedFileByID(arg0->unknown_4_, &var12, &var13);
        func_020727d8(&arg0->unknown_c_);
        func_020728ac(&arg0->unknown_c_, &arg0->unknown_14_, var12, var13, 0, 0, 0);
        var0->RemoveTask(arg0->unknown_4_);

        unsigned short* slot = (unsigned short*)GameState_GetPlayerLocation((char*)bs, GameState_GetProtagonistIndex(bs));
        if (slot == NULL) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }
        struct Struct_ov010_02184354_3* var15 = var4->unknown_8_;
        if (var15 == NULL) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }

        unsigned char visible = 1;
        obj->visible = visible;
        if (info->category == 0) {
            void* colour = GameObject_GetFloorAttribute(caster);
            if (colour != NULL) {
                struct SearchTable* table = (struct SearchTable*)GameState_GetZoneTable(bs);
                struct SearchEntry* entry = ZoneTable_FindEntry(table,
                    ConvertColorToDecimalOffset30000((struct ColorHolder0204bd7c*)colour));
                if (entry != NULL) {
                    if (entry->kind != 0) obj->visible = 0;
                }
            }
        } else {
            struct Struct_ov010_02184354_3* var20 = var4->unknown_8_;
            if (var20 != NULL) {
                if (var20->unknown_e_6_ == 0) var16 = 0;
                arg0->unknown_1_ = var16;
            }
        }

        int var21;
        if (arg0->unknown_1_ == 0) {
            arg0->unknown_0_ = 3;
            var21 = 2;
        } else if (*var14 != 0) {
            arg0->unknown_0_ = 2;
            var21 = 1;
        } else {
            key = 0;
            obj->state = 4;
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, key);
        }

        void* var22 = func_02072a68((struct Struct_02072a68_2*)&arg0->unknown_c_, (short)var21);
#if defined(jpn)
        sprintf(var9, (const char*)var22, *(char**)((char*)var3 + 0x134));
        func_0204500c(var1, var9, 0);
        var1->unknown_998_ = 1;
#else
        struct Vec3i02184354 casterObj;
        NameText_InitFromPartyMember(&casterObj, actorInfo->combatantId);
        func_02046380(presenter);
        *(void**)presenter = &casterObj;
        func_0204500c(presenter, (const char*)entry, 0, 0xe3);
        presenter->active = 1;
#endif
    } else if (var10 == 2) {
#if defined(jpn)
        if (var1->unknown_998_ != 0) return 0;
#else
        if (var1->unknown_998_ != 0) return 0;
#endif
        if (func_020457e0(var1) == 0) {
            void* var24 = func_02072a68((struct Struct_02072a68_2*)&arg0->unknown_c_, 0);
#if defined(jpn)
            sprintf(var9, (const char*)var24, *(char**)((char*)var3 + 0x134));
            func_0204500c(var1, var9, 0);
            var1->unknown_998_ = 1;
#else
            struct Vec3i02184354 casterObj;
            NameText_InitFromPartyMember(&casterObj, actorInfo->combatantId);
            func_02046380(presenter);
            *(void**)presenter = &casterObj;
            func_0204500c(presenter, (const char*)entry, 0, 0xe3);
            presenter->active = 1;
#endif
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
            unsigned short* slot = (unsigned short*)GameState_GetPlayerLocation((char*)bs, GameState_GetProtagonistIndex(bs));
            if (slot != NULL) *slot = 0;
            obj->state = 4;
        } else {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
    } else if (var10 == 4) {
        arg0->unknown_4_ = var0->QueueLoadFile(data_ov010_02184aa6, NULL);
        arg0->unknown_0_ = 5;
        arg0->unknown_2_ = 0;
    } else if (var10 == 5) {
        if (var0->GetTaskStatus(arg0->unknown_4_) == 0) return 0;
        if (var0->GetDetailedTaskStatus(arg0->unknown_4_) != 2) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
        if (arg0->unknown_2_ < 0xf) {
            arg0->unknown_2_ = arg0->unknown_2_ + 1;
            return 0;
        }
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0x74, 0x74);
        SePlayer_PlayExtra(&g_sePlayer, 0, 0);

        void* var27;
        unsigned int var28;
        var0->GetLoadedFileByID(arg0->unknown_4_, &var27, &var28);

#if defined(jpn)
        char* var29 = (char*)var8 + 0x27c;
#else
        char* var29 = (char*)var8 + 0x2cc;
#endif
        struct Vec3i02184354 pos = *(struct Vec3i02184354*)((char*)caster + 0x44);
        VramState_Rewind((struct Foo0207df50*)(stage + 0xc40));
        VramState_Restore(stage + 0xc40);
        void* nodes = func_02057924();
        CreateAndRegisterNode02057de0((struct NodeList02057de0*)nodes, 0x11, &obj->alloc,
                                      (int)filePtr, (int)fileLen);
        VramState_Save(stage + 0xc40);

        struct Struct_ov010_02184354_6 var32;
        var32.unknown_0_ = 0x10a;
        var32.unknown_4_ = 0x10a;
        var32.unknown_8_ = 0x10a;

        struct Struct_ov010_02184354_7 var33;
        var33.unknown_0_ = 0;
        var33.unknown_10_ = 1;
        var33.unknown_12_ = 0;
        var33.unknown_14_ = -1;
        var33.unknown_16_ = -1;
        var33.unknown_18_ = -1;
        var33.unknown_1a_ = -1;
        var33.unknown_1c_ = -0x1000;
        var33.unknown_20_ = 0;
        var33.unknown_24_ = 0;
        var33.unknown_28_ = 0;
        var33.unknown_2c_ = 0;
        var33.unknown_30_ = 0;
        var33.unknown_34_ = 0;
        var33.unknown_38_ = 0;
        var33.unknown_3c_ = 0;
        var33.unknown_40_ = 0;
        var33.unknown_44_ = 0x1000;
        var33.unknown_48_ = 0x1000;
        var33.unknown_4c_ = 0x1000;
        var33.unknown_11_0_ = 0;
        var33.unknown_11_1_ = 0;
        var33.unknown_11_2_ = 1;
        var33.unknown_11_3_ = 0;
        var33.unknown_11_4_ = 0;
        var33.unknown_11_5_ = 0;
        var33.unknown_11_6_ = 0;
        var33.unknown_11_7_ = 0;

        *(Vector3i*)&var33.unknown_2c_ = *(Vector3i const*)&var30.unknown_0_;
        *(Vector3i*)&var33.unknown_44_ = *(Vector3i const*)&var32.unknown_0_;
        arg0->unknown_8_ = func_02057fb4(var31, 0x11, &var33);

        struct Struct_ov010_02184354 var34;
        var34.unknown_0_ = (short)(var30.unknown_0_ >> 4);
        var34.unknown_2_ = (short)(var30.unknown_4_ >> 4);
        var34.unknown_4_ = (short)(var30.unknown_8_ >> 4);

        if (LinkSession_IsHostOrSolo(scene) != 0) {
            unsigned short* slot = (unsigned short*)GameState_GetPlayerLocation((char*)bs, GameState_GetProtagonistIndex(bs));
            if (slot != NULL) {
                slot[0] = move->id;
                slot[1] = anchor.x;
                slot[2] = anchor.y;
                slot[3] = anchor.z;
            }
        }

        struct Struct_ov010_02184354_5* var36 =
            (struct Struct_ov010_02184354_5*)func_02079e2c((char*)func_020797dc(), 0xd2);
        if (var36 != NULL) {
            func_02048350((struct Struct_02048350_2*)var3, var36->unknown_8_0_);
        }
        GameObject* target = bs->GetLeader();
        if (target != NULL) {
            SetFlag0x80At0xc2((struct Flags020340b4*)target);
        }
        func_ov017_021d360c(0, GameState_GetProtagonistIndex(bs), move->id, anchor);
        obj->state = 3;
    } else if (state == 3) {
        GameState* now = GameState::GetInstance();
        int finished = 0;
        if (obj->visible != 0) {
#if defined(jpn)
            if (var38->GetGameObjectByIndex(arg0->unknown_8_) == NULL && var1->unknown_998_ == 0) {
#else
            if (var38->GetGameObjectByIndex(arg0->unknown_8_) == NULL && var1->unknown_998_ == 0) {
#endif
                var39 = 1;
            }
        } else {
#if defined(jpn)
            if (var1->unknown_998_ == 0) var39 = 1;
#else
            if (var1->unknown_998_ == 0) var39 = 1;
#endif
        }
        if (finished != 0) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            SePlayer_UnloadExtraArchiveB(&g_sePlayer);
            return 1;
        }
    }
    return 0;
}
