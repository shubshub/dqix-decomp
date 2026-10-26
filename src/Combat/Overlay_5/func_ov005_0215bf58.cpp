#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov005_0215bf58_1276 = 0x4f8 };
enum { Enum_ov005_0215bf58_6584 = 0x1930, Enum_ov005_0215bf58_11664 = 0x2d08, Enum_ov005_0215bf58_15803 = 0x3d33 };
#else
enum { Enum_ov005_0215bf58_1276 = 0x4fc };
enum { Enum_ov005_0215bf58_6584 = 0x19b8, Enum_ov005_0215bf58_11664 = 0x2d90, Enum_ov005_0215bf58_15803 = 0x3dbb };
#endif

struct MemberScreen
{
    char unk_0[Enum_ov005_0215bf58_1276];
    int member_;
};

struct ItemTable;
struct Element020de650;

struct Struct_ov005_02153ba4
{
    short item_;
    char unk_2[0x1c - 2];
};

struct EquipmentMenu
{
    char unk_0[0xdf4];
    ItemTable* items_;
    char unknown_df8_[Enum_ov005_0215bf58_6584 - 0xdf8];
    unsigned short unknown_19b8_;
    char unknown_19ba_[Enum_ov005_0215bf58_11664 - Enum_ov005_0215bf58_6584 - 2];
    Struct_ov005_02153ba4 slots_[24];
    char unknown_3030_[Enum_ov005_0215bf58_15803 - Enum_ov005_0215bf58_11664 - 24 * sizeof(Struct_ov005_02153ba4)];
    signed char slot_;
};

extern "C" void func_ov005_021562b8(EquipmentMenu* self);
extern "C" void func_ov005_0215730c(EquipmentMenu* self);
extern "C" MemberScreen* func_ov017_021a193c(int* obj);
extern "C" Element020de650* ItemTable_Find(ItemTable* c, int key);
extern "C" int func_020dd4c4(signed char member, Element020de650* entry);
extern "C" void func_ov005_021551fc(char*, int, int);

// USA: func_ov005_0215bf58
extern "C" ARM void func_ov005_0215bf58(EquipmentMenu* self)
{
    int var0 = 0;
    if (g_touchInput.pressed_ || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
        g_touchInput.released_ != 0)
    {
        func_ov005_021562b8(self);
        var0 = 1;
    }
    if (!var0)
        func_ov005_0215730c(self);
    int member = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->member_;
    Element020de650* entry = ItemTable_Find(self->items_, self->slots_[self->slot_].item_);
    if (entry != NULL)
    {
        if (func_020dd4c4(member, entry))
            self->unknown_19b8_ |= 0x100;
        else
            self->unknown_19b8_ &= ~0x100;
    }
    func_ov005_021551fc((char*)self, member, 0);
}
