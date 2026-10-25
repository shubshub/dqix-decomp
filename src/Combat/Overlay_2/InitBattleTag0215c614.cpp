#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_02157030(void* base, int type, short* a, short* b, short* c, short* d);
extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_0215c72c(void* obj, void* dst, int flag);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_0215c8a4(void* obj);
struct Struct_0205d81c;
void Window_SetPanePalette(Struct_0205d81c*, int, int);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);

struct BufOv0215c614 { char pad[RG(0xbd0, 0xa98)]; void* buf; };
struct FieldOv0215c614 { char pad[RG(0xbb8, 0xa80)]; int field; };

// USA: func_ov002_0215c614  (semantic: InitBattleTag0215c614)
extern "C" ARM void func_ov002_0215c614(char* base) {
    short s16 = 0, s14 = 0, s12 = 1, s10 = 1;
    func_ov002_02157030(base, 3, &s16, &s14, &s12, &s10);
    s14 = s14 + 3;
    func_ov002_0215be00(base, ((struct FieldOv0215c614*)(base + 0x1000))->field & 0xff, s16, s14);

    memset(((struct BufOv0215c614*)(base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0215c72c(base, ((struct BufOv0215c614*)(base + 0x1000))->buf, 0);

#if defined(jpn)
    Window_OpenPane(base + 0xe20, ((struct BufOv0215c614*)(base + 0x1000))->buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(base + 0xec8, ((struct BufOv0215c614*)(base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);
#endif

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + RG(0xec8, 0xe20)), 0, 2);
    func_ov002_0215c8a4(base);
    Window_SetPanePalette((Struct_0205d81c*)(base + RG(0xec8, 0xe20)), ((struct FieldOv0215c614*)(base + 0x1000))->field & 0xff, 0);
    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(base + RG(0xec8, 0xe20)), ((struct FieldOv0215c614*)(base + 0x1000))->field & 0xff);
}
