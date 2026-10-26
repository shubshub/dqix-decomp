#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(TaggedNumber02184c30*);
struct Struct_ov011_02184c4c;
extern "C" float func_ov011_02184c4c(Struct_ov011_02184c4c*);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct Struct_ov011_02186650 { char pad[0xc8]; void (*fn)(void*, int*); };
struct Struct_ov011_02186650_2 { struct Struct_ov011_02186650* unknown_0_; };
extern "C" struct Struct_ov011_02186650_2* func_ov023_021f6880(void*, int);

// USA: func_ov011_02186650
extern "C" ARM int func_ov011_02186650(TaggedNumber02184c30* a) {
    int key = func_ov011_02184c30(a);
    int args[3];
    args[0] = (int)(4096.0f * func_ov011_02184c4c((Struct_ov011_02184c4c*)((char*)a + 8)));
    args[1] = (int)(4096.0f * func_ov011_02184c4c((Struct_ov011_02184c4c*)((char*)a + 0x10)));
    args[2] = 0;
    struct Struct_ov011_02186650_2* node = func_ov023_021f6880(func_ov011_021849c8((void*)func_ov017_021b2164()), key);
    if (!node) return 0;
    node->unknown_0_->fn(node, args);
    return 1;
}
