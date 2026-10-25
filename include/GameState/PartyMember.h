#pragma once

// Per-vocation arrays: PartyMemberData::experience_ and levels_ (indexed by the vocation), and the spell table's rows.
enum Vocation
{
    Vocation_Count = 13,
};

// A party member's looks (PartyMemberData::appearance_): the model ids CharacterModel_GetPartModels turns into the
// ten CharacterModelPart models, then the colours and the body size.
struct PartyMemberAppearance {
    short body_;
    short legs_;
    short face_;
    short hairStyle_;           // also gives the hair texture
    short arms_;
    short feet_;
    short headgear_;
    short weapon_;
    short unk_10;               // goes to part 9
    short unk_12;
    unsigned char female_ : 1;  // CharacterCreationUI::sex; CharacterModel_Load picks the 'w' animations when set
    unsigned char skinColor_ : 3;
    unsigned char eyeColor_ : 4;
    unsigned char hairColor_ : 4;
    unsigned char unk_15_4 : 4;
    short defaultArms_;         // part CharacterModelPart_Arms when arms_ is empty
    short width_;               // CharacterCreationUI_GetBodyDimensions; CharacterModel_SetScale's scales
    short height_;
};

// Three 10-bit stats packed in a word (CharacterCreationUI_HandleConfirm copies them into the party record).
struct PackedStats0218742c {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int reserved : 2;
    void SetFirst(int value) { first = value; }
};

// A party member (what CharacterCreationUI::characterData points to). maxHp_ to power_ are the BattleUnit names of
// PartyMember_RecalculateStats, which writes them; PartyMember_RestoreHpMp copies maxHp_ and maxMp_ into hp_ and mp_.
struct PartyMemberData {
    PackedStats0218742c stats_[4];
    char unk_10[0xc];
    unsigned short hp_;
    unsigned short mp_;
    char unk_20[0x1c];
    char name_[0x30];           // CharacterCreationUI_HandleNameEntry writes the typed name here; its length is not
                                // known, 0x30 is the room up to maxHp_
    unsigned short maxHp_;
    unsigned short maxMp_;
    unsigned short attack_;
    unsigned short defence_;
    unsigned short power_;
    char unk_76[0xc2];
    int experience_[Vocation_Count];
    unsigned short levels_[Vocation_Count];
    char unk_186[0xe];
    unsigned char equipment_[11][0x20]; // item records (ItemTable_Find's), copied in by CharacterCreationUI_HandleConfirm
    char unk_2f4[0x194];
    PartyMemberAppearance appearance_;
    char unk_4a4[0xc4];
    short unk_568;              // CharacterModel_Load's vocation argument falls back to it, but it is not the vocation
    unsigned char bareBodyColor_;
#if defined(jpn)
    char unk_56b[0x34d];
#else
    char unk_56b[0x3e5];
#endif
    int vocation_;              // PartyMember_SetVocation writes it; indexes levels_
};
