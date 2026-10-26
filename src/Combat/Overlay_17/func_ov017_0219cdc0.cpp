#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Bytes02033b88;
#if defined(jpn)
enum { Enum_ov017_0219cdc0_396 = 0x180 };
#else
enum { Enum_ov017_0219cdc0_396 = 0x18c };
#endif
extern "C" void* LinkSession_GetInstance();
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_02048150(GameObject*, int, int);
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_ov017_021cedf4(int, int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void Party_ReformLine(void*, int, int, int, int);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" int func_020546a8(void*);
extern "C" void func_ov017_021907dc(int, int, int, int, int);
extern "C" void GameObject_ClearHidden(unsigned char*);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void* GameState_GetParty(GameState*);

static inline int inline_ov017_0219cdc0(unsigned short value, unsigned short key) { return value == key; }
static inline int inline_ov017_0219cdc0_2(unsigned short value, unsigned short key) { return !inline_ov017_0219cdc0(value, key); }

// USA: func_ov017_0219cdc0
extern "C" ARM void func_ov017_0219cdc0(unsigned short destinationZone, int wholeParty, signed char memberId) {
    GameState* state = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    int special = !inline_ov017_0219cdc0_2(destinationZone, 10100);
    unsigned short category = (destinationZone / 100) * 100;
    int var5 = (special | (category == 4100)) != 0;
    var5 = (var5 | (category == 4300)) != 0;
    var5 = (var5 | (category == 4500)) != 0;
    var5 = (var5 | (category == 6400)) != 0;
    int var6 = (special | (category == 4300)) != 0;
    var6 = (var6 | (category == 6400)) != 0;
    int reviveParty = inline_ov017_0219cdc0(destinationZone, 50101) != 0;
    reviveParty = (reviveParty | (destinationZone == 50201)) != 0;
    reviveParty = (reviveParty | (destinationZone == 50301)) != 0;
    reviveParty = (reviveParty | (destinationZone == 50401)) != 0;
    if (var5) {
        int id = GameState_GetProtagonistIndex(state);
        if (!wholeParty) id = memberId;
        GameObject* member = (GameObject*)state->GetPartyMemberByIndex(id);
        if (member && (**(unsigned int**)((char*)member + 0x130) & 1)) {
            if (var6) func_02048150(member, 1, 1);
            else func_02048150(member, 0, 1);
            (*(unsigned int*)((char*)member + Enum_ov017_0219cdc0_396)) &= ~1;
            GameObject_ForceMotionState((Bytes02033b88*)member, 0);
            if (wholeParty) {
                func_ov017_021cedf4(id, 1, 0);
                func_ov017_021c9e00(id, 0, 0, 1);
                Party_ReformLine(resources, 1, 1, 1, 1);
            } else {
                if (state->GetPartyMemberByIndex(id)) {
                    GameObject* combatant = func_0200ff58(state, memberId);
                    if (combatant) id = func_020546a8(combatant);
                    func_ov017_021907dc((int)resources, id, 1, 1, 1);
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
        int var14;
        int i;
        int id;
        var14 = 1;
        for (i = 0; i < party[0xf7c]; i++) {
            id = (party + i)[0xf78];
            member = (GameObject*)state->GetPartyMemberByIndex(id);
            if (!member) continue;
            GameObject* object = state->GetGameObjectByIndex(id * 12 + 20);
            if (object && (object->obj3D_.unknown_2_ == 9031 || object->obj3D_.unknown_2_ == 9032 || object->obj3D_.unknown_2_ == 9033)) {
                if (**(unsigned int**)((char*)member + 0x130) & 1) {
                    func_02048150(member, 0, 1);
                    (*(unsigned int*)((char*)member + Enum_ov017_0219cdc0_396)) &= ~1;
                    GameObject_ForceMotionState((Bytes02033b88*)member, 0);
                    func_ov017_021cedf4(id, 1, 0);
                    func_ov017_021c9e00(id, 0, 0, 1);
                    Party_ReformLine(resources, 1, 1, 1, 1);
                }
            } else if (id && !(**(unsigned int**)((char*)member + 0x130) & 1)) var14 = 0;
        }
        if (var14 && wholeParty) {
            GameObject* protagonist = (GameObject*)state->GetProtagonist();
            if (protagonist && (**(unsigned int**)((char*)protagonist + 0x130) & 1)) {
                func_02048150(protagonist, 0, 1);
                (*(unsigned int*)((char*)protagonist + Enum_ov017_0219cdc0_396)) &= ~1;
                GameObject_ForceMotionState((Bytes02033b88*)protagonist, 0);
                func_ov017_021cedf4(0, 1, 0);
                func_ov017_021c9e00(0, 0, 0, 1);
                Party_ReformLine(resources, 1, 1, 1, 1);
            }
        }
    }
}
