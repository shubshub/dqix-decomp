#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" void* func_ov023_021fad18(void* obj);
extern "C" void func_02012028(void* obj, unsigned char value);

// USA: func_ov004_0216e828
extern "C" ARM int func_ov004_0216e828(void* a) {
#if defined(jpn)
    enum { Enum_ov004_0216e828_728 = 0x228, Enum_ov004_0216e828_736 = 0x230 };
#else
    enum { Enum_ov004_0216e828_728 = 0x2d8, Enum_ov004_0216e828_736 = 0x2e0 };
#endif
    void* base = func_ov011_021849c8(a);
    int g = MessageSystem_GetInstance();
    void* node = func_ov023_021f6880(base, 0xa);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 0xa) return 0;
    void* result = func_ov023_021fad18(node);
    if (result) {
        *(void**)((char*)g + Enum_ov004_0216e828_728) = result;
        int tmp = *(int*)((char*)result + 0x3c);
        if (tmp) {
            *(int*)((char*)g + Enum_ov004_0216e828_736) = tmp;
        }
    }
    func_02012028(GameState::GetInstance(), 0);
    return 0;
}
