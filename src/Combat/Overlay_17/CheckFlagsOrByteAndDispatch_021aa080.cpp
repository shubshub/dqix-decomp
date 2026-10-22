#if defined(jpn)
enum { RegionOffset9a0 = 0x870 };
#else
enum { RegionOffset9a0 = 0x9a0 };
#endif

#include <globaldefs.h>
#include "Input/Input.h"

extern int data_02107800;
struct SePlayer;
extern struct SePlayer g_sePlayer;

int GetGlobalField0x1c020421a0();
void SePlayer_Play(struct SePlayer* obj, int a, int b);

// USA: func_ov017_021aa080  (semantic: CheckFlagsOrByteAndDispatch_021aa080)
extern "C" ARM int func_ov017_021aa080() {
    int base = GetGlobalField0x1c020421a0();
    int field = *(int*)(base + RegionOffset9a0);
    int flag = 0;
    if (field == 3 || field == 0) {
        if (g_keyManager.TestKeysPressed(0x1) ||
            g_keyManager.TestKeysPressed(0x200) ||
            g_keyManager.TestKeysPressed(0x100) ||
            g_keyManager.TestKeysPressed(0x40) ||
            g_keyManager.TestKeysPressed(0x80) ||
            g_keyManager.TestKeysPressed(0x20) ||
            g_keyManager.TestKeysPressed(0x10)) {
            flag = 1;
        }
        if (g_touchInput.released_ != 0) {
            flag = 1;
        }
    }
    if (flag == 0) {
        return 0;
    }
    SePlayer_Play(&g_sePlayer, 1, 0);
    return 1;
}
