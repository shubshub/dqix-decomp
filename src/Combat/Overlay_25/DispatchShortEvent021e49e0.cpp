#include <globaldefs.h>
#include "Sound/SePlayer.h"

void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern struct SePlayer g_sePlayer;

struct Param021e49e0 { char pad[8]; unsigned short field_8; };

// USA: func_ov025_021e49e0
ARM int DispatchShortEvent021e49e0(struct Param021e49e0* p) {
    SePlayer_Play(&g_sePlayer, p->field_8, 0);
    return 1;
}
