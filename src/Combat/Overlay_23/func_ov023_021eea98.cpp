#include <globaldefs.h>

struct Struct_ov023_021eea98 {
    #if defined(jpn)
    char pad[0x8b8];
#else
    char pad[0x950];
#endif
    int index;
};

struct Struct_ov023_021edf54 {
    #if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Struct_ov023_021eea98* table;
};

// USA: func_ov023_021eea98
extern "C" ARM int func_ov023_021eea98(struct Struct_ov023_021edf54* o) {
    struct Struct_ov023_021eea98* t = o->table;
    return *(int*)((char*)t + (t->index * 4) + 0x138);
}
