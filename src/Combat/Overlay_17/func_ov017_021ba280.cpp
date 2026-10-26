#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct SearchStruct0202c1a4;
extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);

extern "C" int func_ov017_021b9bcc(int arg0, const char* arg1);

struct Struct_ov017_021d8438_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    int unknown_4_;
    unsigned char unknown_8_[8];
    int unknown_10_;
};
extern Struct_ov017_021d8438_5 data_ov017_021d8438;

struct Struct_ov017_021d7c54_4 {
    signed char unknown_0_;
    signed char unknown_1_;
};
extern Struct_ov017_021d7c54_4 data_ov017_021d7c54;

// USA: func_ov017_021ba280
extern "C" ARM int func_ov017_021ba280(Script::Parameter* arg0, int arg1) {
    if (data_ov017_021d8438.unknown_10_ != 0) return 1;
    if (data_ov017_021d7c54.unknown_0_ > -1) return 1;
    if (data_ov017_021d8438.unknown_1_ != 0) return 1;
    if (data_ov017_021d7c54.unknown_1_ > -1) return 1;

    GameState::GetInstance();
    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)search)) return 1;
    if (LinkSession_GetOwnSlot(search) == 0) return 1;

    int var1 = arg0[0].ToInt();
    Script::Parameter* var2 = &arg0[1];
    arg0 += 2;
    int var3 = var2->ToInt();
    if (var1 >= 0 && (data_ov017_021d8438.unknown_4_ < var1 || var3 < data_ov017_021d8438.unknown_4_)) return 1;

    if (arg1 >= 5) {
        int var4 = arg0->ToInt();
        arg0++;
        if (var4 != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else {
        if (data_ov017_021d8438.unknown_2_ != 0) return 1;
    }

    int var5 = arg0[0].ToInt();
    const char* var6 = arg0[1].ToString();
    if (var6 == NULL) return 0;
    if (func_ov017_021b9bcc(var5, var6) != 0) data_ov017_021d8438.unknown_0_ = 1;
    return 1;
}
