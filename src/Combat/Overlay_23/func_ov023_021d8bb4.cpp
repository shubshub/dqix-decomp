#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj021d8bb4 {
    virtual int Vtbl0();
    char pad4[0x11a - 4];
    unsigned char f11a;
    unsigned char f11b;
};

typedef int (Obj021d8bb4::*MemFn021d8bb4)();

struct TableBlock021d8bb4 {
    unsigned int v[8];
};

extern "C" void func_0205d0e0(void* obj, int scaleCount);
extern TableBlock021d8bb4 data_ov023_021fd510;
extern MemFn021d8bb4 __ptmf_null;

// USA: func_ov023_021d8bb4  (semantic: DispatchLocalHandlerTable_021d8bb4)
extern "C" ARM int func_ov023_021d8bb4(Obj021d8bb4* obj) {
    int scaleCount = GameState::GetInstance()->GetTickCount();
    if (!scaleCount) scaleCount = 1;
    if (obj->f11b == 0xff) {
        func_0205d0e0((char*)obj + 0x20, scaleCount);
    }
    TableBlock021d8bb4 localBlock = data_ov023_021fd510;
    *(MemFn021d8bb4*)&localBlock.v[6] = __ptmf_null;
    MemFn021d8bb4* table = (MemFn021d8bb4*)&localBlock;
    if (table[obj->f11a] == 0) return 0;
    (obj->*table[obj->f11a])();
    return 0;
}
