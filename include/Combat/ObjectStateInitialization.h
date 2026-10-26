#pragma once

#include "World/Object3D.h"

struct Struct_02032fb8 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_02032e58 {
    Object3D unknown_0_;
    unsigned short unknown_ac_;
    unsigned short unknown_ae_;
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    unsigned short unknown_b6_;
    unsigned short unknown_b8_;
    unsigned short unknown_ba_;
    unsigned short unknown_bc_;
    unsigned char unknown_be_;
    unsigned char unknown_bf_;
    unsigned char unknown_c0_;
    unsigned char unknown_c1_0_ : 2;
    unsigned char unknown_c1_2_ : 1;
    unsigned char unknown_c1_3_ : 1;
    unsigned char unknown_c1_4_ : 4;
    unsigned char unknown_c2_0_ : 4;
    unsigned char unknown_c2_4_ : 1;
    unsigned char unknown_c2_5_ : 1;
    unsigned char unknown_c2_6_ : 1;
    unsigned char unknown_c2_7_ : 1;
    unsigned char unknown_c3_;
    unsigned short unknown_c4_0_ : 15;
    unsigned short unknown_c5_7_ : 1;
    unsigned short unknown_c6_;
    unsigned char unknown_c8_[0x18];
    unsigned char unknown_e0_0_ : 1;
    unsigned char unknown_e0_1_ : 1;
    unsigned char unknown_e0_2_ : 1;
    unsigned char unknown_e0_3_ : 1;
    unsigned char unknown_e0_4_ : 1;
    unsigned char unknown_e0_5_ : 1;
    unsigned char unknown_e0_6_ : 1;
    unsigned char unknown_e0_7_ : 1;
    unsigned char unknown_e1_[0x33];
    Struct_02032fb8 unknown_114_;
    Struct_02032fb8 unknown_11c_;
    unsigned int unknown_124_;
    unsigned int unknown_128_;
    unsigned short unknown_12c_;
};


void ClearFourHalfwords(Struct02032fb8 *value);
extern "C" void GameObject_Initialize(void *receiver);
