#if defined(jpn)
enum { RegionOffset6c = 0x8c };
#else
enum { RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void GameObject_PlaceInZone(GameObject* combatant, unsigned short arg1, int* vec3, int value);

extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" unsigned char GameObject_IsClimbingLadder(char* obj);
struct Vector3i;

struct Owner_1e80c;
struct S_e820;
struct ThreeWords_1e80c { int field0; int field4; int field8; };
extern "C" ThreeWords_1e80c ZoneFeatures_GetDefaultPosition(Owner_1e80c* src);
extern "C" int ZoneFeatures_GetDefaultAngle(S_e820* p);

// USA: func_ov017_0219c598
extern "C" ARM void func_ov017_0219c598(int* arg0, short* arg1, int arg2) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* field3f8 = (unsigned char*)GameState_GetZoneTransition(battleStruct);
    void* dataBase = Zone3D_GetInstance();
    ((int)GetGameResources());
    unsigned char* field2a04 = (unsigned char*)GameState_GetParty(battleStruct);
    GameObject* combatant = battleStruct->GetLeader();

    if (field3f8[0xa] != 0 && arg2 == 0) {
        return;
    }
    if (field3f8[0x67] != 0 && GameObject_IsClimbingLadder((char*)combatant) != 0) {
        return;
    }

    int vec3[3];
    int angle;
    int i;
    if (arg0 != 0) {
        *(Vector3i*)vec3 = *(Vector3i const*)arg0;
        if (arg1 != 0) {
            angle = *arg1;
        }
    } else if (field3f8[0x7] != 0) {
        *(Vector3i*)vec3 = *(Vector3i const*)((int*)(field3f8 + 0x10));
        angle = *(short*)(field3f8 + 0x1c);
    } else {
        *(Vector3i*)vec3 = *(Vector3i const*)((int*)&ZoneFeatures_GetDefaultPosition((Owner_1e80c*)((char*)dataBase + RegionOffset6c)));
        angle = ZoneFeatures_GetDefaultAngle((S_e820*)((char*)dataBase + RegionOffset6c));
    }

    int value = fix32ReduceAngle0To2Pi(angle);

    for (i = 0; i < field2a04[0xf7c]; i++) {
        GameObject* c = battleStruct->GetPartyMemberByIndex((field2a04 + i)[0xf78]);
        if (c != 0) {
            GameObject_PlaceInZone(c, *(unsigned short*)dataBase, vec3, value);
        }
    }

    if (field2a04[0xf7d] != 0) {
        GameObject* c = battleStruct->GetPartyMemberByIndex(0xce);
        if (c != 0) {
            GameObject_PlaceInZone(c, *(unsigned short*)dataBase, vec3, value);
        }
    }
}
