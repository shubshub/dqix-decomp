#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ce524_2 {
    char unknown_0_[9];
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    char unknown_b_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    char unknown_f_;
    unsigned char unknown_10_;
};

struct Struct_ov017_021ce524_3 {
    char unknown_0_[0x800];
    Struct_ov017_021ce524_2 unknown_800_;
};

struct Struct_ov017_021ce524_4 {
#if defined(jpn)
    char unknown_0_[0x1c];
#else
    char unknown1_0_[0x34];
#endif
    Struct_ov017_021ce524_3 unknown_34_;
};

struct Struct_ov017_021ce524_5 {
#if defined(jpn)
    char unknown_0_[0x80];
#else
    char unknown1_0_[0x100];
#endif
    Struct_ov017_021ce524_4 unknown_100_;
};

extern "C" Struct_ov017_021ce524_5* func_02053c6c(unsigned char* arg0);

struct Struct_ov017_021ce524_6 {
    short unknown_0_;
    signed char unknown_2_;
    signed char unknown_3_;
    signed char unknown_4_;
    signed char unknown_5_;
    signed char unknown_6_;
    signed char unknown_7_;
};

struct Struct_ov017_021ce524 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021ce524_6 unknown_4_;
    unsigned char unknown_c_[8];
};

// USA: func_ov017_021ce524
extern "C" ARM void func_ov017_021ce524(short combatantId) {
    LocalEvt021ce524 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x29;
    Sub021ce524* s = &buf.sub;
    s->combatantId = combatantId;

    GameObject* var3 = func_0200ff1c(GameState::GetInstance(), arg0);
    if (var3 == NULL) return;

    Struct_ov017_021ce524_5* var4 = func_02053c6c((unsigned char*)var3);
    if (var4 == NULL) return;

    Struct_ov017_021ce524_2* var5 = &var4->unknown_100_.unknown_34_.unknown_800_;
    var2->unknown_2_ = var5->unknown_9_;
    var2->unknown_3_ = var5->unknown_a_;
    var2->unknown_4_ = var5->unknown_c_;
    var2->unknown_5_ = var5->unknown_d_;
    var2->unknown_6_ = var5->unknown_e_;
    var2->unknown_7_ = var5->unknown_10_;
    func_0205e330(var1, &var0, 0);
}
