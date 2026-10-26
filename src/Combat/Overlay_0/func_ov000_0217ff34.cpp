#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0217ff34_2;
extern "C" Struct_ov000_0217ff34_2* func_0200fea4(GameState*,int);
extern "C" int MessageSystem_GetInstance();
struct Random;
Random* GetBTRandom();
int NextRandomMax(Random*,int);
struct Struct_ov000_0217ff34 {
    char p0[0x14]; unsigned int flags, unknown_18_;
    char p1[6]; unsigned short low:2, category:4, unknown_22_6_:3, unused:7;
    unsigned char mode; char p2[9]; short amount;
    char p3[0x58-0x30];
    signed int unknown_58_0_:3,unknown_58_3_:3,unknown_58_6_:3,unknown_59_1_:3,unknown_59_4_:3,unknown_59_7_:3,unknown_5a_2_:3,unknown_5a_5_:3,unknown_5b_0_:3,unknown_5b_3_:3,rest:2;
};
struct Struct_ov000_0217ff34_2 { char p[0x138]; Struct_ov000_0217ff34* details; };
// USA: func_ov000_0217ff34
extern "C" ARM int func_ov000_0217ff34(void* self,int id,int* amount) {
    int result = -1;
    GameState* gs = GameState::GetInstance();
    MessageSystem_GetInstance();
    Struct_ov000_0217ff34_2* unit = func_0200fea4(gs,id);
    if (!unit) return result;
    int special = 0;
    if (unit) {
        special = (unit->details->unknown_18_ & 0x1000) != 0;
    }
    unsigned int flags = unit->details->flags;
    unsigned char mode = unit->details->mode;
    if (special) {
        switch (NextRandomMax(GetBTRandom(),2)) {
        case 0: result = 4; break;
        case 1: result = 5; break;
        }
        *amount = unit->details->amount;
    } else if (mode) {
        switch (mode) {
        case 1: result = 0x3b; break;
        case 2: result = 0x3a; break;
        case 3: result = 0x39; break;
        case 4: result = 0x38; break;
        }
    } else if (flags & 0x400) {
        switch (unit->details->unknown_58_0_) {
        case 2: result = 0x1f; break;
        case 1: result = 0x20; break;
        case -1: result = 0x21; break;
        case -2: result = 0x22; break;
        }
    } else if (flags & 0x800) {
        switch (unit->details->unknown_58_3_) {
        case 2: result = 0x23; break;
        case 1: result = 0x24; break;
        case -1: result = 0x25; break;
        case -2: result = 0x26; break;
        }
    } else if (flags & 0x1000) {
        switch (unit->details->unknown_58_6_) {
        case 2: result = 0x27; break;
        case 1: result = 0x28; break;
        case -1: result = 0x29; break;
        case -2: result = 0x2a; break;
        }
    } else if (flags & 0x200) result = 0x15;
    else if (flags & 0x10000000) result = 0x18;
    else if (flags & 0x200000) result = 0x19;
    else if (flags & 0x10000) {
        switch (unit->details->unknown_5a_2_) {
        case 2: result = 0x30; break;
        case 1: result = 0x31; break;
        case -1: result = 0x32; break;
        case -2: result = 0x33; break;
        }
    } else if ((flags & 0x2000000) && unit->details->unknown_5b_3_ == 2) result = 0x37;
    else if (flags & 0x4000) {
        switch (unit->details->unknown_59_4_) {
        case 1: result = 0x2d; break;
        case 2: result = 0x2c; break;
        }
    } else if (flags & 0x8000) {
        switch (unit->details->unknown_59_7_) {
        case 1: result = 0x2f; break;
        case 2: result = 0x2e; break;
        }
    } else if (flags & 8) result = 6;
    else if (flags & 0x10) result = 7;
    else if (flags & 0x20) result = 8;
    else if (flags & 0x80000) {
        switch (unit->details->category) {
        case 2: result = 9; break;
        case 5: result = 10; break;
        case 3: result = 11; break;
        case 4: result = 12; break;
        case 7: result = 14; break;
        case 8: result = 15; break;
        }
    } else if (flags & 0x40) {
        switch (unit->details->unknown_22_6_) {
        case 1: result = 0x10; break;
        case 3: result = 0x11; break;
        case 2: result = 0x12; break;
        case 4: result = 0x13; break;
        }
    } else if (flags & 0x100) result = 0x14;
    else if (flags & 2) {
        switch (unit->details->low) {
        case 1: result = 0x17; break;
        case 2: result = 0x16; break;
        }
    } else if ((flags & 0x2000) && unit->details->unknown_59_1_ == 1) result = 0x2b;
    else if (flags & 0x20000) {
        switch (unit->details->unknown_5a_5_) {
        case 1: result = 0x34; break;
        case 2: result = 0x35; break;
        }
    }
    return result;
}
