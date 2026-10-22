#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_02155618_490 = 0x1e6 };
enum { Enum_ov003_02155618_486 = 0x1e2 };
#else
enum { Enum_ov003_02155618_490 = 0x1ea };
enum { Enum_ov003_02155618_486 = 0x1e6 };
#endif

struct Struct_020676e0;
extern "C" int func_020100f8(char* arg0);
extern "C" int func_020a27c4(struct Struct_020676e0* arg0);
extern "C" int func_ov003_021550dc(void* arg0);
extern "C" int func_ov003_02155208(void* arg0);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Struct_0207fdcc_2;
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* arg0, int arg1);

struct Struct_02081f20_2;
extern "C" void func_0208203c(struct Struct_02081f20_2* arg0);

struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8* arg0);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_02155618
extern "C" ARM int func_ov003_02155618(char* arg0) {
    *(void**)(arg0 + 8) = arg0 + Enum_ov003_02155618_490;
    int var0 = 0;
    int var1 = var0;

    GameState* var2 = GameState::GetInstance();
    struct Struct_020676e0* var3 = (struct Struct_020676e0*)func_020100f8((char*)var2);
    if (var3 != 0 && ((*((unsigned char*)var3 + 0x244) & 2) != 0 || func_020a27c4(var3) == 0)) {
        var1 = (g_keyManager.TestKeysPressed(0x200) != 0) ? 1 : 0;
    }

    if (func_ov003_021550dc(obj) != 0 || flagB != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        result = -1;
        if (*(short*)(obj + kRegionValue1EA_1E6) == 6) {
            result = 1;
        }
    } else {
        if (func_ov003_02155208(arg0) != 0) {
            var0 = -1;
        }
    }

    if (var0 != 0) {
        func_0207fdcc(*(struct Struct_0207fdcc_2**)(arg0 + 0x18), *(short*)(arg0 + Enum_ov003_02155618_486));
        func_0208203c((struct Struct_02081f20_2*)(arg0 + 0x80));
        *(void**)(arg0 + 8) = 0;
    }

    if (*(void**)(arg0 + 0x1c) != 0 && var0 != 0) {
        func_020e25e8(*(struct Struct_020e25e8**)(arg0 + 0x1c));
    }

    return var0;
}
