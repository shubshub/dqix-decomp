#include <globaldefs.h>

struct Struct_020bd79c_2 { int f0; int f4; int f8; int fc; };
struct Struct_020bd79c_3 { int unknown_0_; int unknown_4_; int count; struct Struct_020bd79c_2 entries[1]; };
struct Struct_020bd79c { char unknown_0_[0x84]; struct Struct_020bd79c_3* list; };
extern struct Struct_020bd79c* data_02110370;

// USA: func_020bd79c
extern "C" ARM int func_020bd79c(unsigned int index) {
    struct Struct_020bd79c_3* list = data_02110370->list;
    if (index >= (unsigned int)list->count) return 0;
    return list->entries[index].f4;
}
