#pragma once

struct Struct_0202b2f0;

struct Struct_0202b2f0_2 {
    union {
        unsigned short unknown_0_;
        struct {
            unsigned short unknown_0_0_ : 3;
            unsigned short unknown_0_3_ : 5;
            unsigned short unknown_1_0_ : 8;
        };
    } unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 4;
    unsigned short unknown_2_5_ : 2;
    unsigned short unknown_2_7_ : 2;
    unsigned short unknown_3_1_ : 2;
    unsigned short unknown_3_3_ : 1;
    unsigned short unknown_3_4_ : 1;
    unsigned short unknown_3_5_ : 1;
    unsigned short unknown_3_6_ : 1;
    unsigned short unknown_3_7_ : 1;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
};

SearchEntry0202c178* LinkSession_GetReceivedRecord(SearchStruct* object, int value);
void LinkSession_AgeScanResults(SearchStruct* object);
