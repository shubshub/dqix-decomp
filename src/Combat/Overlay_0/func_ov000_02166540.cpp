#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02166540 {
    unsigned short unknown_0_0_ : 15;
    unsigned short unknown_1_7_ : 1;
    unsigned char unknown_2_[0xe];
    unsigned int unknown_10_0_ : 28;
    unsigned int unknown_13_4_ : 1;
    unsigned int unknown_13_5_ : 3;
};
struct Struct_ov000_02166540_4 {
    Object3D object;
    unsigned char unknown_ac_[4];
    Struct_ov000_02166540* unknown_b0_;
};
struct Struct_ov000_02166540_5 {
    unsigned char unknown_0_[0x36];
    unsigned short name;
    unsigned char unknown_38_[0x6c];
};
struct Struct_ov000_02166540_7 {
    Object3D object;
    unsigned char unknown_ac_[4];
    unsigned short scale;
    unsigned char unknown_b2_[0x10];
    unsigned char flags;
    unsigned char unknown_c3_[0x75];
    Struct_ov000_02166540_5* stats;
    unsigned char unknown_13c_[0x40];
    unsigned char mode;
    unsigned char unknown_17d_[0x13];
};
struct Struct_ov000_02166540_8 { unsigned char data[0x70]; };
struct Struct_ov000_02166540_9 {
    unsigned char unknown_0_[0x400];
    unsigned char search[0xc];
    unsigned char names[0xc];
};
struct Struct_ov000_02166540_2 {
    union {
        struct {
            unsigned char unknown_0_[0x158];
            Struct_ov000_02166540_5 stats[8];
            unsigned char search[0xc];
            unsigned char names[0xc];
        };
        struct {
            unsigned char unknown1_0_[0x278];
            Struct_ov000_02166540_9 lookup;
        };
    };
};
struct Struct_ov000_02161c0c_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x21c];
#else
    unsigned char unknown1_0_[0x2a0];
#endif
    Struct_ov000_02166540_2* roster;
    unsigned char unknown_2a4_[0xc14];
    Struct_ov000_02166540_4* unknown_eb8_[4];
    unsigned short unknown_ec8_;
#if defined(jpn)
    unsigned char unknown_e46_[0x6014 - 0xe46];
#else
    unsigned char unknown_eca_[0x4f5a];
#endif
    Struct_ov000_02166540_7 unknown_5e24_[8];
    Struct_ov000_02166540_8 models[8];
};
struct Struct_02070b6c_3;
struct Struct_0204887c;
struct Struct_0206f01c_2;
struct Bytes02033b88;
struct Struct_ov000_02166540_3 {
    unsigned char unknown_0_[0xc];
    short scale;
};
extern "C" void func_02048614(unsigned char*);
extern "C" void func_02049c88(Struct_ov000_02166540_7*, Struct_ov000_02166540_8*);
extern "C" void func_02048588(unsigned char*, unsigned char*);
extern "C" void func_020488ec(char*);
extern "C" char* func_02070fd0(Struct_02070b6c_3*, int);
extern "C" void func_0204887c(Struct_0204887c*, char*);
extern "C" void func_02048bb8(unsigned char*);
extern "C" void func_02048bf8(unsigned char*);
extern "C" Struct_ov000_02166540_3* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" void func_ov000_02166784(Struct_ov000_02161c0c_3*, unsigned char*, unsigned char*);
extern "C" int func_ov000_02167c28(unsigned char*, int);
extern "C" void func_ov017_02191aac(void*, int, int, int);

// USA: func_ov000_02166540
extern "C" ARM void func_ov000_02166540(Struct_ov000_02161c0c_3* state, int slot, int id, unsigned char mode) {
    if (slot < 0xc0 || slot > 0xc7) return;
    GameState* game = GameState::GetInstance();
    void* effects = GetGameResources();
    Struct_ov000_02166540_9* roster = &state->roster->lookup;
    int index = slot - 0xc0;
    Struct_ov000_02166540_4* source = 0;
    for (int i = 0; i < 4; i++) {
        Struct_ov000_02166540_4* candidate = state->unknown_eb8_[i];
        if (candidate && id == candidate->object.unknown_2_) {
            source = candidate;
            break;
        }
    }
    if (!source) return;
    Struct_ov000_02166540_7* combatant = &state->unknown_5e24_[index];
    if (!combatant) return;
    func_02048614((unsigned char*)combatant);
    Struct_ov000_02166540_8* model = &state->models[index];
    if (!model) return;
    func_02049c88(combatant, model);
    combatant->flags |= 0x20;
    func_02048588((unsigned char*)source, (unsigned char*)combatant);
    combatant->object.SetField06(state->unknown_ec8_);
    combatant->mode = mode;
    combatant->stats = &state->roster->stats[index];
    func_020488ec((char*)combatant);
    if (combatant->stats->name) {
        char* name = func_02070fd0((Struct_02070b6c_3*)state->roster->names, combatant->stats->name);
        if (name) func_0204887c((Struct_0204887c*)combatant, name);
    }
    combatant->object.EnableFlag(8);
    Struct_ov000_02166540* var10 = source->unknown_b0_;
    if (var10) {
        if (!var10->unknown_13_4_) func_02048bb8((unsigned char*)combatant);
        if (!var10->unknown_1_7_) func_02048bf8((unsigned char*)combatant);
    }
    Struct_ov000_02166540_3* entry = func_0206f4f0((Struct_0206f01c_2*)roster->search, (short)id);
    if (entry) {
        int value = entry->scale << 2;
        unsigned int scale = 0x324;
        if (value >= 0x4000) scale = 0xc9;
        else if (value >= 0x3000) scale = 0x10c;
        else if (value >= 0x2000) scale >>= 1;
        combatant->scale = scale;
    }
    GameObject_ForceMotionState((Bytes02033b88*)combatant, 0);
    func_0200fd38(game, slot, (GameObject*)combatant);
    func_ov000_02166784(state, (unsigned char*)source, (unsigned char*)combatant);
    func_ov000_02167c28((unsigned char*)state, slot);
    GameObject* var14 = game->GetCombatantByIndex(slot);
    if (var14) {
        struct Struct_ov000_02166540_6 { unsigned char unknown_0_[0x14]; unsigned int flags; };
        if (((Struct_ov000_02166540_6*)var14->currentStats_)->flags & 0x1000000) func_ov017_02191aac(effects, 1, slot, 4);
    }
}
