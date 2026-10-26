#include <globaldefs.h>
#include "Combat/SearchEntry.h"

extern "C" ARM void VCountIrq_PushDisable(void);
extern "C" void VCountIrq_PopDisable(void);

struct Struct_0202ba08_2;
extern "C" ARM struct Struct_0202ba08_2* func_0202ba08(struct Struct_0202ba08_2* dst, struct Struct_0202ba08_2* src);

// Main, originally ShiftRecords0202c478 (USA 0x0202c478, EUR 0x0202c488, JPN 0x0202c004)
extern "C" ARM void LinkSession_AgeScanResults(SearchStruct* obj) {
    VCountIrq_PushDisable();
    char* base = (char*)obj;
    int i;
    for (i = 0; i < *(int*)(base + 0xc); i++) {
        ((int*)(base + 0x790))[i] -= 0x10;
        if (((int*)(base + 0x790))[i] > 0) {
            continue;
        }
        int j;
        for (j = i; j < *(int*)(base + 0xc) - 1; j++) {
            func_0202ba08((struct Struct_0202ba08_2*)(base + 0x10 + j * 0xc0),
                                (struct Struct_0202ba08_2*)(base + 0x10 + (j + 1) * 0xc0));
        }
        (*(int*)(base + 0xc))--;
    }
    VCountIrq_PopDisable();
}
