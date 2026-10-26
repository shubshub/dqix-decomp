#include <globaldefs.h>

extern "C" int NpcWalker_WalkTo(void* obj, int arg);
extern "C" int NpcModel_WalkTo(void* obj, int arg);

// An NPC (an entry of the actor list, data_021075f4).
struct Npc {
    char pad[0x14];
    void* walker;   // its NpcWalker (at its own +0x20)
    void* model;    // its 3D-model mover (NpcModel_WalkTo), used when it has no walker; null for the NPCs seen
};

// Main, originally DispatchOnActiveChild020409b0 (USA 0x020409b0, EUR 0x020409c0, JPN 0x02040eac)
extern "C" ARM int Npc_WalkTo(struct Npc* npc, int target) {
    if (npc->walker != NULL) {
        return NpcWalker_WalkTo(npc->walker, target);
    }
    {
        void* model = npc->model;
        if (model != NULL) {
            return NpcModel_WalkTo(model, target);
        }
        return (int)model;
    }
}
