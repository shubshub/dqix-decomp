// The monsters that can wait inside a chest: when FieldTask_OpenChest's ambush step finds the container's monster id
// among FieldTask_ambushMonsterIds, it names the monster with the text id at the same index.
// Originally data_ov017_021d6ac0 (USA/EUR 0x021d6ac0, JPN 0x021d6ec0).
const unsigned char FieldTask_ambushMonsterIds[3] = {0x26, 0x27, 0x28};
// Originally data_ov017_021d6ac4 (USA/EUR 0x021d6ac4; JPN keeps const char* names at 0x021d7fb4 instead).
const short FieldTask_ambushMonsterNames[3] = {0x2e, 0x2f, 0x30};
