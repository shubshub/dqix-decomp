#include <globaldefs.h>

struct Struct_020bd8d4_2 { int f0; int f4; int f8; int fc; };
struct Struct_020bd8d4_3 { int unknown_0_; int unknown_4_; int count; struct Struct_020bd8d4_2 entries[1]; };
struct Struct_020bd8d4 { char unknown_0_[0x84]; struct Struct_020bd8d4_3* list; };
extern struct Struct_020bd8d4* data_02110370;

// USA: func_020bd8d4
extern "C" ARM void func_020bd8d4(unsigned int index, int value) {
    data_02110370->list->entries[index].f8 = value;
}
