#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_020aea40(unsigned char index, unsigned char isSet);
extern unsigned short data_020e9138[];

// USA: func_020ae9f0
ARM void SyncEightElementFlags_020ae9f0(void) {
    unsigned char* obj = (unsigned char*)Scenario_GetInstance();
    int i;
    for (i = 0; i < 8; i++) {
        int isSet = Scenario_TestFlag((int)obj, obj + 0x8c, data_020e9138[i]);
        func_020aea40(i, isSet);
    }
}
