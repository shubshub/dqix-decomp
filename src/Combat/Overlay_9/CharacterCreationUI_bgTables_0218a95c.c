// Background layer tables of CharacterCreationUI_ApplyTabGraphics. mwcc sorts read-only data by size, so the
// two-byte tables are defined in the order that lands each at its address (ZevyaDev/dqix-decomp#321).
const unsigned char data_ov009_0218a95c = 7; // unreferenced; starts the unit on a word boundary
const unsigned char CharacterCreationUI_paletteSkipModes[2] = {0, 1}; // a tab archive's PALT k is skipped when mode == [k]
const signed char CharacterCreationUI_tabBgPriorities[2] = {2, 1};    // backgrounds 3 and 4
const unsigned char CharacterCreationUI_tabBgNumbers[2] = {0, 1};
const unsigned char CharacterCreationUI_finishBgNumbers[3] = {1, 2, 3}; // backgrounds 0-2, rebuilt on CreationTab_NewGameFinish
const signed char CharacterCreationUI_finishBgScreenCounts[3] = {2, 1, 0};
const signed char CharacterCreationUI_finishBgPriorities[3] = {3, 1, 0};
