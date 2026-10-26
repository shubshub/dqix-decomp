#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov015_0219011c;
struct Struct_ov015_021900dc;
struct Struct_ov015_0219015c_2;
struct Struct_02029634;

struct Struct_ov015_0218c03c_2
{
    char unknown_0_[0x38];
    short unknown_38_;
    unsigned char unknown_3a_;
    char unknown_3b_[0x44 - 0x3b];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
};

struct Struct_ov015_02190e88
{
    Struct_ov015_0218c03c_2* unknown_0_;
    Struct_ov015_02190e88* unknown_4_;
};

struct Struct_02029988_2
{
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
    short unknown_60_;
    char unknown_62_[0x80 - 0x62];
};

struct Struct_ov015_02190acc
{
    char unknown_0_[0x2c];
    Struct_ov015_02190e88* unknown_2c_;
    Struct_ov015_0218c03c_2* unknown_30_;
    char unknown_34_[0x194 - 0x34];
    int unknown_194_;
    char unknown_198_[0x19f - 0x198];
    unsigned char unknown_19f_;
    char unknown_1a0_[0x2bc - 0x1a0];
    int unknown_2bc_;
    int unknown_2c0_;
    Struct_02029988_2 unknown_2c4_;
    char unknown_344_[0x350 - 0x344];
    unsigned char unknown_350_;
};

extern "C" int func_ov015_021925a8(S02190c2c* self);
void SetField18_0219011c(Obj0219011c* object, int step);
extern "C" int func_ov015_02191284(DebugMenu* menu);
void* DebugMenu_GetItem(IndexList_0202a9ac* menu, int index);
const char* GetSubstructAt0x4_02029560(void* item);
extern "C" void func_ov015_0218f364(ViewObject* object, const char* name);
void UpdateField4c021900dc(Obj021900dc* object);
extern "C" void func_ov015_02192700(S02190c2c* self, int unk);
void AdjustSubstructField_0219015c_0219015c(S0219015c* object, int step);

// USA: func_ov015_02191294
extern "C" ARM void func_ov015_02191294(Struct_ov015_02190acc* arg0)
{
    if (func_ov015_021925a8(arg0))
        return;
    if (g_keyManager.TestKeysReleased(0x20) || g_keyManager.TestKeysReleased(0x10) ||
        g_keyManager.TestKeysReleased(0x100))
    {
        arg0->unknown_2bc_ = 0x1e;
        arg0->unknown_2c0_ = 0;
    }
    if (g_keyManager.TestKeysPressed(1))
    {
        if (g_keyManager.TestKeysHeld(0x100))
        {
            Struct_ov015_0218c03c_2* var0 = arg0->unknown_30_;
            var0->unknown_3a_ = var0->unknown_3a_ == 0;
            arg0->unknown_350_ = 1;
            return;
        }
        if (g_keyManager.TestKeysHeld(0x200))
        {
            Struct_ov015_0218c03c_2* var1 = arg0->unknown_30_;
            int var2 = var1->unknown_44_;
            if (arg0->unknown_19f_)
            {
                for (Struct_ov015_02190e88* var3 = arg0->unknown_2c_; var3 != NULL; var3 = var3->unknown_4_)
                {
                    if (var2 == 0)
                        var3->unknown_0_->unknown_44_ = 1;
                    else
                        var3->unknown_0_->unknown_44_ = 0;
                }
            }
            else if (var2 == 0)
            {
                var1->unknown_44_ = 1;
            }
            else
            {
                var1->unknown_44_ = 0;
            }
        }
        SetField18_0219011c((Obj0219011c*)self->current_, self->current_->step_);
        self->current_->motion_ = func_ov015_02191284(&self->menuList_);
        void* item = DebugMenu_GetItem((IndexList_0202a9ac*)&self->menuList_, func_ov015_02191284(&self->menuList_));
        if (item != NULL)
        {
            if (arg0->unknown_19f_)
            {
                for (Struct_ov015_02190e88* var5 = arg0->unknown_2c_; var5 != NULL; var5 = var5->unknown_4_)
                    func_ov015_0218f364(var5->unknown_0_, func_02029560(var4));
            }
            else
            {
                func_ov015_0218f364(arg0->unknown_30_, func_02029560(var4));
            }
        }
        func_ov015_021900dc((Struct_ov015_021900dc*)arg0->unknown_30_);
        arg0->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeysPressed(2))
    {
        func_ov015_0219011c((Struct_ov015_0219011c*)arg0->unknown_30_, arg0->unknown_30_->unknown_4c_);
        arg0->unknown_30_->unknown_3a_ = 0;
        arg0->unknown_30_->unknown_38_ = -1;
        arg0->unknown_30_->unknown_44_ = 0;
        arg0->unknown_30_->unknown_4c_ = 0;
        arg0->unknown_194_ = 0;
        func_ov015_02192700(arg0, 0);
        return;
    }
    if (g_keyManager.TestKeysPressed(0x100))
    {
        if (arg0->unknown_30_->unknown_3a_)
            arg0->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeyRepeat(0x20))
    {
        if (g_keyManager.TestKeysHeld(0x100))
        {
            func_ov015_0219015c((Struct_ov015_0219015c_2*)arg0->unknown_30_, -0x28);
        }
        else
        {
            short var6 = arg0->unknown_2c4_.unknown_5c_;
            int var7 = arg0->unknown_2c4_.unknown_60_ - 8;
            if (var7 < var6)
                var7 = var6;
            arg0->unknown_2c4_.unknown_60_ = var7;
        }
        arg0->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeyRepeat(0x10))
    {
        if (g_keyManager.TestKeysHeld(0x100))
        {
            func_ov015_0219015c((Struct_ov015_0219015c_2*)arg0->unknown_30_, 0x28);
        }
        else
        {
            short var8 = arg0->unknown_2c4_.unknown_5e_;
            int var9 = arg0->unknown_2c4_.unknown_60_ + 8;
            if (var9 > var8)
                var9 = var8;
            arg0->unknown_2c4_.unknown_60_ = var9;
        }
        arg0->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeysHeld(0x20))
    {
        if (!g_keyManager.TestKeysHeld(0x100))
            return;
        if (arg0->unknown_2c0_ < arg0->unknown_2bc_)
        {
            arg0->unknown_2c0_++;
            return;
        }
        arg0->unknown_2c0_ = 0;
        arg0->unknown_2bc_ -= 10;
        func_ov015_0219015c((Struct_ov015_0219015c_2*)arg0->unknown_30_, -0x28);
        arg0->unknown_350_ = 1;
        return;
    }
    if (!g_keyManager.TestKeysHeld(0x10))
        return;
    if (!g_keyManager.TestKeysHeld(0x100))
        return;
    if (arg0->unknown_2c0_ < arg0->unknown_2bc_)
    {
        arg0->unknown_2c0_++;
        return;
    }
    arg0->unknown_2c0_ = 0;
    arg0->unknown_2bc_ -= 10;
    func_ov015_0219015c((Struct_ov015_0219015c_2*)arg0->unknown_30_, 0x28);
    arg0->unknown_350_ = 1;
}
