#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { kRegionValue470_298 = 0x298 };
enum { kRegionValue49C_2C4 = 0x2c4 };
enum { kRegionValue324_20C = 0x20c };
enum { kRegionValue488_2B0 = 0x2b0 };
enum { kRegionValue308_1F0 = 0x1f0 };
enum { kRegionValue390_278 = 0x278 };
#else
enum { kRegionValue470_298 = 0x470 };
enum { kRegionValue49C_2C4 = 0x49c };
enum { kRegionValue324_20C = 0x324 };
enum { kRegionValue488_2B0 = 0x488 };
enum { kRegionValue308_1F0 = 0x308 };
enum { kRegionValue390_278 = 0x390 };
#endif

struct IntField0x23c_020a27c4;
int GetFieldIfFlag4_020100f8(char* obj);
int GetIntAt0x23c(struct IntField0x23c_020a27c4* obj);
extern "C" int func_ov003_02160854(void* obj);

struct Ctx02160a68;
extern "C" int func_ov003_02160a68(struct Ctx02160a68* self);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Obj2081;
void CallFunc0204c804OnMatchingKey_0207fdcc(struct Obj2081* obj, int key);

struct Obj0208203c;
void ResetWithSub0208203c(struct Obj0208203c* obj);

struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_02161344
extern "C" ARM int func_ov003_02161344(char* obj) {
    *(void**)(obj + kRegionValue470_298) = obj + kRegionValue49C_2C4;
    int result = 0;
    int flagB = result;

    GameState* battle = GameState::GetInstance();
    struct IntField0x23c_020a27c4* p = (struct IntField0x23c_020a27c4*)GetFieldIfFlag4_020100f8((char*)battle);
    if (p != 0 && ((*((unsigned char*)p + 0x244) & 2) != 0 || GetIntAt0x23c(p) == 0)) {
        flagB = (g_keyManager.TestKeysPressed(0x200) != 0) ? 1 : 0;
    }

    if (func_ov003_02160854(obj) != 0 || flagB != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        result = -1;
        if (*(short*)(obj + kRegionValue49C_2C4) == 0x2c) {
            result = 1;
        }
    } else {
        if (func_ov003_02160a68((struct Ctx02160a68*)obj) != 0) {
            result = -1;
        }
    }

    if (result != 0) {
        CallFunc0204c804OnMatchingKey_0207fdcc(*(struct Obj2081**)(obj + kRegionValue324_20C), *(short*)(obj + kRegionValue488_2B0));
        ResetWithSub0208203c((struct Obj0208203c*)(obj + kRegionValue308_1F0));
        *(void**)(obj + kRegionValue470_298) = 0;
    }

    if (*(void**)(obj + kRegionValue390_278) != 0 && result != 0) {
        ResetSelectionState020e25e8(*(struct Obj020e25e8**)(obj + kRegionValue390_278));
    }

    return result;
}
