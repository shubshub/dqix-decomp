#include <globaldefs.h>
#if defined(jpn)
#include "std_library_functions.h"
#endif
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Memory.h"
#include "Resource/GameResources.h"

struct Struct_02072a68_2 {
    struct Struct_02072a68* unknown_0_;
    short unknown_4_;
};
struct Struct_02020cb8_4;
struct Struct_02020aec;

struct Struct_ov003_021737e4 {
    void* unknown_0_;
    void* unknown_4_;
    void* unknown_8_;
    char unknown_c_[0xa8 - 0xc];
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[0xb4 - 0xac];
    short unknown_b4_;
    short unknown_b6_;
    char unknown_b8_[0xe0 - 0xb8];
};

#if defined(jpn)
struct Struct_ov003_021737e4_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[0x40];
    char unknown_42_[0x80];
    char unknown_c2_[0xc4 - 0xc2];
    short unknown_c4_;
    short unknown_c6_;
    char unknown_c8_[0xd0 - 0xc8];
    unsigned char unknown_d0_;
    char unknown_d1_[0xd4 - 0xd1];
    char unknown_d4_[0xe9 - 0xd4];
    unsigned char unknown_e9_;
    unsigned char unknown_ea_;
    unsigned char unknown_eb_;
    char unknown_ec_[0xf8 - 0xec];
    int unknown_f8_;
};

extern "C" void func_020a620c(void* obj);
int Pac_CountFiles(ActiveEntry02046900* pac);
void* Pac_GetFile(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void func_0204c684(void* canvas);
extern "C" void* func_02012fe4(void);
extern "C" void __clear(void*, unsigned int);
extern "C" void func_02041f50(char*, char*);
extern "C" int func_02042798(const char*, int, int);
extern "C" void func_02050678(Struct_ov003_021737e4*, short, short, const char*, int, unsigned char, short*, short*);

extern char data_ov003_02180a76[];
extern char data_ov003_0217ec90[];
extern char data_ov003_0217ec99[];
extern char data_ov003_0217eca2[];
extern char data_ov003_0217ecbc[];
extern char data_ov003_0217ecc3[];
extern char data_ov003_0217ebff[];

// USA: func_ov003_021737e4
extern "C" ARM void func_ov003_021737e4(Struct_ov003_021737e4_2* arg0) {
    GetGameResources();
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    func_020a620c(arg0->unknown_d4_);
    if (arg0->unknown_eb_ == 0) {
        arg0->unknown_f8_ = var0->QueueLoadFile(data_ov003_02180a76, NULL);
        arg0->unknown_eb_ = 1;
    } else if (arg0->unknown_eb_ == 1) {
        if (var0->GetTaskStatus(arg0->unknown_f8_) == 0) {
            return;
        }
        void* name;
        void* file;
        unsigned int size;
        void* records[3];
        int sizes[3];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = Pac_CountFiles((ActiveEntry02046900*)file);
        for (int i = 0; i < count; i++) {
            records[i] = Pac_GetFile((Rec020467f0*)file, i, &name, &sizes[i]);
        }
        void* var8 = arg0->unknown_1_ ? var4[1] : var4[0];
        Struct_ov003_021737e4 var9;
        func_0204c684(&var9);
        var9.unknown_8_ = (char*)var8 + 0x10;
        var9.unknown_a8_ = 0x20;
        var9.unknown_aa_ = 8;
        var9.unknown_b4_ = 0xc;
        var9.unknown_b6_ = 0xc;
        func_02012fe4();
        char var10[0x100];
        char var11[0x100];
        char var12[0x100];
        short var13;
        short var14;
        int var15;
        __clear(var10, sizeof(var10));
        __clear(var11, sizeof(var11));
        __clear(var12, sizeof(var12));
        if (arg0->unknown_1_ != 0) {
            sprintf(var12, data_ov003_0217ec90, arg0->unknown_2_);
            int var16 = 4;
            if (strstr(arg0->unknown_2_, data_ov003_0217ec99)) {
                sprintf(var10, data_ov003_0217eca2);
                func_02041f50(var10, var11);
                var15 = func_02042798(var10, 0x100, 0xc);
                func_02050678(&var9, var15 + 1, 0x16, var11, 0xc, 0xe, &var13, &var14);
                func_02050678(&var9, var15, 0x16, var10, 0xc, 0xf, &var13, &var14);
                var16 = 0xf;
            } else if (strstr(arg0->unknown_2_, data_ov003_0217ecbc)) {
                sprintf(var10, data_ov003_0217ecc3);
                func_02041f50(var10, var11);
                var15 = func_02042798(var10, 0x100, 0xc);
                func_02050678(&var9, var15 + 1, 0x16, var11, 0xc, 0xe, &var13, &var14);
                func_02050678(&var9, var15, 0x16, var10, 0xc, 0xf, &var13, &var14);
                var16 = 0xf;
            }
            var15 = func_02042798(var12, 0x100, 0xd);
            func_02050678(&var9, var15 + 1, var16 + 0x16, var12, 0xc, 0xe, &var13, &var14);
            func_02050678(&var9, var15, var16 + 0x16, var12, 0xc, 0xf, &var13, &var14);
        } else {
            sprintf(var10, data_ov003_0217ebff, arg0->unknown_42_);
            func_02041f50(var10, var11);
            sprintf(var12, data_ov003_0217ec90, arg0->unknown_2_);
            var15 = func_02042798(var10, 0x100, 0xc);
            func_02050678(&var9, var15 + 1, 0x16, var11, 0xc, 0xe, &var13, &var14);
            func_02050678(&var9, var15, 0x16, var10, 0xc, 0xf, &var13, &var14);
            var15 = func_02042798(var12, 0x100, 0xc);
            func_02050678(&var9, var15 + 1, 0x25, var12, 0xc, 0xe, &var13, &var14);
            func_02050678(&var9, var15, 0x25, var12, 0xc, 0xf, &var13, &var14);
        }
        int var17 = (arg0->unknown_d0_ - 1) * 0x2000 + 0x1000;
        CleanInvalidateCacheRange((char*)var8 + 0x10, 0x2000);
        LoadToSubBG0CharacterData((char*)var8 + 0x10, var17, 0x2000);
        int var18;
        if (arg0->unknown_1_) {
            var18 = 3;
        } else {
            var18 = 2;
        }
        unsigned short* var19 = (unsigned short*)GetSubBG0ScreenBase();
        for (int var20 = 0; var20 < 0x100; var20++) {
            *(var19 + var20 + (arg0->unknown_d0_ - 1) * 0x100) =
                (unsigned short)(var20 + 0x80 + (arg0->unknown_d0_ - 1) * 0x100) | (unsigned short)(var18 << 12);
        }
        arg0->unknown_c6_ = (arg0->unknown_d0_ << 6) - 0xc0;
        var0->RemoveTask(arg0->unknown_f8_);
        arg0->unknown_f8_ = -1;
        arg0->unknown_eb_ = 2;
    } else if (arg0->unknown_eb_ == 2) {
        if (arg0->unknown_c4_ < arg0->unknown_c6_) {
            arg0->unknown_c4_ += (int)(0.4f * (arg0->unknown_c6_ - arg0->unknown_c4_)) + 1;
            *(volatile unsigned int*)0x04001010 = (arg0->unknown_c4_ << 16) & 0x1ff0000;
        }
        if (arg0->unknown_c4_ >= arg0->unknown_c6_) {
            arg0->unknown_c4_ = arg0->unknown_c6_;
            *(volatile unsigned int*)0x04001010 = (arg0->unknown_c4_ << 16) & 0x1ff0000;
            arg0->unknown_1_ = 0;
            VectorizedMemset(arg0->unknown_2_, 0, 0x40);
            VectorizedMemset(arg0->unknown_42_, 0, 0x80);
            arg0->unknown_e9_ = 2;
            arg0->unknown_eb_ = 0;
        }
    }
}
#else
struct Struct_ov003_021737e4_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    short unknown_2_;
    char unknown_4_[0x40];
    char unknown_44_[0x80];
    char unknown_c4_[0xc6 - 0xc4];
    short unknown_c6_;
    short unknown_c8_;
    char unknown_ca_[0xd4 - 0xca];
    unsigned char unknown_d4_;
    char unknown_d5_[0xd8 - 0xd5];
    char unknown_d8_[0xed - 0xd8];
    unsigned char unknown_ed_;
    unsigned char unknown_ee_;
    unsigned char unknown_ef_;
    char unknown_f0_[0xf4 - 0xf0];
    int unknown_f4_;
    char unknown_f8_[0x1d8 - 0xf8];
    Struct_02072a68_2 unknown_1d8_;
};

extern "C" void func_020a620c(void* obj);
int Pac_CountFiles(ActiveEntry02046900* pac);
void* Pac_GetFile(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void func_0204c684(void* canvas);
extern "C" void* func_02012fe4(void);
extern "C" char* func_02072a68(Struct_02072a68_2* arg0, int arg1);
extern "C" void func_ov003_02172618(void* arg0, int arg1, char** arg2);

extern char data_ov003_02180a76[];

// USA: func_ov003_021737e4
extern "C" ARM void func_ov003_021737e4(Struct_ov003_021737e4_2* arg0) {
    GetGameResources();
    BackgroundLoader* var21 = BackgroundLoader::GetInstance();
    func_020a620c(arg0->unknown_d8_);
    if (arg0->unknown_ef_ == 0) {
        arg0->unknown_f4_ = var21->QueueLoadFile(data_ov003_02180a76, NULL);
        arg0->unknown_ef_ = 1;
    } else if (arg0->unknown_ef_ == 1) {
        if (var21->GetTaskStatus(arg0->unknown_f4_) == 0) {
            return;
        }
        void* name;
        void* file;
        unsigned int size;
        void* records[3];
        int sizes[3];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = Pac_CountFiles((ActiveEntry02046900*)file);
        for (int i = 0; i < count; i++) {
            records[i] = Pac_GetFile((Rec020467f0*)file, i, &name, &sizes[i]);
        }
        void* var29 = arg0->unknown_1_ ? var25[1] : var25[0];
        Struct_ov003_021737e4 var30;
        func_0204c684(&var30);
        var30.unknown_8_ = (char*)var29 + 0x10;
        var30.unknown_a8_ = 0x20;
        var30.unknown_aa_ = 8;
        var30.unknown_b4_ = 0xc;
        var30.unknown_b6_ = 0xc;
        func_02012fe4();
        if (arg0->unknown_1_ != 0) {
            char* var31[2] = {0};
            var31[1] = arg0->unknown_4_;
            int var32 = 4;
            if (arg0->unknown_2_ == 1) {
                var31[0] = func_02072a68(&arg0->unknown_1d8_, 0xc8);
                var32 = 0xf;
            } else if (arg0->unknown_2_ == 2) {
                var31[0] = func_02072a68(&arg0->unknown_1d8_, 0xc9);
                var32 = 0xf;
            }
            func_ov003_02172618(&var30, var32, var31);
        } else {
            char* var33[2] = {arg0->unknown_44_, arg0->unknown_4_};
            func_ov003_02172618(&var30, 0xf, var33);
        }
        int var34 = (arg0->unknown_d4_ - 1) * 0x2000 + 0x1000;
        CleanInvalidateCacheRange((char*)var29 + 0x10, 0x2000);
        LoadToSubBG0CharacterData((char*)var29 + 0x10, var34, 0x2000);
        int var35 = 2;
        if (arg0->unknown_1_) {
            var35 = 3;
        }
        unsigned short* var36 = (unsigned short*)GetSubBG0ScreenBase();
        for (int var37 = 0; var37 < 0x100; var37++) {
            *(var36 + var37 + (arg0->unknown_d4_ - 1) * 0x100) =
                (unsigned short)(var37 + 0x80 + (arg0->unknown_d4_ - 1) * 0x100) | (unsigned short)(var35 << 12);
        }
        arg0->unknown_c8_ = (arg0->unknown_d4_ << 6) - 0xc0;
        var21->RemoveTask(arg0->unknown_f4_);
        arg0->unknown_f4_ = -1;
        arg0->unknown_ef_ = 2;
    } else if (arg0->unknown_ef_ == 2) {
        if (arg0->unknown_c6_ < arg0->unknown_c8_) {
            arg0->unknown_c6_ += (int)(0.4f * (arg0->unknown_c8_ - arg0->unknown_c6_)) + 1;
            *(volatile unsigned int*)0x04001010 = (arg0->unknown_c6_ << 16) & 0x1ff0000;
        }
        if (arg0->unknown_c6_ >= arg0->unknown_c8_) {
            arg0->unknown_c6_ = arg0->unknown_c8_;
            *(volatile unsigned int*)0x04001010 = (arg0->unknown_c6_ << 16) & 0x1ff0000;
            arg0->unknown_1_ = 0;
            arg0->unknown_2_ = -1;
            VectorizedMemset(arg0->unknown_4_, 0, 0x40);
            VectorizedMemset(arg0->unknown_44_, 0, 0x80);
            arg0->unknown_ed_ = 2;
            arg0->unknown_ef_ = 0;
        }
    }
}
#endif
