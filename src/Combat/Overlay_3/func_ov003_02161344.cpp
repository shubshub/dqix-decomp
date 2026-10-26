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

struct IntField0x23c_020a27c4;
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" int func_020a27c4(struct IntField0x23c_020a27c4* obj);
extern "C" int func_ov003_02160854(void* obj);

struct Struct_ov003_02160a68;
extern "C" int func_ov003_02160a68(struct Struct_ov003_02160a68* self);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Struct_0207fdcc_2;
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* obj, int key);

struct Struct_02081f20_2;
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);

struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8* obj);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_02161344
extern "C" ARM int func_ov003_02161344(char* obj) {
    *(void**)(obj + Enum_ov003_02161344_1136) = obj + Enum_ov003_02161344_1180;
    int result = 0;
    int var1 = result;

    GameState* battle = GameState::GetInstance();
    struct IntField0x23c_020a27c4* p = (struct IntField0x23c_020a27c4*)GameState_GetFollowCamera((char*)battle);
    if (p != 0 && ((*((unsigned char*)p + 0x244) & 2) != 0 || func_020a27c4(p) == 0)) {
        var1 = (g_keyManager.TestKeysPressed(0x200) != 0) ? 1 : 0;
    }

    if (func_ov003_02160854(obj) != 0 || var1 != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        result = -1;
        if (*(short*)(obj + Enum_ov003_02161344_1180) == 0x2c) {
            result = 1;
        }
    } else {
        if (func_ov003_02160a68((struct Struct_ov003_02160a68*)obj) != 0) {
            result = -1;
        }
    }

    if (result != 0) {
        func_0207fdcc(*(struct Struct_0207fdcc_2**)(obj + Enum_ov003_02161344_804), *(short*)(obj + Enum_ov003_02161344_1160));
        func_0208203c((struct Struct_02081f20_2*)(obj + Enum_ov003_02161344_776));
        *(void**)(obj + Enum_ov003_02161344_1136) = 0;
    }

    if (*(void**)(obj + Enum_ov003_02161344_912) != 0 && result != 0) {
        func_020e25e8(*(struct Struct_020e25e8**)(obj + Enum_ov003_02161344_912));
    }

    return result;
}
