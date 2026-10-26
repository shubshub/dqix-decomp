#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

struct EffectParam020708c8;
struct Obj020d7aa0;
extern "C" void* LinkSession_GetInstance();
extern "C" EffectParam020708c8* func_020704fc();
void* LinkMessageQueue_GetInstance();
void SetScaledEffectParam020708c8(EffectParam020708c8*, unsigned int);
extern "C" int func_ov017_021959b4();
extern "C" void func_020531f0(GameObject*);
extern "C" void func_ov000_02160fa8(void*, int);
extern "C" int func_ov000_02160fd4(void*, int);
extern "C" int func_ov017_02195658(GameResources*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
void EnqueueEventTag122_021c8b78(unsigned short);
void ClearBitAt0x34_020a367c(unsigned char*, int);
int GameState_GetProtagonistIndex(GameState*);
int GameObject_IsGesturing(signed char*);
#if defined(jpn)
#define func_ov000_02165490 func_ov000_02166bdc
#endif
int IsField0x180NonNegative_020535e0(int*);
Obj020d7aa0* TextQueue_GetInstance();
void TextQueue_Reset(Obj020d7aa0*);
extern "C" void func_ov017_021bd5d0(int);
int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_ov017_02191234(GameResources*);
unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void Main_HandleLid();
extern "C" void func_ov000_02164280(void*);
extern "C" void func_ov000_02166e5c(void*);
extern "C" void func_ov000_021643d4(void*);
extern "C" void func_ov000_02164fac(void*);
extern "C" void func_ov000_02165490(void*);
extern "C" void func_ov000_02166880(unsigned char*);
extern "C" void func_ov000_02166978(void*);
void SePlayer_LoadArchive(void*, int);
extern "C" void func_ov017_021c812c(int, int);
void EmptyStub_ov017_021c8398(int, int);
void NoOp_021c839c(int, int);
void SetFieldsAndSignalData02184220_ov000_02160d80(void*, int);
extern unsigned char g_sePlayer;
struct BattleConfig02163db4 {
    char pad_0[8]; unsigned short eventTag; char pad_a[2]; int mode;
    char pad_10[0x2a - 0x10]; signed char partyId; char pad_2b; int field_2c;
    char pad_30[0x40 - 0x30];
};
struct Struct_ov000_02163db4_2 {
#if defined(jpn)
    char unknown_0_[0x21c]; Struct_ov000_02163db4* unknown_2a0_;
    char unknown_220_[0xe44 - 0x220]; unsigned short unknown_ec8_;
#else
    char unknown1_0_[0x2a0]; Struct_ov000_02163db4* unknown_2a0_;
    char unknown_2a4_[0xec8 - 0x2a4]; unsigned short unknown_ec8_;
#endif
};
#define REG_DISPLAY_CONTROL (*(volatile unsigned int*)0x04000000)
#define REG_BLEND_CONTROL (*(volatile unsigned short*)0x04000050)
static inline void inline_ov000_02163db4(unsigned char* arg0, unsigned char arg1) {
    func_020a367c(arg0, arg1);
}

// USA: func_ov000_02163db4
extern "C" ARM void func_ov000_02163db4(BattleScene02163db4* scene) {
    GameState* state = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    LinkSession_GetInstance();
    EffectParam020708c8* effect = func_020704fc();
    LinkMessageQueue_GetInstance();
    SetBrightness(resources, -16, 0);
    SetScaledEffectParam020708c8(effect, 0);
    if (func_ov017_021959b4()) {
        for (int var4 = 0; var4 < 4; var4++) {
            GameObject* var5 = func_0200ff1c(var0, var4);
            if (var5) func_020531f0(var5);
        }
        func_ov000_02160fa8(arg0, 0x2000000);
    }
    Struct_ov000_02163db4* var6 = arg0->unknown_2a0_;
    int var7 = func_ov017_02195658(var1);
    if (func_020a35e0((unsigned char*)var6, var7 & 0xff)) {
        if (var6->unknown_2a_ == var7) {
            func_ov000_02160fa8(arg0, 0x2000000);
            func_ov017_021c8b78(var6->unknown_8_);
        }
        inline_ov000_02163db4((unsigned char*)var6, var7);
    }
    if (scene->config->partyId != GameState_GetProtagonistIndex(state) && !GetCombatWorkFlags0x55f4_ov000_02160fd4(scene, 2)) return;
    for (int i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(state, i);
        if (!combatant) continue;
        if (TestBitAt0x34_020a35e0((unsigned char*)scene->config, i & 0xff)) {
            if (GameObject_IsGesturing((signed char*)combatant)) func_020531f0(combatant);
        } else {
            if (func_020535e0((int*)var9)) func_020531f0(var9);
        }
    }
    TextQueue_Reset(TextQueue_GetInstance());
    if (scene->config->mode >= 0) func_ov017_021bd5d0(scene->config->mode);
    if (loader->GetNumQueuedTasks() > 0) return;
    if (!FieldTaskQueue_IsEmpty((void**)resources->unknown_ptr_array_3700[0])) return;
    func_ov017_02191234(resources);
    SetFlags00(resources, 0x10);
    unsigned int* data = GlobalFlags_GetInstance();
    FlagWord_SetBits(data, 1);
    FlagWord_SetBits(data, 2);
    FlagWord_SetBits(data, 0x2000);
    Main_HandleLid();
    func_ov000_02164280(scene);
    if (scene->config->mode == 0x1a && !state->GetGameObjectByIndex(1)) func_ov000_02166e5c(scene);
    Main_HandleLid();
    func_ov000_021643d4(scene);
    Main_HandleLid();
    func_ov000_02164fac(scene);
    Main_HandleLid();
    func_ov000_02165490(scene);
    Main_HandleLid();
    InitAndProcessCombat02166880((unsigned char*)scene);
    Main_HandleLid();
    func_ov000_02166978(scene);
    Main_HandleLid();
    SePlayer_LoadArchive(&g_sePlayer, 0x65);
    REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x1100;
    REG_BLEND_CONTROL = 0;
    if (arg0->unknown_2a0_->unknown_2c_) {
        func_ov017_021c812c((unsigned char)arg0->unknown_2a0_->unknown_2a_, 1);
        func_ov017_021c8398((unsigned char)arg0->unknown_2a0_->unknown_2a_, 1);
        func_ov017_021c839c((unsigned char)arg0->unknown_2a0_->unknown_2a_, 1);
    } else {
        func_ov000_02160fa8(arg0, 0x200000);
    }
    if (arg0->unknown_ec8_ == 0x785d || arg0->unknown_ec8_ == 0x77f7 || arg0->unknown_ec8_ == 0x77f5) {
        SetFlags04(var1, 0x200000);
    }
    func_ov000_02160d80(arg0, 1);
}
