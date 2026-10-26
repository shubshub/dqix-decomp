#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int func_ov017_021b9bcc(int a, const char* b);

struct Struct_ov017_021ba3dc {
    char unknown_0_[4];
    unsigned short unknown_4_;
};

struct Struct_ov017_021d8438 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    int unknown_4_;
    unsigned char unknown_8_[8];
    int unknown_10_;
};
extern struct Struct_ov017_021d8438 data_ov017_021d8438;

struct Struct_ov017_021d7c54_5 {
    signed char unknown_0_;
    signed char unknown_1_;
};
extern struct Struct_ov017_021d7c54_5 data_ov017_021d7c54;

// USA: func_ov017_021ba3dc
extern "C" ARM int func_ov017_021ba3dc(Script::Parameter* arg0, int arg1) {
    if (data_ov017_021d8438.unknown_10_ != 0) return 1;
    if (data_ov017_021d7c54.unknown_1_ > -1) return 1;

    GameState* battle = GameState::GetInstance();
    if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) return 1;

    GameObject* var1 = var0->GetGameObjectByIndex(0);
    struct Struct_ov017_021ba3dc* var2 = *(struct Struct_ov017_021ba3dc**)((char*)var1 + 0x130);
    int var3 = var2->unknown_4_;
    if (var3 > 0) return 1;

    int var4 = arg0[0].ToInt();
    Script::Parameter* var5 = &arg0[1];
    arg0 = &arg0[2];
    int var6 = var5->ToInt();
    if (var4 >= 0 && (data_ov017_021d8438.unknown_4_ < var4 || var6 < data_ov017_021d8438.unknown_4_)) return 1;

    if (arg1 >= 5) {
        int var7 = arg0->ToInt();
        arg0++;
        if (var7 != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else {
        if (data_ov017_021d8438.unknown_2_ != 0) return 1;
    }

    int var8 = arg0[0].ToInt();
    const char* var9 = arg0[1].ToString();
    if (var9 == 0) return 0;
    if (func_ov017_021b9bcc(var8, var9) != 0) data_ov017_021d8438.unknown_1_ = 1;
    return 1;
}
