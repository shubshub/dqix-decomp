#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

struct Struct_0203d028;
struct Struct_ov009_02188454;
struct Struct_0201099c_10;

extern "C" void func_0207df50(struct Struct_0203d028* arg0);
extern "C" void func_0207df90(char* arg0);
extern "C" void func_0207dfac(char* arg0);
extern "C" void func_ov023_021e60c4(void* arg0, struct Struct_ov009_02188454* arg1);
extern "C" void func_ov023_021e5fdc(void* arg0, short* arg1, short* arg2);
extern "C" void __clear(void* arg0, unsigned long arg1);

struct Struct_ov023_021e5020_4
{
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_ov023_021e5020_5
{
    char unknown_0_[0x488];
    Struct_ov023_021e5020_4 unknown_488_;
};

struct Struct_ov023_021e5020
{
    void* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 3;
};

extern "C" Struct_ov023_021e5020* func_020dedd0(struct Struct_0201099c_10* arg0, int arg1);

struct Struct_02000c9c_71
{
    char unknown_0_[0x70];
};

struct Struct_ov023_021e5020_2
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov023_021e5020_3
{
    Object3D unknown_0_[10];
    SafeAllocator unknown_6b8_[10];
    SafeAllocator unknown_780_;
    Struct_02000c9c_71 unknown_794_[10];
    short unknown_bf4_[12];
    struct Struct_0201099c_10* unknown_c0c_;
    unsigned char unknown_c10_;
    unsigned char unknown_c11_;
    unsigned char unknown_c12_;
    unsigned char unknown_c13_;
    unsigned char unknown_c14_;
    unsigned char unknown_c15_;
    char unknown_c16_[2];
    Struct_ov023_021e5020_5* unknown_c18_;
    short unknown_c1c_;
    unsigned char unknown_c1e_;
    char unknown_c1f_;
};

extern "C" void func_ov023_021e540c(CharacterModel_021e5020* self);
extern "C" void setCharacterScale(CharacterModel_021e5020* self, int width, int height);

extern "C" const char data_ov023_021fdce0[];
extern "C" const char data_ov023_021fdce9[];

// USA: func_ov023_021e5020
extern "C" ARM void func_ov023_021e5020(Struct_ov023_021e5020_3* arg0)
{
    void* var0;
    unsigned int var1;

    if (arg0->unknown_c12_)
    {
        BackgroundLoader* var2 = BackgroundLoader::GetInstance();
        arg0->unknown_c12_ = 0;
        for (int var3 = 0; var3 < 10; var3++)
        {
            if (arg0->unknown_bf4_[var3] > -1)
            {
                if (var2->GetTaskStatus(arg0->unknown_bf4_[var3]))
                {
                    arg0->unknown_0_[var3].Destroy();
                    arg0->unknown_6b8_[var3].Reset();
                    var2->GetLoadedFileByID(arg0->unknown_bf4_[var3], &var0, &var1);
                    if (var1 != 0)
                    {
                        func_0207df50((Struct_0203d028*)&arg0->unknown_794_[var3]);
                        func_0207df90((char*)&arg0->unknown_794_[var3]);
                        arg0->unknown_0_[var3].SetModelFromFileCopy(&arg0->unknown_6b8_[var3], var0, var1, Model3D::TextureStagingMode_Normal);
                        func_0207dfac((char*)&arg0->unknown_794_[var3]);
                        if (var3 == 4 && arg0->unknown_0_[3].pModel_ != NULL)
                            arg0->unknown_0_[3].pModel_->ApplyTexturesFromModel(arg0->unknown_0_[var3].pModel_);
                    }
                    var2->RemoveTask(arg0->unknown_bf4_[var3]);
                    arg0->unknown_bf4_[var3] = -1;
                }
                else
                {
                    arg0->unknown_c12_ = 1;
                }
            }
        }

        short var4 = arg0->unknown_bf4_[10];
        if (var4 > -1)
        {
            if (var2->GetTaskStatus(var4))
            {
                var2->GetLoadedFileByID(var4, &var0, &var1);
                if (var1 != 0)
                {
                    var2->GetLoadedFileByID(var4, &var0, &var1);
                    if (var1 != 0)
                        arg0->unknown_0_[0].LoadType0AnimationFromFileInMemory(0, &arg0->unknown_780_, var0, var1);
                }
                var2->RemoveTask(var4);
                arg0->unknown_bf4_[10] = -1;
            }
            else
            {
                arg0->unknown_c12_ = 1;
            }
        }

        var4 = arg0->unknown_bf4_[11];
        if (var4 > -1)
        {
            if (var2->GetTaskStatus(var4))
            {
                var2->GetLoadedFileByID(var4, &var0, &var1);
                if (var1 != 0)
                {
                    var2->GetLoadedFileByID(var4, &var0, &var1);
                    if (var1 != 0)
                        arg0->unknown_0_[0].LoadType0AnimationPackageFromBCFGScript(&arg0->unknown_780_, var0, var1);
                }
                var2->RemoveTask(var4);
                arg0->unknown_bf4_[11] = -1;
            }
            else
            {
                arg0->unknown_c12_ = 1;
            }
        }

        if (!arg0->unknown_c12_ && !arg0->unknown_c1e_)
        {
            func_ov023_021e540c(arg0);
            arg0->unknown_c1e_ = 1;
            arg0->unknown_c12_ = 1;
        }

        if (!arg0->unknown_c12_)
        {
            Struct_ov023_021e5020_4* var5 = &arg0->unknown_c18_->unknown_488_;
            if (arg0->unknown_c13_)
            {
                if (var5->unknown_14_0_ == 1 && arg0->unknown_c11_ == 0)
                {
                    if (arg0->unknown_0_[0].unknown_2_ >= 0)
                    {
                        arg0->unknown_0_[0].StopCurrentAnimation();
                        arg0->unknown_0_[0].MaybeSetRegularAnimation(data_ov023_021fdce0, 0);
                    }
                }
                else if (arg0->unknown_0_[0].unknown_2_ >= 0)
                {
                    arg0->unknown_0_[0].StopCurrentAnimation();
                    arg0->unknown_0_[0].MaybeSetRegularAnimation(data_ov023_021fdce9, 0);
                }
                Rotation_021e5020 rotation = {0};
                rotation.y = self->angle_;
                SetWords_021e60c4_021e60c4(&self->parts_[0], (Words021e60c4*)&rotation);
                SetWords_021e60c4_021e60c4(&self->parts_[6], (Words021e60c4*)&rotation);
                SetWords_021e60c4_021e60c4(&self->parts_[1], (Words021e60c4*)&rotation);
                SetWords_021e60c4_021e60c4(&self->parts_[5], (Words021e60c4*)&rotation);
                setCharacterScale(self, appearance->width_, appearance->height_);
            }

            short var7[10];
            func_ov023_021e5fdc((void*)arg0->unknown_c15_, var7, (short*)var5);
            Struct_ov023_021e5020* var8 = func_020dedd0(arg0->unknown_c0c_, var7[8]);
            if (var8 != NULL && var8->unknown_8_4_ == 6)
                arg0->unknown_c10_ = 1;
            else
                arg0->unknown_c10_ = 0;
        }
    }
}
