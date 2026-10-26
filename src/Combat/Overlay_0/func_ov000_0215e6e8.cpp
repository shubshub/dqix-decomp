#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatStats {
    char pad0[0x21];
    unsigned char unknown_21_;
};

struct Struct_ov000_0215ab88 {
    char pad0[0x138];
    CombatStats* stats;
    char unknown_13c_[0x184 - 0x13c];
    unsigned char busy;
};

struct Struct_ov000_0215767c_2 {
    char pad0[0x81b1];
    unsigned char unknown_81b1_0_ : 4;
    unsigned char groupCount : 2;
    char unknown_81b2_[0x8e14 - 0x81b2];
    signed char result;
    char unknown_8e15_[0x8e20 - 0x8e15];
    int unknown_8e20_;
};

struct Struct_ov000_02182c74 { short v[16]; };
struct Struct_ov000_02182b04 { short v[8]; };

extern Struct_ov000_02182c74 data_ov000_02182cf4;
extern Struct_ov000_02182b04 data_ov000_02182bc4;

struct GameState;
extern "C" Struct_ov000_0215ab88* func_0200fea4(GameState*, int);
extern "C" void func_020488ac(unsigned char*, int);
extern "C" void func_020488cc(unsigned char*, int);
extern "C" void func_0208979c(unsigned char*);
extern "C" int func_ov000_0215fc60(char*);
extern "C" int func_ov000_02153e40(Struct_ov000_0215767c_2* battle, short* buf, int max, int start);
extern "C" int func_ov000_0215e9fc(Struct_ov000_0215767c_2* battle, short* buf, int max, int start);
extern "C" void func_ov000_0215a23c(Struct_ov000_0215767c_2* battle);
extern "C" void func_ov000_02157e1c(Struct_ov000_0215767c_2* battle);
extern "C" void func_ov000_02155e94(Struct_ov000_0215767c_2* battle);

// USA: func_ov000_0215e6e8
extern "C" ARM void func_ov000_0215e6e8(Struct_ov000_0215767c_2* battle) {
    int count;
    Struct_ov000_02182c74 ids = data_ov000_02182cf4;
    if (battle->result == 0) {
        count = func_ov000_02153e40(battle, ids.v, 0x10, 1);
        for (int i = 0; i < count; i++) {
            int id = ids.v[i];
            void* gs = GameState::GetInstance();
            Struct_ov000_0215ab88* c = (Struct_ov000_0215ab88*)((GameState*)gs)->GetCombatantByIndex(id);
            if (c != NULL) {
                int var6 = 0;
                int id2 = ids.v[i];
                if (id2 >= 0) {
                    if (id2 <= 3) {
                        var6 = 1;
                    }
                }
                if (var6 == 0) {
                    Struct_ov000_0215ab88* other = func_0200fea4((GameState*)GameState::GetInstance(), id2);
                    if (other != NULL) {
                        other->busy = 0;
                        func_020488ac((unsigned char*)other, 0);
                        func_020488cc((unsigned char*)other, 0);
                    }
                }
                func_0208979c((unsigned char*)c->stats);
                c->stats->unknown_21_ = 0;
            }
        }
        func_ov000_0215a23c(battle);
        if (battle->result == 0) {
            func_ov000_02157e1c(battle);
        }
        func_ov000_02155e94(battle);
        Struct_ov000_02182b04 targets = data_ov000_02182bc4;
        if (func_ov000_0215e9fc(battle, targets.v, 8, 9) <= 0) {
            battle->result = 2;
        } else if (battle->unknown_81b1_0_ == 0) {
            battle->result = 1;
        }
    }
    if (func_ov000_0215fc60((char*)battle) != 0) {
        battle->result = 0;
    }
    battle->unknown_8e20_++;
    if (battle->result != 0) {
        count = func_ov000_0215e9fc(battle, ids.v, 0x10, 0);
        void* gs = GameState::GetInstance();
        for (int i = 0; i < count; i++) {
            (Struct_ov000_0215ab88*)func_0200ff1c((GameState*)gs, ids.v[i]);
        }
    }
}
