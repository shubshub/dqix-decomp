#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct Struct_02000c9c_60;

struct Struct_0205faf4;

struct Struct02030b7c { int field0; void* field4; };

extern "C" int func_ov017_021b9bcc(int a, void* b);

struct Struct_ov017_021d8438_2 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern struct Struct_ov017_021d8438_2 data_ov017_021d8438;

struct Struct_ov017_021d7c54 { signed char byte0; signed char unknown_1_; };
extern struct Struct_ov017_021d7c54 data_ov017_021d7c54;

// USA: func_ov017_021b9d00
extern "C" ARM int func_ov017_021b9d00(struct Variant02030b0c* v, int idx) {
    if (data_ov017_021d8438.field10 != 0) return 1;
    if (data_ov017_021d8438.byte0 != 0) return 1;
    if (data_ov017_021d7c54.byte0 > -1) return 1;
    if (data_ov017_021d8438.unknown_1_ != 0) return 1;
    if (data_ov017_021d7c54.unknown_1_ > -1) return 1;

    GameState::GetInstance();
    int a = ((Script::Parameter*)v)->ToInt();
    struct Variant02030b0c* var1 = (struct Variant02030b0c*)((char*)v + 8);
    v = (struct Variant02030b0c*)((char*)v + 16);
    int b = ((Script::Parameter*)var1)->ToInt();
    if (a >= 0 && (data_ov017_021d8438.field4 < a || b < data_ov017_021d8438.field4)) return 1;

    if (idx >= 5) {
        int c = ((Script::Parameter*)v)->ToInt();
        v = (struct Variant02030b0c*)((char*)v + 8);
        if (c != 0) {
            if (((GameState*)((struct Struct_0205faf4*)GameState::GetInstance()))->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else {
        if (data_ov017_021d8438.unknown_2_ != 0) return 1;
    }

    int d = ((Script::Parameter*)v)->ToInt();
    void* e = (void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)v + 8)))->ToString();
    if (e == 0) return 0;
    func_ov017_021b9bcc(d, e);
    return 1;
}
