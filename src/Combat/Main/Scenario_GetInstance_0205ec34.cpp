#include <globaldefs.h>


extern int g_scenario;

// Main, originally func_0205ec34 (USA 0x0205ec34, EUR 0x0205ec44, JPN 0x0205ff20)
extern "C" ARM void* Scenario_GetInstance(void) {
    return &g_scenario;
}
