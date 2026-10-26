#include <globaldefs.h>

struct Struct_ov031_0223d928 {
    char slotData[2][0x400];
    int slots[2];
    int task;
};

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern Struct_ov031_0223d928* data_ov031_02290d60;
extern "C" ARM int func_ov031_0223beec(int n, int base, int stride);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" ARM void func_ov031_0223d9c4(void);

// USA: func_ov031_0223d928
extern "C" ARM void func_ov031_0223d928(void) {
    void* p = func_ov031_0223cf4c(sizeof(Struct_ov031_0223d928), 4);
    data_ov031_02290d60 = (Struct_ov031_0223d928*)p;
    MIi_CpuClearFast(0x200, p, sizeof(data_ov031_02290d60->slotData));
    for (int i = 0; i < 2; i++) {
        data_ov031_02290d60->slots[i] = func_ov031_0223beec(0x40, (int)data_ov031_02290d60->slotData[i], 8);
    }
    data_ov031_02290d60->task = (int)func_ov031_0223e218((void*)1, (void*)func_ov031_0223d9c4, 0, 0xc8);
}
