#include <globaldefs.h>
struct Struct_020838c4 { unsigned char pad[0x454]; short slots[8]; };
// USA: func_020838c4
extern "C" ARM int func_020838c4(struct Struct_020838c4* s, int value) {
    int found;
    int i;
    int j;
    if (value < 0) {
        return 0;
    }
    found = 0;
    for (i = 0; i < 8; i++) {
        if (value == s->slots[i]) {
            s->slots[i] = -1;
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = 0; j < 7; j++) {
            if (s->slots[j] < 0) {
                s->slots[j] = s->slots[j + 1];
                s->slots[j + 1] = -1;
            }
        }
    }
    return found;
}
