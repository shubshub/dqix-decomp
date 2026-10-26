#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

struct ZoneState { unsigned short zoneId; unsigned short unknown_2_; };
struct ZoneState02097cac {
    unsigned short zoneId;
    char pad0[0x63];
    unsigned char flag65;
};
struct Struct_02097cac_2 {
    char pad0[0x1b3c];
    unsigned int progress;
};

extern "C" void* LinkSession_GetInstance();
extern "C" ZoneState* Zone3D_GetInstance();
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" int func_020981e4(int a, int id);
extern "C" int func_02098240(int a, int id);
extern "C" int func_02098210(int a, int id);
extern "C" void func_020989cc(Struct_02097cac_2* base);
extern "C" void func_ov017_021d3e3c(unsigned char tag);

#define FLAG130(obj) (*(int*)(*(void**)((char*)(obj) + 0x130)))

// USA: func_02097cac
extern "C" ARM void func_02097cac(Struct_02097cac_2* state) {
    void* search = LinkSession_GetInstance();
    GameState* gameState = GameState::GetInstance();
    ZoneState02097cac* zoneState = (ZoneState02097cac*)GameState_GetZoneTransition(gameState);
    ZoneState* currentZone = Zone3D_GetInstance();
    int zoneId = zoneState->zoneId;
    GameObject* protagonist;
    int var6 = currentZone->zoneId;

    if (!func_020981e4((int)state, zoneId) &&
        !func_020981e4((int)state, var6)) return;

    protagonist = gameState->GetProtagonist();

    if (func_02098210((int)state, zoneId) &&
        (!func_02098210((int)state, var6) || zoneState->flag65 != 0)) {
        if (LinkSession_IsHostOrSolo(search) != 0 && (FLAG130(protagonist) & 1) == 0) {
            func_020989cc(state);
        }
        int progress = state->progress;
        func_ov017_021d3e3c(progress);
        switch (progress) {
            case 1:
            case 2: zoneState->zoneId = 0xc3b5; break;
            case 3:
            case 4: zoneState->zoneId = 0xc419; break;
            case 5: zoneState->zoneId = 0xc47d; break;
            case 6: zoneState->zoneId = 0xc4e1; break;
        }
        GameState_SetZoneTransition(gameState, zoneState);
    } else {
        if (LinkSession_IsGuest(search) == 0 || zoneState->flag65 == 0) return;
        int progress = state->progress;
        if (!func_020981e4((int)state, zoneId)) return;
        if (func_02098240((int)state, zoneId)) return;
        if (zoneId == 0xc3bb) return;
        if (zoneId == 0xc3bc) return;
        if (zoneId == 0xc3bd) return;
        if (zoneId == 0xc3be) return;
        int rem = zoneState->zoneId % 100;
        int base = rem + 0xc350;
        switch (progress) {
            case 1:
            case 2: zoneState->zoneId = (unsigned short)(base + 0x64); break;
            case 3:
            case 4: zoneState->zoneId = (unsigned short)(base + 0xc8); break;
            case 5: zoneState->zoneId = (unsigned short)(base + 0x12c); break;
            case 6: zoneState->zoneId = (unsigned short)(base + 0x190); break;
        }
    }
}
