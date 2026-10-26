#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Input/Input.h"

// USA: func_02045740
ARM void MessageSystem::func_02045740() {
    int var0 = unknown_94c_[3];
    unknown_94c_[3] = (var0 + 1) & 0x1f;
    if (g_keyManager.TestKeysPressed(0x40)) {
        int c = unknown_94c_[2] - 1;
        unknown_94c_[2] = c;
        if (c < 0) {
            unknown_94c_[2] = unknown_9a4_ - 1;
        }
        unknown_994_ = unknown_94c_[2];
        unknown_94c_[3] = 0;
        return;
    }
    if (!g_keyManager.TestKeysPressed(0x80)) {
        return;
    }
    unknown_94c_[2] = unknown_94c_[2] + 1;
    if (unknown_94c_[2] >= unknown_9a4_) {
        unknown_94c_[2] = 0;
    }
    unknown_994_ = unknown_94c_[2];
    unknown_94c_[3] = 0;
}
