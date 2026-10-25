#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov000_0215e9fc(int arg0, short* arg1, int arg2, int arg3);
extern "C" int func_ov000_0215ec1c(int arg0, short* arg1, int arg2, int arg3);
extern "C" void* func_ov000_02160f20(void* arg0);
extern "C" int func_0204936c(unsigned char* arg0);
extern "C" void func_ov025_021dc220(void* arg0);

struct Struct_ov025_021dc168 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
    char unknown_22_[0xe];
    struct Struct_ov025_021dc168* unknown_30_;
};

struct Struct_ov025_021dc168_2 {
    char unknown_0_[0x10];
    struct Struct_ov025_021dc168* unknown_10_;
};

struct Struct_ov025_021dc168_3 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    int unknown_29c_;
    char unknown_2a0_[0xeac - 0x2a0];
    int unknown_eac_;
};

// USA: func_ov025_021dc168
extern "C" ARM void func_ov025_021dc168(struct Obj021dc168* obj) {
    GameState* bs = GameState::GetInstance();
    int field29c = obj->field29c;
    bs->GetCamera();
    GetGameResources();

    short var2[12];
    int var3 = 0;
    var3 = var3 + func_ov000_0215e9fc(var1, var2, 12, var3);
    var3 = var3 + func_ov000_0215ec1c(var1, var2 + var3, 12 - var3, 0);

    if (arg0->unknown_eac_ == 2) {
        struct Struct_ov025_021dc168_2* var4 = (struct Struct_ov025_021dc168_2*)func_ov000_02160f20(arg0);
        struct Struct_ov025_021dc168* var5 = var4->unknown_10_;
        int var6 = 1;
        while (var5 != NULL) {
            GameObject* var7 = var0->GetCombatantByIndex(var5->unknown_20_);
            if (var7 != NULL && func_0204936c((unsigned char*)var7)) {
                var6 = 0;
                break;
            }
            var5 = var5->unknown_30_;
        }
        if (var6) {
            func_ov025_021dc220(arg0);
        }
    }
}
