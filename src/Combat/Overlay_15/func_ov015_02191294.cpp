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
struct IndexList_0202a9ac;

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x38];
    short motion_;
    unsigned char unknown_3a_;
    char unknown_3b_[0x44 - 0x3b];
    int unknown_44_;
    int battle_;
    int step_;
};

struct Struct_ov015_02190e88
{
    Struct_ov015_0218c03c_2* object_;
    Struct_ov015_02190e88* unknown_4_;
};

struct DebugMenu
{
    char unk_0[0x5c];
    short unknown_5c_;
    short unknown_5e_;
    short cursor_;
    char unknown_62_[0x80 - 0x62];
};

struct Struct_ov015_02190acc
{
    char unk_0[0x2c];
    Struct_ov015_02190e88* objects_;
    Struct_ov015_0218c03c_2* current_;
    char unknown_34_[0x194 - 0x34];
    int menu_;
    char unknown_198_[0x19f - 0x198];
    unsigned char unknown_19f_;
    char unknown_1a0_[0x2bc - 0x1a0];
    int unknown_2bc_;
    int repeatTimer_;
    DebugMenu menuList_;
    char unknown_344_[0x350 - 0x344];
    unsigned char unknown_350_;
};

extern "C" int func_ov015_021925a8(Struct_ov015_02190acc* self);
extern "C" void func_ov015_0219011c(Struct_ov015_0219011c* object, int step);
extern "C" int func_ov015_02191284(DebugMenu* menu);
extern "C" void* DebugMenu_GetItem(IndexList_0202a9ac* menu, int index);
extern "C" const char* func_02029560(void* item);
extern "C" void func_ov015_0218f364(Struct_ov015_0218c03c_2* object, const char* name);
extern "C" void func_ov015_021900dc(Struct_ov015_021900dc* object);
extern "C" void func_ov015_02192700(Struct_ov015_02190acc* self, int unk);
extern "C" void func_ov015_0219015c(Struct_ov015_0219015c_2* object, int step);

// USA: func_ov015_02191294
extern "C" ARM void func_ov015_02191294(Struct_ov015_02190acc* self)
{
    if (func_ov015_021925a8(self))
        return;
    if (g_keyManager.TestKeysReleased(0x20) || g_keyManager.TestKeysReleased(0x10) ||
        g_keyManager.TestKeysReleased(0x100))
    {
        self->unknown_2bc_ = 0x1e;
        self->repeatTimer_ = 0;
    }
    if (g_keyManager.TestKeysPressed(1))
    {
        if (g_keyManager.TestKeysHeld(0x100))
        {
            Struct_ov015_0218c03c_2* current = self->current_;
            current->unknown_3a_ = current->unknown_3a_ == 0;
            self->unknown_350_ = 1;
            return;
        }
        if (g_keyManager.TestKeysHeld(0x200))
        {
            Struct_ov015_0218c03c_2* current = self->current_;
            int var2 = current->unknown_44_;
            if (self->unknown_19f_)
            {
                for (Struct_ov015_02190e88* node = self->objects_; node != NULL; node = node->unknown_4_)
                {
                    if (var2 == 0)
                        node->object_->unknown_44_ = 1;
                    else
                        node->object_->unknown_44_ = 0;
                }
            }
            else if (var2 == 0)
            {
                current->unknown_44_ = 1;
            }
            else
            {
                current->unknown_44_ = 0;
            }
        }
        func_ov015_0219011c((Struct_ov015_0219011c*)self->current_, self->current_->step_);
        self->current_->motion_ = func_ov015_02191284(&self->menuList_);
        void* item = DebugMenu_GetItem((IndexList_0202a9ac*)&self->menuList_, func_ov015_02191284(&self->menuList_));
        if (item != NULL)
        {
            if (self->unknown_19f_)
            {
                for (Struct_ov015_02190e88* node = self->objects_; node != NULL; node = node->unknown_4_)
                    func_ov015_0218f364(node->object_, func_02029560(item));
            }
            else
            {
                func_ov015_0218f364(self->current_, func_02029560(item));
            }
        }
        func_ov015_021900dc((Struct_ov015_021900dc*)self->current_);
        self->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeysPressed(2))
    {
        func_ov015_0219011c((Struct_ov015_0219011c*)self->current_, self->current_->step_);
        self->current_->unknown_3a_ = 0;
        self->current_->motion_ = -1;
        self->current_->unknown_44_ = 0;
        self->current_->step_ = 0;
        self->menu_ = 0;
        func_ov015_02192700(self, 0);
        return;
    }
    if (g_keyManager.TestKeysPressed(0x100))
    {
        if (self->current_->unknown_3a_)
            self->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeyRepeat(0x20))
    {
        if (g_keyManager.TestKeysHeld(0x100))
        {
            func_ov015_0219015c((Struct_ov015_0219015c_2*)self->current_, -0x28);
        }
        else
        {
            short first = self->menuList_.unknown_5c_;
            int cursor = self->menuList_.cursor_ - 8;
            if (cursor < first)
                cursor = first;
            self->menuList_.cursor_ = cursor;
        }
        self->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeyRepeat(0x10))
    {
        if (g_keyManager.TestKeysHeld(0x100))
        {
            func_ov015_0219015c((Struct_ov015_0219015c_2*)self->current_, 0x28);
        }
        else
        {
            short last = self->menuList_.unknown_5e_;
            int cursor = self->menuList_.cursor_ + 8;
            if (cursor > last)
                cursor = last;
            self->menuList_.cursor_ = cursor;
        }
        self->unknown_350_ = 1;
        return;
    }
    if (g_keyManager.TestKeysHeld(0x20))
    {
        if (!g_keyManager.TestKeysHeld(0x100))
            return;
        if (self->repeatTimer_ < self->unknown_2bc_)
        {
            self->repeatTimer_++;
            return;
        }
        self->repeatTimer_ = 0;
        self->unknown_2bc_ -= 10;
        func_ov015_0219015c((Struct_ov015_0219015c_2*)self->current_, -0x28);
        self->unknown_350_ = 1;
        return;
    }
    if (!g_keyManager.TestKeysHeld(0x10))
        return;
    if (!g_keyManager.TestKeysHeld(0x100))
        return;
    if (self->repeatTimer_ < self->unknown_2bc_)
    {
        self->repeatTimer_++;
        return;
    }
    self->repeatTimer_ = 0;
    self->unknown_2bc_ -= 10;
    func_ov015_0219015c((Struct_ov015_0219015c_2*)self->current_, 0x28);
    self->unknown_350_ = 1;
}
