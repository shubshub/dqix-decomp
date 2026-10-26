#pragma once

struct Struct_020fdc60 {
    unsigned char state;
    unsigned char unknown_1_;
    unsigned char b2;
    unsigned char pad3;
    unsigned short field4;
    unsigned char pad[0xe];
};

extern "C" void func_0201fbe0(Struct_020fdc60 *state, int force);

extern Struct_020fdc60 data_020fdc60[4];
