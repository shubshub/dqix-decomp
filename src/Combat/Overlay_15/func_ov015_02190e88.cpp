#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct AllocatorUnion;
struct Struct_ov015_02190d7c;
struct Struct_ov015_02190d7c_2;
struct Struct_ov015_021900dc;

struct Struct_ov015_0218b828_3
{
    char* name_;
    char* file_;
    unsigned short id_;
    unsigned char page_;
    unsigned char unknown_b_;
};

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x1c];
    unsigned char kind_;
    char unknown_1d_[0x38 - 0x1d];
    short motion_;
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
    char unknown_198_[0x1a1 - 0x198];
    unsigned char unknown_1a1_;
    char unknown_1a2_[2];
    int page_;
    char unknown_1a8_[0x268 - 0x1a8];
    short unknown_268_[0x29];
    char unknown_2ba_[0x2c4 - 0x2ba];
    DebugMenu menuList_;
    char unknown_344_[0x350 - 0x344];
    unsigned char unknown_350_;
};

extern "C" int func_ov015_021925a8(Struct_ov015_02190acc* self);
extern "C" int func_ov015_02191284(DebugMenu* menu);
extern "C" void func_ov015_02191af0(Struct_ov015_02190acc* self, int index);
extern "C" void func_ov015_02191ba0(Struct_ov015_02190acc* self, int index);
extern "C" void func_ov015_02191c70(Struct_ov015_02190acc* self, int index);
extern "C" Struct_ov015_0218b828_3* func_ov015_02193160(Struct_ov015_02190acc* self, int page, int* index);
extern "C" void func_ov015_021931b4(Struct_ov015_02190d7c* self, int page);
extern "C" int func_ov015_021931cc(Struct_ov015_02190d7c_2* self);
extern "C" void func_ov015_02192700(Struct_ov015_02190acc* self, int unk);
extern "C" int func_ov015_02190c2c(Struct_ov015_02190acc* self);
extern "C" void func_ov015_02192158(Struct_ov015_02190acc* self, int index);
extern "C" void func_ov015_0218f308(Struct_ov015_0218c03c_2* object, const char* event);
extern "C" void func_ov015_021900dc(Struct_ov015_021900dc* object);
extern "C" void func_ov015_0218f0c4(Struct_ov015_0218c03c_2* object);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" Struct_ov015_0218c03c_2* func_ov015_021919e4(Struct_ov015_02190acc* self, Struct_ov015_0218b828_3* entry);
extern "C" void func_ov015_02192544(Struct_ov015_02190acc* self);
extern "C" void func_ov015_02190090(Struct_ov015_0218c03c_2* object);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_02190e88
extern "C" ARM void func_ov015_02190e88(Struct_ov015_02190acc* self)
{
    if (func_ov015_021925a8(self))
        return;
    if (g_keyManager.TestKeysPressed(1))
    {
        int index = func_ov015_02191284(&self->menuList_);
        self->unknown_268_[self->page_] = index;
        switch (self->page_)
        {
        case 2:
            func_ov015_02191af0(self, index);
            return;
        case 3:
            func_ov015_02191ba0(self, index);
            return;
        case 40:
            func_ov015_02191c70(self, index);
            return;
        default:
        {
            int start = 0;
            func_ov015_02193160(self, self->page_, &start);
            index += start;
            Struct_ov015_0218b828_3* entry = func_ov015_02193160(self, self->page_, &index);
            if (entry == NULL)
                break;
            if (entry->unknown_b_ != 0)
            {
                func_ov015_021931b4((Struct_ov015_02190d7c*)self, self->page_);
                self->page_ = entry->unknown_b_;
                func_ov015_02192700(self, 0);
                return;
            }
            if (func_ov015_02190c2c(self))
            {
                func_ov015_02192158(self, index);
                return;
            }
            if (self->page_ == 0x21)
            {
                func_ov015_0218f308(self->current_, entry->file_);
                self->menu_ = 1;
                func_ov015_02192700(self, 0);
                self->current_->motion_ = 0;
                func_ov015_021900dc((Struct_ov015_021900dc*)self->current_);
                return;
            }
            if (g_keyManager.TestKeysHeld(0x100))
            {
                Struct_ov015_02190e88* node = self->objects_;
                while (node != NULL)
                {
                    func_ov015_0218f0c4(node->object_);
                    AllocatorUnion_Free(&g_mainAllocator, node->object_);
                    Struct_ov015_02190e88* next = node;
                    node = node->unknown_4_;
                    AllocatorUnion_Free(&g_mainAllocator, next);
                }
                self->objects_ = NULL;
            }
            Struct_ov015_0218c03c_2* object = func_ov015_021919e4(self, entry);
            if (object != NULL && !g_keyManager.TestKeysHeld(0x200))
            {
                self->current_ = object;
                switch (object->kind_)
                {
                case 0:
                case 1:
                    func_ov015_021931b4((Struct_ov015_02190d7c*)self, self->page_);
                    self->page_ = 0x22;
                    func_ov015_02192700(self, 0);
                    return;
                case 2:
                    func_ov015_021931b4((Struct_ov015_02190d7c*)self, self->page_);
                    self->page_ = 0x21;
                    func_ov015_02192700(self, 0);
                    return;
                default:
                    self->menu_ = 1;
                    func_ov015_02192700(self, 0);
                    self->current_->motion_ = 0;
                    func_ov015_021900dc((Struct_ov015_021900dc*)self->current_);
                    return;
                }
            }
            break;
        }
        }
    }
    else if (g_keyManager.TestKeysPressed(2))
    {
        if (self->page_ > 0)
        {
            self->unknown_268_[self->page_] = func_ov015_02191284(&self->menuList_);
            if (self->page_ == 8)
                func_ov015_02192544(self);
            int page = func_ov015_021931cc((Struct_ov015_02190d7c_2*)self);
            if (page >= 0)
            {
                self->page_ = page;
                func_ov015_02192700(self, 0);
            }
        }
    }
    else
    {
        if (g_keyManager.TestKeyRepeat(0x20))
        {
            short first = self->menuList_.unknown_5c_;
            int cursor = self->menuList_.cursor_ - 8;
            if (cursor < first)
                cursor = first;
            self->menuList_.cursor_ = cursor;
            self->unknown_350_ = 1;
            return;
        }
        if (g_keyManager.TestKeyRepeat(0x10))
        {
            short last = self->menuList_.unknown_5e_;
            int cursor = self->menuList_.cursor_ + 8;
            if (cursor > last)
                cursor = last;
            self->menuList_.cursor_ = cursor;
            self->unknown_350_ = 1;
            return;
        }
        if (g_keyManager.TestKeysPressed(0x200))
        {
            if (self->page_ == 6)
            {
                self->unknown_1a1_ = self->unknown_1a1_ == 0;
                self->unknown_350_ = 1;
            }
        }
        else if (g_keyManager.TestKeysPressed(0x100) && (self->page_ == 0x22 || func_ov015_02190c2c(self)))
        {
            func_ov015_02190090(self->current_);
            self->unknown_350_ = 1;
        }
    }
}
