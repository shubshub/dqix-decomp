#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_02027ad8_12 = 0x4c };
#else
enum { Enum_02027ad8_12 = 0xc };
#endif

// USA: func_02027ad8
extern "C" ARM void func_02027ad8(int unused, int flag) {
    GameState* state = GameState::GetInstance();

    if (flag != 0) {
        memset(state->unk_6fc0 + Enum_02027ad8_12, 0xff, 0x200);
    } else {
        memset(state->unk_6fc0 + Enum_02027ad8_12, 0, 0x200);
    }
}
