#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_02083a50;
extern "C" int func_02083a50(struct Struct_02083a50* obj, short* out, int max);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ccfd0 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char unknown_4_0_ : 3;
    unsigned char count : 3;
    unsigned char pad4 : 2;
    unsigned char pad5;
    short unknown_6_[7];
};

// USA: func_ov017_021ccfd0
extern "C" ARM void func_ov017_021ccfd0(int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(bs, combatantId);
    if (!combatant) {
        return;
    }
    int field150 = func_02053c6c((unsigned char*)combatant);
    if (!field150) {
        return;
    }

    unsigned short buffer[288];
    void* p;
    int var5;
    int j;
    int count;

    count = (unsigned short)func_02083a50((struct Struct_02083a50*)field150, (short*)buffer, 0x11f);
    p = LinkMessageQueue_GetInstance();
    var5 = 0;
    j = 0;
    struct Struct_ov017_021ccfd0 evt;
    evt.tag = 0x10;
    evt.unknown_4_0_ = (unsigned char)combatantId;

    while (var5 < count) {
        int i = 0;
        for (; i < 7; i++) {
            if (count <= var5 + i) {
                break;
            }
            evt.unknown_6_[i] = buffer[j * 7 + i];
        }
        evt.count = i;
        func_0205e330(p, &evt, 0);
        var5 += evt.count;
        j++;
    }
}
