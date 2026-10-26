#include <globaldefs.h>
struct Struct_0206f81c_8 { unsigned char pad[0x18]; short id; unsigned char pad2[6]; };
struct Struct_0206f81c { unsigned char pad[0x194]; struct Struct_0206f81c_8 entries[11]; };
// USA: func_02083554
extern "C" ARM struct Struct_0206f81c_8* func_02083554(struct Struct_0206f81c* c, int id) {
    int i;
    for (i = 0; i < 0xb; i++) {
        if (id == c->entries[i].id) {
            return &c->entries[i];
        }
    }
    return 0;
}
