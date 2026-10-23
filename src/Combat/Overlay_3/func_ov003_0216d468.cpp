#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0216d468_704 = 0x150 };
enum { Enum_ov003_0216d468_1040 = 0x428 };
#else
enum { Enum_ov003_0216d468_704 = 0x2c0 };
enum { Enum_ov003_0216d468_1040 = 0x410 };
#endif


struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
void Window_ClearLayers(Cont0205d1e0*);
void Window_DrawPanes(Cont0205d228*);
extern "C" void func_0205da88(void*, int, int, int);
void Window_FlushLayers(Cont0205d274*);
extern "C" void func_ov003_0216d990(void* obj);
#if defined(jpn)
extern "C" void func_ov003_0216dcf0(void* arg0);
#else
extern "C" void func_ov004_0216dcf0(void* arg0);
#endif
extern "C" void func_ov003_0216ddfc(void* arg0);
extern "C" void func_ov003_0217019c(void* arg0);
extern "C" void func_ov003_0215ca1c(void* arg0);
extern "C" void func_ov003_02173ea8(unsigned char* arg0);

// USA: func_ov003_0216d468
extern "C" ARM void func_ov003_0216d468(void* p) {
    char* obj = (char*)p;
    if (*(void**)(obj + 0x1000 + kRegionValue2C0_150) != 0) {
        short f6 = *(short*)(obj + 6);
        if (f6 == 0 || f6 == 1 || *(short*)(obj + 4) == 2) {
            Window_ClearLayers((Cont0205d1e0*)*(void**)(obj + 0x1000 + kRegionValue2C0_150));
            Window_DrawPanes((Cont0205d228*)*(void**)(obj + 0x1000 + kRegionValue2C0_150));
            func_0205da88(*(void**)(obj + 0x1000 + kRegionValue2C0_150), 2, 1, 1);
            Window_FlushLayers((Cont0205d274*)*(void**)(obj + 0x1000 + kRegionValue2C0_150));
        }
    }
    func_ov003_0216d990(var0);
#if defined(jpn)
    func_ov003_0216dcf0(var0);
#else
    func_ov004_0216dcf0(var0);
#endif
    func_ov003_0216ddfc(var0);

    short var2 = *(short*)(var0 + 4);
    if (var2 == 4) {
        func_ov003_0217019c(var0 + Enum_ov003_0216d468_1040);
        return;
    }
    if (var2 == 3) {
        if (*(short*)(var0 + 6) == 1) {
            func_ov003_0215ca1c(var0 + 0x14);
        }
        return;
    }
    if (var2 == 5 && *(short*)(var0 + 6) == 6) {
#if defined(jpn)
        func_ov003_02173ea8((unsigned char*)(var0 + 0xda0));
#else
        func_ov003_02173ea8((unsigned char*)(var0 + 0x31c + 0xc00));
#endif
    }
}
