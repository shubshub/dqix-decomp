#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02073dfc_348 = 0x150, Enum_02073dfc_352 = 0x154 };
#else
enum { Enum_02073dfc_348 = 0x15c, Enum_02073dfc_352 = 0x160 };
#endif
#include "GameState/GameState.h"

struct Struct_02073dfc { int x; int y; int z; };
struct Struct_02028460_3 { int x; int y; int z; };
struct U16Field0x6_020375f8 { char unk[0x6]; unsigned short field; };

extern "C" struct Struct_02073dfc func_02034104(GameObject* combatant);
struct Vector3i;

// USA: func_02073dfc
extern "C" ARM int func_02073dfc(unsigned short* arg0, struct Struct_02028460_3* arg1) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant;
    for (int i = 0; i < 4; i++) {
        combatant = battleStruct->GetPartyMemberByIndex(i);
        if (combatant == 0) continue;
        int targetId = ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06();
        struct Struct_02073dfc local = func_02034104(combatant);
        if (*(int*)((char*)combatant + Enum_02073dfc_348) != -1) {
            targetId = *(int*)((char*)combatant + Enum_02073dfc_348);
            if (i == 0 || (combatant->obj3D_.unknown_0_ & 0x1000)) {
                *(Vector3i*)((int*)&local) = *(Vector3i const*)((int*)((char*)combatant + Enum_02073dfc_352));
            }
        }
        if (*arg0 == targetId) {
            int dist = Vector3fix_Distance((const Vector3fix*)arg1, (const Vector3fix*)((struct Struct_02028460_3*)&local));
            if (dist < 0x3800) {
                return 1;
            }
        }
    }
    return 0;
}
