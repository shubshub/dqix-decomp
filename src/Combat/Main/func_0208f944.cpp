#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Grotto/Main/DetailedTreasureMapData.h"

extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int ZoneId_IsGrotto(int id);
extern "C" int ZoneId_IsGrottoBossFloor(int x);

struct Struct_0208f944 {
    char unknown_0_[IS_JPN ? 0x280 : 0x260];
    unsigned char f260;
    char unknown_261_;
    unsigned char unknown_262_;
    char unknown_263_[5];
    unsigned int unknown_268_;
    unsigned int unknown_26c_;
    unsigned int unknown_270_;
    unsigned short unknown_274_;
};

struct State0208f944 {
    unsigned short h0;
    char unknown_2_[5];
    unsigned char unknown_7_;
    char unknown_8_[2];
    unsigned char unknown_a_;
    char unknown_b_[5];
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned short unknown_1c_;
};

// USA: func_0208f944
extern "C" ARM void func_0208f944(struct Struct_0208f944* obj) {
    GameState* battle = GameState::GetInstance();
    struct State0208f944* state = (struct State0208f944*)GameState_GetZoneTransition(battle);
    struct GrottoStruct* grotto = battle->GetGrottoStruct();
    void* misc = Zone3D_GetInstance();
    int a = state->h0;
    int b = *(unsigned short*)misc;

    if (obj->unknown_262_ != 0 && a != 0xc3b5) {
        state->h0 = obj->unknown_274_;
        state->unknown_7_ = 1;
        state->unknown_1c_ = 0x3244;
        state->unknown_10_ = obj->unknown_268_;
        state->unknown_14_ = obj->unknown_26c_;
        state->unknown_18_ = obj->unknown_270_;
        state->unknown_a_ = 0;
        a = obj->unknown_274_;
    }

    obj->unknown_262_ = 0;

    if (!ZoneId_IsGrotto(a)) {
        if (ZoneId_IsGrotto(b)) {
            if (a < 0x7530 || a > 0x9c3f) {
                ((DetailedTreasureMapData*)obj)->Clear();
            }
        }
    }

    if (ZoneId_IsGrotto(a) && !ZoneId_IsGrotto(b)) {
        signed char var6 = grotto->unknown_8;
        if (var6 != -1) {
            if (!ZoneId_IsGrottoBossFloor(a)) {
                int rem = a % 20;
                state->h0 = (unsigned short)((rem + 0x1c40 + 0x8000) + var6 * 20);
            }
        }
    }

    obj->f260 = 0;
}
