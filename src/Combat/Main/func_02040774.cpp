#include <globaldefs.h>

struct Fields020407b4;
extern "C" void func_020407b4(struct Fields020407b4* dst, int a, int b, int c);

struct Struct_02040774 {
    char pad4[4];
    int a;
    int b;
    int c;
};
struct Struct_0203d028_15 {
    char pad[0x14];
    struct Struct_02040774* f14;
    void* f18;
    void* f1c;
};

// USA: func_02040774
extern "C" ARM void func_02040774(struct Struct_0203d028_15* obj, int a, int b, int c) {
    struct Struct_02040774* p = obj->f14;
    if (p != NULL) {
        p->a = a;
        p->b = b;
        p->c = c;
        return;
    }
    if (obj->f18 != NULL) {
        func_020407b4((struct Fields020407b4*)obj->f18, a, b, c);
        return;
    }
    if (obj->f1c != NULL) {
        func_020407b4((struct Fields020407b4*)obj->f1c, a, b, c);
    }
}
