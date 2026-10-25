#ifndef SOUND_SEPLAYER_H
#define SOUND_SEPLAYER_H

// The menu sound effect player: SePlayer_Play plays effect N from the archive g_sePlayer holds. 0xd0 bytes (the bss
// symbol after g_sePlayer starts 0xd0 bytes on).
struct SePlayer {
    char unknown0[0xb4];
    short archive;       // the sound archive SePlayer_Play plays its effects from
    char unknownB6[0xc4 - 0xb6];
    short extraArchive;  // the one SePlayer_PlayExtra plays from (only when >= 0); SePlayer_LoadExtraArchiveA/B set it
    char unknownC6[0xd0 - 0xc6];
};
extern SePlayer g_sePlayer;
void SePlayer_Play(SePlayer* player, int effect, int handle);

// Sound archive ids: SePlayer_LoadExtraArchiveA/B load one and make it SePlayer::extraArchive.
enum SoundArchive
{
    SoundArchive_NewGameFinish = 0x6f,  // CharacterCreationUI_HandleNewGameFinish plays its effects 0 and 1
};

enum SoundEffect
{
    SoundEffect_Select = 1,
    SoundEffect_Cursor = 2,
};

#endif
