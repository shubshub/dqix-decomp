#include <globaldefs.h>
struct Desc021b790c;

int Scenario_RunTrigger(void*, int, void*);

// USA: func_02064a24
ARM void ClearField0x498Dispatch10_02064a24(void* obj, Desc021b790c* arg) {
    *(int*)((char*)obj + 0x498) = 0;
    Scenario_RunTrigger(obj, 0x10, (void*)arg);
}
