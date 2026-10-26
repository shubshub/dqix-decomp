#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov017_0218e8c8 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov017_0218e8c8_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x3508];
#else
    unsigned char unknown1_0_[0x3718];
#endif

    Struct_ov017_0218e8c8* unknown_3718_;
#if defined(jpn)
    unsigned char unknown_350c_[0x3910 - 0x350c];
#else
    unsigned char unknown_371c_[0x3b30 - 0x371c];
#endif

    Struct_ov017_0218e8c8* unknown_3b30_;
};

extern "C" char* Zone3D_GetInstance(void);
int IsIdInRange020981e4(int, int);
unsigned short GetField6b4_021b8480(void* obj);
extern "C" unsigned char* func_ov017_021b8478(void* obj);
int GetByteAtPtrOrZero_02191b58(void*, int);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_ov017_0218eafc(OvCtx0218e8c8* ov, int idx);
int GameObject_IsHidden(unsigned char* obj);
extern "C" int GameObject_Draw(void* obj, int a, int b);
extern "C" void func_ov017_0218dba0(int id);

// USA: func_ov017_0218e8c8
extern "C" ARM void func_ov017_0218e8c8(Struct_ov017_0218e8c8_2* arg0, int arg1, int arg2) {
#if defined(jpn)
 enum {Enum_ov017_0218e8c8_2112=0x860};
#else
 enum {Enum_ov017_0218e8c8_2112=0x840};
#endif
    GameState* gs = GameState::GetInstance();
    char* base = Zone3D_GetInstance();
    int inRange = 0;
    if (IsIdInRange020981e4((int)(base + regionalOffset0), id)) {
        inRange = 1;
    }

    unsigned char* var3 = NULL;
    if ((arg0->unknown_3718_->unknown_3_ != 0 && func_ov017_021b8480(arg0->unknown_3718_) == 0) ||
        (arg0->unknown_3b30_->unknown_3_ != 0 && arg0->unknown_3718_->unknown_2_ != 0)) {
        var3 = func_ov017_021b8478(arg0->unknown_3718_);
    }

    for (int var4 = 0; var4 < 4; var4++) {
        unsigned char var5 = func_ov017_02191b58(arg0, var4) | 2;
        if (arg2 == 1) {
            if (var5 != 0) continue;
        } else if (arg2 == 2 && var5 == 0) {
            continue;
        }

        int var6 = 0;
        GameObject* var7 = func_0200ff1c(var0, var4);
        GameObject* var8 = var0->GetGameObjectByIndex(var4 * 0xc + 0x14);
        if (var7 == NULL) continue;

        if (TestFlags08((GameResources*)arg0, 2) == 0 && var7->obj3D_.GetFlag(0x800000) == 0) {
            if (arg1 != var7->obj3D_.GetField06()) continue;
        } else if (TestFlags08((GameResources*)arg0, 4) != 0) {
            if (arg1 != var7->obj3D_.GetField06()) continue;
        }

        if (var3 != NULL && func_020a35e0(var3, var4) == 0) continue;

        if (var2 && var8 != NULL) {
            if (var8->obj3D_.unknown_2_ == 0x2347 || var8->obj3D_.unknown_2_ == 0x2348 ||
                var8->obj3D_.unknown_2_ == 0x2349) {
                var6 = 1;
            }
        }
        if (var6) continue;

        func_ov017_0218eafc(arg0, var4);
    }

    GameObject* member = gs->GetPartyMemberByIndex(0xce);
    if (member != NULL && !GameObject_IsHidden((unsigned char*)member) && GameObject_Draw(member, 1, 0)) {
        func_ov017_0218dba0(0xce);
    }
}
