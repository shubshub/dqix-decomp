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

struct ListHead02046b60;
struct Obj020397cc;
struct Obj020d7aa0;
struct Base02010834;
struct Flags02033fcc;

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
    unsigned char flagFd;
    unsigned char unknown_fe_[1];
    unsigned char unknown_ff_;
};

extern "C" int GameObject_IsClimbingLadder(char*);
extern "C" int Camera_GetOrbitYaw(void* obj);
extern "C" void* GameState_GetFollowCamera(char*);
extern "C" int LinkSession_IsActive(int*);
extern "C" int func_020a1eb0(void);
extern "C" void func_020a1df8(int);
extern "C" unsigned int* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_020a27b8(unsigned char* obj);
extern "C" void* TextQueue_GetInstance(void);
extern "C" void TextQueue_Reset(Obj020d7aa0* obj);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg1);
extern "C" void func_02053ec8(void*, int);
extern "C" void func_02053ed8(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void GameState_GetPartyMemberIds(Base02010834* base, int index, int* out, int* outCount);
extern "C" void GameObject_PauseMovement(Flags02033fcc*);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
struct Struct_ov017_021baedc;
extern "C" void func_ov017_021bb088(Struct_ov017_021baedc*);
extern "C" int* func_02010768(void* obj);
struct SafeAllocator;
extern "C" void func_ov001_0215aa14(SafeAllocator*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" ARM int func_ov017_021bb27c(Struct_ov017_021bbc10* self);

extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
void SetBrightness(GameResources* resources, int brightness, int duration);
char* strstr(const char* str, const char* arg1);

extern const char data_ov017_021d7d6c[];
extern const char data_ov017_021d7d9e[];
extern const char data_ov017_021d7db8[];
extern const char data_ov017_021d7dbb[];
extern const char data_ov017_021d7dbf[];
extern const char data_ov017_021d7de0[];
extern const char data_ov017_021d7df9[];

// USA: func_ov017_021bbc10
extern "C" ARM int func_ov017_021bbc10(Struct_ov017_021bbc10* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* unk = gs->GetLeader();
    unsigned char* field4 = (unsigned char*)GameState_GetFollowCamera((char*)gs);
    GameResources* res = GetGameResources();
    void* search = LinkSession_GetInstance();

    if (func_02046b60((ListHead02046b60*)res->fieldTaskQueue_, 1)) {
        self->unknown_ff_ = 1;
        self->unknown_1_ = 1;
        return self->unknown_a_;
    }
    FlagWord_SetBits(GlobalFlags_GetInstance(), 0x400e);
    if (res->unknown_4080 != 0) {
        return self->unknown_a_;
    }
    SubBlock02038508* field26c = GameObject_GetLadderClimb(unk);
    if (GameObject_IsClimbingLadder((char*)unk) != 0 && field26c->command != 2) {
        return self->unknown_a_;
    }
    if (self->flagFd == 0 && FieldTaskQueue_IsEmpty((void**)res->unknown_ptr_array_3700[0]) == 0) {
        return self->unknown_a_;
    }
    SetFlags00(res, 0x10);
    if (TestFlags00(res, 0x1000) == 0 && func_020a1eb0() != 1) {
        func_020a1df8(1);
    }
    func_ov001_0215aa14((SafeAllocator*)NULL);
    GameObject_DisableControl((Obj020397cc*)unk, 1);
    func_020a27b8(field4);
    TextQueue_Reset((Obj020d7aa0*)TextQueue_GetInstance());
    *(unsigned short*)(field4 + 0x21e) = Camera_GetOrbitYaw(field4);

    if (LinkSession_IsActive((int*)search)) {
        char* arr = (char*)GameState_GetParty(gs);
        for (int i = 0; i < *(unsigned char*)(arr + 0xf7c); i++) {
            GameObject* combatant = func_0200ff1c(gs, *(unsigned char*)(arr + i + 0xf78));
            if (combatant != NULL) {
                func_02053ec8(combatant, 3);
                func_02053ed8(combatant);
            }
        }
    }

    int count;
    int ids[4];
    GameState_GetPartyMemberIds((Base02010834*)gs, GameState_GetProtagonistIndex(gs), ids, &count);
    for (int i = 0; i < count; i++) {
        GameObject* member = gs->GetPartyMemberByIndex(ids[i]);
        if (member != NULL) {
            GameObject_PauseMovement((Flags02033fcc*)member);
            if (GameObject_IsClimbingLadder((char*)member) == 0 || GameObject_GetLadderClimb(member)->command != 2) {
                member->obj3D_.SetAnimationByName(data_ov017_021d7d6c, 0x10);
            }
            GameObject_ResetTrail((unsigned char*)member);
        }
    }
    GameObject* extra = gs->GetPartyMemberByIndex(0xce);
    if (extra != NULL) {
        GameObject_ResetTrail((unsigned char*)extra);
    }
    func_ov017_021bb088((Struct_ov017_021baedc*)self->unknown_d0_);
    int* var15 = func_02010768(gs);
    var15[0] = 0;
    var15[1] = 0;
    loader->AddFence();

    if (self->unknown_9c_ != 0) {
        self->unknown_74_ = loader->QueueLoadFile(data_ov017_021d7d9e, NULL);
    } else if (self->unknown_cc_ != 0) {
        char* name = *(char**)((char*)Zone3D_GetInstance() + 8);
        if (gs->GetGameObjectByIndex(self->unknown_cd_) == NULL || strstr(name + 5, data_ov017_021d7db8) == NULL ||
            strstr(name + 5, data_ov017_021d7dbb) == NULL) {
            SetBrightness(res, 0, 0x28);
            func_ov017_021bb27c(self);
            self->unknown_1_ = 1;
            return self->unknown_a_;
        }
        return 0xc;
    } else {
        unsigned int id = self->unknown_8_;
        if (id >= 0x5208 && id < 0x9c40) {
            self->unknown_74_ = loader->QueueLoadFile(data_ov017_021d7dbf, NULL);
            loader->GetNumQueuedTasks();
        } else if (id >= 0x9c40) {
            self->unknown_74_ = loader->QueueLoadFile(data_ov017_021d7de0, NULL);
        } else {
            self->unknown_74_ = loader->QueueLoadFile(data_ov017_021d7df9, NULL);
        }
    }
    return 1;
}
