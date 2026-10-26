#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov004_021589e8 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int top : 6;
};

struct Struct_ov031_02243e34 {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int unknown_c_;
};

struct Struct_ov031_02243e34_2 {
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};

struct Struct_01ff8b48_18 {
    short id;
    unsigned short unknown_2_;
    unsigned int value : 7;
    unsigned int unknown_4_7_ : 25;
    unsigned char unknown_8_[0x20];
};

struct Struct_ov004_0215c900 {
    short unknown_0_;
    unsigned short unknown_2_;
    Struct_01ff8b48_18 entries[6];
    Struct_ov004_021589e8 start;
    short itemId;
    unsigned short unknown_fa_;
    unsigned short unknown_fc_;
    unsigned short unknown_fe_;
    Struct_ov004_021589e8 end;
    Struct_ov004_021589e8 unknown_104_;
    unsigned int unknown_108_;
    unsigned short flags : 13;
    unsigned short unknown_10d_5_ : 3;
    unsigned short unknown_10e_;
};

struct Struct_02245528;
extern "C" void func_ov031_022125c8();
extern "C" int func_ov031_0221268c();
extern "C" void func_ov031_022120f8();
extern "C" void func_ov031_02245528(Struct_02245528*, int);
extern "C" int func_ov031_0221244c(void*, void*);
extern "C" int func_ov017_021b2090(Struct_ov004_021589e8, Struct_ov004_021589e8);
extern "C" void func_ov031_02212784();
extern "C" void func_ov031_02245478(Struct_02245528*);

#if defined(jpn)
extern "C" void func_ov031_02211c50(int);
extern unsigned char data_ov031_0224a1b4[];
#endif

// USA: func_ov031_02243e34
extern "C" ARM void func_ov031_02243e34(void* object) {
    unsigned char* state = (unsigned char*)object;
    switch (state[0x35]) {
    case 0:
#if defined(jpn)
        func_ov031_02211c50(2);
#endif
        state[0x35] = 4;
        break;
    case 4:
        func_ov031_022125c8();
        state[0x35] = 5;
        break;
    case 5: {
        int result = func_ov031_0221268c();
        if (result == 3) state[0x35] = 6;
        else if (result == 4) state[0x35] = 8;
        else if (result == 5 || result == 0) {
            func_ov031_022120f8();
            func_ov031_02245528((Struct_02245528*)object, 0);
        }
        int& timer = *(int*)(state + 0x384);
        if (timer < 0x46000) timer += 0x333;
        break;
    }
    case 6: {
        Struct_ov031_02243e34 date;
        Struct_ov031_02243e34_2 time;
        if (func_ov031_0221244c(&date, &time)) {
            date.year += 2000;
#if defined(jpn)
            time.hours += 9;
            if (time.hours >= 24) {
                time.hours -= 24;
                ++date.day;
                unsigned int var5 = *(const unsigned int*)(data_ov031_0224a1b4 + date.month * sizeof(unsigned int));
                if (var5 < date.day) {
                    date.day = 1;
                    if (++date.month > 12) {
                        date.month = 1;
                        ++date.year;
                    }
                }
            }
#endif
            Struct_ov004_021589e8& var6 = *(Struct_ov004_021589e8*)(state + 0x378);
            var6.low = date.year;
            var6.f12 = date.month;
            var6.unknown_2_0_ = date.day;
            var6.unknown_2_5_ = time.hours;
            var6.top = time.minutes;
            state[0x44] |= 4;
            if (state[0x374] & 0x10) {
#if defined(jpn)
                Struct_ov004_0215c900* downloaded = (Struct_ov004_0215c900*)((char*)GameState::GetInstance() + 0x5c0c);
#else
                Struct_ov004_0215c900* downloaded = (Struct_ov004_0215c900*)((char*)GameState::GetInstance() + 0x5e6c);
#endif
                bool var8 = func_ov017_021b2090(downloaded->unknown_104_, var6) != 0;
                if (!var8) {
                    state[0x44] |= 0x80;
                    state[0x374] &= ~1;
                }
            }
        } else state[0x374] &= ~1;
        if (state[0x374] & 0x80) state[0x35] = 7;
        else if (state[0x374] & 2) {
            state[0x3d0] = 1;
            func_ov031_02245528((Struct_02245528*)object, 5);
        } else if (!(state[0x374] & 1)) state[0x35] = 7;
        else func_ov031_02245528((Struct_02245528*)object, 4);
        break;
    }
    case 7:
        func_ov031_02212784();
        state[0x35] = 5;
        break;
    case 8:
        func_ov031_02245478((Struct_02245528*)object);
        func_ov031_022120f8();
        break;
    }
}
