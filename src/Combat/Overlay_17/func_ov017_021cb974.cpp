#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_ov017_021cb974 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned int unknown_8_0_ : 3;
    unsigned int unknown_8_3_ : 3;
    unsigned int unknown_8_6_ : 3;
    unsigned int unknown_9_1_ : 3;
    unsigned int unknown_9_4_ : 3;
    unsigned int unknown_9_7_ : 3;
    unsigned int unknown_a_2_ : 3;
    unsigned int unknown_a_5_ : 3;
    unsigned int unknown_b_0_ : 3;
    unsigned int unknown_b_3_ : 3;
    unsigned int unknown_b_6_ : 2;
    unsigned int unknown_c_0_ : 3;
    unsigned int unknown_c_3_ : 3;
    unsigned int unknown_c_6_ : 3;
    unsigned int unknown_d_1_ : 3;
    unsigned int unknown_d_4_ : 4;
    unsigned int unknown_e_0_ : 16;
    unsigned char unknown_10_;
};
struct Struct_ov017_021cb974_2 { char unknown_0_[0x70]; unsigned char unknown_70_[15]; char unknown_7f_[0x14]; unsigned char unknown_93_[15]; char unknown_a2_[2]; };
struct Struct_ov017_021cb974_3 { char unknown_0_[8]; unsigned short unknown_8_; char unknown_a_[0x20]; signed char unknown_2a_; char unknown_2b_[0x12d]; Struct_ov017_021cb974_2 unknown_158_[8]; };
struct Struct_ov017_021cb974_4 { char unknown_0_[0x8e18]; Struct_ov017_021cb974_3* unknown_8e18_; };
struct Struct_ov017_021d82e0 {
#if defined(jpn)
 char unknown_0_[0x3508];
#else
 char unknown1_0_[0x3718];
#endif
 void* table; };
void* GetField6b0_021b8470(void*);
int GameState_GetProtagonistIndex(GameState*);

// USA: func_ov017_021cb974
extern "C" ARM void func_ov017_021cb974(int, PackedStatus* packet, GameState* game, BattleContext* context) {
    BattleStatus* status = (BattleStatus*)GetField6b0_021b8470(context->table);
    StatusOwner* owner;
    if (!status || !(owner = status->owner)) return;
    if (owner->owner == GameState_GetProtagonistIndex(game)) return;
    if (owner->battleId != packet->battleId) return;
    int index = packet->entryId - 0xc0;
    if (index < 0 || index >= 8) return;
    StatusEntry* target = &owner->entries[index];
    if (packet->mode == 1) {
        target->current[0] = packet->value0;
        target->current[1] = packet->value1;
        target->current[2] = packet->value2;
        target->current[3] = packet->value3;
        target->current[4] = packet->value4;
        target->current[5] = packet->value5;
        target->current[6] = packet->value6;
        target->current[7] = packet->value7;
        target->current[8] = packet->value8;
        target->current[9] = packet->value9;
        target->current[10] = packet->value10;
        target->current[11] = packet->value11;
        target->current[12] = packet->value12;
        target->current[13] = packet->value13;
        target->current[14] = packet->value14;
    } else {
        var3->unknown_93_[0] = arg1->unknown_8_0_;
        var3->unknown_93_[1] = arg1->unknown_8_3_;
        var3->unknown_93_[2] = arg1->unknown_8_6_;
        var3->unknown_93_[3] = arg1->unknown_9_1_;
        var3->unknown_93_[4] = arg1->unknown_9_4_;
        var3->unknown_93_[5] = arg1->unknown_9_7_;
        var3->unknown_93_[6] = arg1->unknown_a_2_;
        var3->unknown_93_[7] = arg1->unknown_a_5_;
        var3->unknown_93_[8] = arg1->unknown_b_0_;
        var3->unknown_93_[9] = arg1->unknown_b_3_;
        var3->unknown_93_[10] = arg1->unknown_c_0_;
        var3->unknown_93_[11] = arg1->unknown_c_3_;
        var3->unknown_93_[12] = arg1->unknown_c_6_;
        var3->unknown_93_[13] = arg1->unknown_d_1_;
        var3->unknown_93_[14] = arg1->unknown_d_4_;
    }
}
