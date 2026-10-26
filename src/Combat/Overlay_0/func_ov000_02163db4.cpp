#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

struct Struct_020708c8;
struct Obj020d7aa0;
extern "C" void* LinkSession_GetInstance();
extern "C" Struct_020708c8* func_020704fc();
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void func_020708c8(Struct_020708c8*, unsigned int);
extern "C" int func_ov017_021959b4();
extern "C" void func_020531f0(GameObject*);
extern "C" void func_ov000_02160fa8(void*, int);
extern "C" int func_ov000_02160fd4(void*, int);
extern "C" int func_ov017_02195658(GameResources*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_ov017_021c8b78(unsigned short);
extern "C" void func_020a367c(unsigned char*, int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int GameObject_IsGesturing(signed char*);
#if defined(jpn)
#define func_ov000_02165490 func_ov000_02166bdc
#endif
extern "C" int func_020535e0(int*);
extern "C" Obj020d7aa0* TextQueue_GetInstance();
extern "C" void TextQueue_Reset(Obj020d7aa0*);
extern "C" void func_ov017_021bd5d0(int);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_ov017_02191234(GameResources*);
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void Main_HandleLid();
extern "C" void func_ov000_02164280(void*);
extern "C" void func_ov000_02166e5c(void*);
extern "C" void func_ov000_021643d4(void*);
extern "C" void func_ov000_02164fac(void*);
extern "C" void func_ov000_02165490(void*);
extern "C" void func_ov000_02166880(unsigned char*);
extern "C" void func_ov000_02166978(void*);
extern "C" void SePlayer_LoadArchive(void*, int);
extern "C" void func_ov017_021c812c(int, int);
extern "C" void func_ov017_021c8398(int, int);
extern "C" void func_ov017_021c839c(int, int);
extern "C" void func_ov000_02160d80(void*, int);
extern unsigned char g_sePlayer;
struct Struct_ov000_02163db4 {
    char unknown_0_[8]; unsigned short unknown_8_; char unknown_a_[2]; int mode;
    char unknown_10_[0x2a - 0x10]; signed char partyId; char unknown_2b_; int unknown_2c_;
    char unknown_30_[0x40 - 0x30];
};
struct Struct_ov000_02163db4_2 {
#if defined(jpn)
    char unknown_0_[0x21c]; Struct_ov000_02163db4* config;
    char unknown_220_[0xe44 - 0x220]; unsigned short unknown_ec8_;
#else
    char unknown1_0_[0x2a0]; Struct_ov000_02163db4* config;
    char unknown_2a4_[0xec8 - 0x2a4]; unsigned short unknown_ec8_;
#endif
};
#define REG_DISPLAY_CONTROL (*(volatile unsigned int*)0x04000000)
#define REG_BLEND_CONTROL (*(volatile unsigned short*)0x04000050)
static inline void inline_ov000_02163db4(unsigned char* config, unsigned char index) {
    func_020a367c(config, index);
}

// USA: func_ov000_02163db4
extern "C" ARM void func_ov000_02163db4(Struct_ov000_02163db4_2* scene) {
    GameState* state = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    LinkSession_GetInstance();
    Struct_020708c8* effect = func_020704fc();
    LinkMessageQueue_GetInstance();
    SetBrightness(resources, -16, 0);
    func_020708c8(effect, 0);
    if (func_ov017_021959b4()) {
        for (int i = 0; i < 4; i++) {
            GameObject* combatant = func_0200ff1c(state, i);
            if (combatant) func_020531f0(combatant);
        }
        func_ov000_02160fa8(scene, 0x2000000);
    }
    Struct_ov000_02163db4* config = scene->config;
    int partyId = func_ov017_02195658(resources);
    if (func_020a35e0((unsigned char*)config, partyId & 0xff)) {
        if (config->partyId == partyId) {
            func_ov000_02160fa8(scene, 0x2000000);
            func_ov017_021c8b78(config->unknown_8_);
        }
        inline_ov000_02163db4((unsigned char*)config, partyId);
    }
    if (scene->config->partyId != GameState_GetProtagonistIndex(state) && !func_ov000_02160fd4(scene, 2)) return;
    for (int i = 0; i < 4; i++) {
        GameObject* combatant = func_0200ff1c(state, i);
        if (!combatant) continue;
        if (func_020a35e0((unsigned char*)scene->config, i & 0xff)) {
            if (GameObject_IsGesturing((signed char*)combatant)) func_020531f0(combatant);
        } else {
            if (func_020535e0((int*)combatant)) func_020531f0(combatant);
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
    func_ov000_02166880((unsigned char*)scene);
    Main_HandleLid();
    func_ov000_02166978(scene);
    Main_HandleLid();
    SePlayer_LoadArchive(&g_sePlayer, 0x65);
    REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x1100;
    REG_BLEND_CONTROL = 0;
    if (scene->config->unknown_2c_) {
        func_ov017_021c812c((unsigned char)scene->config->partyId, 1);
        func_ov017_021c8398((unsigned char)scene->config->partyId, 1);
        func_ov017_021c839c((unsigned char)scene->config->partyId, 1);
    } else {
        func_ov000_02160fa8(scene, 0x200000);
    }
    if (scene->unknown_ec8_ == 0x785d || scene->unknown_ec8_ == 0x77f7 || scene->unknown_ec8_ == 0x77f5) {
        SetFlags04(resources, 0x200000);
    }
    func_ov000_02160d80(scene, 1);
}
