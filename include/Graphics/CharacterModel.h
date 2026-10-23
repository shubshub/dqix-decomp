#pragma once

// The parts of a CharacterModel, one Object3D each, loaded from data/pack_lv5/chara_pd.gp2 as
// d_<letter><number>.nsbmd. Only the parts character creation changes are named so far.
enum CharacterModelPart
{
    CharacterModelPart_Body = 0,        // d_b###; its model also picks the animation files
    CharacterModelPart_Face = 2,        // d_f###
    CharacterModelPart_Hair = 3,        // d_h###
    CharacterModelPart_HairTexture = 4, // d_h###.nsbtx: the hair style's number plus the hair colour
};

// Model ids of the hair styles and faces in a PartyMemberAppearance: style N of a tab is First + N.
enum AppearanceModel
{
    AppearanceModel_FirstHairStyle = 9000,
    AppearanceModel_FirstFace = 9020,
};
