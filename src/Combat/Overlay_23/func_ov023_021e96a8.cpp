#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov023_021e8f28(int index);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void func_ov017_021d6134(void* obj, int value);
extern "C" void* __clear(void* dst, int count);

struct Struct_ov023_021e96a8 { int x : 10; int y : 10; int z : 10; };
struct Struct_ov023_021e96a8_2 { char pad[0x18]; struct Struct_ov023_021e96a8 unknown_18_; struct Struct_ov023_021e96a8 unknown_1c_; };

// USA: func_ov023_021e96a8
extern "C" ARM int func_ov023_021e96a8(unsigned char* obj) {
#if defined(jpn)
 enum { regionalOffset=0x144 };
#else
 enum { regionalOffset=0x150 };
#endif
    GameState::GetInstance();
    GameObject* entry = func_ov023_021e8f28(func_ov017_021d60f4(obj));
    if (entry == 0) {
        return 0;
    }

    int accum[6];
    __clear(accum, 0x18);

    for (int j = 0; j < 0xb; j++) {
        int var3 = *(int*)((char*)entry + regionalOffset) + 0x194;
        int var4 = var3 + ((unsigned char)j << 5);
        struct Struct_ov023_021e96a8_2* node;
        if (var4 != 0 && (node = *(struct Struct_ov023_021e96a8_2**)var4) != 0) {
            accum[0] += node->unknown_18_.x;
            accum[1] += node->unknown_18_.y;
            accum[2] += node->unknown_18_.z;
            accum[3] += node->unknown_1c_.x;
            accum[4] += node->unknown_1c_.y;
            accum[5] += node->unknown_1c_.z;
        }
    }

    int mode = func_ov017_021d60f4(obj + 0x8);
    switch (mode) {
        case 0: func_ov017_021d6134(obj + 0x10, accum[4]); break;
        case 1: func_ov017_021d6134(obj + 0x10, accum[0]); break;
        case 2: func_ov017_021d6134(obj + 0x10, accum[1]); break;
        case 3: func_ov017_021d6134(obj + 0x10, accum[2]); break;
        case 4: func_ov017_021d6134(obj + 0x10, accum[3]); break;
        case 5: func_ov017_021d6134(obj + 0x10, accum[5]); break;
    }
    return 1;
}
