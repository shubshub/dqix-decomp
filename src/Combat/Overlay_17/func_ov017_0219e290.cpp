#include <globaldefs.h>



extern "C" int Scenario_GetInstance(int obj);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021d0924(int, int, unsigned short, int);
extern unsigned short data_ov017_021d6638[18];

// USA: func_ov017_0219e290
extern "C" ARM void func_ov017_0219e290(void* obj, unsigned short val) {
    int base = Scenario_GetInstance((int)obj);
    int idx = -1;
    for (unsigned int i = 0; i < 0x12; i++) {
        if (val == data_ov017_021d6638[i]) idx = i;
    }
    if (idx < 0) return;
    Scenario_SetFlag((void*)base, (unsigned char*)base + 0x8c, idx + 0x200, 1);
    if (LinkSession_IsHostOrSolo(LinkSession_GetInstance()) == 0) return;
    func_ov017_021d0924(1, 0, (unsigned short)idx, 1);
}
