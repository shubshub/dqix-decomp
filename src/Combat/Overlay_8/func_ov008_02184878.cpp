#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Cont0205d1e0;
extern "C" void Window_ClearLayers(struct Cont0205d1e0*);
struct Cont0205d228;
extern "C" void Window_DrawPanes(struct Cont0205d228*);
struct Cont0205d274;
extern "C" void Window_FlushLayers(struct Cont0205d274*);
extern "C" void func_ov008_02188730(void* obj);
extern "C" void func_ov008_02188934(void* obj);
struct Struct_ov008_02184878;
extern "C" void func_ov008_021889f8(struct Struct_ov008_02184878* obj);
extern "C" void func_ov008_02188870(void* obj);
extern "C" void func_ov023_021eb4b8(void* obj);

// USA: func_ov008_02184878
extern "C" ARM void func_ov008_02184878(char* obj) {
    signed char state = *(signed char*)(obj + 0xb10);
    if (state == 0 || state == 1 || state == 0xe) return;
    if (*(void**)(obj + 0xb08) == 0) {
        Window_ClearLayers((Cont0205d1e0*)(obj + 0x130));
        Window_DrawPanes((Cont0205d228*)(obj + 0x130));
        Window_FlushLayers((Cont0205d274*)(obj + 0x130));
    }
    if (*(int*)(obj + 0xb24) == 1) return;
    if (*(signed char*)(obj + 0xb10) == 3 && *(unsigned char*)(obj + 0xb11) < 1) return;
    func_ov008_02188730(obj);
    func_ov008_02188934(obj);
    func_ov008_021889f8((struct Struct_ov008_02184878*)obj);
    func_ov008_02188870(obj);
    if (*(void**)(obj + 0xb08) != 0) {
        func_ov023_021eb4b8(*(void**)(obj + 0xb08));
    }
}
