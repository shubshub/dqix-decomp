#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

int fix32sin(int x);
int fix32cos(int x);
extern "C" int rand(void);

struct NpcWanderSteps {
    Vector3i directions[4];   // +x, +z, -x, -z
};

extern struct NpcWanderSteps Npc_wanderSteps;

// Where an NPC may wander: an axis-aligned box. In mode 8 the NPC instead paces back and forth along one line at
// angle (only its steps change; the box stays axis-aligned).
struct NpcWanderBox {
    char pad0[0x1f];
    unsigned char mode;
    char pad20[2];
    short angle;
    int xMax;
    int zMax;
    int xMin;
    int zMin;
};

// An NPC (an entry of the actor list, data_021075f4).
struct Npc {
    char pad0[0xc];
    struct NpcWanderBox* wanderBox;
    char pad10[4];
    void* walker;   // its NpcWalker (at its own +0x20)
    void* model;    // its 3D-model mover (NpcModel_WalkTo), used when it has no walker; null for the NPCs seen
};
extern int Npc_WalkTo(struct Npc* obj, int arg);

// Main, originally func_02040f48 (USA 0x02040f48, EUR 0x02040f58, JPN 0x02041444)
// Sends the NPC one unit from where it is (clamped into its wander box) in a random one of the step directions
// it may take: all four inside the box, only those heading back in when it's past an edge.
extern "C" ARM void Npc_PickWanderStep(struct Npc* self, Vector3i* from) {
    struct NpcWanderSteps steps = Npc_wanderSteps;
    Vector3i target = *from;
    Vector3i choices[4];

    if (self->wanderBox->mode == 8) {
        int sine = fix32sin(self->wanderBox->angle);
        int cosine = fix32cos(self->wanderBox->angle);
        if (sine < 0) sine = -sine;
        if (cosine < 0) cosine = -cosine;
        if (self->wanderBox->angle < 0x191e || (self->wanderBox->angle > 0x323d && self->wanderBox->angle < 0x4b5c)) {
            steps.directions[0].x = sine;
            steps.directions[0].z = cosine;
            steps.directions[1].x = sine;
            steps.directions[1].z = cosine;
            steps.directions[2].x = -sine;
            steps.directions[2].z = -cosine;
            steps.directions[3].x = -sine;
            steps.directions[3].z = -cosine;
        } else {
            steps.directions[0].x = sine;
            steps.directions[0].z = -cosine;
            steps.directions[1].x = sine;
            steps.directions[1].z = -cosine;
            steps.directions[2].x = -sine;
            steps.directions[2].z = cosine;
            steps.directions[3].x = -sine;
            steps.directions[3].z = cosine;
        }
    }

    int count = 0;
    if (target.x < self->wanderBox->xMax) {
        choices[count] = steps.directions[0];
        count++;
    }
    if (target.z < self->wanderBox->zMax) {
        choices[count] = steps.directions[1];
        count++;
    }
    if (target.x > self->wanderBox->xMin) {
        choices[count] = steps.directions[2];
        count++;
    }
    if (target.z > self->wanderBox->zMin) {
        choices[count] = steps.directions[3];
        count++;
    }

    if (target.x > self->wanderBox->xMax) target.x = self->wanderBox->xMax;
    if (target.z > self->wanderBox->zMax) target.z = self->wanderBox->zMax;
    if (target.x < self->wanderBox->xMin) target.x = self->wanderBox->xMin;
    if (target.z < self->wanderBox->zMin) target.z = self->wanderBox->zMin;

    int pick = rand() % count;
    Vector3fix_Add((const Vector3fix*)&target, (const Vector3fix*)&choices[pick], (Vector3fix*)&target);
    Npc_WalkTo(self, (int)&target);
}
