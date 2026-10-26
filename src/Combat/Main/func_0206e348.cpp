#include <globaldefs.h>


extern "C" short func_0206e3e8(int unused, int key);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

// USA: func_0206e348
extern "C" ARM void func_0206e348(unsigned char* obj, int index, int value) {
    int idx = func_0206e3e8((int)obj, (short)index);
    if (idx - 0x11 < 0) return;
    Scenario_SetFlag(obj, obj + 0x8c, idx + 0xbf1, value);
}
