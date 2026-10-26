#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02011930;
extern "C" unsigned char func_02011930(void* obj, struct Struct_02011930* info, void* name1, void* name2);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" unsigned char func_020119cc(void* obj);

// USA: func_ov004_021658b0
extern "C" ARM int func_ov004_021658b0(void* a) {
#if defined(jpn)
    enum { fieldOffset = 0x1ee };
#else
    enum { fieldOffset = 0x46e };
#endif
    void* bs = GameState::GetInstance();
    unsigned char r = func_02011930(bs, NULL, NULL, NULL);
    if (r != 0) {
        func_ov011_021848a0(a, 0x64);
        char* bs2 = (char*)GameState::GetInstance();
        bs2[0x6000 + fieldOffset] = 1;
        func_020119cc(bs);
    } else {
        func_ov011_021848a0(a, 0x65);
    }
    return 0;
}
