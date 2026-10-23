#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/Brightness.h"
struct Struct_02018300_3;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_ov017_021bec00_3 {
#if defined(jpn)
    char unknown_0_[0x240c];
#else
    char unknown1_0_[0x23ec];
#endif
    ActiveGrottoClass unknown_23ec_;
};
union Struct_ov017_021bec00_4 { struct { int unknown_0_, unknown_4_; }; long long unknown1_0_; };
struct Struct_ov017_021bec00_5 {
#if defined(jpn)
    char unknown_0_[0x7e8];
#else
    char unknown1_0_[0x918];
#endif
    short unknown_918_;
    char unknown_91a_[0x998-0x91a];
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_, unknown_9a4_;
    char unknown_9a8_[0x1858-0x9a8];
    Struct_ov017_021bec00_4 unknown_1858_;
#if defined(jpn)
    char unknown_1730_[0x17de - 0x1730];
#else
    char unknown_1860_[0x19ae - 0x1860];
#endif
    unsigned char unknown_19ae_, unknown_19af_;
    char unknown_19b0_[8];
    unsigned char unknown_19b8_;
};
struct Struct_ov017_021bec00 {
    unsigned short unknown_0_;
    char unknown_2_[2];
    unsigned char unknown_4_;
    char unknown_5_[2];
    unsigned char unknown_7_, unknown_8_, unknown_9_;
    char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    int unknown_10_, unknown_14_, unknown_18_;
    short unknown_1c_, unknown_1e_;
    int unknown_20_[4];
    char unknown_30_[0x6c-0x30];
    short unknown_6c_;
    char unknown_6e_[2];
};
struct Struct_ov017_021bec00_2 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[0x38-2];
    int unknown_38_;
    char unknown_3c_[4];
    int unknown_40_;
    SafeAllocator unknown_44_;
    char unknown_58_[0xa4];
};
extern "C" void func_0202ae18();
extern "C" Struct_ov017_021bec00_3* func_02012fe4();
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void KeyTable_Load(void*, SafeAllocator*, void*, unsigned int);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov017_021bec00_5*, char*, int);
#else
extern "C" void func_0204500c(Struct_ov017_021bec00_5*, char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_02043270(Struct_ov017_021bec00_5*, int, int, int, int);
#else
extern "C" void func_02042b98(Struct_ov017_021bec00_5*, int, int, int, int);
#endif
extern "C" void func_ov017_021bef84(Struct_ov017_021bec00_2*);
extern "C" Struct_ov017_021bec00_5* func_020421a0();
extern "C" void func_020397cc(Struct_02018300_3*, int);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" Struct_ov017_021bec00* func_0200fd0c(GameState*);
extern "C" void func_ov017_0219e310(unsigned char*, int);
extern "C" void func_020469b4(Struct_0201bdac_2*, Struct_0201bdac*);
extern "C" void func_02043204(char*);
extern "C" void func_020397c0(void*);
extern AllocatorUnion data_02114e20;
#if defined(jpn)
extern char data_ov017_021d86ac[], data_ov017_021d86c6[];
#else
extern char data_ov017_021d7e98[], data_ov017_021d7eb2[];
#endif
// USA: func_ov017_021bec00
extern "C" ARM void func_ov017_021bec00(Struct_ov017_021bec00_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    func_0202ae18();
    GameResources* var1 = GetGameResources();
    Struct_ov017_021bec00_5* var2 = func_020421a0();
    BackgroundLoader* var3 = BackgroundLoader::GetInstance();
    ActiveGrottoClass* var4 = &func_02012fe4()->unknown_23ec_;
    var0->GetGrottoStruct();
    char var5[0x100] = {};
    var2->unknown_19ae_ = 0;
    if (arg0->unknown_38_ == 0) {
        func_020397cc((Struct_02018300_3*)var0->GetUnknownGameObject(), 1);
        SetFlags04(var1, 0xc0);
        Struct_0208cb08* var6 = func_02094a00();
        func_02094b30(var6, 0x203, 0);
        if (func_02094b4c(var6)) {
            arg0->unknown_38_ = 1;
            arg0->unknown_44_.CreateTypeA(func_02012d88(&data_02114e20, 0xc00), 0xc00);
#if defined(jpn)
            arg0->unknown_40_ = var3->QueueLoadFile(data_ov017_021d86ac, 0);
#else
            arg0->unknown_40_ = var3->QueueLoadFile(data_ov017_021d7e98, 0);
#endif
        }
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.Reset();
            KeyTable_Load(&self->script, &self->allocator, data, length);
            loader->RemoveTask(self->task);
            self->task = -1;
            self->state = 2;
        }
    } else if (arg0->unknown_38_ == 2) {
        if (!IsBrightnessTransitionActive(var1)) {
            if ((unsigned char&)var4->unknown_260_[2]) {
                Struct_ov017_021bec00* var9 = func_0200fd0c(var0);
                VectorizedMemset(var9, 0, 0x70);
                var9->unknown_4_ = 1;
                var9->unknown_8_ = 1;
                var9->unknown_9_ = 1;
                var9->unknown_b_ = -1;
                var9->unknown_20_[0] = -1;
                var9->unknown_20_[1] = -1;
                var9->unknown_20_[2] = -1;
                var9->unknown_20_[3] = -1;
                var9->unknown_1e_ = -1;
                var9->unknown_c_ = 0;
                var9->unknown_6c_ = -1;
                var9->unknown_0_ = (unsigned short&)var4->unknown_274_;
                Vector3fix var10 = *(Vector3fix*)&var4->unknown_264_[1];
                var9->unknown_10_ = var10.x;
                var9->unknown_14_ = var10.y;
                var9->unknown_18_ = var10.z;
                var9->unknown_1c_ = 0x3244;
                var9->unknown_7_ = 1;
                Struct_0201bdac_2* var11;
                unsigned char* var12 = (unsigned char*)var1->unknown_ptr_array_36fc[4];
                var11 = (Struct_0201bdac_2*)var1->unknown_ptr_array_36fc[0];
                func_ov017_0219e310(var12, 0);
                func_020469b4(var11, (Struct_0201bdac*)var12);
                var4->unknown_260_[2] = 0;
                func_ov017_021bef84(arg0);
                arg0->unknown_1_ = 1;
            } else {
#if defined(jpn)
                sprintf(var5, data_ov017_021d86c6, var4->GetPopupName());
                func_0204500c(var2, var5, 0);
#else
                sprintf(var5, data_ov017_021d7eb2, var4->GetPopupName());
                func_0204500c(var2, var5, 0, 256);
#endif
                var2->unknown_19b8_ = 1;
                var2->unknown_19af_ = 0;
#if defined(jpn)
                func_02043270(var2, (256-var2->unknown_918_)/2, 64, var2->unknown_918_, 30);
#else
                func_02042b98(var2, (256-var2->unknown_918_)/2, 64, var2->unknown_918_, 30);
#endif
                long long var13 = var2->unknown_1858_.unknown1_0_;
                int var14 = (int)var13;
                int var15 = (int)(var13 >> 32) + 3;
                var2->unknown_1858_.unknown_0_ = var14;
                var2->unknown_1858_.unknown_4_ = var15;
                var2->unknown_9a4_ = 1;
                var2->unknown_998_ = 1;
                arg0->unknown_38_ = 3;
            }
        }
    } else if (arg0->unknown_38_ == 3 && var2->unknown_9a0_ == 0) {
        func_02043204((char*)var2);
        func_020397c0(var0->GetUnknownGameObject());
        Struct_0208cb08* var16 = func_02094a00();
        func_02094b38(var16, 0x1f9);
        func_02094ab0(var16);
        func_ov017_021bef84(arg0);
        arg0->unknown_1_ = 1;
    }
}
