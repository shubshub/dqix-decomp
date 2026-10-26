// The new hero's bare body colour for each eye colour: CharacterCreationUI_HandleConfirm writes entry eyeColor[sex]
// into the party member's bareBodyColor (+0x56a); party members made later get a random one of 16 instead.
// It picks the colour of the clothes shown with no body armour: CharacterModel_Load adds it to the body file's
// number (seen in-game: female d_b629 at 0, d_b641 at 12; the top orange at 0, dark grey at 12).
// Originally CharacterCreationUI_bareBodyColors (USA/EUR 0x0218a9b4, JPN 0x0218b988); defined in C from ZevyaDev/dqix-decomp#319.
const unsigned char CharacterCreationUI_bareBodyColors[8] = {12, 13, 4, 1, 6, 7, 9, 14};
