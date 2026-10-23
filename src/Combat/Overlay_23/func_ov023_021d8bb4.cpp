#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov023_021d8bb4 {
    virtual int inline_ov023_021d8bb4();
    char unknown_4_[0x11a - 4];
    unsigned char unknown_11a_;
    unsigned char unknown_11b_;
};

typedef int (Struct_ov023_021d8bb4::*Type_ov023_021d8bb4)();

struct Struct_ov023_021fd510 {
    unsigned int unknown_0_[8];
};

extern "C" void Window_Update(void* obj, int scaleCount);
extern TableBlock021d8bb4 data_ov023_021fd510;
extern MemFn021d8bb4 __ptmf_null;

// USA: func_ov023_021d8bb4  (semantic: DispatchLocalHandlerTable_021d8bb4)
extern "C" ARM int func_ov023_021d8bb4(Obj021d8bb4* obj) {
    int scaleCount = GameState::GetInstance()->GetTickCount();
    if (!scaleCount) scaleCount = 1;
    if (obj->f11b == 0xff) {
        Window_Update((char*)obj + 0x20, scaleCount);
    }
    TableBlock021d8bb4 localBlock = data_ov023_021fd510;
    *(MemFn021d8bb4*)&localBlock.v[6] = __ptmf_null;
    MemFn021d8bb4* table = (MemFn021d8bb4*)&localBlock;
    if (table[obj->f11a] == 0) return 0;
    (obj->*table[obj->f11a])();
    return 0;
}
