#pragma once

union Struct_0208ec78 {
    unsigned int word;
    struct {
        unsigned int timer : 9;
        unsigned int unknown_1_1_ : 4;
        unsigned int unknown_1_5_ : 4;
        unsigned int flags : 8;
        unsigned int count : 4;
        unsigned int kind : 2;
        unsigned int active : 1;
    } fields;
};


extern "C" void func_ov017_021d38f8(unsigned char mode, signed char partySlot,
                               unsigned char mask, unsigned char pointId,
                               const Struct_0208ec78* arg4);
