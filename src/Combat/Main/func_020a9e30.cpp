#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
enum { Enum_020a9e30_28620 = 0x6d8c, Enum_020a9e30_23760 = 0x5a70 };
#else
enum { Enum_020a9e30_28620 = 0x6fcc, Enum_020a9e30_23760 = 0x5cd0 };
#endif

struct Struct_020a9e30 {
    unsigned char unknown_0_[0x200];
    unsigned int flags;
    unsigned char bits[10];
};

struct Struct_020a9e30_2 {
    unsigned char unknown0[Enum_020a9e30_23760];
    unsigned char bits[10];
    unsigned char unknown_5cda_[Enum_020a9e30_28620 - Enum_020a9e30_23760 - 10];
    unsigned char unknown_6fcc_[0x200];
    unsigned int flags;
};

// USA: func_020a9e30
extern "C" ARM int func_020a9e30(void* param) {
    Struct_020a9e30* saved = static_cast<Struct_020a9e30*>(param);
    GameState* battle = GameState::GetInstance();
    Struct_020a9e30_2* buffers = reinterpret_cast<Struct_020a9e30_2*>(battle);
    VectorizedInvertedMemcpy(saved->unknown_0_, buffers->unknown_6fcc_, sizeof(saved->unknown_0_));
    VectorizedInvertedMemcpy(saved->bits, buffers->bits, sizeof(saved->bits));
    buffers->flags = saved->flags;
    struct GrottoStruct* grotto = battle->GetGrottoStruct();
    grotto->unknown_0[3] = (saved->flags & 1) != 0;
    buffers->flags = 0;
    return 1;
}
