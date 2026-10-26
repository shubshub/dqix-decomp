#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov004_021630a4_2 { unsigned int v[3]; };

class Struct_ov004_021630a4 {
    char pad4[8];
public:
    unsigned char unknown_c_;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_021630a4_8(const Struct_ov004_021630a4_2& v);
    virtual Struct_ov004_021630a4_2 inline_ov004_021630a4_9();
};

extern "C" Struct_ov004_021630a4* func_ov004_0215e47c(void* a, int key);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);

extern int data_ov004_021707e8;

// USA: func_ov004_021630a4
extern "C" ARM int func_ov004_021630a4(void* a) {
#if defined(jpn)
    enum { stateFieldOffset = 0x18 };
#else
    enum { stateFieldOffset = 0x10 };
#endif
    Struct_ov004_021630a4* node = func_ov004_0215e47c(a, 9);
    node->unknown_c_ &= ~0x80;
    Struct_ov004_021630a4_2 v2;
    const Struct_ov004_021630a4_2& v = node->inline_ov004_021630a4_9();
    v2 = v;
    v2.v[0] = 0;
    v2.v[1] = 0;
    v2.v[2] = 0;
    node->inline_ov004_021630a4_8(v2);
    GameState_SetCamera(GameState::GetInstance(), *(int*)((char*)&data_ov004_021707e8 + stateFieldOffset));
    return 0;
}
