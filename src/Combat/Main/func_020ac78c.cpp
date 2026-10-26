#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "GameState/GameState.h"

// USA: func_020ac78c
extern "C" ARM int func_020ac78c(void* dst) {
#if defined(jpn)
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x62b4, dst, 1);
#else
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x64f4, dst, 1);
#endif
    return 1;
}
