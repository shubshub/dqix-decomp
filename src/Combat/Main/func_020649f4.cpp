#include <globaldefs.h>

extern "C" int Scenario_RunTrigger(void*, int, void*);

// USA: func_020649f4
extern "C" ARM int func_020649f4(void* a, void* b) {
    return Scenario_RunTrigger(a, 3, b);
}
