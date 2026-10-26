#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "GameState/GameState.h"

struct Variant02030b0c;

struct Struct_0201d530;
struct Vector3i;

struct Struct_0205faf4;

struct Struct_02108cec_3 {
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
extern struct Struct_02108cec_3 data_02108cec;

// USA: func_0206c2c0
extern "C" ARM int func_0206c2c0(void* param0, int param1) {
    struct Struct_0206bf2c* rec;
    struct Struct_0201d530* q;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    int v7;
    int v8;
    int key;
    int lo;
    int hi;

    data_02108cec.unknown_a_ = data_02108cec.unknown_a_ + 1;

    v0 = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    v1 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    v2 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x10)))->ToInt();
    v3 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x18)))->ToInt();
    v4 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x20)))->ToInt();
    v5 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x28)))->ToInt();

    hi = v3 * 1000 + v4 * 10 + v5;
    key = data_02108cec.byte0 + (data_02108cec.unknown_2_ * 1000 + data_02108cec.unknown_1_ * 10);
    lo = v0 * 1000 + v1 * 10 + v2;
    if (key < lo || hi < key) {
        return 1;
    }

    v6 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x30)))->ToInt();

    {
        struct Struct_0205faf4* gs = (Struct_0205faf4*)GameState::GetInstance();
        if (v6 == 1) {
            if (((GameState*)gs)->IsMorningDayOrEvening()) return 1;
        } else if (v6 == 0) {
            if (!((GameState*)gs)->IsMorningDayOrEvening()) return 1;
        }
    }

    v7 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x38)))->ToInt();
    v8 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x40)))->ToInt();

    if (v7 != data_02108cec.unknown_c_) {
        func_0206dd68(data_02108cec.field10, v8);
        return 1;
    }

    rec = (struct Struct_0206bf2c*)((SafeAllocator*)data_02108cec.field14)->Allocate(0x78);
    if (rec == 0) return 0;

    func_0206bf2c(rec);

    rec->field4 = v0;
    rec->field5 = v1;
    rec->field6 = v2;
    rec->unknown_7_ = v3;
    rec->field8 = v4;
    rec->unknown_9_ = v5;
    rec->unknown_a_0_ = v6;
    rec->field2 = v7;
    rec->field0 = v8;

    if (param1 < 10) {
        func_0206dd68(data_02108cec.field10, v8);
        return 1;
    }

    q = (Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x48)))->ToVec3fix((Vector3i*)rec->vec);
    rec->field1c = (unsigned short)(int)(4096.0f * ((Script::Parameter*)q)->ToFloat());

    if (param1 > 13) {
        rec->unknown_1e_ = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)q + 8)))->ToInt();
    }

    rec->field44 = data_02108cec.unknown_a_;
    func_0206db48(data_02108cec.field10, rec);
    return 1;
}
