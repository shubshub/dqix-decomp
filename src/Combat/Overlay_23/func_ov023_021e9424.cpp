#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov023_021e8f28(int index);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void func_ov017_021d6134(void* obj, int value);

// USA: func_ov023_021e9424
extern "C" ARM int func_ov023_021e9424(char* ptr, int n) {
#if defined(jpn)
 enum {regionalOffset0=0x144};
#else
 enum {regionalOffset0=0x150};
#endif
    GameState::GetInstance();
    int var0 = func_ov017_021d60f4(ptr);
    ptr += 8;
    GameObject* combatant = func_ov023_021e8f28(var0);
    if (!combatant) return 0;

    int var2 = 1;
    int i;
    for (i = 0; i < n - 2; i += 2) {
        int val1 = func_ov017_021d60f4(ptr);
        char* var5 = ptr + 8;
        ptr += 0x10;
        int val2 = func_ov017_021d60f4(var5);
        int var7 = *(int*)((char*)combatant + regionalOffset0) + 0x194;
        unsigned char idx = (unsigned char)val1;
        int var9 = var7 + (idx << 5);
        short var10 = *(short*)(var9 + 0x18);
        if (var10 != val2) var2 = 0;
    }

    if (var2 != 0) {
        func_ov017_021d6134(ptr, 1);
    } else {
        func_ov017_021d6134(ptr, 0);
    }
    return 1;
}
