#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_ov017_0218db14 {
#if defined(jpn)
    unsigned char unknown_0_[0x4188];
#else
    unsigned char unknown1_0_[0x4438];
#endif
    Vector3fix unknown_4438_;
};

// USA: func_ov017_0218db14
extern "C" ARM int func_ov017_0218db14(struct Battle0218db14* battle, const Vector3fix* dir, int scale, int threshold, unsigned char force) {
    GameObject* obj = GameState::GetInstance()->GetLeader();
    if (obj == NULL) {
        return 0;
    }
    short* var1 = (short*)((char*)var0 + 0xb2);
    int var2 = *var1;
    var2 = (int)(((long long)var2 * arg2 + 0x800) >> 12);
    if (arg4) {
        *var1 = var2;
        return 1;
    }
    Vector3fix var3;
    Vector3fix_Normalize(arg1, &var3);
    if (Vector3fix_InnerProduct(&var3, &arg0->unknown_4438_) <= arg3) {
        *var1 = var2;
        return 1;
    }
    return 0;
}
