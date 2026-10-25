#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);

// USA: func_ov017_02198f70
ARM void SetFieldFromHelper491_02198f70(void* unused, int val) {
    unsigned char* p = (unsigned char*)Scenario_GetInstance();
    p[0x491] = val;
}
