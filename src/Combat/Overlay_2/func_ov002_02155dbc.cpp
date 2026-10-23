#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_02155dbc func_ov002_021574fc
#endif

struct Struct_0205d1e0;
struct Struct_0205d228;
struct Struct_0205d274;
struct Struct_020e28dc;
struct Struct_020e2794_2;
#if defined(jpn)
extern "C" void func_ov023_021e7868(void *arg0);
#else
extern "C" void func_ov023_021e761c(void *arg0);
#endif
void InitBuffersIfFlag431_021eb4b8(void *p);
void ResetCombatEntry02184a58(void *p);
void Window_ClearLayers(struct Cont0205d1e0 *c);
void Window_DrawPanes(struct Cont0205d228 *c);
void Window_FlushLayers(struct Cont0205d274 *c);
int GetInnerFlagBit0020e28dc(struct Outer020e28dc *o);
void UpdateEntryIfActive020e2794(struct Struct020e2794 *s, void *p);
extern "C" void func_0205da88(void *c, int a, int b, int d);
extern "C" void func_ov002_0215aaa4(void *base);
#if !defined(jpn)
extern "C" void func_ov002_0215b9a4(void *arg0, int arg1, int arg2);
#endif
#if !defined(jpn)
extern "C" void func_ov002_021619b4(int arg0, int arg1, int arg2);
#endif
extern "C" void func_ov002_0215ab60(void *arg0);
extern "C" void func_ov002_0215ad70(void *arg0);
extern "C" void func_ov002_0215afb8(void *arg0);
extern "C" void func_ov002_0215b0a8(void *arg0);
extern "C" void func_ov002_0215b138(void *arg0);

// USA: func_ov002_02155dbc
extern "C" ARM void func_ov002_02155dbc(char *arg0) {
    if (*(unsigned char *) (arg0 + 0x1000 + LOW_REGION(0xb87, 0xcc3)) != 0) {
#if defined(jpn)
        func_ov023_021e7868(arg0 + 0x18 + 0x800);
#else
        func_ov023_021e761c(arg0 + 0xb4 + 0x800);
#endif
    }
    if (*(void **) (arg0 + 0x2000 + LOW_REGION(0x298, 0x468)) != NULL) {
        func_ov023_021eb4b8(*(void **) (arg0 + 0x2000 + LOW_REGION(0x298, 0x468)));
    }
    if (*(int *) (arg0 + 0x1000 + LOW_REGION(0xa80, 0xbb8)) == LOW_REGION(0x1f, 0x1e) && *(int *) (arg0 + 0x1000 + LOW_REGION(0xa88, 0xbc0)) > 4) {
        func_ov013_02184a58(arg0 + LOW_REGION(0xc20, 0xd70) + 0x1000);
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
        if (*(unsigned char *) (arg0 + 0x1000 + 0xc34) != 0) {
            func_ov002_0215b9a4(arg0, 0x1b, 0);
            func_ov002_0215b9a4(arg0, 0x1a, 0);
            func_ov002_021619b4(*(signed char *) (arg0 + 0x1c00 + 0x20), *(int *) (arg0 + 0x1000 + LOW_REGION(0x9c0, 0xa68)),
                                *(int *) (arg0 + 0x1000 + 0xbd8));
            *(unsigned char *) (arg0 + 0x1000 + 0xc34) = 0;
        }

#endif
        func_ov002_0215ab60(arg0);
        func_ov002_0215ad70(arg0);
        func_ov002_0215afb8(arg0);
        func_ov002_0215b0a8(arg0);
        func_ov002_0215b138(arg0);
    }
    if (*(struct Struct_020e28dc **) arg0 != NULL && func_020e28dc(*(struct Struct_020e28dc **) arg0)) {
        func_020e2794(*(struct Struct_020e2794_2 **) arg0, NULL);
    }
    if (*(struct Struct_020e28dc **) (arg0 + 4) != NULL && func_020e28dc(*(struct Struct_020e28dc **) (arg0 + 4))) {
        func_020e2794(*(struct Struct_020e2794_2 **) (arg0 + 4), *(void **) (arg0 + 0x1000 + LOW_REGION(0x9c0, 0xa68)));
    }
}
