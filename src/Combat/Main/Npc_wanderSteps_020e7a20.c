// The steps a wandering NPC can take: fx32 unit vectors +x, +z, -x, -z (x, y, z each).
// Npc_PickWanderStep clamps the NPC into its wander box, keeps the steps that head back into the box,
// and walks it one step (one unit) along a random one of them.
// Seen in-game: four wandering NPCs in Angel Falls moved one unit at a time and stayed within their boxes.
// Originally data_020e7a20 (USA 0x020e7a20, EUR 0x020e7a30, JPN 0x020e837c); defined in C for usa.
const int Npc_wanderSteps[4][3] = {{0x1000, 0, 0}, {0, 0, 0x1000}, {-0x1000, 0, 0}, {0, 0, -0x1000}};
