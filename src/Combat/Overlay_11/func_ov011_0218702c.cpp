#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void* obj, int key);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#define func_ov024_021f6f10 func_ov023_021f6f10
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif

struct Struct_ov011_0218702c {
    char pad0[0x42];
    unsigned short unknown_42_;
    char pad1[1];
    unsigned char bit0:1;
    unsigned char unknown_45_1_:R(7, 6);
#if !defined(jpn)
    unsigned char unknown_45_7_:1;
#endif
};

// USA: func_ov011_0218702c
extern "C" ARM int func_ov011_0218702c(struct TaggedNumber02184c30* a) {
    int v0 = func_ov011_02184c30(a);
    int v1 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    int v2 = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x10));
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(ctx);
    struct Struct_ov011_0218702c* node = (struct Struct_ov011_0218702c*)func_ov023_021f6880(obj, v0);
    if (!node) return 0;
    if (func_ov024_021f6f10(node) != 8) return 0;
    node->unknown_45_1_ = v1;
    node->unknown_42_ = (unsigned short)v2;
    return 1;
}
