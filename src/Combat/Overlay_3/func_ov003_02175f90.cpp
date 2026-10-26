#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02175f90_4114 = 0xf8e };
#else
enum { Enum_ov003_02175f90_4114 = 0x1012 };
#endif
#include "GameState/GameState.h"

extern "C" unsigned char func_0207ca94(int index);
extern "C" short func_0207c638(void* base, unsigned int index);

// USA: func_ov003_02175f90
extern "C" ARM short func_ov003_02175f90(void* obj) {
    GameState* bs = GameState::GetInstance();
    void* p = GameState_GetParty(bs);
    short v = *(short*)((char*)obj + Enum_ov003_02175f90_4114);
    int idx = (short)(v - 286);
    unsigned char cnt = func_0207ca94(idx);
    return func_0207c638((char*)p + 0x1d4, cnt);
}
