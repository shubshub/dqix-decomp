#pragma once

#include "GameState/PartyMember.h"

// The spells each vocation learns and at which level, as SpellTable_Load fills it from data/prm/spelltable.bin.

enum
{
    SpellTable_SpellsPerVocation = 20,
};

struct SpellTableEntry { unsigned short spell; unsigned short level; };
struct SpellTable {
    char unk_0[0x10c];
    SpellTableEntry spells[Vocation_Count][SpellTable_SpellsPerVocation];
    char unk_51c[0x34];
};
