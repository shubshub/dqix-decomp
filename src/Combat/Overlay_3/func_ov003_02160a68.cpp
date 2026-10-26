#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_02160a68_804 = 0x20c };
enum { Enum_ov003_02160a68_912 = 0x278 };
enum { Enum_ov003_02160a68_808 = 0x210 };
enum { Enum_ov003_02160a68_1160 = 0x2b0 };
enum { Enum_ov003_02160a68_916 = 0x27c };
#else
enum { Enum_ov003_02160a68_804 = 0x324 };
enum { Enum_ov003_02160a68_912 = 0x390 };
enum { Enum_ov003_02160a68_808 = 0x328 };
enum { Enum_ov003_02160a68_1160 = 0x488 };
enum { Enum_ov003_02160a68_916 = 0x394 };
#endif

extern "C" int func_ov017_021a4e70(unsigned char* base);

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
extern "C" int func_020e2984(struct Struct_020e28dc* window);

struct Struct_0207fdcc_2;
extern "C" int func_02080d54(struct Struct_0207fdcc_2* obj, int key, int px, int arg3);

struct Struct_ov003_02160a68 {
    char pad0[Enum_ov003_02160a68_804];
    struct Struct_0207fdcc_2* unknown_324_;
    char pad1[Enum_ov003_02160a68_912 - Enum_ov003_02160a68_808];
    struct Struct_020e28dc* unknown_390_;
    char pad2[Enum_ov003_02160a68_1160 - Enum_ov003_02160a68_916];
    short unknown_488_;
};

// USA: func_ov003_02160a68
extern "C" ARM int func_ov003_02160a68(struct Struct_ov003_02160a68* self) {
    int flag = 0;
    unsigned char* battleWord = (unsigned char*)(int)GameState::GetInstance()->GetResources();
    if (g_keyManager.TestKeysPressed(2)) {
        if (func_ov017_021a4e70(battleWord)) {
            flag = 1;
        }
    }

    if (func_020e28dc(self->unknown_390_)) {
        if (func_020e2984(self->unknown_390_)) {
            flag = 1;
        }
    } else if (g_touchInput.pressed_ != 0) {
        int a, b;
        g_touchInput.GetTouchPoint(&a, &b);
        if (!func_02080d54(self->unknown_324_, self->unknown_488_, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}
