#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02053ccc(unsigned char*);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);

// USA: func_02064a9c
extern "C" ARM int func_02064a9c(void* param0, void* param1) {
    void* x = func_02053ccc((unsigned char*)(GameState::GetInstance()->GetLeader()));
    if (x != NULL) {
        if (*(int*)((char*)x + 4) == 3) {
            *(int*)((char*)param1 + 4) = *(unsigned char*)((char*)x + 0x2c);
        }
    } else {
        signed char b = *(signed char*)((char*)param0 + 0x491);
        if (b > -1) {
            *(int*)((char*)param1 + 4) = b;
        }
    }
    return Scenario_RunTrigger(param0, 0x13, param1);
}
