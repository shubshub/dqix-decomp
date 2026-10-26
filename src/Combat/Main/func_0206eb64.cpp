#include <globaldefs.h>


extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

// USA: func_0206eb64
extern "C" ARM void func_0206eb64(unsigned char* obj, int bit, int value) {
    if (bit >= 0x400) {
        Scenario_SetFlag(obj, obj + 0x8c, bit + 0x6fa, value);
        return;
    }
    Scenario_SetFlag(obj, obj + 0x8c, bit, value);
}
