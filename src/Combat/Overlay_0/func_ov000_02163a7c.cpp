#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
struct Struct_02049f50;
extern "C" void func_02049f50(struct Struct_02049f50* obj, int val, int count);

struct Struct_ov000_02163a7c {
#if defined(jpn)
    char pad[0x218];
#else
    char pad[0x29c];
#endif
    int unknown_29c_;
};

// USA: func_ov000_02163a7c
extern "C" ARM void func_ov000_02163a7c(struct Struct_ov000_02163a7c* obj) {
    GameState* bs = GameState::GetInstance();
    short buf[16];
    int n = 0;
    n = n + func_ov000_0215e9fc(obj->unknown_29c_, buf, 0x10, n);
    n = n + func_ov000_0215ec1c(obj->unknown_29c_, buf + n, 0x10 - n, 0);
    short* p = buf;
    for (int i = 0; i < n; p++, i++) {
        GameObject* c = bs->GetCombatantByIndex(*p);
        if (c) {
            func_02049f50((struct Struct_02049f50*)c, 0x1f, 0);
        }
    }
}
