#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_0208baec_2 { unsigned char unknown_0_[0xc]; int unknown_c_, unknown_10_, unknown_14_, unknown_18_; unsigned short unknown_1c_; unsigned short unknown_1e_; unsigned short unknown_20_; unsigned char unknown_22_; unsigned char unknown_23_[5]; };

struct Struct_0208cfcc { char unknown_0_[0x3c]; SafeAllocator unknown_3c_; };
struct Struct_0208cfcc_2 { char unknown_0_[0x40]; Struct_0208baec_2* unknown_40_; char unknown_44_[8]; unsigned short unknown_4c_; char unknown_4e_[2]; unsigned char unknown_50_; char unknown_51_[3]; };
struct Struct_02065990_2 {
    Struct_0208cfcc* unknown_0_;
    char unknown_4_[0x5c];
    Struct_0208cfcc_2 unknown_60_;
    Struct_0208baec_2* unknown_b4_;
    char unknown_b8_[8];
    int unknown_c0_;
    int unknown_c4_;
    int unknown_c8_;
    float unknown_cc_;
    unsigned short unknown_d0_;
    short unknown_d2_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_;
    unsigned char unknown_d8_;
    signed char unknown_d9_;
    unsigned short unknown_da_;
};
struct Struct_02020cb8_4;
struct Struct_02020aec;
#if defined(jpn)
extern char data_020f12cc[];
#endif
extern char data_020f11eb[];
extern char data_020f11fe[];
extern char g_sePlayer[];
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_0208bf28(Struct_02065990_2*, int, unsigned char);
extern "C" int func_02046900(Struct_02020cb8_4*);
extern "C" void func_0205a444(char*);
extern "C" void* func_020467f0(Struct_02020aec*, int, void**, int*);
extern "C" void func_0205a528(Struct_0208cfcc_2*, void*, int, SafeAllocator*);
extern "C" void func_0205aed0(void*, char*, unsigned int, int);
extern "C" void func_0205af38(int, char*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void func_0205eb54(void*, int, int);
extern "C" void func_0205eb90(void*, int, int);
extern "C" void func_0205eb80(void*);

static inline int inline_0208cfcc(Struct_02065990_2* arg0) { return (arg0->unknown_da_ & 0x100) == 0; }

// USA: func_0208cfcc
extern "C" ARM void func_0208cfcc(Struct_02065990_2* arg0) {
    Struct_0208cfcc* var0;
    BackgroundLoader* var1;
    GameResources* var2 = GetGameResources();
    var1 = BackgroundLoader::GetInstance();
    if (arg0->unknown_d5_ == 0) {
        int var3 = inline_0208cfcc(arg0) == 0;
        unsigned int var4 = 300;
        if (var3) var4 = 150;
        if (arg0->unknown_d0_ < var4) arg0->unknown_d0_ += GameState::GetInstance()->GetTickCount();
        else if (var3) {
            SetSubBrightness(var2, -4, 4);
#if defined(jpn)
            arg0->unknown_c0_ = var1->QueueLoadFile(data_020f12cc, 0);
#else
            arg0->unknown_c0_ = var1->QueueLoadFileInGP2(data_020f11eb, data_020f11fe, 0);
#endif
            arg0->unknown_d5_++;
        } else {
            func_0208bf28(arg0, arg0->unknown_d2_, 0);
            arg0->unknown_da_ |= 4;
            arg0->unknown_c8_ = 0;
            arg0->unknown_d7_ = 0;
            arg0->unknown_d5_ = 2;
        }
    } else if (arg0->unknown_d5_ == 1) {
        if (var1->GetTaskStatus(arg0->unknown_c0_)) {
            var0 = arg0->unknown_0_;
            var0->unknown_3c_.Reset();
            void* var5;
            void* var6;
            unsigned int var7;
            var1->GetLoadedFileByID(arg0->unknown_c0_, &var6, &var7);
            int var8 = func_02046900((Struct_02020cb8_4*)var6);
            func_0205a444((char*)&arg0->unknown_60_);
            arg0->unknown_60_.unknown_50_ = 1;
            arg0->unknown_60_.unknown_40_ = arg0->unknown_b4_;
            arg0->unknown_60_.unknown_4c_ = 3;
            for (int var9 = 0; var9 < var8; var9++) {
                int var10;
                void* var11 = func_020467f0((Struct_02020aec*)var6, var9, &var5, &var10);
                func_0205a528(&arg0->unknown_60_, var11, var10, &var0->unknown_3c_);
            }
            func_0205aed0(&arg0->unknown_60_, (char*)arg0->unknown_b4_, 3, 64);
            var1->RemoveTask(arg0->unknown_c0_);
            arg0->unknown_c0_ = -1;
            arg0->unknown_da_ |= 4;
            arg0->unknown_c8_ = 0;
            arg0->unknown_d7_ = 0;
            arg0->unknown_d5_++;
        }
    } else if (arg0->unknown_d5_ == 2) {
        if (!IsSubBrightnessTransitionActive(GetGameResources())) {
            func_0205af38((int)&arg0->unknown_60_, (char*)&arg0->unknown_b4_[0], 1, 1);
            func_0205af38((int)&arg0->unknown_60_, (char*)&arg0->unknown_b4_[1], 1, 1);
            arg0->unknown_d8_ = 0;
            arg0->unknown_cc_ = 0;
            arg0->unknown_da_ &= ~1;
            arg0->unknown_d5_++;
        }
    } else if (arg0->unknown_d5_ == 3) {
        arg0->unknown_da_ |= 8;
        if (arg0->unknown_cc_ < 1.0f) arg0->unknown_cc_ += 0.2f;
        else {
            obj->blend = 1.0f;
            SetForwardAndStore0205eb54(g_sePlayer, 110, 110);
            DispatchIfField0xc4NonNeg_0205eb90(g_sePlayer, 0, 0);
            obj->state++;
            obj->delay = 30;
        }
    } else if (arg0->unknown_d5_ == 4) {
        arg0->unknown_da_ |= 128;
        arg0->unknown_d5_++;
    } else if (arg0->unknown_d5_ == 5) {
        if (!(arg0->unknown_da_ & 128)) {
            arg0->unknown_cc_ += 0.2f;
            if (1.0f < arg0->unknown_cc_) {
                arg0->unknown_cc_ = 1.0f;
                arg0->unknown_d5_++;
            }
        }
    } else if (obj->state == 6 && obj->delay == 0) {
        ForwardField0xc0_0205eb80(g_sePlayer);
        obj->complete = 1;
        obj->state = 0;
    }
}
