#include <globaldefs.h>
struct Struct_02061c04_22 { unsigned char pad[0x454]; short slots[8]; };
// USA: func_0208386c
extern "C" ARM void func_0208386c(struct Struct_02061c04_22* s, int idx) {
    if (idx < 0) return;
    if (idx >= 8) return;
    s->slots[idx] = -1;
    for (; idx < 7; idx++) {
        s->slots[idx] = s->slots[idx + 1];
        s->slots[idx + 1] = -1;
    }
}
