#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02175f20_4114 = 0xf8e };
enum { Enum_ov003_02175f20_4110 = 0xf8a };
enum { Enum_ov003_02175f20_4116 = 0xf90 };
#else
enum { Enum_ov003_02175f20_4114 = 0x1012 };
enum { Enum_ov003_02175f20_4110 = 0x100e };
enum { Enum_ov003_02175f20_4116 = 0x1014 };
#endif

extern "C" unsigned char func_0207ca94(int index);
extern "C" int func_0207c6b8(unsigned char* obj, unsigned int index, int target);

// USA: func_ov003_02175f20
extern "C" ARM int func_ov003_02175f20(void* obj) {
    GameState* bs = GameState::GetInstance();
    void* p = GameState_GetParty(bs);
    short v1 = *(short*)((char*)obj + Enum_ov003_02175f20_4114);
    int idx = (short)(v1 - 286);
    unsigned char cnt = func_0207ca94(idx);
    short v3 = *(short*)((char*)obj + Enum_ov003_02175f20_4110);
    short v2 = *(short*)((char*)obj + Enum_ov003_02175f20_4116);
    unsigned char* var7 = (unsigned char*)p + 0x1d4;
    short idx2 = (short)(v3 - 295);
    idx2 = v2 * 5 + idx2;
    return func_0207c6b8(var7, cnt, idx2);
}
