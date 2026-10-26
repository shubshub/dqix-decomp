#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_02011538
extern "C" ARM int func_02011538(GameState* battleStruct) {
#if defined(jpn)
    return *(unsigned char*)((char*)battleStruct + 0x54c1);
#else
    return *(unsigned char*)((char*)battleStruct + 0x5721);
#endif
}
