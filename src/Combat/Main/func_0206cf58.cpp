#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"


struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct Struct_0205faf4_13;
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" int func_0206e260(PackedNibbleArray0206e260*, int);
extern "C" int func_0206e2dc(Struct_0205faf4_13*, int);
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
static inline int inline_0206cf58(PackedNibbleArray0206e120* table, int slot, int value)
{
    return func_0206e120(table, slot) == value;
}
struct Struct_02108cec_5
{
    unsigned char day;
    unsigned char month;
    unsigned char year;
    char pad3;
    short slot;
    short id;
    short state;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    char unknown_e_[2];
    void* receiver;
    SafeAllocator* allocator;
};
extern Struct_02108cec_5 data_02108cec;

// USA: func_0206cf58
extern "C" ARM int func_0206cf58(Script::Parameter* params, int count)
{
    PackedNibbleArray0206e120* table;
    Struct_0206bf2c* record;
    data_02108cec.unknown_a_++;
    int slot = params[0].ToInt();
    int mode = params[1].ToInt();
    int var4 = params[2].ToInt();
    int var5 = params[3].ToInt();
    int var6 = params[4].ToInt();
    int var7 = params[5].ToInt();
    int var8 = params[6].ToInt();
    int var9 = params[7].ToInt();
    int var10 = params[8].ToInt();
    int var11 = params[9].ToInt();
    int id = params[10].ToInt();
    if (data_02108cec.id != id)
    {
        data_02108cec.id = id;
        data_02108cec.state = -1;
        data_02108cec.slot = -1;
    }
    table = Scenario_GetInstance();
    if (data_02108cec.slot != slot && data_02108cec.slot > -1)
    {
        if (inline_0206cf58(table, slot, 1) || inline_0206cf58(table, slot, 2))
        {
        }
        else if (inline_0206cf58(table, data_02108cec.slot, 3) && inline_0206cf58(table, slot, 3))
        {
            if (data_02108cec.slot > slot)
                return 1;
        }
    }
    switch (mode)
    {
    case -1:
        if (!inline_0206cf58(table, slot, 0)) return 1;
        break;
    case 3:
        if (!inline_0206cf58(table, slot, 1)) return 1;
        break;
    case 0:
        if (!inline_0206cf58(table, slot, 2)) return 1;
        break;
    case 1:
        if (!func_0206e260((PackedNibbleArray0206e260*)table, slot)) return 1;
        break;
    case 2:
        if (!inline_0206cf58(table, slot, 3)) return 1;
        break;
    case 4:
        if (func_0206e2dc((Struct_0205faf4_13*)table, slot) && inline_0206cf58(table, slot, 0))
        {
        }
        else return 1;
        break;
    }
    int var13 = var9 + (var7 * 1000 + var8 * 10);
    int date = data_02108cec.day + (data_02108cec.year * 1000 + (short)data_02108cec.month * (short)10);
    int var15 = var6 + (var4 * 1000 + var5 * 10);
    if (date < var15 || var13 < date)
        return 1;
    GameState* game = GameState::GetInstance();
    if (var10 == 1)
    {
        if (game->IsMorningDayOrEvening())
            return 1;
    }
    else if (var10 == 0)
    {
        if (!game->IsMorningDayOrEvening())
            return 1;
    }
    if (var11 != data_02108cec.unknown_c_)
    {
        func_0206dd68(data_02108cec.receiver, id);
        return 1;
    }
    record = (Struct_0206bf2c*)data_02108cec.allocator->Allocate(0x78);
    if (record == NULL)
        return 0;
    func_0206bf2c(record);
    record->unknown_46_ = slot;
    record->field4 = var4;
    record->field5 = var5;
    record->field6 = var6;
    record->unknown_7_ = var7;
    record->field8 = var8;
    record->unknown_9_ = var9;
    record->unknown_a_0_ = (unsigned char)var10;
    record->field2 = var11;
    record->field0 = id;
    if (data_02108cec.id != id)
        data_02108cec.id = id;
    if (count < 12)
    {
        func_0206dd68(data_02108cec.receiver, id);
        data_02108cec.slot = slot;
        return 1;
    }
    Script::Parameter* next = params[11].ToVec3fix((Vector3fix*)record->vec);
    record->field1c = (int)(4096.0f * next->ToFloat());
    if (count > 15)
        record->unknown_1e_ = next[1].ToInt();
    record->field44 = data_02108cec.unknown_a_;
    record->unknown_a_6_ = 1;
    func_0206db48(data_02108cec.receiver, record);
    data_02108cec.slot = slot;
    return 1;
}
