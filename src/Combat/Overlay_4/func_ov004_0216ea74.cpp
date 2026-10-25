#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"

struct Struct_0201e830;

struct Struct_ov004_021589e8 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};

struct Struct_ov004_0216ea74_4 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned short unknown_c_;
    unsigned char unknown_e_[0x20];
    unsigned char unknown_2e_[6];
    signed char unknown_34_;
    Struct_ov004_021589e8 unknown_38_;
    unsigned char unknown_3c_[0xc];
    unsigned int unknown_48_;
};

struct Struct_ov004_02171048 { char unknown_0_[4]; struct Struct_ov004_0216ea74_4* unknown_4_; };
extern Struct_ov004_02171048 data_ov004_02171048;

extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021b2090(PackedField017 a, PackedField017 b);
int GetFieldAt0x7e_0201e830(struct S_e830* p);
void Set3DClearColor_020c5588(int, int, int, int, int);
void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
int RegisterSlotA020cf0fc(int);
int RegisterSlotB020cf1a8(int);

struct Struct_ov004_0216ea74 {
    unsigned char unknown_0_[4];
    SafeAllocator unknown_4_;
};

static inline Struct_0201e830* inline_ov004_0216ea74(Zone3D* arg0) {
    return (Struct_0201e830*)&arg0->substruct_6c_;
}

struct Struct_ov004_0216ea74_2 {
    unsigned char unknown_0_[0x44];
    Struct_ov004_021589e8 unknown_44_;
    unsigned char unknown_48_[8];
    unsigned int unknown_50_;
};

struct Struct_ov004_0216ea74_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x6120];
#else
    unsigned char unknown1_0_[0x6380];
#endif
    Struct_ov004_0216ea74_2 unknown_6380_;
};

// USA: func_ov004_0216ea74
extern "C" ARM int func_ov004_0216ea74(SafeAllocator* arg0) {
    GameState* var0 = GameState::GetInstance();
    data_ov004_02171048.unknown_4_ = 0;
    Struct_ov004_0216ea74* var1 = (Struct_ov004_0216ea74*)func_ov011_021845f8(arg0, 0);
    if (!var1) return 0;
    SafeAllocator* var2 = &var1->unknown_4_;
    struct Struct_ov004_0216ea74_4* var3 = (struct Struct_ov004_0216ea74_4*)var2->Allocate(sizeof(Struct_ov004_0216ea74_4));
    data_ov004_02171048.unknown_4_ = var3;
    if (!var3) return 0;

    var3->unknown_0_ = 0;
    var3->unknown_4_ = 0;
    var3->unknown_8_ = 0;
    var3->unknown_c_ = 0x3def;
    memset(var3->unknown_e_, 0, 0x20);
    var3->unknown_2e_[0] = 0;
    var3->unknown_2e_[1] = 0;
    var3->unknown_2e_[2] = 0;
    var3->unknown_2e_[3] = 0;
    var3->unknown_2e_[4] = 0;
    var3->unknown_2e_[5] = 0;
    var3->unknown_34_ = -1;
    memset(var3->unknown_3c_, 0, 0xc);
    var3->unknown_48_ = 0;

    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    if (!zone) return 0;
    S_e830* p = GetZonePlacementData(zone);
    if (!p) return 0;
    data_ov004_02171048.ptr->half0c = GetFieldAt0x7e_0201e830(p);

    GameResources* var6 = GetGameResources();
    data_ov004_02171048.unknown_4_->unknown_0_ = GetFlags00(var6);
    data_ov004_02171048.unknown_4_->unknown_4_ = GetFlags04(var6);
    data_ov004_02171048.unknown_4_->unknown_8_ = GetFlags08(var6);
    SetFlags00(var6, 4);
    SetFlags04(var6, 0x8de);

    func_020c5588(0, 0x1f, 0x7fff, 0, 0);
    func_020c54a4(0, 0, 0, 0);

    int var7[4];
    int var8[3];
    func_020cf0fc((int)var7);
    func_020cf1a8((int)var8);

    data_ov004_02171048.unknown_4_->unknown_38_.unknown_0_0_ = var7[0] + 0x7d0;
    data_ov004_02171048.unknown_4_->unknown_38_.unknown_1_4_ = var7[1];
    data_ov004_02171048.unknown_4_->unknown_38_.unknown_2_0_ = var7[2];
    data_ov004_02171048.unknown_4_->unknown_38_.unknown_2_5_ = var8[0];
    data_ov004_02171048.unknown_4_->unknown_38_.unknown_3_2_ = var8[1];

    Struct_ov004_0216ea74_2* var9 = &((Struct_ov004_0216ea74_3*)var0)->unknown_6380_;
    if (var9->unknown_50_ & 1) {
        if (func_ov017_021b2090(var9->unknown_44_, data_ov004_02171048.unknown_4_->unknown_38_) != 0) {
            data_ov004_02171048.unknown_4_->unknown_2e_[2] = 1;
        }
    }
    return 0;
}
