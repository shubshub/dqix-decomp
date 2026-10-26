#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b594 data_ov008_0218c1aa
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct Struct_0206f81c_2;
struct TailList020469b4;
struct TailNode020469b4;
struct SafeAllocator;

extern "C" void func_ov008_02184a3c(char* obj, unsigned char value);
extern "C" void func_ov008_02184754(void* obj);
extern "C" void func_ov008_021845ac(void* obj);
extern "C" void func_020dc2d0(int mode);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int handler, int arg2);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_ov004_0216aa70(SafeAllocator* allocator, void* arg);
extern char data_ov008_0218b594;

struct Struct_ov008_0218b084 {
    char pad0[0x2a8];
    char unknown_2a8_[0xdb8 - 0x2a8];
    unsigned char unknown_db8_;
    char pad1[R(0xe98,0xe9c) - 0xdb9];
    signed char unknown_e9c_;
    char pad2[R(0xea8,0xeac) - R(0xe99,0xe9d)];
    int unknown_eac_;
#if !defined(jpn)
    int unknown_eb0_;
#endif
    char pad3[R(0xeb0,0xeb8) - R(0xeac,0xeb4)];
    unsigned char unknown_eb8_;
    char pad4;
    unsigned char unknown_eba_;
    char pad5[R(0xeb8,0xec0) - R(0xeb3,0xebb)];
    unsigned char bit0 : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char rest : 6;
};

// USA: func_ov008_0218b084
extern "C" ARM void func_ov008_0218b084(Struct_ov008_0218b084* self) {
    if (self->unknown_e9c_ == 0) {
        if (!self->unknown_ec0_1_) {
            self->unknown_e9c_ = 2;
            return;
        }
        func_ov008_02184a3c(self->unknown_2a8_, 0xd);
        self->unknown_e9c_ = self->unknown_e9c_ + 1;
        return;
    }
    if (self->unknown_e9c_ == 1) {
        func_ov008_02184754(self->unknown_2a8_);
        if (self->unknown_db8_ != 0xe) {
            return;
        }
        func_ov008_021845ac(self->unknown_2a8_);
        self->unknown_e9c_ = self->unknown_e9c_ + 1;
        return;
    }
    if (self->unknown_e9c_ != 2) {
        return;
    }
    void* res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    loader->RemoveTask(self->unknown_eac_);
#if !defined(jpn)
    loader->RemoveTask(self->unknown_eb0_);
    self->unknown_eac_ = -1;
    self->unknown_eb0_ = -1;
#endif
    unsigned short* var2 = (unsigned short*)0x4001008;
    var2[0] = (var2[0] & ~3) | 1;
    var2[1] = (var2[1] & ~3) | 2;
    var2[2] = (var2[2] & ~3);
    func_020dc2d0(0);
    if (self->unknown_eba_ != 0) {
        TailList020469b4* list;
        unsigned char* obj = *(unsigned char**)((char*)res + R(0x392c,0x3b4c));
        list = *(TailList020469b4**)((char*)res + R(0x34ec,0x36fc));
        func_ov017_021b2174(obj);
        func_ov017_021b2ba0((Struct_0206f81c_2*)obj, &data_ov008_0218b594);
        func_ov017_021b2bd0(obj, (int)func_ov004_0216aa70, OVERLAY_ID(4));
        func_020469b4(list, (TailNode020469b4*)obj);
    }
    self->unknown_eb8_ = 1;
}
