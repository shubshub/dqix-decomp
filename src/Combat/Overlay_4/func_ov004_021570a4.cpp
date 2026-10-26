#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov004_021570a4 { char pad[0x5c]; short unknown_5c_; };
extern "C" Struct_ov004_021570a4* func_ov004_02156ed0(void* obj, int key);

// USA: func_ov004_021570a4
extern "C" ARM void* func_ov004_021570a4(void* obj, int index) {
#if defined(jpn)
    enum { fieldOffset = 0xc };
#else
    enum { fieldOffset = 0x26c };
#endif
    if ((unsigned)index >= 6) return NULL;
    char* base = (char*)GameState::GetInstance() + fieldOffset + 0x5c00;
    Struct_ov004_021570a4* var1 = func_ov004_02156ed0(obj, 0x5b);
    int mult = var1->unknown_5c_ * 6 + index;
    return (base + 4) + mult * 0x28;
}
