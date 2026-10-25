#include <globaldefs.h>
#include "Sound/SePlayer.h"

extern "C" void SePlayer_PlayArchiveEntry(void*, int, int, int);

// Main, originally DispatchWithShortB4_0205eaa0 (USA 0x0205eaa0, EUR 0x0205eab0, JPN 0x0205fd8c)
ARM void SePlayer_Play(struct SePlayer* player, int effect, int handle) {
    SePlayer_PlayArchiveEntry(player, player->archive, effect, handle);
}
