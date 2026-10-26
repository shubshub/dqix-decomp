#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0205416c_448 = 0x1b4 };
#else
enum { Enum_0205416c_448 = 0x1c0 };
#endif

#include "GameState/GameState.h"

extern "C" void func_02054028(void* obj, int n);

// USA: func_0205416c
extern "C" ARM void func_0205416c(void* obj) {
    unsigned int n = (unsigned int)((GameState*)(GameState::GetInstance()))->GetEffectiveDeltaTime();
    unsigned short v = *(unsigned short*)((char*)obj + Enum_0205416c_448);
    if (v >= n) {
        *(unsigned short*)((char*)obj + Enum_0205416c_448) = v - n;
        return;
    }
    func_02054028(obj, 0);
}
