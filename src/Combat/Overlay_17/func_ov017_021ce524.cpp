#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ce524_2 {
    char padding[9];
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
    char padding[0x800];
    Struct_ov017_021ce524_2 stats;
};

struct Struct_ov017_021ce524_4 {
#if defined(jpn)
    char padding[0x1c];
#else
    char padding[0x34];
#endif
    Struct_ov017_021ce524_3 fields;
};

struct Struct_ov017_021ce524_5 {
#if defined(jpn)
    char padding[0x80];
#else
    char padding[0x100];
#endif
    Struct_ov017_021ce524_4 unknown_100_;
};

extern "C" Struct_ov017_021ce524_5* func_02053c6c(unsigned char* obj);

struct Struct_ov017_021ce524_6 {
    short combatantId;
    signed char field2;
    signed char unknown_3_;
    signed char field4;
    signed char field5;
    signed char field6;
    signed char unknown_7_;
};

struct Struct_ov017_021ce524 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021ce524_6 sub;
    unsigned char pad2[8];
};

// USA: func_ov017_021ce524
extern "C" ARM void func_ov017_021ce524(short combatantId) {
    Struct_ov017_021ce524 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x29;
    Struct_ov017_021ce524_6* s = &buf.sub;
    s->combatantId = combatantId;

    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == NULL) return;

    Struct_ov017_021ce524_5* data = func_02053c6c((unsigned char*)combatant);
    if (data == NULL) return;

    Struct_ov017_021ce524_2* stats = &data->unknown_100_.fields.stats;
    s->field2 = stats->unknown_9_;
    s->unknown_3_ = stats->unknown_a_;
    s->field4 = stats->unknown_c_;
    s->field5 = stats->unknown_d_;
    s->field6 = stats->unknown_e_;
    s->unknown_7_ = stats->unknown_10_;
    func_0205e330(p, &buf, 0);
}
