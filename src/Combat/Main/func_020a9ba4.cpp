#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_020a9ba4 {
    unsigned char first[0x200];
    unsigned char second[0x200];
    int unknown_400_;
};

#if defined(jpn)
enum { Enum_020a9ba4_24960 = 0x5f20, Enum_020a9ba4_24448 = 0x5d20, Enum_020a9ba4_24444 = 0x5d1c };
#else
enum { Enum_020a9ba4_24960 = 0x6180, Enum_020a9ba4_24448 = 0x5f80, Enum_020a9ba4_24444 = 0x5f7c };
#endif

// USA: func_020a9ba4
extern "C" ARM int func_020a9ba4(void* src) {
    struct Struct_020a9ba4 buf;
    GameState* bs = GameState::GetInstance();
    memcpy(&buf, src, sizeof(buf));
    memcpy((char*)bs + Enum_020a9ba4_24960, buf.second, 0x200);
    memcpy((char*)bs + Enum_020a9ba4_24448, buf.first, 0x200);
    *(int*)((char*)bs + Enum_020a9ba4_24444) = buf.unknown_400_;
    return 1;
}
