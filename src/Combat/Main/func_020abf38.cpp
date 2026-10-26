#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

// USA: func_020abf38
extern "C" ARM int func_020abf38(void* dst) {
#if defined(jpn)
    enum { regionalOffset0 = 0x73b0 };
#else
    enum { regionalOffset0 = 0x75f0 };
#endif
    memcpy(dst, (char*)GameState::GetInstance() + regionalOffset0, 0x4d0);
    return 1;
}
