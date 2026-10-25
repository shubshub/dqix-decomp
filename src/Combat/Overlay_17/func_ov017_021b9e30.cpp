#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"


struct Struct_ov017_021d8438_3 {
    unsigned char unknown_0_, unknown_1_, unknown_2_, unknown_3_;
    int unknown_4_, unknown_8_, unknown_c_, unknown_10_;
    void* unknown_14_;
    int unknown_18_, unknown_1c_, unknown_20_;
};
struct Selected021b9e30 { signed char selected; signed char pending; };
extern Data021b9e30 data_ov017_021d8438;
extern Selected021b9e30 data_ov017_021d7c54;
struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct PackedNibbleArray0206e2dc;
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance(GameState*);
int CheckFlagAndThreshold0206e31c(int, int);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc*, int);
extern "C" int func_ov017_021b9bcc(int, const void*);
static inline int inline_ov017_021b9e30(Struct_0205faf4_3* arg0, int arg1, int arg2) {
    return func_0206e120(arg0, arg1) == arg2;
}

// USA: func_ov017_021b9e30
extern "C" ARM int func_ov017_021b9e30(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10) return 1;
    if (data_ov017_021d8438.byte1) return 1;
    if (data_ov017_021d7c54.pending > -1) return 1;
    PackedNibbleArray0206e120* fields = Scenario_GetInstance(GameState::GetInstance());
    int index = params->ToInt();
    if (!CheckFlagAndThreshold0206e31c((int)fields, index)) return 1;
    if (data_ov017_021d7c54.selected != index && data_ov017_021d7c54.selected > -1 && !NibbleEquals021b9e30(fields, index, 1) && !NibbleEquals021b9e30(fields, index, 2)) {
        if (!NibbleEquals021b9e30(fields, data_ov017_021d7c54.selected, 3) || !NibbleEquals021b9e30(fields, index, 3) || data_ov017_021d7c54.selected > index) return 1;
    }
    Script::Parameter* var2 = arg0 + 1;
    arg0 += 2;
    switch (var2->ToInt()) {
    case -1:
        if (!inline_ov017_021b9e30(var0, var1, 0)) return 1;
        break;
    case 0:
        if (!inline_ov017_021b9e30(var0, var1, 2)) return 1;
        break;
    case 1:
        if (!func_0206e260((Struct_0205faf4_4*)var0, var1)) return 1;
        break;
    case 2:
        if (!inline_ov017_021b9e30(var0, var1, 3)) return 1;
        break;
    case 3:
        if (!inline_ov017_021b9e30(var0, var1, 1)) return 1;
        break;
    case 4:
        if (!func_0206e2dc((Struct_0205faf4_13*)var0, var1) || !inline_ov017_021b9e30(var0, var1, 0)) return 1;
        break;
    }
    if (arg1 >= 5) {
        int var3 = arg0->ToInt();
        arg0++;
        if (var3) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else if (data_ov017_021d8438.unknown_2_) return 0;
    int var4 = arg0->ToInt();
    const char* var5 = arg0[1].ToString();
    if (!var5) return 0;
    if (func_ov017_021b9bcc(var4, var5)) data_ov017_021d7c54.unknown_0_ = var1;
    return 1;
}
