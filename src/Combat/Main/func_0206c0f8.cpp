#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_0201d530;
struct Vector3i;

struct Struct_0205faf4;

struct Struct_02108cec_2 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char pad3;
    unsigned short unknown_4_;
    unsigned short half6;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    void* field10;
    void* field14;
};
extern struct Struct_02108cec_2 data_02108cec;

// USA: func_0206c0f8
extern "C" ARM int func_0206c0f8(void* param0, int param1) {
    struct Struct_0206bf2c* rec;
    struct Struct_0201d530* q;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;

    data_02108cec.unknown_a_ = data_02108cec.unknown_a_ + 1;

    v0 = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    if (v0 != data_02108cec.unknown_2_) return 1;
    v1 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    if (v1 != data_02108cec.unknown_1_) return 1;
    v2 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x10)))->ToInt();
    if (v2 != data_02108cec.byte0) return 1;
    v3 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x18)))->ToInt();

    {
        struct Struct_0205faf4* gs = (Struct_0205faf4*)GameState::GetInstance();
        if (v3 == 1) {
            if (((GameState*)gs)->IsMorningDayOrEvening()) return 1;
        } else if (v3 == 0) {
            if (!((GameState*)gs)->IsMorningDayOrEvening()) return 1;
        }
    }

    v4 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x20)))->ToInt();
    v5 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x28)))->ToInt();

    if (v4 != data_02108cec.unknown_c_) {
        func_0206dd68(data_02108cec.field10, v5);
        return 1;
    }

    rec = (struct Struct_0206bf2c*)((SafeAllocator*)data_02108cec.field14)->Allocate(0x78);
    if (rec == 0) return 0;

    func_0206bf2c(rec);

    rec->field4 = v0;
    rec->field5 = v1;
    rec->field6 = v2;
    rec->unknown_a_0_ = (unsigned char)v3;
    rec->field2 = v4;
    rec->field0 = v5;

    if (param1 < 7) {
        func_0206dd68(data_02108cec.field10, v5);
        return 1;
    }

    q = (Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x30)))->ToVec3fix((Vector3i*)rec->vec);
    rec->field1c = (int)(4096.0f * ((Script::Parameter*)q)->ToFloat());

    if (param1 > 10) {
        rec->unknown_1e_ = ((Script::Parameter*)((struct Variant02030b0c*)((char*)q + 8)))->ToInt();
    }

    rec->field44 = data_02108cec.unknown_a_;
    func_0206db48(data_02108cec.field10, rec);
    return 1;
}
