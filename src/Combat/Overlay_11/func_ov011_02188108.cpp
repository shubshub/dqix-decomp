#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

struct Struct_ov011_02188108 {
    char pad[0x7c];
    void (*fn)(void*, int);
};
struct Struct_ov011_02188108_2 {
    struct Struct_ov011_02188108* unknown_0_;
};
extern "C" struct Struct_ov011_02188108_2* func_ov023_021f6880(void*, int);

// USA: func_ov011_02188108
extern "C" ARM int func_ov011_02188108(struct TaggedNumber02184c30* arg0) {
    int key = func_ov011_02184c30(arg0);
    int val = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    struct Struct_ov011_02188108_2* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), key);
    if (!node) return 0;
    node->unknown_0_->fn(node, val);
    return 1;
}
