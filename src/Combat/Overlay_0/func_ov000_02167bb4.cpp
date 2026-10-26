#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02049ee8(unsigned char* obj);

#if defined(jpn)
enum { Enum_ov000_02167bb4_668 = 0x218 };
#else
enum { Enum_ov000_02167bb4_668 = 0x29c };
#endif

// USA: func_ov000_02167bb4
extern "C" ARM int func_ov000_02167bb4(unsigned char* obj, int id) {
    GameState* battle = GameState::GetInstance();
    void* base = *(void**)(obj + Enum_ov000_02167bb4_668);
    int key = *(int*)((char*)base + id * 4 + 0x8000 + 0xde0) & 0xff;
    GameObject* c = battle->GetCombatantByIndex(key);
    int val = c ? (func_02049ee8((unsigned char*)c) != 0) : 0;
    if (val) return 0;
    if (id < 0 || id >= 8) return 0;
    return 0x7fffffff;
}
