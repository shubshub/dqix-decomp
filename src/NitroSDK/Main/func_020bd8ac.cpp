#include <globaldefs.h>

struct Struct_020bd8ac_2 { int f0; int f4; int f8; int fc; };
struct Struct_020bd8ac_3 { int unknown_0_; int unknown_4_; int count; struct Struct_020bd8ac_2 entries[1]; };
struct Struct_020bd8ac { char unknown_0_[0x84]; struct Struct_020bd8ac_3* list; };
extern struct Struct_020bd8ac* data_02110370;

// USA: func_020bd8ac
extern "C" ARM int func_020bd8ac(unsigned int index) {
    struct Struct_020bd8ac_3* list = data_02110370->list;
    if (index >= (unsigned int)list->count) return 0;
    return list->entries[index].f8;
}
