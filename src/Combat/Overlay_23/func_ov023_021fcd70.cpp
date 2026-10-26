#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021bdbe4(unsigned char* base);
extern "C" int func_ov017_021bdbd8(unsigned char* base);
extern "C" void CharacterModel_Draw(void* addr, void* pair);

struct Struct_ov023_021fcd70 { int a; int b; };
struct Struct_ov023_021fcd70_2 { unsigned char bit0 : 1; unsigned char rest : 7; };

// USA: func_ov023_021fcd70
extern "C" ARM void func_ov023_021fcd70(void* obj) {
    int h = (int)GetGameResources();
    Struct_ov023_021fcd70 p;
    if (h == 0) {
        p.b = 0;
        p.a = 0;
    } else {
        p.b = func_ov017_021bdbe4((unsigned char*)h);
        p.a = func_ov017_021bdbd8((unsigned char*)h);
    }
    Struct_ov023_021fcd70_2* var2 = (Struct_ov023_021fcd70_2*)((char*)obj + 0x1864);
    unsigned int mask = var2->bit0;
    void* addr = (char*)obj + 0x20 + mask * 0xc20;
    CharacterModel_Draw(addr, &p);
}
