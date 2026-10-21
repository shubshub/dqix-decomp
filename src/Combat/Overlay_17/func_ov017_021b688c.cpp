#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <NitroSDK/Graphics.h>
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_02018300_3;
struct Struct_02038598_5;
struct Struct_ov017_021b688c {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x330];
#endif
    unsigned int unknown_330_;
#if defined(jpn)
    char unknown_21c_[0x2a8 - 0x21c];
#else
    char unknown_334_[0x480 - 0x334];
#endif
    short unknown_480_;
    char unknown_482_[0x4a1 - 0x482];
    unsigned char unknown_4a1_;
    char unknown_4a2_[0x22];
};
struct Struct_ov017_021b688c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    signed char unknown_20_;
    char unknown_21_[3];
    Struct_ov017_021b688c* unknown_24_;
};
struct PartySlots { char pad_0[0xf78]; signed char slots[4]; unsigned char count; };
void CancelPendingAction020397cc(Obj020397cc*, int);
int GetFieldIfFlag4_020100f8(char*);
void SetFlagsAt0x244_020a28a0(unsigned char*, unsigned char);
extern "C" void func_020a0cc4(int);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern AllocatorUnion data_02114e20;
extern "C" void func_020a0c0c();
extern "C" void func_020a1df8(int);
extern "C" void func_ov003_0215f9c0(Struct_ov017_021b688c*, int);
extern "C" void func_ov003_0215f8cc(Struct_ov017_021b688c*, SafeAllocator*);
extern "C" void func_020a27b8(unsigned char*);
extern "C" int func_ov003_0215fce8(Struct_ov017_021b688c*, unsigned int);
extern "C" void func_ov003_0215fb94(Struct_ov017_021b688c*);
extern "C" void func_ov017_021b67d8(Struct_ov017_021b688c_2*);
extern "C" int func_02046b60(Struct_02038598_5*, int);
extern "C" void func_020397c0(void*);
extern "C" int func_ov017_021959b4();
extern "C" void func_020a27ac(void*);
extern "C" void func_020a28b0(unsigned char*, int);
extern "C" void* func_0205ec34();
extern "C" void* func_02010828(GameState*);
extern "C" void func_0206e424(void*, int);

// USA: func_ov017_021b688c
extern "C" ARM void func_ov017_021b688c(MenuWork* work) {
    GameState* game = GameState::GetInstance();
    Obj020397cc* object = (Obj020397cc*)game->GetUnknownGameObject();
    CancelPendingAction020397cc(object, 1);
    GameResources* resources = game->GetResources();
    SetFlags04(resources, 0xc0);
    SetFlagsAt0x244_020a28a0((unsigned char*)GetFieldIfFlag4_020100f8((char*)game), 1);
    if (work->state == 0) {
        func_020a0cc4(0x1b800);
        void* var3 = func_02012d88(&data_02114e20, 0x1b800);
        if (!var3) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var3, 0x1b800);
        arg0->unknown_8_.Reset();
        arg0->unknown_24_ = (Struct_ov017_021b688c*)arg0->unknown_8_.Allocate(sizeof(Struct_ov017_021b688c));
        if (!arg0->unknown_24_) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        func_020a1df8(3);
        func_ov003_0215f9c0(arg0->unknown_24_, arg0->unknown_1c_);
        arg0->unknown_24_->unknown_4a1_ = arg0->unknown_1f_;
        arg0->unknown_24_->unknown_480_ = arg0->unknown_20_;
        func_ov003_0215f8cc(arg0->unknown_24_, &arg0->unknown_8_);
        func_020a27b8((unsigned char*)func_020100f8((char*)var0));
        arg0->unknown_1d_++;
    } else if (arg0->unknown_1d_ == 1) {
        if (!func_ov003_0215fce8(arg0->unknown_24_, var0->GetTickCount())) return;
        Struct_0208cb08* var4 = func_02094a00();
        func_02094b40(var4);
        func_02094ab0(var4);
        func_02094b34(var4, 0x6f, 0x1388, 1, 1);
        arg0->unknown_1d_++;
    } else if (arg0->unknown_1d_ == 2) {
        if (!func_02094b4c(func_02094a00())) return;
        func_ov003_0215fb94(arg0->unknown_24_);
        arg0->unknown_1d_++;
    } else if (arg0->unknown_1d_ == 3) {
        DISPCNT = (arg0->unknown_24_->unknown_330_ << 8) | (DISPCNT & ~0x1f00);
        arg0->unknown_1d_++;
        func_ov017_021b67d8(arg0);
        arg0->unknown_1_ = 1;
        Struct_02038598_5* var5 = (Struct_02038598_5*)var2->unknown_ptr_array_36fc[0];
        if (func_02046b60(var5, 4) || func_02046b60(var5, 0x18)) {
            func_020397cc(var1, 1);
            return;
        }
        ClearFlags04(var2, 0xc0);
        func_020397c0(var1);
        unsigned char* var6 = (unsigned char*)func_020100f8((char*)var0);
        if (!func_ov017_021959b4()) func_020a27ac(var6);
        func_020a28b0(var6, 2);
        void* var7 = func_0205ec34();
        func_02010828(var0);
        Struct_ov000_02175808_4* var8 = (Struct_ov000_02175808_4*)func_02010828(var0);
        for (int var9 = 0; var9 < var8->unknown_f7c_; var9++) func_0206e424(var7, var8->unknown_f78_[var9]);
    }
}
