#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"

struct S_e830;

struct Struct_ov004_021589e8 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int top : 6;
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

struct Struct_ov004_02171048 { char pad[4]; struct Struct_ov004_0216ea74_4* ptr; };
extern Struct_ov004_02171048 data_ov004_02171048;

extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021b2090(Struct_ov004_021589e8 a, Struct_ov004_021589e8 b);
extern "C" int func_0201e830(struct S_e830* p);
extern "C" void Set3DClearColor(int, int, int, int, int);
extern "C" void func_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" int func_020cf0fc(int);
extern "C" int RTC_GetTime(int);

struct Struct_ov004_0216ea74 {
    unsigned char unknown_0_[4];
    SafeAllocator allocator;
};

static inline S_e830* inline_ov004_0216ea74(Zone3D* zone) {
    return (S_e830*)&zone->substruct_6c_;
}

struct Struct_ov004_0216ea74_2 {
    unsigned char unknown_0_[0x44];
    Struct_ov004_021589e8 unknown_44_;
    unsigned char unknown48[8];
    unsigned int flags;
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
extern "C" ARM int func_ov004_0216ea74(SafeAllocator* a) {
    GameState* bs = GameState::GetInstance();
    data_ov004_02171048.ptr = 0;
    Struct_ov004_0216ea74* ctx = (Struct_ov004_0216ea74*)func_ov011_021845f8(a, 0);
    if (!ctx) return 0;
    SafeAllocator* alloc = &ctx->allocator;
    struct Struct_ov004_0216ea74_4* blk = (struct Struct_ov004_0216ea74_4*)alloc->Allocate(sizeof(Struct_ov004_0216ea74_4));
    data_ov004_02171048.ptr = blk;
    if (!blk) return 0;

    blk->unknown_0_ = 0;
    blk->unknown_4_ = 0;
    blk->unknown_8_ = 0;
    blk->unknown_c_ = 0x3def;
    memset(blk->unknown_e_, 0, 0x20);
    blk->unknown_2e_[0] = 0;
    blk->unknown_2e_[1] = 0;
    blk->unknown_2e_[2] = 0;
    blk->unknown_2e_[3] = 0;
    blk->unknown_2e_[4] = 0;
    blk->unknown_2e_[5] = 0;
    blk->unknown_34_ = -1;
    memset(blk->unknown_3c_, 0, 0xc);
    blk->unknown_48_ = 0;

    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    if (!zone) return 0;
    S_e830* p = inline_ov004_0216ea74(zone);
    if (!p) return 0;
    data_ov004_02171048.ptr->unknown_c_ = func_0201e830(p);

    GameResources* obj = GetGameResources();
    data_ov004_02171048.ptr->unknown_0_ = GetFlags00(obj);
    data_ov004_02171048.ptr->unknown_4_ = GetFlags04(obj);
    data_ov004_02171048.ptr->unknown_8_ = GetFlags08(obj);
    SetFlags00(obj, 4);
    SetFlags04(obj, 0x8de);

    Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
    func_020c54a4(0, 0, 0, 0);

    int var7[4];
    int slotB[3];
    func_020cf0fc((int)var7);
    RTC_GetTime((int)slotB);

    data_ov004_02171048.ptr->unknown_38_.low = var7[0] + 0x7d0;
    data_ov004_02171048.ptr->unknown_38_.f12 = var7[1];
    data_ov004_02171048.ptr->unknown_38_.unknown_2_0_ = var7[2];
    data_ov004_02171048.ptr->unknown_38_.unknown_2_5_ = slotB[0];
    data_ov004_02171048.ptr->unknown_38_.top = slotB[1];

    Struct_ov004_0216ea74_2* var9 = &((Struct_ov004_0216ea74_3*)bs)->unknown_6380_;
    if (var9->flags & 1) {
        if (func_ov017_021b2090(var9->unknown_44_, data_ov004_02171048.ptr->unknown_38_) != 0) {
            data_ov004_02171048.ptr->unknown_2e_[2] = 1;
        }
    }
    return 0;
}
