#pragma once

struct Struct_0209e5b4 {
    unsigned int flags;
    unsigned char unknown4[4];
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned char unknown10[2];
    short unknown_12_;
    unsigned short unknown_14_;
    unsigned char unknown16[8];
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unknown20[0x10];
    short unknown_30_[8];
};

struct Struct_0209e5b4_2 {
    int count;
    Struct_0209e5b4 records[16];
};

struct Struct_0209e5b4_3 {
    unsigned char unknown0[4];
    unsigned char *source;
    unsigned char unknown8[0x90];
    Struct_0209e5b4_2 kept;
    Struct_0209e5b4_2 scratch;
};
