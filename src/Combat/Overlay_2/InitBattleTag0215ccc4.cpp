#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

extern "C" void func_ov002_02157030(void* base, int type, short* a, short* b, short* c, short* d);
extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_0215cd98(void* base, void* dst, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufOv0215ccc4 { char pad[RG(0xbd0, 0xa98)]; void* buf; };
struct FieldOv0215ccc4 { char pad[RG(0xbb8, 0xa80)]; int field; };

// USA: func_ov002_0215ccc4
ARM void InitBattleTag0215ccc4(char* base) {
    short s16 = 0, s14 = 0, s12 = 1, s10 = 1;
    func_ov002_02157030(base, 4, &s16, &s14, &s12, &s10);
    s16 = s16 + 1;
    s14 = s14 + 8;
    func_ov002_0215be00(base, ((struct FieldOv0215ccc4*)(base + 0x1000))->field & 0xff, s16, s14);

    memset(((struct BufOv0215ccc4*)(base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0215cd98(base, ((struct BufOv0215ccc4*)(base + 0x1000))->buf, 0);

#if defined(jpn)
    Window_OpenPane(base + 0xe20, ((struct BufOv0215ccc4*)(base + 0x1000))->buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(base + 0xec8, ((struct BufOv0215ccc4*)(base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);
#endif
}
