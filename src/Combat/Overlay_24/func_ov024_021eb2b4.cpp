#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);

struct Struct_ov024_021eb2b4 { char pad[0x10]; int unknown_10_; };
struct Struct_ov024_021fe6d8 { short v[4]; };
extern struct Struct_ov024_021fe6d8 data_ov024_021fe6d8;
struct Struct_ov024_021eb2b4_2 { unsigned char unknown_0_0_:3; unsigned char flag:1; unsigned char unknown_0_4_:4; };

// USA: func_ov024_021eb2b4
extern "C" ARM int func_ov024_021eb2b4(struct Struct_ov024_021eb2b4* obj) {
    int result = 0;
    struct Struct_ov024_021fe6d8 buf = data_ov024_021fe6d8;
    int count = func_ov000_0215e9fc(obj->unknown_10_, buf.v, 4, 1);
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->unknown_10_, buf.v[i]);
        struct Struct_ov024_021eb2b4_2* sb = (struct Struct_ov024_021eb2b4_2*)((char*)c->currentStats_ + 0x3b);
        if (sb->flag) result++;
    }
    return result;
}
