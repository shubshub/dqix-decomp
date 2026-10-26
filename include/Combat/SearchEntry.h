#pragma once

struct SearchStruct;

struct SearchEntry0202c178 {
    union {
        unsigned short raw;
        struct {
            unsigned short selected : 3;
            unsigned short reserved : 5;
            unsigned short kind : 8;
        };
    } flags;
    unsigned short active : 1;
    unsigned short members : 4;
    unsigned short selector1 : 2;
    unsigned short selector2 : 2;
    unsigned short selector3 : 2;
    unsigned short bit11 : 1;
    unsigned short unknown_3_4_ : 1;
    unsigned short bit13 : 1;
    unsigned short unknown_3_6_ : 1;
    unsigned short unknown_3_7_ : 1;
    unsigned short mask;
    unsigned short field6;
    short x;
    short y;
    short z;
    short angle;
};

extern "C" SearchEntry0202c178* LinkSession_GetReceivedRecord(SearchStruct* object, int value);
extern "C" void LinkSession_AgeScanResults(SearchStruct* object);
