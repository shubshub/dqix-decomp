#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

extern int data_ov003_0217f304[];

static inline int inline_ov003_02156054(int i) {
    return data_ov003_0217f304[i];
}

struct Struct_ov003_02156054 {
    char pad0[0x20];
    int* entries;
};

// USA: func_ov003_02156054
extern "C" ARM void func_ov003_02156054(struct Struct_ov003_02156054* self) {
    unsigned char count = 0;
    for (unsigned char i = 1; i < 7; i++) {
        self->entries[count] = i;
        count++;
    }
    unsigned char* ctx = (unsigned char*)Scenario_GetInstance();
    for (unsigned char j = 0; data_ov003_0217f304[j] != 0; j++) {
        int id = inline_ov003_02156054(j);
        if (Scenario_TestFlag((int)ctx, ctx + 0x8c, id + 0x113f)) {
            self->entries[count] = id;
            count++;
        }
    }
}
