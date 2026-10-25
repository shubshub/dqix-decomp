#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e72a8_24576 = 0x7000, Enum_ov025_021e72a8_4053 = 0x1c5 };
#else
enum { Enum_ov025_021e72a8_24576 = 0x6000, Enum_ov025_021e72a8_4053 = 0xfd5 };
#endif

#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

extern "C" void* func_ov000_02160130(void);
extern "C" int func_0202ed7c(char* arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_ov025_021e72a8 {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};

// USA: func_ov025_021e72a8
extern "C" ARM int func_ov025_021e72a8(struct Struct_ov025_021e72a8* arg0) {
    void* var0 = func_ov000_02160130();
    if (var0 != 0) {
        *(unsigned char*)((char*)var0 + Enum_ov025_021e72a8_24576 + Enum_ov025_021e72a8_4053) = 1;
    }
    GameState* bs = GameState::GetInstance();
    char* field = (char*)bs->GetCamera();
    CallFunc020a0d6cAtField0x16c_0202ed7c(field, (int)((char*)p + 8), p->f14, p->f18, p->f1c);
    return 1;
}
