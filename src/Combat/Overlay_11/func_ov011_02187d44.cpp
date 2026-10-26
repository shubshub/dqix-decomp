#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov023_021f9da0(void* obj, unsigned char v);

// USA: func_ov011_02187d44
extern "C" ARM int func_ov011_02187d44(struct TaggedNumber02184c30* arg0) {
    int key = func_ov011_02184c30(arg0);
    int val = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    void* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), key);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;
    func_ov023_021f9da0(node, val != 0);
    return 1;
}
