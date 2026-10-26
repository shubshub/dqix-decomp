#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov023_021d8bb4 {
    virtual int inline_ov023_021d8bb4();
    char pad4[0x11a - 4];
    unsigned char unknown_11a_;
    unsigned char unknown_11b_;
};

typedef int (Struct_ov023_021d8bb4::*Type_ov023_021d8bb4)();

struct Struct_ov023_021fd510 {
    unsigned int v[8];
};

extern "C" void Window_Update(void* obj, int scaleCount);
extern Struct_ov023_021fd510 data_ov023_021fd510;
extern Type_ov023_021d8bb4 __ptmf_null;

// USA: func_ov023_021d8bb4
extern "C" ARM int func_ov023_021d8bb4(Struct_ov023_021d8bb4* obj) {
    int scaleCount = GameState::GetInstance()->GetTickCount();
    if (!scaleCount) scaleCount = 1;
    if (obj->unknown_11b_ == 0xff) {
        Window_Update((char*)obj + 0x20, scaleCount);
    }
    Struct_ov023_021fd510 var1 = data_ov023_021fd510;
    *(Type_ov023_021d8bb4*)&var1.v[6] = __ptmf_null;
    Type_ov023_021d8bb4* table = (Type_ov023_021d8bb4*)&var1;
    if (table[obj->unknown_11a_] == 0) return 0;
    (obj->*table[obj->unknown_11a_])();
    return 0;
}
