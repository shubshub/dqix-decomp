#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Input/Input.h"

void FollowCamera_Update(void* actor);

struct Struct_ov015_02190d7c;
extern "C" void func_ov015_021931b4(struct Struct_ov015_02190d7c* arg0, int arg1);
struct Struct_ov015_02190d7c_2;
extern "C" int func_ov015_021931cc(struct Struct_ov015_02190d7c_2* arg0);
extern "C" void func_ov015_02192700(void* arg0, int arg1);
struct Struct_ov015_0218f1c4;
extern "C" ARM void func_ov015_0218f1c4(struct Struct_ov015_0218f1c4* arg0);

struct Struct_ov015_02190d7c_3 {
    int unknown_0_;
    struct Struct_ov015_02190d7c_3* unknown_4_;
};

struct Struct_ov015_02190d7c_4 {
    char unknown_0_[0x2c];
    struct Struct_ov015_02190d7c_3* unknown_2c_;
    char unknown_30_[0x38 - 0x2c - 4];
    signed char unknown_38_;
    char unknown_39_[0x194 - 0x38 - 1];
    int unknown_194_;
    int unknown_198_;
    char unknown_19c_[0x1a4 - 0x198 - 4];
    int unknown_1a4_;
};

// USA: func_ov015_02190d7c
extern "C" ARM void func_ov015_02190d7c(struct Struct_ov015_02190d7c_4* arg0) {
    GameState* var0 = GameState::GetInstance();
    if (var0 == 0) {
        return;
    }
    void* f3b0 = bs->GetCamera();
    if (f3b0 != 0) {
        FollowCamera_Update(f3b0);
    }

    struct Struct_ov015_02190d7c_3* var2 = arg0->unknown_2c_;
    while (var2 != 0) {
        func_ov015_0218f1c4((struct Struct_ov015_0218f1c4*)var2->unknown_0_);
        var2 = var2->unknown_4_;
    }

    if (!g_keyManager.TestKeysPressed(4)) {
        return;
    }

    int var3 = arg0->unknown_194_;
    arg0->unknown_194_ = arg0->unknown_198_;
    arg0->unknown_198_ = var3;

    int var4;
    if (arg0->unknown_194_ == 2) {
        func_ov015_021931b4((struct Struct_ov015_02190d7c*)arg0, arg0->unknown_1a4_);
        arg0->unknown_1a4_ = 0x23;
        goto cleanup;
    }

    do {
        var4 = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)arg0);
    } while (var4 >= 0x23);

    signed char var5 = arg0->unknown_38_;
    if (var5 >= 0) {
        switch (var5) {
        case 0:
        case 1:
            while (var4 >= 0xf) {
                var4 = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)arg0);
            }
            goto reset;
        case 2:
            while (var4 >= 0x21) {
                var4 = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)arg0);
            }
            goto reset;
        default:
        reset:
            arg0->unknown_38_ = -1;
            if (arg0->unknown_194_ == 1) {
                arg0->unknown_194_ = 0;
            }
            break;
        }
    }

    arg0->unknown_1a4_ = var4;
cleanup:
    func_ov015_02192700(arg0, 0);
}
