#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02052df8;
extern "C" int func_02052df8(Struct_02052df8*, int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int func_020dd200(int, int);
extern "C" int func_020dd154(int, int);
struct Struct_020dd4c4_2 {
    unsigned int : 7;
    unsigned int category : 4;
    unsigned int : 18;
    unsigned int protagonistOnly : 1;
    unsigned int unknown_3_6_ : 2;
    unsigned int vocationMask : 12;
    unsigned int : 15;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 1;
    unsigned int : 2;
};
struct Struct_020dd4c4_3 {
    Struct_020dd4c4_2* requirements;
    int unknown_4_;
    unsigned int kind : 4;
    unsigned int : 28;
    char unknown_c_[0xc];
    short count;
};
struct Struct_020dd4c4_4 {
    char unknown_0_[0x186];
    unsigned char revocations[13];
    char unknown_193_[0x49c - 0x193];
    unsigned char flag : 1;
    unsigned char : 7;
#if defined(jpn)
    char unknown_49d_[0x8b8 - 0x49d];
#else
    char unknown1_49d_[0x950 - 0x49d];
#endif
    int vocation;
    unsigned short inline_020dd4c4(int vocation) const {
        return revocations[vocation];
    }
};
struct Struct_020dd4c4 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_020dd4c4_4* record;
};
static inline Struct_020dd4c4* inline_020dd4c4_2(int id) {
    return (Struct_020dd4c4*)func_0200ff1c(GameState::GetInstance(), id);
}

// USA: func_020dd4c4
extern "C" ARM int func_020dd4c4(int id, Struct_020dd4c4_3* entry) {
    if (!entry) return 0x200;
    if (entry->count <= 0) return 0x200;
    Struct_020dd4c4* combatant = inline_020dd4c4_2(id);
    if (!combatant) return 0x20;
    if (!combatant->record->vocation) return 0;
    int var1 = entry->kind <= 7;
    if (!var1) return 8;
    if (!entry->requirements) return 8;
    int result = 0;
    GameState* state = GameState::GetInstance();
    result |= (entry->requirements->protagonistOnly && id != GameState_GetProtagonistIndex(state)) ? 0x100 : 0;
    int var4;
    if (entry->kind != 0 && entry->kind != 1) var4 = 0;
    else if (func_020dd200(id & 0xff, entry->requirements->category & 0xff)) var4 = 0;
    else {
        if (func_020dd154(id, entry->requirements->category & 0xff)) var4 = 0;
        else var4 = 1;
    }
    result |= var4;
    int var5;
    if (entry->kind == 0) var5 = 0;
    else if (entry->kind == 1) var5 = 0;
    else {
        int vocation = inline_020dd4c4_2(id)->record->vocation;
        if (vocation == 0) var5 = 2;
        else {
            int mask = 1 << (vocation - 1);
            var5 = (entry->requirements->vocationMask & mask) ? 0 : 2;
        }
    }
    result |= var5;
    Struct_020dd4c4_4* record = inline_020dd4c4_2(id)->record;
    int revocations = record->inline_020dd4c4(record->vocation);
    result |= entry->requirements->unknown_3_6_ <= (unsigned short)revocations ? 0 : 0x10;
    combatant = inline_020dd4c4_2(id);
    Struct_020dd4c4_2* requirements = entry->requirements;
    unsigned int flag = combatant->record->flag;
    int var12;
    if (func_02052df8((Struct_02052df8*)combatant, 9) == 0x4680 && !requirements->unknown_7_5_) var12 = 0;
    else {
        unsigned int var13[2] = { requirements->unknown_7_3_, requirements->unknown_7_4_ };
        var12 = var13[flag] ? 0 : 0x80;
    }
    result |= var12;
    return result;
}
