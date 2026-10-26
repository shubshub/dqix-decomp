#include <globaldefs.h>

extern "C" int Scenario_TestFlag(int, unsigned char*, int);

// USA: func_0206e384
extern "C" ARM unsigned short func_0206e384(unsigned char* obj) {
    unsigned short result = 0;
    int i;
    for (i = 0; i < 16; i++) {
        if (Scenario_TestFlag((int)obj, obj + 0x8c, i + 0xc02)) {
            result |= (1 << i);
        }
    }
    return result;
}
