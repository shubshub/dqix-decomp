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
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_0215c8a4(void* obj);
struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);
struct Struct_0205dee8;
extern "C" void func_0205dee8(struct Struct_0205dee8* obj, int val);

struct BufOv0215c614 { char pad[RG(0xbd0, 0xa98)]; void* buf; };
struct FieldOv0215c614 { char pad[RG(0xbb8, 0xa80)]; int field; };

// USA: func_ov002_0215c614
extern "C" ARM void func_ov002_0215c614(char* base) {
    short var0 = 0, var1 = 0, var2 = 1, var3 = 1;
    func_ov002_02157030(base, 3, &var0, &var1, &var2, &var3);
    var1 = var1 + 3;
    func_ov002_0215be00(base, ((struct FieldOv0215c614*)(base + 0x1000))->field & 0xff, var0, var1);

    memset(((struct BufOv0215c614*)(base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0215c72c(base, ((struct BufOv0215c614*)(base + 0x1000))->buf, 0);

#if defined(jpn)
    Window_OpenPane(base + 0xe20, ((struct BufOv0215c614*)(base + 0x1000))->buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(base + 0xec8, ((struct BufOv0215c614*)(base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);
#endif

    func_0205de24((struct Struct0205de24*)(base + RG(0xec8, 0xe20)), 0, 2);
    func_ov002_0215c8a4(base);
    Window_SetPanePalette((Struct_0205d81c*)(base + RG(0xec8, 0xe20)), ((struct FieldOv0215c614*)(base + 0x1000))->field & 0xff, 0);
    func_0205dee8((struct Struct_0205dee8*)(base + RG(0xec8, 0xe20)), ((struct FieldOv0215c614*)(base + 0x1000))->field & 0xff);
}
