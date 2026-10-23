#include <globaldefs.h>
#include "Resource/GameResources.h"

int GetField4340_021bdbe4(unsigned char* base);
int GetField433c_021bdbd8(unsigned char* base);
extern "C" void CharacterModel_Draw(void* addr, void* pair);

struct Pair021fcd70 { int a; int b; };
struct BitByte021fcd70 { unsigned char bit0 : 1; unsigned char rest : 7; };

// USA: func_ov023_021fcd70  (semantic: SelectAndDispatchPair_021fcd70)
extern "C" ARM void func_ov023_021fcd70(void* obj) {
    int h = (int)GetGameResources();
    Pair021fcd70 p;
    if (h == 0) {
        p.b = 0;
        p.a = 0;
    } else {
        p.b = GetField4340_021bdbe4((unsigned char*)h);
        p.a = GetField433c_021bdbd8((unsigned char*)h);
    }
    BitByte021fcd70* bf = (BitByte021fcd70*)((char*)obj + 0x1864);
    unsigned int mask = bf->bit0;
    void* addr = (char*)obj + 0x20 + mask * 0xc20;
    CharacterModel_Draw(addr, &p);
}
