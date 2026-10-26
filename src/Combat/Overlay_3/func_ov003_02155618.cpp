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

struct IntField0x23c_020a27c4;
int GameState_GetFollowCamera(char* obj);
int GetIntAt0x23c(struct IntField0x23c_020a27c4* obj);
extern "C" int func_ov003_021550dc(void* obj);
extern "C" int func_ov003_02155208(void* self);

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

    GameState* battle = GameState::GetInstance();
    struct IntField0x23c_020a27c4* p = (struct IntField0x23c_020a27c4*)GameState_GetFollowCamera((char*)battle);
    if (p != 0 && ((*((unsigned char*)p + 0x244) & 2) != 0 || GetIntAt0x23c(p) == 0)) {
        flagB = (g_keyManager.TestKeysPressed(0x200) != 0) ? 1 : 0;
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
