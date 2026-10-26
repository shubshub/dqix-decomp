#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

class Struct_ov001_02155d54;
extern "C" int func_ov028_021d8d40(Struct_ov001_02155d54* arg0, unsigned short arg1);
extern "C" int func_ov001_02156858(void*);
struct GameResources;
void UnlockAndSetBrightness(GameResources*, int, int);
extern "C" int func_ov001_02153994(void);

// USA: func_ov001_02155d54
extern "C" ARM int func_ov001_02155d54(void* obj) {
#if defined(jpn)
    enum { regionalOffset = -4 };
#else
    enum { regionalOffset = 0 };
#endif
    GameState::GetInstance();
    GameResources* b = GetGameResources();
    int var1 = *(int*)((char*)obj + 0x160 + regionalOffset);
    if (var1 != 0) {
        int r = func_ov028_021d8d40((Struct_ov001_02155d54*)var1, 2);
        *((unsigned char*)obj + 0x164 + regionalOffset) = (r != 0);
    }
    if (func_ov001_02156858(obj) != 0) {
        UnlockAndSetBrightness(b, -16, 0x1e);
        *(int*)((char*)obj + 0x15c + regionalOffset) = 1;
        return 0xe;
    }
    return (func_ov001_02153994() != 1) ? *(unsigned short*)((char*)obj + 0xa) : 0xf;
}
