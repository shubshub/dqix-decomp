#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "Combat/BufferedScriptResult.h"

#if defined(jpn)
#define data_ov017_021d7c10 data_ov017_021d832c
#endif
struct Obj020397cc { char padding[0xb2]; short unknown_b2_; };
struct Struct_02046f84 { char padding[0xf0]; };
struct BattleLoad021b6290 {
    unsigned char type, unknown_1_;
    char padding2[6];
    unsigned char flag8;
    char unknown_9_[3];
    Struct_02046f84 action;
    unsigned char state, delay;
    short unknown_fe_, task;
};
struct Actor0209c678;
struct Struct_0203e5d8;
struct ListHead02046b60;
extern "C" void* Zone3D_GetInstance();
extern "C" unsigned char* func_020704fc();
extern "C" void func_02017c58(void*);
extern "C" int func_02046cc8(Struct_02046f84*);
extern "C" int func_0204700c(Struct_02046f84*);
extern "C" void* func_ov017_021b8478(void*);
extern "C" void func_0209c480(Actor0209c678*, int);
extern "C" void func_0209c2e0(Actor0209c678*, int, int);
extern "C" void func_0205e944(void*, int);
extern "C" void MessageSystem_Stop(void*);
extern "C" int abs(int);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void BgmPlayer_FadeOut(Actor0209c678*, int);
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void* MessageSystem_GetInstance();
extern "C" Struct_0203e5d8* func_0203cf4c();
extern "C" void func_0203e5d8(Struct_0203e5d8*, int);
extern "C" float func_020709ac(unsigned char*);
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void func_02047198(Struct_02046f84*);
extern "C" void func_02046f84(Struct_02046f84*);
extern "C" void func_ov017_0218d274(void* controller);
extern "C" void func_ov017_0218f79c(void*);
extern "C" void func_ov017_021a2840(GameResources*);
extern char data_ov017_021d7c10[];
extern Actor0209c678 g_bgmPlayer;
extern char g_sePlayer[];
// Overlay 17, originally func_ov017_021b6290 (USA/EUR 0x021b6290, JPN 0x021b6844)
extern "C" ARM void FieldTask_EnterBattle(BattleLoad021b6290* self) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    Zone3D_GetInstance();
    Obj020397cc* actor = (Obj020397cc*)game->GetLeader();
    unsigned char* var3 = func_020704fc();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* var5 = resources->unknown_ptr_3718;
    if (self->state == 0) {
        GameObject_DisableControl(actor, 1);
        actor->unknown_b2_ = 0;
        if (self->unknown_fe_ >= 0) {
            self->task = loader->QueueLoadFile(data_ov017_021d7c10, 0);
            BgmPlayer_FadeOut(&g_bgmPlayer, 10);
        }
        if (self->unknown_fe_ <= 0) self->delay = 0;
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
                Struct_02074060 var9;
                Struct_02074060* result = &var9;
                if (func_02046b60((ListHead02046b60*)resources->fieldTaskQueue_, 10)) {
                    void* var11 = func_ov017_021b8478(var5);
                    if (var11) result = (Struct_02074060*)((char*)var11 + 0x10);
                }
                if (func_0207416c(result, self->unknown_fe_, data, length)) id = result->unknown_e_;
                loader->RemoveTask(self->task);
                self->task = BackgroundLoader::TaskStatus_Invalid;
            }
            func_0209c480(&g_bgmPlayer, id);
            func_0209c2e0(&g_bgmPlayer, 127, 0);
            func_0205e944(g_sePlayer, 127);
            SetFlags04(resources, 0x40);
            MessageSystem_Stop(MessageSystem_GetInstance());
            func_0203e5d8(func_0203cf4c(), 0);
            if ((int)func_020709ac(var3) > 30 || abs(GetBrightness((GameResources*)resources, false)) == 16) {
                SetMainBrightness(resources, -16, 0);
                if (GetBrightness((GameResources*)resources, true) == Brightness_Normal) {
                    SetSubBrightness(resources, -16, 15);
                }
                self->state = 4;
            } else self->state = 3;
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
            func_02047198(&self->action);
            func_02046f84(&self->action);
            func_ov017_0218d274(resources);
            func_ov017_0218f79c(resources);
            func_ov017_021a2840(resources);
            func_0203e5d8(func_0203cf4c(), 1);
            self->unknown_1_ = 1;
        }
    }
}
