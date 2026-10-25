#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Combat/WorkRecord.h"


struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct PackedNibbleArray0206e2dc;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
void UnlinkNodeByByteId0206dd68(void*, int);
struct Data02108cec {
    int field0;
    short wait;
    short group;
    short previous;
    unsigned short serial;
    unsigned short level;
    unsigned short field_e;
    void* list;
    SafeAllocator* allocator;
};
extern Struct_02108cec data_02108cec;
static inline int inline_0206cbcc(Struct_0205faf4_3* arg0, int arg1, int arg2) {
    return func_0206e120(arg0, arg1) == arg2;
}

// USA: func_0206cbcc
extern "C" ARM int func_0206cbcc(Script::Parameter* arg0, int arg1) {
    data_02108cec.unknown_a_++;
    Struct_0205faf4_3* var0;
    int var1 = arg0[0].ToInt();
    int var2 = arg0[1].ToInt();
    int var3 = arg0[2].ToInt();
    int var4 = arg0[3].ToInt();
    int var5 = arg0[4].ToInt();
    if (data_02108cec.unknown_6_ != var5) {
        data_02108cec.unknown_6_ = var5;
        data_02108cec.unknown_8_ = -1;
        data_02108cec.unknown_4_ = -1;
    }
    if (data_02108cec.wait > 0) return 1;
    table = Scenario_GetInstance();
    if (data_02108cec.previous != index && data_02108cec.previous > -1 &&
        !IsNibble0206cbcc(table, index, 1) && !IsNibble0206cbcc(table, index, 2) &&
        IsNibble0206cbcc(table, data_02108cec.previous, 3) && IsNibble0206cbcc(table, index, 3)) {
        if (data_02108cec.previous > index) return 1;
    }
    switch (var2) {
    case -1: if (!inline_0206cbcc(var0, var1, 0)) return 1; break;
    case 3: if (!inline_0206cbcc(var0, var1, 1)) return 1; break;
    case 0: if (!inline_0206cbcc(var0, var1, 2)) return 1; break;
    case 1: if (!func_0206e260((Struct_0205faf4_4*)var0, var1)) return 1; break;
    case 2: if (!inline_0206cbcc(var0, var1, 3)) return 1; break;
    case 4: if (!func_0206e2dc((Struct_0205faf4_13*)var0, var1) || !inline_0206cbcc(var0, var1, 0)) return 1; break;
    }
    GameState* var6 = GameState::GetInstance();
    if (var3 == 1) { if (var6->IsMorningDayOrEvening()) return 1; }
    else if (var3 == 0) { if (!var6->IsMorningDayOrEvening()) return 1; }
    if (var4 != data_02108cec.unknown_c_) {
        func_0206dd68(data_02108cec.unknown_10_, var5);
        return 1;
    }
    Struct_0206bf2c* var7 = (Struct_0206bf2c*)data_02108cec.unknown_14_->Allocate(0x78);
    if (!var7) return 0;
    func_0206bf2c(var7);
    var7->unknown_46_ = var1;
    var7->unknown_a_0_ = (unsigned char)var3;
    var7->unknown_2_ = var4;
    var7->unknown_0_ = var5;
    if (arg1 < 6) {
        func_0206dd68(data_02108cec.unknown_10_, var5);
        data_02108cec.unknown_8_ = var1;
        return 1;
    }
    Script::Parameter* var8 = arg0[5].ToVec3fix((Vector3fix*)var7->unknown1_10_);
    var7->unknown_1c_ = (int)(4096.0f * var8->ToFloat());
    if (arg1 > 9) var7->unknown_1e_ = var8[1].ToInt();
    var7->unknown_44_ = data_02108cec.unknown_a_;
    func_0206db48(data_02108cec.unknown_10_, var7);
    data_02108cec.unknown_8_ = var1;
    return 1;
}
