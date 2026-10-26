#ifndef GAMESTATE_OVERLAY17_DAY_CYCLE_H
#define GAMESTATE_OVERLAY17_DAY_CYCLE_H

struct Struct_ov017_021d75b8 {
#if defined(jpn)
    float unknown_8_;
    int unknown_4_;
    float unknown_14_;
    float unknown_0_;
    float unknown_10_;
    float unknown_c_;
#else
    float unknown_0_;
    int unknown_4_;
    float unknown_8_;
    float unknown_c_;
    float unknown_10_;
    float unknown_14_;
#endif
};

struct Struct_ov017_021d837c {
    float unknown0;
#if defined(jpn)
    float unknown_14_;
#endif
    float dayStart;
    float eveningStart;
    float morningStart;
    float nightStart;
#if !defined(jpn)
    float unknown_14_;
#endif
};


extern Struct_ov017_021d75b8 data_ov017_021d75b8;
extern Struct_ov017_021d837c data_ov017_021d837c;

#endif
