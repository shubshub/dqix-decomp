#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

struct Struct_0201099c_10;

struct Struct_ov023_021e5974_2
{
    int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 8;
    unsigned int unknown_6_4_ : 12;
};

struct Struct_02015ef4_4
{
    PartModel_021e5974* model_;
    int unk_4;
    int unk_8;
    int unk_c;
    unsigned int unk_10_0 : 20;
    unsigned int letter_ : 8;
    unsigned int unk_10_28 : 4;
    short unk_14;
    short unk_16;
    short itemId_;
};

struct Struct_ov023_021e5974_3
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char skinColor_ : 3;
    unsigned char eyeColor_ : 4;
    unsigned char hairColor_ : 4;
    unsigned char unk_15_4 : 4;
    short unk_16;
    short width_;
    short height_;
};

struct Struct_ov023_021e5974_4
{
    char pad0[0x488];
    PartyMemberAppearance_021e5974 appearance_;
    char pad4a4[0x568 - 0x4a4];
    short vocation_;
    unsigned char bareBodyColor;
};

struct Struct_02000c9c_72
{
    char unknown_0_[0x70];
};

struct Struct_ov023_021e5974
{
    Object3D unknown_0_[10];
    SafeAllocator unknown_6b8_[10];
    SafeAllocator unknown_780_;
    Struct_02000c9c_72 unknown_794_[10];
    short unknown_bf4_[12];
    struct Struct_0201099c_10* unknown_c0c_;
    unsigned char unknown_c10_;
    unsigned char unknown_c11_;
    unsigned char unknown_c12_;
    unsigned char unknown_c13_;
    unsigned char unknown_c14_;
    unsigned char unknown_c15_;
    char unknown_c16_[2];
    Struct_ov023_021e5974_4* unknown_c18_;
    short unknown_c1c_;
    unsigned char unknown_c1e_;
    char unknown_c1f_;
};

struct Struct_ov023_021fd678
{
    char unknown_0_[8];
};

extern "C" int func_020100a8(GameState* arg0);
extern "C" void func_ov023_021e5fdc(void* arg0, short* arg1, short* arg2);
extern "C" Struct_02015ef4_4* func_020dedd0(struct Struct_0201099c_10* arg0, int arg1);
extern "C" unsigned short func_020de234(Struct_02015ef4_4* arg0, int arg1);
extern "C" void func_ov023_021e61a0(Struct_ov023_021e5974* arg0);

extern const int data_ov023_021fd698[5];
extern const Struct_ov023_021fd678 data_ov023_021fd678;
extern const char data_ov023_021fdd16[];
extern const char data_ov023_021fd680[10];
extern const char data_ov023_021fdd1c[];
extern const char data_ov023_021fdd2a[];
extern const char data_ov023_021fdd45[];
extern const char data_ov023_021fdd58[];

// The item a part shows when nothing is equipped there (CopyAndClampShorts_021e5fdc's default body); its file
// number takes the member's bareBodyColor.
enum { BareBodyItem = 1000 };

// Overlay 23, originally func_ov023_021e5974 (USA/EUR 0x021e5974, JPN 0x021e5b58)
extern "C" ARM void CharacterModel_Load(CharacterModel_021e5974* self, PartyMemberData_021e5974* member,
                                        int vocation, int unused, int force)
{
    char var0[0x80];
    char var1[0x80];
    short var2[10];
    short var3;

    if (arg1 == NULL)
        return;

    arg0->unknown_c18_ = arg1;
    func_ov023_021e61a0(arg0);
    GameState* var4 = GameState::GetInstance();
    BackgroundLoader* var5 = BackgroundLoader::GetInstance();
    Struct_ov023_021e5974_3* var6 = &arg1->unknown_488_;
    if (arg2 < 0)
        arg2 = arg1->unknown_568_;
    if (arg2 < 0)
        arg2 = func_020100a8(var4);
    arg0->unknown_c15_ = arg2;
    func_ov023_021e5fdc((void*)arg2, var2, var6->unknown_0_);
    arg0->unknown_0_[3].unknown_2_ = -1;
    arg0->unknown_0_[4].unknown_2_ = -1;
    func_020dedd0(arg0->unknown_c0c_, var2[7]);
    Struct_02015ef4_4* var7[10] = {0};
    var7[0] = func_020dedd0(arg0->unknown_c0c_, var2[0]);
    var7[7] = func_020dedd0(arg0->unknown_c0c_, var2[7]);
    arg0->unknown_c1c_ = arg0->unknown_0_[0].rotation_.y;

    arg0->unknown_c13_ = 0;
    for (int var8 = 0; var8 < 5; var8++)
    {
        int var9 = data_ov023_021fd698[var8];
        if (var2[var9] != (var3 = arg0->unknown_0_[var9].unknown_2_) || arg4 != 0)
        {
            arg0->unknown_c13_ = 1;
            arg0->unknown_0_[0].unknown_2_ = -1;
            arg0->unknown_0_[6].unknown_2_ = -1;
            arg0->unknown_0_[5].unknown_2_ = -1;
            arg0->unknown_0_[1].unknown_2_ = -1;
            break;
        }
    }

    for (int var10 = 0; var10 < 10; var10++)
    {
        if (var2[var10] < 0)
        {
            arg0->unknown_0_[var10].Destroy();
            arg0->unknown_0_[var10].unknown_2_ = -1;
            if (var10 == 0)
                var2[5] = -1;
            continue;
        }
        Struct_02015ef4_4* var11 = func_020dedd0(arg0->unknown_c0c_, var2[var10]);
        if (var11 == NULL)
        {
            arg0->unknown_0_[var10].Initialize();
            arg0->unknown_0_[var10].unknown_2_ = var2[var10];
            continue;
        }
        arg0->unknown_0_[var10].Destroy();
        arg0->unknown_6b8_[var10].Reset();
        bool var12;
        if (arg1 == NULL)
        {
            var12 = false;
        }
        else
        {
            int var13;
            Struct_02015ef4_4* var14 = var7[0];
            Struct_02015ef4_4* var15 = var7[7];
            int var16 = arg1->unknown_488_.unknown_14_0_;
            var13 = func_020de234(var11, var16);
            Struct_ov023_021fd678 var17 = data_ov023_021fd678;
            char var18[2] = {0};

            if (var10 == 4)
            {
                strcpy(var17.unknown_0_, data_ov023_021fdd16);
                var18[0] = 'a';
                var18[1] = 0;
                var13 += var6->unknown_15_0_;
            }
            if (var10 == 3)
            {
                prefix[0] = 'a';
                prefix[1] = 0;
                if (weapon != NULL && weapon->itemId_ > -1)
                {
                    unsigned int var19 = (unsigned int)func_020de234(var15, var16) / 100;
                    if (var19 < 10)
                    {
                        char var20 = data_ov023_021fd680[var19];
                        if (var20 == 0)
                        {
                            var12 = false;
                            goto queue;
                        }
                        var18[0] = var20;
                        if (var19 == 3 && var16 == 0 && var6->unknown_0_[3] == 0x2329)
                            var18[0] = 'f';
                    }
                    else
                    {
                        var12 = false;
                        goto queue;
                    }
                }
            }
            if (var10 == 5)
            {
                var3 = var6->unknown_0_[4];
                if (var3 == 0x1f4a || var3 < 0)
                    var13 = func_020de234(var14, var16);
            }
            if (entry->itemId_ == BareBodyItem)
                id += member->bareBodyColor;
            sprintf(path, data_ov023_021fdd1c, (char)entry->letter_, id, prefix, ext.name_);
            ok = true;
        }
    queue:
        if (var12)
        {
            arg0->unknown_bf4_[var10] = var5->QueueLoadFileInGP2(data_ov023_021fdd2a, var0, NULL);
            arg0->unknown_0_[var10].unknown_2_ = var2[var10];
        }
    }

    arg0->unknown_c13_ = 1;
    if (arg0->unknown_c13_)
    {
        Struct_02015ef4_4* var21 = func_020dedd0(arg0->unknown_c0c_, var2[0]);
        Struct_02015ef4_4* var22 = func_020dedd0(arg0->unknown_c0c_, var2[8]);
        unsigned char var23 = 0;
        if (var22 != NULL)
            var23 = var22->unknown_0_->unknown_5_4_;
        if (var21 != NULL)
        {
            int var24 = 'm';
            if (var6->unknown_14_0_ == 1)
                var24 = 'w';
            sprintf(var1, data_ov023_021fdd45, var21->unknown_0_->unknown_5_4_, var23, var24);
            arg0->unknown_bf4_[10] = var5->QueueLoadFileInGP2(data_ov023_021fdd2a, var1, NULL);
            sprintf(var1, data_ov023_021fdd58, var21->unknown_0_->unknown_5_4_, var23, var24);
            arg0->unknown_bf4_[11] = var5->QueueLoadFileInGP2(data_ov023_021fdd2a, var1, NULL);
            if (arg0->unknown_0_[0].pModel_ != NULL)
                arg0->unknown_0_[0].pModel_->RemoveAnimations();
            arg0->unknown_0_[0].RemoveAllAnimationPackages();
            arg0->unknown_780_.Reset();
        }
    }
    arg0->unknown_c12_ = 1;
    arg0->unknown_c1e_ = 0;
}
