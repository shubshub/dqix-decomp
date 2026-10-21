#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "Combat/BufferedScriptResult.h"

#if defined(jpn)
#define data_ov017_021d7c10 data_ov017_021d832c
#endif
struct Struct_02018300_3 { char unknown_0_[0xb2]; short unknown_b2_; };
struct Struct_02046f84 { char unknown_0_[0xf0]; };
struct Struct_ov017_021b6290 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[6];
    unsigned char unknown_8_;
    char unknown_9_[3];
    Struct_02046f84 unknown_c_;
    unsigned char unknown_fc_, unknown_fd_;
    short unknown_fe_, unknown_100_;
};
struct Struct_02109bf4_4;
struct Struct_0203e5d8;
struct Struct_02038598_5;
extern "C" void* func_02012fe4();
extern "C" unsigned char* func_020704fc();
extern "C" void func_02017c58(void*);
extern "C" int func_02046cc8(Struct_02046f84*);
extern "C" int func_0204700c(Struct_02046f84*);
extern "C" void* func_ov017_021b8478(void*);
extern "C" void func_0209c480(Struct_02109bf4_4*, int);
extern "C" void func_0209c2e0(Struct_02109bf4_4*, int, int);
extern "C" void func_0205e944(void*, int);
extern "C" void func_02043124(void*);
extern "C" int abs(int);
extern "C" void func_020397cc(Struct_02018300_3*, int);
extern "C" void func_0209c678(Struct_02109bf4_4*, int);
extern "C" int func_02046b60(Struct_02038598_5*, int);
extern "C" void* func_020421a0();
extern "C" Struct_0203e5d8* func_0203cf4c();
extern "C" void func_0203e5d8(Struct_0203e5d8*, int);
extern "C" float func_020709ac(unsigned char*);
extern "C" unsigned int* func_020d6c00();
extern "C" void func_020466e4(unsigned int*, unsigned int);
extern "C" void func_02047198(Struct_02046f84*);
extern "C" void func_02046f84(Struct_02046f84*);
extern "C" void func_ov017_0218d274(void* arg0);
extern "C" void func_ov017_0218f79c(void*);
extern "C" void func_ov017_021a2840(GameResources*);
extern char data_ov017_021d7c10[];
extern Struct_02109bf4_4 data_02109bf4;
extern char data_02108760[];
// USA: func_ov017_021b6290
extern "C" ARM void func_ov017_021b6290(Struct_ov017_021b6290* arg0) {
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    func_02012fe4();
    Struct_02018300_3* var2 = (Struct_02018300_3*)var0->GetUnknownGameObject();
    unsigned char* var3 = func_020704fc();
    BackgroundLoader* var4 = BackgroundLoader::GetInstance();
    void* var5 = var1->unknown_ptr_3718;
    if (arg0->unknown_fc_ == 0) {
        func_020397cc(var2, 1);
        var2->unknown_b2_ = 0;
        if (arg0->unknown_fe_ >= 0) {
            arg0->unknown_100_ = var4->QueueLoadFile(data_ov017_021d7c10, 0);
            func_0209c678(&data_02109bf4, 10);
        }
        if (arg0->unknown_fe_ <= 0) arg0->unknown_fd_ = 0;
        if (arg0->unknown_8_) func_02017c58(func_02012fe4());
        arg0->unknown_fc_ = 1;
    }
    if (arg0->unknown_fd_) --arg0->unknown_fd_;
    if (arg0->unknown_fc_ == 1) {
        if (func_02046cc8(&arg0->unknown_c_)) arg0->unknown_fc_ = 2;
    } else if (arg0->unknown_fc_ == 2) {
        if (arg0->unknown_fd_ == 0) {
            int var6 = 23;
            if (arg0->unknown_100_ > BackgroundLoader::TaskStatus_Invalid) {
                if (!var4->GetTaskStatus(arg0->unknown_100_)) return;
                void* var7;
                unsigned int var8;
                var4->GetLoadedFileByID(arg0->unknown_100_, &var7, &var8);
                Struct_02074060 var9;
                Struct_02074060* var10 = &var9;
                if (func_02046b60((Struct_02038598_5*)var1->unknown_ptr_array_36fc[0], 10)) {
                    void* var11 = func_ov017_021b8478(var5);
                    if (var11) var10 = (Struct_02074060*)((char*)var11 + 0x10);
                }
                if (func_0207416c(var10, arg0->unknown_fe_, var7, var8)) var6 = var10->unknown_e_;
                var4->RemoveTask(arg0->unknown_100_);
                arg0->unknown_100_ = BackgroundLoader::TaskStatus_Invalid;
            }
            func_0209c480(&data_02109bf4, var6);
            func_0209c2e0(&data_02109bf4, 127, 0);
            func_0205e944(data_02108760, 127);
            SetFlags04(resources, 0x40);
            func_02043124(GetGlobalField0x1c020421a0());
            SetOrClearBit0x10OnEntries_0203e5d8(GetGlobalPtr021075f4_0203cf4c(), 0);
            if ((int)GetIntAt0xc_020709ac(timing) > 30 || abs(GetBrightness((GameResources*)resources, false)) == 16) {
                SetMainBrightness(resources, -16, 0);
                if (GetBrightness((GameResources*)resources, true) == Brightness_Normal) {
                    SetSubBrightness(resources, -16, 15);
                }
                arg0->unknown_fc_ = 4;
            } else arg0->unknown_fc_ = 3;
        }
    } else if (arg0->unknown_fc_ == 3) {
        if (func_0204700c(&arg0->unknown_c_)) arg0->unknown_fc_ = 4;
    } else if (arg0->unknown_fc_ == 4) {
        if (!IsBrightnessTransitionActive(var1)) {
            SetFlags04(var1, 4);
            SetFlags04(var1, 16);
            SetFlags04(var1, 2);
            SetFlags00(var1, 4);
            func_020466e4(func_020d6c00(), 1);
            func_02047198(&arg0->unknown_c_);
            func_02046f84(&arg0->unknown_c_);
            func_ov017_0218d274(var1);
            func_ov017_0218f79c(var1);
            func_ov017_021a2840(var1);
            func_0203e5d8(func_0203cf4c(), 1);
            arg0->unknown_1_ = 1;
        }
    }
}
