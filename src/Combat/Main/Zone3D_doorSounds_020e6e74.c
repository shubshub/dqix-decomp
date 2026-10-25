// The sound effect Zone3D_OpenDoor plays when a door opens, indexed by the door's type
// (param->unk_2c.type2.soundIndex), through SePlayer_Play(&g_sePlayer, sound, 0).
// Seen in-game: the Observatory storeroom's double door played 202 (entry 2), once per leaf.
// Originally data_020e6e74 (USA 0x020e6e74, EUR 0x020e6e84, JPN 0x020e7718); defined in C for usa.
const int Zone3D_doorSounds[5] = {200, 201, 202, 203, 204};
