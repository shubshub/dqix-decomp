#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_ov017_021cb974 {
    int field0;
    unsigned short battleId;
    unsigned short entryId;
    unsigned int value0 : 3;
    unsigned int unknown_8_3_ : 3;
    unsigned int unknown_8_6_ : 3;
    unsigned int unknown_9_1_ : 3;
    unsigned int unknown_9_4_ : 3;
    unsigned int unknown_9_7_ : 3;
    unsigned int unknown_a_2_ : 3;
    unsigned int unknown_a_5_ : 3;
    unsigned int value8 : 3;
    unsigned int unknown_b_3_ : 3;
    unsigned int unused0 : 2;
    unsigned int value10 : 3;
    unsigned int unknown_c_3_ : 3;
    unsigned int unknown_c_6_ : 3;
    unsigned int unknown_d_1_ : 3;
    unsigned int unknown_d_4_ : 4;
    unsigned int unused1 : 16;
    unsigned char mode;
};
struct Struct_ov017_021cb974_2 { char pad0[0x70]; unsigned char current[15]; char pad1[0x14]; unsigned char previous[15]; char pad2[2]; };
struct Struct_ov017_021cb974_3 { char pad0[8]; unsigned short battleId; char pad1[0x20]; signed char owner; char pad2[0x12d]; Struct_ov017_021cb974_2 entries[8]; };
struct Struct_ov017_021cb974_4 { char pad[0x8e18]; Struct_ov017_021cb974_3* owner; };
struct Struct_ov017_021d82e0 {
#if defined(jpn)
 char pad[0x3508];
#else
 char pad[0x3718];
#endif
 void* table; };
extern "C" void* func_ov017_021b8470(void*);
extern "C" int GameState_GetProtagonistIndex(GameState*);

// USA: func_ov017_021cb974
extern "C" ARM void func_ov017_021cb974(int, Struct_ov017_021cb974* packet, GameState* game, Struct_ov017_021d82e0* context) {
    Struct_ov017_021cb974_4* status = (Struct_ov017_021cb974_4*)func_ov017_021b8470(context->table);
    Struct_ov017_021cb974_3* owner;
    if (!status || !(owner = status->owner)) return;
    if (owner->owner == GameState_GetProtagonistIndex(game)) return;
    if (owner->battleId != packet->battleId) return;
    int index = packet->entryId - 0xc0;
    if (index < 0 || index >= 8) return;
    Struct_ov017_021cb974_2* target = &owner->entries[index];
    if (packet->mode == 1) {
        target->current[0] = packet->value0;
        target->current[1] = packet->unknown_8_3_;
        target->current[2] = packet->unknown_8_6_;
        target->current[3] = packet->unknown_9_1_;
        target->current[4] = packet->unknown_9_4_;
        target->current[5] = packet->unknown_9_7_;
        target->current[6] = packet->unknown_a_2_;
        target->current[7] = packet->unknown_a_5_;
        target->current[8] = packet->value8;
        target->current[9] = packet->unknown_b_3_;
        target->current[10] = packet->value10;
        target->current[11] = packet->unknown_c_3_;
        target->current[12] = packet->unknown_c_6_;
        target->current[13] = packet->unknown_d_1_;
        target->current[14] = packet->unknown_d_4_;
    } else {
        target->previous[0] = packet->value0;
        target->previous[1] = packet->unknown_8_3_;
        target->previous[2] = packet->unknown_8_6_;
        target->previous[3] = packet->unknown_9_1_;
        target->previous[4] = packet->unknown_9_4_;
        target->previous[5] = packet->unknown_9_7_;
        target->previous[6] = packet->unknown_a_2_;
        target->previous[7] = packet->unknown_a_5_;
        target->previous[8] = packet->value8;
        target->previous[9] = packet->unknown_b_3_;
        target->previous[10] = packet->value10;
        target->previous[11] = packet->unknown_c_3_;
        target->previous[12] = packet->unknown_c_6_;
        target->previous[13] = packet->unknown_d_1_;
        target->previous[14] = packet->unknown_d_4_;
    }
}
