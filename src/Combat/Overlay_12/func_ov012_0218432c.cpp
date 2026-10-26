#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218432c func_ov012_021853a0
#endif
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif

#include "GameState/GameState.h"

#if defined(jpn)
#define data_ov012_0218afaa data_ov012_0218bd16
#define data_ov012_0218afac data_ov012_0218bd18
#endif
struct Struct_ov012_0218432c {
    unsigned int unk0 : 9;
    signed int value : 10;
    unsigned int unknown_2_3_ : 13;
};

struct Struct_ov012_0218afaa { short value; short unused; };

extern struct Struct_ov012_0218afaa data_ov012_0218afaa[];
extern struct Struct_ov012_0218afaa data_ov012_0218afac[];

// USA: func_ov012_0218432c
extern "C" ARM int func_ov012_0218432c(int index) {
    char* base = (char*)GameState::GetInstance() + R(0x543c, 0x569c);
    int var1 = ((struct Struct_ov012_0218432c*)(base + 4))->value;
    short a1 = data_ov012_0218afaa[index].value;
    if (a1 <= var1) {
        short a2 = data_ov012_0218afac[index].value;
        if (var1 < a2) return var1 - a1;
    }
    return 0;
}
