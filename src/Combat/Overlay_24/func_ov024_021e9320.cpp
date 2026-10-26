#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021dd828 { char pad[0x10]; int unused; };

// USA: func_ov024_021e9320
extern "C" ARM int func_ov024_021e9320(struct Struct_ov024_021dd828* ctx, int id, int mode) {
    GameObject* c = GetCombatantByID(ctx->unused, id);
    if (!c) return 0;
    int var1 = func_ov024_021de25c((struct Struct_ov024_021de124*)c);
    if (mode != 0) {
        if (var1) {
            return func_ov024_021da644(id, 0x83, 0x84);
        }
        return func_ov024_021da644(id, 0x81, 0x82);
    }
    if (var1) return 0x85;
    #if defined(jpn)
        return 0x1b;
#else
        return func_ov024_021da644(id, 0x26d, 0x1b);
#endif
}
