#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0208ec04_23772 = 0x5a7c };
#else
enum { Enum_0208ec04_23772 = 0x5cdc };
#endif

#include "GameState/GameState.h"

struct Struct_0208ec04 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 8;
    unsigned int unknown_2_1_ : 8;
    unsigned int type4 : 4;
    unsigned int unknown_3_5_ : 2;
    unsigned int flag : 1;
};

// USA: func_0208ec04
extern "C" ARM void func_0208ec04(void) {
    char* base = (char*)GameState::GetInstance();
    struct Struct_0208ec04* e = (struct Struct_0208ec04*)(base + Enum_0208ec04_23772);
    int i;
    for (i = 0; i < 0x64; i++, e++) {
        if (e->flag && e->unknown_2_1_ != 0) {
            e->unknown_2_1_ = 0;
            e->unknown_0_0_ = e->type4 * 3;
        }
    }
}
