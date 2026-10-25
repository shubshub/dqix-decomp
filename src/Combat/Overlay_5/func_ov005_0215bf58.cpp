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

struct Struct_ov005_02153ba4_2
{
    char unknown_0_[Enum_ov005_0215bf58_1276];
    int unknown_4fc_;
};

struct ItemTable;
struct Element020de650;

struct Struct_ov005_02153ba4
{
    short unknown_0_;
    char unknown_2_[0x1c - 2];
};

struct Struct_ov005_02153954
{
    char unk_0[0xdf4];
    ItemTable* items_;
    char unk_df8[kInfoFlags - 0xdf8];
    unsigned short infoFlags_;
    char unk_19ba[kSlots - kInfoFlags - 2];
    EquipmentSlot slots_[24];
    char unk_3030[kSelectedSlot - kSlots - 24 * sizeof(EquipmentSlot)];
    signed char slot_;
};

extern "C" void func_ov005_021562b8(EquipmentMenu* self);
extern "C" void func_ov005_0215730c(EquipmentMenu* self);
MemberScreen* GetField1c_021a193c(int* obj);
Element020de650* ItemTable_Find(ItemTable* c, int key);
extern "C" int func_020dd4c4(signed char member, Element020de650* entry);
void DispatchByIdxAndCond021551fc(char*, int, int);

// USA: func_ov005_0215bf58
extern "C" ARM void func_ov005_0215bf58(Struct_ov005_02153954* arg0)
{
    int var0 = 0;
    if (g_touchInput.pressed_ || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
        g_touchInput.released_ != 0)
    {
        func_ov005_021562b8(arg0);
        var0 = 1;
    }
    if (!touchHandled)
        func_ov005_0215730c(self);
    int member = GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->member_;
    Element020de650* entry = ItemTable_Find(self->items_, self->slots_[self->slot_].item_);
    if (entry != NULL)
    {
        if (func_020dd4c4(var1, var2))
            arg0->unknown_19b8_ |= 0x100;
        else
            arg0->unknown_19b8_ &= ~0x100;
    }
    func_ov005_021551fc((char*)arg0, var1, 0);
}
