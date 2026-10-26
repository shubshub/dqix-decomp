#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "Combat/WorkRecord.h"


struct Variant02030b0c;
struct Struct_0201d530;
struct Vector3i;

struct GameState;

extern "C" char* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" int func_0206eb98(unsigned char*, int);
extern "C" void func_0206dd68(void*, int);

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    void* unknown_10_;
    void* unknown_14_;
};
extern struct Struct_02108cec data_02108cec;

// USA: func_0206d4e0
extern "C" ARM int func_0206d4e0(void* param0, int param1) {
    if (param1 < 9) {
        return 0;
    }
    data_02108cec.unknown_a_++;
    bool var0 = false;
    if (param1 % 2 == 0) {
        var0 = true;
    }
    int n;
    int second;
    int half = (var0 ? param1 - 8 : param1 - 7) / 2;
    char* ctx = Scenario_GetInstance();
    struct Variant02030b0c* arg = (struct Variant02030b0c*)param0;
    for (n = half; n > 0; n--) {
        int packed = ((Script::Parameter*)arg)->ToInt();
        struct Variant02030b0c* next = (struct Variant02030b0c*)((char*)arg + 8);
        arg = (struct Variant02030b0c*)((char*)arg + 0x10);
        second = ((Script::Parameter*)next)->ToInt();
        int mode = packed >> 16;
        if (mode == 1) {
            int hit = Scenario_TestFlag((int)ctx, (unsigned char*)(ctx + 0x8c), (unsigned short)packed);
            if ((second != 0 && hit == 0) || (second == 0 && hit != 0)) {
                return 1;
            }
        } else if (mode == 2) {
            int hit = func_0206eb98((unsigned char*)ctx, (unsigned short)packed);
            if ((second != 0 && hit == 0) || (second == 0 && hit != 0)) {
                return 1;
            }
        } else {
            return 1;
        }
    }

    int kind = ((Script::Parameter*)arg)->ToInt();
    struct GameState* gs = GameState::GetInstance();
    if (kind == 1) {
        if (gs->IsMorningDayOrEvening()) {
            return 1;
        }
    } else if (kind == 0) {
        if (!gs->IsMorningDayOrEvening()) {
            return 1;
        }
    }

    int a = ((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 8)))->ToInt();
    int b = ((Script::Parameter*)((struct Variant02030b0c*)((char*)arg + 0x10)))->ToInt();
    if (a != data_02108cec.unknown_c_) {
        func_0206dd68(data_02108cec.unknown_10_, b);
        return 1;
    }

    struct Struct_0206bf2c* rec = (struct Struct_0206bf2c*)((SafeAllocator*)data_02108cec.unknown_14_)->Allocate(0x78);
    if (rec == 0) {
        return 0;
    }
    func_0206bf2c(rec);
    rec->field2 = (unsigned short)a;
    int rem = param1 - half * 2 - var0;
    rec->field0 = (unsigned char)b;
    if (rem < 4) {
        func_0206dd68(data_02108cec.unknown_10_, rec->field0);
        return 1;
    }

    struct Struct_0201d530* v = (Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)((char*)arg + 0x18)))->ToVec3fix((Vector3i*)rec->vec);
    rec->field1c = (short)(4096.0f * ((Script::Parameter*)v)->ToFloat());
    if (var0) {
        rec->unknown_1e_ = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
    }
    rec->field44 = data_02108cec.unknown_a_;
    rec->unknown_a_2_ = 1;
    func_0206db48(data_02108cec.unknown_10_, rec);
    return 1;
}
