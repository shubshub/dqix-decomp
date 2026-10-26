#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned int);

struct Struct_02082cdc_2 {
    unsigned int x : 10;
    unsigned int y : 10;
    unsigned int z : 10;
    unsigned int reserved : 2;
};
struct Struct_02082cdc { Struct_02082cdc_2 values[3]; };
struct Struct_020827c4 { char data[0x1c]; };
struct CombatSelection {
    signed char selected : 6;
    unsigned char active : 1;
    unsigned char reserved : 1;
    unsigned char count : 4;
    unsigned char unknown_1_4_ : 1;
    unsigned char mode : 3;
    unsigned char enabled[13];
    unsigned char status[13];
    int entries[13];
    int current;
    unsigned short unknown_54_;
    char unknown_56_[2];
    Struct_02082cdc triples[13];
    unsigned short unknown_f4_;
    unsigned char flags[27];
    unsigned char unknown_111_[9];
    unsigned char unknown_11a_[36];
    unsigned char unknown_13e_;
    unsigned char cursor : 3;
    unsigned char capacity : 5;
    unsigned char unknown_140_[12];
    Struct_02082cdc_2 unknown_14c_[4];
    unsigned int timer : 10;
    unsigned int unknown_15d_2_ : 10;
    unsigned int unknown_15e_4_ : 12;
    Struct_020827c4 unknown_160_;
    unsigned char unknown_17c_[0xc0];
};
extern "C" void func_02082cdc(Struct_02082cdc*);
extern "C" void func_020827c4(Struct_020827c4*);

// Main, originally func_02086404 (USA 0x02086404, EUR 0x02086414, JPN 0x02086d24)
extern "C" ARM void PartyMemberRecord_Init(CombatSelection* selection) {
    selection->selected = -1;
    selection->active = 0;
    selection->count = 0;
    selection->unknown_1_4_ = 0;
    for (int i = 0; i < 13; ++i) {
        selection->entries[i] = 0;
        selection->enabled[i] = 1;
        selection->status[i] = 0;
        func_02082cdc(&selection->triples[i]);
    }
    selection->current = 0;
    selection->unknown_54_ = 0;
    selection->unknown_f4_ = 0;
    memset(selection->flags, 0, sizeof(selection->flags));
    memset(selection->unknown_111_, 0, sizeof(selection->unknown_111_));
    memset(selection->unknown_11a_, 0, sizeof(selection->unknown_11a_));
    selection->unknown_13e_ = 0;
    memset(selection->unknown_140_, 0, sizeof(selection->unknown_140_));
    selection->unknown_14c_[0].x = 0;
    selection->unknown_14c_[0].y = 0;
    selection->unknown_14c_[0].z = 0;
    selection->unknown_14c_[1].x = 0;
    selection->unknown_14c_[1].y = 0;
    selection->unknown_14c_[1].z = 0;
    selection->unknown_14c_[2].x = 0;
    selection->unknown_14c_[2].y = 1;
    selection->unknown_14c_[2].z = 0;
    selection->unknown_14c_[3].x = 1;
    selection->unknown_14c_[3].y = 0;
    selection->unknown_14c_[3].z = 0;
    selection->timer = 0;
    selection->unknown_15d_2_ = 0;
    func_020827c4(&selection->unknown_160_);
    memset(selection->unknown_17c_, -1, sizeof(selection->unknown_17c_));
    selection->mode = 0;
    selection->cursor = 0;
    selection->capacity = 5;
}
