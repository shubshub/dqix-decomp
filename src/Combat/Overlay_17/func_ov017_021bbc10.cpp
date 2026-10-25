#include <globaldefs.h>
#include "Combat/ActorAction.h"

#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define data_ov017_021d7d6c data_ov017_021d8544
#define data_ov017_021d7d9e data_ov017_021d8576
#define data_ov017_021d7db8 data_ov017_021d8590
#define data_ov017_021d7dbb data_ov017_021d8593
#define data_ov017_021d7dbf data_ov017_021d8597
#define data_ov017_021d7de0 data_ov017_021d85b8
#define data_ov017_021d7df9 data_ov017_021d85d1
#endif

struct Struct_02038598_5;
struct Struct_02018300_3;
struct Struct_020d7aa0_2;
struct Struct_02010834;
struct Struct_02033fcc;

struct Struct_ov017_021bbc10 {
    unsigned char unknown_0_[1];
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_[0x68];
    int unknown_74_;
#if defined(jpn)
    unsigned char unknown_78_[0x20];
#else
    unsigned char unknown1_78_[0x24];
#endif
    unsigned char unknown_9c_;
    unsigned char unknown_9d_[0xcc - 0x9d];
    unsigned char unknown_cc_;
    unsigned char unknown_cd_;
    unsigned char unknown_ce_[0xd0 - 0xce];
    unsigned char unknown_d0_[0x10];
    unsigned char unknown_e0_[0xfd - 0xe0];
    unsigned char unknown_fd_;
    unsigned char unknown_fe_[1];
    unsigned char unknown_ff_;
};

int GetByte0x26c_02039d7c(char*);
int GetField0x70_0202e7f0(void* obj);
void* GetFieldIfFlag4_020100f8(char*);
int CheckField0NonZero_0202b7d8(int*);
int PeekInputLogA_020a1eb0(void);
void PushInputLogA_020a1df8(int);
unsigned int* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
void* TextQueue_GetInstance(void);
void TextQueue_Reset(Obj020d7aa0* obj);
void GameObject_DisableControl(Obj020397cc* obj, int arg1);
void SetField0x158_02053ec8(void*, int);
void CaptureTransformState02053ed8(void* obj);
int GameState_GetProtagonistIndex(GameState* gs);
void CopyCountedBytesToIntArray02010834(Base02010834* base, int index, int* out, int* outCount);
void SetFlag0x4At0xe0(Flags02033fcc*);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
struct Obj021bb088;
void InitTimerObj_021bb088(Obj021bb088*);
int* GetFieldPtrAt0x5ca4_02010768(void* obj);
struct SafeAllocator;
void ClearAllocSlotsAndStore_0215aa14(SafeAllocator*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_0202ae18(void);
extern "C" ARM int func_ov017_021bb27c(Struct_ov017_021bbc10* arg0);

extern "C" int func_02046b60(Struct_02038598_5* arg0, int arg1);
extern "C" int func_02046b08(void** arg0);
void SetBrightness(GameResources* resources, int brightness, int duration);
char* strstr(const char* arg0, const char* arg1);

extern const char data_ov017_021d7d6c[];
extern const char data_ov017_021d7d9e[];
extern const char data_ov017_021d7db8[];
extern const char data_ov017_021d7dbb[];
extern const char data_ov017_021d7dbf[];
extern const char data_ov017_021d7de0[];
extern const char data_ov017_021d7df9[];

// USA: func_ov017_021bbc10
extern "C" ARM int func_ov017_021bbc10(Struct_ov017_021bbc10* arg0) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    GameObject* var2 = var0->GetUnknownGameObject();
    unsigned char* var3 = (unsigned char*)func_020100f8((char*)var0);
    GameResources* var4 = GetGameResources();
    void* var5 = func_0202ae18();

    if (ListContainsId((ListHead02046b60*)res->fieldTaskQueue_, 1)) {
        self->flagFf = 1;
        self->flag01 = 1;
        return self->result0a;
    }
    FlagWord_SetBits(GlobalFlags_GetInstance(), 0x400e);
    if (res->unknown_4080 != 0) {
        return self->result0a;
    }
    Struct_02037d10* var6 = func_020399a8(var2);
    if (func_02039d7c((char*)var2) != 0 && var6->unknown_1_ != 2) {
        return arg0->unknown_a_;
    }
    if (self->flagFd == 0 && IsField0Null_02046b08((void**)res->unknown_ptr_array_3700[0]) == 0) {
        return self->result0a;
    }
    SetFlags00(var4, 0x10);
    if (TestFlags00(var4, 0x1000) == 0 && func_020a1eb0() != 1) {
        func_020a1df8(1);
    }
    ClearAllocSlotsAndStore_0215aa14((SafeAllocator*)NULL);
    GameObject_DisableControl((Obj020397cc*)unk, 1);
    ClearIntAt0x23c_020a27b8(field4);
    TextQueue_Reset((Obj020d7aa0*)TextQueue_GetInstance());
    *(unsigned short*)(field4 + 0x21e) = GetField0x70_0202e7f0(field4);

    if (CheckField0NonZero_0202b7d8((int*)search)) {
        char* arr = (char*)GameState_GetParty(gs);
        for (int i = 0; i < *(unsigned char*)(arr + 0xf7c); i++) {
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(gs, *(unsigned char*)(arr + i + 0xf78));
            if (combatant != NULL) {
                SetField0x158_02053ec8(combatant, 3);
                CaptureTransformState02053ed8(combatant);
            }
        }
    }

    int count;
    int ids[4];
    CopyCountedBytesToIntArray02010834((Base02010834*)gs, GameState_GetProtagonistIndex(gs), ids, &count);
    for (int i = 0; i < count; i++) {
        GameObject* member = gs->GetPartyMemberByIndex(ids[i]);
        if (member != NULL) {
            SetFlag0x4At0xe0((Flags02033fcc*)member);
            if (GetByte0x26c_02039d7c((char*)member) == 0 || GetFieldPtrAt0x26c_020399a8(member)->command != 2) {
                member->obj3D_.SetAnimationByName(data_ov017_021d7d6c, 0x10);
            }
            func_02039d24((unsigned char*)var13);
        }
    }
    GameObject* var14 = var0->GetPartyMemberByIndex(0xce);
    if (var14 != NULL) {
        func_02039d24((unsigned char*)var14);
    }
    func_ov017_021bb088((Struct_ov017_021baedc*)arg0->unknown_d0_);
    int* var15 = func_02010768(var0);
    var15[0] = 0;
    var15[1] = 0;
    var1->AddFence();

    if (self->useAltPath9c != 0) {
        self->task74 = loader->QueueLoadFile(data_ov017_021d7d9e, NULL);
    } else if (self->flagCc != 0) {
        char* name = *(char**)((char*)Zone3D_GetInstance() + 8);
        if (gs->GetGameObjectByIndex(self->indexCd) == NULL || strstr(name + 5, data_ov017_021d7db8) == NULL ||
            strstr(name + 5, data_ov017_021d7dbb) == NULL) {
            SetBrightness(res, 0, 0x28);
            func_ov017_021bb27c(self);
            self->flag01 = 1;
            return self->result0a;
        }
        return 0xc;
    } else {
        unsigned int var17 = arg0->unknown_8_;
        if (var17 >= 0x5208 && var17 < 0x9c40) {
            arg0->unknown_74_ = var1->QueueLoadFile(data_ov017_021d7dbf, NULL);
            var1->GetNumQueuedTasks();
        } else if (var17 >= 0x9c40) {
            arg0->unknown_74_ = var1->QueueLoadFile(data_ov017_021d7de0, NULL);
        } else {
            arg0->unknown_74_ = var1->QueueLoadFile(data_ov017_021d7df9, NULL);
        }
    }
    return 1;
}
