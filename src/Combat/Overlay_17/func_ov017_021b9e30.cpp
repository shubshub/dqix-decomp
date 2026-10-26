#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"


struct Struct_ov017_021d8438_3 {
    unsigned char byte0, unknown_1_, unknown_2_, pad3;
    int field4, field8, fieldc, field10;
    void* field14;
    int field18, field1c, field20;
};
struct Struct_ov017_021d7c54_2 { signed char selected; signed char pending; };
extern Struct_ov017_021d8438_3 data_ov017_021d8438;
extern Struct_ov017_021d7c54_2 data_ov017_021d7c54;
struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct Struct_0205faf4_13;
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance(GameState*);
extern "C" int func_0206e31c(int, int);
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" int func_0206e260(PackedNibbleArray0206e260*, int);
extern "C" int func_0206e2dc(Struct_0205faf4_13*, int);
extern "C" int func_ov017_021b9bcc(int, const void*);
static inline int inline_ov017_021b9e30(PackedNibbleArray0206e120* fields, int index, int value) {
    return func_0206e120(fields, index) == value;
}

// USA: func_ov017_021b9e30
extern "C" ARM int func_ov017_021b9e30(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10) return 1;
    if (data_ov017_021d8438.unknown_1_) return 1;
    if (data_ov017_021d7c54.pending > -1) return 1;
    PackedNibbleArray0206e120* fields = Scenario_GetInstance(GameState::GetInstance());
    int index = params->ToInt();
    if (!func_0206e31c((int)fields, index)) return 1;
    if (data_ov017_021d7c54.selected != index && data_ov017_021d7c54.selected > -1 && !inline_ov017_021b9e30(fields, index, 1) && !inline_ov017_021b9e30(fields, index, 2)) {
        if (!inline_ov017_021b9e30(fields, data_ov017_021d7c54.selected, 3) || !inline_ov017_021b9e30(fields, index, 3) || data_ov017_021d7c54.selected > index) return 1;
    }
    Script::Parameter* var2 = params + 1;
    params += 2;
    switch (var2->ToInt()) {
    case -1:
        if (!inline_ov017_021b9e30(fields, index, 0)) return 1;
        break;
    case 0:
        if (!inline_ov017_021b9e30(fields, index, 2)) return 1;
        break;
    case 1:
        if (!func_0206e260((PackedNibbleArray0206e260*)fields, index)) return 1;
        break;
    case 2:
        if (!inline_ov017_021b9e30(fields, index, 3)) return 1;
        break;
    case 3:
        if (!inline_ov017_021b9e30(fields, index, 1)) return 1;
        break;
    case 4:
        if (!func_0206e2dc((Struct_0205faf4_13*)fields, index) || !inline_ov017_021b9e30(fields, index, 0)) return 1;
        break;
    }
    if (count >= 5) {
        int var3 = params->ToInt();
        params++;
        if (var3) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else if (data_ov017_021d8438.unknown_2_) return 0;
    int value = params->ToInt();
    const char* name = params[1].ToString();
    if (!name) return 0;
    if (func_ov017_021b9bcc(value, name)) data_ov017_021d7c54.selected = index;
    return 1;
}
