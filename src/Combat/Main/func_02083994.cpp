#include <globaldefs.h>
struct Struct_02083994 { unsigned char pad[0x454]; short slots[8]; };
// USA: func_02083994
extern "C" ARM int func_02083994(struct Struct_02083994* s, int value) {
    int count;
    int i;
    if (value < 0) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 8; i++) {
        short v = s->slots[i];
        if (v < 0) {
            break;
        }
        if (v == value) {
            count++;
        }
    }
    return count;
}
