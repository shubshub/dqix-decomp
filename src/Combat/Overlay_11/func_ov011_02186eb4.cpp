#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(TaggedNumber02184c30*);

extern "C" int func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct Struct_ov011_02186eb4 { char pad[0xc]; unsigned char flags; };
extern "C" struct Struct_ov011_02186eb4* func_ov023_021f6880(void*, int);

// USA: func_ov011_02186eb4
extern "C" ARM int func_ov011_02186eb4(TaggedNumber02184c30* a) {
    int key = func_ov011_02184c30(a);
    int val = func_ov011_02184c30((TaggedNumber02184c30*)((char*)a + 8));
    struct Struct_ov011_02186eb4* node = func_ov023_021f6880(func_ov011_021849c8((void*)func_ov017_021b2164()), key);
    if (!node) return 0;
    if (val != 0) node->flags |= 0x4;
    else node->flags &= ~0x4;
    return 1;
}
