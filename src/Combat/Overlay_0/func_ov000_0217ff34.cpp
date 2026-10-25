#include <globaldefs.h>
#include "GameState/GameState.h"

struct Unit0217ff34;
Unit0217ff34* GetCombatantWithFlag0x400_0200fea4(GameState*,int);
int MessageSystem_GetInstance();
struct Random;
Random* GetBTRandom();
int NextRandomMax(Random*,int);
struct Struct_ov000_0217ff34 {
    char unknown_0_[0x14]; unsigned int unknown_14_, unknown_18_;
    char unknown_1c_[6]; unsigned short unknown_22_0_:2, unknown_22_2_:4, unknown_22_6_:3, unknown_23_1_:7;
    unsigned char unknown_24_; char unknown_25_[9]; short unknown_2e_;
    char unknown_30_[0x58-0x30];
    signed int unknown_58_0_:3,unknown_58_3_:3,unknown_58_6_:3,unknown_59_1_:3,unknown_59_4_:3,unknown_59_7_:3,unknown_5a_2_:3,unknown_5a_5_:3,unknown_5b_0_:3,unknown_5b_3_:3,unknown_5b_6_:2;
};
struct Struct_ov000_0217ff34_2 { char unknown_0_[0x138]; Struct_ov000_0217ff34* unknown_138_; };
// USA: func_ov000_0217ff34
extern "C" ARM int func_ov000_0217ff34(void* self,int id,int* amount) {
    int result = -1;
    GameState* gs = GameState::GetInstance();
    MessageSystem_GetInstance();
    Unit0217ff34* unit = GetCombatantWithFlag0x400_0200fea4(gs,id);
    if (!unit) return result;
    int special = 0;
    if (unit) {
        special = (unit->details->flags18 & 0x1000) != 0;
    }
    unsigned int var4 = var2->unknown_138_->unknown_14_;
    unsigned char var5 = var2->unknown_138_->unknown_24_;
    if (var3) {
        switch (NextRandomMax(GetBTRandom(),2)) {
        case 0: var0 = 4; break;
        case 1: var0 = 5; break;
        }
        *arg2 = var2->unknown_138_->unknown_2e_;
    } else if (var5) {
        switch (var5) {
        case 1: var0 = 0x3b; break;
        case 2: var0 = 0x3a; break;
        case 3: var0 = 0x39; break;
        case 4: var0 = 0x38; break;
        }
    } else if (var4 & 0x400) {
        switch (var2->unknown_138_->unknown_58_0_) {
        case 2: var0 = 0x1f; break;
        case 1: var0 = 0x20; break;
        case -1: var0 = 0x21; break;
        case -2: var0 = 0x22; break;
        }
    } else if (var4 & 0x800) {
        switch (var2->unknown_138_->unknown_58_3_) {
        case 2: var0 = 0x23; break;
        case 1: var0 = 0x24; break;
        case -1: var0 = 0x25; break;
        case -2: var0 = 0x26; break;
        }
    } else if (var4 & 0x1000) {
        switch (var2->unknown_138_->unknown_58_6_) {
        case 2: var0 = 0x27; break;
        case 1: var0 = 0x28; break;
        case -1: var0 = 0x29; break;
        case -2: var0 = 0x2a; break;
        }
    } else if (var4 & 0x200) var0 = 0x15;
    else if (var4 & 0x10000000) var0 = 0x18;
    else if (var4 & 0x200000) var0 = 0x19;
    else if (var4 & 0x10000) {
        switch (var2->unknown_138_->unknown_5a_2_) {
        case 2: var0 = 0x30; break;
        case 1: var0 = 0x31; break;
        case -1: var0 = 0x32; break;
        case -2: var0 = 0x33; break;
        }
    } else if ((var4 & 0x2000000) && var2->unknown_138_->unknown_5b_3_ == 2) var0 = 0x37;
    else if (var4 & 0x4000) {
        switch (var2->unknown_138_->unknown_59_4_) {
        case 1: var0 = 0x2d; break;
        case 2: var0 = 0x2c; break;
        }
    } else if (var4 & 0x8000) {
        switch (var2->unknown_138_->unknown_59_7_) {
        case 1: var0 = 0x2f; break;
        case 2: var0 = 0x2e; break;
        }
    } else if (var4 & 8) var0 = 6;
    else if (var4 & 0x10) var0 = 7;
    else if (var4 & 0x20) var0 = 8;
    else if (var4 & 0x80000) {
        switch (var2->unknown_138_->unknown_22_2_) {
        case 2: var0 = 9; break;
        case 5: var0 = 10; break;
        case 3: var0 = 11; break;
        case 4: var0 = 12; break;
        case 7: var0 = 14; break;
        case 8: var0 = 15; break;
        }
    } else if (var4 & 0x40) {
        switch (var2->unknown_138_->unknown_22_6_) {
        case 1: var0 = 0x10; break;
        case 3: var0 = 0x11; break;
        case 2: var0 = 0x12; break;
        case 4: var0 = 0x13; break;
        }
    } else if (var4 & 0x100) var0 = 0x14;
    else if (var4 & 2) {
        switch (var2->unknown_138_->unknown_22_0_) {
        case 1: var0 = 0x17; break;
        case 2: var0 = 0x16; break;
        }
    } else if ((var4 & 0x2000) && var2->unknown_138_->unknown_59_1_ == 1) var0 = 0x2b;
    else if (var4 & 0x20000) {
        switch (var2->unknown_138_->unknown_5a_5_) {
        case 1: var0 = 0x34; break;
        case 2: var0 = 0x35; break;
        }
    }
    return var0;
}
