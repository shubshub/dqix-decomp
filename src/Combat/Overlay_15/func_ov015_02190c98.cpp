#include <globaldefs.h>
#include "Input/Input.h"

extern "C" ARM int func_ov015_021925a8(void* obj);

struct Struct_ov015_02190c98 {
    char pad[0x350];
    unsigned char unknown_350_;
};

// USA: func_ov015_02190c98
extern "C" ARM int func_ov015_02190c98(struct Struct_ov015_02190c98* obj) {
    if (obj->unknown_350_ != 0) return 1;
    if (!func_ov015_021925a8(obj)) {
        if (g_keyManager.TestKeysHeld(0xc0)) return 1;
    }
    if (!func_ov015_021925a8(obj)) {
        if (g_keyManager.TestKeysReleased(0xc0)) return 1;
    }
    return 0;
}
