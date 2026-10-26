#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"

unsigned char GameObject_IsClimbingLadder(char* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);
int GameState_GetFollowCamera(char* obj);
int GetField0x21c020a277c(void* obj);
void SetField0x21c_020a2770(void* obj, short value);
typedef void (*SetField0x21cIntFn)(void* obj, int value);
void LinkSession_UpdatePartySize(void* obj);

struct Buf16_02191108 { int x[4]; };
extern "C" void func_ov017_02190884(int b, struct Buf16_02191108* outBuf, int* zero, int c, int d, int e);
extern "C" void* LinkSession_GetInstance(void* ctx);

extern "C" void func_020a2be8(void* obj);

// Overlay 17, originally func_ov017_02191108 (USA/EUR 0x02191108, JPN 0x02191cec)
extern "C" ARM void Party_ReformLine(void* unused, int c, int d, int e, int flag) {
    GameState* battle = GameState::GetInstance();
    if (battle->GetProtagonist() == 0) return;

    GameObject* combatant2 = battle->GetLeader();
    if (combatant2 != 0 && GameObject_IsClimbingLadder((char*)combatant2) != 0) {
        SubBlock02038508* field = GameObject_GetLadderClimb(combatant2);
        field->unknown52 = 1;
        return;
    }

    int zero = 0;
    int fieldVal = GameState_GetProtagonistIndex(battle);
    struct Buf16_02191108 buf;
    func_ov017_02190884(fieldVal, &buf, &zero, c, d, e);
    int idx = buf.x[0];

    GameObject* combatant = battle->GetGameObjectByIndex(idx);
    if (combatant != 0) {
        ((Object3D*)((unsigned char*)combatant))->DisableFlag(0x80);
    }

    void* p2 = (void*)GameState_GetFollowCamera((char*)battle);
    if (p2 != 0) {
        int val = GetField0x21c020a277c(p2);
        if (val != 0xc9 && val != 0xca) {
            ((SetField0x21cIntFn)SetField0x21c_020a2770)(p2, idx);
            if (flag != 0 && val != idx) {
                func_020a2be8(p2);
            }
        }
    }

    unsigned char* ptr = (unsigned char*)GameState_GetParty(battle);
    int i;
    for (i = 0; i < zero; i++) {
        unsigned char* dst = ptr + i;
        dst[0xf78] = (unsigned char)buf.x[i];
    }
    ptr[0xf7c] = (unsigned char)zero;
    LinkSession_UpdatePartySize(LinkSession_GetInstance(ptr));
}
