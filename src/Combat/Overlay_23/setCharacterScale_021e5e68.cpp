#include <globaldefs.h>
#include <World/Object3D.h>

static inline fix32_t inline_ov023_021e5e68(fix32_t arg0, fix32_t arg1)
{
    return (fix32_t)(((int64_t)arg0 * arg1 + 0x800) >> 12);
}

enum
{
    Enum_ov023_021e5e68_0,
    Enum_ov023_021e5e68_1,
    Enum_ov023_021e5e68_2,
    Enum_ov023_021e5e68_3,
    Enum_ov023_021e5e68_4,
    Enum_ov023_021e5e68_5,
    Enum_ov023_021e5e68_6,
    Enum_ov023_021e5e68_7,
    Enum_ov023_021e5e68_8,
    Enum_ov023_021e5e68_9
};

struct Struct_ov023_021e5e68
{
    Object3D unknown_0_[10];
};

// Overlay 23, originally func_ov023_021e5e68 (USA/EUR 0x021e5e68, JPN 0x021e604c)
extern "C" ARM void setCharacterScale(CharacterModel_021e5e68* self, int width, int height)
{
    fix32_t var0 = inline_ov023_021e5e68(arg2, arg1);
    arg0->unknown_0_[Enum_ov023_021e5e68_0].SetScale(var0, arg2, var0);
    arg0->unknown_0_[Enum_ov023_021e5e68_6].SetScale(var0, arg2, var0);
    arg0->unknown_0_[Enum_ov023_021e5e68_1].SetScale(var0, arg2, var0);
    arg0->unknown_0_[Enum_ov023_021e5e68_5].SetScale(var0, arg2, var0);

    short var1 = fix32_Divide(0x1000, var0);
    short var2 = fix32_Divide(0x1000, arg2);
    arg0->unknown_0_[Enum_ov023_021e5e68_8].SetScale(var1, var2, var1);
    arg0->unknown_0_[Enum_ov023_021e5e68_9].SetScale(var1, var2, var1);

    short var3 = inline_ov023_021e5e68(var1, 0x1000);
    short var4 = inline_ov023_021e5e68(var2, 0x1000);
    short var5 = inline_ov023_021e5e68(0x1000, var1);
    arg0->unknown_0_[Enum_ov023_021e5e68_2].SetScale(var3, var4, var5);
    arg0->unknown_0_[Enum_ov023_021e5e68_3].SetScale(var3, var4, var5);
    arg0->unknown_0_[Enum_ov023_021e5e68_7].SetScale(var3, var4, var5);
}
