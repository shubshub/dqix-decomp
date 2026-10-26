#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

struct Struct_0208fa8c { unsigned short unknown_0_; unsigned short unknown_2_; };
struct Struct_02097cac {
    unsigned short unknown_0_;
    char unknown_2_[0x63];
    unsigned char unknown_65_;
};
struct Struct_02097cac_2 {
    char unknown_0_[0x1b3c];
    unsigned int unknown_1b3c_;
};

extern "C" void* LinkSession_GetInstance();
extern "C" ZoneState* Zone3D_GetInstance();
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);
void* GameState_GetZoneTransition(GameState* battleStruct);
int IsIdInRange020981e4(int a, int id);
int IsIdInRange02098240(int a, int id);
int IsIdInSet02098210(int a, int id);
void UpdateRankLevel020989cc(Base020989cc* base);
void EnqueueEventTag186_021d3e3c(unsigned char tag);

#define FLAG130(obj) (*(int*)(*(void**)((char*)(obj) + 0x130)))

// USA: func_02097cac
extern "C" ARM void func_02097cac(Base020989cc* state) {
    void* search = LinkSession_GetInstance();
    GameState* gameState = GameState::GetInstance();
    ZoneState02097cac* zoneState = (ZoneState02097cac*)GameState_GetZoneTransition(gameState);
    ZoneState* currentZone = Zone3D_GetInstance();
    int zoneId = zoneState->zoneId;
    GameObject* protagonist;
    int previousZoneId = currentZone->zoneId;

    if (!func_020981e4((int)arg0, var4) &&
        !func_020981e4((int)arg0, var6)) return;

    var5 = var1->GetProtagonist();

    if (IsIdInSet02098210((int)state, zoneId) &&
        (!IsIdInSet02098210((int)state, previousZoneId) || zoneState->flag65 != 0)) {
        if (LinkSession_IsHostOrSolo(search) != 0 && (FLAG130(protagonist) & 1) == 0) {
            UpdateRankLevel020989cc(state);
        }
        int var7 = arg0->unknown_1b3c_;
        func_ov017_021d3e3c(var7);
        switch (var7) {
            case 1:
            case 2: var2->unknown_0_ = 0xc3b5; break;
            case 3:
            case 4: var2->unknown_0_ = 0xc419; break;
            case 5: var2->unknown_0_ = 0xc47d; break;
            case 6: var2->unknown_0_ = 0xc4e1; break;
        }
        GameState_SetZoneTransition(gameState, zoneState);
    } else {
        if (LinkSession_IsGuest(search) == 0 || zoneState->flag65 == 0) return;
        int progress = state->progress;
        if (!IsIdInRange020981e4((int)state, zoneId)) return;
        if (IsIdInRange02098240((int)state, zoneId)) return;
        if (zoneId == 0xc3bb) return;
        if (zoneId == 0xc3bc) return;
        if (zoneId == 0xc3bd) return;
        if (zoneId == 0xc3be) return;
        int rem = zoneState->zoneId % 100;
        int base = rem + 0xc350;
        switch (progress) {
            case 1:
            case 2: var2->unknown_0_ = (unsigned short)(var10 + 0x64); break;
            case 3:
            case 4: var2->unknown_0_ = (unsigned short)(var10 + 0xc8); break;
            case 5: var2->unknown_0_ = (unsigned short)(var10 + 0x12c); break;
            case 6: var2->unknown_0_ = (unsigned short)(var10 + 0x190); break;
        }
    }
}
