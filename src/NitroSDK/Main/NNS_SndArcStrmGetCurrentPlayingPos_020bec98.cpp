#include <globaldefs.h>

struct Struct_020bec98_2
{
    char unknown_0_[0xc4];
    unsigned short unknown_c4_;
    char unknown_c6_[0x9a];
    unsigned int unknown_160_;
};
struct Struct_020bec98 { Struct_020bec98_2* player_; };

static inline bool inline_020bec98(const Struct_020bec98* handle)
{
    return handle->player_ != NULL;
}

// Main, originally ScaleField0x160By1000_020bec98 (USA 0x020bec98, EUR 0x020beca8, JPN 0x020c0764)
extern "C" ARM unsigned int NNS_SndArcStrmGetCurrentPlayingPos(void* object)
{
    Struct_020bec98* handle = (Struct_020bec98*)object;
    Struct_020bec98_2* player;
    unsigned long long position;
    if (!inline_020bec98(handle))
        return 0;
    player = handle->player_;
    position = player->unknown_160_;
    position *= 1000;
    position /= (unsigned int)player->unknown_c4_;
    return (unsigned int)position;
}
