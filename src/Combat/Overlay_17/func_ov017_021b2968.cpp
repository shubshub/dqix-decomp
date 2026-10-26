#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Graphics/VRAMStaging.h"

extern "C" int func_020429d4(void);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord02046708;
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
void SetMainBrightness(GameResources*, int, int);
void SetBrightness(GameResources*, int, int);
extern "C" void GameObject_EnableControl(void* obj);

struct Struct_ov017_021b2968 {
    unsigned char pad0;
    unsigned char flag1;
    char pad2[0x36];
    unsigned int unknown_38_;
};

// USA: func_ov017_021b2968
extern "C" ARM int func_ov017_021b2968(struct Struct_ov017_021b2968* self) {
    GameResources* var0 = GetGameResources();

    unsigned int var1 = (self->unknown_38_ << 28) >> 31;
    if (var1) {
        void* buf = (void*)func_020429d4();
        memset(buf, 0, 0x800);
        StageMemoryToVRAM(VRAMSubregion_MainBG1Screen, buf, 0, 0x800, true, false);
        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, buf, 0, 0x800, true, false);
        StageMemoryToVRAM(VRAMSubregion_MainBG3Screen, buf, 0, 0x800, true, false);
        StageMemoryToVRAM(VRAMSubregion_MainBG1Character, buf, 0, 0x20, true, false);
        StageMemoryToVRAM(VRAMSubregion_MainBG2Character, buf, 0, 0x20, true, false);
        StageMemoryToVRAM(VRAMSubregion_MainBG3Character, buf, 0, 0x20, true, false);

        struct FlagWord02046708* flagWord = (struct FlagWord02046708*)GlobalFlags_GetInstance();
        if (!FlagWord_TestBits(flagWord, 1) && !FlagWord_TestBits(flagWord, 0x40)) {
            SetMainBrightness((GameResources*)var0, 0, 0x28);
        } else {
            SetBrightness((GameResources*)var0, 0, 0x28);
        }
    }

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetLeader();
    if (combatant) {
        GameObject_EnableControl(combatant);
    }

    self->flag1 = 1;
    return 8;
}
