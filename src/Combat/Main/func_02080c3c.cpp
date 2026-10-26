#include <globaldefs.h>

struct Struct_0207fdcc_2;
struct Struct_0207fdcc { char pad[0xc5]; unsigned char flags; };
extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);

// USA: func_02080c3c
extern "C" ARM int func_02080c3c(struct Struct_0207fdcc_2* obj, int key) {
    struct Struct_0207fdcc* e = func_02081da8(obj, key);
    if (e != NULL) {
        return (e->flags & 0x20) == 0;
    }
    return 0;
}
