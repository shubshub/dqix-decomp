#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov004_02165868_1134 = 0x1ee };
#else
enum { Enum_ov004_02165868_1134 = 0x46e };
#endif

#include "GameState/GameState.h"

extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02165868
extern "C" ARM int func_ov004_02165868(void* obj) {
    func_ov011_021848a0(obj, 0x6c);
    GameState* battle = GameState::GetInstance();
    *((unsigned char*)battle + 0x6000 + Enum_ov004_02165868_1134) = 0;
    return 0;
}
