#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct SearchStruct0202c1a4;
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);

extern "C" int func_ov017_021b9bcc(int id, const char* name);

struct Struct_ov017_021d8438_5 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern Struct_ov017_021d8438_5 data_ov017_021d8438;

struct Struct_ov017_021d7c54_4 {
    signed char byte0;
    signed char unknown_1_;
};
extern Struct_ov017_021d7c54_4 data_ov017_021d7c54;

// USA: func_ov017_021ba280
extern "C" ARM int func_ov017_021ba280(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10 != 0) return 1;
    if (data_ov017_021d7c54.byte0 > -1) return 1;
    if (data_ov017_021d8438.unknown_1_ != 0) return 1;
    if (data_ov017_021d7c54.unknown_1_ > -1) return 1;

    GameState::GetInstance();
    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)search)) return 1;
    if (LinkSession_GetOwnSlot(search) == 0) return 1;

    int lo = params[0].ToInt();
    Script::Parameter* var2 = &params[1];
    params += 2;
    int hi = var2->ToInt();
    if (lo >= 0 && (data_ov017_021d8438.field4 < lo || hi < data_ov017_021d8438.field4)) return 1;

    if (count >= 5) {
        int var4 = params->ToInt();
        params++;
        if (var4 != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else {
        if (data_ov017_021d8438.unknown_2_ != 0) return 1;
    }

    int id = params[0].ToInt();
    const char* name = params[1].ToString();
    if (name == NULL) return 0;
    if (func_ov017_021b9bcc(id, name) != 0) data_ov017_021d8438.byte0 = 1;
    return 1;
}
