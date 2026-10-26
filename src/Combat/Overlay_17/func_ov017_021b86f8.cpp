#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/TextQueue.h"
#include "Resource/Brightness.h"

struct Struct_020708c8;
struct Struct_02012de8;

struct Struct_ov017_021b86f8 {
    char unknown_0_[0x24];
    unsigned short unknown_24_;
    char unknown_26_[0x6ac - 0x26];
    void* unknown_6ac_;
    char unknown_6b0_[0x6b4 - 0x6b0];
    unsigned short unknown_6b4_;
    unsigned short unknown_6b6_;
};

extern char g_bgmPlayer[];
#if defined(jpn)
extern char data_ov017_021d83e7[];
#endif

void MessageSystem_GetInstance(void);
int GameState_GetProtagonistIndex(GameState* gs);
GameObject* GetCombatantChecked_0200ff94(GameState* battleStruct, int combatantId);
extern "C" EffectParam020708c8* func_020704fc(void);
FlagWord02046708* GlobalFlags_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
void* TextQueue_GetInstance(void);
int StandardStrings_Get(int value);
void* GetOffsetPtr02160f08(void* obj);
extern "C" void func_ov000_02172850(void* obj);
float GetIntAt0xc_020709ac(unsigned char* obj);
void SetScaledEffectParam020708c8(EffectParam020708c8* obj, unsigned int value);
extern "C" int abs(int x);
void SetMainBrightness(GameResources* res, int level, int b);
int FlagWord_TestBits(FlagWord02046708* word, unsigned int mask);
struct FlagWord020466f4;
void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int bits);
void SetCombatModeFromCase020dc2d0(int mode);
int GetState0209ca68(char* p);
extern "C" void func_0209c530(void* p);
extern "C" void func_ov017_021c9c64(unsigned short a, int b);
void SetFieldForMatchingCombatant_021c98f4(int target, int flag);

// USA: func_ov017_021b86f8
extern "C" ARM void func_ov017_021b86f8(BattleScene021b86f8* self, int combatantId, int showMessage, int arg3) {
    if (self->field_0x6ac == NULL) return;
    if (combatantId != self->activeCombatantId || self->state != 2) return;
    GameState* gs = GameState::GetInstance();
    MessageSystem_GetInstance();
    GameObject* combatant = GetCombatantChecked_0200ff94(gs, GameState_GetProtagonistIndex(gs));
    GameResources* res = GetGameResources();
    EffectParam020708c8* effect = func_020704fc();
    FlagWord02046708* flagWord = GlobalFlags_GetInstance();
    Zone3D_GetInstance();
    if (combatant != NULL) {
        if (showMessage) {
#if defined(jpn)
            TextQueue_Push(TextQueue_GetInstance(), data_ov017_021d83e7, 0, 0, 1);
#else
            TextQueue_Push(TextQueue_GetInstance(), (void*)StandardStrings_Get(0x23), 0, 0, 1
#if !defined(jpn)
                , 1
#endif
            );
#endif

        }
        func_ov000_02172850(func_ov000_02160f08(arg0->unknown_6ac_));
    }
    if ((int)func_020709ac((unsigned char*)var3) > 0x1e) {
        func_020708c8(var3, 0x1e);
    }
    if (abs(GetBrightness((GameResources*)var2, false)) == 0x10) {
        SetMainBrightness(var2, 0, 0x1e);
    }
    if (FlagWord_TestBits(flagWord, 1)) {
        FlagWord_ClearBits((FlagWord020466f4*)flagWord, 1);
        SetCombatModeFromCase020dc2d0(0);
    }
    if (GetState0209ca68(g_bgmPlayer) == 2) {
        func_0209c530(g_bgmPlayer);
    }
    FlagWord_ClearBits((FlagWord020466f4*)flagWord, 0x200);
    ClearFlags04(res, 0x40);
    ClearFlags04(res, 4);
    ClearFlags04(res, 0x10);
    ClearFlags04(res, 2);
    ClearFlags00(res, 4);
    self->flags |= 0x2000;
    self->state = 3;
    func_ov017_021c9c64(combatantId, arg3);
    SetFieldForMatchingCombatant_021c98f4(combatantId, 1);
}
