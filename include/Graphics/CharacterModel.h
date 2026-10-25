#pragma once

#include "Graphics/VramState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct ItemTable;
struct PartyMemberData;

// The parts of a CharacterModel, one Object3D each, loaded from data/pack_lv5/chara_pd.gp2 as
// d_<letter><number>.nsbmd. CharacterModel_GetPartModels fills them from the PartyMemberAppearance fields of the same
// names. Part 9 (PartyMemberAppearance::unk_10) hangs on the "weaponL" bone; what it is has not been checked.
enum CharacterModelPart
{
    CharacterModelPart_Body = 0,        // d_b###; its model also picks the animation files
    CharacterModelPart_Legs = 1,        // d_p###; skinned, follows the body's animation
    CharacterModelPart_Face = 2,        // d_f###
    CharacterModelPart_Hair = 3,        // d_h###
    CharacterModelPart_HairTexture = 4, // d_h###.nsbtx: the hair style's number plus the hair colour
    CharacterModelPart_Arms = 5,        // d_a###; skinned
    CharacterModelPart_Feet = 6,        // d_r###; skinned
    CharacterModelPart_Headgear = 7,    // drawn at the "head" bone; picks the hair model's variant
    CharacterModelPart_Weapon = 8,      // drawn at "weaponR" (both "arm2" bones while holdsWithArms_); its number is
                                        // in the animation file name
    CharacterModelPart_Count = 10,
};

// Model ids of the hair styles and faces in a PartyMemberAppearance: style N of a tab is First + N.
enum AppearanceModel
{
    AppearanceModel_FirstHairStyle = 9000,
    AppearanceModel_FirstFace = 9020,
};

// A character's 3D model (0xc20 bytes): character creation's two previews, and the menu characters of overlay 23.
struct CharacterModel {
    Object3D parts_[CharacterModelPart_Count];
    SafeAllocator allocators_[CharacterModelPart_Count]; // one per part (CharacterModel_CreateAllocators)
    SafeAllocator animationAllocator_;      // the body's animations
    VramState vramStates_[CharacterModelPart_Count]; // texture and palette VRAM reserved per part
    short tasks_[12];                       // loader tasks: the parts, then the body's .nsbca and .bcfg
    struct ItemTable* itemTable_;
    unsigned char holdsWithArms_;           // the weapon is an item of type 6, drawn in both hands
    unsigned char forceStandAnimation_;     // females play "stand" too instead of "stand_cm"
    unsigned char loading_;
    unsigned char bodyChanged_;
    unsigned char visible_;
    unsigned char vocation_;
    char unk_c16[2];
    PartyMemberData* member_;
    short angle_;
    unsigned char colored_;
    char unk_c1f;
};

typedef char VerifyCharacterModelSize[sizeof(CharacterModel) == 0xc20 ? 1 : -1];
