#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(TaggedNumber02184c30*);

extern "C" int func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct Struct_ov011_02188284 {
    char pad[0xa4];
    void (*fn)(void*, int);
};
struct Struct_ov011_02188284_2 {
    struct Struct_ov011_02188284* unknown_0_;
};
extern "C" struct Struct_ov011_02188284_2* func_ov023_021f6880(void*, int);

// USA: func_ov011_02188284
extern "C" ARM int func_ov011_02188284(TaggedNumber02184c30* a) {
    int key = func_ov011_02184c30(a);
    int val = func_ov011_02184c30((TaggedNumber02184c30*)((char*)a + 8));
    struct Struct_ov011_02188284_2* node = func_ov023_021f6880(func_ov011_021849c8((void*)func_ov017_021b2164()), key);
    if (!node) return 0;
    node->unknown_0_->fn(node, val);
    return 1;
}
