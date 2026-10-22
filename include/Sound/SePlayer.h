#ifndef SOUND_SEPLAYER_H
#define SOUND_SEPLAYER_H

// The menu sound effect player: SePlayer_Play plays effect N from the archive g_sePlayer holds.
struct SePlayer;
extern SePlayer g_sePlayer;
void SePlayer_Play(SePlayer* player, int effect, int arg);

enum SoundEffect
{
    SoundEffect_Select = 1,
    SoundEffect_Cursor = 2,
};

#endif
