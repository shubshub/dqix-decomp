#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02179e44_4112 = 0xf8c };
enum { Enum_ov003_02179e44_4116 = 0xf90 };
enum { Enum_ov003_02179e44_4118 = 0xf92 };
enum { Enum_ov003_02179e44_4124 = 0xf98 };
enum { Enum_ov003_02179e44_4144 = 0xfac };
enum { Enum_ov003_02179e44_4163 = 0xfbf };
enum { Enum_ov003_02179e44_2204 = 0x818 };
#else
enum { Enum_ov003_02179e44_4112 = 0x1010 };
enum { Enum_ov003_02179e44_4116 = 0x1014 };
enum { Enum_ov003_02179e44_4118 = 0x1016 };
enum { Enum_ov003_02179e44_4124 = 0x101c };
enum { Enum_ov003_02179e44_4144 = 0x1030 };
enum { Enum_ov003_02179e44_4163 = 0x1043 };
enum { Enum_ov003_02179e44_2204 = 0x89c };
#endif

#include "GameState/GameState.h"

extern "C" short func_02080468(void* obj, int id);
struct Struct_020a0b8c;
extern "C" int func_020a0b8c(struct Struct_020a0b8c* p);

// USA: func_ov003_02179e44
extern "C" ARM int func_ov003_02179e44(char* obj) {
    GameState* battle = GameState::GetInstance();
    void* ptr = GameState_GetParty(battle);
    int state = *(int*)(obj + Enum_ov003_02179e44_4144);
    void* var3 = *(void**)(obj + Enum_ov003_02179e44_2204);
    int type;
    switch (state) {
        case 1: type = 0x11; break;
        case 2: type = 0x12; break;
        case 3: type = 0x13; break;
        case 4: type = 0x14; break;
    }

    *(char*)(obj + Enum_ov003_02179e44_4163) = -1;
    short idx = func_02080468(var3, type);
    short v10 = *(short*)(obj + Enum_ov003_02179e44_4112);
    int var7 = *(int*)(obj + Enum_ov003_02179e44_4144);
    short diff = (short)(v10 - idx);
    if (var7 > diff) {
        int val = *(int*)(obj + Enum_ov003_02179e44_4124 + diff * 4);
        *(char*)(obj + Enum_ov003_02179e44_4163) = (char)val;
        *(short*)(obj + Enum_ov003_02179e44_4116) = 0;
        *(short*)(obj + Enum_ov003_02179e44_4118) = 1;
        return 1;
    } else {
        int count = func_020a0b8c((struct Struct_020a0b8c*)ptr);
        int n = (count + 7) / 8;
        *(short*)(obj + Enum_ov003_02179e44_4116) = 0;
        *(short*)(obj + Enum_ov003_02179e44_4118) = n;
        short var12 = *(short*)(obj + Enum_ov003_02179e44_4118);
        if (var12 == 0) {
            var12 = 1;
            *(short*)(obj + Enum_ov003_02179e44_4118) = var12;
        }
        return var12;
    }
}
