#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct_ov017_021ce5b4_2 {
    char padding[4];
    unsigned short combatantId;
    signed char field6;
    signed char unknown_7_;
    signed char field8;
    signed char field9;
    signed char fieldA;
    signed char fieldB;
};

struct Struct_ov017_021ce5b4 {
    char padding[0x809];
    signed char unknown_809_;
    signed char unknown_80a_;
    char unknown_80b_;
    signed char unknown_80c_;
    signed char unknown_80d_;
    signed char unknown_80e_;
    char unknown_80f_;
    signed char unknown_810_;
};

struct Struct_02000c9c_61 {
#if defined(jpn)
    char padding[0x1c];
#else
    char padding[0x34];
#endif
    Struct_ov017_021ce5b4 fields;
};

struct Struct_ov017_021ce5b4_3 {
#if defined(jpn)
    char padding[0x80];
#else
    char padding[0x100];
#endif
    Struct_02000c9c_61 unknown_100_;
};

extern "C" Struct_ov017_021ce5b4_3* func_02053c6c(unsigned char* obj);

static inline Struct_02000c9c_61* inline_ov017_021ce5b4(Struct_ov017_021ce5b4_3* data) {
    return &data->unknown_100_;
}

static inline Struct_ov017_021ce5b4* inline_ov017_021ce5b4_2(Struct_02000c9c_61* region) {
    return &region->fields;
}

// USA: func_ov017_021ce5b4
extern "C" ARM void* func_ov017_021ce5b4(int unused, Struct_ov017_021ce5b4_2* event, GameState* gameState) {
    GameObject* combatant = func_0200ff1c(gameState, event->combatantId);
    if (combatant == NULL) return combatant;

    Struct_ov017_021ce5b4_3* data = func_02053c6c((unsigned char*)combatant);
    if (data == NULL) return data;

    Struct_ov017_021ce5b4* fields = inline_ov017_021ce5b4_2(inline_ov017_021ce5b4(data));
    fields->unknown_809_ = event->field6;
    fields->unknown_80a_ = event->unknown_7_;
    fields->unknown_80c_ = event->field8;
    fields->unknown_80d_ = event->field9;
    fields->unknown_80e_ = event->fieldA;
    fields->unknown_810_ = event->fieldB;
    return fields;
}
