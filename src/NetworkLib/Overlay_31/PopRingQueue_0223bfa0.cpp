#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int FastIntModulus(int arg0, int arg1);

struct Struct_ov031_0223bfa0 {
    unsigned short count;
    unsigned char head;
    unsigned char tail;
};

// USA: func_ov031_0223bfa0
extern "C" ARM int func_ov031_0223bfa0(struct Struct_ov031_0223bfa0* q) {
    int value = 0;
    unsigned int var1 = DisableSpecificInterrupts(1);
    if (q->head != q->tail) {
        int var2 = FastIntModulus(q->tail + q->count - 1, q->count);
        q->tail = var2;
        value = *(int*)((char*)q + q->tail * 4 + 4);
    }
    EnableSpecificInterrupts(var1);
    return value;
}
