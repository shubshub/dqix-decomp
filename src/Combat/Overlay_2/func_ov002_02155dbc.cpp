#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_02155dbc func_ov002_021574fc
#endif

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
struct Struct_020e28dc;
struct Struct_020e2794_2;
#if defined(jpn)
extern "C" void func_ov023_021e7868(void *p);
#else
extern "C" void func_ov023_021e761c(void *p);
#endif
extern "C" void func_ov023_021eb4b8(void *p);
extern "C" void func_ov013_02184a58(void *p);
extern "C" void Window_ClearLayers(struct Cont0205d1e0 *c);
extern "C" void Window_DrawPanes(struct Cont0205d228 *c);
extern "C" void Window_FlushLayers(struct Cont0205d274 *c);
extern "C" int func_020e28dc(struct Struct_020e28dc *o);
extern "C" void func_020e2794(struct Struct_020e2794_2 *s, void *p);
extern "C" void func_0205da88(void *c, int a, int b, int d);
extern "C" void func_ov002_0215aaa4(void *base);
#if !defined(jpn)
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);
#endif
#if !defined(jpn)
extern "C" void func_ov002_021619b4(int a, int b, int c);
#endif
extern "C" void func_ov002_0215ab60(void *base);
extern "C" void func_ov002_0215ad70(void *base);
extern "C" void func_ov002_0215afb8(void *base);
extern "C" void func_ov002_0215b0a8(void *base);
extern "C" void func_ov002_0215b138(void *base);

// USA: func_ov002_02155dbc
extern "C" ARM void func_ov002_02155dbc(char *base) {
    if (*(unsigned char *) (base + 0x1000 + LOW_REGION(0xb87, 0xcc3)) != 0) {
#if defined(jpn)
        func_ov023_021e7868(base + 0x18 + 0x800);
#else
        func_ov023_021e761c(base + 0xb4 + 0x800);
#endif
    }
    if (*(void **) (base + 0x2000 + LOW_REGION(0x298, 0x468)) != NULL) {
        func_ov023_021eb4b8(*(void **) (base + 0x2000 + LOW_REGION(0x298, 0x468)));
    }
    if (*(int *) (base + 0x1000 + LOW_REGION(0xa80, 0xbb8)) == LOW_REGION(0x1f, 0x1e) && *(int *) (base + 0x1000 + LOW_REGION(0xa88, 0xbc0)) > 4) {
        func_ov013_02184a58(base + LOW_REGION(0xc20, 0xd70) + 0x1000);
    } else {
        char *list = base + LOW_REGION(0x220, 0x2c8);
        Window_ClearLayers((struct Cont0205d1e0 *) (list + 0xc00));
        Window_DrawPanes((struct Cont0205d228 *) (list + 0xc00));
        func_0205da88(list + 0xc00, 1, 2, 1);
        func_0205da88(list + 0xc00, 1, 3, 1);
        func_0205da88(list + 0xc00, 2, 3, 0);
        Window_FlushLayers((struct Cont0205d274 *) (list + 0xc00));
        func_ov002_0215aaa4(base);
#if !defined(jpn)
        if (*(unsigned char *) (base + 0x1000 + 0xc34) != 0) {
            func_ov002_0215b9a4(base, 0x1b, 0);
            func_ov002_0215b9a4(base, 0x1a, 0);
            func_ov002_021619b4(*(signed char *) (base + 0x1c00 + 0x20), *(int *) (base + 0x1000 + LOW_REGION(0x9c0, 0xa68)),
                                *(int *) (base + 0x1000 + 0xbd8));
            *(unsigned char *) (base + 0x1000 + 0xc34) = 0;
        }

#endif
        func_ov002_0215ab60(base);
        func_ov002_0215ad70(base);
        func_ov002_0215afb8(base);
        func_ov002_0215b0a8(base);
        func_ov002_0215b138(base);
    }
    if (*(struct Struct_020e28dc **) base != NULL && func_020e28dc(*(struct Struct_020e28dc **) base)) {
        func_020e2794(*(struct Struct_020e2794_2 **) base, NULL);
    }
    if (*(struct Struct_020e28dc **) (base + 4) != NULL && func_020e28dc(*(struct Struct_020e28dc **) (base + 4))) {
        func_020e2794(*(struct Struct_020e2794_2 **) (base + 4), *(void **) (base + 0x1000 + LOW_REGION(0x9c0, 0xa68)));
    }
}
