#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Struct_020d217c_2 {
    Struct_020d217c_2* next;   /* 0x0 */
};
struct Struct_02112780_3 {
    int unknown_0_[2];             /* 0x0,0x4 */
    Struct_020d217c_2* head;   /* 0x8 */
    Struct_020d217c_2* tail;   /* 0xc */
};
extern Struct_02112780_3 data_02112780;

// USA: func_020d248c
extern "C" ARM void func_020d248c(Struct_020d217c_2* node) {
    unsigned int mask = DisableIRQInterrupts();
    Struct_020d217c_2* tail = data_02112780.tail;
    if (tail == 0) {
        data_02112780.head = node;
        data_02112780.tail = node;
    } else {
        tail->next = node;
        data_02112780.tail = node;
    }
    node->next = 0;
    SetIRQInterruptState(mask);
}
