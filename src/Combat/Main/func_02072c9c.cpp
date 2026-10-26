#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void func_02052d7c(void* combatant, int arg1, int arg2);
extern "C" void func_02072afc(int id, void* out1, void* out2);
extern "C" int func_02053c6c(unsigned char* obj);
extern char data_020f0cf4[];

struct Struct_02072c9c {
    void* ptr;
    char pad[0x14];
    short flag;
};

// USA: func_02072c9c
extern "C" ARM void func_02072c9c(int combatantId, char* buf) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == NULL) {
        return;
    }
    int fieldVal = func_02053c6c((unsigned char*)combatant);
    if (fieldVal == 0) {
        return;
    }
    char* table = (char*)fieldVal;

    char local1[0x2c];
    char var4[0x18];
    func_02072afc(combatantId, local1, var4);

    struct Struct_02072c9c* var5 = (struct Struct_02072c9c*)(table + 0x294);
    struct Struct_02072c9c* var6 = (struct Struct_02072c9c*)(table + 0x194);
    if (var6 == NULL) {
        func_02052d7c(combatant, 0, -1);
        func_02072afc(combatantId, local1, var4);
        var6 = (struct Struct_02072c9c*)(table + 0x194);
    }

    unsigned int* var7 = *(unsigned int**)var6;
    unsigned int val1 = (var7[1] << 12) >> 24;
    unsigned int val2 = 0;
    if (var5->flag >= 0) {
        if (var5 != NULL) {
            unsigned int* var10 = *(unsigned int**)var5;
            val2 = (var10[1] << 12) >> 24;
        }
    }
    sprintf(buf, data_020f0cf4, val1, val2);
}
