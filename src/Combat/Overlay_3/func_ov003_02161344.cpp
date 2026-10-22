#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_02161344_1136 = 0x298 };
enum { Enum_ov003_02161344_1180 = 0x2c4 };
enum { Enum_ov003_02161344_804 = 0x20c };
enum { Enum_ov003_02161344_1160 = 0x2b0 };
enum { Enum_ov003_02161344_776 = 0x1f0 };
enum { Enum_ov003_02161344_912 = 0x278 };
#else
enum { Enum_ov003_02161344_1136 = 0x470 };
enum { Enum_ov003_02161344_1180 = 0x49c };
enum { Enum_ov003_02161344_804 = 0x324 };
enum { Enum_ov003_02161344_1160 = 0x488 };
enum { Enum_ov003_02161344_776 = 0x308 };
enum { Enum_ov003_02161344_912 = 0x390 };
#endif

struct Struct_020676e0;
extern "C" int func_020100f8(char* arg0);
extern "C" int func_020a27c4(struct Struct_020676e0* arg0);
extern "C" int func_ov003_02160854(void* arg0);

struct Struct_ov003_02160a68;
extern "C" int func_ov003_02160a68(struct Struct_ov003_02160a68* arg0);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Struct_0207fdcc_2;
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* arg0, int arg1);

struct Struct_02081f20_2;
extern "C" void func_0208203c(struct Struct_02081f20_2* arg0);

struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8* arg0);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_02161344
extern "C" ARM int func_ov003_02161344(char* arg0) {
    *(void**)(arg0 + Enum_ov003_02161344_1136) = arg0 + Enum_ov003_02161344_1180;
    int var0 = 0;
    int var1 = var0;

    GameState* var2 = GameState::GetInstance();
    struct Struct_020676e0* var3 = (struct Struct_020676e0*)func_020100f8((char*)var2);
    if (var3 != 0 && ((*((unsigned char*)var3 + 0x244) & 2) != 0 || func_020a27c4(var3) == 0)) {
        var1 = (g_keyManager.TestKeysPressed(0x200) != 0) ? 1 : 0;
    }

    if (func_ov003_02160854(obj) != 0 || flagB != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        result = -1;
        if (*(short*)(obj + kRegionValue49C_2C4) == 0x2c) {
            result = 1;
        }
    } else {
        if (func_ov003_02160a68((struct Struct_ov003_02160a68*)arg0) != 0) {
            var0 = -1;
        }
    }

    if (var0 != 0) {
        func_0207fdcc(*(struct Struct_0207fdcc_2**)(arg0 + Enum_ov003_02161344_804), *(short*)(arg0 + Enum_ov003_02161344_1160));
        func_0208203c((struct Struct_02081f20_2*)(arg0 + Enum_ov003_02161344_776));
        *(void**)(arg0 + Enum_ov003_02161344_1136) = 0;
    }

    if (*(void**)(arg0 + Enum_ov003_02161344_912) != 0 && var0 != 0) {
        func_020e25e8(*(struct Struct_020e25e8**)(arg0 + Enum_ov003_02161344_912));
    }

    return var0;
}
