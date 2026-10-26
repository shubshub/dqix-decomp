#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void** list, int value);
#if defined(jpn)
#define func_ov024_021f6f10 func_ov023_021f6f10
extern "C" int func_ov024_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif

struct Struct_ov004_02158dcc { char pad[0x1b0]; unsigned short unknown_1b0_; char pad2[0x1c8-0x1b2]; int unknown_1c8_; };
extern "C" void func_ov011_021849e0(struct Struct_ov004_02158dcc* obj, unsigned short val);

// USA: func_ov011_021858f4
extern "C" ARM int func_ov011_021858f4(struct TaggedNumber02184c30* a) {
    int val = func_ov011_02184c30(a);
    void* key = func_ov017_021b2164();
    void** list = (void**)func_ov011_021849c8(key);
    void* node = func_ov023_021f6880(list, val);
    if (node == 0) return 0;
    if (func_ov024_021f6f10(node) != 7) return 0;
    func_ov011_021849e0((struct Struct_ov004_02158dcc*)key, (unsigned short)val);
    return 1;
}
