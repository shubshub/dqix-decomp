#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include <GameState/GameState.h>
#include <Util/Random.h>
#include <std_library_functions.h>

struct Struct_ov000_02154a04 {
    char pad0[8];
    unsigned int field8 : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 22;
    char pad1[8];
    unsigned int field14 : 28;
    unsigned int selection : 4;
    int field18;
    unsigned int field1c : 14;
    unsigned int unknown_1d_6_ : 5;
    unsigned int unknown_1e_3_ : 13;
};
struct Struct_ov000_02154a04_2 { char pad[0x17c]; unsigned char group; };

extern "C" void* func_02079e2c(char*, int);
extern "C" int func_ov000_0215e9fc(Random*, short*, int, int);
extern "C" short func_ov000_02154f30(Random*, short, int, short*);
extern "C" void func_ov000_02153d10(Random*, short*);
extern "C" void func_ov000_02153d78(Random*, short, short*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" int func_ov000_02153e78(Random*, short*, int, int, int);
extern "C" int func_ov000_0215eb1c(Random*, short*, int, int);
extern "C" signed char func_ov000_0215fbe0(Random*, int);
extern short data_ov000_02182af4[8];

// USA: func_ov000_02154a04
extern "C" ARM int func_ov000_02154a04(Random* arg0, int combatantId, int arg2, short* targets) {
    int count = 0;
    GameState::GetInstance();
    Struct_ov000_02154a04* definition = (Struct_ov000_02154a04*)func_02079e2c((char*)func_020797dc(), (short)arg2);
    if (!definition) return 0;
    unsigned int var2 = definition->unknown_9_0_;
    unsigned int selection = definition->selection;
    if (selection == 1) {
        targets[count++] = combatantId;
    } else if (var2 == 1) {
        if (selection == 2 || selection == 5) {
            int available = func_ov000_0215e9fc(arg0, targets, 8, 1);
            targets[0] = func_ov000_02154f30(arg0, (short)combatantId, available, targets);
            count = 1;
        } else if (selection == 4) {
            count = func_ov000_0215e9fc(arg0, targets, 8, 1);
        } else if (selection == 3) {
            count = func_ov000_0215e9fc(arg0, targets, 8, 1);
        }
    } else if (var2 == 2) {
        if (selection == 2) {
            short var5 = 0;
            func_ov000_02153d10(arg0, &var5);
            targets[count++] = var5;
        } else if (selection == 8) {
            short var6 = 0;
            func_ov000_02153d78(arg0, (short)combatantId, &var6);
            targets[count++] = var6;
        } else if (selection == 4) {
            GameObject* combatant = func_0200fea4(GameState::GetInstance(), (short)combatantId);
            count = func_ov000_02153e78(arg0, targets, 8, ((Struct_ov000_02154a04_2*)combatant)->group, 1);
        } else if (selection == 3) {
            count = func_ov000_0215eb1c(arg0, targets, 8, 1);
        }
    }
    short selected[8];
    unsigned short* source = (unsigned short*)data_ov000_02182af4;
    int var10 = 8;
    unsigned short* destination = (unsigned short*)selected;
    do { *destination = *source++; destination++; } while (--var10);
    short* var12 = selected;
    int var13 = func_ov000_0215fbe0(arg0, (signed char)definition->unknown_1d_6_);
    if (var13 > 0) {
        for (int i = 0; i < var13; i++) var12[i] = targets[NextRandomMax(arg0, count)];
        memset(targets, 0, count * 2);
        memcpy(targets, selected, var13 * 2);
        count = var13;
    }
    return count;
}
