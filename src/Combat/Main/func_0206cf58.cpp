#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"


struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct PackedNibbleArray0206e2dc;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
static inline int NibbleIs0206cf58(PackedNibbleArray0206e120* table, int slot, int value)
{
    return func_0206e120(arg0, arg1) == arg2;
}
struct Struct_02108cec_5
{
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    char unknown_3_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    char unknown_e_[2];
    void* unknown_10_;
    SafeAllocator* unknown_14_;
};
extern Struct_02108cec_5 data_02108cec;

// USA: func_0206cf58
extern "C" ARM int func_0206cf58(Script::Parameter* arg0, int arg1)
{
    Struct_0205faf4_3* var0;
    Struct_0206bf2c* var1;
    data_02108cec.unknown_a_++;
    int var2 = arg0[0].ToInt();
    int var3 = arg0[1].ToInt();
    int var4 = arg0[2].ToInt();
    int var5 = arg0[3].ToInt();
    int var6 = arg0[4].ToInt();
    int var7 = arg0[5].ToInt();
    int var8 = arg0[6].ToInt();
    int var9 = arg0[7].ToInt();
    int var10 = arg0[8].ToInt();
    int var11 = arg0[9].ToInt();
    int var12 = arg0[10].ToInt();
    if (data_02108cec.unknown_6_ != var12)
    {
        data_02108cec.unknown_6_ = var12;
        data_02108cec.unknown_8_ = -1;
        data_02108cec.unknown_4_ = -1;
    }
    table = Scenario_GetInstance();
    if (data_02108cec.slot != slot && data_02108cec.slot > -1)
    {
        if (inline_0206cf58(var0, var2, 1) || inline_0206cf58(var0, var2, 2))
        {
        }
        else if (inline_0206cf58(var0, data_02108cec.unknown_4_, 3) && inline_0206cf58(var0, var2, 3))
        {
            if (data_02108cec.unknown_4_ > var2)
                return 1;
        }
    }
    switch (var3)
    {
    case -1:
        if (!inline_0206cf58(var0, var2, 0)) return 1;
        break;
    case 3:
        if (!inline_0206cf58(var0, var2, 1)) return 1;
        break;
    case 0:
        if (!inline_0206cf58(var0, var2, 2)) return 1;
        break;
    case 1:
        if (!func_0206e260((Struct_0205faf4_4*)var0, var2)) return 1;
        break;
    case 2:
        if (!inline_0206cf58(var0, var2, 3)) return 1;
        break;
    case 4:
        if (func_0206e2dc((Struct_0205faf4_13*)var0, var2) && inline_0206cf58(var0, var2, 0))
        {
        }
        else return 1;
        break;
    }
    int var13 = var9 + (var7 * 1000 + var8 * 10);
    int var14 = data_02108cec.unknown_0_ + (data_02108cec.unknown_2_ * 1000 + (short)data_02108cec.unknown_1_ * (short)10);
    int var15 = var6 + (var4 * 1000 + var5 * 10);
    if (var14 < var15 || var13 < var14)
        return 1;
    GameState* var16 = GameState::GetInstance();
    if (var10 == 1)
    {
        if (var16->IsMorningDayOrEvening())
            return 1;
    }
    else if (var10 == 0)
    {
        if (!var16->IsMorningDayOrEvening())
            return 1;
    }
    if (var11 != data_02108cec.unknown_c_)
    {
        func_0206dd68(data_02108cec.unknown_10_, var12);
        return 1;
    }
    var1 = (Struct_0206bf2c*)data_02108cec.unknown_14_->Allocate(0x78);
    if (var1 == NULL)
        return 0;
    func_0206bf2c(var1);
    var1->unknown_46_ = var2;
    var1->unknown_4_ = var4;
    var1->unknown_5_ = var5;
    var1->unknown_6_ = var6;
    var1->unknown_7_ = var7;
    var1->unknown_8_ = var8;
    var1->unknown_9_ = var9;
    var1->unknown_a_0_ = (unsigned char)var10;
    var1->unknown_2_ = var11;
    var1->unknown_0_ = var12;
    if (data_02108cec.unknown_6_ != var12)
        data_02108cec.unknown_6_ = var12;
    if (arg1 < 12)
    {
        func_0206dd68(data_02108cec.unknown_10_, var12);
        data_02108cec.unknown_4_ = var2;
        return 1;
    }
    Script::Parameter* var17 = arg0[11].ToVec3fix((Vector3fix*)var1->unknown1_10_);
    var1->unknown_1c_ = (int)(4096.0f * var17->ToFloat());
    if (arg1 > 15)
        var1->unknown_1e_ = var17[1].ToInt();
    var1->unknown_44_ = data_02108cec.unknown_a_;
    var1->unknown_a_6_ = 1;
    func_0206db48(data_02108cec.unknown_10_, var1);
    data_02108cec.unknown_4_ = var2;
    return 1;
}
