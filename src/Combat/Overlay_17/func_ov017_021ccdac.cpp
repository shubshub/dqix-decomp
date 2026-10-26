#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_020839dc;
extern "C" int func_020839dc(struct Struct_020839dc* s, unsigned char* out, int max);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ccdac {
    unsigned char tag;
    unsigned char pad[3];
    unsigned char unknown_4_0_ : 3;
    unsigned char unknown_4_3_ : 4;
    unsigned char unused1 : 1;
    unsigned char data[15];
};

// USA: func_ov017_021ccdac
extern "C" ARM void func_ov017_021ccdac(int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200ff1c(bs, combatantId);
    if (!c) return;
    int field150 = func_02053c6c((unsigned char*)c);
    if (!field150) return;

    unsigned char indices[0x44];
    void* p;
    int var5;
    int var6;
    int total;

    total = func_020839dc((struct Struct_020839dc*)field150, indices, 0x42);
    total = total & 0xff;

    p = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021ccdac buf;
    buf.tag = 0xf;
    buf.unknown_4_0_ = combatantId;

    var5 = 0;
    var6 = 0;
    while (var5 < total) {
        int j;
        for (j = 0; j < 0xf; j++) {
            if (total <= var5 + j) break;
            buf.data[j] = indices[var6 * 15 + j];
        }
        buf.unknown_4_3_ = j;
        func_0205e330(p, &buf, 0);
        var5 += buf.unknown_4_3_;
        var6++;
    }
}
