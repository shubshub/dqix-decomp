#include <globaldefs.h>
struct Struct_0207d300 { unsigned char pad[0x454]; short slots[8]; };
// USA: func_02083960
extern "C" ARM int func_02083960(struct Struct_0207d300* s) {
    int count = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (s->slots[i] > 0) {
            count++;
        }
    }
    return count;
}
