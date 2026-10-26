#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct Struct_01ff91ac_24;

struct SearchStruct0202c1a4 { char pad[0x1038]; signed char arr[16]; };
extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_0205faf4;

struct Struct02030b7c { int field0; void* field4; };

extern "C" int func_ov017_021b9bcc(int a, void* b);

struct Struct_ov017_021d8438_4 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern struct Struct_ov017_021d8438_4 data_ov017_021d8438;

struct Struct_ov017_021d7c54_3 { signed char byte0; signed char unknown_1_; };
extern struct Struct_ov017_021d7c54_3 data_ov017_021d7c54;

// USA: func_ov017_021ba124
extern "C" ARM int func_ov017_021ba124(struct Variant02030b0c* v, int idx) {
    if (data_ov017_021d8438.field10 != 0) return 1;
    if (data_ov017_021d7c54.byte0 > -1) return 1;
    if (data_ov017_021d8438.unknown_1_ != 0) return 1;
    if (data_ov017_021d7c54.unknown_1_ > -1) return 1;

    GameState::GetInstance();
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)search)) return 1;
    if (LinkSession_GetOwnSlot(search) != 0) return 1;

    int a = ((Script::Parameter*)v)->ToInt();
    struct Variant02030b0c* var2 = (struct Variant02030b0c*)((char*)v + 8);
    v = (struct Variant02030b0c*)((char*)v + 16);
    int b = ((Script::Parameter*)var2)->ToInt();
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
    if (func_ov017_021b9bcc(d, e) != 0) data_ov017_021d8438.byte0 = 1;
    return 1;
}
