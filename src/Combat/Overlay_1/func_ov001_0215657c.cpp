#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#include <std_library_functions.h>
#endif

struct Struct_ov001_0215657c_2 {
    char field_0;
    unsigned char done;
    char unknown_2_[6];
    unsigned short destination;
    unsigned short state;
    char unknown_c_[0xa];
    unsigned short unknown_16_;
    unsigned short unknown_18_;
#if defined(jpn)
    char field_1a[0x76];
#else
    char field_1a[0x7a];
#endif
    int context;
    char unknown_98_[0xba];
    unsigned short targetId;
    unsigned short flag;
    unsigned short area;
    unsigned short unknown_158_;
};
#if defined(jpn)
struct Obj02046574 {
    char field_0[0x868];
    int active;
    char unknown_86c_[0xf76];
    unsigned char unknown_19b2_;
    char unknown_17e3_[0xb];
    unsigned char unknown_19be_;
};
extern const char data_ov001_021661e8[];
#else
struct Obj02046574 {
    char field_0[0x998];
    int active;
    char unknown_99c_[0x1016];
    unsigned char unknown_19b2_;
    char unknown_19b3_[0xb];
    unsigned char unknown_19be_;
};
#endif
struct Struct_02070900 { int red; int green; int blue; };
struct Struct_02070900_2;
struct Struct_020707c8;
struct EventFlags0215657c { char field_0[0x8c]; unsigned char flags[1]; };
extern "C" char* GameState_GetFollowCamera(char*);
extern "C" EventFlags0215657c* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" unsigned short* Zone3D_GetInstance();
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" int StandardStrings_Get(int);
extern "C" void MessageSystem_FormatText(Obj02046574*, int, int, char*, int, int, int);
#if defined(jpn)
extern "C" void func_0204500c(Obj02046574*, char*, int);
#else
extern "C" void func_0204500c(Obj02046574*, char*, int, int);
#endif
void SetMainBrightness(GameResources*, int, int);
extern "C" Struct_02070900_2* func_020704fc();
extern "C" void func_02070900(Struct_02070900_2*, Struct_02070900*, unsigned int);
extern "C" void func_020707c8(Struct_020707c8*);
extern "C" void func_0209c2e0(void*, int, int);
extern "C" void func_02046a8c(void*, void*);
extern "C" void func_ov017_021bb0c4(unsigned char*);
void SetBrightness(GameResources*, int, int);
extern "C" void FollowCamera_EnableFollow(void*);
extern "C" void func_020a2718(char*);
extern "C" void func_ov017_021bb27c(void*);
extern int g_bgmPlayer __attribute__((aligned(4)));

// USA: func_ov001_0215657c
extern "C" ARM int func_ov001_0215657c(Struct_ov001_0215657c_2* transition, void* list) {
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return transition->state;
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    game->GetLeader();
    char* field = GameState_GetFollowCamera((char*)game);
    int blocked = 0;
    int sameArea = 0;
    void* node = resources->unknown_ptr_3718;
    if (transition->unknown_16_ == transition->targetId) blocked = 1;
    else if (transition->unknown_18_ == transition->unknown_158_) blocked = 1;
    else {
        EventFlags0215657c* flags = Scenario_GetInstance();
        if (Scenario_TestFlag((int)flags, flags->flags, transition->flag + 0x38e)) blocked = 1;
        else if (transition->area == *Zone3D_GetInstance()) sameArea = 1;
    }
    if (blocked) {
        GameState* state = GameState::GetInstance();
        GameResources* display = GetGameResources();
        Obj02046574* message = MessageSystem_GetInstance();
        GameObject* member = func_0200ff1c(state, 0);
        if (member) {
            char* name = (char*)member->baseStats_;
#if defined(jpn)
            char text[0x50];
            sprintf(text, data_ov001_021661e8, name);
            func_0204500c(message, text, 0);
#else
            MessageSystem_SetStringArgument(message, 0, name);
            char text[0x100];
            int messageId = StandardStrings_Get(0x34);
            MessageSystem_FormatText(message, 12, messageId, text, 0xe3, 0, 1);
            func_0204500c(message, text, 0, 0xe3);
#endif
            message->active = 1;
            message->unknown_19b2_ = 0;
            message->unknown_19be_ = 1;
        }
        SetMainBrightness(display, 0, 1);
        Struct_02070900_2* effect = func_020704fc();
        Struct_02070900 color = {};
        func_02070900(effect, &color, 0);
        func_020707c8((Struct_020707c8*)effect);
        return 5;
    }
    if (sameArea) {
        transition->destination = transition->targetId;
        func_0209c2e0(&g_bgmPlayer, transition->context, 0);
        func_02046a8c(list, node);
        func_ov017_021bb0c4((unsigned char*)transition);
        return 0;
    }
    SetBrightness(resources, 0, 30);
    FollowCamera_EnableFollow(field);
    func_020a2718(field);
    func_0209c2e0(&g_bgmPlayer, transition->context, 0);
    func_ov017_021bb27c(transition);
    transition->done = 1;
    func_02046a8c(list, node);
    return transition->state;
}
