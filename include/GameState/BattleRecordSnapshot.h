#ifndef GAMESTATE_BATTLE_RECORD_SNAPSHOT_H
#define GAMESTATE_BATTLE_RECORD_SNAPSHOT_H



struct Struct_020ac4f8 {
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
};

extern "C" void func_ov008_02184598(Struct_020ac4f8*);

struct Struct_02061c04_2 {
    Struct_020ac4f8 elapsed;
    Struct_020ac4f8 unknown_4_;
};

struct Struct_02061c04_3 {
    Struct_020ac4f8 unknown_0_;
    Struct_020ac4f8 unknown_4_;
    unsigned int unknown_8_0_ : 17;
    unsigned int unknown_a_1_ : 7;
    unsigned int unknown_b_0_ : 7;
    unsigned int unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 17;
    unsigned int unknown_e_1_ : 7;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    unsigned int unknown_14_0_ : 8;
    unsigned int unknown_15_0_ : 14;
    unsigned int unknown_16_6_ : 10;
    unsigned int unknown_18_0_ : 24;
    unsigned int captured : 1;
    unsigned int unknown_1b_1_ : 7;
    unsigned int unknown_1c_;
};

struct Struct_02061c04 {
    Struct_02061c04_2 unknown_0_;
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 8;
    unsigned int unknown_c_0_ : 14;
    unsigned int unknown_d_6_ : 14;
    unsigned int unknown_f_4_ : 4;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    unsigned int unknown_14_0_ : 9;
    unsigned int unknown_15_1_ : 9;
    unsigned int unknown_16_2_ : 11;
    unsigned int unknown_17_5_ : 3;
    unsigned int unknown_18_0_ : 9;
    unsigned int unknown_19_1_ : 7;
    unsigned int unknown_1a_0_ : 4;
    unsigned int unknown_1a_4_ : 12;
    unsigned int unknown_1c_0_ : 16;
    unsigned int unknown_1e_0_ : 16;
    unsigned int unknown_20_0_ : 16;
    unsigned int unknown_22_0_ : 16;
    unsigned int unknown24;
    unsigned int unknown_28_0_ : 12;
    unsigned int unknown_29_4_ : 10;
    unsigned int unknown_2a_6_ : 10;
    unsigned int unknown_2c_0_ : 24;
    unsigned int unknown_2f_0_ : 8;
    unsigned int unknown_30_0_ : 24;
    unsigned int unknown_33_0_ : 8;
    unsigned int unknown_34_0_ : 24;
    unsigned int unknown_37_0_ : 8;
    unsigned int unknown_38_0_ : 24;
    unsigned int unknown_3b_0_ : 8;
    unsigned int unknown_3c_0_ : 24;
    unsigned int unknown_3f_0_ : 8;
    unsigned int unknown_40_0_ : 24;
    unsigned int unknown_43_0_ : 8;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned char unknown4c[0x1c];
    Struct_02061c04_2 unknown_68_;
    unsigned int unknown_70_[5];
    unsigned int unknown_84_0_ : 10;
    unsigned int unknown_85_2_ : 16;
    unsigned int unknown_87_2_ : 6;
    unsigned int unknown_88_0_ : 24;
    unsigned int unknown_8b_0_ : 8;
    unsigned int unknown_8c_0_ : 24;
    unsigned int unknown_8f_0_ : 8;
    Struct_02061c04_3 unknown_90_;
};


extern "C" int func_020ac4c0(void* destination);

#endif
