#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void func_020120d4(unsigned char*, unsigned char);

#if defined(jpn)
enum { Enum_020a9af8_23772 = 0x5a7c };
#else
enum { Enum_020a9af8_23772 = 0x5cdc };
#endif

// USA: func_020a9af8
extern "C" ARM int func_020a9af8(unsigned char* arg) {
    GameState* bs = GameState::GetInstance();
    func_020120d4((unsigned char*)bs, arg[0]);
    memcpy((char*)bs + Enum_020a9af8_23772, arg + 4, 0x190);
    return 1;
}
