#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

#define REG_SUB_BG_0208cb08 (*(volatile Struct_0208cb08_2*)0x04001000)
struct Struct_0208cb08_2 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned short unknown_8_[4];
};
struct Struct_02015438;
struct Struct_02074b64 { unsigned char unknown_0_[0x14]; };
struct Struct_0204b12c;
struct Struct_0204af38;
struct Struct_02020cb8_5;
struct Struct_02020cb8_4;
struct Struct_02020aec;
struct Struct_0208cb08_3 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_;
    unsigned char unknown_1d_[3];
};
struct Struct_0208cb08_4 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    unsigned char unknown_28_[0x14];
    SafeAllocator unknown_3c_;
};
struct Struct_0208cb08_5 {
    Struct_0208cb08_4* unknown_0_;
    unsigned char unknown_4_[0x28];
    Struct_02074b64 unknown_2c_;
    Struct_0208cb08_3 unknown_40_;
    unsigned char unknown_60_[0x40];
    void* unknown_a0_;
    unsigned char unknown_a4_[8];
    unsigned short unknown_ac_;
    unsigned char unknown_ae_[2];
    unsigned char unknown_b0_;
    unsigned char unknown_b1_[3];
    char* unknown_b4_;
    unsigned int unknown_b8_;
    int unknown_bc_;
    unsigned char unknown_c0_[0x12];
    short unknown_d2_;
    unsigned char unknown_d4_, unknown_d5_, unknown_d6_;
    unsigned char unknown_d7_[3];
    unsigned short unknown_da_;
};
unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
void BackupSubBgControlRegisters(SubBgControlBackup02074b64*);
void OrGlobalFlag0x40_020dc2bc();
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void func_0204b11c(unsigned char*, int);
extern "C" void func_0204b12c(Struct_0204b12c*, SafeAllocator*);
extern "C" void func_0204af38(Struct_0204af38*, int, SafeAllocator*);
extern "C" void func_0204b5e8(Struct_02020cb8_5*, int, int);
extern "C" void func_0208c9cc(int, int, int, int, int);
extern "C" int func_02046900(Struct_02020cb8_4*);
extern "C" void* func_020467f0(Struct_02020aec*, int, void**, int*);
extern "C" void func_0205aed0(void*, char*, unsigned int, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" int func_0205a528(void*, void*, int, int);
extern "C" void func_020dfec0(void*, SafeAllocator*, void*, unsigned int);
extern "C" void func_0208bf78(Struct_0208cb08_5*);
extern char data_020f11a2[], data_020f11b3[], data_020f11c0[], data_020f11da[];

#if defined(jpn)
extern char data_020f129e[], data_020f12b2[];
#endif

// USA: func_0208cb08
extern "C" ARM void func_0208cb08(Object_0208cb08* object) {
    if (object->target < 0) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = GameState::GetInstance()->GetResources();
    if (object->state == 0) {
        SetFlags00(resources, 0x6000);
        OrBitsIntoField0_020466e4(GetDataPtr02114e04_020d6c00(), 1);
        FontBankLoader* global = GetGlobal02109400_02094a00();
        int notification = 0x67;
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) != 0x2d) {
            if (object->target < 0) notification = 0x32;
            else {
                int var4 = arg0->unknown_d2_ / 20;
                if (var4 > 9) var4 = 9;
                var3 = var4 + 0x32;
            }
        }
        func_02094b30(var2, var3, 0);
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 1) {
        if (func_02094b4c(func_02094a00())) ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 2) {
        func_02074b64(&arg0->unknown_2c_);
        func_020dc2bc();
        if (!(arg0->unknown_da_ & 0x10)) SetSubBrightness(var1, -16, 8);
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 3) {
        if (IsSubBrightnessTransitionActive(var1)) return;
        Struct_0208cb08_4* var5 = arg0->unknown_0_;
        var5->unknown_14_.Reset();
        func_0204b11c((unsigned char*)&arg0->unknown_40_, 0);
        arg0->unknown_40_.unknown_1c_ = (arg0->unknown_40_.unknown_1c_ & ~0xf) | 1;
        arg0->unknown_40_.unknown_1c_ &= ~0xf0;
        func_0204b5b4(&arg0->unknown_40_, 0);
        func_0204b12c((Struct_0204b12c*)&arg0->unknown_40_, &var5->unknown_14_);
        func_0204af38((Struct_0204af38*)&arg0->unknown_40_, 1, &var5->unknown_14_);
        func_0204b5e8((Struct_02020cb8_5*)&arg0->unknown_40_, 0, 0);
        func_0208c9cc(0, 0, 15, 0, 0);
        arg0->unknown_b0_ = 1;
        arg0->unknown_a0_ = arg0->unknown_b4_;
        arg0->unknown_ac_ = 3;
#if defined(jpn)
        arg0->unknown_bc_ = var0->QueueLoadFile(data_020f129e, 0);
#else
        arg0->unknown_bc_ = var0->QueueLoadFileInGP2(data_020f11a2, data_020f11b3, 0);
#endif
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 4) {
        if (!var0->GetTaskStatus(arg0->unknown_bc_)) return;
        Struct_0208cb08_4* var6 = arg0->unknown_0_;
        var6->unknown_3c_.Reset();
        void* var7;
        void* var8;
        unsigned int var9;
        var0->GetLoadedFileByID(arg0->unknown_bc_, &var8, &var9);
        int var10 = func_02046900((Struct_02020cb8_4*)var8);
        int var11 = 0;
        int var12;
        for (; var11 < var10; ++var11) {
            void* var13 = func_020467f0((Struct_02020aec*)var8, var11, &var7, &var12);
            func_0205a528(arg0->unknown_60_, var13, var12, (int)&var6->unknown_3c_);
        }
        func_0205aed0(arg0->unknown_60_, arg0->unknown_b4_, 3, 0x40);
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 5) {
#if defined(jpn)
        arg0->unknown_bc_ = var0->QueueLoadFile(data_020f12b2, 0);
#else
        arg0->unknown_bc_ = var0->QueueLoadFileInGP2(data_020f11c0, data_020f11da, 0);
#endif
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 6) {
        if (!var0->GetTaskStatus(arg0->unknown_bc_)) return;
        Struct_0208cb08_4* var14 = arg0->unknown_0_;
        void* var15;
        unsigned int var16;
        var0->GetLoadedFileByID(arg0->unknown_bc_, &var15, &var16);
        if (var14) {
            var14->unknown_0_.Reset();
            func_020dfec0(arg0->unknown_4_, &var14->unknown_0_, var15, var16);
        }
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 7) {
        func_0208bf78(arg0);
        ++arg0->unknown_d5_;
    } else if (arg0->unknown_d5_ == 8) {
        if (!arg0->unknown_d6_) {
            REG_SUB_BG_0208cb08.unknown_8_[0] &= ~3;
            REG_SUB_BG_0208cb08.unknown_8_[1] = (REG_SUB_BG_0208cb08.unknown_8_[1] & ~3) | 2;
            REG_SUB_BG_0208cb08.unknown_8_[2] = (REG_SUB_BG_0208cb08.unknown_8_[2] & ~3) | 3;
            REG_SUB_BG_0208cb08.unknown_8_[3] = (REG_SUB_BG_0208cb08.unknown_8_[3] & ~3) | 1;
            REG_SUB_BG_0208cb08.unknown_0_ = (REG_SUB_BG_0208cb08.unknown_0_ & ~0x1f00) | 0x1900;
            if (func_02046b24((Struct_02015438**)var1->unknown_ptr_array_36fc[0]) == 0x2d) {
                if (!IsSubBrightnessTransitionActive(var1)) SetSubBrightness(var1, 0, 25);
            } else if (!(arg0->unknown_da_ & 0x10)) SetSubBrightness(var1, 0, 8);
            ++arg0->unknown_d5_;
        } else func_0208bf78(arg0);
    } else if (arg0->unknown_d5_ == 9) {
        if (!IsSubBrightnessTransitionActive(var1)) {
            arg0->unknown_d4_ = 1;
            arg0->unknown_d5_ = 0;
        }
    }
}
