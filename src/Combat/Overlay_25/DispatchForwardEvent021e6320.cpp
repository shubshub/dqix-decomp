#include <globaldefs.h>

void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);

extern char g_sePlayer;

struct Param021e6320 { char pad[8]; unsigned short field_8; unsigned short field_a; };

// USA: func_ov025_021e6320
ARM int DispatchForwardEvent021e6320(struct Param021e6320* p) {
    SePlayer_LoadExtraArchiveB(&g_sePlayer, p->field_8, p->field_a);
    return 1;
}
