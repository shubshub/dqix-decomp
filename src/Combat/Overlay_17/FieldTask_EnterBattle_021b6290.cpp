#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "Combat/BufferedScriptResult.h"

#if defined(jpn)
#define data_ov017_021d7c10 data_ov017_021d832c
#endif
struct Struct_02018300_3 { char unknown_0_[0xb2]; short unknown_b2_; };
struct Struct_02046f84 { char unknown_0_[0xf0]; };
struct Struct_ov017_021b6290 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[6];
    unsigned char unknown_8_;
    char unknown_9_[3];
    Struct_02046f84 unknown_c_;
    unsigned char unknown_fc_, unknown_fd_;
    short unknown_fe_, unknown_100_;
};
struct Actor0209c678;
struct RootEntries;
struct ListHead02046b60;
extern "C" void* Zone3D_GetInstance();
extern "C" unsigned char* func_020704fc();
extern "C" void func_02017c58(void*);
extern "C" int func_02046cc8(Struct_02046f84*);
extern "C" int func_0204700c(Struct_02046f84*);
extern "C" void* func_ov017_021b8478(void*);
extern "C" void func_0209c480(Struct_02109bf4_4*, int);
extern "C" void func_0209c2e0(Struct_02109bf4_4*, int, int);
extern "C" void func_0205e944(void*, int);
extern "C" void MessageSystem_Stop(void*);
extern "C" int abs(int);
void GameObject_DisableControl(Obj020397cc*, int);
void BgmPlayer_FadeOut(Actor0209c678*, int);
int ListContainsId(ListHead02046b60*, int);
void* MessageSystem_GetInstance();
RootEntries* GetGlobalPtr021075f4_0203cf4c();
void SetOrClearBit0x10OnEntries_0203e5d8(RootEntries*, int);
float GetIntAt0xc_020709ac(unsigned char*);
unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
void EmptyStub02047198(Struct02046f84*);
void ResetObjectAndAllocator02046f84(Struct02046f84*);
void ConfigureModeByByte_0218d274_0218d274(void* controller);
void ProcessCombatantsIfFlagged_0218f79c(void*);
void ProcessSlotField58_021a2840(GameResources*);
extern char data_ov017_021d7c10[];
extern Actor0209c678 g_bgmPlayer;
extern char g_sePlayer[];
// Overlay 17, originally func_ov017_021b6290 (USA/EUR 0x021b6290, JPN 0x021b6844)
extern "C" ARM void FieldTask_EnterBattle(BattleLoad021b6290* self) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    Zone3D_GetInstance();
    Obj020397cc* actor = (Obj020397cc*)game->GetLeader();
    unsigned char* timing = func_020704fc();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* streamOwner = resources->unknown_ptr_3718;
    if (self->state == 0) {
        GameObject_DisableControl(actor, 1);
        actor->field_b2 = 0;
        if (self->streamID >= 0) {
            self->task = loader->QueueLoadFile(data_ov017_021d7c10, 0);
            BgmPlayer_FadeOut(&g_bgmPlayer, 10);
        }
        if (self->streamID <= 0) self->delay = 0;
        if (self->flag8) func_02017c58(Zone3D_GetInstance());
        self->state = 1;
    }
    if (self->delay) --self->delay;
    if (self->state == 1) {
        if (func_02046cc8(&self->action)) self->state = 2;
    } else if (self->state == 2) {
        if (self->delay == 0) {
            int id = 23;
            if (self->task > BackgroundLoader::TaskStatus_Invalid) {
                if (!loader->GetTaskStatus(self->task)) return;
                void* data;
                unsigned int length;
                loader->GetLoadedFileByID(self->task, &data, &length);
                BufferedScriptResult temporary;
                BufferedScriptResult* result = &temporary;
                if (ListContainsId((ListHead02046b60*)resources->fieldTaskQueue_, 10)) {
                    void* overrideState = func_ov017_021b8478(streamOwner);
                    if (overrideState) result = (BufferedScriptResult*)((char*)overrideState + 0x10);
                }
                if (func_0207416c(var10, arg0->unknown_fe_, var7, var8)) var6 = var10->unknown_e_;
                var4->RemoveTask(arg0->unknown_100_);
                arg0->unknown_100_ = BackgroundLoader::TaskStatus_Invalid;
            }
            func_0209c480(&g_bgmPlayer, id);
            func_0209c2e0(&g_bgmPlayer, 127, 0);
            func_0205e944(g_sePlayer, 127);
            SetFlags04(resources, 0x40);
            MessageSystem_Stop(MessageSystem_GetInstance());
            SetOrClearBit0x10OnEntries_0203e5d8(GetGlobalPtr021075f4_0203cf4c(), 0);
            if ((int)GetIntAt0xc_020709ac(timing) > 30 || abs(GetBrightness((GameResources*)resources, false)) == 16) {
                SetMainBrightness(resources, -16, 0);
                if (GetBrightness((GameResources*)resources, true) == Brightness_Normal) {
                    SetSubBrightness(resources, -16, 15);
                }
                arg0->unknown_fc_ = 4;
            } else arg0->unknown_fc_ = 3;
        }
    } else if (self->state == 3) {
        if (func_0204700c(&self->action)) self->state = 4;
    } else if (self->state == 4) {
        if (!IsBrightnessTransitionActive(resources)) {
            SetFlags04(resources, 4);
            SetFlags04(resources, 16);
            SetFlags04(resources, 2);
            SetFlags00(resources, 4);
            FlagWord_SetBits(GlobalFlags_GetInstance(), 1);
            EmptyStub02047198(&self->action);
            ResetObjectAndAllocator02046f84(&self->action);
            ConfigureModeByByte_0218d274_0218d274(resources);
            ProcessCombatantsIfFlagged_0218f79c(resources);
            ProcessSlotField58_021a2840(resources);
            SetOrClearBit0x10OnEntries_0203e5d8(GetGlobalPtr021075f4_0203cf4c(), 1);
            self->complete = 1;
        }
    }
}
