#include <globaldefs.h>
#if defined(jpn)
enum { kActorFlagsOffset = 0x1c2 };
#else
enum { kActorFlagsOffset = 0x1ce };
#endif
enum { kActorFlag_Hidden = 4 };

// Area ids: a zone id / 100 (map/maplist9.bin). These four are the areas the hidden actors are kept out of.
enum {
    kArea_Observatory = 41,             // X01 (zones 4100-4110)
    kArea_RealmOfTheAlmighty = 43,      // X03
    kArea_ObservatoryLater = 45,        // X05 (has 'Exterior 4 (Destroyed)' and 'For Ending')
    kArea_StarflightExpress = 64,       // S14
};

#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);

struct Obj02039df4 {
    char pad0[4];
    short actorIndex;                   // Object3D::actorIndex_
    char pad6[0xc2 - 6];
    unsigned char unknown_c2_0_ : 5;
    unsigned char flagBit0xc2 : 1;
    unsigned char unknown_c2_6_ : 2;
    char padc3[kActorFlagsOffset - 0xc3];
    unsigned char flags;                // kActorFlag_*
};

// Main, originally ApplyStatusTickEffect (USA 0x02039df4, EUR 0x02039e04, JPN 0x0203984c)
extern "C" ARM void GameObject_HideInCelestialAreas(struct Obj02039df4* actor) {
    int area;
    GameObject* flaggedActor;

    if (actor->flagBit0xc2) return;
    flaggedActor = func_0200ff58(GameState::GetInstance(), actor->actorIndex);
    if (flaggedActor == NULL) return;
    area = ((Object3D*)actor)->GetField06() / 100;
    if (area != kArea_RealmOfTheAlmighty && area != kArea_ObservatoryLater && area != kArea_StarflightExpress && area != kArea_Observatory) return;
    actor->flags |= kActorFlag_Hidden;
    ((Object3D*)actor)->TransitionInheritedAlpha(0, 0);
    ((Object3D*)actor)->SetInheritedAlpha(0);
}
