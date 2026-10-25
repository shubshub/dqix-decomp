#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#include <std_library_functions.h>
#endif

struct Struct_ov001_0215657c_2 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    char unknown_c_[0xa];
    unsigned short unknown_16_;
    unsigned short unknown_18_;
#if defined(jpn)
    char unknown_1a_[0x76];
#else
    char unknown1_1a_[0x7a];
#endif
    int unknown_94_;
    char unknown_98_[0xba];
    unsigned short unknown_152_;
    unsigned short unknown_154_;
    unsigned short unknown_156_;
    unsigned short unknown_158_;
};
#if defined(jpn)
struct Struct_02046574_2 {
    char unknown_0_[0x868];
    int unknown_998_;
    char unknown_86c_[0xf76];
    unsigned char unknown_19b2_;
    char unknown_17e3_[0xb];
    unsigned char unknown_19be_;
};
extern const char data_ov001_021661e8[];
#else
struct Struct_02046574_2 {
    char unknown_0_[0x998];
    int unknown_998_;
    char unknown_99c_[0x1016];
    unsigned char unknown_19b2_;
    char unknown_19b3_[0xb];
    unsigned char unknown_19be_;
};
#endif
struct Rgb02070900 { int red; int green; int blue; };
struct EffectParam02070900;
struct Timer020707c8;
struct EventFlags0215657c { char field_0[0x8c]; unsigned char flags[1]; };
char* GetFieldIfFlag4_020100f8(char*);
extern "C" EventFlags0215657c* Scenario_GetInstance();
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" unsigned short* Zone3D_GetInstance();
Obj02046574* MessageSystem_GetInstance();
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
int StandardStrings_Get(int);
extern "C" void MessageSystem_FormatText(Obj02046574*, int, int, char*, int, int, int);
#if defined(jpn)
extern "C" void func_0204500c(Struct_02046574_2*, char*, int);
#else
extern "C" void func_0204500c(Struct_02046574_2*, char*, int, int);
#endif
void SetMainBrightness(GameResources*, int, int);
extern "C" Struct_02070900_2* func_020704fc();
extern "C" void func_02070900(Struct_02070900_2*, Struct_02070900*, unsigned int);
extern "C" void func_020707c8(Struct_020707c8*);
extern "C" void func_0209c2e0(void*, int, int);
extern "C" void func_02046a8c(void*, void*);
extern "C" void func_ov017_021bb0c4(unsigned char*);
void SetBrightness(GameResources*, int, int);
void FollowCamera_EnableFollow(void*);
void ApplyVecFromField0x246_020a2718(char*);
extern "C" void func_ov017_021bb27c(void*);
extern int g_bgmPlayer __attribute__((aligned(4)));

// USA: func_ov001_0215657c
extern "C" ARM int func_ov001_0215657c(Struct_ov001_0215657c_2* arg0, void* arg1) {
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return arg0->unknown_a_;
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    var0->GetUnknownGameObject();
    char* var2 = func_020100f8((char*)var0);
    int var3 = 0;
    int var4 = 0;
    void* var5 = var1->unknown_ptr_3718;
    if (arg0->unknown_16_ == arg0->unknown_152_) var3 = 1;
    else if (arg0->unknown_18_ == arg0->unknown_158_) var3 = 1;
    else {
        EventFlags0215657c* flags = Scenario_GetInstance();
        if (Scenario_TestFlag((int)flags, flags->flags, transition->flag + 0x38e)) blocked = 1;
        else if (transition->area == *Zone3D_GetInstance()) sameArea = 1;
    }
    if (blocked) {
        GameState* state = GameState::GetInstance();
        GameResources* display = GetGameResources();
        Obj02046574* message = MessageSystem_GetInstance();
        GameObject* member = GetCombatantWithFlag0x100_0200ff1c(state, 0);
        if (member) {
            char* name = (char*)member->baseStats_;
#if defined(jpn)
            char var12[0x50];
            sprintf(var12, data_ov001_021661e8, var11);
            func_0204500c(var9, var12, 0);
#else
            MessageSystem_SetStringArgument(message, 0, name);
            char text[0x100];
            int messageId = StandardStrings_Get(0x34);
            MessageSystem_FormatText(message, 12, messageId, text, 0xe3, 0, 1);
            func_0204500c(message, text, 0, 0xe3);
#endif
            var9->unknown_998_ = 1;
            var9->unknown_19b2_ = 0;
            var9->unknown_19be_ = 1;
        }
        SetMainBrightness(var8, 0, 1);
        Struct_02070900_2* var15 = func_020704fc();
        Struct_02070900 var16 = {};
        func_02070900(var15, &var16, 0);
        func_020707c8((Struct_020707c8*)var15);
        return 5;
    }
    if (sameArea) {
        transition->destination = transition->targetId;
        func_0209c2e0(&g_bgmPlayer, transition->context, 0);
        func_02046a8c(list, node);
        ClearFields_021bb0c4((unsigned char*)transition);
        return 0;
    }
    SetBrightness(resources, 0, 30);
    FollowCamera_EnableFollow(field);
    ApplyVecFromField0x246_020a2718(field);
    func_0209c2e0(&g_bgmPlayer, transition->context, 0);
    func_ov017_021bb27c(transition);
    transition->done = 1;
    func_02046a8c(list, node);
    return transition->state;
}
