#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02053f7c_178 = 0xa6 };
#else
enum { Enum_02053f7c_178 = 0xb2 };
#endif

#include "GameState/GameState.h"

struct Obj02086aec {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Struct_02053f7c_2 {
    char pad[Enum_02053f7c_178];
    short unknown_b2_;
};

struct Struct_02053f7c_3 {
    char pad[4];
    short field4;
    char pad2[0x100 - 6];
    struct Struct_02053f7c_2 sub;
};

extern "C" void* GameState_GetParty(GameState* gs);

// USA: func_02053f7c
extern "C" ARM void func_02053f7c(Struct_02053f7c_3* obj, unsigned short a, int b) {
    struct Obj02086aec* p = (struct Obj02086aec*)GameState_GetParty(GameState::GetInstance());
    int found = 0;
    int i;
    if (p != NULL) {
        for (i = 0; i < p->count; i++) {
            unsigned char id = p->ids[i];
            if (id == obj->field4) {
                found = 1;
                break;
            }
        }
    }
    if (b != 0 || found != 0) {
        obj->sub.unknown_b2_ = a;
    }
}
