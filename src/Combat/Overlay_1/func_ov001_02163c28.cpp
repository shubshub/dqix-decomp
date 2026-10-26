#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02010768(void* obj);
extern "C" int func_ov017_021d6134(void* obj, int flag);

// USA: func_ov001_02163c28
extern "C" ARM int func_ov001_02163c28(void* obj) {
#if defined(jpn)
    enum { regionalFieldOffset = 0x444 };
#else
    enum { regionalFieldOffset = 0x424 };
#endif
    void* p = *(void**)func_02010768(GameState::GetInstance());
    int flag = 0;
    if (p != NULL) {
        flag = *(void**)((char*)p + regionalFieldOffset) != NULL;
    }
    func_ov017_021d6134(obj, flag);
    return 1;
}
