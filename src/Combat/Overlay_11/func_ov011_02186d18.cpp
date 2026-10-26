#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void* list, int value);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" void func_ov023_021f9c60(void* obj, unsigned short v);

// USA: func_ov011_02186d18
extern "C" ARM int func_ov011_02186d18(struct TaggedNumber02184c30* a) {
    int val = func_ov011_02184c30(a);
    int val2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    void* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), val);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 7) return 0;
    func_ov023_021f9c60(node, (unsigned short)val2);
    return 1;
}
