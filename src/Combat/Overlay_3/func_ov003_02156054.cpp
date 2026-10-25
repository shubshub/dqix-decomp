#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);

extern int data_ov003_0217f304[];

static inline int inline_ov003_02156054(int arg0) {
    return data_ov003_0217f304[arg0];
}

struct Struct_ov003_02156054 {
    char unknown_0_[0x20];
    int* unknown_20_;
};

// USA: func_ov003_02156054
extern "C" ARM void func_ov003_02156054(struct Struct_ov003_02156054* arg0) {
    unsigned char var0 = 0;
    for (unsigned char var1 = 1; var1 < 7; var1++) {
        arg0->unknown_20_[var0] = var1;
        var0++;
    }
    unsigned char* ctx = (unsigned char*)Scenario_GetInstance();
    for (unsigned char j = 0; data_ov003_0217f304[j] != 0; j++) {
        int id = GetId02156054(j);
        if (Scenario_TestFlag((int)ctx, ctx + 0x8c, id + 0x113f)) {
            self->entries[count] = id;
            count++;
        }
    }
}
