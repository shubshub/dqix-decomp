#include <globaldefs.h>

extern int Scenario_TestFlag(int unused, unsigned char* arr, int index);

// USA: func_0206eb98
ARM int TestBitWithBias0206eb98(unsigned char* obj, int index) {
    int i = index;
    if (i >= 0x400) {
        return Scenario_TestFlag((int)obj, obj + 0x8c, i + 0x6fa);
    }
    return Scenario_TestFlag((int)obj, obj + 0x8c, i);
}
