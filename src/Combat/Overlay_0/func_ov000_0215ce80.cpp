#include <globaldefs.h>
#include "Util/Random.h"

struct Struct_ov000_0215ce80_3 { char data[0x40]; };
struct Struct_ov000_0215ce80_4 { char data[0x18]; };
struct Struct_ov000_0215ce80 { char data[10]; };

struct Struct_ov000_0215ce80_2 {
    unsigned char a;
    unsigned char b;
    short c;
    int d;
};

struct Struct_ov000_0215767c_2 {
    struct Random rng;
    char pad20[0x5c60 - sizeof(struct Random)];
    Struct_ov000_0215ce80_3 entries[16];
    char unknown_6060_[0x81b0 - 0x6060];
    unsigned char unknown_81b0_;
    unsigned char unknown_81b1_0_ : 4;
    unsigned char groupCount : 2;
    unsigned char unknown_81b1_6_ : 2;
    short unknown_81b2_;
    Struct_ov000_0215ce80_4 groups[3];
    Struct_ov000_0215ce80_2 pairs[4];
    char unknown_821c_[0x8d5c - 0x821c];
    unsigned char unknown_8d5c_[10];
    Struct_ov000_0215ce80 records[12];
    char unknown_8dde_[0x8de0 - 0x8dde];
    signed char unknown_8de0_[0x20];
    char unknown_8e00_[4];
    short unknown_8e04_;
    signed char unknown_8e06_;
    unsigned char unknown_8e07_;
    char unknown_8e08_[0x8e14 - 0x8e08];
    signed char result;
    unsigned char unknown_8e15_;
    char unknown_8e16_[2];
    int unknown_8e18_;
    int unknown_8e1c_;
    int unknown_8e20_;
    char unknown_8e24_[4];
    int unknown_8e28_;
    int unknown_8e2c_;
    int unknown_8e30_;
    int unknown_8e34_;
    char unknown_8e38_[4];
    float unknown_8e3c_;
    float unknown_8e40_;
    unsigned char unknown_8e44_[3];
    unsigned char unknown_8e47_;
    signed char unknown_8e48_;
    unsigned char mode;
    short unknown_8e4a_;
    short unknown_8e4c_;
    short unknown_8e4e_;
    char unknown_8e50_[0x8e84 - 0x8e50];
    unsigned char unknown_8e84_[0x10];
    unsigned char unknown_8e94_;
    char unknown_8e95_[2];
    unsigned char unknown_8e97_;
    char unknown_8e98_[0x8eb0 - 0x8e98];
    int unknown_8eb0_;
};

extern char data_ov000_021838c1[];

extern "C" void func_ov000_0215d090(Struct_ov000_0215767c_2* battle);
extern "C" void* memset(void* dst, int c, unsigned int n);
unsigned long long GetCurrentTimestamp(void);

// USA: func_ov000_0215ce80
extern "C" ARM void func_ov000_0215ce80(Struct_ov000_0215767c_2* battle) {
    func_ov000_0215d090(battle);
    battle->unknown_8e18_ = 0;
    battle->unknown_8e1c_ = 0;
    battle->unknown_8e20_ = 0;
    battle->unknown_8e47_ = 0;
    battle->unknown_8e48_ = -1;
    battle->unknown_8e28_ = 0;
    battle->unknown_8e2c_ = 0;
    battle->unknown_8e30_ = 0;
    battle->result = 0;
    battle->unknown_8e34_ = 0;
    battle->unknown_8e15_ = 0;
    battle->unknown_8e3c_ = 1.0f;
    battle->unknown_8e40_ = 1.0f;
    battle->mode = 0;
    memset(battle->unknown_8e44_, 0, sizeof(battle->unknown_8e44_));
    memset(battle->unknown_8e84_, 0, sizeof(battle->unknown_8e84_));
    battle->unknown_81b0_ = 0;
    battle->unknown_81b1_0_ = 0;
    battle->groupCount = 0;
    battle->unknown_81b1_6_ = 0;
    battle->unknown_81b2_ = 0;
    for (int i = 0; i < 3; i++) {
        memset(&battle->groups[i], 0, sizeof(Struct_ov000_0215ce80_4));
    }
    for (int i = 0; i < 4; i++) {
        battle->pairs[i].c = 0;
        battle->pairs[i].a = 0;
        battle->pairs[i].b = 0;
        battle->pairs[i].d = 0;
    }
    memset(battle->unknown_8d5c_, 0, sizeof(battle->unknown_8d5c_));
    battle->unknown_8e07_ = 0;
    battle->unknown_8e04_ = -1;
    battle->unknown_8e06_ = -1;
    battle->unknown_8e4a_ = 0;
    battle->unknown_8e4c_ = 0;
    battle->unknown_8e4e_ = 0;
    battle->unknown_8e97_ = 0;
    for (int i = 0; i < 16; i++) {
        memset(&battle->entries[i], 0, sizeof(Struct_ov000_0215ce80_3));
    }
    for (int i = 0; i < 12; i++) {
        memset(&battle->records[i], 0, sizeof(Struct_ov000_0215ce80));
    }
    battle->unknown_8e94_ = 0;
    battle->unknown_8eb0_ = 1;
    InitRandom(&battle->rng, GetCurrentTimestamp(), data_ov000_021838c1, 1);
    memset(battle->unknown_8de0_, -1, sizeof(battle->unknown_8de0_));
}
