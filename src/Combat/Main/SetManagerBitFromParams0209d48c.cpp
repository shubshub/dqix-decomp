#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void*);
extern "C" int func_ov017_021d60f4(void*);
void SetBitWithOffset0206eb64(unsigned char*, int, int);

// USA: func_0209d48c
ARM int SetManagerBitFromParams0209d48c(void* arg) {
    void* mgr = Scenario_GetInstance(arg);
    if (mgr == NULL) return 0;
    int bit = func_ov017_021d60f4(arg);
    int value = func_ov017_021d60f4((char*)arg + 8);
    SetBitWithOffset0206eb64((unsigned char*)mgr, bit, value);
    return 1;
}
