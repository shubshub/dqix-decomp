#include <globaldefs.h>

struct Struct_0209afd4_5 { unsigned short id; char pad[0x4a]; };

// USA: func_0209b9e4
extern "C" ARM struct Struct_0209afd4_5* func_0209b9e4(struct Struct_0209afd4_5 *base, int key) {
    int i;
    for (i = 0; i < 6; i++) {
        if (key == base[i].id) return &base[i];
    }
    return NULL;
}
