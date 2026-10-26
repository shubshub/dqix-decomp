#include <globaldefs.h>
extern "C" void* func_02053ccc(unsigned char*);
#include "GameState/GameState.h"

extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);

// USA: func_02064a40
extern "C" ARM int func_02064a40(void* param0, void* param1) {
    void* x = func_02053ccc((unsigned char*)(GameState::GetInstance()->GetProtagonist()));
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
    return Scenario_RunTrigger(param0, 9, param1);
}
