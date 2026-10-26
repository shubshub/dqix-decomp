#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov011_02184a0c(void*, unsigned short);

// USA: func_ov011_02185948
extern "C" ARM int func_ov011_02185948(struct TaggedNumber02184c30* arg0) {
    int key = func_ov011_02184c30(arg0);
    void* base = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(base);
    void* node = func_ov023_021f6880(obj, key);
    if (!node) return 0;
    func_ov011_02184a0c(base, (unsigned short)key);
    return 1;
}
