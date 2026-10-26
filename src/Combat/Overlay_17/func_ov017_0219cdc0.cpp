#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02010604;
#if defined(jpn)
enum { Enum_ov017_0219cdc0_396 = 0x180 };
#else
enum { Enum_ov017_0219cdc0_396 = 0x18c };
#endif
extern "C" void* LinkSession_GetInstance();
int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_02048150(GameObject*, int, int);
int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_ov017_021cedf4(int, int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void Party_ReformLine(void*, int, int, int, int);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
int GetSignedByte0x2d0_020546a8(void*);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
void GameObject_ClearHidden(unsigned char*);
extern "C" int LinkSession_IsHostOrSolo(void*);
void* GameState_GetParty(GameState*);

static inline int inline_ov017_0219cdc0(unsigned short arg0, unsigned short arg1) { return arg0 == arg1; }
static inline int inline_ov017_0219cdc0_2(unsigned short arg0, unsigned short arg1) { return !inline_ov017_0219cdc0(arg0, arg1); }

// USA: func_ov017_0219cdc0
extern "C" ARM void func_ov017_0219cdc0(unsigned short destinationZone, int wholeParty, signed char memberId) {
    GameState* state = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    int special = !NotEqual(destinationZone, 10100);
    unsigned short category = (destinationZone / 100) * 100;
    int recover = (special | (category == 4100)) != 0;
    recover = (recover | (category == 4300)) != 0;
    recover = (recover | (category == 4500)) != 0;
    recover = (recover | (category == 6400)) != 0;
    int fullRecovery = (special | (category == 4300)) != 0;
    fullRecovery = (fullRecovery | (category == 6400)) != 0;
    int reviveParty = Equal(destinationZone, 50101) != 0;
    reviveParty = (reviveParty | (destinationZone == 50201)) != 0;
    reviveParty = (reviveParty | (destinationZone == 50301)) != 0;
    reviveParty = (reviveParty | (destinationZone == 50401)) != 0;
    if (recover) {
        int id = GameState_GetProtagonistIndex(state);
        if (!wholeParty) id = memberId;
        GameObject* member = (GameObject*)state->GetPartyMemberByIndex(id);
        if (member && (**(unsigned int**)((char*)member + 0x130) & 1)) {
            if (fullRecovery) func_02048150(member, 1, 1);
            else func_02048150(member, 0, 1);
            (*(unsigned int*)((char*)member + ActorFlagsOffset)) &= ~1;
            GameObject_ForceMotionState((Bytes02033b88*)member, 0);
            if (wholeParty) {
                func_ov017_021cedf4(id, 1, 0);
                func_ov017_021c9e00(id, 0, 0, 1);
                Party_ReformLine(resources, 1, 1, 1, 1);
            } else {
                if (state->GetPartyMemberByIndex(id)) {
                    GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(state, memberId);
                    if (combatant) id = GetSignedByte0x2d0_020546a8(combatant);
                    CallHelperWithBuf_021907dc((int)resources, id, 1, 1, 1);
                    GameObject* linked = (GameObject*)state->GetPartyMemberByIndex(id);
                    if (linked) {
                        linked->obj3D_.SetInheritedAlpha(31);
                        GameObject_ClearHidden((unsigned char*)linked);
                    }
                }
            }
        }
    }
    if (reviveParty && LinkSession_IsHostOrSolo(search) && wholeParty) {
        unsigned char* party = (unsigned char*)GameState_GetParty(state);
        GameObject* member;
        int allRevived;
        int i;
        int id;
        allRevived = 1;
        for (i = 0; i < party[0xf7c]; i++) {
            id = (party + i)[0xf78];
            member = (GameObject*)state->GetPartyMemberByIndex(id);
            if (!member) continue;
            GameObject* object = state->GetGameObjectByIndex(id * 12 + 20);
            if (object && (object->obj3D_.unknown_2_ == 9031 || object->obj3D_.unknown_2_ == 9032 || object->obj3D_.unknown_2_ == 9033)) {
                if (**(unsigned int**)((char*)member + 0x130) & 1) {
                    func_02048150(member, 0, 1);
                    (*(unsigned int*)((char*)member + ActorFlagsOffset)) &= ~1;
                    GameObject_ForceMotionState((Bytes02033b88*)member, 0);
                    func_ov017_021cedf4(id, 1, 0);
                    func_ov017_021c9e00(id, 0, 0, 1);
                    Party_ReformLine(resources, 1, 1, 1, 1);
                }
            } else if (var16 && !(**(unsigned int**)((char*)var13 + 0x130) & 1)) var14 = 0;
        }
        if (allRevived && wholeParty) {
            GameObject* protagonist = (GameObject*)state->GetProtagonist();
            if (protagonist && (**(unsigned int**)((char*)protagonist + 0x130) & 1)) {
                func_02048150(protagonist, 0, 1);
                (*(unsigned int*)((char*)protagonist + ActorFlagsOffset)) &= ~1;
                GameObject_ForceMotionState((Bytes02033b88*)protagonist, 0);
                func_ov017_021cedf4(0, 1, 0);
                func_ov017_021c9e00(0, 0, 0, 1);
                Party_ReformLine(resources, 1, 1, 1, 1);
            }
        }
    }
}
