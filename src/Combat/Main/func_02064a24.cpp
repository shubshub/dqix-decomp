#include <globaldefs.h>
struct Struct_02064a08;

extern "C" int Scenario_RunTrigger(void*, int, void*);

// USA: func_02064a24
extern "C" ARM void func_02064a24(void* obj, Struct_02064a08* arg) {
    *(int*)((char*)obj + 0x498) = 0;
    Scenario_RunTrigger(obj, 0x10, (void*)arg);
}
