#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "GameState/GameState.h"

// USA: func_020ac760
extern "C" ARM int func_020ac760(void* dst) {
#if defined(jpn)
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x62b4, dst, 0xad6);
#else
    VectorizedInvertedMemcpy((char*)GameState::GetInstance() + 0x64f4, dst, 0xad6);
#endif
    return 1;
}
