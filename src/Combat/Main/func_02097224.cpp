#include <globaldefs.h>
extern "C" int func_02096f78(unsigned char*);

struct Struct_02097054_6;
struct Struct_02097054_5;
typedef int (*Type_020971a8)(struct Struct_02097054_6*);
extern "C" struct Struct_02097054_6* func_020971a8(struct Struct_02097054_5*, int, Type_020971a8);

// USA: func_02097224
extern "C" ARM struct Struct_02097054_6* func_02097224(struct Struct_02097054_5* c, int key) {
    return func_020971a8(c, key, (Type_020971a8)func_02096f78);
}
