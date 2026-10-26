#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cdaa0 {
    float valA;
};

struct Struct_ov017_021cdaa0_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021cdaa0 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021cdaa0
extern "C" ARM void func_ov017_021cdaa0(void) {
    GameState* battleStruct = GameState::GetInstance();
    Struct_ov017_021cdaa0_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x93;
    Struct_ov017_021cdaa0* s = &buf.sub;
    s->valA = battleStruct->GetDayTimer();
    func_0205e330(p, &buf, 0);
}
