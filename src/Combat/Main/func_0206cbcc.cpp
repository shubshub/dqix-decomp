#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Combat/WorkRecord.h"


struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct Struct_0205faf4_13;
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" int func_0206e260(PackedNibbleArray0206e260*, int);
extern "C" int func_0206e2dc(Struct_0205faf4_13*, int);
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
extern "C" void func_0206dd68(void*, int);
struct Struct_02108cec {
    int field0;
    short wait;
    short group;
    short previous;
    unsigned short unknown_a_;
    unsigned short level;
    unsigned short unknown_e_;
    void* list;
    SafeAllocator* allocator;
};
extern Struct_02108cec data_02108cec;
static inline int inline_0206cbcc(PackedNibbleArray0206e120* table, int index, int value) {
    return func_0206e120(table, index) == value;
}

// USA: func_0206cbcc
extern "C" ARM int func_0206cbcc(Script::Parameter* params, int count) {
    data_02108cec.unknown_a_++;
    PackedNibbleArray0206e120* table;
    int index = params[0].ToInt();
    int var2 = params[1].ToInt();
    int day = params[2].ToInt();
    int level = params[3].ToInt();
    int group = params[4].ToInt();
    if (data_02108cec.group != group) {
        data_02108cec.group = group;
        data_02108cec.previous = -1;
        data_02108cec.wait = -1;
    }
    if (data_02108cec.wait > 0) return 1;
    table = Scenario_GetInstance();
    if (data_02108cec.previous != index && data_02108cec.previous > -1 &&
        !inline_0206cbcc(table, index, 1) && !inline_0206cbcc(table, index, 2) &&
        inline_0206cbcc(table, data_02108cec.previous, 3) && inline_0206cbcc(table, index, 3)) {
        if (data_02108cec.previous > index) return 1;
    }
    switch (var2) {
    case -1: if (!inline_0206cbcc(table, index, 0)) return 1; break;
    case 3: if (!inline_0206cbcc(table, index, 1)) return 1; break;
    case 0: if (!inline_0206cbcc(table, index, 2)) return 1; break;
    case 1: if (!func_0206e260((PackedNibbleArray0206e260*)table, index)) return 1; break;
    case 2: if (!inline_0206cbcc(table, index, 3)) return 1; break;
    case 4: if (!func_0206e2dc((Struct_0205faf4_13*)table, index) || !inline_0206cbcc(table, index, 0)) return 1; break;
    }
    GameState* state = GameState::GetInstance();
    if (day == 1) { if (state->IsMorningDayOrEvening()) return 1; }
    else if (day == 0) { if (!state->IsMorningDayOrEvening()) return 1; }
    if (level != data_02108cec.level) {
        func_0206dd68(data_02108cec.list, group);
        return 1;
    }
    Struct_0206bf2c* record = (Struct_0206bf2c*)data_02108cec.allocator->Allocate(0x78);
    if (!record) return 0;
    func_0206bf2c(record);
    record->unknown_46_ = index;
    record->unknown_a_0_ = (unsigned char)day;
    record->field2 = level;
    record->field0 = group;
    if (count < 6) {
        func_0206dd68(data_02108cec.list, group);
        data_02108cec.previous = index;
        return 1;
    }
    Script::Parameter* value = params[5].ToVec3fix((Vector3fix*)record->vec);
    record->field1c = (int)(4096.0f * value->ToFloat());
    if (count > 9) record->unknown_1e_ = value[1].ToInt();
    record->field44 = data_02108cec.unknown_a_;
    func_0206db48(data_02108cec.list, record);
    data_02108cec.previous = index;
    return 1;
}
